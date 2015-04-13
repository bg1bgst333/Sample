// ヘッダファイルのインクルード
#include "CWinApp_.h"	// CWinApp_クラス

// CWinApp_のメンバの定義
// メンバ関数InitInstance()
BOOL CWinApp_::InitInstance(){	// インスタンスの初期化処理

	// 変数・ポインタの宣言
	CFrameWnd *pFrameWnd;	// CFrameWndのオブジェクトポインタ
	int iRet;				// メッセージボックスで何が選択されたかを格納するint型変数iRet.

	// フレームウィンドウの作成
	pFrameWnd = new CFrameWnd();	// newでCFrameWndのインスタンスを作成し, pFrameWndに格納.
	m_pMainWnd = pFrameWnd;	// m_pMainWndにpFrameWndをセット.
	pFrameWnd->Create(NULL, _T("InitInstance"));	// Createで"InitInstance"というウィンドウ名のフレームウィンドウ作成.
	pFrameWnd->ShowWindow(m_nCmdShow);	// ShowWindowでウィンドウを表示.
	pFrameWnd->UpdateWindow();	// UpdateWindowでウィンドウを更新.

	// メッセージボックスで"はい", "いいえ"を選択.
	iRet = MessageBox(NULL, _T("YesNo?"), _T("InitInstance"), MB_YESNO);	// MessageBoxで"はい", "いいえ"選択型のメッセージボックスを表示.
	if (iRet == IDYES){	// "はい"
		m_bInitState = TRUE;	// m_bInitStateをTRUEにする.
		return TRUE;	// 初期化成功としてTRUEを返す.
	}
	else{	// "いいえ"
		m_bInitState = FALSE;	// m_bInitStateをFALSEにする.
		return FALSE;	// 初期化失敗としてFALSEを返す.
	}

}

// メンバ関数Run()
int CWinApp_::Run(){	// メッセージループ

	// 変数の宣言
	int iRet;	// Runの戻り値を格納するint型変数iRet.

	// メッセージボックスを用意し, 表示されればここに来ている.
	MessageBox(NULL, _T("Run before"), _T("Run"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"Run before"と表示.

	// 親クラスのメッセージループを使う.
	iRet = CWinApp::Run();	// CWinAppのRunを呼んで, 戻り値をiRetに格納.(ウィンドウを閉じるまでRunは抜けない.)

	// Runの後にここに来る.
	MessageBox(NULL, _T("Run after"), _T("Run"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"Run after"と表示.

	// メッセージループの終了.
	return iRet;	// Runの戻り値iRetを返す.

}

// メンバ関数ExitInstance()
int CWinApp_::ExitInstance(){	// インスタンスの終了処理

	// 変数の宣言
	MSG msg;	// ExitInstance内にて, メッセージボックスが表示されない現象対策.

	// InitInstanceの戻り値がFALSEの時のみ, 表示されない現象対策を実行する.
	if (!m_bInitState){	// m_bInitStateがFALSEの時.

		// GetMessageでWM_QUITが処理されるまで待つ.
		while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessageの戻り値が0以下になるまで待つ.

		}

	}

	// インスタンス終了時に来る.
	MessageBox(NULL, _T("ExitInstance"), _T("ExitInstance"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"ExitInstance"と表示.
	
	// 終了処理の終了.
	return CWinApp::ExitInstance();	// 親クラスのExitInstanceの戻り値を返す.

}