/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数 */
int main(void){

  /* 変数の宣言 */
  FILE *fp; /* ファイルポインタfp */
  int fileno_fp; /* int型fileno_fp. */

  /* stdin, stdout, stderrのファイルディスクリプタの値を出力. */
  printf("fileno stdin = %d\n", fileno(stdin)); /* fileno(stdin)の値を出力.(このように直接出力しないとなぜかprintfで出力されない.) */
  printf("fileno stdout = %d\n", fileno(stdout)); /* fileno(stdout)の値を出力.(こちらも直接出力.) */
  printf("fileno stderr = %d\n", fileno(stderr)); /* fileno(stderr)の値を出力.(こちらも直接出力.) */

  /* test.txtを開く. */
  fp = fopen("test.txt", "r"); /* fopenで"test.txt"を開いて, fpを取得. */
  if (fp == NULL){ /* NULLなら. */
    perror("fopen error!"); /* perrorで"fopen error!"とエラー出力. */
    return -1; /* -1を返して異常終了. */
  }

  /* fpのファイルディスクリプタの値を取得. */
  fileno_fp = fileno(fp); /* filenoにfpを渡すと, fileno_fpにファイルディスクリプタの値が返る. */
  printf("fileno fp = %d\n", fileno_fp); /* fileno_fpを出力. */

  /* test.txtを閉じる. */
  fclose(fp); /* fcloseでfpを閉じる. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
