// ヘッダファイルのインクルード
#include "CWinApp_.h"	// CWinApp_クラス
#include "resource.h"	// リソースID

// CWinApp_のメンバの定義
// メンバ関数InitInstance()
BOOL CWinApp_::InitInstance(){	// インスタンスの初期化処理

	// 構造体の宣言
	CFrameWnd *pFrameWnd;			// CFrameWndのオブジェクトポインタ

	// CFrameWndのインスタンス作成
	pFrameWnd = new CFrameWnd();	// newでCFrameWndのインスタンスを作成し, pFrameWndに格納.
	m_pMainWnd = pFrameWnd;			// m_pMainWndにpFrameWndをセット.

	// フレームをリソースからロードしてウィンドウを作成.
	pFrameWnd->LoadFrame(IDR_MAINFRAME);	// LoadFrameで共有リソースIDがIDR_MAINFRAMEとなるフレームをロード.

	// CFrameWndの表示
	pFrameWnd->ShowWindow(m_nCmdShow);	// ShowWindowでウィンドウを表示.

	// CFrameWndの更新
	pFrameWnd->UpdateWindow();	// UpdateWindowでウィンドウを更新.

	// 初期化成功
	return TRUE;	// 初期化成功ならTRUEを返す.

}