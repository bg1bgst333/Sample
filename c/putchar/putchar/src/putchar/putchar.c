/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  char c; /* char型変数c */

  /* 文字リテラルの出力 */
  putchar('A'); /* putcharで文字リテラル'A'を出力. */

  /* 改行の出力 */
  putchar('\n'); /* putcharで改行文字'\n'を出力. */

  /* 数値リテラルを指定して文字を出力. */
  putchar(65); /* putcharで数値リテラル65を指定すると'A'が出力される. */

  /* 改行の出力 */
  putchar('\n'); /* putcharで改行文字'\n'を出力. */

  /* char型変数に文字を代入. */
  c = 'A'; /* cに文字'A'を代入. */

  /* 変数の内容を出力. */
  putchar(c); /* putcharでcを出力. */

  /* 改行の出力 */
  putchar('\n'); /* putcharで改行文字'\n'を出力. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
