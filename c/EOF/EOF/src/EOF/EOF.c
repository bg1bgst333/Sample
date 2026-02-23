/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  FILE *fp;
  int value;
  int result;

  /* 無限ループでファイルを読み込む. */
  fp = fopen("test.txt", "r");
  if (fp == NULL){
    return 1;
  }
  while (1){
    result = fscanf(fp, "%d", &value);
    if (result == EOF){ /* EOFなら. */
      printf("(EOF)\n"); /* "(EOF)"を出力. */
      break;
    }
    printf("%d\n", value); /* 読み込めた値を出力. */
  }
  fclose(fp);

  /* プログラムの終了 */
  return 0;

}
