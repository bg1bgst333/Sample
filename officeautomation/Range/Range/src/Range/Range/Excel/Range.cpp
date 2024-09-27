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