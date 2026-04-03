/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* 変数の初期化・宣言 */
  char c = 'X';
  int d = 10;
  unsigned int x = 0x11a;
  float f = 0.12;
  char s[] = "ABCDE";
  int ret_c;
  int ret_d;
  int ret_x;
  int ret_f;
  int ret_s;
  FILE *fp;

  /* ファイルtest.txtを開く. */
  fp = fopen("test.txt", "w");
  if (fp == NULL){

    /* エラー処理 */
    printf("Can't open file!\n");
    return -1;

  }

  /* 変数のファイル出力・戻り値の取得 */
  ret_c = fprintf(fp, "%c", c);
  fprintf(fp, "\n");
  ret_d = fprintf(fp, "%d", d);
  fprintf(fp, "\n");
  ret_x = fprintf(fp, "%x", x); 
  fprintf(fp, "\n");
  ret_f = fprintf(fp, "%.2f", f);
  fprintf(fp, "\n");
  ret_s = fprintf(fp, "%s", s);

  /* 戻り値の出力. */
  printf("ret_c = %d\n", ret_c);
  printf("ret_d = %d\n", ret_d);
  printf("ret_x = %d\n", ret_x);
  printf("ret_f = %d\n", ret_f);
  printf("ret_s = %d\n", ret_s);

  /* ファイルを閉じる. */
  fclose(fp);

  /* プログラムの終了 */
  return 0;

}

