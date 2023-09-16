/* ヘッダファイルのインクルード */
#include <stdio.h>	/* 標準入出力 */
#include <stdlib.h>	/* 標準ユーティリティ */
#include <locale.h>	/* ロケール */

/* main関数の定義 */
int main(void){

	/* 変数・配列の宣言・初期化 */
	_locale_t loc1;
	const wchar_t wc = L'あ';
	int len1 = 0;
	char mb1[MB_LEN_MAX + 1] = {0};
	FILE *fp1 = NULL;

	/* "Japanese_Japan.20932"(EUC-JP)ロケールloc1の生成. */
	loc1 = _create_locale(LC_ALL, "Japanese_Japan.20932");	/* _create_localeで"Japanese_Japan.20932"なロケールloc1を作成. */

	/* ワイド文字からマルチバイト文字へ変換. */
	len1 = _wctomb_l(mb1, wc, loc1);	/* _wctomb_lでワイド文字からloc1ロケールなマルチバイト文字へ変換. */
	printf("len1 = %d\n", len1);	/* len1を出力. */

	/* バイナリファイル出力 */
	fp1 = fopen("test1.txt", "wb");	/* "test1.txt"を開く. */
	if (fp1 == NULL){	/* 失敗 */
		perror("test1");
		_free_locale(loc1);	/* _free_localeでloc1を解放. */
		return -1;
	}
	fwrite(mb1, sizeof(char), len1, fp1);	/* fwriteでmb1を書き込む. */
	fclose(fp1);	/* 閉じる */

	/* loc1の解放. */
	_free_locale(loc1);	/* _free_localeでloc1を解放. */

	/* 正常終了 */
	return 0;	/* 0を返して正常終了. */

}