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
	ITypeInfo *pTypeInfo;	// ITypeInfoポインタpTypeInfo.
	TYPEATTR *pTypeAttr;	// TYPEATTR構造体ポインタpTypeAttr.

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

	// ITypeInfoポインタpTypeInfoの取得.
	hr = pDispatch->GetTypeInfo(0, 0, &pTypeInfo);	// IDispatch::GetTypeInfoでITypeInfoポインタpTypeInfo取得.
	if (FAILED(hr)) {	// 失敗.
		_tprintf(_T("IDispatch::GetTypeInfo NG!\n"));	// "IDispatch::GetTypeInfo NG!"と出力.
		pDispatch->Release();	// IDispatch::Releaseで解放.
		CoTaskMemFree(lpwszCLSID);	// CoTaskMemFreeでlpwszCLSIDを解放.
		CoUninitialize();	// CoUninitializeで終了処理.
		return -3;	// -3を返して終了.
	}

	// IDispatch::GetTypeInfoは成功.
	_tprintf(_T("IDispatch::GetTypeInfo OK!\n"));	// "IDispatch::GetTypeInfo OK!"と出力.

	// 取得したITypeInfoインターフェースポインタpTypeInfoを出力.
	_tprintf(_T("pTypeInfo = 0x%08x\n"), (unsigned long)pTypeInfo);	// pTypeInfoを出力.

	// 型の属性の取得.
	hr = pTypeInfo->GetTypeAttr(&pTypeAttr);	// ITypeInfo::GetTypeAttrで型の属性を取得.
	if (FAILED(hr)) {	// 失敗.
		_tprintf(_T("ITypeInfo::GetTypeAttr NG!\n"));	// "ITypeInfo::GetTypeAttr NG!"と出力.
		pTypeInfo->Release();	// ITypeInfo::Releaseで解放.
		pDispatch->Release();	// IDispatch::Releaseで解放.
		CoTaskMemFree(lpwszCLSID);	// CoTaskMemFreeでlpwszCLSIDを解放.
		CoUninitialize();	// CoUninitializeで終了処理.
		return -4;	// -4を返して終了.
	}

	// ITypeInfo::GetTypeAttrは成功.
	_tprintf(_T("ITypeInfo::GetTypeAttr OK!\n"));	// "ITypeInfo::GetTypeAttr OK!"と出力.

	// 取得したTYPEATTR構造体ポインタpTypeAttrを出力.
	_tprintf(_T("pTypeAttr = 0x%08x\n"), (unsigned long)pTypeAttr);	// pTypeAttrを出力.

	// pTypeAttrの解放.
	pTypeInfo->ReleaseTypeAttr(pTypeAttr);	// ITypeInfo::ReleaseTypeAttrでpTypeAttrを解放.

	// pTypeInfoの解放.
	pTypeInfo->Release();	// ITypeInfo::Releaseで解放.

	// pDispatchの解放.
	pDispatch->Release();	// IDispatch::Releaseで解放.

	// lpwszCLSIDの解放.
	CoTaskMemFree(lpwszCLSID);	// CoTaskMemFreeでlpwszCLSIDを解放.

	// COMの終了処理.
	CoUninitialize();	// CoUninitializeで終了処理.

	// プログラムの終了.
	return 0;	// 0を返して終了.

}