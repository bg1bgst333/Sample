/* ヘッダファイルのインクルード */
#include <stdio.h>	/* 標準入出力 */
#include <stdlib.h>	/* 標準ユーティリティ */
#include <locale.h>	/* ロケール */

/* main関数の定義 */
int main(void){

	/* 変数の初期化 */
	const wchar_t wc = L'あ';
	int wcsize = sizeof(wc);
	char mb1[MB_LEN_MAX + 1] = {0};
	int len1 = 0;
	FILE *fp1 = NULL;

	/* "Japanese_Japan.932"指定 */
	setlocale(LC_ALL, "Japanese_Japan.932");	/* setlocaleにLC_ALL, "Japanese_Japan.932"を指定. */

	/* 標準出力 */
	printf("wc = %lc\n", wc);	/* wcを出力. */
	printf("wc(%%04x) = 0x%04x\n", wc);	/* wcを16進数出力. */
	printf("wcsize = %d\n", wcsize);	/* wcsizeを出力. */

	/* ワイド文字からマルチバイト文字へ変換. */
	len1 = wctomb(mb1, wc);	/* wctombでワイド文字からマルチバイト文字へ変換. */

	/* 標準出力 */
	printf("mb1 = %s\n", mb1);	/* mb1を出力. */
	printf("len1 = %d\n", len1);	/* len1を出力. */

	/* バイナリファイル出力 */
	fp1 = fopen("test1.txt", "wb");	/* "test1.txt"を開く. */
	if (fp1 == NULL){	/* 失敗 */
		perror("test1");
		return -1;
	}
	fwrite(mb1, sizeof(char), len1, fp1);	/* fwriteでmb1を書き込む. */
	fclose(fp1);	/* 閉じる */

	/* 正常終了 */
	return 0;	/* 0を返して正常終了. */

}