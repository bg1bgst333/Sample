// ヘッダファイルのインクルード
#include "CFrameWnd_.h"	// CFrameWnd_クラス
#include "resource.h"	// リソースID

// CFrameWnd_のメッセージマップ
BEGIN_MESSAGE_MAP(CFrameWnd_, CFrameWnd)
	ON_UPDATE_COMMAND_UI(ID_ITEM_1_1, OnUpdateItem1_1)	// メニュー項目などのUI更新マクロ.(Item1_1)
	ON_COMMAND(ID_ITEM_1_1, OnItem1_1)	// メニュー項目などのコマンドマクロ.(Item1_1)
	ON_UPDATE_COMMAND_UI(ID_ITEM_1_2, OnUpdateItem1_2)	// メニュー項目などのUI更新マクロ.(Item1_2)
	ON_COMMAND(ID_ITEM_1_2, OnItem1_2)	// メニュー項目などのコマンドマクロ.(Item1_2)
	ON_UPDATE_COMMAND_UI(ID_ITEM_1_3, OnUpdateItem1_3)	// メニュー項目などのUI更新マクロ.(Item1_3)
	ON_COMMAND(ID_ITEM_1_3, OnItem1_3)	// メニュー項目などのコマンドマクロ.(Item1_3)
	ON_UPDATE_COMMAND_UI(ID_ITEM_1_4, OnUpdateItem1_4)	// メニュー項目などのUI更新マクロ.(Item1_4)
	ON_COMMAND(ID_ITEM_1_4, OnItem1_4)	// メニュー項目などのコマンドマクロ.(Item1_4)
END_MESSAGE_MAP()

// CFrameWnd_のメンバの定義
// コンストラクタCFrameWnd_()
CFrameWnd_::CFrameWnd_(){	// 初期化処理

	// メンバの初期化.
	m_bAutoMenuEnable = FALSE;	// これを指定しないと無効やグレーアウトにならないので注意!

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

	// Item1-4をMF_DISABLEDにセット.
	CMenu *pMenu = GetMenu();	// メニューの取得.
	CMenu *pSubMenu = pMenu->GetSubMenu(0);	// 0番目のサブメニュー取得.
	pSubMenu->EnableMenuItem(ID_ITEM_1_4, MF_BYCOMMAND | MF_DISABLED);	// pSubMenu->EnableMenuItemでID_ITEM_1_4をMF_DISABLEDにする.

}

// ハンドラOnUpdateItem1_2()
void CFrameWnd_::OnUpdateItem1_2(CCmdUI* pCmdUI){	// メニュー項目Item1_2のUI更新ハンドラ

	// メニュー項目Item1_2のUI更新
	if (pCmdUI){	// pCmdUIがNULLでないなら.

		// メニュー項目Item1_2の有効化
		pCmdUI->Enable();	// EnableでItem1_2を有効にする.(デフォルト引数はTRUE.)

	}

}

// ハンドラOnItem1_2()
void CFrameWnd_::OnItem1_2(){	// メニュー項目Item1_2のコマンドハンドラ

	// Item1-4をMF_ENABLEDにセット.
	CMenu *pMenu = GetMenu();	// メニューの取得.
	CMenu *pSubMenu = pMenu->GetSubMenu(0);	// 0番目のサブメニュー取得.
	pSubMenu->EnableMenuItem(ID_ITEM_1_4, MF_BYCOMMAND | MF_ENABLED);	// pSubMenu->EnableMenuItemでID_ITEM_1_4をMF_ENABLEDにする.

}

// ハンドラOnUpdateItem1_3()
void CFrameWnd_::OnUpdateItem1_3(CCmdUI* pCmdUI){	// メニュー項目Item1_3のUI更新ハンドラ

	// メニュー項目Item1_3のUI更新
	if (pCmdUI){	// pCmdUIがNULLでないなら.

		// メニュー項目Item1_3の有効化
		pCmdUI->Enable();	// EnableでItem1_3を有効にする.(デフォルト引数はTRUE.)

	}

}

// ハンドラOnItem1_3()
void CFrameWnd_::OnItem1_3(){	// メニュー項目Item1_3のコマンドハンドラ

	// Item1-4をMF_GRAYEDにセット.
	CMenu *pMenu = GetMenu();	// メニューの取得.
	CMenu *pSubMenu = pMenu->GetSubMenu(0);	// 0番目のサブメニュー取得.
	pSubMenu->EnableMenuItem(ID_ITEM_1_4, MF_BYCOMMAND | MF_GRAYED);	// pSubMenu->EnableMenuItemでID_ITEM_1_4をMF_GRAYEDにする.

}

// ハンドラOnUpdateItem1_4()
void CFrameWnd_::OnUpdateItem1_4(CCmdUI* pCmdUI){	// メニュー項目Item1_4のUI更新ハンドラ

	// ここもコメントアウトしないと無効やグレーアウトにならない模様.
#if 0
	// メニュー項目Item1_4のUI更新
	if (pCmdUI){	// pCmdUIがNULLでないなら.

		// メニュー項目Item1_4の有効化
		pCmdUI->Enable();	// EnableでItem1_4を有効にする.(デフォルト引数はTRUE.)

	}
#endif

}

// ハンドラOnItem1_4()
void CFrameWnd_::OnItem1_4(){	// メニュー項目Item1_4のコマンドハンドラ

}