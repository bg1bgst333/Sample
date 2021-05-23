/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <stdlib.h> /* 標準ユーティリティ */

/* main関数 */
int main(void){

  /* 変数・配列の宣言 */
  char str[16]; /* 数値文字列を格納するchar型配列str(長さ16) */
  double d; /* double型変数d */

  /* 入力フォーム */
  printf("str: "); /* strの入力フォームを出力. */
  scanf("%s", str); /* scanfで入力された文字列をstrに格納. */

  /* atofで数値文字列strを倍精度浮動小数点数値dに変換. */
  d = atof(str); /* atofにstrを渡すことで, dに変換された浮動小数点数値が返る. */

  /* dの出力. */
  printf("d = %lf\n", d); /* dを出力. */

  /* プログラムの終了. */
  return 0; /* 0を返して正常終了. */

}
