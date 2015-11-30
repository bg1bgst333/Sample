/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <sys/types.h> /* 派生型 */
#include <pthread.h> /* POSIXスレッド */

/* スレッドの引数として渡す構造体THREAD_ARGの定義. */
typedef struct{
  int no; /* スレッド番号 */
  int *count1; /* カウント1のポインタ */
  int *count2; /* カウント2のポインタ */
  pthread_rwlock_t *rwlock; /* read/writeロックのポインタ */
}THREAD_ARG; /* これでTHREAD_ARG型の完成. */

/* start_routine関数の定義 */
void *start_routine(void *arg){

  /* 変数の宣言・初期化 */
  THREAD_ARG *thread_arg = (THREAD_ARG *)arg; /* argをTHREAD_ARG型ポインタにキャストし, thread_argに格納. */

  /* noごとに動作を変える. */
  if (thread_arg->no == 0){ /* noが0の時. */

    /* readロックを掛ける. */
    pthread_rwlock_rdlock(thread_arg->rwlock); /* pthread_rwlock_rdlockでreadロックを掛ける. */

    /* no, count1, count2の値をチェックする. */
    printf("no = %d, count1 = %d, count2 = %d\n", thread_arg->no, *(thread_arg->count1), *(thread_arg->count2)); /* それぞれの値を出力. */
    sleep(1); /* 1秒スリープ */
    printf("no = %d, count1 = %d, count2 = %d\n", thread_arg->no, *(thread_arg->count1), *(thread_arg->count2)); /* それぞれの値を出力. */
    sleep(1); /* 1秒スリープ */
    printf("no = %d, count1 = %d, count2 = %d\n", thread_arg->no, *(thread_arg->count1), *(thread_arg->count2)); /* それぞれの値を出力. */
    sleep(1); /* 1秒スリープ */
    *(thread_arg->count1) = 1; /* count1を1にする. */
    printf("no = %d, count1 = %d, count2 = %d\n", thread_arg->no, *(thread_arg->count1), *(thread_arg->count2)); /* それぞれの値を出力. */
    sleep(1); /* 1秒スリープ */
    printf("no = %d, count1 = %d, count2 = %d\n", thread_arg->no, *(thread_arg->count1), *(thread_arg->count2)); /* それぞれの値を出力. */
    sleep(1); /* 1秒スリープ */

    /* readロックをアンロック. */
    pthread_rwlock_unlock(thread_arg->rwlock); /* pthread_rwlock_unlockでreadロックをアンロック. */

  }
  else{ /* noが1の時. */

    /* writeロックを掛ける. */
    pthread_rwlock_wrlock(thread_arg->rwlock); /* pthread_rwlock_wrlockでwriteロックを掛ける. */

    /* no, count1, count2の値をチェックする. */
    printf("no = %d, count1 = %d, count2 = %d\n", thread_arg->no, *(thread_arg->count1), *(thread_arg->count2)); /* それぞれの値を出力. */
    sleep(1); /* 1秒スリープ */
    *(thread_arg->count2) = 1; /* count2を1にする. */
    printf("no = %d, count1 = %d, count2 = %d\n", thread_arg->no, *(thread_arg->count1), *(thread_arg->count2)); /* それぞれの値を出力. */
    sleep(1); /* 1秒スリープ */
    *(thread_arg->count2) = 2; /* count2を2にする. */
    printf("no = %d, count1 = %d, count2 = %d\n", thread_arg->no, *(thread_arg->count1), *(thread_arg->count2)); /* それぞれの値を出力. */
    sleep(1); /* 1秒スリープ */
    *(thread_arg->count2) = 3; /* count2を3にする. */
    printf("no = %d, count1 = %d, count2 = %d\n", thread_arg->no, *(thread_arg->count1), *(thread_arg->count2)); /* それぞれの値を出力. */
    sleep(1); /* 1秒スリープ */
    *(thread_arg->count2) = 4; /* count2を4にする. */
    printf("no = %d, count1 = %d, count2 = %d\n", thread_arg->no, *(thread_arg->count1), *(thread_arg->count2)); /* それぞれの値を出力. */
    sleep(1); /* 1秒スリープ */

    /* writeロックをアンロック. */
    pthread_rwlock_unlock(thread_arg->rwlock); /* pthread_rwlock_unlockでwriteロックをアンロック. */

  }

  /* スレッドの終了 */
  return NULL; /* NULLを返す */

} 

/* main関数の定義 */
int main(void){

  /* 変数・配列の宣言・初期化 */
  pthread_t thread[2]; /* pthread_t型配列thread(要素数2) */
  pthread_rwlock_t rwlock; /* read/writeロック. */
  THREAD_ARG thread_arg[2]; /* 引数として渡すTHREAD_ARG型配列thread_arg.(要素数2) */
  int count1 = 0; /* カウント1を0に初期化. */
  int count2 = 0; /* カウント2を0に初期化. */

  /* read/writeロックの初期化 */
  pthread_rwlock_init(&rwlock, 0); /* pthread_rwlock_initでrwlockを初期化. */

  /* スレッド0の生成 */
  thread_arg[0].no = 0; /* noは0. */
  thread_arg[0].count1 = &count1; /* count1のアドレスをthread_arg[0].count1に. */
  thread_arg[0].count2 = &count2; /* count2のアドレスをthread_arg[0].count2に. */
  thread_arg[0].rwlock = &rwlock; /* rwlockのアドレスをthread_arg[0].rwlockに. */
  pthread_create(&thread[0], NULL, start_routine, &thread_arg[0]); /* pthread_createでthread[0]を生成. */
  pthread_detach(thread[0]); /* pthread_detachでthread[0]をデタッチ. */

  /* スレッド1の生成 */
  thread_arg[1].no = 1; /* noは1. */
  thread_arg[1].count1 = &count1; /* count1のアドレスをthread_arg[1].count1に. */
  thread_arg[1].count2 = &count2; /* count2のアドレスをthread_arg[1].count2に. */
  thread_arg[1].rwlock = &rwlock; /* rwlockのアドレスをthread_arg[1].rwlockに. */
  pthread_create(&thread[1], NULL, start_routine, &thread_arg[1]); /* pthread_createでthread[1]を生成. */
  pthread_detach(thread[1]); /* pthread_detachでthread[1]をデタッチ. */
  
  /* スレッドの終了 */
  pthread_exit(NULL); /* デタッチしたスレッドの終了を待つ. */

  /* ロックの破棄 */
  pthread_rwlock_destroy(&rwlock); /* pthread_rwlock_destroyでrwlockを破棄. */

  /* プログラムの終了 */
  return 0;

}
