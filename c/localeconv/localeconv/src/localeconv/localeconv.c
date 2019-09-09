/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <locale.h> /* ロケール */

/* main関数 */
int main(void){

  /* 構造体の宣言 */
  struct lconv *lc; /* lconv構造体へのポインタlc. */

  /* ロケール情報の取得 */
  lc = localeconv(); /* localeconvで取得したロケール情報へのポインタをlcに格納. */

  /* 数値形式における小数点文字(decimal_point)や整数部セパレータ(thousands_sep, 3桁ごとに区切る記号.)を出力. */
  printf("lc->decimal_point = %s\n", lc->decimal_point); /* lc->decimal_pointを出力. */
  printf("lc->thousands_sep = %s\n", lc->thousands_sep); /* lc->thousands_sepを出力. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
