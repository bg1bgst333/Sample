// ヘッダのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR対応
// 独自のヘッダ
#include "Border.h"	// Excel::CBorder

// コンストラクタCBorder
Excel::CBorder::CBorder() {

}

// 引数付きコンストラクタ.(IDispatchポインタpDispatchを受け取る.)
Excel::CBorder::CBorder(IDispatch *pDispatch) {

	// m_pDispatchにセット.
	m_pDispatch = pDispatch;

}

// デストラクタ~CBorder
Excel::CBorder::~CBorder() {

	// m_pDispatchの解放.
	if (m_pDispatch != NULL) {	// m_pDispatchがNULLでなければ.
		m_pDispatch->Release();	// IDispatch::Releaseで解放.
		m_pDispatch = NULL;	// NULLをセット.
	}

}

// LineStyleプロパティの設定.
BOOL Excel::CBorder::put_LineStyle(XlLineStyle xlLineStyle) {

	// メソッドやプロパティのDISPIDの取得.
	LPOLESTR lpwszName = L"LineStyle";	// lpwszNameを"LineStyle"で初期化.
	DISPID dispid;	// DISPID型dispid.
	HRESULT hr = m_pDispatch->GetIDsOfNames(IID_NULL, &lpwszName, 1, LOCALE_USER_DEFAULT, &dispid);	// IDispatch::GetIDsOfNamesでdispid取得.
	if (FAILED(hr)) {	// 失敗.
		return FALSE;
	}

	// 渡された引数のセット.
	VARIANT var;	// VARIANT構造体var.
	VariantInit(&var);	// varをVariantInitで初期化.
	var.vt = VT_I4;
	var.lVal = xlLineStyle;
	// メソッドやプロパティにアクセス.
	DISPPARAMS dispparams;	// DISPPARAMS構造体dispparams.
	DISPID dispidname = DISPID_PROPERTYPUT;	// dispidnameをDISPID_PROPERTYPUTに初期化.
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

// Weightプロパティの設定.
BOOL Excel::CBorder::put_Weight(XlBorderWeight xlBorderWeight) {

	// メソッドやプロパティのDISPIDの取得.
	LPOLESTR lpwszName = L"Weight";	// lpwszNameを"Weight"で初期化.
	DISPID dispid;	// DISPID型dispid.
	HRESULT hr = m_pDispatch->GetIDsOfNames(IID_NULL, &lpwszName, 1, LOCALE_USER_DEFAULT, &dispid);	// IDispatch::GetIDsOfNamesでdispid取得.
	if (FAILED(hr)) {	// 失敗.
		return FALSE;
	}

	// 渡された引数のセット.
	VARIANT var;	// VARIANT構造体var.
	VariantInit(&var);	// varをVariantInitで初期化.
	var.vt = VT_I4;
	var.lVal = xlBorderWeight;
	// メソッドやプロパティにアクセス.
	DISPPARAMS dispparams;	// DISPPARAMS構造体dispparams.
	DISPID dispidname = DISPID_PROPERTYPUT;	// dispidnameをDISPID_PROPERTYPUTに初期化.
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
