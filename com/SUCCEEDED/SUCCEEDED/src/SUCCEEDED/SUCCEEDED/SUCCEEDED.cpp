// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR対応

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// COMの初期化.
	HRESULT hr = CoInitialize(NULL);	// CoInitializeでCOMを初期化し, 戻り値をhrに格納.
	if (SUCCEEDED(hr)){	// SUCCEEDEDマクロで判定.
		_tprintf(_T("SUCCEEDED!\n"));	// "SUCCEEDED!"と出力.
	}
	if (hr == S_OK){	// S_OKなら初期化成功.
		_tprintf(_T("CoInitialize success!\n"));	// "CoInitialize success!"と出力.
	}

	// 2回目のCOMの初期化.
	HRESULT hr2 = CoInitialize(NULL);	// CoInitializeでCOMを初期化し, 戻り値をhr2に格納.
	if (SUCCEEDED(hr2)){	// SUCCEEDEDマクロで判定.
		_tprintf(_T("SUCCEEDED!\n"));	// "SUCCEEDED!"と出力.
	}
	if (hr2 == S_FALSE){	// S_FALSEならすでに初期化されている.
		_tprintf(_T("Already initialized!\n"));	// "Already initialized!"と出力.
	}

	// COMの終了処理.
	CoUninitialize();	// CoUninitializeで終了処理.

	// プログラムの終了.
	return 0;	// 0を返して終了.

}