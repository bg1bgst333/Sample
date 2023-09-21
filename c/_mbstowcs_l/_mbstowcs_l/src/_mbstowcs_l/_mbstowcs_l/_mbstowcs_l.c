/* ヘッダファイルのインクルード */
#include <stdio.h>	/* 標準入出力 */
#include <stdlib.h>	/* 標準ユーティリティ */
#include <locale.h>	/* ロケール */

/* main関数の定義 */
int main(void){

	/* 変数・配列の宣言・初期化 */
	_locale_t loc1;
	FILE *fp1 = NULL;
	char buf1[16] = {0};
	int len1;
	int buf_size1;
	wchar_t *wstr1 = NULL;
	int wstr1_len;

	/* "Japanese_Japan.932"指定 */
	setlocale(LC_ALL, "Japanese_Japan.932");	/* setlocaleにLC_ALL, "Japanese_Japan.932"を指定. */

	/* "Japanese_Japan.20932"(EUC-JP)ロケールloc1の生成. */
	loc1 = _create_locale(LC_ALL, "Japanese_Japan.20932");	/* _create_localeで"Japanese_Japan.20932"なロケールloc1を作成. */

	/* バイナリファイル入力 */
	fp1 = fopen("test1.txt", "rb");	/* "test1.txt"を開く. */
	if (fp1 == NULL){	/* 失敗 */
		perror("open test1");
		_free_locale(loc1);	/* _free_localeでloc1を解放. */
		return -1;
	}
	len1 = fread(buf1, sizeof(char), 15, fp1);	/* freadで読み込み, buf1に格納. */
	buf1[len1] = '\0';	/* 末尾にNULL文字. */
	printf("buf1 = %s\n", buf1);	/* buf1を出力. */

	/* バッファサイズ取得. */
	buf_size1 = _mbstowcs_l(NULL, buf1, 0, loc1);	/* 先頭NULLで必要バッファサイズをbuf_size1に格納. */
	printf("buf_size1 = %d\n", buf_size1);	/* buf_size1を出力. */

	/* マルチバイト文字列からワイド文字列に変換. */
	wstr1 = malloc((buf_size1 + 1) * sizeof(wchar_t));	/* (buf_size1 + 1) * sizeof(wchar_t)分のメモリ確保. */
	wstr1_len = _mbstowcs_l(wstr1, buf1, buf_size1 + 1, loc1);	/* _mbstowcs_lでワイド文字列に変換. */
	if (wstr1_len < 0){	/* マイナスは失敗. */
		perror("_mbstowcs_l test1");
		_free_locale(loc1);	/* _free_localeでloc1を解放. */
		free(wstr1);	/* wstr1解放 */
		fclose(fp1);	/* fp1を閉じる. */
		return -2;
	}
	printf("wstr1 = %ls\n", wstr1);	/* printfでwstr1を出力. */
	 _free_locale(loc1);	/* _free_localeでloc1を解放. */
	free(wstr1);	/* wstr1解放 */
	fclose(fp1);	/* fp1を閉じる. */

	/* 正常終了 */
	return 0;	/* 0を返して正常終了. */

}