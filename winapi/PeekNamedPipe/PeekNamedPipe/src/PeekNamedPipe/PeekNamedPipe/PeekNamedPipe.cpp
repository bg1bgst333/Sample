// ヘッダファイルのインクルード
#include <string>		// std::string
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の初期化
	SECURITY_ATTRIBUTES sa = {0};		// セキュリティ属性saを{0]で初期化.
	BOOL bRetPipe = FALSE;				// パイプ生成結果bRetPipeをFALSEで初期化.
	HANDLE hPipe[2] = {NULL, NULL};		// 配列hPipeを{NULL, NULL}で初期化.
	STARTUPINFO si = {0};				// スタートアップ情報siは{0}で初期化.
	TCHAR tszCommandString[64] = {0};	// 文字配列tszCommandString(長さ64)を{0}で初期化.
	BOOL bRetProcess = FALSE;			// プロセス生成結果bRetProcessをFALSEで初期化.
	PROCESS_INFORMATION pi = {0};		// プロセス情報piは{0}で初期化.
	DWORD dwRetWait = 0;				// WaitForSingleObjectの戻り値dwRetWaitを0で初期化.
	BOOL bExit = FALSE;					// ループを抜けるかどうかの判定bExitをFALSEで初期化.
	BOOL bRetPeek = FALSE;				// パイプに溜まっている残量を取得できたかどうかを表すbRetPeekをFALSEで初期化.
	DWORD dwTotalLen = 0;				// 残りの合計サイズdwTotalLenを0で初期化.
	BYTE btBuf[1024] = {0};				// バッファbtBuf(長さ1024)を{0}で初期化.
	DWORD dwReadLen = 0;				// 1回の読み込み量dwReadLenを0で初期化.
	std::string strResponse = "";		// 読み込み文字列strResponseを""で初期化.
	BOOL bRead = FALSE;					// 読み込めたかどうかの判定bReadをFALSEで初期化.

	// セキュリティ属性の設定.
	sa.nLength = sizeof(sa);		// サイズ
	sa.bInheritHandle = TRUE;		// 継承する.
	sa.lpSecurityDescriptor = NULL;	// NULL.

	// パイプの作成.
	bRetPipe = CreatePipe(&hPipe[0], &hPipe[1], &sa, 0);	// CreatePipeでパイプ作成.
	if (bRetPipe){	// 成功.

		// スタートアップ情報のセット.
		si.cb = sizeof(STARTUPINFO);	// サイズ.
		si.dwFlags = STARTF_USESTDHANDLES;	// 標準入出力ハンドルに指定の物を使う.
		si.hStdOutput = hPipe[1];	// 標準出力にhPipe[1]をセット.

		// プロセスを生成.
		_tcscpy(tszCommandString, _T("ping yahoo.co.jp"));	// コマンド文字列をいったんtszCommandStringにコピー.(yahoo.co.jpにpingを打つ.)
		bRetProcess = CreateProcess(NULL, tszCommandString, NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);	// CreateProcessで"ping"コマンドを起動.
		if (bRetProcess){	// 成功.

			// スレッドハンドルを閉じる.
			if (pi.hThread != NULL){	// pi.hThreadがNULLでない時.
				CloseHandle(pi.hThread);	// pi.hThreadを閉じる.
				pi.hThread = NULL;	// pi.hThreadにNULLをセット.
			}

			// 読み込みループ.
			do{
				// 終了まで待つ.
				dwRetWait = WaitForSingleObject(pi.hProcess, INFINITE);	// WaitForSingleObjectでシグナル状態まで待つ.
				if (dwRetWait == WAIT_OBJECT_0){	// 終了.

					// 抜けるフラグを立てる.
					bExit = TRUE;	// bExitをTRUEに.

				}

				// パイプに溜まっている残量をチェック.
				bRetPeek = PeekNamedPipe(hPipe[0], NULL, 0, NULL, &dwTotalLen, NULL);	// PeekNamedPipeで残量チェック.
				if (!bRetPeek){	// 失敗

					// 抜ける.
					break;	// breakで抜ける.

				}

				// 合計0以上.
				if (dwTotalLen > 0){	// dwTotalLenが0より大きい.

					// btBufのクリア.
					ZeroMemory(btBuf, (sizeof(BYTE) * 1024));	// ZeroMemoryでbtBufをクリア.

					// パイプから読み込む.
					bRead = ReadFile(hPipe[0], btBuf, (sizeof(BYTE) * 1024) - 1, &dwReadLen, NULL);	// ReadFileでhPipe[0]を読み込む.
					if (!bRead){	// 失敗

						// 抜ける.
						break;	// breakで抜ける.

					}

					// 読み込めたらNULL終端.
					btBuf[dwReadLen] = '\0';	// dwReadLen番目に'\0'をセット.

					// 連結.
					strResponse += (char *)btBuf;	// strResponseにbtBufを結合.

					// 合計に満たないので続ける.
					if (dwReadLen < dwTotalLen){	// dwReadLenがdwTotalLenに満たない.
						bExit = FALSE;	// bExitをFALSEにする.
					}

				}

			} while (!bExit);
		}
		else{	// 失敗.

			// "CreateProcess failed!"と表示.
			MessageBox(NULL, _T("CreateProcess failed!"), _T("PeekNamedPipe"), MB_OK);	// MessageBoxで"CreateProcess failed!"を表示.

		}

		// パイプを閉じる.
		if (hPipe[1] != NULL){
			CloseHandle(hPipe[1]);	// hPipe[1]を閉じる.
			hPipe[1] = NULL;	// hPipe[1]にNULLをセット.
		}
		if (hPipe[0] != NULL){
			CloseHandle(hPipe[0]);	// hPipe[0]を閉じる.
			hPipe[0] = NULL;	// hPipe[0]にNULLをセット.
		}

		// スレッドハンドルを閉じる.
		if (pi.hThread != NULL){
			CloseHandle(pi.hThread);	// pi.hThreadを閉じる.
			pi.hThread = NULL;	// pi.hThreadにNULLをセット.
		}

		// プロセスハンドルを閉じる.
		if (pi.hProcess != NULL){
			CloseHandle(pi.hProcess);	// pi.hProcessを閉じる.
			pi.hProcess = NULL;	// pi.hProcessにNULLをセット.
		}

		// strResponseの表示.
		MessageBoxA(NULL, strResponse.c_str(), "PeekNamedPipe", MB_OK);	// MessageBoxAでstrResponseの内容を表示.

	}

	// プログラムの終了
	return 0;	// 0を返して正常終了.

}