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
		CMenu m_cPopupMenu1;	// メンバとして持っておかないと初期化スコープ外れた時, 破棄されちゃう.
		CMenu m_cPopupMenu2;	// メンバとして持っておかないと初期化スコープ外れた時, 破棄されちゃう.
		CMenu m_cPopupMenu3;	// メンバとして持っておかないと初期化スコープ外れた時, 破棄されちゃう.

	// publicメンバ
	public:

		// publicメンバ関数
		// コンストラクタ
		CFrameWnd_();	// コンストラクタ(引数なし)

		// ハンドラ
		virtual void OnPaint();	// 画面の描画を要求された時.
		void OnUpdateItem1_1(CCmdUI* pCmdUI);	// メニュー項目Item1_1のUI更新ハンドラ
		void OnItem1_1();	// メニュー項目Item1_1のコマンドハンドラ
		void OnUpdateItem2_2(CCmdUI* pCmdUI);	// メニュー項目Item2_2のUI更新ハンドラ
		void OnItem2_2();	// メニュー項目Item2_2のコマンドハンドラ
		void OnUpdateItem3_3(CCmdUI* pCmdUI);	// メニュー項目Item3_3のUI更新ハンドラ
		void OnItem3_3();	// メニュー項目Item3_3のコマンドハンドラ

		// メッセージマップ
		DECLARE_MESSAGE_MAP()	// メッセージマップの利用を宣言.

};