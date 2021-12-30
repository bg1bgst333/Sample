// ヘッダファイルのインクルード
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <windows.h>	// 標準WindowsAPI

// 関数プロトタイプ宣言.
void WINAPI ThreadProc(LPVOID lpParameter);	// スレッド内部処理ThreadProc.

// スレッドに渡す情報構造体THREAD_INFOの定義.
typedef struct{
	BOOL m_bRunning;	// 実行中かどうか.
	HANDLE m_hHandles[2];	// 0: 変更通知ハンドル, 1: 停止ハンドル
} THREAD_INFO;

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の定義と初期化.
	HANDLE hThread = NULL;	// スレッドハンドルhThreadをNULLで初期化.
	THREAD_INFO ti = {0};	// THREAD_INFO構造体tiを{0}で初期化.
	DWORD dwThreadId = 0;	// スレッドIDのdwThreadIdを0で初期化.

	// スレッドの開始.
	_tprintf(_T("thread begin before.\n"));
	hThread = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ThreadProc, (LPVOID)&ti, 0, &dwThreadId);	// CreateThreadでThreadProc開始.

	// 1分休止.
	_tprintf(_T("thread wait before.\n"));
	Sleep(1 * 60 * 1000);	// Sleepで1分待つ.

	// 終了させる.
	ti.m_bRunning = FALSE;	// m_bRunningをFALSEに.
	SetEvent(ti.m_hHandles[1]);	// 停止ハンドルをシグナル状態に.

	// スレッド終了を待つ.
	WaitForSingleObject(hThread, INFINITE);	// WaitForSingleObjectで終了まで待つ.

	// スレッドハンドルを閉じる.
	_tprintf(_T("thread close before.\n"));
	CloseHandle(hThread);	// CloseHandleでhThreadを閉じる.

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}

