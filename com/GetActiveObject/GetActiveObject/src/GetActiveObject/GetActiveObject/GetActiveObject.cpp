// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR対応

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]) {	// main関数のTCHAR版.

	// 変数の宣言と初期化.
	HRESULT hr;		// CLSIDFromProgIDの結果を格納するhr.
	CLSID clsid;	// CLSIDを格納するclsid.
	WCHAR *lpwszCLSID;	// CLSID文字列を指すWCHARポインタlpwszCLSID.
	IUnknown *pUnknown;	// IUnknownポインタpUnknown.
	IDispatch *pDispatch;	// IDispatchポインタpDispatch.

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

	// アクティブな登録済みオブジェクトの取得.
	hr = GetActiveObject(clsid, NULL, &pUnknown);	// GetActiveObjectでpUnknownを取得.
	if (FAILED(hr)) {	// 失敗.
		_tprintf(_T("GetActiveObject NG!\n"));	// "GetActiveObject NG!"と出力.
		CoTaskMemFree(lpwszCLSID);	// CoTaskMemFreeでlpwszCLSIDを解放.
		CoUninitialize();	// CoUninitializeで終了処理.
		return -2;	// -2を返して終了.
	}
	
	// GetActiveObjectは成功.
	_tprintf(_T("GetActiveObject OK!\n"));	// "GetActiveObject OK!"と出力.

	// 取得したIUnknownインターフェースポインタpUnknownを出力.
	_tprintf(_T("pUnknown = 0x%08x\n"), (unsigned long)pUnknown);	// pUnknownを出力.

	// IDispatchポインタpDispatchの取得.
	hr = pUnknown->QueryInterface(IID_PPV_ARGS(&pDispatch));	// // IUnknown::QueryInterfaceでIDispatchポインタpDispatch取得.
	if (FAILED(hr)) {	// 失敗.
		_tprintf(_T("IUnknown::QueryInterface NG!\n"));	// "IUnknown::QueryInterface NG!"と出力.
		pUnknown->Release();	// IUnknown::Releaseで解放.
		CoTaskMemFree(lpwszCLSID);	// CoTaskMemFreeでlpwszCLSIDを解放.
		CoUninitialize();	// CoUninitializeで終了処理.
		return -3;	// -3を返して終了.
	}

	// IUnknown::QueryInterfaceは成功.
	_tprintf(_T("IUnknown::QueryInterface OK!\n"));	// "IUnknown::QueryInterface OK!"と出力.

	// 取得したIDispatchインターフェースポインタpDispatchを出力.
	_tprintf(_T("pDispatch = 0x%08x\n"), (unsigned long)pDispatch);	// pDispatchを出力.
	
	// メソッドやプロパティのDISPIDの取得.
	LPOLESTR lpwszName = L"Quit";	// lpwszNameを"Quit"で初期化.
	DISPID dispid;	// DISPID型dispid.
	hr = pDispatch->GetIDsOfNames(IID_NULL, &lpwszName, 1, LOCALE_USER_DEFAULT, &dispid);	// IDispatch::GetIDsOfNamesでdispid取得.
	if (FAILED(hr)) {	// 失敗.
		_tprintf(_T("IDispatch::GetIDsOfNames NG!\n"));	// "IDispatch::GetIDsOfNames NG!"と出力.
		pDispatch->Release();	// IDispatch::Releaseで解放.
		pUnknown->Release();	// IUnknown::Releaseで解放.
		CoTaskMemFree(lpwszCLSID);	// CoTaskMemFreeでlpwszCLSIDを解放.
		CoUninitialize();	// CoUninitializeで終了処理.
		return -4;	// -4を返して終了.
	}

	// IDispatch::GetIDsOfNamesは成功.
	_tprintf(_T("IDispatch::GetIDsOfNames OK!\n"));	// "IDispatch::GetIDsOfNames OK!"と出力.

	// 取得したdispidを出力.
	_tprintf(_T("dispid = %d\n"), dispid);	// dispidを出力.

	// メソッドやプロパティにアクセス.
	DISPPARAMS dispparams;	// DISPPARAMS構造体dispparams.
	dispparams.cArgs = 0;	// 引数の数は0.
	dispparams.rgvarg = NULL;	// NULLを指定.
	dispparams.rgdispidNamedArgs = NULL;	// NULLを指定.
	dispparams.cNamedArgs = 0;	// cNamedArgsは0.
	hr = pDispatch->Invoke(dispid, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_METHOD, &dispparams, NULL, NULL, NULL);	// IDispatch::Invokeでアクセス.
	if (FAILED(hr)) {	// 失敗.
		_tprintf(_T("IDispatch::Invoke NG!\n"));	// "IDispatch::Invoke NG!"と出力.
		pDispatch->Release();	// IDispatch::Releaseで解放.
		pUnknown->Release();	// IUnknown::Releaseで解放.
		CoTaskMemFree(lpwszCLSID);	// CoTaskMemFreeでlpwszCLSIDを解放.
		CoUninitialize();	// CoUninitializeで終了処理.
		return -5;	// -5を返して終了.
	}

	// IDispatch::Invokeは成功.
	_tprintf(_T("IDispatch::Invoke OK!\n"));	// "IDispatch::Invoke OK!"と出力.

	// pDispatchの解放.
	pDispatch->Release();	// IDispatch::Releaseで解放.

	// pUnknownの解放.
	pUnknown->Release();	// IUnknown::Releaseで解放.

	// lpwszCLSIDの解放.
	CoTaskMemFree(lpwszCLSID);	// CoTaskMemFreeでlpwszCLSIDを解放.

	// COMの終了処理.
	CoUninitialize();	// CoUninitializeで終了処理.

	// プログラムの終了.
	return 0;	// 0を返して終了.

}