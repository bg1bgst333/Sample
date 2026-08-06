/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  char str[256];
  int ret;
  FILE *fp;

  /* test.txtを開く. */
  fp = fopen("test.txt", "r");
  if (fp == NULL){

    /* エラー処理 */
    printf("Can't open file!\n");
    return -1;

  }

  /* EOFになるまでファイルから文字列を読み込む. */
  while (1){

    /* 文字列を読み込む. */
    ret = fscanf(fp, "%s", str);

    /* 文字列の出力. */
    printf("str = %s\n", str);

    /* 戻り値の出力. */
    printf("ret = %d\n", ret);

    /* EOFチェック */
    if (ret == EOF){
      printf("EOF!\n");
      break;
    }

  }

  /* ファイルを閉じる. */
  fclose(fp);

  /* プログラムの終了 */
  return 0;

}
