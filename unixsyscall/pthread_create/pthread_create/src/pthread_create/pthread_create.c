/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <sys/types.h> /* 派生型 */
#include <pthread.h> /* POSIXスレッド */

/* start_routine関数の定義 */
void *start_routine(void *arg){

  /* 変数の宣言 */
  int i; /* ループ用変数i */

  /* 1から5までを出力. */
  for (i = 1; i <= 5; i++){ /* 1から5まで5回繰り返す. */

    /* iを出力. */
    printf("i = %d\n", i); /* printfでiの値を出力. */
    sleep(1); /* 1秒休止 */

  }

  /* スレッドの終了 */
  return NULL; /* NULLを返す. */

}

/* main関数の定義 */
int main(void){

  /* 変数・配列の宣言 */
  int i; /* ループ用変数i */
  pthread_t thread[5]; /* pthread_t型の配列thread(要素数5) */
  int result; /* pthread_createの結果を格納するint型変数result. */

  /* スレッドの一斉開始 */
  for (i = 0; i < 5; i++){ /* 5回繰り返す. */

    /* スレッド開始 */
    result = pthread_create(&thread[i], NULL, start_routine, NULL); /* pthread_createでスレッドを生成して開始.(新しいスレッドstart_routineを実行.) */
    if (result != 0){ /* 0以外ならエラー. */
      printf("pthread_create error!\n"); /* エラーメッセージ. */
    }

  }

  /* 全てのスレッドの終了を待機. */
  for (i = 0; i < 5; i++){ /* 5回繰り返す. */

    /* スレッド待機 */
    pthread_join(thread[i], NULL); /* pthread_joinでthreadのi番目を待機. */

  }

  /* プログラムの終了 */
  return 0;

}
