// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言と初期化.
	SC_HANDLE hSCM = NULL;	// SC_HANDLE型hSCMをNULLで初期化.
	SC_HANDLE hService = NULL;	// SC_HANDLE型hServiceをNULLで初期化.
	LPCTSTR lpctszService = _T("Irmon");	// サービス名lpctszServiceを"Irmon"で初期化.
	BOOL bStart = FALSE;	// BOOL型bStartをFALSEで初期化.

	// SCManagerのオープン
	hSCM = OpenSCManager(NULL, NULL, SC_MANAGER_CONNECT);	// OpenSCManagerでSCManagerを開き, ハンドルをhSCMに格納.
	if (hSCM != NULL){	// NULLでない時.

		// hSCMの出力.
		_tprintf(_T("hSCM = 0x%08x\n"), (unsigned long)hSCM);	// hSCMの値を出力.

		// Serviceのオープン
		hService = OpenService(hSCM, lpctszService, SERVICE_START);	// OpenServiceで"Irmon"を開く.
		if (hService != NULL){	// NULLでない時.

			// hServiceの出力.
			_tprintf(_T("hService = 0x%08x\n"), (unsigned long)hService);	// hServiceの値を出力.

			// サービスの開始.
			bStart = StartService(hService, 0, NULL);	// StartServiceでサービス開始.
			if (bStart){	// TRUEなら.
				_tprintf(_T("StartService success!\n"));	// "StartService success!"を出力.
			}
			else{	// FALSEなら.
				_tprintf(_T("StartService failed!\n"));	// "StartService failed!"を出力.
			}
			Sleep(5000);	// 5秒待つ.
			CloseServiceHandle(hService);	// CloseServiceHandleでhServiceを閉じる.

		}
		else{	// NULLの時.
			_tprintf(_T("OpenService failed!\n"));	// "OpenService failed!"と出力.
		}

		// hSCMを閉じる.
		CloseServiceHandle(hSCM);	// CloseServiceHandleでhSCMを閉じる.

	}
	else{	// NULLの時.
		_tprintf(_T("OpenSCManager failed!\n"));	// "OpenSCManager failed!"と出力.
	}

	// プログラムの終了
	return 0;	// 0を返して正常終了.

}