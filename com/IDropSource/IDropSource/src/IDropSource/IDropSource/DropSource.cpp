// ヘッダのインクルード
// 標準のヘッダファイル
#include <tchar.h>	// TCHAR型, _Tマクロ
// 独自のヘッダ
#include "DropSource.h"	// CDropSource

// コンストラクタCDropSource.
CDropSource::CDropSource() : m_lRef(1){}	// m_lRefを1で初期化.

// QueryInterfaceメソッド.
STDMETHODIMP CDropSource::QueryInterface(REFIID riid, LPVOID *ppv){

	// riidがIID_IUnknownかIID_IDropSourceの場合のみ, 自分自身のポインタを返す.
	if (riid == IID_IUnknown || riid == IID_IDropSource){	// riidが対応しているインターフェースの場合.

		*ppv = static_cast<IDropSource *>(this);	// *ppvに自分自身をIDropSource*としてキャストして格納.
		AddRef();	// AddRefで参照カウントを1増やす.
		return S_OK;	// S_OKを返す.

	}

	// 対応していないインターフェースの場合.
	*ppv = NULL;	// *ppvをNULLにする.
	return E_NOINTERFACE;	// E_NOINTERFACEを返す.

}

// AddRefメソッド.
STDMETHODIMP_(ULONG) CDropSource::AddRef(){

	// InterlockedIncrementでm_lRefを1増やして返す.
	return InterlockedIncrement(&m_lRef);	// InterlockedIncrementでm_lRefをスレッドセーフに1増やす.

}

// Releaseメソッド.
STDMETHODIMP_(ULONG) CDropSource::Release(){

	// InterlockedDecrementでm_lRefを1減らす.
	LONG lRes = InterlockedDecrement(&m_lRef);	// InterlockedDecrementでm_lRefをスレッドセーフに1減らし, lResに結果を格納.
	if (lRes == 0){	// 0になった(誰も参照していない)場合.

		delete this;	// deleteで自分自身を破棄.

	}
	return lRes;	// lResを返す.

}

// QueryContinueDragメソッド.(ドラッグを続けるかどうかをOLE側から問い合わせられる. MSDN記載の標準的な実装.)
STDMETHODIMP CDropSource::QueryContinueDrag(BOOL fEscapePressed, DWORD grfKeyState){

	// ESCキーが押されていたら, ドラッグ中止.
	if (fEscapePressed){	// fEscapePressedがTRUEの場合.

		return DRAGDROP_S_CANCEL;	// DRAGDROP_S_CANCELを返す.(ドラッグを中止する, という意味.)

	}

	// マウスの左ボタンが離されていたら, ドロップ実行.
	if (!(grfKeyState & MK_LBUTTON)){	// grfKeyStateにMK_LBUTTON(左ボタン押下)ビットが立っていない場合.

		return DRAGDROP_S_DROP;	// DRAGDROP_S_DROPを返す.(ここでドロップを実行する, という意味.)

	}

	// それ以外(まだ左ボタンを押したままドラッグ中)は, ドラッグ続行.
	return S_OK;	// S_OKを返す.(ドラッグを続ける, という意味.)

}

// GiveFeedbackメソッド.(ドラッグ中のカーソル表示を自分で決めるか, 既定に任せるかを答える. 今回は最小実装として, 常に既定のカーソルに任せる. カーソルの作り込みは次回のIDropSource::GiveFeedbackで扱う.)
STDMETHODIMP CDropSource::GiveFeedback(DWORD dwEffect){

	// DRAGDROP_S_USEDEFAULTCURSORSを返す.(OLE側が選んだ既定のカーソルをそのまま使う, という意味.)
	return DRAGDROP_S_USEDEFAULTCURSORS;	// DRAGDROP_S_USEDEFAULTCURSORSを返す.

}
