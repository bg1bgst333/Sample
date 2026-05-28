/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* 変数の初期化・宣言 */
  char str[256];
  char *ret;
  FILE *fp;

  /* ファイルtest.txtを開く. */
  fp = fopen("test.txt", "r");
  if (fp == NULL){

    /* エラー処理 */
    printf("Can't open file!\n");
    return -1;

  }

  /* ファイルから文字列を読み込む. */
  ret = fgets(str, sizeof(str), fp);

  /* 戻り値の出力. */
  printf("ret = %p\n", ret);
  printf("str = %s\n", str);

  /* retとstrのポインタが同じか確認する. */
  if (ret == str){
    printf("ret == str\n");
  }

  /* ファイルを閉じる. */
  fclose(fp);

  /* プログラムの終了 */
  return 0;

}
