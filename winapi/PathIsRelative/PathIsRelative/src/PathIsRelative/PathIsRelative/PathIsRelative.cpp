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

	// 与えられた引数のパスが相対パスかどうかチェック.
	BOOL bRet = PathIsRelative(argv[1]);	// PathIsRelativeでargv[1]というパスが相対パスかどうかチェック.
	if (bRet){	// bRetがTRUE.
		_tprintf(_T("Relative!\n"));	// "Relative!"と出力.
	}
	else{	// bRetがFALSE.
		_tprintf(_T("Not relative!\n"));	// "Not relative!"と出力.
	}

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}