/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* 関数のプロトタイプ宣言 */
int factorial(int n); /* 渡された値を階乗した値を返す再帰処理関数factorial. */
 
/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  int x; /* int型変数x */
  int result; /* 結果を格納するint型変数result. */

  /* xの入力 */
  printf("x: "); /* printfでxの入力フォームを出力. */
  scanf("%d", &x); /* scanfでxに入力値を格納. */

  /* xの階乗を再帰処理で求める. */
  result = factorial(x); /* factorialにxを渡して, 結果をresultに格納. */

  /* 結果の出力 */
  printf("factorial(%d) = %d\n", x, result); /* printfでfactorial(x)の結果を出力. */

  /* プログラムの終了 */  
  return 0;

}

/* 階乗関数factorialの定義. */
int factorial(int n){

  /* 階乗の計算 */
  if (n > 0){ /* nが0より大きい時. */
    return n * factorial(n - 1); /* nとfactorial(n -1)を掛けたものを戻り値とする. */
  }
  else{ /* nが0の時. */
    return 1; /* 1を返す. */
  }

}
