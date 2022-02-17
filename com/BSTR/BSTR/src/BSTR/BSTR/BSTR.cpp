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

	// 各文字の出力.
	wprintf(L"str[%d] = %lu\n", -1, *(str - 2));				// strの2個前(BSTRが2つ分なので4バイト前)を符号無し整数値で出力.
	wprintf(L"str[%d] = 0x%08x\n", 0, (unsigned long)str[0]);	// str[0]の出力.
	wprintf(L"str[%d] = 0x%08x\n", 1, (unsigned long)str[1]);	// str[1]の出力.
	wprintf(L"str[%d] = 0x%08x\n", 2, (unsigned long)str[2]);	// str[2]の出力.
	wprintf(L"str[%d] = 0x%08x\n", 3, (unsigned long)str[3]);	// str[3]の出力.
	wprintf(L"str[%d] = 0x%08x\n", 4, (unsigned long)str[4]);	// str[4]の出力.
	wprintf(L"str[%d] = 0x%08x\n", 5, (unsigned long)str[5]);	// strの1個後(BSTRが1つ分なので2バイト後)を出力.

	// strの解放.
	SysFreeString(str);	// SysFreeStringでstrを解放.

	// プログラムの終了.
	return 0;	// 0を返して終了.

}