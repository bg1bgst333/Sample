// ヘッダファイルのインクルード
#include "CFrameWnd_.h"	// CFrameWnd_クラス
#include "resource.h"	// リソースID

// CFrameWnd_のメッセージマップ
BEGIN_MESSAGE_MAP(CFrameWnd_, CFrameWnd)
	ON_UPDATE_COMMAND_UI(ID_ITEM_1_1, OnUpdateItem1_1)	// メニュー項目などのUI更新マクロ.(Item1_1)
	ON_COMMAND(ID_ITEM_1_1, OnItem1_1)	// メニュー項目などのコマンドマクロ.(Item1_1)
END_MESSAGE_MAP()

// CFrameWnd_のメンバの定義
// コンストラクタCFrameWnd_()
CFrameWnd_::CFrameWnd_(){	// 初期化処理

}

// ハンドラOnUpdateItem1_1()
void CFrameWnd_::OnUpdateItem1_1(CCmdUI* pCmdUI){	// メニュー項目Item1_1のUI更新ハンドラ

	// メニュー項目Item1_1のUI更新
	if (pCmdUI){	// pCmdUIがNULLでないなら.

		// メニュー項目Item1_1の有効化
		pCmdUI->Enable();	// EnableでItem1_1を有効にする.(デフォルト引数はTRUE.)

	}

}

// ハンドラOnItem1_1()
void CFrameWnd_::OnItem1_1(){	// メニュー項目Item1_1のコマンドハンドラ

	// メニューの差し替え.
	CMenu *pMenu = CMenu::FromHandle(m_hMenuDefault);	// デフォルトメニューm_hMenuDefaultを元にCMenu::FromHandleでCMenuオブジェクトポインタ取得.
	SetMenu(NULL);	// CWnd::SetMenu(NULL)でメニューを外す.
	CMenu::DeleteTempMap();
	pMenu->DestroyMenu();	// CMenu::DestroyMenuでメニューを破棄.
	CMenu cNewMenu;	// CMenuオブジェクトcNewMenu.
	cNewMenu.CreateMenu();	// cNewMenu.CreateMenuでメニュー作成.
	cNewMenu.AppendMenu(MF_ENABLED | MF_STRING, 102, _T("Item2"));	// cNewMenu.AppendMenuでItem2を追加.
	SetMenu(&cNewMenu);	// SetMenuでcNewMenuのアドレスをセット.
	m_hMenuDefault = cNewMenu.m_hMenu;	// m_hMenuDefaultにcNewMenu.m_hMenuをセット.

}