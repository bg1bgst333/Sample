// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// C標準入出力

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;			// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	TCHAR tszHWnd[128];	// hWndの値を16進整数の文字列に変換したものを格納するTCHAR型配列tszHWnd.(長さ128)

	// ウィンドウの作成
	hWnd = CreateWindow(_T("STATIC"), _T(""), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで"STATIC"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("CreateWindow"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
		return -1;	// 異常終了

	}

	// ウィンドウハンドルの表示
	_stprintf(tszHWnd, _T("CreateWindow succeed!(hWnd = 0x%08x)"), hWnd);	// _stprintfでhWndの16進整数値を文字列に変換してtszHWndに格納.
	MessageBox(hWnd, tszHWnd, _T("CreateWindow"), MB_OK | MB_ICONASTERISK);	// MessageBoxでtszHWndを表示.

	// ウィンドウの破棄
	DestroyWindow(hWnd);	// DestroyWindowでhWndを破棄.

	// プログラムの終了
	return 0;

}