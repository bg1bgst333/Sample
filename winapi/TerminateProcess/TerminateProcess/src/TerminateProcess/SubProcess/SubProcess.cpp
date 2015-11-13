// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// "SubProcess Start!"と出力.
	_tprintf(_T("SubProcess Start!\n"));	// "SubProcess Start!"と出力.

	// 30秒休止
	Sleep(30000);	// Sleepで30000ミリ秒休止.

	// "SubProcess End!"と出力.
	_tprintf(_T("SubProcess End!\n"));	// "SubProcess End!"と出力.

	// プログラムの終了
	ExitProcess(10);	// ExitProcessで終了コードとして10を返す.

}