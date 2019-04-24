/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */

/* main関数の定義 */
int main(void){

  /* 配列の宣言 */
  char str1[256]; /* char型配列str1 */

  /* str1に"ABCDE"をセット. */
  strncpy(str1, "ABCDE", 5); /* strncpyでstr1に"ABCDE"をセット. */

  /* str1の出力. */
  printf("str1 = %s\n", str1); /* str1を出力. */

  /* str1に"VWXYZ"を3文字分コピー.("VWX"がコピーされる.) */
  strncpy(str1, "VWXYZ", 3); /* strncpyでstr1に"VWXYZ"を3文字分コピー.("VWX"がコピーされる.) */

  /* str1の出力. */
  printf("str1 = %s\n", str1); /* str1を出力. */

  /* str1に"12"を10文字分コピー.("12"がコピーされる.) */
  strncpy(str1, "12", 10); /* strncpyでstr1に"12"を10文字分コピー.("12"がコピーされる.) */

  /* str1の出力. */
  printf("str1 = %s\n", str1); /* str1を出力. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
