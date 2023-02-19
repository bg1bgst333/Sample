// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 配列の初期化
	TCHAR tszCurrentPath[MAX_PATH] = {0};	// このプロセスの現在のディレクトリパスを指すTCHAR配列tszCurrentPath(長さMAX_PATH)を{0}で初期化.

	// このプロセスの現在のディレクトリパスを取得.
	DWORD dwRet = GetCurrentDirectory(MAX_PATH, tszCurrentPath);	// GetCurrentDirectoryでtszCurrentPathを取得.
	if (dwRet != 0){	// 成功.
		_tprintf(_T("tszCurrentPath = %s\n"), tszCurrentPath);	// tszCurrentPathを出力.
	}
	else{	// 失敗.
		_tprintf(_T("GetCurrentDirectory failed.\n"));	// "GetCurrentDirectory failed."を出力.
	}

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}