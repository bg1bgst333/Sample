// ヘッダのインクルード
// 独自のヘッダ
#include "Application.h"	// CApplication

// コンストラクタCApplication
CApplication::CApplication(){

	// メンバの初期化
	m_pMainWnd = NULL;	// m_pMainWndをNULLで初期化.

}

// メッセージループ処理関数Run.
int CApplication::Run(){

	// 構造体の宣言
	MSG msg;	// MSG型構造体msg.

	// メッセージループの処理
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessageでウィンドウメッセージを取得し, msgに格納.(0以下ならここを抜ける.)

		// メッセージの変換と送出.
		TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.
		DispatchMessage(&msg);	// DispatchMessageでメッセージをウィンドウプロシージャWindowProcに送出.

	}

	// ExitInstanceの値を返す.
	return ExitInstance();	// returnでExitInstanceの値を返す.

}

// 終了処理関数ExitInstance.
int CApplication::ExitInstance(){

	// メインウィンドウの破棄
	if (m_pMainWnd != NULL){	// m_pMainWndがNULLでない時.

		// 破棄する.
		delete m_pMainWnd;	// deleteでm_pMainWndを破棄.
		m_pMainWnd = NULL;	// m_pMainWndにNULLをセット.

	}

	// 今回は常に0を返す.
	return 0;	// returnで0を返す.

}