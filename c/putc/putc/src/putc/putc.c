/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数 */
int main(void){

  /* 変数の宣言 */
  FILE *fp; /* ファイルポインタfp */
  int i; /* int型変数i. */
  int ret; /* int型変数ret. */

  /* test.txtを開く. */
  fp = fopen("test.txt", "w"); /* fopenで"test.txt"を"w"で開き, ファイルポインタをfpに格納. */
  if (fp == NULL){ /* エラー */

    /* エラー処理 */
    perror("test.txt"); /* perrorで"test.txt"に関するエラーを出力. */
    return -1; /* -1を返して異常終了. */

  }

  /* 'A'から'E'までをfpに出力. */
  for (i = 0; i < 5; i++){ /* 0から4まで繰り返す. */

    /* 1文字ずつ出力. */
    putc('A' + i, fp); /* putcで'A' + iの文字をfpに書き込む. */

  }

  /* ファイルを閉じる. */
  fclose(fp); /* fcloseでfpを閉じる. */

  /* 閉じた後にputcする. */
  ret = putc('A' + 5, fp); /* putcで'A' + 5の文字を閉じたfpに書き込む. */
  if (ret != EOF){ /* retがEOFでない場合. */
    printf("ret = \'%c\'\n", (char)ret); /* retに格納されている文字を出力. */
  }
  else{ /* retがEOFの時. */
    perror("ret == EOF"); /* perrorで"ret == EOF"に関するエラーを出力. */
    return -2; /* -2を返して異常終了. */
  }

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
