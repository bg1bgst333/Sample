// ヘッダのインクルード
// 標準のヘッダファイル
#include <tchar.h>	// TCHAR型, _Tマクロ
// 独自のヘッダ
#include "DropTarget.h"	// CDropTarget

// コンストラクタCDropTarget.
CDropTarget::CDropTarget(HWND hWnd) : m_lRef(1), m_hWnd(hWnd){}	// m_lRefを1, m_hWndを引数hWndで初期化.

// QueryInterfaceメソッド.
STDMETHODIMP CDropTarget::QueryInterface(REFIID riid, LPVOID *ppv){

	// riidがIID_IUnknownかIID_IDropTargetの場合のみ, 自分自身のポインタを返す.
	if (riid == IID_IUnknown || riid == IID_IDropTarget){	// riidが対応しているインターフェースの場合.

		*ppv = static_cast<IDropTarget *>(this);	// *ppvに自分自身をIDropTarget*としてキャストして格納.
		AddRef();	// AddRefで参照カウントを1増やす.
		return S_OK;	// S_OKを返す.

	}

	// 対応していないインターフェースの場合.
	*ppv = NULL;	// *ppvをNULLにする.
	return E_NOINTERFACE;	// E_NOINTERFACEを返す.

}

// AddRefメソッド.
STDMETHODIMP_(ULONG) CDropTarget::AddRef(){

	// InterlockedIncrementでm_lRefを1増やして返す.
	return InterlockedIncrement(&m_lRef);	// InterlockedIncrementでm_lRefをスレッドセーフに1増やす.

}

// Releaseメソッド.
STDMETHODIMP_(ULONG) CDropTarget::Release(){

	// InterlockedDecrementでm_lRefを1減らす.
	LONG lRes = InterlockedDecrement(&m_lRef);	// InterlockedDecrementでm_lRefをスレッドセーフに1減らし, lResに結果を格納.
	if (lRes == 0){	// 0になった(誰も参照していない)場合.

		delete this;	// deleteで自分自身を破棄.

	}
	return lRes;	// lResを返す.

}

// DragEnterメソッド.(今回の主役ではないので, 最小スタブのまま.)
STDMETHODIMP CDropTarget::DragEnter(IDataObject *pDataObj, DWORD grfKeyState, POINTL pt, DWORD *pdwEffect){

	// コピー効果ありとして受け入れる.
	*pdwEffect = DROPEFFECT_COPY;	// *pdwEffectにDROPEFFECT_COPYをセット.

	// S_OKを返す.
	return S_OK;	// S_OKを返す.

}

// DragOverメソッド.(今回の主役ではないので, 最小スタブのまま.)
STDMETHODIMP CDropTarget::DragOver(DWORD grfKeyState, POINTL pt, DWORD *pdwEffect){

	// コピー効果ありのままにしておく.
	*pdwEffect = DROPEFFECT_COPY;	// *pdwEffectにDROPEFFECT_COPYをセット.

	// S_OKを返す.
	return S_OK;	// S_OKを返す.

}

// DragLeaveメソッド.(今回の主役ではないので, 最小スタブのまま.)
STDMETHODIMP CDropTarget::DragLeave(){

	// S_OKを返す.
	return S_OK;	// S_OKを返す.

}

// Dropメソッド.(今回の主役ではないので, 最小スタブのまま.)
STDMETHODIMP CDropTarget::Drop(IDataObject *pDataObj, DWORD grfKeyState, POINTL pt, DWORD *pdwEffect){

	// コピー効果ありとして返す.
	*pdwEffect = DROPEFFECT_COPY;	// *pdwEffectにDROPEFFECT_COPYをセット.

	// S_OKを返す.
	return S_OK;	// S_OKを返す.

}
