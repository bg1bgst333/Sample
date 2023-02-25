// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <shlwapi.h>	// シェルAPI

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// コマンドライン引数の数.
	_tprintf(_T("argc = %d\n"), argc);	// argcを出力.
	if (argc != 2){	// 2以外はエラー.
		_tprintf(_T("error: argc != 2\n"));	// "error: argc != 2"と出力.
		return -1;	// -1を返して異常終了.
	}

	// パスからファイル名部分を抽出.
	TCHAR *ptszFileName = NULL;	// ファイル名を指すTCHAR型ポインタptszFileNameをNULLで初期化.
	ptszFileName = PathFindFileName(argv[1]);	// PathFindFileNameでargv[1]のファイル名部分を抽出.
	_tprintf(_T("ptszFileName = %s\n"), ptszFileName);	// ptszFileNameを出力.

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}