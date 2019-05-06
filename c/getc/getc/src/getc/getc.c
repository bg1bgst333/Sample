/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力(ファイル入出力も含む.) */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  char c; /* 取得した文字を格納するchar型変数c. */
  FILE *fp; /* ファイルポインタfp */

  /* 標準入力から文字を取得. */
  printf("stdin: "); /* 入力フォーム. */
  c = getc(stdin); /* getcでstdinから文字を取得. */

  /* 取得した文字の出力. */
  printf("stdin: c = %c\n", c); /* cを出力. */

  /* ファイルから文字を取得.(test1.txtを開く.) */
  fp = fopen("test1.txt", "r"); /* test1.txtを"r"で開く. */
  if (fp == NULL){ /* エラー */

    /* エラー処理 */
    perror("test1.txt"); /* test1.txtに関するエラー出力. */
    return -1; /* -1を返して異常終了. */

  }

  /* 文字を取得. */
  c = getc(fp); /* getcでfpから文字を取得. */

  /* 取得した文字の出力. */
  printf("fp: c = %c\n", c); /* cを出力. */

  /* test1.txtを閉じる. */
  fclose(fp); /* fcloseでtest1.txtを閉じる. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
