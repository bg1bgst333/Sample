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

  /* 変数の出力・戻り値の取得 */
  ret_c = printf("%c", c);
  printf("\n");
  ret_d = printf("%d", d);
  printf("\n");
  ret_x = printf("%x", x);
  printf("\n");
  ret_f = printf("%.2f", f);
  printf("\n");
  ret_s = printf("%s", s);
  printf("\n");

  /* 戻り値の出力. */
  printf("ret_c = %d\n", ret_c);
  printf("ret_d = %d\n", ret_d);
  printf("ret_x = %d\n", ret_x);
  printf("ret_f = %d\n", ret_f);
  printf("ret_s = %d\n", ret_s);

  /* プログラムの終了 */
  return 0;

}
