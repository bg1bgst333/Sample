/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
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

  /* EOFになるまでファイルから文字列を読み込む. */
  while (1){

    /* 文字列の読み込み. */
    ret = fgets(str, sizeof(str), fp);

    /* 戻り値の出力. */
    printf("ret = %p\n", ret);

    /* NULLチェック */
    if (ret == NULL){
      printf("ret == NULL\n");
      break;
    }

    /* 読み込んだ文字列の出力. */
    printf("str = %s", str);

  }

  /* ファイルを閉じる. */
  fclose(fp);

  /* プログラムの終了 */
  return 0;

}
