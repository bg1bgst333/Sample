/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  int ic; /* int型変数ic */
  char cc; /* char型変数cc */

  /* 入力フォームの出力 */
  printf("ic: "); /* "ic: "を出力. */

  /* 入力文字の取得 */
  ic = getchar(); /* getcharが返す値をicに代入. */

  /* 整数型を文字型に変換. */
  cc = (char)ic; /* icをcharにキャストしてccに代入. */

  /* 整数として出力. */
  printf("ic = %d\n", ic); /* printfでicを出力. */

  /* 文字として出力. */
  printf("cc = %c\n", cc); /* printfでccを出力. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
