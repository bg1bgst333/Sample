/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  char str[256];
  int d;
  int ret;
  FILE *fp;

  /* test.txtを開く. */
  fp = fopen("test.txt", "r");
  if (fp == NULL){
    /* エラー処理 */
    printf("Can't open file!\n");
    return -1;
  }

  /* ファイルから文字列と整数を読み込み, 戻り値を取得. */
  ret = fscanf(fp, "%s %d", str, &d);

  /* 出力 */
  printf("str = %s\n", str);
  printf("d = %d\n", d);
  printf("ret = %d\n", ret);

  /* ファイルを閉じる. */
  fclose(fp);

  /* プログラムの終了 */
  return 0;

}
