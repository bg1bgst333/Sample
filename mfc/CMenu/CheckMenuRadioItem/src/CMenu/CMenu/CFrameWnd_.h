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
		BOOL m_bInitMenu;	// メニュー初期化フラグm_bInitMenu.

	// publicメンバ
	public:

		// publicメンバ関数
		// コンストラクタ
		CFrameWnd_();	// コンストラクタ(引数なし)

		// ハンドラ
		virtual void OnPaint();	// 画面の描画を要求された時.
		afx_msg void OnRangeCmds(UINT nID);	// 範囲内のどれかが選択された時のコマンドハンドラ.

		// メッセージマップ
		DECLARE_MESSAGE_MAP()	// メッセージマップの利用を宣言.

};