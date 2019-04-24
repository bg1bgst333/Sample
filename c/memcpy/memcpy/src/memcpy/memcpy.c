/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */

/* main関数の定義 */
int main(void){

  /* 配列の宣言 */
  char buf1[32]; /* char型配列buf1(長さ32) */
  char buf2[32]; /* char型配列buf2(長さ32) */

  /* すべて'A'で埋める. */
  memset(buf1, 'A', 32); /* memsetでbuf1を'A'で埋める. */
  memset(buf2, 'A', 32); /* memsetでbuf2を'A'で埋める. */

  /* バッファの出力 */
  printf("buf1 = %s\n", buf1); /* printfでbuf1の内容を出力. */
  printf("buf2 = %s\n", buf2); /* printfでbuf2の内容を出力. */

  /* strcpyでコピー. */
  strcpy(buf1, "ABC"); /* strcpyでbuf1の先頭に"ABC"をコピー. */

  /* memcpyでコピー. */
  memcpy(buf2, "ABC", 3); /* memcpyでbuf2の先頭に"ABC"の3文字をコピー. */

  /* バッファの出力 */
  printf("buf1 = %s\n", buf1); /* printfでbuf1の内容を出力. */
  printf("buf2 = %s\n", buf2); /* printfでbuf2の内容を出力. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
