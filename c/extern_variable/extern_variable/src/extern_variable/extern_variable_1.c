/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* 関数のプロトタイプ宣言 */
void func1(void); /* このモジュール(extern_variable_1.c)で定義している関数func1 */
void func2(void); /* 別のモジュール(extern_variable_2.c)で定義している関数func2 */

/* グローバル変数の宣言 */
int global_variable_1; /* グローバル変数global_variable_1 */

/* extern変数の宣言 */
extern int global_variable_2; /* 別のモジュール(extern_variable_2.c)で定義しているglobal_variable_2の参照を宣言. */

/* main関数の定義 */
int main(void){

  /* このモジュールのグローバル変数に値を代入. */
  global_variable_1 = 10; /* global_variable_1に10を代入. */
  global_variable_2 = 0; /*  global_variable_2に0を代入. */

  /* 別のモジュールの関数を呼ぶ. */
  func2(); /* 別のモジュール(extern_variable_2.c)の関数func2を呼ぶ. */

  /* このモジュールの関数を呼ぶ. */
  func1(); /* このモジュール(extern_variable_1.c)の関数func1を呼ぶ. */

  /* 値を出力 */
  printf("global_variable_1 = %d\n", global_variable_1); /* global_variable_1の値を出力. */
  printf("global_variable_2 = %d\n", global_variable_2); /* global_variable_2の値を出力. */

  /* プログラムの終了 */
  return 0;

}

/* func1の定義 */
void func1(void){

  /* func1からglobal_variable_2の値を出力. */
  printf("global_variable_2(in func1) = %d\n", global_variable_2); /* global_variable_2の値を出力. */

  /* global_variable_2に値を代入. */
  global_variable_2 = 200; /* global_varialbe_2に200を代入. */

  /* global_variable_1に値を代入. */
  global_variable_1 = 30; /* global_variable_2に30を代入. */

}
