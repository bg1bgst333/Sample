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

	// メニューのポインタを取得.
	CMenu *pMenu = GetMenu();	// GetMenuでメニューのポインタを取得し, pMenuに格納.

	// メニューハンドルの取得.
	HMENU hMenu = pMenu->m_hMenu;	// pMenuのメニューハンドルm_hMenuをhMenuに格納.

	// メニューhMenuの0番目のメニュー項目となっているポップアップメニューのハンドルを取得.
	HMENU hPopupMenu1 = ::GetSubMenu(hMenu, 0);	// WindowsAPIのGetSubMenuで0番目のポップアップメニューハンドルを取得し, hPopupMenu1に格納.

	// ポップアップメニュー項目の追加.
	::AppendMenu(hPopupMenu1, MF_ENABLED | MF_STRING, ID_ITEM_1_4, _T("Item1-4(&M)"));	// WindowsAPIのAppendMenuでhPopupMenu1に"Item1-4"を追加.

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

	// メニュー項目Item1_2が選択された時.
	AfxMessageBox(_T("Item1-2"), MB_OK | MB_ICONASTERISK);	// AfxMessageBoxで"Item1-2"と表示.

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

	// メニュー項目Item1_3が選択された時.
	AfxMessageBox(_T("Item1-3"), MB_OK | MB_ICONASTERISK);	// AfxMessageBoxで"Item1-3"と表示.

}