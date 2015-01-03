/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* 変数・配列の宣言 */
  int i; /* int型変数i */
  float f; /* float型変数f */
  char c; /* char型変数c */
  char str[32]; /* char型配列str(長さ32) */

  /* 1つの変数や配列に入力されたデータを格納. */
  printf("i: "); /* iの入力フォーム */
  scanf("%d", &i); /* scanfで入力された整数をiに格納. */
  printf("f: "); /* fの入力フォーム */
  scanf("%f", &f); /* scanfで入力された実数をfに格納. */
  printf("c: "); /* cの入力フォーム */
  scanf("%*c%c", &c); /* scanfで入力された文字をcに格納.(直前の改行文字は%*cで読み飛ばす.) */
  printf("str: "); /* strの入力フォーム */
  scanf("%s", str); /* scanfで入力された文字列をstrに格納. */
  printf("i = %d, f = %f, c = %c, str = %s\n", i, f, c, str); /* それぞれの変数・配列の中身をprintfで出力. */

  /* 2つ以上の入力されたデータを指定の変数・配列に格納. */
  printf("ex) 10 123 A ABC\n"); /* 入力例 */
  scanf("%d %f %c %s", &i, &f, &c, str); /* スペースで区切って入力する. */
  printf("i = %d, f = %f, c = %c, str = %s\n", i, f, c, str); /* それぞれの変数・配列の中身をprintfで出力. */

  /* プログラムの終了 */
  return 0;

}
