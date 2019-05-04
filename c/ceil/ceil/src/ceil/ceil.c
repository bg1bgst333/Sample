/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <math.h> /* 数学関数 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  double x; /* 入力された値を格納するdouble型変数x. */
  double c; /* xより小さくない最小の整数値を格納するdouble型変数c. */

  /* 値の入力 */
  printf("x: "); /* xの入力フォーム. */
  scanf("%lf", &x); /* 入力値をxに格納. */

  /* 実数xに対して, xより小さくない最小の整数を求める. */
  c = ceil(x); /* ceilでxの小数点以下を切り上げ, cに格納. */

  /* cの出力 */
  printf("c = %lf\n", c); /* printfでcを出力. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
