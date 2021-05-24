/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <stdlib.h> /* 標準ユーティリティ */

/* main関数 */
int main(void){

  /* 変数・配列の宣言 */
  char str[16]; /* 数値文字列を格納するchar型配列str(長さ16) */
  long l_0; /* long型変数l_0(0が基数.) */
  long l_2; /* long型変数l_2(2が基数.) */
  long l_8; /* long型変数l_8(8が基数.) */
  long l_10; /* long型変数l_10(10が基数.) */
  long l_16; /* long型変数l_16(16が基数.) */

  /* 入力フォーム */
  printf("str: "); /* strの入力フォームを出力. */
  scanf("%s", str); /* scanfで入力された文字列をstrに格納. */

  /* strtolで数値文字列strを指定の整数を基数とする整数値l_*に変換. */
  l_0 = strtol(str, NULL, 0); /* 0を基数として変換.(この場合基数は自動検出.) */
  l_2 = strtol(str, NULL, 2); /* 2を基数として変換.(基数2.) */
  l_8 = strtol(str, NULL, 8); /* 8を基数として変換.(基数8.) */
  l_10 = strtol(str, NULL, 10); /* 10を基数として変換.(基数10.) */
  l_16 = strtol(str, NULL, 16); /* 16を基数として変換.(基数16.) */

  /* l_*の出力. */
  printf("l_0 = %d\n", l_0); /* l_0を出力. */
  printf("l_2 = %d\n", l_2); /* l_2を出力. */
  printf("l_8 = %d\n", l_8); /* l_8を出力. */
  printf("l_10 = %d\n", l_10); /* l_10を出力. */
  printf("l_16 = %d\n", l_16); /* l_16を出力. */

  /* プログラムの終了. */
  return 0; /* 0を返して正常終了. */

}
