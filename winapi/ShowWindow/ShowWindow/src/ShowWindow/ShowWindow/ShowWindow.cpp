// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;	// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.

	// ウィンドウの作成
	hWnd = CreateWindow(_T("STATIC"), _T(""), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで"STATIC"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("ShowWindow"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
		return -1;	// 異常終了

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.
	MessageBox(hWnd, _T("CreateWindow succeed!"), _T("ShowWindow"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"CreateWindow succeed!"を表示.(なおかつ, ウィンドウの表示状態を維持している.)

	// ウィンドウの破棄
	DestroyWindow(hWnd);	// DestroyWindowでhWndを破棄.

	// プログラムの終了
	return 0;

}