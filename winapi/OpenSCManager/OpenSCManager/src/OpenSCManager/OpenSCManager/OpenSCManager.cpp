// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言と初期化.
	SC_HANDLE hSCM = NULL;	// SC_HANDLE型hSCMをNULLで初期化.

	// SCManagerのオープン
	hSCM = OpenSCManager(NULL, NULL, SC_MANAGER_CONNECT);	// OpenSCManagerでSCManagerを開き, ハンドルをhSCMに格納.
	if (hSCM != NULL){	// NULLでない時.
		_tprintf(_T("hSCM = 0x%08x\n"), (unsigned long)hSCM);	// hSCMの値を出力.
		CloseServiceHandle(hSCM);	// CloseServiceHandleでhSCMを閉じる.
	}
	else{	// NULLの時.
		_tprintf(_T("OpenSCManager failed!\n"));	// "OpenSCManager failed!"と出力.
	}

	// プログラムの終了
	return 0;	// 0を返して正常終了.

}