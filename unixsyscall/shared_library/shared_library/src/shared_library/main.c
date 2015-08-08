/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include "func.h" /* 関数func */

/* main関数の定義 */
int main(void){

  /* funcを呼ぶ. */
  func(); /* 別のモジュール(func.c)に定義されている関数funcを呼ぶ. */

  /* プログラムの終了 */
  return 0;

}
