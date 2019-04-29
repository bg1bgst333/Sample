/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */

/* main関数の定義 */
int main(void){

  /* 初期化 */
  char target[] = "ABCXDEF"; /* targetを"ABCXDEF"で初期化. */
  char *p = NULL; /* みつかった位置のポインタpをNULLで初期化. */
  int d = 0; /* 距離dを0で初期化. */

  /* 'X'の部分に'\0'を代入. */
  target[3] = '\0'; /* target[3]に'\0'を代入する. */

  /* targetを出力. */
  printf("target = %s\n", target); /* targetを出力. */

  /* 文字'E'を探す. */
  p = memchr(target, 'E', 7); /* targetから7文字分探して, 'E'をみつける. */
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
