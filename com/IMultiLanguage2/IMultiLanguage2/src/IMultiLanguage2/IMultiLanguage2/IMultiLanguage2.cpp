// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR対応
#include <stdio.h>		// C標準入出力
#include <mlang.h>		// 多言語

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言と初期化.
	HRESULT hr;		// COMの初期化の結果を格納するhr.
	HRESULT hr2;	// IMultiLanguage2の生成結果を格納するhr2.
	IMultiLanguage2 *pMultiLang = NULL;	// IMultiLanguage2インターフェースポインタpMultiLangをNULLで初期化.

	// COMの初期化.
	hr = CoInitialize(NULL);	// CoInitializeでCOMを初期化し, 戻り値をhrに格納.
	if (FAILED(hr)){	// FAILEDマクロで判定.
		_tprintf(_T("FAILED!\n"));	// "FAILED!"と出力.
		return -1;	// -1を返して異常終了.
	}

	// IMultiLanguage2インターフェースの生成.
	hr2 = CoCreateInstance(CLSID_CMultiLanguage, 0, CLSCTX_INPROC_SERVER, IID_IMultiLanguage2, (LPVOID *)&pMultiLang);	// CoCreateInstanceで, IMultiLanguage2インターフェースを生成.
	if (FAILED(hr2)){	// FAILEDマクロで判定.
		_tprintf(_T("FAILED!\n"));	// "FAILED!"と出力.
		CoUninitialize();	// CoUninitializeで終了処理.
		return -2;	// -2を返して異常終了.
	}

	// CoCreateInstanceは成功.
	_tprintf(_T("CoCreateInstance OK!\n"));	// "CoCreateInstance OK!"と出力.

	// 取得したIMultiLanguage2インターフェースポインタpMultiLangを出力.
	_tprintf(_T("pMultiLang = 0x%08x\n"), (unsigned long)pMultiLang);	// pMultiLangを出力.

	// COMの終了処理.
	pMultiLang->Release();	// IMultiLanguage2::Releaseで解放.
	CoUninitialize();	// CoUninitializeで終了処理.

	// プログラムの終了.
	return 0;	// 0を返して終了.

}