// ヘッダファイルのインクルード
#include "CFrameWnd_.h"	// CFrameWnd_クラス
#include "resource.h"	// リソースID

// CFrameWnd_のメッセージマップ
BEGIN_MESSAGE_MAP(CFrameWnd_, CFrameWnd)
	ON_WM_PAINT()	// OnPaintのメッセージマクロ
	ON_COMMAND_RANGE(ID_ITEM_1_1, ID_ITEM_1_4, &OnRangeCmds)	// メニューラジオボタン用のマクロ(同じIDでON_COMMANDとは両立できないみたいなので注意!)
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

// ハンドラOnRangeCmds(UINT nID)
void CFrameWnd_::OnRangeCmds(UINT nID){	// 範囲内のどれかが選択された時のコマンドハンドラ.

	// nIDと項目IDを比較.
	if (nID == ID_ITEM_1_1){
		AfxMessageBox(_T("ID_ITEM_1_1"));
	}
	if (nID == ID_ITEM_1_2){
		AfxMessageBox(_T("ID_ITEM_1_2"));
	}
	if (nID == ID_ITEM_1_3){
		AfxMessageBox(_T("ID_ITEM_1_3"));
	}
	if (nID == ID_ITEM_1_4){
		AfxMessageBox(_T("ID_ITEM_1_4"));
	}

}