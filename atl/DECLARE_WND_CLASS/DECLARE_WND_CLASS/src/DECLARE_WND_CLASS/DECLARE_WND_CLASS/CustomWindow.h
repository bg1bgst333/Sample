// カスタムウィンドウクラスCCustomWindowの定義
class CCustomWindow : public CWindowImpl<CCustomWindow>{	// CWindowImpl<CCustomWindow>の派生クラスとして, CCustomWindowを定義.

	// publicメンバ
	public:

		// ウィンドウクラス名登録マクロ
		DECLARE_WND_CLASS(NULL);	// マクロDECLARE_WND_CLASSにNULLを指定.

	// privateメンバ
	private:

		// メッセーマップマクロ
		BEGIN_MSG_MAP(CCustomWindow)
			MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
		END_MSG_MAP()

		// メンバ関数の定義
		// ウィンドウ破棄時のイベントハンドラOnDestroy
		LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled){

			// 終了メッセージの送信
			PostQuitMessage(0);	// PostQuitMessageで終了コードを0としてWM_QUITメッセージを送信.
			return 0;	// 0を返す.

		}

};