// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR対応

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]) {	// main関数のTCHAR版.

	// 変数の宣言と初期化.
	HRESULT hr;		// CLSIDFromProgIDの結果を格納するhr.
	CLSID clsid;	// CLSIDを格納するclsid.
	WCHAR *lpwszCLSID;	// CLSID文字列を指すWCHARポインタlpwszCLSID.
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

	// IDispatchポインタpDispatchの取得.
	hr = CoCreateInstance(clsid, NULL, CLSCTX_LOCAL_SERVER, IID_PPV_ARGS(&pDispatch));	// CoCreateInstanceで, pDispatchを生成.
	if (FAILED(hr)) {	// 失敗.
		_tprintf(_T("CoCreateInstance(IDispatch) NG!\n"));	// "CoCreateInstance(IDispatch) NG!"と出力.
		CoTaskMemFree(lpwszCLSID);	// CoTaskMemFreeでlpwszCLSIDを解放.
		CoUninitialize();	// CoUninitializeで終了処理.
		return -2;	// -2を返して終了.
	}

	// CoCreateInstanceは成功.
	_tprintf(_T("CoCreateInstance(IDispatch) OK!\n"));	// "CoCreateInstance(IDispatch) OK!"と出力.

	// 取得したIDispatchインターフェースポインタpDispatchを出力.
	_tprintf(_T("pDispatch = 0x%08x\n"), (unsigned long)pDispatch);	// pDispatchを出力.
	
	// メソッドやプロパティのDISPIDの取得.
	LPOLESTR lpwszName = L"Visible";	// lpwszNameを"Visible"で初期化.
	DISPID dispid;	// DISPID型dispid.
	hr = pDispatch->GetIDsOfNames(IID_NULL, &lpwszName, 1, LOCALE_USER_DEFAULT, &dispid);	// IDispatch::GetIDsOfNamesでdispid取得.
	if (FAILED(hr)) {	// 失敗.
		_tprintf(_T("IDispatch::GetIDsOfNames NG!\n"));	// "IDispatch::GetIDsOfNames NG!"と出力.
		pDispatch->Release();	// IDispatch::Releaseで解放.
		CoTaskMemFree(lpwszCLSID);	// CoTaskMemFreeでlpwszCLSIDを解放.
		CoUninitialize();	// CoUninitializeで終了処理.
		return -3;	// -3を返して終了.
	}

	// IDispatch::GetIDsOfNamesは成功.
	_tprintf(_T("IDispatch::GetIDsOfNames OK!\n"));	// "IDispatch::GetIDsOfNames OK!"と出力.

	// 取得したdispidを出力.
	_tprintf(_T("dispid = %d\n"), dispid);	// dispidを出力.

	// メソッドやプロパティにアクセス.
	VARIANT var;	// VARIANT構造体var.
	DISPPARAMS dispparams;	// DISPPARAMS構造体dispparams.
	DISPID dispidname = DISPID_PROPERTYPUT;	// dispidnameをDISPID_PROPERTYPUTに初期化.
	var.vt = VT_I4;	// 4バイトint.
	var.lVal = 1;	// 値は1.
	dispparams.cArgs = 1;	// 引数の数は1.
	dispparams.rgvarg = &var;	// &varを指定.
	dispparams.rgdispidNamedArgs = &dispidname;	// &dispidnameを指定.
	dispparams.cNamedArgs = 1;	// cNamedArgsも1.
	hr = pDispatch->Invoke(dispid, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_PROPERTYPUT, &dispparams, NULL, NULL, NULL);	// IDispatch::Invokeでアクセス.
	if (FAILED(hr)) {	// 失敗.
		_tprintf(_T("IDispatch::Invoke NG!\n"));	// "IDispatch::Invoke NG!"と出力.
		pDispatch->Release();	// IDispatch::Releaseで解放.
		CoTaskMemFree(lpwszCLSID);	// CoTaskMemFreeでlpwszCLSIDを解放.
		CoUninitialize();	// CoUninitializeで終了処理.
		return -4;	// -4を返して終了.
	}

	// IDispatch::Invokeは成功.
	_tprintf(_T("IDispatch::Invoke OK!\n"));	// "IDispatch::Invoke OK!"と出力.

	// pDispatchの解放.
	pDispatch->Release();	// IDispatch::Releaseで解放.

	// lpwszCLSIDの解放.
	CoTaskMemFree(lpwszCLSID);	// CoTaskMemFreeでlpwszCLSIDを解放.

	// COMの終了処理.
	CoUninitialize();	// CoUninitializeで終了処理.

	// プログラムの終了.
	return 0;	// 0を返して終了.

}