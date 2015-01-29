/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力(ファイル入出力も含む.) */

/* main関数の定義 */
int main(void){

  /* ポインタの宣言 */
  FILE *fp; /* ファイルポインタfp(FILE型構造体へのポインタ) */

  /* ファイルを開く. */
  fp = fopen("test.txt", "r"); /* fopenで"test.txt"というファイルを読込専用("r")で開く. */
  if (fp == NULL){ /* fp == NULLならファイルを開くのに失敗. */

    /* エラー処理 */
    printf("Can't open file!\n"); /* printfで"Can't open file!"というエラーメッセージを出力. */
    return -1; /* エラーなど異常終了の場合は, -1などの0以外の値を返す. */

  }

  /* 成功した場合の処理 */
  printf("File was opened successfully.(fp == %p)\n", fp); /* "File was opened successfully."というメッセージとfpの値を出力. */

  /* ファイルを閉じる. */
  fclose(fp); /* fcloseでfpの指すファイルを閉じる. */

  /* プログラムの正常終了 */
  return 0; /* 正常終了なので0を返す. */

}
