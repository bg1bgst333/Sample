/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数 */
int main(void){

  /* 変数の宣言 */
  FILE *fp; /* ファイルポインタfp */
  FILE *new; /* ファイルポインタnew */

  /* 存在しないファイルをわざと開く. */
  fp = fopen("test.txt", "r"); /* fopenで"test.txt"を開く. */
  if (fp == NULL){ /* NULLなら. */

    /* 既存のストリームのリダイレクト. */
    new = freopen("err.log", "a", stderr); /* freopenでstderrを"err.log"として開き直す. */
    if (new != NULL){ /* newがNULLでなければ. */

      /* newの値とstderrの値を出力. */
      fprintf(new, "new = %d, stderr = %d\n", new, stderr); /* newに:newを出力.(これもerr.logに出力される.) */

      /* エラーメッセージの出力. */
      perror("fopen error!"); /* perrorで"fopen error!"と出力. */

      /* stderrを閉じる. */
      fclose(stderr); /* fcloseでstderrを閉じる. */

      /* 異常終了 */
      return -1; /* -1を返して異常終了. */

    }

  }

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
