// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の初期化
	HANDLE hFile = NULL;				// ファイルハンドルhFileをNULLで初期化.
	TCHAR tszHFile[64] = {0};			// 文字配列tszHFile(長さ64)を{0}で初期化.
	HANDLE hStdOut = NULL;				// 標準出力ハンドルhStdOutをNULLで初期化.
	TCHAR tszHStdOut[64] = {0};			// 文字配列tszHStdOut(長さ64)を{0}で初期化.
	STARTUPINFO si = {0};				// スタートアップ情報siは{0}で初期化.
	TCHAR tszCommandString[64] = {0};	// 文字配列tszCommandString(長さ64)を{0}で初期化.
	BOOL bRet = FALSE;					// プロセス生成結果bRetをFALSEで初期化.
	PROCESS_INFORMATION pi = {0};		// プロセス情報piは{0}で初期化.
	DWORD dwRet = 0;					// プロセスの待機状態dwRetを0で初期化.

	// "ping"コマンドの出力を記録する"ping.log"を作成.
	hFile = CreateFile(_T("ping.log"), GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);	// "ping.log"を作成.
	if (hFile != INVALID_HANDLE_VALUE){	// 成功.

		// hFileを文字列に変換.
		_stprintf(tszHFile, _T("hFile = 0x%08x"), (unsigned int)hFile);	// _stprintfでhFileをtszHFileに変換.

		// hFileを表示.
		MessageBox(NULL, tszHFile, _T("DuplicateHandle"), MB_OK);	// MessageBoxでtszHFileを表示.

		// ハンドルの複製(現在のプロセスは度々取得した方がいい.)
		DuplicateHandle(GetCurrentProcess(), hFile, GetCurrentProcess(), &hStdOut, 0, TRUE, DUPLICATE_SAME_ACCESS);	// DuplicateHandleでhFileと同じファイルを指すhStdOutを取得.
		if (hStdOut != INVALID_HANDLE_VALUE){	// 成功.

			// hStdOutを文字列に変換.
			_stprintf(tszHStdOut, _T("hStdOut = 0x%08x"), (unsigned int)hStdOut);	// _stprintfでhStdOutをtszHStdOutに変換.

			// hStdOutを表示.
			MessageBox(NULL, tszHStdOut, _T("DuplicateHandle"), MB_OK);	// MessageBoxでtszHStdOutを表示.

			// スタートアップ情報のセット.
			si.cb = sizeof(STARTUPINFO);	// サイズ.
			si.dwFlags = STARTF_USESTDHANDLES;	// 標準入出力ハンドルに指定の物を使う.
			si.hStdOutput = hStdOut;	// 標準出力にhStdOut.

			// プロセスを生成.
			_tcscpy(tszCommandString, _T("ping yahoo.co.jp"));	// コマンド文字列をいったんtszCommandStringにコピー.(yahoo.co.jpにpingを打つ.)
			bRet = CreateProcess(NULL, tszCommandString, NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);	// CreateProcessで"ping"コマンドを起動.
			if (bRet){	// 成功.

				// スレッドハンドルを閉じる.
				if (pi.hThread != NULL) {	// pi.hThreadがNULLでない時.
					CloseHandle(pi.hThread);	// pi.hThreadを閉じる.
					pi.hThread = NULL;	// pi.hThreadにNULLをセット.
				}

				// 終了まで待つ.
				dwRet = WaitForSingleObject(pi.hProcess, INFINITE);	// WaitForSingleObjectでシグナル状態まで待つ.
				if (dwRet == WAIT_OBJECT_0){	// 終了.

					// "CreateProcess Finish!"と表示.
					MessageBox(NULL, _T("CreateProcess Finish!"), _T("DuplicateHandle"), MB_OK);	// MessageBoxで"CreateProcess Finish!"を表示.

				}

			}
			else{	// 失敗.

				// "CreateProcess failed!"と表示.
				MessageBox(NULL, _T("CreateProcess failed!"), _T("DuplicateHandle"), MB_OK);	// MessageBoxで"CreateProcess failed!"を表示.

			}

			// 複製した標準出力ハンドルを閉じる.
			CloseHandle(hStdOut);	// hStdOutを閉じる.

		}

		// "ping.log"を閉じる.
		CloseHandle(hFile);	// hFileを閉じる.

		// スレッドハンドルを閉じる.
		if (pi.hThread != NULL){	// pi.hThreadがNULLでない時.
			CloseHandle(pi.hThread);	// pi.hThreadを閉じる.
			pi.hThread = NULL;	// pi.hThreadにNULLをセット.
		}

		// プロセスハンドルを閉じる.
		if (pi.dwProcessId != NULL){	// pi.hProcessがNULLでない時.
			CloseHandle(pi.hProcess);	// pi.hProcessを閉じる.
			pi.hProcess = NULL;	// pi.hProcessにNULLをセット.
		}

	}

	// プログラムの終了
	return 0;	// 0を返して正常終了.

}