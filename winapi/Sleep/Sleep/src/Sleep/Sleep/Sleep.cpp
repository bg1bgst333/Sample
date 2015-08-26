// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言
	SYSTEMTIME st1;	// SYSTEMTIME構造体変数st1
	SYSTEMTIME st2;	// SYSTEMTIME構造体変数st2

	// ローカル時刻(JST)を取得.(1回目)
	GetLocalTime(&st1);	// GetLocalTimeでローカル時刻(JST)を取得し, st1に格納する.

	// ローカル時刻(JST)の出力.(1回目)
	_tprintf(_T("[JST(1)]: %d/%d/%d %d:%02d:%02d\n"), st1.wYear, st1.wMonth, st1.wDay, st1.wHour, st1.wMinute, st1.wSecond);	// st1の各要素(年月日時分秒)を出力.

	// Sleepで5秒休む.
	Sleep(5000);	// Sleepで5秒(5000ミリ秒)CPUを休ませる.

	// ローカル時刻(JST)を取得.(2回目)
	GetLocalTime(&st2);	// GetLocalTimeでローカル時刻(JST)を取得し, st2に格納する.

	// ローカル時刻(JST)の出力.(2回目)
	_tprintf(_T("[JST(2)]: %d/%d/%d %d:%02d:%02d\n"), st2.wYear, st2.wMonth, st2.wDay, st2.wHour, st2.wMinute, st2.wSecond);	// st2の各要素(年月日時分秒)を出力.

	// プログラムの終了.
	return 0;

}