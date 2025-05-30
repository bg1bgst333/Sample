// ヘッダファイルのインクルード
#include "CFrameWnd_.h"	// CFrameWnd_クラス
#include "resource.h"	// リソースID

// CFrameWnd_のメッセージマップ
BEGIN_MESSAGE_MAP(CFrameWnd_, CFrameWnd)
	ON_UPDATE_COMMAND_UI(ID_ITEM_1_1, OnUpdateItem1_1)	// メニュー項目などのUI更新マクロ.(Item1_1)
	ON_COMMAND(ID_ITEM_1_1, OnItem1_1)	// メニュー項目などのコマンドマクロ.(Item1_1)
	ON_WM_CREATE()	// OnCreateのメッセージマクロ
END_MESSAGE_MAP()

// CFrameWnd_のメンバの定義
// コンストラクタCFrameWnd_()
CFrameWnd_::CFrameWnd_(){	// 初期化処理

}

// メッセージハンドラOnCreate()
int CFrameWnd_::OnCreate(LPCREATESTRUCT lpCreateStruct){	// ウィンドウが作成された時.

	// 子ウィンドウの作成.
	m_hChild = CreateWindow(_T("STATIC"), _T("Child"), WS_CHILD | WS_VISIBLE | WS_BORDER,0, 0, 100, 100, m_hWnd, NULL, lpCreateStruct->hInstance, NULL);
	return 0;

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

	// CWndオブジェクトにウィンドウハンドルを一時的にアタッチして, 操作して, デタッチ.
	CWnd child;
	child.Attach(m_hChild);
	child.SetWindowText(_T("Item1-1"));
	HWND hWnd;
	hWnd = child.Detach();

}