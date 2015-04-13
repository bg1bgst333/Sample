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

	// 変数の宣言
	HDC hDC;		// このウィンドウのデバイスコンテキストハンドルhDC.
	PAINTSTRUCT ps;	// ペイント情報を管理するPAINTSTRUCT構造体変数ps.

	// 文字列の描画
	hDC = ::BeginPaint(m_hWnd, &ps);	// WindowsAPIのBeginPaintで描画の準備をし, デバイスコンテキストハンドルを取得.
	::TextOut(hDC, 0, 0, _T("OnPaint"), (int)_tcslen(_T("OnPaint")));	// WindowsAPIのTextOutで"OnPaint"と描画.
	::EndPaint(m_hWnd, &ps);	// WindowsAPIのEndPaintで描画を終了.

}