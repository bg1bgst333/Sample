// カスタムウィンドウクラスCCustomWindowの定義
class CCustomWindow : public CWindowImpl<CCustomWindow>{	// CWindowImpl<CCustomWindow>の派生クラスとして, CCustomWindowを定義.

	// publicメンバ
	public:

		// ウィンドウクラス名登録マクロ
		DECLARE_WND_CLASS(_T("CCustomWindow"));	// マクロDECLARE_WND_CLASSでウィンドウクラス名"CCustomWindow"を登録.

	// privateメンバ
	private:

		// メッセーマップマクロ
		BEGIN_MSG_MAP(CCustomWindow)
		END_MSG_MAP()

};