// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){	// TCHAR対応版

	// デバッグ用の文字列を出力する.
	OutputDebugString(_T("ABCDE\n"));	// デバッグ用の文字列として"ABCDE"と改行を出力する.

	// プログラムの正常終了
	return 0;	// 0を返して正常終了.

}