// ヘッダのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR対応
// 独自のヘッダ
#include "Application.h"	// Word::CApplication

// コンストラクタCApplication
Excel::CApplication::CApplication() {

}

// staticな生成関数CreateInstance.
Excel::CApplication * Excel::CApplication::CreateInstance() {

	// 変数の宣言と初期化.
	CLSID clsid;	// CLSIDを格納するclsid.
	IDispatch * pDispatch = NULL;	// IDispatchポインタpDispatchをNULLで初期化.

	// "Excel.Application"のCLSIDの取得.
	HRESULT hr = CLSIDFromProgID(_T("Excel.Application"), &clsid);	// CLSIDFromProgIDで"Excel.Application"のclsidを取得.
	if (FAILED(hr)) {	// 失敗.
		return NULL;
	}

	// IDispatchポインタpDispatchの取得.
	hr = CoCreateInstance(clsid, NULL, CLSCTX_LOCAL_SERVER, IID_PPV_ARGS(&pDispatch));	// CoCreateInstanceで, pDispatchを生成.
	if (FAILED(hr)) {	// 失敗.
		return NULL;
	}

	// 成功.
	CApplication *pApplication = new CApplication();
	pApplication->m_pDispatch = pDispatch;
	return pApplication;

}

// デストラクタ~CApplication
Excel::CApplication::~CApplication() {

	// m_pDispatchの解放.
	if (m_pDispatch != NULL) {	// m_pDispatchがNULLでなければ.
		m_pDispatch->Release();	// IDispatch::Releaseで解放.
		m_pDispatch = NULL;	// NULLをセット.
	}

}

// 表示・非表示プロパティの設定.
BOOL Excel::CApplication::put_Visible(BOOL bVisible) {

	// メソッドやプロパティのDISPIDの取得.
	LPOLESTR lpwszName = L"Visible";	// lpwszNameを"Visible"で初期化.
	DISPID dispid;	// DISPID型dispid.
	HRESULT hr = m_pDispatch->GetIDsOfNames(IID_NULL, &lpwszName, 1, LOCALE_USER_DEFAULT, &dispid);	// IDispatch::GetIDsOfNamesでdispid取得.
	if (FAILED(hr)) {	// 失敗.
		return FALSE;
	}

	// メソッドやプロパティにアクセス.
	VARIANT var;	// VARIANT構造体var.
	DISPPARAMS dispparams;	// DISPPARAMS構造体dispparams.
	DISPID dispidname = DISPID_PROPERTYPUT;	// dispidnameをDISPID_PROPERTYPUTに初期化.
	var.vt = VT_I4;	// 4バイトint.
	if (bVisible) {	// TRUEなら.
		var.lVal = 1;	// 値は1.
	}
	else {
		var.lVal = 0;	// 値は0.
	}
	dispparams.cArgs = 1;	// 引数の数は1.
	dispparams.rgvarg = &var;	// &varを指定.
	dispparams.rgdispidNamedArgs = &dispidname;	// &dispidnameを指定.
	dispparams.cNamedArgs = 1;	// cNamedArgsも1.
	hr = m_pDispatch->Invoke(dispid, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_PROPERTYPUT, &dispparams, NULL, NULL, NULL);	// IDispatch::Invokeでアクセス.
	if (FAILED(hr)) {	// 失敗.
		return FALSE;
	}

	// 成功.
	return TRUE;

}

// Workbooksオブジェクトプロパティの取得.
Excel::CWorkbooks * Excel::CApplication::get_Workbooks() {

	// メソッドやプロパティのDISPIDの取得.
	LPOLESTR lpwszName = L"Workbooks";	// lpwszNameを"Workbooks"で初期化.
	DISPID dispid;	// DISPID型dispid.
	HRESULT hr = m_pDispatch->GetIDsOfNames(IID_NULL, &lpwszName, 1, LOCALE_USER_DEFAULT, &dispid);	// IDispatch::GetIDsOfNamesでdispid取得.
	if (FAILED(hr)) {	// 失敗.
		return NULL;
	}

	// メソッドやプロパティにアクセス.
	VARIANT var;	// VARIANT構造体var.
	DISPPARAMS dispparams;	// DISPPARAMS構造体dispparams.
	DISPID dispidname = DISPID_PROPERTYPUT;	// dispidnameをDISPID_PROPERTYPUTに初期化.
	VariantInit(&var);	// varをVariantInitで初期化.
	dispparams.cArgs = 0;	// 引数の数は0.
	dispparams.rgvarg = NULL;	// NULLを指定.
	dispparams.rgdispidNamedArgs = NULL;	// NULLを指定.
	dispparams.cNamedArgs = 0;	// cNamedArgsも0.
	hr = m_pDispatch->Invoke(dispid, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_PROPERTYGET, &dispparams, &var, NULL, NULL);	// IDispatch::Invokeでアクセス.
	if (FAILED(hr)) {	// 失敗.
		return NULL;
	}

	// 成功.
	CWorkbooks *pWorkbooks = new CWorkbooks(var.pdispVal);	// CWorkbooksのコンストラクタにvar.pdispValをセット.
	return pWorkbooks;

}

// Applicationの終了.
void Excel::CApplication::Quit() {

	// メソッドやプロパティのDISPIDの取得.
	LPOLESTR lpwszName = L"Quit";	// lpwszNameを"Quit"で初期化.
	DISPID dispid;	// DISPID型dispid.
	HRESULT hr = m_pDispatch->GetIDsOfNames(IID_NULL, &lpwszName, 1, LOCALE_USER_DEFAULT, &dispid);	// IDispatch::GetIDsOfNamesでdispid取得.
	if (FAILED(hr)) {	// 失敗.
		return;
	}

	// メソッドやプロパティにアクセス.
	VARIANT var;	// VARIANT構造体var.
	DISPPARAMS dispparams;	// DISPPARAMS構造体dispparams.
	DISPID dispidname = DISPID_PROPERTYPUT;	// dispidnameをDISPID_PROPERTYPUTに初期化.
	VariantInit(&var);	// varをVariantInitで初期化.
	dispparams.cArgs = 0;	// 引数の数は0.
	dispparams.rgvarg = NULL;	// NULLを指定.
	dispparams.rgdispidNamedArgs = NULL;	// NULLを指定.
	dispparams.cNamedArgs = 0;	// cNamedArgsも0.
	hr = m_pDispatch->Invoke(dispid, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_METHOD, &dispparams, &var, NULL, NULL);	// IDispatch::Invokeでアクセス.
	if (FAILED(hr)) {	// 失敗.
		return;
	}

	// 成功.
	return;

}
