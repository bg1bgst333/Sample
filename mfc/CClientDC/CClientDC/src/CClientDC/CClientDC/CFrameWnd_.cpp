// ヘッダファイルのインクルード
#include "CFrameWnd_.h"	// CFrameWnd_クラス

// CFrameWnd_のメッセージマップ
BEGIN_MESSAGE_MAP(CFrameWnd_, CFrameWnd)
	ON_WM_LBUTTONDOWN()	// OnLButtonDownのメッセージマクロ
END_MESSAGE_MAP()

// CFrameWnd_のメンバの定義
// コンストラクタCFrameWnd_()
CFrameWnd_::CFrameWnd_(){	// 初期化処理

}

// メッセージハンドラOnLButtonDown()
void CFrameWnd_::OnLButtonDown(UINT nFlags, CPoint point){	// マウスの左ボタンが押された時.

	// オブジェクトの宣言
	CClientDC dc(this);	// CClientDCオブジェクトのコンストラクタにthis(CFrameWnd_のインスタンス自身)を渡す.
	CString cstrPoint;	// マウスカーソルの位置座標を表す文字列cstrPoint.

	// マウスカーソルの位置座標を表す文字列をcstrPointにセット.
	cstrPoint.Format(_T("(x, y) = (%d, %d)"), point.x, point.y);	// cstrPointのメンバ関数Formatで point.xと point.yを使った文字列をセット.

	// 文字列の描画
	dc.TextOut(0, 0, cstrPoint, cstrPoint.GetLength());	// dcのメンバ関数TextOutでcstrPointを描画.(GetLengthメンバ関数は文字列長を返す.)

}