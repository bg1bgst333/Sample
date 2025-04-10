/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <math.h> /* 数学関数 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  double x; /* 入力された値を格納するdouble型変数x. */
  double result; /* 結果を表すdouble型変数result. */

  /* 値の入力 */
  printf("x: "); /* xの入力フォーム */
  scanf("%lf", &x); /* 入力値をxに格納. */

  /* ネイピア数eの指数関数eのx乗の値を計算. */
  result = exp(x); /* eのx乗の値をexpで求めて, 結果をresultに格納. */

  /* 結果の出力 */
  printf("exp(%lf) = %lf\n", x, result); /* 結果を出力. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
