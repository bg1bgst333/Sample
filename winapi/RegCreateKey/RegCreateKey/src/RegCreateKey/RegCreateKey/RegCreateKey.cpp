// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の初期化.
	HKEY hKey = NULL;	// 作成したキーのハンドルHKEY型hKeyをNULLに初期化.
	LONG lRet = 0;	// RegCreateKeyの戻り値LONG型lRetを0に初期化.

	// "HKEY_CURRENT_USER\Software\RegCreateKey"というレジストリキーの作成.
	lRet = RegCreateKey(HKEY_CURRENT_USER, _T("Software\\RegCreateKey"), &hKey);	// RegCreateKeyでキー"HKEY_CURRENT_USER\Software\RegCreateKey"を作成.
	if (lRet != ERROR_SUCCESS){	// 成功(ERROR_SUCCESS)でなければ.

		// "ERROR!"と出力.
		_tprintf(_T("ERROR!\n"));	// "ERROR!"と出力.
		return -1;	// -1を返して終了.

	}

	// "SUCCESS!"と出力.
	_tprintf(_T("SUCCESS!\n"));	// "SUCCESS!"と出力.

	// hKeyを閉じる.
	RegCloseKey(hKey);	// RegCloseKeyでhKeyを閉じる.

	// プログラムの終了
	return 0;	// 0を返して終了.

}