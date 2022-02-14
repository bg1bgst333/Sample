// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR対応
#include <stdio.h>		// C標準入出力

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// BSTR型文字列strに文字列を割り当てる.
	BSTR str = SysAllocString(L"ABCDE");	// SysAllocStringでstrにワイド文字列の"ABCDE"を割り当てる.

	// strの出力.
	wprintf(L"%s\n", str);	// wprintfでstrを出力.

	// strの解放.
	SysFreeString(str);	// SysFreeStringでstrを解放.

	// プログラムの終了.
	return 0;	// 0を返して終了.

}