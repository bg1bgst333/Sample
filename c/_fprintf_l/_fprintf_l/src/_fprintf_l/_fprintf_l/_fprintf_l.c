/* ヘッダファイルのインクルード */
#include <stdio.h>	/* 標準入出力 */
#include <locale.h>	/* ロケール */

/* main関数の定義 */
int main(void){

	/* 変数・配列の宣言・初期化 */
	_locale_t loc1;
	_locale_t loc2;
	FILE *fp1 = NULL;
	FILE *fp2 = NULL;

	/* "Japanese_Japan.932"(Shift_JIS)ロケールloc1の生成. */
	loc1 = _create_locale(LC_ALL, "Japanese_Japan.932");	/* _create_localeで"Japanese_Japan.932"(Shift_JIS)なロケールloc1を作成. */

	/* loc1でファイル出力. */
	fp1 = fopen("test1.txt", "w");	/* "test1.txt"を開く. */
	if (fp1 == NULL){	/* 失敗 */
		perror("test1");
		_free_locale(loc1);	/* _free_localeでloc1を解放. */
		return -1;
	}
	_fprintf_l(fp1, "%s", loc1, "あいうえお");	/* _fprintf_lでloc1で"あいうえお"を出力. */
	fclose(fp1);	/* 閉じる */
	_free_locale(loc1);	/* _free_localeでloc1を解放. */

	/* "Japanese_Japan.20932"(EUC-JP)ロケールloc2の生成. */
	loc2 = _create_locale(LC_ALL, "Japanese_Japan.20932");	/* _create_localeで"Japanese_Japan.20932"(EUC-JP)なロケールloc2を作成. */

	/* loc2でファイル出力. */
	fp2 = fopen("test2.txt", "w");	/* "test2.txt"を開く. */
	if (fp2 == NULL){	/* 失敗 */
		perror("test2");
		_free_locale(loc2);	/* _free_localeでloc2を解放. */
		return -2;
	}
	_fprintf_l(fp2, "%s", loc2, "あいうえお");	/* _fprintf_lでloc2で"あいうえお"を出力. */
	fclose(fp2);	/* 閉じる */
	_free_locale(loc2);	/* _free_localeでloc2を解放. */

	/* 正常終了 */
	return 0;	/* 0を返して正常終了. */

}