// ヘッダのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR対応
// 独自のヘッダ
#include "Workbooks.h"	// Word::CWorkbooks

// コンストラクタCWorkbooks
Excel::CWorkbooks::CWorkbooks() {

}

// 引数付きコンストラクタ.(IDispatchポインタpDispatchを受け取る.)
Excel::CWorkbooks::CWorkbooks(IDispatch *pDispatch) {

	// m_pDispatchにセット.
	m_pDispatch = pDispatch;

}

// デストラクタ~CWorkbooks
Excel::CWorkbooks::~CWorkbooks() {

	// m_pDispatchの解放.
	if (m_pDispatch != NULL) {	// m_pDispatchがNULLでなければ.
		m_pDispatch->Release();	// IDispatch::Releaseで解放.
		m_pDispatch = NULL;	// NULLをセット.
	}

}

// Workbookの追加.
Excel::CWorkbook * Excel::CWorkbooks::Add() {

	// メソッドやプロパティのDISPIDの取得.
	LPOLESTR lpwszName = L"Add";	// lpwszNameを"Add"で初期化.
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
	hr = m_pDispatch->Invoke(dispid, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_METHOD, &dispparams, &var, NULL, NULL);	// IDispatch::Invokeでアクセス.
	if (FAILED(hr)) {	// 失敗.
		return NULL;
	}

	// 成功.
	CWorkbook *pWorkbook = new CWorkbook(var.pdispVal);	// CWorkbookのコンストラクタにvar.pdispValをセット.
	return pWorkbook;

}

// 指定のWorkbookを開く.
Excel::CWorkbook * Excel::CWorkbooks::Open(LPCTSTR lpctszFileName) {

	// メソッドやプロパティのDISPIDの取得.
	LPOLESTR lpwszName = L"Open";	// lpwszNameを"Open"で初期化.
	DISPID dispid;	// DISPID型dispid.
	HRESULT hr = m_pDispatch->GetIDsOfNames(IID_NULL, &lpwszName, 1, LOCALE_USER_DEFAULT, &dispid);	// IDispatch::GetIDsOfNamesでdispid取得.
	if (FAILED(hr)) {	// 失敗.
		return NULL;
	}

	// メソッドやプロパティにアクセス.
	VARIANT var;	// VARIANT構造体var.
	VARIANT varResult;	// 結果を格納するVARIANT構造体varResult.
	DISPPARAMS dispparams;	// DISPPARAMS構造体dispparams.
	DISPID dispidname = DISPID_PROPERTYPUT;	// dispidnameをDISPID_PROPERTYPUTに初期化.
	var.vt = VT_BSTR;	// 文字列
	var.bstrVal = SysAllocString(lpctszFileName);	// SysAllocStringでlpctszFileNameのBSTR生成.
	VariantInit(&varResult);	// VariantInitでvarResult初期化.
	dispparams.cArgs = 1;	// 引数の数は1.
	dispparams.rgvarg = &var;	// &varを指定.
	dispparams.rgdispidNamedArgs = NULL;	// NULLを指定.
	dispparams.cNamedArgs = 0;	// cNamedArgsも0.
	hr = m_pDispatch->Invoke(dispid, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_METHOD, &dispparams, &varResult, NULL, NULL);	// IDispatch::Invokeでアクセス.
	SysFreeString(var.bstrVal);	// SysFreeStringでvar.bstrValを破棄.
	if (FAILED(hr)) {	// 失敗.
		return NULL;
	}

	// 成功.
	CWorkbook *pWorkbook = new CWorkbook(varResult.pdispVal);	// CWorkbookのコンストラクタにvarResult.pdispValをセット.
	return pWorkbook;

}
