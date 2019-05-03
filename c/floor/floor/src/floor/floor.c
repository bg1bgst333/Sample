/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <math.h> /* 数学関数 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  double x; /* 入力された値を格納するdouble型変数x. */
  double f; /* xを超えない最大の整数値を格納するdouble型変数f. */

  /* 値の入力 */
  printf("x: "); /* xの入力フォーム. */
  scanf("%lf", &x); /* 入力値をxに格納. */

  /* 実数xに対して, xを超えない最大の整数を求める. */
  f = floor(x); /* floorでxの小数点以下を切り捨て, fに格納. */

  /* fの出力 */
  printf("f = %lf\n", f); /* printfでfを出力. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}  
