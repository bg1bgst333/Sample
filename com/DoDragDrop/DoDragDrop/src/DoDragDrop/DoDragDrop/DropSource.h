// 二重インクルード防止
#ifndef __DROPSOURCE_H__
#define __DROPSOURCE_H__

// ヘッダのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <ole2.h>		// IDropSource

// CDropSourceクラスの定義.(IDropSourceを実装するクラス. 今回はGiveFeedbackの中身を作り込む.)
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
		STDMETHODIMP QueryContinueDrag(BOOL fEscapePressed, DWORD grfKeyState);	// QueryContinueDragメソッド.(前回と同じ最小実装のまま. 今回の主役ではない.)
		STDMETHODIMP GiveFeedback(DWORD dwEffect);									// GiveFeedbackメソッド.(dwEffectに応じて自分でカーソルを設定する. これが今回の主役.)

};

#endif
