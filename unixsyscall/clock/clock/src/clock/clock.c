/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <time.h> /* UNIX時間 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  clock_t start; /* 開始時刻start(プロセッサ時間単位) */
  clock_t end; /* 終了時刻end(プロセッサ時間単位) */
  double elapsed; /* 経過時間elapsed(秒単位) */
  long i; /* ループ用変数i */

  /* 開始時刻start */
  start = clock(); /* clockで開始時刻(プロセッサ時間単位)を取得し, startに格納. */

  /* iが1000000になるまでループする. */
  for (i = 0; i != 1000000; i++){ /* iを0から足し続けて, 1000000になるまでループ. */

    /* iを出力 */
    printf("i = %ld\n", i); /* printfでiを出力. */

  }

  /* iが1000000の時. */
  printf("i = %ld\n", i); /* printfでi( = 1000000)を出力. */

  /* 終了時刻end */
  end = clock(); /* clockで終了時刻(プロセッサ時間単位)を取得し, endに格納. */

  /* 経過時間の計算 */
  elapsed = (double)(end - start) / CLOCKS_PER_SEC; /* endからstartを引いてCLOCKS_PER_SECで割ると秒単位の経過時間が算出できるので, それをelapsedに格納. */

  /* 経過時間の出力 */
  printf("elapsed = %lf\n", elapsed); /* printfで経過時間elapsedを出力. */

  /* プログラムの終了 */
  return 0;

}
