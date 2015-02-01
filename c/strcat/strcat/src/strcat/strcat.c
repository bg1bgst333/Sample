/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */

/* main関数の定義 */
int main(void){

  /* 配列の宣言 */
  char str1[256]; /* 連結元char型配列str1(長さ256) */
  char str2[512]; /* 連結先char型配列str2(長さ512) */

  /* str1に文字列をセット. */
  strcpy(str1, "XYZ"); /* strcpyでstr1に"XYZ"をコピー. */

  /* str2に文字列をセット. */
  strcpy(str2, "ABC"); /* strcpyでstr2に"ABC"をコピー. */

  /* str1, str2の出力.(strcat前) */
  printf("str1: %s\n", str1); /* str1("XYZ")の出力. */
  printf("str2: %s\n", str2); /* str2("ABC")の出力. */

  /* 1行空ける. */
  printf("\n"); /* "\n"で1行空ける. */

  /* str2にstr1を連結. */
  strcat(str2, str1); /* strcatでstr2の文字列にstr1の文字列を連結. */

  /* str1, str2の出力.(strcat後) */
  printf("str1: %s\n", str1); /* str1("XYZ")の出力. */
  printf("str2: %s\n", str2); /* str2("ABCXYZ")の出力. */

  /* プログラムの終了 */
  return 0;

}
