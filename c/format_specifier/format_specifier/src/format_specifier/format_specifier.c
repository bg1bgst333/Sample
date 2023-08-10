/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* 変数の初期化. */
  unsigned short us = 32768; /* unsigned short型usを32768(signed shortの最大値 + 1)で初期化. */
  unsigned int u = 2147483648; /* unsigned int型uを2147483648(signed intの最大値 + 1)で初期化. */
  unsigned long ul = 2147483648; /* unsigned long型ulを2147483648(signed longの最大値 + 1)で初期化. */
  unsigned short o = 10; /* unsigned short型oを10で初期化. */
  float e = 13579; /* float型eを13579で初期化. */

  /* 出力 */
  printf("us(%%hi) = %hi\n", us); /* printfでusを%hiで出力. */
  printf("us(%%hu) = %hu\n", us); /* printfでusを%huで出力. */
  printf("u(%%d) = %d\n", u); /* printfでuを%dで出力. */
  printf("u(%%u) = %u\n", u); /* printfでuを%uで出力. */
  printf("ul(%%d) = %d\n", ul); /* printfでulを%dで出力. */
  printf("ul(%%lu) = %lu\n", ul); /* printfでulを%luで出力. */
  printf("o(%%hi) = %hi\n", o); /* printfでoを%hiで出力. */
  printf("o(%%o) = %o\n", o); /* printfでoを%oで出力. */
  printf("e(%%f) = %f\n", e); /* printfでeを%fで出力. */ 
  printf("e(%%e) = %5.4e\n", e); /* printfでeを%5.4eで出力. */

  /* プログラムの終了 */
  return 0;

}
