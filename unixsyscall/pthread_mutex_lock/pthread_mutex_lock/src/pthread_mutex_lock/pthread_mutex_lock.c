/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <sys/types.h> /* 派生型 */
#include <pthread.h> /* POSIXスレッド */

/* スレッドの引数として渡す構造体THREAD_ARGの定義. */
typedef struct{
  int no; /* スレッド番号 */
  pthread_mutex_t *mutex; /* ミューテックスへのポインタ */
}THREAD_ARG; /* これでTHREAD_ARG型の完成. */

/* start_routine関数の定義 */
void *start_routine(void *arg){

  /* 変数の宣言 */
  int i; /* ループ用変数i */
  THREAD_ARG *thread_arg; /* THREAD_ARG型ポインタthread_arg */

  /* 引数argをTHREAD_ARG型のポインタにキャスト. */
  thread_arg = (THREAD_ARG *)arg; /* argをTHREAD_ARG型のポインタにキャストして, thread_argに格納. */

  /* ミューテックスのロック */
  pthread_mutex_lock(thread_arg->mutex); /* pthread_mutex_lockでthread_arg->mutexの指すミューテックスをロック. */

  /* 1から5まで出力. */
  for (i = 1; i <= 5; i++){ /* 1から5まで5回繰り返す. */

    /* i, thread_arg->noを出力. */
    printf("i = %d, no = %d\n", i, thread_arg->no); /* printfでi, thread_arg->noを出力. */
    sleep(1); /* 1秒休止 */

  }

  /* ミューテックスのアンロック */
  pthread_mutex_unlock(thread_arg->mutex); /* pthread_mutex_unlockでthread_arg->mutexの指すミューテックスをアンロック. */

  /* スレッドの終了 */
  return NULL; /* NULLを返す. */

}

/* main関数の定義 */
int main(void){

  /* 変数・配列の宣言・初期化 */
  int i; /* ループ用変数i */
  pthread_t thread[5]; /* pthread_t型配列thread(要素数5) */
  THREAD_ARG thread_arg[5]; /* 引数として渡すTHREAD_ARG型配列thread_arg.(要素数5) */
  pthread_mutex_t fast = PTHREAD_MUTEX_INITIALIZER; /* pthread_mutex_t型変数fastをPTHREAD_MUTEX_INITIALIZERで初期化. */

  /* スレッドの一斉開始 */
  /* スレッド0 */
  thread_arg[0].no = 0; /* no = 0 */
  thread_arg[0].mutex = &fast; /* mutex = &fast */
  pthread_create(&thread[0], NULL, start_routine, &thread_arg[0]); /* pthread_createでスレッド開始. */
  pthread_detach(thread[0]); /* pthread_detachでthread[0]をデタッチ状態にする. */
  /* スレッド1 */
  thread_arg[1].no = 1; /* no = 1 */
  thread_arg[1].mutex = &fast; /* mutex = &fast */
  pthread_create(&thread[1], NULL, start_routine, &thread_arg[1]); /* pthread_createでスレッド開始. */
  pthread_detach(thread[1]); /* pthread_detachでthread[1]をデタッチ状態にする. */
  /* スレッド2 */
  thread_arg[2].no = 2; /* no = 2 */
  thread_arg[2].mutex = &fast; /* mutex = &fast */
  pthread_create(&thread[2], NULL, start_routine, &thread_arg[2]); /* pthread_createでスレッド開始. */
  pthread_detach(thread[2]); /* pthread_detachでthread[2]をデタッチ状態にする. */
  /* スレッド3 */
  thread_arg[3].no = 3; /* no = 3 */
  thread_arg[3].mutex = &fast; /* mutex = &fast */
  pthread_create(&thread[3], NULL, start_routine, &thread_arg[3]); /* pthread_createでスレッド開始. */
  pthread_detach(thread[3]); /* pthread_detachでthread[3]をデタッチ状態にする. */
  /* スレッド4 */
  thread_arg[4].no = 4; /* no = 4 */
  thread_arg[4].mutex = &fast; /* mutex = &fast */
  pthread_create(&thread[4], NULL, start_routine, &thread_arg[4]); /* pthread_createでスレッド開始. */
  pthread_detach(thread[4]); /* pthread_detachでthread[4]をデタッチ状態にする. */

  /* デタッチしたスレッド達が終了するまで待機. */
  pthread_exit(NULL); /* ここでpthread_exitすると, デタッチしたスレッドがすべて終了するまで待機する. */

  /* プログラムの終了 */
  return 0;

}
