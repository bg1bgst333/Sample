/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(int argc, char *argv[]){

  /* CGI処理. */
  printf("Content-type: text/plain\n"); /* "Content-type: text/plain\n"を出力. */
  printf("\n"); /* printfで改行を出力. */
  printf("argc = %d\n", argc); /* argcを出力. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
