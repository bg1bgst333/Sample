// ヘッダのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR対応
// 独自のヘッダ
#include "Range.h"	// Excel::CRange

// コンストラクタCRange
Excel::CRange::CRange() {

}

// 引数付きコンストラクタ.(IDispatchポインタpDispatchを受け取る.)
Excel::CRange::CRange(IDispatch *pDispatch) {

	// m_pDispatchにセット.
	m_pDispatch = pDispatch;

}

// デストラクタ~CRange
Excel::CRange::~CRange() {

	// m_pDispatchの解放.
	if (m_pDispatch != NULL) {	// m_pDispatchがNULLでなければ.
		m_pDispatch->Release();	// IDispatch::Releaseで解放.
		m_pDispatch = NULL;	// NULLをセット.
	}

}

// Itemプロパティ(Rangeオブジェクト)の取得.
Excel::CRange * Excel::CRange::get_Item(int i, int j) {

	// メソッドやプロパティのDISPIDの取得.
	LPOLESTR lpwszName = L"Item";	// lpwszNameを"Item"で初期化.
	DISPID dispid;	// DISPID型dispid.
	HRESULT hr = m_pDispatch->GetIDsOfNames(IID_NULL, &lpwszName, 1, LOCALE_USER_DEFAULT, &dispid);	// IDispatch::GetIDsOfNamesでdispid取得.
	if (FAILED(hr)) {	// 失敗.
		return NULL;
	}

	// メソッドやプロパティにアクセス.
	VARIANT var[2];	// VARIANT構造体配列var.
	VARIANT varResult;	// 結果を格納するVARIANT構造体varResult.
	DISPPARAMS dispparams;	// DISPPARAMS構造体dispparams.
	DISPID dispidname = DISPID_PROPERTYPUT;	// dispidnameをDISPID_PROPERTYPUTに初期化.
	// 複数の引数の場合, 逆順なので注意.(行(i)がvar[1], 列(j)がvar[0]になる.)
	VariantInit(&var[1]);	// var[1]を初期化.
	var[1].vt = VT_I4;	// 4バイトint.
	var[1].lVal = i;	// iを代入.
	VariantInit(&var[0]);	// var[0]を初期化.
	var[0].vt = VT_I4;	// 4バイトint.
	var[0].lVal = j;	// jを代入.
	VariantInit(&varResult);	// VariantInitでvarResult初期化.
	dispparams.cArgs = 2;	// 引数の数は2.
	dispparams.rgvarg = var;	// varを指定.
	dispparams.rgdispidNamedArgs = NULL;	// NULLを指定.
	dispparams.cNamedArgs = 0;	// cNamedArgsも0.
	hr = m_pDispatch->Invoke(dispid, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_PROPERTYGET, &dispparams, &varResult, NULL, NULL);	// IDispatch::Invokeでアクセス.
	if (FAILED(hr)) {	// 失敗.
		return NULL;
	}

	// 成功.
	CRange *pRange = new CRange(varResult.pdispVal);	// CRangeのコンストラクタにvarResult.pdispValをセット.
	return pRange;

}

// Valueプロパティの設定.
BOOL Excel::CRange::put_Value(int iValue) {

	// メソッドやプロパティのDISPIDの取得.
	LPOLESTR lpwszName = L"Value";	// lpwszNameを"Value"で初期化.
	DISPID dispid;	// DISPID型dispid.
	HRESULT hr = m_pDispatch->GetIDsOfNames(IID_NULL, &lpwszName, 1, LOCALE_USER_DEFAULT, &dispid);	// IDispatch::GetIDsOfNamesでdispid取得.
	if (FAILED(hr)) {	// 失敗.
		return FALSE;
	}

	// 渡された引数のセット.
	VARIANT var;	// VARIANT構造体var.
	VariantInit(&var);	// varをVariantInitで初期化.
	var.vt = VT_I4;
	var.lVal = iValue;
	VARIANT varResult;	// VARIANT構造体varResult.
	VariantInit(&varResult);	// varResultをVariantInitで初期化.
	// メソッドやプロパティにアクセス.
	DISPPARAMS dispparams;	// DISPPARAMS構造体dispparams.
	DISPID dispidname = DISPID_PROPERTYPUT;	// dispidnameをDISPID_PROPERTYPUTに初期化.
	dispparams.cArgs = 1;	// 引数の数は1.
	dispparams.rgvarg = &var;	// &varを指定.
	dispparams.rgdispidNamedArgs = &dispidname;	// &dispidnameを指定.
	dispparams.cNamedArgs = 1;	// cNamedArgsも1.
	hr = m_pDispatch->Invoke(dispid, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_PROPERTYPUT, &dispparams, &varResult, NULL, NULL);	// IDispatch::Invokeでアクセス.
	if (FAILED(hr)) {	// 失敗.
		return FALSE;
	}

	// 成功.
	return TRUE;

}

// Valueプロパティの取得.
BOOL Excel::CRange::get_Value(VARIANT *pvarValue) {

	// メソッドやプロパティのDISPIDの取得.
	LPOLESTR lpwszName = L"Value";	// lpwszNameを"Value"で初期化.
	DISPID dispid;	// DISPID型dispid.
	HRESULT hr = m_pDispatch->GetIDsOfNames(IID_NULL, &lpwszName, 1, LOCALE_USER_DEFAULT, &dispid);	// IDispatch::GetIDsOfNamesでdispid取得.
	if (FAILED(hr)) {	// 失敗.
		return FALSE;
	}

	// メソッドやプロパティにアクセス.
	DISPPARAMS dispparams;	// DISPPARAMS構造体dispparams.
	DISPID dispidname = DISPID_PROPERTYPUT;	// dispidnameをDISPID_PROPERTYPUTに初期化.
	dispparams.cArgs = 0;	// 引数の数は0.
	dispparams.rgvarg = NULL;	// NULLを指定.
	dispparams.rgdispidNamedArgs = NULL;	// NULLを指定.
	dispparams.cNamedArgs = 0;	// cNamedArgsも0.
	hr = m_pDispatch->Invoke(dispid, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_PROPERTYGET, &dispparams, pvarValue, NULL, NULL);	// IDispatch::Invokeでアクセス.
	if (FAILED(hr)) {	// 失敗.
		return FALSE;
	}

	// 成功.
	return TRUE;

}
