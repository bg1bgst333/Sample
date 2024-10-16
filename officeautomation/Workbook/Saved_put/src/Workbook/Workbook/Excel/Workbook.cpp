// ヘッダのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR対応
// 独自のヘッダ
#include "Workbook.h"	// Excel::CWorkbook

// コンストラクタCWorkbook
Excel::CWorkbook::CWorkbook() {

}

// 引数付きコンストラクタ.(IDispatchポインタpDispatchを受け取る.)
Excel::CWorkbook::CWorkbook(IDispatch *pDispatch) {

	// m_pDispatchにセット.
	m_pDispatch = pDispatch;

}

// デストラクタ~CCWorkbook
Excel::CWorkbook::~CWorkbook() {

	// m_pDispatchの解放.
	if (m_pDispatch != NULL) {	// m_pDispatchがNULLでなければ.
		m_pDispatch->Release();	// IDispatch::Releaseで解放.
		m_pDispatch = NULL;	// NULLをセット.
	}

}

// Worksheetsオブジェクトプロパティの取得.
Excel::CWorksheets * Excel::CWorkbook::get_Worksheets() {

	// メソッドやプロパティのDISPIDの取得.
	LPOLESTR lpwszName = L"Worksheets";	// lpwszNameを"Worksheets"で初期化.
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
	CWorksheets *pWorksheets = new CWorksheets(var.pdispVal);	// CWorksheetsのコンストラクタにvar.pdispValをセット.
	return pWorksheets;

}

// ActiveSheetプロパティ(Worksheetオブジェクト)の取得.
Excel::CWorksheet * Excel::CWorkbook::get_ActiveSheet() {

	// メソッドやプロパティのDISPIDの取得.
	LPOLESTR lpwszName = L"ActiveSheet";	// lpwszNameを"ActiveSheet"で初期化.
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
	CWorksheet *pWorksheet = new CWorksheet(var.pdispVal);	// CWorksheetのコンストラクタにvar.pdispValをセット.
	return pWorksheet;

}

// 保存済みフラグプロパティの設定.
void Excel::CWorkbook::put_Saved(BOOL bSaved) {

	// メソッドやプロパティのDISPIDの取得.
	LPOLESTR lpwszName = L"Saved";	// lpwszNameを"Saved"で初期化.
	DISPID dispid;	// DISPID型dispid.
	HRESULT hr = m_pDispatch->GetIDsOfNames(IID_NULL, &lpwszName, 1, LOCALE_USER_DEFAULT, &dispid);	// IDispatch::GetIDsOfNamesでdispid取得.
	if (FAILED(hr)) {	// 失敗.
		return;
	}

	// メソッドやプロパティにアクセス.
	VARIANT var;	// VARIANT構造体var.
	DISPPARAMS dispparams;	// DISPPARAMS構造体dispparams.
	DISPID dispidname = DISPID_PROPERTYPUT;	// dispidnameをDISPID_PROPERTYPUTに初期化.
	var.vt = VT_I4;	// 4バイトint.
	if (bSaved) {	// TRUEなら.
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
		return;
	}

	// 成功.
	return;

}
