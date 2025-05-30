// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR対応

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]) {	// main関数のTCHAR版.

	// 変数の宣言と初期化.
	HRESULT hr;		// 結果を格納するhr.
	ITypeLib *pTypeLib = NULL;	// ITypeLibポインタpTypeLibをNULLで初期化.

	// COMの初期化.
	CoInitialize(NULL);	// CoInitializeでCOMを初期化.

	// 引数は1番目だけ受け付ける.
	if (argc != 2) {	// 引数が2つ以外.

		// 異常終了
		CoUninitialize();	// CoUninitializeで終了処理.
		return -1;	// -1を返して終了.

	}

	// タイプライブラリのロード.
	hr = LoadTypeLib(argv[1], &pTypeLib);	// LoadTypeLibでタイプライブラリのロード.
	if (FAILED(hr)) {	// 失敗.
		_tprintf(_T("LoadTypeLib NG!\n"));	// "LoadTypeLib NG!"と出力.
		CoUninitialize();	// CoUninitializeで終了処理.
		return -2;	// -2を返して終了.
	}

	// 取得したITypeLibインターフェースポインタpTypeLibを出力.
	_tprintf(_T("pTypeLib = 0x%08x\n"), (unsigned long)pTypeLib);	// pTypeLibを出力.

	// ITypeInfoポインタの数を取得.
	int nCount = pTypeLib->GetTypeInfoCount();	// ITypeLib::GetTypeInfoCountでITypeInfoポインタの数を取得.
	_tprintf(_T("nCount = %d\n"), nCount);	// nCountを出力.

	// pTypeLibの解放.
	if (pTypeLib != NULL) {
		pTypeLib->Release();
	}

	// COMの終了処理.
	CoUninitialize();	// CoUninitializeで終了処理.

	// プログラムの終了.
	return 0;	// 0を返して終了.

}