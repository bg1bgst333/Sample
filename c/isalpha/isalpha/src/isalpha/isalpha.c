/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <ctype.h> /* 文字操作 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  int c; /* int型変数c */

  /* 入力フォームの出力 */
  printf("c: "); /* "c: "を出力. */

  /* 入力文字の取得 */
  c = getchar(); /* getcharが返す値をcに代入. */

  /* 入力文字のチェック */
  if (isalpha(c)){ /* isalphaが真なら. */

    /* "Alphabet"と出力. */
    printf("Alphabet\n"); /* printfで"Alphabet"と出力. */

  }
  else{ /* isalphaが偽なら. */

    /* "Not Alphabet"と出力. */
    printf("Not Alphabet\n"); /* printfで"Not Alphabet"と出力. */

  }

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
