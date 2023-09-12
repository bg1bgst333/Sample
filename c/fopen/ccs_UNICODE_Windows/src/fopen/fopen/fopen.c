/* ヘッダファイルのインクルード */
#include <stdio.h>	/* 標準入出力 */
#include <locale.h>	/* ロケール */

/* main関数の定義 */
int main(void){

	/* 変数の宣言・初期化 */
	char *loc;
	FILE *fp1;
	FILE *fp2;
	wchar_t buf1[16] = {0};
	wchar_t buf2[16] = {0};

	/* "Japanese_Japan.932"指定 */
	loc = setlocale(LC_ALL, "Japanese_Japan.932");	/* setlocaleにLC_ALL, "Japanese_Japan.932"を指定. */
	printf("loc = %s\n", loc);	/* locを出力. */

	/* ファイルを開く. */
	fp1 = fopen("test1.txt", "r,ccs=UNICODE");	/* fopenで"test1.txt"を開く. */
	if (fp1 == NULL){	/* 失敗. */
		perror("fopen 1");
		return -1;
	}

	/* ファイル入力データをワイド文字列として格納. */
	fwscanf(fp1, L"%s", buf1);	/* fwscanfでbuf1に格納. */
	wprintf(L"%s\n", buf1);	/* buf1を出力. */

	/* 閉じる. */
	fclose(fp1); /* fcloseでfp1を閉じる. */

	/* ファイルを開く. */
	fp2 = fopen("test2.txt", "r, ccs=UNICODE");	/* fopenで"test2.txt"を開く. */
	if (fp2 == NULL){	/* 失敗. */
		perror("fopen 2");
		return -2;
	}

	/* ファイル入力データをワイド文字列として格納. */
	fwscanf(fp2, L"%s", buf2);	/* fwscanfでbuf2に格納. */
	wprintf(L"%s\n", buf2);	/* buf2を出力. */

	/* 閉じる. */
	fclose(fp2); /* fcloseでfp2を閉じる. */

	/* プログラムの終了 */
	return 0;

}