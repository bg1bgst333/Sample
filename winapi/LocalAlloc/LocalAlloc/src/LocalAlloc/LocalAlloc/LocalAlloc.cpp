// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <stdio.h>		// C標準入出力
#include <string.h>		// C文字列処理

// main関数の定義
int main(int argc, TCHAR *argv[]){	// main関数

	// 変数の宣言.
	HLOCAL hLocal;		// ヒープハンドルhLocal
	LPSTR lpszText;		// 文字列ポインタlpszText

	// メモリ確保.
	hLocal = LocalAlloc(LMEM_FIXED, 16);	// LocalAllocでサイズ16の固定メモリを確保し, ヒープハンドルをhLocalに返す.
	
	// メモリのロック.
	lpszText = (LPSTR)LocalLock(hLocal);	// LocalLockでメモリ領域をロックし, メモリの先頭アドレスをlpszTextに返す.

	// 文字列を確保したメモリにコピー.
	strcpy(lpszText, "ABCDE");	// strcpyでlpszTextに"ABCDE"をコピー.

	// 文字列の出力.
	printf("lpszText(hLocal) = %s\n", lpszText);	// printfでlpszTextを出力.

	// メモリのアンロック.
	LocalUnlock(hLocal);	// LocalUnlockでhLocalのメモリ領域をアンロック.

	// メモリ解放.
	LocalFree(hLocal);	// LocalFreeでhLocalのメモリ解放.

	// プログラムの終了.
	return 0;

}