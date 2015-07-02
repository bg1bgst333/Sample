/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  FILE *fp; /* ファイルポインタfp */
  int i; /* ループ用変数i */
  char buf[4]; /* サイズ4のchar型配列バッファbuf. */

  /* 高水準入出力関数で使われるバッファサイズを出力 */
  printf("BUFSIZ = %d\n", BUFSIZ); /* printfでBUFSIZの値を出力. */

  /* ファイルtest_1.txtを開く. */
  fp = fopen("test_1.txt", "rb"); /* fopenで"test_1.txt"を"rb"で開く. */
  if (fp == NULL){ /* NULLの時はエラー. */

    /* エラー処理 */
    printf("fopen error!\n"); /* "fopen error!"と出力. */
    return -1; /* -1を返す. */

  }

  /* 読込開始 */
  printf("fread start\n"); /* "fread start"と出力. */

  /* test_1.txt(サイズ8192バイト)の内容を読み込む. */
  for (i = 0; i < 2048; i++){ /* 4バイトずつ2048回読み込む.(4 * 2048 = 8192でBUFSIZと同じ.) */

    /* 4バイト読み込む. */
    fread(buf, 4, 1, fp); /* freadで4バイトずつbufに読み込む.(純粋にfreadだけ呼びたいので出力とかはしない.) */

  }

  /* 読込終了 */
  printf("fread end\n"); /* "fread end"と出力. */

  /* 閉じる */
  fclose(fp); /* fcloseでfpを閉じる. */

  /* プログラムの終了 */
  return 0;

}
