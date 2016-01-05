// ヘッダファイルのインクルード
#include "CFrameWnd_.h"	// CFrameWnd_クラス

// CFrameWnd_のメッセージマップ
BEGIN_MESSAGE_MAP(CFrameWnd_, CFrameWnd)
	ON_WM_PAINT()		// OnPaintのメッセージマクロ
	ON_WM_LBUTTONDOWN()	// OnLButtonDownのメッセージマクロ
END_MESSAGE_MAP()

// CFrameWnd_のメンバの定義
// コンストラクタCFrameWnd_()
CFrameWnd_::CFrameWnd_(){	// 初期化処理

	// メンバ変数の初期化
	m_x = 0;	// m_xの初期値は0.
	m_y = 0;	// m_yの初期値は0.

}

// メッセージハンドラOnPaint()
void CFrameWnd_::OnPaint(){	// 画面の描画を要求された時.

	// オブジェクトの宣言
	CPaintDC dc(this);	// CPaintDCオブジェクトのコンストラクタにthis(CFrameWnd_のインスタンス自身)を渡す.
	CString cstrPoint;	// マウスカーソルの位置座標を表す文字列cstrPoint.

	// マウスカーソルの位置座標を表す文字列をcstrPointにセット.
	cstrPoint.Format(_T("(x, y) = (%d, %d)"), m_x, m_y);	// cstrPointのメンバ関数Formatでm_xとm_yを使った文字列をセット.

	// 文字列の描画
	dc.TextOut(0, 0, cstrPoint, cstrPoint.GetLength());	// dcのメンバ関数TextOutでcstrPointを描画.(GetLengthメンバ関数は文字列長を返す.)

}

// メッセージハンドラOnLButtonDown()
void CFrameWnd_::OnLButtonDown(UINT nFlags, CPoint point){	// マウスの左ボタンが押された時.

	// マウスカーソルの位置座標を渡す.
	m_x = point.x;	// pointで渡された座標のxをm_xに代入.
	m_y = point.y;	// pointで渡された座標のyをm_yに代入.

	// 画面の更新を要求.
	Invalidate();	// Invalidateで画面全体の更新を要求.(引数なしはデフォルトでTRUEなので背景消去あり.)

}