// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// C標準入出力

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;			// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;			// ウィンドウメッセージ情報を格納するMSG構造体型変数msg.
	TCHAR tszMsg[128];	// ウィンドウメッセージ番号文字列を格納するTCHAR型配列tszMsg.(長さ128)

	// ウィンドウの作成
	hWnd = CreateWindow(_T("STATIC"), _T(""), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで"STATIC"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("GetMessage"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
		return -1;	// 異常終了

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.

	// メッセージの取得
	GetMessage(&msg, NULL, 0, 0);	// GetMessageでウィンドウメッセージを取得してmsgに格納.
	_stprintf(tszMsg, _T("msg.message = 0x%08x"), msg.message);	// メッセージ番号msg.messageを含む文字列を作成.
	MessageBox(hWnd, tszMsg, _T("GetMessage"), MB_OK | MB_ICONASTERISK);	// MessageBoxで取得したメッセージ番号を表示.

	// ウィンドウの破棄
	DestroyWindow(hWnd);	// DestroyWindowでhWndを破棄.

	// プログラムの終了
	return 0;

}