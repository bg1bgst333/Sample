// ヘッダファイルのインクルード
#include "CChildWnd.h"	// CChildWndクラス
#include "resource.h"	// リソースID

// CChildWndのメッセージマップ
BEGIN_MESSAGE_MAP(CChildWnd, CWnd)
	ON_WM_DESTROY()	// OnDestroyのメッセージマクロ
END_MESSAGE_MAP()

// メッセージハンドラOnDestroy()
void CChildWnd::OnDestroy(){	// ウィンドウが破棄された時.

}