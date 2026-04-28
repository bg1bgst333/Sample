/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* 変数の初期化・宣言 */
  int ret;
  FILE *fp;

  /* ファイルtest.txtを読み取り専用で開く. */
  fp = fopen("test.txt", "r");
  if (fp == NULL){
    printf("Can't open file!\n");
    return -1;
  }

  /* 読み取り専用で開いたファイルへの書き込み・戻り値の取得 */
  ret = fprintf(fp, "test");

  /* 戻り値の出力. */
  printf("ret = %d\n", ret);

  /* retが負なら"return value minus!"と表示. */
  if (ret < 0){
    printf("return value minus!\n");
  }

  /* ファイルを閉じる. */
  fclose(fp);

  /* プログラムの終了 */
  return 0;

}
