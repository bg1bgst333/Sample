/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <stdlib.h> /* 標準ユーティリティ */

/* main関数 */
int main(void){

  /* 変数・配列の宣言 */
  char str[16]; /* 数値文字列を格納するchar型配列str(長さ16) */
  int i; /* int型変数i */

  /* 入力フォーム */
  printf("str: "); /* strの入力フォームを出力. */
  scanf("%s", str); /* scanfで入力された文字列をstrに格納. */

  /* atoiで数値文字列strを整数値iに変換. */
  i = atoi(str); /* atoiにstrを渡すことで, iに変換された整数値が返る. */

  /* iの出力. */
  printf("i = %d\n", i); /* iを出力. */

  /* プログラムの終了. */
  return 0; /* 0を返して正常終了. */

}
