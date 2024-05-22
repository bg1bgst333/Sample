// ヘッダファイルのインクルード
#include "CWinApp_.h"	// CWinApp_クラス
#include "CFrameWnd_.h"	// CFrameWnd_クラス
#include "resource.h"	// リソースID

// CWinApp_のメンバの定義
// メンバ関数InitInstance()
BOOL CWinApp_::InitInstance(){	// インスタンスの初期化処理

	// 構造体の宣言
	WNDCLASS wc = {0};		// ウィンドウクラス情報をもつWNDCLASS構造体型変数wcを{0}で初期化.
	CFrameWnd_ *pFrameWnd_;	// CFrameWnd_のオブジェクトポインタpFrameWnd_.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("CMenu");							// ウィンドウクラス名は"CMenu".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = AfxWndProc;							// MFC既定のウィンドウプロシージャAfxWndProcを設定.
	wc.hInstance = AfxGetInstanceHandle();					// AfxGetInstanceHandleで取得した現在のインスタンスハンドル.
	wc.hIcon = LoadIcon(IDI_APPLICATION);					// アイコンはアプリケーション既定のもの.
	wc.hCursor = LoadCursor(IDC_ARROW);						// カーソルは矢印.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 背景は白ブラシ.
	wc.lpszMenuName = NULL;									// メニューはなし.
	wc.cbClsExtra = 0;										// 0でいい.
	wc.cbWndExtra = 0;										// 0でいい.

	// ウィンドウクラスの登録
	AfxRegisterClass(&wc);	// AfxRegisterClassでウィンドウクラスを登録.

	// CFrameWnd_のインスタンス作成
	pFrameWnd_ = new CFrameWnd_();	// newでCFrameWnd_のインスタンスを作成し, pFrameWnd_に格納.
	m_pMainWnd = pFrameWnd_;		// m_pMainWndにpFrameWnd_をセット.

	// CFrameWnd_の作成
	RECT rc = {0, 0, 640, 480};
	pFrameWnd_->Create(_T("CMenu"), _T("CMenu"), WS_OVERLAPPEDWINDOW, rc, NULL, NULL);	// CFrameWnd::CreateでpFrameWnd_のインスタンスのウィンドウを作成.

	// CFrameWnd_の表示
	pFrameWnd_->ShowWindow(m_nCmdShow);	// ShowWindowでウィンドウを表示.

	// CFrameWndの更新
	pFrameWnd_->UpdateWindow();	// UpdateWindowでウィンドウを更新.

	// 初期化成功
	return TRUE;	// 初期化成功ならTRUEを返す.

}