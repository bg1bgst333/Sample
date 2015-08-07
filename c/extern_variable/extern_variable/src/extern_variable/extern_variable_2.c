/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* 関数のプロトタイプ宣言 */
void func1(void); /* 別のモジュール(extern_variable_1.c)で定義している関数func1 */
void func2(void); /* このモジュール(extern_variable_2.c)で定義している関数func2 */

/* グローバル変数の宣言 */
int global_variable_2; /* グローバル変数global_variable_2 */

/* extern変数の宣言 */
extern int global_variable_1; /* 別のモジュール(extern_variable_1.c)で定義しているglobal_variable_1の参照を宣言. */

/* func2の定義 */
void func2(void){

  /* func2からglobal_variable_1の値を出力. */
  printf("global_variable_1(in func2) = %d\n", global_variable_1); /* global_variable_1の値を出力. */

  /* global_variable_1に値を代入. */
  global_variable_1 = 20; /* global_variable_1に20を代入. */

  /* global_variable_2に値を代入. */
  global_variable_2 = 100; /* global_variable_2に100を代入. */

}
