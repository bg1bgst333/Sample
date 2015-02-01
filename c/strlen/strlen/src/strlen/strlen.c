/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */

/* main関数の定義 */
int main(void){

  /* 変数・配列の宣言 */
  int len; /* 入力された文字列の長さ(バイトサイズ)を格納するint型変数len. */
  char str[256]; /* 入力された文字列を格納するchar型配列str. */

  /* 文字列の入力 */
  printf("str: "); /* strの入力フォーム */
  scanf("%s", str); /* 入力された文字列をstrに格納. */

  /* 文字列の長さ(バイトサイズ)を取得. */
  len = strlen(str); /* strlenでstrの長さを取得し, lenに格納. */

  /* 入力された文字列とその長さを出力. */
  printf("str = %s\n", str); /* printfでstrを出力. */
  printf("len = %d\n", len); /* printfでstrの長さlenを出力. */

  /* プログラムの終了 */
  return 0;

}
