/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */

/* main関数の定義 */
int main(void){

  /* 配列の宣言 */
  char buf1[32]; /* char型配列buf1(長さ32) */
  char buf2[32]; /* char型配列buf2(長さ32) */

  /* バッファのクリア */
  memset(buf1, '\0', 32); /* memsetでbuf1のすべての要素に'\0'をセット. */
  memset(buf2, '\0', 32); /* memsetでbuf2のすべての要素に'\0'をセット. */

  /* バッファの出力 */
  printf("buf1 = %s\n", buf1); /* printfでbuf1の内容を出力. */
  printf("buf2 = %s\n", buf2); /* printfでbuf2の内容を出力. */

  /* buf1に"ABCDE"をコピー. */
  strcpy(buf1, "ABCDE"); /* strcpyでbuf1に"ABCDE"をコピー. */

  /* buf2の先頭から5文字目までの要素に文字'A'をセット. */
  memset(buf2, 'A', 5); /* memsetでbuf2の先頭から5文字目まで'A'をセット. */

  /* バッファの出力 */
  printf("buf1 = %s\n", buf1); /* printfでbuf1の内容を出力. */
  printf("buf2 = %s\n", buf2); /* printfでbuf2の内容を出力. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
