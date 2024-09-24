// ヘッダのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR対応
// 独自のヘッダ
#include "Workbook.h"	// Word::CWorkbook

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