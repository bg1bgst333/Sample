// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <stdio.h>		// C標準入出力
#include <string.h>		// C文字列処理

// main関数の定義
int main(int argc, TCHAR *argv[]){	// main関数

	// 変数の宣言.
	HGLOBAL hGlobal;	// ヒープハンドルhGlobal
	LPSTR lpszText;		// 文字列ポインタlpszText

	// メモリ確保.
	hGlobal = GlobalAlloc(GMEM_FIXED, 16);	// GlobalAllocでサイズ16の固定メモリを確保し, ハンドルをhGlobalに返す.

	// メモリのロック.
	lpszText = (LPSTR)GlobalLock(hGlobal);	// GlobalLockでメモリ領域をロックし, メモリの先頭アドレスをlpszTextに返す.

	// 固定メモリの場合はハンドルhGlobalとポインタlpszTextの値は同じ.
	printf("hGlobal = 0x%08x\n", (unsigned int)hGlobal);	// hGlobalの値を出力.
	printf("lpszText = 0x%08x\n", (unsigned int)lpszText);	// lpszTextの値を出力.

	// 文字列を確保したメモリにコピー.
	strcpy((LPSTR)hGlobal, "ABCDE");	// strcpyでhGlobalに"ABCDE"をコピー.(hGlobalをLPSTRにキャスト.)

	// 文字列の出力.
	printf("hGlobal = %s\n", (LPSTR)hGlobal);	// printfでhGlobalを出力.(hGlobalをLPSTRにキャスト.)
	printf("lpszText = %s\n", lpszText);	// printfでlpszTextを出力.

	// メモリのアンロック.
	GlobalUnlock(hGlobal);	// GlobalUnlockでhGlobalのメモリ領域をアンロック.

	// メモリ解放.
	GlobalFree(hGlobal);	// GlobalFreeでhGlobalのメモリ解放.

	// 再びメモリ確保.
	hGlobal = GlobalAlloc(GHND | GMEM_SHARE, 16);	// GlobalAllocでサイズ16の移動可能な0で初期化されたメモリを確保し, ハンドルをhGlobalに返す.

	// メモリのロック.
	lpszText = (LPSTR)GlobalLock(hGlobal);	// GlobalLockでメモリ領域をロックし, メモリの先頭アドレスをlpszTextに返す.

	// 移動可能メモリの場合はハンドルhGlobalとポインタlpszTextの値が異なる.
	printf("hGlobal = 0x%08x\n", (unsigned int)hGlobal);	// hGlobalの値を出力.
	printf("lpszText = 0x%08x\n", (unsigned int)lpszText);	// lpszTextの値を出力.

	// 文字列を確保したメモリにコピー.
	strcpy(lpszText, "ABCDE");	// strcpyでlpszTextに"ABCDE"をコピー.

	// 文字列の出力.
	printf("lpszText = %s\n", lpszText);	// printfでlpszTextを出力.

	// メモリのアンロック.
	GlobalUnlock(hGlobal);	// GlobalUnlockでhGlobalのメモリ領域をアンロック.

	// メモリ解放.
	GlobalFree(hGlobal);	// GlobalFreeでhGlobalのメモリ解放.

	// プログラムの終了.
	return 0;

}