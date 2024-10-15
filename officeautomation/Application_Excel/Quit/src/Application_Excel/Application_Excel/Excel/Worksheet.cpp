// ヘッダのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR対応
// 独自のヘッダ
#include "Worksheet.h"	// Excel::CWorksheet

// コンストラクタCWorksheet
Excel::CWorksheet::CWorksheet() {

}

// 引数付きコンストラクタ.(IDispatchポインタpDispatchを受け取る.)
Excel::CWorksheet::CWorksheet(IDispatch *pDispatch) {

	// m_pDispatchにセット.
	m_pDispatch = pDispatch;

}

// デストラクタ~CWorksheet
Excel::CWorksheet::~CWorksheet() {

	// m_pDispatchの解放.
	if (m_pDispatch != NULL) {	// m_pDispatchがNULLでなければ.
		m_pDispatch->Release();	// IDispatch::Releaseで解放.
		m_pDispatch = NULL;	// NULLをセット.
	}

}

// Cellsプロパティ(Rangeオブジェクト)の取得.
Excel::CRange * Excel::CWorksheet::get_Cells() {

	// メソッドやプロパティのDISPIDの取得.
	LPOLESTR lpwszName = L"Cells";	// lpwszNameを"Cells"で初期化.
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
	CRange *pRange = new CRange(var.pdispVal);	// CRangeのコンストラクタにvar.pdispValをセット.
	return pRange;

}

// Cellsプロパティ(Rangeオブジェクト)の取得.(row, columnを渡す.)
Excel::CRange * Excel::CWorksheet::get_Cells(int row, int column) {

	// メソッドやプロパティのDISPIDの取得.
	LPOLESTR lpwszName = L"Cells";	// lpwszNameを"Cells"で初期化.
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
	var[1].lVal = row;	// rowを代入.
	VariantInit(&var[0]);	// var[0]を初期化.
	var[0].vt = VT_I4;	// 4バイトint.
	var[0].lVal = column;	// columnを代入.
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

// Rangeプロパティの取得.
Excel::CRange * Excel::CWorksheet::get_Range(LPCTSTR lpctszCell) {

	// メソッドやプロパティのDISPIDの取得.
	LPOLESTR lpwszName = L"Range";	// lpwszNameを"Range"で初期化.
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
	var.bstrVal = SysAllocString(lpctszCell);	// SysAllocStringでlpctszCellのBSTR生成.
	VariantInit(&varResult);	// VariantInitでvarResult初期化.
	dispparams.cArgs = 1;	// 引数の数は1.
	dispparams.rgvarg = &var;	// &varを指定.
	dispparams.rgdispidNamedArgs = NULL;	// NULLを指定.
	dispparams.cNamedArgs = 0;	// cNamedArgsも0.
	hr = m_pDispatch->Invoke(dispid, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_PROPERTYGET, &dispparams, &varResult, NULL, NULL);	// IDispatch::Invokeでアクセス.
	SysFreeString(var.bstrVal);	// SysFreeStringでvar.bstrValを破棄.
	if (FAILED(hr)) {	// 失敗.
		return NULL;
	}

	// 成功.
	CRange *pRange = new CRange(varResult.pdispVal);	// CRangeのコンストラクタにvarResult.pdispValをセット.
	return pRange;

}

// Rangeプロパティの取得.(range1, range2を渡す.)
Excel::CRange * Excel::CWorksheet::get_Range(CRange * range1, CRange * range2) {

	// メソッドやプロパティのDISPIDの取得.
	LPOLESTR lpwszName = L"Range";	// lpwszNameを"Range"で初期化.
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
	// 複数の引数の場合, 逆順なので注意.(range1がvar[1], range2がvar[0]になる.)
	VariantInit(&var[1]);	// var[1]を初期化.
	var[1].vt = VT_DISPATCH;	// VT_DISPATCH
	var[1].pdispVal = range1->m_pDispatch;	// range1->m_pDispatchを代入.
	VariantInit(&var[0]);	// var[0]を初期化.
	var[0].vt = VT_DISPATCH;	// VT_DISPATCH
	var[0].pdispVal = range2->m_pDispatch;	// range2->m_pDispatchを代入.
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

