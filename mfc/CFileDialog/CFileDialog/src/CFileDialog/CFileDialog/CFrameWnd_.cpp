// ヘッダファイルのインクルード
// 既定のヘッダ
#include <afxdlgs.h>	// ダイアログなど.
// 独自のヘッダ
#include "CFrameWnd_.h"	// CFrameWnd_クラス
#include "resource.h"	// リソースID

// CFrameWnd_のメッセージマップ
BEGIN_MESSAGE_MAP(CFrameWnd_, CFrameWnd)
	ON_UPDATE_COMMAND_UI(ID_ITEM_1_1, OnUpdateItem1_1)	// メニュー項目などのUI更新マクロ.(Item1_1)
	ON_COMMAND(ID_ITEM_1_1, OnItem1_1)	// メニュー項目などのコマンドマクロ.(Item1_1)
	ON_UPDATE_COMMAND_UI(ID_ITEM_1_2, OnUpdateItem1_2)	// メニュー項目などのUI更新マクロ.(Item1_2)
	ON_COMMAND(ID_ITEM_1_2, OnItem1_2)	// メニュー項目などのコマンドマクロ.(Item1_2)
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

	// "ファイルを開く"ダイアログの表示.
	CFileDialog dlg(TRUE);	// CFileDialogオブジェクトdlgのコンストラクタでTRUEだけ渡す.
	INT_PTR ret = dlg.DoModal();	// dlg.DoModalで表示.
	if (ret == IDOK){	// 選択された.
		AfxMessageBox(_T("IDOK"));
	}
	else if (ret == IDCANCEL){	// キャンセル.
		AfxMessageBox(_T("IDCANCEL"));
	}

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

	// "名前を付けて保存"ダイアログの表示.
	CFileDialog dlg(FALSE);	// CFileDialogオブジェクトdlgのコンストラクタでFALSEだけ渡す.
	INT_PTR ret = dlg.DoModal();	// dlg.DoModalで表示.
	if (ret == IDOK){	// 選択された.
		AfxMessageBox(_T("IDOK"));
	}
	else if (ret == IDCANCEL){	// キャンセル.
		AfxMessageBox(_T("IDCANCEL"));
	}

}