/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  FILE *fp; /* ファイルポインタfp */
  char buf[819200]; /* サイズ819200のバッファを用意. */

  /* 高水準入出力関数で使われるバッファサイズを出力. */
  printf("BUFSIZ = %d\n", BUFSIZ); /* printfでBUFSIZの値を出力. */

  /* ファイルtest_2.txtを開く. */
  fp = fopen("test_2.txt", "wb"); /* fopenで"test_2.txt"を"wb"で開く. */
  if (fp == NULL){ /* NULLの時はエラー. */

    /* エラー処理 */
    printf("fopen error!\n"); /* "fopen error!"と出力. */
    return -1; /* -1を返す. */

  }

  /* 書込開始 */
  printf("fwrite start\n"); /* "fwrite start"と出力. */

  /* 'A'を819200個セット. */
  memset(buf, 'A', 819200); /* memsetで819200個の'A'をセット. */

  /* 819200バイト一気に書きこむ. */
  fwrite(buf, 819200, 1, fp); /* fwriteで819200バイト分の'A'を1個分一気に書きこむ.(純粋にfwriteだけ呼びたいので出力とかはしない.) */

  /* 書込終了 */
  printf("fwrite end\n"); /* "fwrite end"と出力. */

  /* 閉じる */
  fclose(fp); /* fcloseでfpを閉じる. */

  /* プログラムの終了 */
  return 0;

}
