/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(int argc, char *argv[]){

  /* 変数の宣言 */
  int i; /* ループ用変数i. */
  /* CGI処理. */
  printf("Content-type: text/plain\n"); /* "Content-type: text/plain\n"を出力. */
  printf("\n"); /* printfで改行を出力. */
  printf("argc = %d\n", argc); /* argcを出力. */
  for (i = 0; i < argc; i++){ /* argcの数繰り返す. */
    printf("argv[%d] = %s\n", i, argv[i]); /* argv[i]を出力. */
  }

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
