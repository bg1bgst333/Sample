// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR対応

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]) {	// main関数のTCHAR版.

	// 変数の宣言と初期化.
	HRESULT hr;		// CLSIDFromProgIDの結果を格納するhr.
	CLSID clsid;	// CLSIDを格納するclsid.
	WCHAR *lpwszCLSID;	// CLSID文字列を指すWCHARポインタlpwszCLSID.

	// COMの初期化.
	CoInitialize(NULL);	// CoInitializeでCOMを初期化.

	// WordのProgIDからCLSIDを取得.
	hr = CLSIDFromProgID(_T("Word.Application"), &clsid);	// CLSIDFromProgIDで"Word.Application"のclsidを取得.
	if (FAILED(hr)) {	// 失敗.
		_tprintf(_T("CLSIDFromProgID NG!\n"));	// "CLSIDFromProgID NG!"と出力.
		CoUninitialize();	// CoUninitializeで終了処理.
		return -1;	// -1を返して終了.
	}

	// clsidを文字列に変換し, 出力.
	StringFromCLSID(clsid, &lpwszCLSID);	// clsidをlpwszCLSIDに変換.
	wprintf(L"lpwszCLSID = %s\n", lpwszCLSID);	// lpwszCLSIDを出力.

	// lpwszCLSIDの解放.
	CoTaskMemFree(lpwszCLSID);	// CoTaskMemFreeでlpwszCLSIDを解放.

	// COMの終了処理.
	CoUninitialize();	// CoUninitializeで終了処理.

	// プログラムの終了.
	return 0;	// 0を返して終了.

}