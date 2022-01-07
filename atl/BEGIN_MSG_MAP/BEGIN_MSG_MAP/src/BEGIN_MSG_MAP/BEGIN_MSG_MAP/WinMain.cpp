// ヘッダのインクルード
// 既定のヘッダ
#include <tchar.h>	// TCHAR
// 独自のヘッダ
#include "stdafx.h"	// stdafx.h
#include "CustomWindow.h"	// CCustomWindow

// _Moduleの定義.
CComModule _Module;	// 実体はここに定義.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){	// Windowsプログラムのエントリポイント

	// 初期化
	_Module.Init(NULL, hInstance);	// _Module.Initで初期化.

	// ウィンドウの作成.
	CCustomWindow customWnd;	// CCustomWindowオブジェクトcustomWndを宣言.
	customWnd.Create(NULL, CWindow::rcDefault, _T("BEGIN_MSG_MAP"), WS_OVERLAPPEDWINDOW);	// customWnd.Createでウィンドウ名"BEGIN_MSG_MAP"のウィンドウを作成.
	customWnd.ShowWindow(SW_SHOW);	// customWnd.ShowWindowでウィンドウを表示.

	// メッセージループ.
	MSG msg;	// MSG構造体変数msgを宣言.
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// メッセージが来る間.

		// メッセージ処理.
		TranslateMessage(&msg);	// TranslateMessageで変換処理.
		DispatchMessage(&msg);	// DispatchMessageで送出処理.

	}
	
	// 終了処理
	_Module.Term();	// _Module.Termで終了処理.

	// プログラムの終了.
	return msg.wParam;	// msg.wParamを返して正常終了.

}