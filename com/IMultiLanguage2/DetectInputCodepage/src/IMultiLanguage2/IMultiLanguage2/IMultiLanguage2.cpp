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
	HRESULT hr3;	// IMultiLanguage2::DetectInputCodepageの結果を格納するhr3.
	IMultiLanguage2 *pMultiLang = NULL;	// IMultiLanguage2インターフェースポインタpMultiLangをNULLで初期化.
	DetectEncodingInfo dei[10];	// 検出エンコード情報の配列dei.
	char input[] = "今日の天気は晴れで最高気温は5℃です。今日の天気は晴れで最高気温は5℃です。今日の天気は晴れで最高気温は5℃です。今日の天気は晴れで最高気温は5℃です。今日の天気は晴れで最高気温は5℃です。今日の天気は晴れで最高気温は5℃です。今日の天気は晴れで最高気温は5℃です。";	// 入力文字列input.
	int len;	// inputの長さlen.
	int num = 10;	// 配列deiの要素数numを10で初期化.

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

	// 入力文字コードの検出.
	len = strlen(input);	// strlenでinputの長さを取得し, lenに格納.
	hr3 = pMultiLang->DetectInputCodepage(MLDETECTCP_NONE, 0, input, &len, dei, &num);	// IMultiLanguage2::DetectInputCodepageで検出.
	if (FAILED(hr2)){	// FAILEDマクロで判定.
		_tprintf(_T("FAILED!\n"));	// "FAILED!"と出力.
		pMultiLang->Release();	// IMultiLanguage2::Releaseで解放.
		CoUninitialize();	// CoUninitializeで終了処理.
		return -3;	// -3を返して異常終了.
	}

	// numの分繰り返す.
	for (int i = 0; i < num; i++){
		_tprintf(_T("dei[%d].nCodePage = %lu, dei[%d].nDocPercent = %lu\n"), i, dei[i].nCodePage, i, dei[i].nDocPercent);	// deiの中身を出力.
	}

	// COMの終了処理.
	pMultiLang->Release();	// IMultiLanguage2::Releaseで解放.
	CoUninitialize();	// CoUninitializeで終了処理.

	// プログラムの終了.
	return 0;	// 0を返して終了.

}