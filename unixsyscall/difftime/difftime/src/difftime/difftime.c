/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <time.h> /* UNIX時間 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  time_t start; /* 開始時刻start */
  time_t end; /* 終了時刻end */
  double elapsed; /* 経過時間elapsed */
  long i; /* ループ用変数i */

  /* 開始時刻のセット */
  start = time(NULL); /* timeで開始時刻を取得し, startに格納. */

  /* iが1000000になるまでループする. */
  for (i = 0; i != 1000000; i++){ /* iを0から足し続けて, 1000000になるまでループ. */

    /* iを出力 */
    printf("i = %ld\n", i); /* printfでiを出力. */

  }

  /* iが-1の時. */
  printf("i = %ld\n", i); /* printfでi( = 1000000)を出力. */

  /* 終了時刻のセット */
  end = time(NULL); /* timeで終了時刻を取得し, endに格納. */

  /* 経過時間の計算 */
  elapsed = difftime(end, start); /* difftimeでstartとendの差である経過時間を計算し, elapsedに格納. */

  /* 経過時間の出力 */
  printf("elapsed = %lf\n", elapsed); /* printfで経過時間elapsedを出力. */

  /* プログラムの終了 */
  return 0;

}
