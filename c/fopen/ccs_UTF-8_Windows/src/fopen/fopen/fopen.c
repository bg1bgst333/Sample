/* ヘッダファイルのインクルード */
#include <stdio.h>	/* 標準入出力 */
#include <locale.h>	/* ロケール */

/* main関数の定義 */
int main(void){

	/* 変数の宣言 */
	FILE *fp1;

	/* ファイルを開く. */
	fp1 = fopen("test1.txt", "w, ccs=UTF-8");	/* fopenで"test1.txt"を開く. */
	if (fp1 == NULL){	/* 失敗. */
		perror("fopen 1");
		return -1;
	}

	/* ワイド文字列でL"あいうえお"を出力. */
	fwprintf(fp1, L"%s", L"あいうえお");	/* fwprintfでL"あいうえお"を出力. */

	/* 閉じる. */
	fclose(fp1); /* fcloseでfp1を閉じる. */

	/* プログラムの終了 */
	return 0;

}