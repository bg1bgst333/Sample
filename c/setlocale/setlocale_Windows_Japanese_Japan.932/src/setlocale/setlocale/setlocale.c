/* ヘッダファイルのインクルード */
#include <stdio.h>	/* 標準入出力 */
#include <locale.h>	/* ロケール */

/* main関数の定義 */
int main(void){

	/* 変数の宣言 */
	char *loc;
	FILE *fp1;
	FILE *fp2;

	/* "Japanese_Japan.932"指定 */
	loc = setlocale(LC_ALL, "Japanese_Japan.932");	/* setlocaleにLC_ALL, "Japanese_Japan.932"を指定. */
	printf("loc = %s\n", loc);	/* locを出力. */

	/* ファイルを開く. */
	fp1 = fopen("test1.txt", "w");	/* fopenで"test1.txt"を開く. */
	if (fp1 == NULL){	/* 失敗. */
		perror("fopen 1");
		return -1;
	}

	/* マルチバイト文字列で"あいうえお"を出力. */
	fprintf(fp1, "%s", "あいうえお");	/* fprintfで"あいうえお"を出力.

	/* 閉じる. */
	fclose(fp1); /* fcloseでfp1を閉じる. */

	/* ファイルを開く. */
	fp2 = fopen("test2.txt", "w");	/* fopenで"test2.txt"を開く. */
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