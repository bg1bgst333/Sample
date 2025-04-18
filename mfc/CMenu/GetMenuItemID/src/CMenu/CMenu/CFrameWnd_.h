// 二重インクルード防止
#pragma once	// VisualC++独自のプリプロセッサ#pragma onceで二重インクルード防止.

// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <afxwin.h>	// MFC標準
#include <tchar.h>	// TCHAR型

// CFrameWndの派生クラスCFrameWnd_の定義
class CFrameWnd_ : public CFrameWnd{	// フレームウィンドウクラス

	// publicメンバ
	public:

		// publicメンバ関数
		// コンストラクタ
		CFrameWnd_();	// コンストラクタ(引数なし)

		// ハンドラ
		void OnUpdateItem1_1(CCmdUI* pCmdUI);	// メニュー項目Item1_1のUI更新ハンドラ
		void OnItem1_1();	// メニュー項目Item1_1のコマンドハンドラ
		void OnUpdateItem1_2(CCmdUI* pCmdUI);	// メニュー項目Item1_2のUI更新ハンドラ
		void OnItem1_2();	// メニュー項目Item1_2のコマンドハンドラ
		void OnUpdateItem1_3(CCmdUI* pCmdUI);	// メニュー項目Item1_3のUI更新ハンドラ
		void OnItem1_3();	// メニュー項目Item1_3のコマンドハンドラ
		void OnUpdateItem1_4(CCmdUI* pCmdUI);	// メニュー項目Item1_4のUI更新ハンドラ
		void OnItem1_4();	// メニュー項目Item1_4のコマンドハンドラ

		// メッセージマップ
		DECLARE_MESSAGE_MAP()	// メッセージマップの利用を宣言.

};