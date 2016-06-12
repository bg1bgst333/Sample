/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(int argc, char *argv[]){ /* argcは引数の個数, argvは各引数文字列へのポインタを格納した配列. */

  /* 変数の宣言 */
  int i; /* ループ用int型変数i. */

  /* 指定された引数をすべて出力. */
  for (i = 0; i < argc; i++){ /* argcの数だけ繰り返す. */
    printf("argv[%d] = %s\n", i, argv[i]); /* printfでargv[i]を出力. */
  }

  /* プログラムの終了 */
  return 0;

}
