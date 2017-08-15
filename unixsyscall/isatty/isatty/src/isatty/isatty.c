/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <unistd.h> /* UNIX標準 */

/* main関数 */
int main(void){

  /* 変数の宣言 */
  int i; /* ループ用変数i. */

  /* リダイレクトされているかをチェック. */
  if (isatty(fileno(stdout))){ /* stdoutのディスクリプタが端末への出力の場合. */

    /* 5回"ABCDE"を出力. */
    for (i = 0; i < 5; i++){ /* 5回繰り返す. */
      printf("ABCDE\n"); /* "ABCDE"を出力. */
    }

  }
  else{ /* stdoutのディスクリプタがリダイレクトされてファイルに出力された場合. */

    /* ヘッダの出力. */
    printf("-----header-----\n"); /* "-----header-----"を出力. */

    /* 5回"ABCDE"を出力. */
    for (i = 0; i < 5; i++){ /* 5回繰り返す. */
      printf("ABCDE\n"); /* "ABCDE"を出力. */
    }

    /* フッダの出力. */
    printf("-----footer-----\n"); /* "-----footer-----"を出力. */

  }

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
