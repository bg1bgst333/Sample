/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数 */
int main(void){

  /* 配列の宣言 */
  char buf[256]; /* char型buf(長さ256) */

  /* 文字列の入力 */
  scanf("%s", buf); /* 入力文字列をbufに格納. */

  /* bufの出力 */
  printf("buf = %s\n", buf); /* printfでbufの出力. */

  /* プログラムの終了 */
  return 0; /* 正常終了 */

}
