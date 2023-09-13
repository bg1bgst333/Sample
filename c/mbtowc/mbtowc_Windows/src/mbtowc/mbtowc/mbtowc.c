/* ヘッダファイルのインクルード */
#include <stdio.h>	/* 標準入出力 */
#include <stdlib.h>	/* 標準ユーティリティ */
#include <locale.h>	/* ロケール */

/* main関数の定義 */
int main(void){

	/* 変数の初期化 */
	FILE *fp1 = NULL;
	char buf1[16] = {0};
	int len1 = 0;
	wchar_t wc1 = L'\0';
	int result1;

	/* "Japanese_Japan.932"指定 */
	setlocale(LC_ALL, "Japanese_Japan.932");	/* setlocaleにLC_ALL, "Japanese_Japan.932"を指定. */

	/* バイナリファイル入力 */
	fp1 = fopen("test1.txt", "rb");	/* "test1.txt"を開く. */
	if (fp1 == NULL){	/* 失敗 */
		perror("open test1");
		return -1;
	}
	len1 = fread(buf1, sizeof(char), 16, fp1);	/* freadで読み込み, buf1に格納. */
	printf("len1 = %d\n", len1);	/* len1を出力. */
	printf("buf1 = %s\n", buf1);	/* buf1を出力. */

	/* マルチバイト文字からワイド文字に変換. */
	result1 = mbtowc(&wc1, buf1, MB_CUR_MAX);	/* mbtowcでワイド文字に変換. */
	if (result1 < 0){	/* マイナスは失敗. */
		perror("mbtowc test1");
		fclose(fp1);	/* fp1を閉じる. */
		return -2;
	}
	printf("wc1 = %lc\n", wc1);	/* printfでwc1を出力. */

	/* 終了処理 */
	fclose(fp1);	/* fp1を閉じる. */
	
	/* 正常終了 */
	return 0;	/* 0を返して正常終了. */

}