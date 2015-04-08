// ヘッダファイルのインクルード
#include "CWinApp_.h"	// CWinApp_クラス

// CWinApp_のメンバの定義
// メンバ関数InitInstance()
BOOL CWinApp_::InitInstance(){	// インスタンスの初期化処理

	// 変数の宣言
	int iRet;	// メッセージボックスで何が選択されたかを格納するint型変数iRet.

	// メッセージボックスで"はい", "いいえ"を選択.
	iRet = AfxMessageBox(_T("YesNo?"), MB_YESNO);	// AfxMessageBoxで"はい", "いいえ"選択型のメッセージボックスを表示.
	if (iRet == IDYES){	// "はい"

		// 初期化成功ということにする.
		return TRUE;	// 初期化成功ならTRUEを返す.

	}
	else{	// "いいえ"

		// 初期化失敗ということにする.
		return FALSE;	// 初期化失敗ならFALSEを返す.

	}

}

// メンバ関数Run()
int CWinApp_::Run(){	// メッセージループ

	// メッセージボックスを用意し, 表示されればここに来ている.
	AfxMessageBox(_T("Run"), MB_OK | MB_ICONASTERISK);	// AfxMessageBoxで"Run"と表示.

	// メッセージループの終了.
	return 0;	// ここは一応0にしておく.

}