// ヘッダファイルのインクルード
#include "CFrameWnd_.h"	// CFrameWnd_クラス
#include "resource.h"	// リソースID

// CFrameWnd_のメッセージマップ
BEGIN_MESSAGE_MAP(CFrameWnd_, CFrameWnd)
	ON_WM_PAINT()	// OnPaintのメッセージマクロ
	ON_UPDATE_COMMAND_UI(ID_ITEM_1_1, OnUpdateItem1_1)	// メニュー項目などのUI更新マクロ.(Item1_1)
	ON_COMMAND(ID_ITEM_1_1, OnItem1_1)	// メニュー項目などのコマンドマクロ.(Item1_1)
	ON_UPDATE_COMMAND_UI(ID_ITEM_2_2, OnUpdateItem2_2)	// メニュー項目などのUI更新マクロ.(Item2_2)
	ON_COMMAND(ID_ITEM_2_2, OnItem2_2)	// メニュー項目などのコマンドマクロ.(Item2_2)
	ON_UPDATE_COMMAND_UI(ID_ITEM_3_3, OnUpdateItem3_3)	// メニュー項目などのUI更新マクロ.(Item3_3)
	ON_COMMAND(ID_ITEM_3_3, OnItem3_3)	// メニュー項目などのコマンドマクロ.(Item3_3)
END_MESSAGE_MAP()

// CFrameWnd_のメンバの定義
// コンストラクタCFrameWnd_()
CFrameWnd_::CFrameWnd_(){	// 初期化処理

	// メンバの初期化.
	m_bInitMenu = FALSE;	// m_bInitMenuをFALSEに初期化.

}

// メッセージハンドラOnPaint()
void CFrameWnd_::OnPaint(){	// 画面の描画を要求された時.

	// 変数の宣言
	HDC hDC;		// このウィンドウのデバイスコンテキストハンドルhDC.
	PAINTSTRUCT ps;	// ペイント情報を管理するPAINTSTRUCT構造体変数ps.

	// メニューの初期化.
	if (!m_bInitMenu){	// FALSEなら初期化.

		// メニューの差し替え.
		SetMenu(NULL);
		CMenu *pMenu = CMenu::FromHandle(m_hMenuDefault);
		pMenu->DestroyMenu();
		m_cPopupMenu1.CreatePopupMenu();
		m_cPopupMenu1.AppendMenu(MF_STRING, ID_ITEM_1_1, _T("Item1-1(&A)"));
		m_cPopupMenu1.AppendMenu(MF_STRING, ID_ITEM_1_2, _T("Item1-2(&B)"));
		m_cPopupMenu1.AppendMenu(MF_STRING, ID_ITEM_1_3, _T("Item1-3(&C)"));
		m_cPopupMenu2.CreatePopupMenu();
		m_cPopupMenu2.AppendMenu(MF_STRING, ID_ITEM_2_1, _T("Item2-1(&D)"));
		m_cPopupMenu2.AppendMenu(MF_STRING, ID_ITEM_2_2, _T("Item2-2(&E)"));
		m_cPopupMenu2.AppendMenu(MF_STRING, ID_ITEM_2_3, _T("Item3-3(&F)"));
		m_cPopupMenu3.CreatePopupMenu();
		m_cPopupMenu3.AppendMenu(MF_STRING, ID_ITEM_3_1, _T("Item3-1(&G)"));
		m_cPopupMenu3.AppendMenu(MF_STRING, ID_ITEM_3_2, _T("Item3-2(&H)"));
		m_cPopupMenu3.AppendMenu(MF_STRING, ID_ITEM_3_3, _T("Item3-3(&I)"));
		CMenu cMenu;
		cMenu.CreateMenu();
		cMenu.AppendMenu(MF_POPUP, (UINT_PTR)m_cPopupMenu1.m_hMenu, _T("Item1"));
		cMenu.AppendMenu(MF_POPUP, (UINT_PTR)m_cPopupMenu2.m_hMenu, _T("Item2"));
		cMenu.AppendMenu(MF_POPUP, (UINT_PTR)m_cPopupMenu3.m_hMenu, _T("Item3"));
		SetMenu(&cMenu);
		m_hMenuDefault = cMenu.m_hMenu;
		m_bInitMenu = TRUE;	// TRUEをセット.

	}

	// 文字列の描画
	hDC = ::BeginPaint(m_hWnd, &ps);	// WindowsAPIのBeginPaintで描画の準備をし, デバイスコンテキストハンドルを取得.
	::EndPaint(m_hWnd, &ps);	// WindowsAPIのEndPaintで描画を終了.

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

}

// ハンドラOnUpdateItem2_2()
void CFrameWnd_::OnUpdateItem2_2(CCmdUI* pCmdUI){	// メニュー項目Item2_2のUI更新ハンドラ

	// メニュー項目Item2_2のUI更新
	if (pCmdUI){	// pCmdUIがNULLでないなら.

		// メニュー項目Item2_2の有効化
		pCmdUI->Enable();	// EnableでItem2_2を有効にする.(デフォルト引数はTRUE.)

	}

}

// ハンドラOnItem2_2()
void CFrameWnd_::OnItem2_2(){	// メニュー項目Item2_2のコマンドハンドラ

}

// ハンドラOnUpdateItem3_3()
void CFrameWnd_::OnUpdateItem3_3(CCmdUI* pCmdUI){	// メニュー項目Item3_3のUI更新ハンドラ

	// メニュー項目Item3_3のUI更新
	if (pCmdUI){	// pCmdUIがNULLでないなら.

		// メニュー項目Item3_3の有効化
		pCmdUI->Enable();	// EnableでItem3_3を有効にする.(デフォルト引数はTRUE.)

	}

}

// ハンドラOnItem3_3()
void CFrameWnd_::OnItem3_3(){	// メニュー項目Item3_3のコマンドハンドラ

}