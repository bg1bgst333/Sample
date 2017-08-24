/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <assert.h> /* アサーション */

/* main関数 */
int main(void){

  /* 変数の宣言 */
  int x; /* int型変数x */

  /* 入力フォーム */
  printf("x: "); /* xの入力フォームを出力. */
  scanf("%d", &x); /* scanfで入力された数値をxに格納. */

  /* xが負の値の場合は強制終了するアサーション. */
  assert(x >= 0); /* assertに"x >= 0"という条件式を渡す. */

  /* xの出力. */
  printf("x = %d\n", x); /* xを出力. */

  /* プログラムの終了. */
  return 0; /* 0を返して正常終了. */

}
