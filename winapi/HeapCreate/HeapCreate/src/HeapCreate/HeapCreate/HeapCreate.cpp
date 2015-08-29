// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <stdio.h>		// C標準入出力
#include <string.h>		// C文字列処理

// main関数の定義
int main(int argc, TCHAR *argv[]){	// main関数

	// 変数の宣言.
	HANDLE hHeap;	// ヒープハンドルhHeap
	LPSTR lpszText;	// 文字列ポインタlpszText

	// 新たにヒープを作成.
	hHeap = HeapCreate(0, 0, 0);	// HeapCreateで新たにヒープを作成.

	// メモリ確保.
	lpszText = (LPSTR)HeapAlloc(hHeap, HEAP_ZERO_MEMORY, 16);	// HeapAllocでサイズ16のメモリを確保し, そのメモリのポインタを返す.(LPVOIDなのでLPSTRにキャストしてlpszTextに格納.)

	// 文字列を確保したメモリにコピー.
	strcpy(lpszText, "ABCDE");	// strcpyでlpszTextに"ABCDE"をコピー.

	// 文字列の出力.
	printf("lpszText(hHeap) = %s\n", lpszText);	// printfでlpszTextを出力.

	// メモリ解放.
	HeapFree(hHeap, NULL, lpszText);	// HeapFreeでlpszTextのメモリを解放.

	// 作成したヒープを破棄.
	HeapDestroy(hHeap);	// HeapDestroyでヒープを破棄.

	// プログラムの終了.
	return 0;

}