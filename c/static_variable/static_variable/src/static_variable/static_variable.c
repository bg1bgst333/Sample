/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* 関数のプロトタイプ宣言 */
void static_variable_func(void); /* static変数を中で使っている関数static_variable_funのプロトタイプ宣言. */

/* main関数の定義 */
int main(void){

  /* static変数を中で使っている関数を呼ぶ.(1回目) */
  static_variable_func(); /* static_variable_funcを呼ぶ. */

  /* static変数を中で使っている関数を呼ぶ.(2回目) */
  static_variable_func(); /* static_variable_funcを呼ぶ. */

  /* static変数を中で使っている関数を呼ぶ.(3回目) */
  static_variable_func(); /* static_variable_funcを呼ぶ. */

  /* プログラムの終了 */
  return 0;

}

/* static_variable_funcの定義 */
void static_variable_func(void){ /* 中でstatic変数にアクセス. */

  /* 変数の宣言・初期化 */
  static int a; /* staticなint型変数a. */
  static int b = 10; /* staticなint型変数bを10に初期化. */
  int x = 0; /* staticではないint型変数xを0に初期化. */

  /* static変数の値を出力. */
  printf("a = %d\n", a); /* aの値を出力. */
  printf("b = %d\n", b); /* bの値を出力. */
  printf("x = %d\n", x); /* xの値を出力. */

  /* static変数の値を変更. */
  a = a + 10; /* aの値を10増やす. */
  b = b + 10; /* bの値を10増やす. */
  x = x + 10; /* xの値を10増やす. */

}
