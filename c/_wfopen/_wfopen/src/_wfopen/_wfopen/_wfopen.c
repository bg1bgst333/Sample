/* ヘッダファイルのインクルード */
#include <stdio.h>	/* 標準入出力 */

/* main関数の定義 */
int main(void){

	/* ポインタの宣言 */
	FILE *fp;	/* ファイルポインタfp. */
	char buf[16];	/* char型バッファbuf. */

	/* ファイルを開く. */
	fp = _wfopen(L"test.txt", L"r");	/* _wfopenでL"test.txt"というファイルを読込専用(L"r")で開く. */
	if (fp == NULL){	/* fp == NULLならファイルを開くのに失敗. */

		/* エラー処理 */
		printf("Can't open file!\n");	/* printfで"Can't open file!"というエラーメッセージを出力. */
		return -1;	/* エラーなど異常終了の場合は, -1などの0以外の値を返す. */

	}

	/* ファイルからの読み込み */
	fscanf(fp, "%s", buf);	/* fscanfでfpを読み込んでbufに格納. */

	/* bufの出力. */
	printf("%s\n", buf);	/* printfでbufを出力. */

	/* ファイルを閉じる. */
	fclose(fp);	/* fcloseでfpの指すファイルを閉じる. */

	/* プログラムの終了 */
	return 0;	/* 正常終了 */

}