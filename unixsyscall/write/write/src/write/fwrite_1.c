/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  FILE *fp; /* ファイルポインタfp */
  int i; /* ループ用変数i */

  /* 高水準入出力関数で使われるバッファサイズを出力. */
  printf("BUFSIZ = %d\n", BUFSIZ); /* printfでBUFSIZの値を出力. */

  /* ファイルtest_1.txtを開く. */
  fp = fopen("test_1.txt", "wb"); /* fopenで"test_1.txt"を"wb"で開く. */
  if (fp == NULL){ /* NULLの時はエラー. */

    /* エラー処理 */
    printf("fopen error!\n"); /* "fopen error!"と出力. */
    return -1; /* -1を返す. */

  }

  /* 書込開始 */
  printf("fwrite start\n"); /* "fwrite start"と出力. */

  /* test_1.txtに"ABCD"4バイトを2048回書きこむ.(4 * 2048 = 8192でBUFSIZと同じ.) */
  for (i = 0; i < 2048; i++){ /* 2048回繰り返す. */

    /* 4バイト書きこむ. */
    fwrite("ABCD", 4, 1, fp); /* fwriteで4バイトずつtest_1.txtに書きこむ.(純粋にfwriteだけ呼びたいので出力とかはしない.) */

  }

  /* 書込終了 */
  printf("fwrite end\n"); /* "fwrite end"と出力. */

  /* 閉じる */
  fclose(fp); /* fcloseでfpを閉じる. */

  /* プログラムの終了 */
  return 0;

}
