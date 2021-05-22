/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <ctype.h> /* 文字操作 */

/* main関数の定義 */
int main(void){

  /* 変数の初期化 */
  char c = NULL; /* char型変数cをNULLで初期化. */

  /* 文字の取得 */
  c = (char)getchar(); /* getcharで文字を取得して, cに格納.(charにキャスト.) */

  /* 句読点文字かどうか判定. */
  if (ispunct(c)){ /* ispunctでcが句読点文字なら. */
    printf("%02x is Punctuation Character!\n", c); /* 句読点文字であることを出力. */
  }

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
