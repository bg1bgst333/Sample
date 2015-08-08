/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include "shared.h" /* 関数shared */
#include "func.h" /* 関数funcのプロトタイプ宣言 */

/* 関数funcの定義 */
void func(void){

  /* "func!"と出力. */
  printf("func!\n"); /* printfで"func!"と出力. */

  /* sharedを呼ぶ. */
  shared(); /* シェアードライブラリ(libshared.so)に定義されている関数sharedを呼ぶ. */

}
