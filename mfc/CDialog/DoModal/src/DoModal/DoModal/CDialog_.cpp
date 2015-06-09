// ヘッダファイルのインクルード
#include "CDialog_.h"	// CDialog_クラス

// CDialog_のメッセージマップ
BEGIN_MESSAGE_MAP(CDialog_, CDialog)
	ON_WM_LBUTTONDOWN()	// OnLButtonDownのメッセージマクロ
	ON_WM_CLOSE()	// OnCloseのメッセージマクロ
END_MESSAGE_MAP()

// CDialog_のメンバの定義
// メッセージハンドラOnLButtonDown()
void CDialog_::OnLButtonDown(UINT nFlags, CPoint point){	// マウスの左ボタンが押された時.

	// IDOK
	EndDialog(IDOK);	// EndDialogで"OK"として終了する.

}

// メッセージハンドラOnClose()
void CDialog_::OnClose(){	// ダイアログの閉じるボタンが押された時.

	// IDCANCEL
	EndDialog(IDCANCEL);	// EndDialogで"キャンセル"として終了する.

}