/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* 関数のプロトタイプ宣言 */
void global_variable_access_func(void); /* グローバル変数にアクセスする関数global_variable_access_funcのプロトタイプ宣言. */

/* グローバル変数の宣言 */
int global_variable; /* このモジュール内ならどこでもアクセス可能なint型グローバル変数global_variableの宣言. */

/* main関数の定義 */
int main(void){

  /* main関数からグローバル変数に代入. */
  global_variable = 10; /* global_variableに10を代入. */

  /* グローバル変数の値を出力. */
  printf("global_variable = %d\n", global_variable); /* printfでglobal_variableの値を出力. */

  /* 別の関数からグローバル変数にアクセス. */
  global_variable_access_func(); /* global_variable_access_funcを呼ぶ. */

  /* 最終的なグローバル変数の値を出力. */
  printf("global_variable = %d\n", global_variable); /* printfでglobal_variableの値を出力. */

  /* プログラムの終了 */
  return 0;

}

/* global_variable_access_funcの定義 */
void global_variable_access_func(void){ /* グローバル変数にアクセス. */

  /* ここからグローバル変数の値を参照して, それを出力. */
  printf("global_variable(in global_variable_access_func) = %d\n", global_variable); /* printfでglobal_variableの値を出力. */

  /* ここからグローバル変数に値を代入. */
  global_variable = 20; /* global_variableに20を代入. */

}
