/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力(ファイル入出力も含む.) */

/* main関数の定義 */
int main(void){

  /* 配列・ポインタの宣言 */
  char text[256]; /* test.txtから読み込んだ文字列(最大255( = 256 - 1)文字). */
  FILE *fp; /* ファイルポインタfp */

  /* test.txtを開く. */
  fp = fopen("test.txt", "r"); /* test.txtを"r"で開く. */
  if (fp == NULL){ /* エラー */

    /* エラー処理 */
    printf("Can't open file!\n");
    return -1;

  }

  /* test.txtの読み込み. */
  fgets(text, 256, fp); /* fgetsでtest.txtから1行読み込み, textに格納する. */

  /* textの出力. */
  printf("%s\n", text); /* printfでtextを出力. */

  /* test.txtを閉じる. */
  fclose(fp); /* fcloseでtest.txtを閉じる. */

  /* プログラムの終了 */
  return 0;

}
