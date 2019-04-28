/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */

/* main関数の定義 */
int main(void){

  /* 初期化 */
  char target[] = "ABCDE"; /* targetを"ABCDE"で初期化. */
  char *p = NULL; /* みつかった位置のポインタpをNULLで初期化. */
  int d = 0; /* 距離dを0で初期化. */

  /* 文字'D'を探す. */
  p = strchr(target, 'D'); /* strchrでtargetから'D'を探す. */
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
