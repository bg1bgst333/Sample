/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数 */
int main(void){

  /* 変数の宣言 */
  char c; /* 取得文字c */
  FILE *fp; /* ファイルポインタfp */

  /* test.txtを開く. */
  fp = fopen("test.txt", "r"); /* fopenで"test.txt"を"r"で開き, ファイルポインタをfpに格納. */
  if (fp == NULL){ /* エラー */

    /* エラー処理 */
    perror("test.txt"); /* perrorで"test.txt"に関するエラーを出力. */
    return -1; /* -1を返して異常終了. */

  }

  /* 1文字ずつ文字を取得し, 出力していく. */
  while ((c = fgetc(fp)) != EOF){ /* fgetcでfpから文字を取得してcに格納, さらにそのcがEOFでない間はループを続ける. */

    /* cを出力. */
    putchar(c); /* putcharでcを出力. */

  }

  /* "test.txt"を閉じる. */
  fclose(fp); /* fcloseでfpを閉じる. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
