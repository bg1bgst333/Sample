/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* 整数リテラル */
  printf("Integer Literal(Decimal) %d = %d\n", 123, 123); /* printfで整数リテラル(10進数)の123を出力. */
  printf("Integer Literal(Octal) %d = 0%o\n", 0173, 0173); /* printfで整数リテラル(8進数)の123( = 0173)を出力. */
  printf("Integer Literal(Hexadecimal) %d = 0x%x\n", 0x7b, 0x7b); /* printfで整数リテラル(16進数)の123( = 0x7b)を出力. */

  /* 実数リテラル */
  printf("Float Literal %f = %f\n", 0.00025, 0.00025); /* printfで実数リテラルの0.00025を出力. */
  printf("Float Literal(Scientific notation) %f = %e\n", 2.5e-4, 2.5e-4); /* printfで実数リテラル(指数表記)の0.00025( = 2.5e-4)を出力. */

  /* 文字リテラル */
  printf("Char Literal %c = %c\n", 'A', 'A'); /* printfで文字リテラルの'A'を出力. */
  printf("Char Literal(Byte value) %c = 0x%x\n", 0x41, 0x41); /* printfで文字リテラル(バイト値)の'A'( = 0x41)を出力. */

  /* 文字列リテラル */
  printf("String Literal %s\n", "ABC"); /* printfで文字列リテラルの"ABC"を出力. */

  /* プログラムの終了 */
  return 0;

}
