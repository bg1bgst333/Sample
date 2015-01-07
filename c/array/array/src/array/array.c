/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  int n; /* int型変数n */
  int array[10]; /* int型配列array(要素数10) */

  /* 配列の各要素に値を代入. */
  for (n = 0; n < 10; n++){ /* nが10未満の間, 繰り返す. */
    array[n] = 2 * n + 1; /* arrayの各要素に, 要素番号の2倍 + 1の値を代入. */
  }

  /* 各要素の値を出力. */
  for (n = 0; n < 10; n++){ /* nが10未満の間, 繰り返す. */
    printf("array[%d] = %d\n", n, array[n]); /* printfでarrayの各要素の値を出力. */
  }

  /* プログラムの終了 */
  return 0;

}
