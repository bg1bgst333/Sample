/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* 文字列マクロSTRをvwxyz定義. */
#define STR "vwxyz"

/* main関数の定義 */
int main(void){

  /* 変数・配列・ポインタの宣言・初期化. */
  char c; /* char型変数c */
  int i; /* int型変数i */
  float f; /* float型変数f */
  double d; /* double型変数d */
  int array[5]; /* int型配列array(要素数5) */
  int *ptr; /* int型ポインタptr */
  char str[] = "abcde"; /* 文字配列strを"abcde"に初期化. */
  char *pstr = "pqrst"; /* 文字列リテラル"pqrst"のアドレスをポインタpstrにセット. */

  /* sizeofで型のサイズを調べる. */
  printf("sizeof(char) = %d\n", sizeof(char)); /* printfでsizeof(char)の値を出力. */
  printf("sizeof(int) = %d\n", sizeof(int)); /* printfでsizeof(int)の値を出力. */
  printf("sizeof(float) = %d\n", sizeof(float)); /* printfでsizeof(float)の値を出力. */
  printf("sizeof(double) = %d\n", sizeof(double)); /* printfでsizeof(double)の値を出力. */

  /* sizeofで変数のサイズを調べる. */
  printf("sizeof(c) = %d\n", sizeof(c)); /* printfでsizeof(c)の値を出力. */
  printf("sizeof(i) = %d\n", sizeof(i)); /* printfでsizeof(i)の値を出力. */
  printf("sizeof(f) = %d\n", sizeof(f)); /* printfでsizeof(f)の値を出力. */
  printf("sizeof(d) = %d\n", sizeof(d)); /* printfでsizeof(d)の値を出力. */

  /* 配列とポインタのサイズ比較. */
  ptr = array; /* arrayの先頭アドレスをptrに格納. */
  printf("sizeof(array) = %d\n", sizeof(array)); /* printfでsizeof(array)の値を出力. */
  printf("sizeof(ptr) = %d\n", sizeof(ptr)); /* printfでsizeof(ptr)の値を出力. */

  /* 文字列のサイズ比較. */
  printf("sizeof(str) = %d\n", sizeof(str)); /* printfでsizeof(str)の値を出力. */
  printf("sizeof(pstr) = %d\n", sizeof(pstr)); /* printfでsizeof(pstr)の値を出力. */
  printf("sizeof(STR) = %d\n", sizeof(STR)); /* printfでsizeof(STR)の値を出力. */
  
  /* プログラムの終了 */
  return 0;

}
