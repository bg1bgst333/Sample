// ヘッダファイルのインクルード
#include "CWinApp_.h"	// CWinApp_クラス

// CWinApp_のメンバの定義
// メンバ関数InitInstance()
BOOL CWinApp_::InitInstance(){	// インスタンスの初期化処理

	// ポインタの宣言
	CFrameWnd *pFrameWnd;	// CFrameWndのオブジェクトポインタ

	// ウィンドウクラスのインスタンス作成
	pFrameWnd = new CFrameWnd();	// newでCFrameWndのインスタンスを作成し, pFrameWndに格納.

	// メインウィンドウのセット
	m_pMainWnd = pFrameWnd;	// m_pMainWndにpFrameWndをセット.

	// フレームウィンドウの作成.
	pFrameWnd->Create(NULL, _T("Run"));	// Createで"Run"というウィンドウ名のフレームウィンドウ作成.

	// ウィンドウの表示
	pFrameWnd->ShowWindow(m_nCmdShow);	// ShowWindowでウィンドウを表示.

	// ウィンドウの更新
	pFrameWnd->UpdateWindow();	// UpdateWindowでウィンドウを更新.

	// 初期化成功
	return TRUE;	// 初期化成功ならTRUEを返す.

}

// メンバ関数Run()
int CWinApp_::Run(){	// メッセージループ

	// 変数の宣言
	int iRet;	// Runの戻り値を格納するint型変数iRet.
	
	// 親クラスのメッセージループを使う.
	iRet = CWinApp::Run();	// CWinAppのRunを呼んで, 戻り値をiRetに格納.(ウィンドウを閉じるまでRunは抜けない.)

	// 親クラスのRunを抜けたらメッセージボックス表示.
	AfxMessageBox(_T("Exit Run!"), MB_OK | MB_ICONASTERISK);	// AfxMessageBoxで"Exit Run!"と表示.

	// メッセージループの戻り値を返す.
	return iRet;	// iRetを返す.

}