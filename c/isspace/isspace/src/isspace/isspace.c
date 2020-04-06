/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <ctype.h> /* 文字操作 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  int c; /* int型変数c. */

  /* 1文字読み込む. */
  c = getchar(); /* getcharで読み込んだ文字c. */
  if (isspace(c)){ /* isspaceで標準空白類文字かチェック. */
    printf("c = 0x%02x, Standard White Space Characters!\n", c); /* cの値と"Standard White Space Characters!"と出力. */
  }
  else{ /* 標準空白類文字ではない. */
    printf("c = 0x%02x, Not Standard White Space Characters!\n", c); /* cの値と"Not Standard White Space Characters!"と出力. */
  }

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
