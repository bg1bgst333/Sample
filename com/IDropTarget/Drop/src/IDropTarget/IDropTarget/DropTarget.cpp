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

// DragEnterメソッド.(ドラッグがウィンドウに入ってきたとき.)
STDMETHODIMP CDropTarget::DragEnter(IDataObject *pDataObj, DWORD grfKeyState, POINTL pt, DWORD *pdwEffect){

	// コピー効果ありとして受け入れる.
	*pdwEffect = DROPEFFECT_COPY;	// *pdwEffectにDROPEFFECT_COPYをセット.(これでドラッグ中のカーソルが「コピー」アイコンになる.)

	// タイトルバーに, ドラッグが入ってきたことを表示する.
	SetWindowText(m_hWnd, _T("IDropTarget (DragEnter!)"));	// SetWindowTextでタイトルバーを書き換える.

	// S_OKを返す.
	return S_OK;	// S_OKを返す.

}

// DragOverメソッド.(ドラッグ中, ウィンドウ内でマウスが動いたとき.)
STDMETHODIMP CDropTarget::DragOver(DWORD grfKeyState, POINTL pt, DWORD *pdwEffect){

	// DragEnterと同様, コピー効果ありのままにしておく.
	*pdwEffect = DROPEFFECT_COPY;	// *pdwEffectにDROPEFFECT_COPYをセット.

	// タイトルバーに, ドラッグ中であることを表示する.
	SetWindowText(m_hWnd, _T("IDropTarget (DragOver!)"));	// SetWindowTextでタイトルバーを書き換える.

	// S_OKを返す.
	return S_OK;	// S_OKを返す.

}

// DragLeaveメソッド.(ドラッグがウィンドウから出て行ったとき.)
STDMETHODIMP CDropTarget::DragLeave(){

	// タイトルバーに, ドラッグが出て行ったことを表示する.
	SetWindowText(m_hWnd, _T("IDropTarget (DragLeave!)"));	// SetWindowTextでタイトルバーを書き換える.

	// S_OKを返す.
	return S_OK;	// S_OKを返す.

}

// Dropメソッド.(ウィンドウ内でドロップされたとき.まだ中身(pDataObj)は見ず, 他の引数(座標・修飾キー・効果)を深掘りする.)
STDMETHODIMP CDropTarget::Drop(IDataObject *pDataObj, DWORD grfKeyState, POINTL pt, DWORD *pdwEffect){

	// このメソッドのローカル変数の宣言
	TCHAR tszTitle[256];	// タイトルバーに表示する文字列を組み立てるTCHAR型配列tszTitle.
	POINT ptClient;			// クライアント座標に変換したドロップ位置を格納するPOINT型変数ptClient.
	LPCTSTR lpctszKeys;		// 押されていた修飾キーを表す文字列へのポインタlpctszKeys.
	LPCTSTR lpctszEffect;	// 選んだ効果を表す文字列へのポインタlpctszEffect.
	DWORD dwChosenEffect;	// 実際に選択する効果を格納するDWORD型変数dwChosenEffect.

	// ptはスクリーン座標(POINTL型)なので, POINT型に詰め替えてからScreenToClientでクライアント座標へ変換する.
	ptClient.x = pt.x;	// ptClient.xにpt.xを代入.
	ptClient.y = pt.y;	// ptClient.yにpt.yを代入.
	ScreenToClient(m_hWnd, &ptClient);	// ScreenToClientでスクリーン座標をクライアント座標へ変換.

	// grfKeyStateのビットを見て, 押されていた修飾キーに応じて選ぶ効果を決める.(Ctrl=コピー, Shift=移動, どちらも無しなら既定でコピー, というWindowsの標準的な慣習.)
	if (grfKeyState & MK_CONTROL){	// Ctrlキーが押されていた場合.(MK_CONTROLはwinuser.hで定義されているビットフラグ.)

		lpctszKeys = _T("Ctrl");	// lpctszKeysに"Ctrl"をセット.
		dwChosenEffect = DROPEFFECT_COPY;	// Ctrl押下時はコピー効果を選ぶ.

	}
	else if (grfKeyState & MK_SHIFT){	// Shiftキーが押されていた場合.

		lpctszKeys = _T("Shift");	// lpctszKeysに"Shift"をセット.
		dwChosenEffect = DROPEFFECT_MOVE;	// Shift押下時は移動効果を選ぶ.

	}
	else{	// どちらも押されていない場合.

		lpctszKeys = _T("なし");	// lpctszKeysに"なし"をセット.
		dwChosenEffect = DROPEFFECT_COPY;	// 既定はコピー効果にしておく.

	}

	// 選んだ効果を表す文字列を用意する.
	lpctszEffect = (dwChosenEffect == DROPEFFECT_COPY) ? _T("Copy") : _T("Move");	// dwChosenEffectに応じて"Copy"か"Move"をlpctszEffectにセット.

	// *pdwEffectに選んだ効果を書き込む.(呼び出し元(OLE側)はこの値を見て, ドロップ完了時のカーソル・アイコンの見た目を決める.)
	*pdwEffect = dwChosenEffect;	// *pdwEffectにdwChosenEffectをセット.

	// タイトルバーに, クライアント座標・修飾キー・選んだ効果をまとめて表示する.
	wsprintf(tszTitle, _T("IDropTarget (Drop! pt=(%d,%d) keys=%s effect=%s)"), ptClient.x, ptClient.y, lpctszKeys, lpctszEffect);	// wsprintfで座標・修飾キー・効果を埋め込んだ文字列を組み立てる.
	SetWindowText(m_hWnd, tszTitle);	// SetWindowTextでタイトルバーを書き換える.

	// S_OKを返す.
	return S_OK;	// S_OKを返す.

}
