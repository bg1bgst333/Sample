/* ヘッダファイルのインクルード */
#include <stdio.h>	/* 標準入出力 */
#include <locale.h>	/* ロケール */

/* main関数の定義 */
int main(void){

	/* 変数の宣言 */
	FILE *fp1;
	FILE *fp2;

	/* ファイルを開く. */
	fp1 = fopen("test1.txt", "w,ccs=UNICODE");	/* fopenで"test1.txt"を開く. */
	if (fp1 == NULL){	/* 失敗. */
		perror("fopen 1");
		return -1;
	}

	/* ワイド文字列でL"あいうえお"を出力. */
	fwprintf(fp1, L"%s", L"あいうえお");	/* fwprintfでL"あいうえお"を出力. */

	/* 閉じる. */
	fclose(fp1); /* fcloseでfp1を閉じる. */

	/* ファイルを開く. */
	fp2 = fopen("test2.txt", "w, ccs=UNICODE");	/* fopenで"test2.txt"を開く. */
	if (fp2 == NULL){	/* 失敗. */
		perror("fopen 2");
		return -2;
	}

	/* ワイド文字列でL"あいうえお"を出力. */
	fwprintf(fp2, L"%s", L"あいうえお");	/* fwprintfでL"あいうえお"を出力. */

	/* 閉じる. */
	fclose(fp2); /* fcloseでfp2を閉じる. */

	/* プログラムの終了 */
	return 0;

}