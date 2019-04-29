/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */

/* main関数の定義 */
int main(void){

  /* 初期化 */
  char target[] = "ABABABDABCDABABDDAABDAC"; /* targetを"ABABABDABCDABABDDAABDAC"で初期化. */
  char *p = NULL; /* みつけた場所のアドレスpをNULLで初期化. */
  int d = 0; /* 距離dを0で初期化. */

  /* 文字列の検索. */
  p = strstr(target, "ABC"); /* strstrでtargetから"ABC"を探す. */
  if (p == NULL){ /* みつからなかった. */
    printf("Not found!\n"); /* "Not found!"と出力. */
  }
  else{ /* みつかった. */
    printf("p = %s\n", p); /* pを出力. */
    d = p - target; /* pからtargetを引くと, ポインタ演算で距離がわかる. */
    printf("d = %d\n", d); /* dを出力. */
  }

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
