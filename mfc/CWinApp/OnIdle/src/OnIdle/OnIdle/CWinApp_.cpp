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
	pFrameWnd_->Create(NULL, _T("OnIdle"));	// CreateでCFrameWnd_のインスタンスのウィンドウを作成.

	// CFrameWnd_の表示
	pFrameWnd_->ShowWindow(m_nCmdShow);	// ShowWindowでウィンドウを表示.

	// CFrameWnd_の更新
	pFrameWnd_->UpdateWindow();	// UpdateWindowでウィンドウを更新.

	// 初期化成功
	return TRUE;	// 初期化成功ならTRUEを返す.

}

// メンバ関数OnIdle()
BOOL CWinApp_::OnIdle(LONG lCount){	// アイドル時の処理(メッセージが来ない時の処理.)

	// オブジェクトの宣言
	CClientDC dc(m_pMainWnd);	// CClientDCオブジェクトのコンストラクタにm_pMainWnd(CFrameWnd_のインスタンス)を渡す.
	CString cstrLCount;			// lCountの値を表す文字列cstrLCount.

	// lCountの値を表す文字列をcstrLCountにセット.
	cstrLCount.Format(_T("lCount = %d"), lCount);	// cstrLCountのメンバ関数FormatでlCountを使った文字列をセット.

	// 文字列の描画
	dc.TextOut(0, 0, cstrLCount, cstrLCount.GetLength());	// dcのメンバ関数TextOutでcstrLCountを描画.(GetLengthメンバ関数は文字列長を返す.)

	// lCountが50000以上になったら, アイドル状態をやめる.
	if (lCount >= 50000){	// lCountが50000以上になったら.
		return FALSE;	// FALSEを返してアイドル状態をやめる.
	}

	// lCountが50000未満ならアイドル状態を継続する.
	return TRUE;	// TRUEを返してアイドル状態を継続する.

}