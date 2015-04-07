// ヘッダファイルのインクルード
#include "CFrameWnd_.h"	// CFrameWnd_クラス

// CFrameWnd_のメッセージマップ
BEGIN_MESSAGE_MAP(CFrameWnd_, CFrameWnd)
END_MESSAGE_MAP()

// CFrameWnd_のメンバの定義
// コンストラクタCFrameWnd_()
CFrameWnd_::CFrameWnd_(){	// 初期化処理

	// フレームウィンドウの作成
	Create(NULL, _T("CFrameWnd_"));	// Createでタイトルが"CFrameWnd_"となるウィンドウを作成.

}