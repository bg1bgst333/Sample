// ヘッダファイルのインクルード
#include "CFrameWnd_.h"	// CFrameWnd_クラス
#include "resource.h"	// リソースID

// CFrameWnd_のメッセージマップ
BEGIN_MESSAGE_MAP(CFrameWnd_, CFrameWnd)
	ON_WM_PAINT()	// OnPaintのメッセージマクロ
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
	m_bInitMenu = FALSE;	// m_bInitMenuをFALSEに初期化.
	m_bAutoMenuEnable = FALSE;	// これを指定しないと無効やグレーアウトにならないので注意!

}

// メッセージハンドラOnPaint()
void CFrameWnd_::OnPaint(){	// 画面の描画を要求された時.

	// 変数の宣言
	HDC hDC;		// このウィンドウのデバイスコンテキストハンドルhDC.
	PAINTSTRUCT ps;	// ペイント情報を管理するPAINTSTRUCT構造体変数ps.

	// メニューの初期化.
	if (!m_bInitMenu){	// FALSEなら初期化.

		// 初期化処理.
		m_bInitMenu = TRUE;	// TRUEをセット.
		
	}

	// 文字列の描画
	hDC = ::BeginPaint(m_hWnd, &ps);	// WindowsAPIのBeginPaintで描画の準備をし, デバイスコンテキストハンドルを取得.
	::EndPaint(m_hWnd, &ps);	// WindowsAPIのEndPaintで描画を終了.

}

// ハンドラOnUpdateItem1_1()
void CFrameWnd_::OnUpdateItem1_1(CCmdUI* pCmdUI){	// メニュー項目Item1_1のUI更新ハンドラ

}

// ハンドラOnItem1_1()
void CFrameWnd_::OnItem1_1(){	// メニュー項目Item1_1のコマンドハンドラ

	// Item1-1の状態を判定.
	CMenu *pMenu = CMenu::FromHandle(m_hMenuDefault);	// CMenu::FromHandleでデフォルトメニューのpMenu取得.
	CMenu *pSubMenu = pMenu->GetSubMenu(0);	// 0番目のサブメニュー取得.
	UINT uiState1 = pSubMenu->GetMenuState(ID_ITEM_1_1, MF_BYCOMMAND);	// pSubMenu->GetMenuStateでuiState1を取得.
	if (uiState1 & MF_CHECKED){	// チェック済み
		pSubMenu->CheckMenuItem(ID_ITEM_1_1, MF_UNCHECKED | MF_BYCOMMAND);	// pSubMenu->CheckMenuItemでチェック外す.
	}
	else{	// 未チェック
		pSubMenu->CheckMenuItem(ID_ITEM_1_1, MF_CHECKED | MF_BYCOMMAND);	// pSubMenu->CheckMenuItemでチェック付ける.
	}

}

// ハンドラOnUpdateItem1_2()
void CFrameWnd_::OnUpdateItem1_2(CCmdUI* pCmdUI){	// メニュー項目Item1_2のUI更新ハンドラ

}

// ハンドラOnItem1_2()
void CFrameWnd_::OnItem1_2(){	// メニュー項目Item1_2のコマンドハンドラ

}

// ハンドラOnUpdateItem1_3()
void CFrameWnd_::OnUpdateItem1_3(CCmdUI* pCmdUI){	// メニュー項目Item1_3のUI更新ハンドラ

}

// ハンドラOnItem1_3()
void CFrameWnd_::OnItem1_3(){	// メニュー項目Item1_3のコマンドハンドラ

}

// ハンドラOnUpdateItem1_4()
void CFrameWnd_::OnUpdateItem1_4(CCmdUI* pCmdUI){	// メニュー項目Item1_4のUI更新ハンドラ

}

// ハンドラOnItem1_4()
void CFrameWnd_::OnItem1_4(){	// メニュー項目Item1_4のコマンドハンドラ

	// メニュー項目の状態を判定.
	CMenu *pMenu = CMenu::FromHandle(m_hMenuDefault);	// CMenu::FromHandleでデフォルトメニューのpMenu取得.
	CMenu *pSubMenu = pMenu->GetSubMenu(0);	// 0番目のサブメニュー取得.
	UINT uiState1 = pSubMenu->GetMenuState(ID_ITEM_1_1, MF_BYCOMMAND);	// ID_ITEM_1_1の状態uiState1を取得.
	if (uiState1 == MF_GRAYED){
		AfxMessageBox(_T("uiState1: MF_GRAYED"));
	}
	UINT uiState2 = pSubMenu->GetMenuState(ID_ITEM_1_2, MF_BYCOMMAND);	// ID_ITEM_1_2の状態uiState2を取得.
	if (uiState2 == MF_ENABLED){
		AfxMessageBox(_T("uiState2: MF_ENABLED"));
	}
	UINT uiState3 = pSubMenu->GetMenuState(ID_ITEM_1_3, MF_BYCOMMAND);	// ID_ITEM_1_3の状態uiState3を取得.
	if (uiState3 == MF_DISABLED){
		AfxMessageBox(_T("uiState3: MF_DISABLED"));
	}

}