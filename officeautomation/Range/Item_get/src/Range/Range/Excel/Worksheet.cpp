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
