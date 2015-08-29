// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <stdio.h>		// C標準入出力
#include <string.h>		// C文字列処理

// main関数の定義
int main(int argc, TCHAR *argv[]){	// main関数

	// 変数の宣言.
	LPSTR lpszText;	// 文字列ポインタlpszText

	// メモリ確保.
	lpszText = (LPSTR)VirtualAlloc(NULL, 128, MEM_COMMIT, PAGE_READWRITE);	// VirtualAllocでメモリ確保.

	// 文字列を確保したメモリにコピー.
	strcpy(lpszText, "ABCDE");	// strcpyでlpszTextに"ABCDE"をコピー.

	// 文字列の出力.
	printf("lpszText(Virtual) = %s\n", lpszText);	// printfでlpszTextを出力.

	// メモリ解放.
	VirtualFree((LPVOID)lpszText, 0, MEM_RELEASE);	// VirtualFreeでメモリ解放.

	// プログラムの終了.
	return 0;

}