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

  /* 10を底とする対数関数logxの値を計算. */
  result = log10(x); /* 10を底とするlogxの値をlog10で求めて, 結果をresultに格納. */

  /* 結果の出力 */
  printf("log10(%lf) = %lf\n", x, result); /* 結果を出力. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
