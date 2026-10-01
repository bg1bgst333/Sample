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

// QueryContinueDragメソッド.(前回と同じ最小実装のまま. 今回の主役ではない.)
STDMETHODIMP CDropSource::QueryContinueDrag(BOOL fEscapePressed, DWORD grfKeyState){

	// ESCキーが押されていたら, ドラッグ中止.
	if (fEscapePressed){	// fEscapePressedがTRUEの場合.

		return DRAGDROP_S_CANCEL;	// DRAGDROP_S_CANCELを返す.

	}

	// マウスの左ボタンが離されていたら, ドロップ実行.
	if (!(grfKeyState & MK_LBUTTON)){	// grfKeyStateにMK_LBUTTON(左ボタン押下)ビットが立っていない場合.

		return DRAGDROP_S_DROP;	// DRAGDROP_S_DROPを返す.

	}

	// それ以外(まだ左ボタンを押したままドラッグ中)は, ドラッグ続行.
	return S_OK;	// S_OKを返す.

}

// GiveFeedbackメソッド.(dwEffectに応じて自分でカーソルを設定する. これが今回の主役.)
STDMETHODIMP CDropSource::GiveFeedback(DWORD dwEffect){

	// このメソッドのローカル変数の宣言
	HCURSOR hCursor;	// SetCursorに渡すカーソルハンドルを格納するHCURSOR型変数hCursor.

	// dwEffectの値によって, 使うシステムカーソルを切り替える.(本来は専用のカーソルリソースを用意するところだが, 今回はシステム標準カーソルで代用する.)
	switch (dwEffect){	// switch文でdwEffectの値ごとに分岐.

		case DROPEFFECT_COPY:	// コピー効果の場合.

			hCursor = LoadCursor(NULL, IDC_UPARROW);	// hCursorにIDC_UPARROW(上矢印カーソル, コピーの代用)をセット.
			break;	// breakで抜ける.

		case DROPEFFECT_MOVE:	// 移動効果の場合.

			hCursor = LoadCursor(NULL, IDC_SIZEALL);	// hCursorにIDC_SIZEALL(四方矢印, 移動の代用)をセット.
			break;	// breakで抜ける.

		case DROPEFFECT_LINK:	// リンク効果の場合.

			hCursor = LoadCursor(NULL, IDC_HAND);	// hCursorにIDC_HAND(手の形, リンクの代用)をセット.
			break;	// breakで抜ける.

		default:	// それ以外(DROPEFFECT_NONE等, 受け付けない場合).

			hCursor = LoadCursor(NULL, IDC_NO);	// hCursorにIDC_NO(禁止マーク)をセット.
			break;	// breakで抜ける.

	}

	// SetCursorで, 実際にカーソルの見た目を切り替える.
	SetCursor(hCursor);	// SetCursorにhCursorを渡し, 現在のカーソルを切り替える.

	// S_OKを返す.(自分でカーソルを設定した, つまり既定のカーソルは使わない, という意味.)
	return S_OK;	// S_OKを返す.

}
