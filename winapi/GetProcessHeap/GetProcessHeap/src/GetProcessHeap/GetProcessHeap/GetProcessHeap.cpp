// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <stdio.h>		// C標準入出力
#include <string.h>		// C文字列処理

// main関数の定義
int main(int argc, TCHAR *argv[]){	// main関数

	// 変数の宣言.
	HANDLE hHeap;	// ヒープハンドルhHeap

	// このプロセスのヒープを取得.
	hHeap = GetProcessHeap();	// GetProcessHeapでこのプロセスのヒープハンドルを取得.

	// ヒープハンドルの値を出力.
	printf("hHeap = 0x%08x\n", hHeap);	// printfでhHeapを出力.

	// プログラムの終了.
	return 0;

}