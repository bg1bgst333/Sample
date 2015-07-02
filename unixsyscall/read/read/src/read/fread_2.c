/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  FILE *fp; /* ファイルポインタfp */
  int i; /* ループ用変数i */
  char buf[819200]; /* サイズ819200のchar型配列バッファbuf. */

  /* 高水準入出力関数で使われるバッファサイズを出力 */
  printf("BUFSIZ = %d\n", BUFSIZ); /* printfでBUFSIZの値を出力. */

  /* ファイルtest_2.txtを開く. */
  fp = fopen("test_2.txt", "rb"); /* fopenで"test_2.txt"を"rb"で開く. */
  if (fp == NULL){ /* NULLの時はエラー. */

    /* エラー処理 */
    printf("fopen error!\n"); /* "fopen error!"と出力. */
    return -1; /* -1を返す. */

  }

  /* 読込開始 */
  printf("fread start\n"); /* "fread start"と出力. */

  /* 819200バイト一気に読み込む. */
  fread(buf, 819200, 1, fp); /* freadで819200バイト一気にbufに読み込む.(純粋にfreadだけ呼びたいので出力とかはしない.) */

  /* 読込終了 */
  printf("fread end\n"); /* "fread end"と出力. */

  /* 閉じる */
  fclose(fp); /* fcloseでfpを閉じる. */

  /* プログラムの終了 */
  return 0;

}
