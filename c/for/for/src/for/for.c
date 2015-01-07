/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言・初期化 */
  int n; /* int型変数n */
  int m; /* int型変数m */
  int x = 0; /* int型変数xの値を0に初期化. */
  int i; /* ループ用int型変数i */

  /* n, mの入力 */
  printf("n( <= m): "); /* nの入力フォーム */
  scanf("%d", &n); /* 最初の数値をnに格納. */
  printf("m( >= n): "); /* mの入力フォーム */
  scanf("%d", &m); /* 最後の数値をmに格納. */

  /* nからmまでの和を求める(for文). */
  for (i = n; i <= m; i++){ /* iの初期値をnとし, iがm以下の間は以下のブロックを実行, 1回終わるたびにiを1増やす. */
    x = x + i; /* xにiを足す. */
  }

  /* nからmまでの和xを出力. */
  printf("sum(n, ..., m) = %d\n", x); /* printfでxを出力. */

  /* プログラムの終了 */
  return 0;

}
