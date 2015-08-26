// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言
	SYSTEMTIME st;	// SYSTEMTIME構造体変数st

	// 現在のローカル時刻(JST)を取得.
	GetLocalTime(&st);	// GetLocalTimeで現在のローカル時刻(JST)を取得し, stに格納する.

	// 現在のローカル時刻(JST)の出力.
	_tprintf(_T("[JST]: %d/%d/%d %d:%02d:%02d\n"), st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);	// stの各要素(年月日時分秒)を出力.

	// プログラムの終了.
	return 0;

}