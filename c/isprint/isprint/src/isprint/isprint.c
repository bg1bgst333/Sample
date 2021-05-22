/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <ctype.h> /* 文字操作 */

/* main関数の定義 */
int main(void){

  /* 変数の初期化 */
  char c = NULL; /* char型変数cをNULLで初期化. */

  /* 文字の取得 */
  c = (char)getchar(); /* getcharで文字を取得して, cに格納.(charにキャスト.) */

  /* 表示文字(スペースを含む)かどうか判定. */
  if (isprint(c)){ /* isprintでcが表示文字(スペースを含む)なら. */
    printf("%02x is Printable Character!\n", c); /* 表示文字(スペースを含む)であることを出力. */
  }

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
