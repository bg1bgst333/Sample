// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// "test.txt"を既定のプログラムで開く.
	_tprintf(_T("open test.txt!\n"));	// "open test.txt!"と出力.
	ShellExecute(NULL, _T("open"), _T("test.txt"), NULL, NULL, SW_SHOW);	// ShellExecuteで"test.txt"を既定のプログラムで開く.("open"は指定のファイルを既定のプログラムで開くという操作. この場合, 既定のテキストエディタ(メモ帳など)で"test.txt"が開かれる.)
	
	// プログラムの終了
	return 0;

}