// ヘッダファイルのインクルード
#include "CWinApp_.h"	// CWinApp_クラス

// CWinApp_のメンバの定義
// メンバ関数InitInstance()
BOOL CWinApp_::InitInstance(){	// インスタンスの初期化処理

	// 構造体の宣言
	WNDCLASS wc = {0};		// ウィンドウクラス情報をもつWNDCLASS構造体型変数wcを{0}で初期化.
	CFrameWnd *pFrameWnd;	// CFrameWndのオブジェクトポインタ

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("AfxRegisterClass");				// ウィンドウクラス名は"AfxRegisterClass".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = AfxWndProc;							// MFC既定のウィンドウプロシージャAfxWndProcを設定.
	wc.hInstance = AfxGetInstanceHandle();					// AfxGetInstanceHandleで取得した現在のインスタンスハンドル.
	wc.hIcon = LoadIcon(IDI_APPLICATION);					// アイコンはアプリケーション既定のもの.
	wc.hCursor = LoadCursor(IDC_ARROW);						// カーソルは矢印.
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);	// 背景は黒ブラシ.
	wc.lpszMenuName = NULL;									// メニューはなし.
	wc.cbClsExtra = 0;										// 0でいい.
	wc.cbWndExtra = 0;										// 0でいい.

	// ウィンドウクラスの登録
	AfxRegisterClass(&wc);	// AfxRegisterClassでウィンドウクラスを登録.

	// CFrameWndのインスタンス作成
	pFrameWnd = new CFrameWnd();	// newでCFrameWndのインスタンスを作成し, pFrameWndに格納.
	m_pMainWnd = pFrameWnd;			// m_pMainWndにpFrameWndをセット.

	// CFrameWndの作成
	pFrameWnd->Create(_T("AfxRegisterClass"), _T("AfxRegisterClass"));	// CreateでCFrameWndのインスタンスのウィンドウを作成.

	// CFrameWndの表示
	pFrameWnd->ShowWindow(m_nCmdShow);	// ShowWindowでウィンドウを表示.

	// CFrameWndの更新
	pFrameWnd->UpdateWindow();	// UpdateWindowでウィンドウを更新.

	// 初期化成功
	return TRUE;	// 初期化成功ならTRUEを返す.

}