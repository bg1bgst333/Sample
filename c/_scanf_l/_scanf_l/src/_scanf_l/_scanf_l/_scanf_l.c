/* ヘッダファイルのインクルード */
#include <stdio.h>	/* 標準入出力 */
#include <locale.h>	/* ロケール */

/* main関数の定義 */
int main(void){

	/* 変数・配列の宣言・初期化 */
	char *loc;
	_locale_t loc1;
	_locale_t loc2;
	char buf1[128];
	char buf2[128];

	/* "Japanese_Japan.932"指定 */
	loc = setlocale(LC_ALL, "Japanese_Japan.932");	/* setlocaleにLC_ALL, "Japanese_Japan.932"を指定. */
	printf("loc = %s\n", loc);	/* locを出力. */

	/* "Japanese_Japan.932"(Shift_JIS)ロケールloc1の生成. */
	loc1 = _create_locale(LC_ALL, "Japanese_Japan.932");	/* _create_localeで"Japanese_Japan.932"(Shift_JIS)なロケールloc1を作成. */

	/* loc1で標準入力. */
	_scanf_l("%s", loc1, buf1);	/* _scanf_lでloc1で入力文字列をbuf1に格納. */

	/* buf1を標準出力. */
	printf("buf1 = %s\n", buf1);	/* printfでbuf1を出力. */

	/* loc1の解放. */
	_free_locale(loc1);	/* _free_localeでloc1を解放. */

	/* いったんバッファをフラッシュ. */
	fflush(stdin);	/* fflushでstdinをフラッシュ. */

	/* "Japanese_Japan.20932"(EUC-JP)ロケールloc2の生成. */
	loc2 = _create_locale(LC_ALL, "Japanese_Japan.20932");	/* _create_localeで"Japanese_Japan.20932"(EUC-JP)なロケールloc2を作成. */

	/* loc2で標準入力. */
	_scanf_l("%s", loc2, buf2);	/* _scanf_lでloc2で入力文字列をbuf2に格納. */

	/* buf2を標準出力. */
	printf("buf2 = %s\n", buf2);	/* printfでbuf2を出力. */

	/* loc2の解放. */
	_free_locale(loc2);	/* _free_localeでloc2を解放. */

	/* 正常終了 */
	return 0;	/* 0を返して正常終了. */

}