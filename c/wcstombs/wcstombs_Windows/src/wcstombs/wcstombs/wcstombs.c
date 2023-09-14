/* ヘッダファイルのインクルード */
#include <stdio.h>	/* 標準入出力 */
#include <stdlib.h>	/* 標準ユーティリティ */
#include <locale.h>	/* ロケール */

/* main関数の定義 */
int main(void){

	/* 変数・配列の宣言・初期化 */
	wchar_t wstr[] = L"あいうえお";
	int buf_size1;
	char *buf1_ptr = NULL;
	int len1;
	FILE *fp1 = NULL;

	/* "Japanese_Japan.932"指定 */
	setlocale(LC_ALL, "Japanese_Japan.932");	/* setlocaleにLC_ALL, "Japanese_Japan.932"を指定. */
	
	/* 標準出力 */
	printf("wstr = %ls\n", wstr);	/* wstrを出力. */
	
	/* バッファサイズ取得. */
	buf_size1 = wcstombs(NULL, wstr, 0);	/* 先頭NULLで必要バッファサイズをbuf_size1に格納. */
	
	/* ワイド文字列からマルチバイト文字列へ変換. */
	buf1_ptr = malloc((buf_size1 + 1) * sizeof(char));	/* (buf_size1 + 1)分のメモリ確保. */
	len1 = wcstombs(buf1_ptr, wstr, buf_size1);	/* wcstombsで変換. */
	*(buf1_ptr + len1) = '\0';	/* 終端はNULL. */
	
	/* 標準出力 */
	printf("buf1_ptr = %s\n", buf1_ptr);	/* buf1_ptrを出力. */
	printf("len1 = %d\n", len1);	/* len1を出力. *;

	/* バイナリファイル出力 */
	fp1 = fopen("test1.txt", "wb");	/* "test1.txt"を開く. */
	if (fp1 == NULL){	/* 失敗 */
		perror("test1");
		free(buf1_ptr);	/* 解放 */
		return -1;
	}
	fwrite(buf1_ptr, sizeof(char), len1, fp1);	/* fwriteでbuf1_ptrを書き込む. */
	fclose(fp1);	/* 閉じる */
	free(buf1_ptr);	/* 解放 */

	/* 正常終了 */
	return 0;	/* 0を返して正常終了. */

}