// スレッド内部処理ThreadProcの定義.
void WINAPI ThreadProc(LPVOID lpParameter){

	// 変数の宣言と初期化.
	DWORD dwSize = 0;	// バッファサイズdwSizeを0で初期化.
	TCHAR *ptszBuf = NULL;	// プリンタ名を格納する文字列バッファポインタptszBufをNULLで初期化.
	HANDLE hPrinter = NULL;	// プリンタハンドルhPrinterをNULLで初期化.
	BOOL bOpen = FALSE;	// プリンタが開けたかを表すbOpenをFALSEで初期化.
	THREAD_INFO *pTI = NULL;	// THREAD_INFOポインタpTIをNULLで初期化.
	DWORD dwChange = 0;	// 何が変わったかを示すdwChangeを0で初期化.
	PRINTER_NOTIFY_INFO *pPNI = NULL;	// PRINTER_NOTIFY_INFO構造体ポインタpPNIをNULLで初期化.
	int i = 0;	// ループ用変数iを0で初期化.
	PRINTER_NOTIFY_OPTIONS pno = {0};	// PRINTER_NOTIFY_OPTIONS構造体pnoを{0}で初期化.
	PRINTER_NOTIFY_OPTIONS_TYPE pnot[2];	// PRINTER_NOTIFY_OPTIONS_TYPE構造体配列pnot(要素数2)
	WORD pnf[PRINTER_NOTIFY_FIELD_OBJECT_GUID + 1];	// PRINTER_NOTIFY_FIELD_XXXを格納する配列pnf.(要素数27)
	WORD jnf[JOB_NOTIFY_FIELD_BYTES_PRINTED + 1];	// JOB_NOTIFY_FIELD_XXXを格納する配列jnf.(要素数24)

	// 開始.
	_tprintf(_T("threadproc begin before.\n"));

	// 引数をTHREAD_INFOに戻す.
	pTI = (THREAD_INFO *)lpParameter;	// lpParameterを(THREAD_INFO *)にキャスト.
	pTI->m_bRunning = TRUE;	// m_bRunningをTRUEにする.

	// 既定のプリンタ名を取得.
	GetDefaultPrinter(NULL, &dwSize);	// GetDefaultPrinterにNULLを渡してバッファサイズを取得.
	ptszBuf = new TCHAR[dwSize];	// dwSize分のバッファを確保.
	GetDefaultPrinter(ptszBuf, &dwSize);	// GetDefaultPrinterで既定のプリンタ名を取得.
	_tprintf(_T("Default Printer: %s\n"), ptszBuf);	// ptszBufを出力.

	// プリンタハンドルの取得.
	bOpen = OpenPrinter(ptszBuf, &hPrinter, NULL);	// OpenPrinterでプリンタ名ptszBufのプリンタを開く.
	if (bOpen){	// 成功.
		if (hPrinter != NULL){	// プリンタハンドルはNULLではない.
			_tprintf(_T("hPrinter: 0x%08x\n"), (unsigned long)hPrinter);	// hPrinterを出力.

			// 変更通知ハンドルの取得.
			pno.Version = 2;	// バージョンは2.
			pno.Count = 2;	// pnotの要素数は2.
			pno.pTypes = pnot;	// pTypesにpnotを指定.
			for (i = 0; i <= PRINTER_NOTIFY_FIELD_OBJECT_GUID; i++){
				pnf[i] = PRINTER_NOTIFY_FIELD_SERVER_NAME + i;
			}
			pnot[0].Type = PRINTER_NOTIFY_TYPE;
			pnot[0].Count = PRINTER_NOTIFY_FIELD_OBJECT_GUID + 1;
			pnot[0].pFields = pnf;
			for (i = 0; i <= JOB_NOTIFY_FIELD_BYTES_PRINTED; i++){
				jnf[i] = JOB_NOTIFY_FIELD_PRINTER_NAME + i;
			}
			pnot[1].Type = JOB_NOTIFY_TYPE;
			pnot[1].Count = JOB_NOTIFY_FIELD_BYTES_PRINTED + 1;
			pnot[1].pFields = jnf;
			pTI->m_hHandles[0] = FindFirstPrinterChangeNotification(hPrinter, PRINTER_CHANGE_ALL, 0, &pno);	// FindFirstPrinterChangeNotificationで変更通知ハンドル取得.(pnoのアドレスを渡す.)
			if (pTI->m_hHandles[0] != NULL){	// NULLでない.
				_tprintf(_T("pTI->m_hHandles[0]: 0x%08x\n"), (unsigned long)pTI->m_hHandles[0]);	// pTI->m_hHandles[0]を出力.
				
				// 停止イベントの作成.
				pTI->m_hHandles[1] = CreateEvent(NULL, FALSE, FALSE, _T("StopEvent"));	// CreateEventで"StopEvent"を作成.
				if (pTI->m_hHandles[1] != NULL){	// NULLでない.
					_tprintf(_T("pTI->m_hHandles[1]: 0x%08x\n"), (unsigned long)pTI->m_hHandles[1]);	// pTI->m_hHandles[1]を出力.

					// 監視ループ.
					while (pTI->m_bRunning){	// pTI->m_bRunningがTRUEの間.

						// 2つのハンドルを監視.
						if (WaitForMultipleObjects(2, pTI->m_hHandles, FALSE, INFINITE) == WAIT_OBJECT_0){	// 2つのハンドルのどちらかがシグナル状態になるまで待つ.

							// プリンタの通知なのかはFindNextPrinterChangeNotificationでわかる.
							if (FindNextPrinterChangeNotification(pTI->m_hHandles[0], &dwChange, &pno, (LPVOID *)&pPNI)){	// FindNextPrinterChangeNotificationで通知確認.(pnoのアドレスを渡す.)
								_tprintf(_T("notify!\n"));
								if (dwChange & PRINTER_CHANGE_ADD_PRINTER){
									_tprintf(_T("PRINTER_CHANGE_ADD_PRINTER\n"));
								}
								if (dwChange & PRINTER_CHANGE_SET_PRINTER){
									_tprintf(_T("PRINTER_CHANGE_SET_PRINTER\n"));
								}
								if (dwChange & PRINTER_CHANGE_DELETE_PRINTER){
									_tprintf(_T("PRINTER_CHANGE_DELETE_PRINTER\n"));
								}
								if (dwChange & PRINTER_CHANGE_FAILED_CONNECTION_PRINTER){
									_tprintf(_T("PRINTER_CHANGE_FAILED_CONNECTION_PRINTER\n"));
								}
								if (dwChange & PRINTER_CHANGE_ADD_JOB){
									_tprintf(_T("PRINTER_CHANGE_ADD_JOB\n"));
								}
								if (dwChange & PRINTER_CHANGE_SET_JOB){
									_tprintf(_T("PRINTER_CHANGE_SET_JOB\n"));
								}
								if (dwChange & PRINTER_CHANGE_DELETE_JOB){
									_tprintf(_T("PRINTER_CHANGE_DELETE_JOB\n"));
								}
								if (dwChange & PRINTER_CHANGE_WRITE_JOB){
									_tprintf(_T("PRINTER_CHANGE_WRITE_JOB\n"));
								}
								if (dwChange & PRINTER_CHANGE_ADD_FORM){
									_tprintf(_T("PRINTER_CHANGE_ADD_FORM\n"));
								}
								if (dwChange & PRINTER_CHANGE_SET_FORM){
									_tprintf(_T("PRINTER_CHANGE_SET_FORM\n"));
								}
								if (dwChange & PRINTER_CHANGE_DELETE_FORM){
									_tprintf(_T("PRINTER_CHANGE_DELETE_FORM\n"));
								}
								if (dwChange & PRINTER_CHANGE_ADD_PORT){
									_tprintf(_T("PRINTER_CHANGE_ADD_PORT\n"));
								}
								if (dwChange & PRINTER_CHANGE_CONFIGURE_PORT){
									_tprintf(_T("PRINTER_CHANGE_CONFIGURE_PORT\n"));
								}
								if (dwChange & PRINTER_CHANGE_DELETE_PORT){
									_tprintf(_T("PRINTER_CHANGE_DELETE_PORT\n"));
								}
								if (dwChange & PRINTER_CHANGE_ADD_PRINT_PROCESSOR){
									_tprintf(_T("PRINTER_CHANGE_ADD_PRINT_PROCESSOR\n"));
								}
								if (dwChange & PRINTER_CHANGE_DELETE_PRINT_PROCESSOR){
									_tprintf(_T("PRINTER_CHANGE_DELETE_PRINT_PROCESSOR\n"));
								}
								if (dwChange & PRINTER_CHANGE_ADD_PRINTER_DRIVER){
									_tprintf(_T("PRINTER_CHANGE_ADD_PRINTER_DRIVER\n"));
								}
								if (dwChange & PRINTER_CHANGE_SET_PRINTER_DRIVER){
									_tprintf(_T("PRINTER_CHANGE_SET_PRINTER_DRIVER\n"));
								}
								if (dwChange & PRINTER_CHANGE_DELETE_PRINTER_DRIVER){
									_tprintf(_T("PRINTER_CHANGE_DELETE_PRINTER_DRIVER\n"));
								}
								if (dwChange & PRINTER_CHANGE_TIMEOUT){
									_tprintf(_T("PRINTER_CHANGE_TIMEOUT\n"));
								}

								// PRINTER_NOTIFY_INFOのチェック.
								if (pPNI != NULL){ // pPNIがNULLで無い.
									_tprintf(_T("pPNI->Version = %lu\n"), pPNI->Version);
									_tprintf(_T("pPNI->Flags = %lu\n"), pPNI->Flags);
									_tprintf(_T("pPNI->Count = %lu\n"), pPNI->Count);
									for (i = 0; i < pPNI->Count; i++){
										_tprintf(_T("pPNI->aData[i].Id = %08x\n"), pPNI->aData[i].Id);
										_tprintf(_T("pPNI->aData[i].Type = %08x\n"), pPNI->aData[i].Type);
									}
								}

							}

						}
					}

					CloseHandle(pTI->m_hHandles[1]);	// とりあえずはpTI->m_hHandles[1]をCloseHandleで閉じる.
				}

				FindClosePrinterChangeNotification(pTI->m_hHandles[0]);	// pTI->m_hHandles[0]をFindClosePrinterChangeNotificationで閉じる.
			}

			ClosePrinter(hPrinter);	// ClosePrinterでhPrinterを閉じる.
		}
	}

	// メモリ解放.
	delete[] ptszBuf;	// ptszBufを解放.

	// 終了.
	_tprintf(_T("threadproc after before.\n"));

}