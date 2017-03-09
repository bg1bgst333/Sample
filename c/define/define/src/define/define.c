/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */

/* マクロの定義 */
#define INT_TEN 10
#define STR_ABC "ABC"

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  int i; /* int型i */
  char str[8]; /* char型配列str.(要素数8.) */

  /* マクロの代入やコピー */
  i = INT_TEN; /* INT_TENは10に置換されるので, コンパイル時はi = 10となっている. */
  strcpy(str, STR_ABC); /* STR_ABCは"ABC"に置換されるので, コンパイル時はstrcpy(str, "ABC")となっている. */

  /* 出力 */
  printf("i = %d\n", i); /* printfでiを出力. */
  printf("str = %s\n", str); /* printfでstrを出力. */

  /* プログラムの終了 */
  return 0;

}
