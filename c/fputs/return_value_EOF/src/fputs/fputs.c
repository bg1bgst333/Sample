/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言と初期化. */
  int ret;
  FILE *fp;
  char str[] = "ABCDE";

  /* ファイルtest.txtを読み取り専用で開く. */
  fp = fopen("test.txt", "r");
  if (fp == NULL){

    /* エラー処理 */
    printf("Can't open file!\n");
    return -1;

  }

  /* 文字列をファイルに書き込む. */
  ret = fputs(str, fp);

  /* 戻り値の出力. */
  printf("ret = %d\n", ret);

  /* EOFチェック */
  if (ret == EOF){
    printf("EOF!\n");
  }

  /* ファイルを閉じる. */
  fclose(fp);

  /* プログラムの終了 */
  return 0;

}
