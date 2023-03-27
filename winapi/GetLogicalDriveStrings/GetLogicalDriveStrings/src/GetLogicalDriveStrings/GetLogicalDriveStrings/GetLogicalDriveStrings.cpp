// ヘッダファイルのインクルード
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <string.h>		// 文字列処理
#include <windows.h>	// 標準WindowsAPI

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 配列・ポインタの初期化.
	TCHAR tszDrives[128] = {0};	// ドライブ文字列群が格納されるTCHAR型配列tszDrives(長さ128)を{0}で初期化.
	TCHAR *ptszDrive = NULL;	// ドライブ文字列を指すTCHAR型ポインタptszDriveをNULLで初期化.

	// 有効なドライブ文字列群を取得.
	GetLogicalDriveStrings(128, tszDrives);	// GetLogicalDriveStringsで有効なドライブ文字列群を取得.

	// ドライブ文字列一覧出力.
	ptszDrive = tszDrives;	// 先頭にセット.
	while (*ptszDrive != _T('\0')){	// NULL文字でない.
		_tprintf(_T("%s\n"), ptszDrive);	// ptszDriveを出力.
		ptszDrive += _tcslen(ptszDrive) + 1;	// ptszDriveの(文字数 + 1)の分だけ進む.
	}

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}