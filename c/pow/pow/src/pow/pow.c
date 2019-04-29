/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <math.h> /* 数学関数 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  double a; /* 基数を表すdouble型変数a. */
  double x; /* 指数を表すdouble型変数x. */
  double result; /* 結果を表すdouble型変数result. */

  /* 値の入力 */
  printf("a: "); /* aの入力フォーム. */
  scanf("%lf", &a); /* 入力値をaに格納. */
  printf("x: "); /* xの入力フォーム. */
  scanf("%lf", &x); /* 入力値をxに格納. */

  /* 冪乗の計算 */
  result = pow(a, x); /* powでaのx乗を求め, 結果をresultに格納する. */

  /* 結果の出力 */
  printf("pow(%lf, %lf) = %lf\n", a, x, result); /* 結果を出力. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
