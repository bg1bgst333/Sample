/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <setjmp.h> /* setjmp */

/* ジャンプバッファの宣言 */
jmp_buf env; /* 実行コンテキストを格納するjmp_buf型env */

/* main関数 */
int main(void){

  /* 1つ目の処理 */
  printf("ABC\n"); /* "ABC"を出力. */

  /* 実行コンテキストの格納 */
  if (setjmp(env) == 0){ /* setjmpでenvに実行コンテキストを格納.(セットの時は0が返る.) */

    /* 2つ目の処理 */
    printf("DEF\n"); /* "DEF"を出力. */

  }

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
