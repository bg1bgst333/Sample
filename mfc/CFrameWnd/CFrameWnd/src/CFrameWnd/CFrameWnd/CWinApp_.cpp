// ヘッダファイルのインクルード
#include "CFrameWnd_.h"	// CFrameWnd_クラス
#include "CWinApp_.h"	// CWinApp_クラス

// CWinApp_のメンバの定義
// メンバ関数InitInstance()
BOOL CWinApp_::InitInstance(){	// インスタンスの初期化処理

	// ウィンドウクラスのインスタンス作成
	m_pMainWnd = new CFrameWnd_();	// newでCFrameWnd_のインスタンスを作成し, m_pMainWndに格納.

	// ウィンドウの表示
	m_pMainWnd->ShowWindow(m_nCmdShow);	// ShowWindowでウィンドウを表示.

	// ウィンドウの更新
	m_pMainWnd->UpdateWindow();	// UpdateWindowでウィンドウを更新.

	// 初期化成功
	return TRUE;	// 初期化成功ならTRUEを返す.

}