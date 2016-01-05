// 二重インクルード防止
#pragma once	// VisualC++独自のプリプロセッサ#pragma onceで二重インクルード防止.

// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <afxwin.h>	// MFC標準
#include <tchar.h>	// TCHAR型

// CFrameWndの派生クラスCFrameWnd_の定義
class CFrameWnd_ : public CFrameWnd{	// フレームウィンドウクラス

	// privateメンバ
	private:

		// privateメンバ変数
		int m_x;	// マウスの左ボタンが押された時のマウスカーソルの位置座標x.
		int m_y;	// マウスの左ボタンが押された時のマウスカーソルの位置座標y.

	// publicメンバ
	public:

		// publicメンバ関数
		// コンストラクタ
		CFrameWnd_();	// コンストラクタ(引数なし)

		// メッセージハンドラ
		virtual void OnPaint();	// 画面の描画を要求された時.
		virtual void OnLButtonDown(UINT nFlags, CPoint point);	// マウスの左ボタンが押された時.

		// メッセージマップ
		DECLARE_MESSAGE_MAP()	// メッセージマップの利用を宣言.

};