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
			pTI->m_hHandles[0] = FindFirstPrinterChangeNotification(hPrinter, PRINTER_CHANGE_ALL, 0, NULL);	// FindFirstPrinterChangeNotificationで変更通知ハンドル取得.
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
							if (FindNextPrinterChangeNotification(pTI->m_hHandles[0], &dwChange, NULL, NULL)){	// FindNextPrinterChangeNotificationで通知確認.
								_tprintf(_T("notify!\n"));
							}

						}
					}

					CloseHandle(pTI->m_hHandles[1]);	// とりあえずはpTI->m_hHandles[1]をCloseHandleで閉じる.
				}

				//CloseHandle(pTI->m_hHandles[0]);	// とりあえずはpTI->m_hHandles[0]をCloseHandleで閉じる.
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