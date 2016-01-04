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
	m_pMainWnd = pFrameWnd_;		// m_pMainWnd(CWnd)にpFrameWnd_をセット.

	// ウィンドウの作成
	pFrameWnd_->Create(NULL, _T("CWnd"));	// 親なしのウィンドウはCFrameWnd::Createでしか作れないので, pFrameWnd_からCreateを呼ぶ.
	
	// ウィンドウの表示
	m_pMainWnd->ShowWindow(m_nCmdShow);	// m_pMainWnd(CWnd)のShowWindowでウィンドウを表示.

	// ウィンドウの更新
	m_pMainWnd->UpdateWindow();	// m_pMainWnd(CWnd)のUpdateWindowでウィンドウを更新.

	// 初期化成功
	return TRUE;	// 初期化成功ならTRUEを返す.

}