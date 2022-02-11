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
	if (SUCCEEDED(hr)){	// SUCCEEDEDマクロで判定.
		_tprintf(_T("SUCCEEDED!\n"));	// "SUCCEEDED!"と出力.
	}
	else if (FAILED(hr)){	// FAILEDマクロで判定.
		_tprintf(_T("FAILED!\n"));	// "FAILED!"と出力.
		return -1;	// -1を返して異常終了.
	}

	// セキュリティ初期化.
	hr2 = CoInitializeSecurity(NULL, -1, NULL, NULL, -1, -1, NULL, -1, NULL);	// CoInitializeSecurityでセキュリティ初期化.(でたらめな引数を指定.)
	if (SUCCEEDED(hr2)){	// SUCCEEDEDマクロで判定.
		_tprintf(_T("SUCCEEDED!\n"));	// "SUCCEEDED!"と出力.
	}
	else if (FAILED(hr2)){	// FAILEDマクロで判定.
		_tprintf(_T("FAILED!\n"));	// "FAILED!"と出力.
		CoUninitialize();	// CoUninitializeで終了処理.
		return -2;	// -2を返して異常終了.
	}

	// COMの終了処理.
	CoUninitialize();	// CoUninitializeで終了処理.

	// プログラムの終了.
	return 0;	// 0を返して終了.

}