// ヘッダファイルのインクルード
#include "CWinApp_.h"	// CWinApp_クラス

// CWinApp_のメンバの定義
// メンバ関数InitInstance()
BOOL CWinApp_::InitInstance(){	// インスタンスの初期化処理

	// 構造体の宣言
	WNDCLASS wc = {0};				// ウィンドウクラス情報をもつWNDCLASS構造体型変数wcを{0}で初期化.
	CFrameWnd *pFrameWnd;			// CFrameWndのオブジェクトポインタ
	RECT rect = {0, 0, 200, 200};	// ウィンドウの矩形情報を持つRECT型構造体変数rectを(0, 0, 200, 200)に初期化.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("Create");						// ウィンドウクラス名は"Create".
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
	pFrameWnd->Create(_T("Create"), _T("Create"), WS_OVERLAPPEDWINDOW, rect);	// CreateでCFrameWndのインスタンスのウィンドウを作成.(スタイルはWS_OVERLAPPEDWINDOW, ウィンドウ矩形情報はrectを指定.)

	// CFrameWndの表示
	pFrameWnd->ShowWindow(m_nCmdShow);	// ShowWindowでウィンドウを表示.

	// CFrameWndの更新
	pFrameWnd->UpdateWindow();	// UpdateWindowでウィンドウを更新.

	// 初期化成功
	return TRUE;	// 初期化成功ならTRUEを返す.

}