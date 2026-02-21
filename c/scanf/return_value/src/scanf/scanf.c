/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* 変数・配列の宣言 */
  int n;
  int x;
  int y; 
  char str1[16];
  char str2[16];
  char str3[16];
  int ret_1;
  int ret_2;
  int ret_3;

  /* 入力値が整数1つ. */
  printf("n: ");
  ret_1 = scanf("%d", &n);
  printf("n = %d, ret_1 = %d\n", n, ret_1);

  /* 入力値が整数2つ. */
  printf("x y: ");
  ret_2 = scanf("%d %d", &x, &y);
  printf("x = %d, y = %d, ret_2 = %d\n", x, y, ret_2);

  /* 入力値が文字列3つ. */
  printf("str1 str2 str3: ");
  ret_3 = scanf("%s %s %s", str1, str2, str3);
  printf("str1 = %s, str2 = %s, str3 = %s, ret_3 = %d\n", str1, str2, str3, ret_3);

  /* プログラムの終了 */
  return 0;

}
