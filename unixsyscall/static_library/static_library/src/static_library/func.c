/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include "static_1.h" /* 関数static_1 */
#include "static_2.h" /* 関数static_2 */
#include "func.h" /* 関数funcのプロトタイプ宣言 */

/* 関数funcの定義 */
void func(void){

  /* "func!"と出力. */
  printf("func!\n"); /* printfで"func!"と出力. */

  /* static_1を呼ぶ. */
  static_1(); /* スタティックライブラリ(libstatic.a)に定義されている関数static_1を呼ぶ. */

  /* static_2を呼ぶ. */
  static_2(); /* スタティックライブラリ(libstatic.a)に定義されている関数static_2を呼ぶ. */

}
