/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */

/* main関数の定義 */
int main(void){

  /* 配列の宣言 */
  char str1[] = "ABCDE"; /* コピー元char型配列str1は"ABCDE"に初期化. */
  char str2[256]; /* コピー先char型配列str2. */

  /* str2は空文字列("")にする. */
  str2[0] = '\0'; /* str2の先頭にNULL文字を入れることで空文字列("")にする. */

  /* str1, str2の出力.(strcpy前) */
  printf("str1: %s\n", str1); /* str1を出力.("ABCDE") */
  printf("str2: %s\n", str2); /* str2を出力.("") */

  /* 1行空ける. */
  printf("\n"); /* printfで"\n"を出力することで1行空ける. */

  /* str1の文字列をstr2にコピー. */
  strcpy(str2, str1); /* strcpyでstr1の文字列をstr2にコピー. */

  /* str1, str2の出力.(strcpy後) */
  printf("str1: %s\n", str1); /* str1を出力.("ABCDE") */
  printf("str2: %s\n", str2); /* str2を出力.(コピーされたので"ABCDE") */

  /* プログラムの終了 */
  return 0;

}
