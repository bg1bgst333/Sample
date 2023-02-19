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
		
		// 相対パスである.
		_tprintf(_T("Relative!\n"));	// "Relative!"と出力.

		// 絶対パスを取得する.
		TCHAR tszFullPath[MAX_PATH] = {0};	// フルパス文字列を格納するTCHAR型配列tszFullPath(長さMAX_PATH)を{0}で初期化.
		TCHAR *ptszFilePart = NULL;	// パスのファイル名部分を指すTCHAR型ポインタptszFilePartをNULLで初期化.
		DWORD dwRet = GetFullPathName(argv[1], MAX_PATH, tszFullPath, &ptszFilePart);	// GetFullPathNameでargv[1]のフルパスを取得.
		if (dwRet != 0){	// 0以外なら成功.
			_tprintf(_T("tszFullPath = %s\n"), tszFullPath);	// tszFullPathを出力.
			_tprintf(_T("ptszFilePart = %s\n"), ptszFilePart);	// ptszFilePartを出力.
		}
		else{	// 0なら失敗.
			_tprintf(_T("GetFullPathName failed.\n"));	// "GetFullPathName failed."を出力.
		}

	}
	else{	// bRetがFALSE.
		_tprintf(_T("Not relative!\n"));	// "Not relative!"と出力.
	}

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}