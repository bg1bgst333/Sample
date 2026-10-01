// 二重インクルード防止
#ifndef __DROPSOURCE_H__
#define __DROPSOURCE_H__

// ヘッダのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <ole2.h>		// IDropSource

// CDropSourceクラスの定義.(IDropSourceを実装するクラス. 今回はインターフェース導入回として, 標準的な最小実装にする.)
class CDropSource : public IDropSource{

	// privateメンバ
	private:

		// privateメンバ変数
		LONG m_lRef;	// 参照カウントm_lRef.

	// publicメンバ
	public:

		// publicメンバ関数
		// コンストラクタ
		CDropSource();	// コンストラクタCDropSource.

		// IUnknownのメソッド
		STDMETHODIMP QueryInterface(REFIID riid, LPVOID *ppv);	// QueryInterfaceメソッド.
		STDMETHODIMP_(ULONG) AddRef();								// AddRefメソッド.
		STDMETHODIMP_(ULONG) Release();								// Releaseメソッド.

		// IDropSourceのメソッド
		STDMETHODIMP QueryContinueDrag(BOOL fEscapePressed, DWORD grfKeyState);	// QueryContinueDragメソッド.(ドラッグを続けるかどうかをOLE側から問い合わせられる.)
		STDMETHODIMP GiveFeedback(DWORD dwEffect);									// GiveFeedbackメソッド.(ドラッグ中のカーソル表示を自分で決めるか, 既定に任せるかを答える. 今回は既定に任せる最小実装. カーソルの作り込みは次回のIDropSource::GiveFeedbackで扱う.)

};

#endif
