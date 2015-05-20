// ヘッダファイルのインクルード
#include "CFrameWnd_.h"	// CFrameWnd_クラス
#include "resource.h"	// リソースID

// CFrameWnd_のメッセージマップ
BEGIN_MESSAGE_MAP(CFrameWnd_, CFrameWnd)
	ON_UPDATE_COMMAND_UI(ID_ITEM_1_1, OnUpdateItem1_1)	// メニュー項目などのUI更新マクロ.(Item1_1)
END_MESSAGE_MAP()

// CFrameWnd_のメンバの定義
// コンストラクタCFrameWnd_()
CFrameWnd_::CFrameWnd_(){	// 初期化処理

}

// メッセージハンドラOnCommand()
BOOL CFrameWnd_::OnCommand(WPARAM wParam, LPARAM lParam){	// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりした時.

	// どのメニュー項目が選択されたかを判定する.
	switch (LOWORD(wParam)){	// LOWORD(wParam)で選択されたメニュー項目のIDが取得できるので, その値で判定する.

		// 取得したIDごとに処理を分岐.
		// Item1-1が選択された時.
		case ID_ITEM_1_1:

			// ID_ITEM_1_1ブロック
			{

				// メッセージボックスを表示.
				AfxMessageBox(_T("Item1-1"), MB_OK | MB_ICONASTERISK);	// AfxMessageBoxで"Item1-1"と表示.
							
				// TRUEを返す.
				return TRUE;	// 処理したので戻り値としてTRUEを返す.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// それ以外の時.
		default:

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

	}

	// ここに来る時は処理していない時.
	return FALSE;	// 処理していないのでFALSEを返す.

}

// ハンドラOnUpdateItem1_1()
void CFrameWnd_::OnUpdateItem1_1(CCmdUI* pCmdUI){	// メニュー項目Item1_1のUI更新ハンドラ

	// メニュー項目Item1_1のUI更新
	if (pCmdUI){	// pCmdUIがNULLでないなら.

		// メニュー項目Item1_1の有効化
		pCmdUI->Enable();	// EnableでItem1_1を有効にする.(デフォルト引数はTRUE.)

	}

}