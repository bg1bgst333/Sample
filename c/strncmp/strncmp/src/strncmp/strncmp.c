/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */

/* main関数の定義 */
int main(void){

  /* 配列の初期化 */
  char str1[] = "ABCXDEF"; /* str1を"ABCXDEF"で初期化. */
  char str2[] = "ABD"; /* str2を"ABD"で初期化. */
  char target[] = "ABCXDEG"; /* targetを"ABCXDEG"で初期化. */

  /* 'X'を'\0'にする. */
  str1[3] = '\0'; /* 3番目の文字'X'を'\0'にする. */
  target[3] = '\0'; /* 3番目の文字'X'を'\0'にする. */

  /* strncmp(str1, 3文字)の比較 */
  if (strncmp(str1, target, 3) == 0){ /* 一致 */
    printf("strncmp(str1, target, 3) is match!\n"); /* match */
  }

  /* strncmp(str2, 3文字)の比較 */
  if (strncmp(str2, target, 3) != 0){ /* 不一致 */
    printf("strncmp(str2, target, 3) is unmatch!\n"); /* unmatch */
  }

  /* strncmp(str1, 6文字)の比較 */
  if (strncmp(str1, target, 6) == 0){ /* 一致 */
    printf("strncpm(str1, target, 6) is match!\n"); /* match */
  }

  /* strncmp(str1, 7文字)の比較 */
  if (strncmp(str1, target, 7) == 0){ /* 一致 */
    printf("strncpm(str1, target, 7) is match!\n"); /* match */
  }

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
