// ヘッダファイルのインクルード
#include "CFrameWnd_.h"	// CFrameWnd_クラス

// CFrameWnd_のメッセージマップ
BEGIN_MESSAGE_MAP(CFrameWnd_, CFrameWnd)
	ON_WM_CREATE()	// OnCreateのメッセージマクロ
END_MESSAGE_MAP()

// CFrameWnd_のメンバの定義
// コンストラクタCFrameWnd_()
CFrameWnd_::CFrameWnd_(){	// 初期化処理

}

// メッセージハンドラOnCreate()
int CFrameWnd_::OnCreate(LPCREATESTRUCT lpCreateStruct){	// ウィンドウが作成された時.

	// 変数・オブジェクトの宣言
	CString cstrMsg;	// メッセージボックスで表示する文字列を格納するcstrMsg.
	CString cstrTmp;	// 書式変換用一時文字列cstrTmp.

	// cstMsgにlpCreateStructの内容の一部を追加する.
	cstrMsg = cstrMsg + _T("OnCreate");													// まずは"OnCreate"を追加.
	cstrTmp.Format(_T("\nm_hWnd = 0x%08x"), m_hWnd);									// 次にcstrTmpにm_hWndをFormatメンバ関数で表示文字列にしたものをセット.
	cstrMsg = cstrMsg + cstrTmp;														// cstrTmpを追加.
	cstrTmp.Format(_T("\nlpCreateStruct->lpszName = %s"), lpCreateStruct->lpszName);	// 次にcstrTmpにlpCreateStruct->lpszNameをFormatメンバ関数で表示文字列にしたものをセット.
	cstrMsg = cstrMsg + cstrTmp;														// cstrTmpを追加.
	cstrTmp.Format(_T("\nlpCreateStruct->x = %d"), lpCreateStruct->x);					// 次にcstrTmpにlpCreateStruct->xをFormatメンバ関数で表示文字列にしたものをセット.
	cstrMsg = cstrMsg + cstrTmp;														// cstrTmpを追加.
	cstrTmp.Format(_T("\nlpCreateStruct->y = %d"), lpCreateStruct->y);					// 次にcstrTmpにlpCreateStruct->yをFormatメンバ関数で表示文字列にしたものをセット.
	cstrMsg = cstrMsg + cstrTmp;														// cstrTmpを追加.

	// cstrMsgを表示.
	AfxMessageBox(cstrMsg, MB_OK | MB_ICONASTERISK);	// AfxMessageBoxでcstrMsgを表示.

	// ウィンドウ作成成功
	return 0;	// return文で0を返して, ウィンドウ作成成功とする.

}