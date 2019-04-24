/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */

/* main関数の定義 */
int main(void){

  /* 配列の初期化 */
  char pattern[] = "ABCXDEF"; /* patternを"ABCXDEF"で初期化. */
  char target[] = "ABCXDEG"; /* targetを"ABCXDEG"で初期化. */

  /* 'X'を'\0'にする. */
  pattern[3] = '\0'; /* 3番目の文字'X'を'\0'にする. */
  target[3] = '\0'; /* 3番目の文字'X'を'\0'にする. */

  /* strcmpの比較 */
  if (strcmp(pattern, target) == 0){ /* 一致 */
    printf("strcmp(pattern, target) is match!\n"); /* "strcmp(pattern, target) is match!"と出力. */
  }

  /* memcmp(0文字目から3文字目まで)の比較 */
  if (memcmp(pattern, target, 4) == 0){ /* 一致 */
    printf("memcmp(pattern, target, 4) is match!\n"); /* "memcmp(pattern, target, 4) is match!"と出力. */
  }

  /* memcmp(0文字目から5文字目まで)の比較 */
  if (memcmp(pattern, target, 6) == 0){ /* 一致 */
    printf("memcmp(pattern, target, 6) is match!\n"); /* "memcmp(pattern, target, 6) is match!"と出力. */
  }

  /* memcmp(0文字目から6文字目まで)の比較 */
  if (memcmp(pattern, target, 7) == 0){ /* 一致 */
    printf("memcmp(pattern, target, 7) is match!\n"); /* "memcmp(pattern, target, 7) is match!"と出力. */
  }
  else{ /* 不一致 */
    printf("memcmp(pattern, target, 7) is unmatch!\n"); /* "memcmp(pattern, target, 7) is unmatch!"と出力. */
  }

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
