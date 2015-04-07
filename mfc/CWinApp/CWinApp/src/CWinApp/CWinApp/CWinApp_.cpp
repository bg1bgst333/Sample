// ヘッダファイルのインクルード
#include "CWinApp_.h"	// CWinApp_クラス

// CWinApp_のメンバの定義
// メンバ関数InitInstance()
BOOL CWinApp_::InitInstance(){	// インスタンスの初期化処理

	// メッセージボックスでクラス名を表示.
	AfxMessageBox(_T("CWinApp_"));	// AfxMessageBoxで"CWinApp_"と表示.

	// 初期化成功
	return TRUE;	// 初期化成功ならTRUEを返す.

}