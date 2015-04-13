// ヘッダファイルのインクルード
#include "CFrameWnd_.h"	// CFrameWnd_クラス
#include "CWinApp_.h"	// CWinApp_クラス

// CWinApp_のメンバの定義
// メンバ関数InitInstance()
BOOL CWinApp_::InitInstance(){	// インスタンスの初期化処理

	// ポインタの宣言
	CFrameWnd_ *pFrameWnd_;	// CFrameWnd_のオブジェクトポインタ

	// CFrameWnd_のインスタンス作成
	pFrameWnd_ = new CFrameWnd_();	// newでCFrameWnd_のインスタンスを作成し, pFrameWnd_に格納.
	m_pMainWnd = pFrameWnd_;	// m_pMainWndにpFrameWnd_をセット.

	// CFrameWnd_の作成
	pFrameWnd_->Create(NULL, _T("CPaintDC"));	// CreateでCFrameWnd_のインスタンスのウィンドウを作成.

	// CFrameWnd_の表示
	pFrameWnd_->ShowWindow(m_nCmdShow);	// ShowWindowでウィンドウを表示.

	// CFrameWnd_の更新
	pFrameWnd_->UpdateWindow();	// UpdateWindowでウィンドウを更新.

	// 初期化成功
	return TRUE;	// 初期化成功ならTRUEを返す.

}