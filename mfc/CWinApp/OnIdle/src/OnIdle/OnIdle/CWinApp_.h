// 二重インクルード防止
#pragma once	// VisualC++独自のプリプロセッサ#pragma onceで二重インクルード防止.

// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <afxwin.h>	// MFC標準
#include <tchar.h>	// TCHAR型

// CWinAppの派生クラスCWinApp_の定義
class CWinApp_ : public CWinApp{	// アプリケーションクラス

	// publicメンバ
	public:

		// publicメンバ関数
		// 基底クラスのメンバ関数のオーバーライド
		virtual BOOL InitInstance();		// インスタンスの初期化処理
		virtual BOOL OnIdle(LONG lCount);	// アイドル時の処理(メッセージが来ない時の処理.)

};

// アプリケーションインスタンスの宣言
CWinApp_ theApp;	// CWinApp_のインスタンスtheAppを宣言.