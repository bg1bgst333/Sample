// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// C標準入出力

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の初期化
	HANDLE hProcess = NULL;	// プロセスハンドルhProcessをNULLで初期化.
	TCHAR tszHProcess[64] = {0};	// 文字配列tszHProcess(長さ64)を{0}で初期化.

	// 現在のプロセスの擬似ハンドルを取得.(実際には常に-1が返ってくる仕様.互換性のためにこの関数で取得することが推奨されている.)
	hProcess = GetCurrentProcess();	// GetCurrentProcessの戻り値をhProcessに格納.
	_stprintf(tszHProcess, _T("hProcess = %d"), (int)hProcess);	// _stprintfでhProcessをtszHProcessに変換.

	// hProcessを表示.
	MessageBox(NULL, tszHProcess, _T("GetCurrentProcess"), MB_OK);	// MessageBoxでtszHProcessを表示.

	// プログラムの終了
	return 0;	// 0を返して正常終了.

}
