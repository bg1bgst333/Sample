/* ヘッダファイルのインクルード */
#include <stdio.h>	/* 標準入出力 */
#include <locale.h>	/* ロケール */

/* main関数の定義 */
int main(void){

	/* 変数・配列の宣言・初期化 */
	char *loc;
	_locale_t loc1;
	_locale_t loc2;

	/* "Japanese_Japan.932"指定 */
	loc = setlocale(LC_ALL, "Japanese_Japan.932");	/* setlocaleにLC_ALL, "Japanese_Japan.932"を指定. */
	printf("loc = %s\n", loc);	/* locを出力. */

	/* "Japanese_Japan.932"(Shift_JIS)ロケールloc1の生成. */
	loc1 = _create_locale(LC_ALL, "Japanese_Japan.932");	/* _create_localeで"Japanese_Japan.932"(Shift_JIS)なロケールloc1を作成. */

	/* loc1で標準出力. */
	_printf_l("%s", loc1, "あいうえお\n");	/* _printf_lでloc1で"あいうえお"を出力. */

	/* loc1の解放. */
	_free_locale(loc1);	/* _free_localeでloc1を解放. */

	/* "Japanese_Japan.20932"(EUC-JP)ロケールloc2の生成. */
	loc2 = _create_locale(LC_ALL, "Japanese_Japan.20932");	/* _create_localeで"Japanese_Japan.20932"(EUC-JP)なロケールloc2を作成. */

	/* loc2で標準出力. */
	_printf_l("%s", loc2, "あいうえお\n");	/* _printf_lでloc2で"あいうえお"を出力. */

	/* loc2の解放. */
	_free_locale(loc2);	/* _free_localeでloc2を解放. */

	/* 正常終了 */
	return 0;	/* 0を返して正常終了. */

}