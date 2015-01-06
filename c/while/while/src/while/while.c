/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言・初期化 */
  int n; /* int型変数n */
  int m; /* int型変数m */
  int x = 0; /* int型変数xの値を0に初期化. */

  /* n, mの入力 */
  printf("n( <= m): "); /* nの入力フォーム */
  scanf("%d", &n); /* 最初の数値をnに格納. */
  printf("m( >= n): "); /* mの入力フォーム */
  scanf("%d", &m); /* 最後の数値をmに格納. */

  /* nからmまでの和を求める. */
  while (n <= m){ /* nがmと等しくなるまで繰り返す. */
    x = x + n; /* xにnを足す. */
    n = n + 1; /* nを1増やす. */
  }

  /* nからmまでの和xを出力. */
  printf("sum(n, ..., m) = %d\n", x); /* printfでxを出力. */

  /* プログラムの終了 */
  return 0;

}
