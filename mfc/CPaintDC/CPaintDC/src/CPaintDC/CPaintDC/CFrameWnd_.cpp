// ヘッダファイルのインクルード
#include "CFrameWnd_.h"	// CFrameWnd_クラス

// CFrameWnd_のメッセージマップ
BEGIN_MESSAGE_MAP(CFrameWnd_, CFrameWnd)
	ON_WM_PAINT()	// OnPaintのメッセージマクロ
END_MESSAGE_MAP()

// CFrameWnd_のメンバの定義
// コンストラクタCFrameWnd_()
CFrameWnd_::CFrameWnd_(){	// 初期化処理

}

// メッセージハンドラOnPaint()
void CFrameWnd_::OnPaint(){	// 画面の描画を要求された時.

	// オブジェクトの宣言
	CPaintDC dc(this);	// CPaintDCオブジェクトのコンストラクタにthis(CFrameWnd_のインスタンス自身)を渡す.

	// 文字列の描画
	dc.TextOut(0, 0, _T("CPaintDC"), (int)_tcslen(_T("CPaintDC")));	// dcのメンバ関数TextOutで"CPaintDC"と描画.(BeginPaintとEndPaintは不要.)

}