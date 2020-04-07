/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(int argc, char *argv[]){

  /* 変数の宣言 */
  int i; /* ループ用変数i. */

  /* コマンドライン引数の出力. */
  for (i = 0; i < argc; i++){ /* argcの数繰り返す. */

    /* argvの出力. */
    printf("argv[%d] = %s\n", i, argv[i]); /* argvの各要素を出力. */

  }

  /* プログラムの終了. */
  return 0; /* 0を返して正常終了. */

}
