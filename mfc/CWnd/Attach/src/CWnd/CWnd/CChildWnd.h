// 二重インクルード防止
#pragma once	// VisualC++独自のプリプロセッサ#pragma onceで二重インクルード防止.

// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <afxwin.h>	// MFC標準
#include <tchar.h>	// TCHAR型

// CWndの派生クラスCChildWndの定義
class CChildWnd : public CWnd{	// 子ウィンドウクラス

	// publicメンバ
	public:

		// publicメンバ関数
		// ハンドラ
		virtual void OnDestroy();	// ウィンドウが破棄された時.

		// メッセージマップ
		DECLARE_MESSAGE_MAP()	// メッセージマップの利用を宣言.

};
