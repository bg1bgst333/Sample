/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言・初期化 */
  int d = 10; /* dの値を10に初期化. */
  unsigned int x = 0xa; /* xの値を0xaに初期化. */
  float f = 0.123; /* fの値を0.123に初期化. */
  char c = 'A'; /* cの値を'A'に初期化. */

  /* 文字列リテラルのみの出力 */
  printf("String Literal only\n"); /* printfで文字列リテラル"String Literal only"のみ出力. */

  /* 1つの変数を指定の書式で出力. */
  printf("Decimal Int d = %d\n", d); /* printfでdの値を%d(10進整数形式)で出力. */
  printf("Hexadecimal Unsigned Int x = %x\n", x); /* printfでxの値を%x(16進整数形式)で出力. */
  printf("Float f = %f\n", f); /* printfでfの値を%f(実数形式)で出力. */
  printf("Char c = %c\n", c); /* printfでcの値を%c(文字形式)で出力. */

  /* 2つ以上の変数を指定の書式で出力. */
  printf("d = %d, x = %x, f = %f, c = %c\n", d, x, f, c); /* printfでd, x, f, cをそれぞれ出力. */

  /* 詳細な書式の指定 */
  printf("Field: [%3d]\n", 10); /* 桁数を指定すると足りない桁をスペースで埋める. */
  printf("Zero: [%03d]\n", 10); /* 0を付けると足りない桁を0で埋める. */
  printf("Precision: [%4.2f]\n", 12.345); /* .の後に数値を付けると小数点以下の精度を指定できる. */
  printf("Radix: [%#x], [%#o]\n", 0xa, 012); /* #を付けると, 基数に応じた文字を付ける. */

  /* プログラムの終了 */
  return 0;

}
