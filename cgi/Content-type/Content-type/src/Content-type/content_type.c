/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* CGIとして文字列の出力. */
  printf("Content-type: text/plain\n"); /* "Content-type: text/plain\n"を出力. */
  printf("\n"); /* printfで改行を出力. */
  printf("ABCDE"); /* printfで"ABCDE"(改行無し)の出力. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
