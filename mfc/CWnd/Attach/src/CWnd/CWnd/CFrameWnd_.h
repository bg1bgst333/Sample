// 二重インクルード防止
#pragma once	// VisualC++独自のプリプロセッサ#pragma onceで二重インクルード防止.

// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <afxwin.h>	// MFC標準
#include <tchar.h>	// TCHAR型
// 独自のヘッダファイル
#include "CChildWnd.h"	// CChildWndクラス

// CFrameWndの派生クラスCFrameWnd_の定義
class CFrameWnd_ : public CFrameWnd{	// フレームウィンドウクラス

	// privateメンバ
	private:

		// privateメンバ変数
		CMenu *m_pMenu;	// CMenuオブジェクトポインタm_pMenu.
		HWND m_hChild;	// 子ウィンドウハンドルm_hChild.
		CChildWnd m_childWnd;	// 子ウィンドウクラスm_childWnd.

	// publicメンバ
	public:

		// publicメンバ関数
		// コンストラクタ
		CFrameWnd_();	// コンストラクタ(引数なし)

		// ハンドラ
		virtual int OnCreate(LPCREATESTRUCT lpCreateStruct);	// ウィンドウが作成された時.
		void OnUpdateItem1_1(CCmdUI* pCmdUI);	// メニュー項目Item1_1のUI更新ハンドラ
		void OnItem1_1();	// メニュー項目Item1_1のコマンドハンドラ
		virtual void OnClose();	// ウィンドウが閉じられた時.

		// メッセージマップ
		DECLARE_MESSAGE_MAP()	// メッセージマップの利用を宣言.

};