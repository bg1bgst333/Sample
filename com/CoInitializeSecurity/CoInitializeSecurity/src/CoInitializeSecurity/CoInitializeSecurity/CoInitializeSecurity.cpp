// ヘッダファイルのインクルード
#define _WIN32_DCOM		// DCOMの定義
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR対応
#include <stdio.h>		// C標準入出力
#include <objbase.h>	// COM

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言
	HRESULT hr;		// COMの初期化の結果を格納するhr.
	HRESULT hr2;	// セキュリティ初期化の結果を格納するhr2.

	// MTA(マルチスレッドアパートメント)に属するように設定.
	hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);	// CoInitializeExにCOINIT_MULTITHREADEDを指定して初期化.
	if (hr == S_OK){	// S_OKなら初期化成功.
		_tprintf(_T("CoInitializeEx success!\n"));	// "CoInitializeEx success!"と出力.
	}
	else if (hr == S_FALSE){	// S_FALSEならすでに初期化されている.
		_tprintf(_T("Already initialized!\n"));	// "Already initialized!"と出力.
	}
	else{	// それ以外.
		_tprintf(_T("Failed!\n"));	// "Failed!"と出力.
		return -1;	// -1を返して異常終了.
	}

	// セキュリティ初期化.
	hr2 = CoInitializeSecurity(NULL, -1, NULL, NULL, RPC_C_AUTHN_LEVEL_DEFAULT, RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE, NULL);	// CoInitializeSecurityでセキュリティ初期化.
	if (hr2 == S_OK){	// S_OKなら初期化成功.
		_tprintf(_T("CoInitializeSecurity success!\n"));	// "CoInitializeSecurity success!"と出力.
	}
	else{	// それ以外.
		_tprintf(_T("Failed!\n"));	// "Failed!"と出力.
		CoUninitialize();	// CoUninitializeで終了処理.
		return -2;	// -2を返して異常終了.
	}

	// COMの終了処理.
	CoUninitialize();	// CoUninitializeで終了処理.

	// プログラムの終了.
	return 0;	// 0を返して終了.

}