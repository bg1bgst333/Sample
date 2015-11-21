/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */
#include <sys/types.h> /* 派生型 */
#include <pthread.h> /* POSIXスレッド */

/* スレッドの引数として渡す構造体THREAD_ARGの定義. */
typedef struct{
  int no; /* スレッド番号 */
  char message[32]; /* スレッドが出力するメッセージ. */
}THREAD_ARG; /* これでTHREAD_ARG型の完成. */

/* start_routine関数の定義 */
void *start_routine(void *arg){

  /* 変数の宣言 */
  int i; /* ループ用変数i */
  THREAD_ARG *thread_arg; /* THREAD_ARG型ポインタthread_arg */

  /* 引数argをTHREAD_ARG型のポインタにキャスト. */
  thread_arg = (THREAD_ARG *)arg; /* argをTHREAD_ARG型のポインタにキャストして, thread_argに格納. */

  /* 1から5までを出力. */
  for (i = 1; i <= 5; i++){ /* 1から5まで5回繰り返す. */

    /* i, thread_arg->no, thread_arg->messageを出力. */
    printf("i = %d, no = %d, message = %s\n", i, thread_arg->no, thread_arg->message); /* printfでi, thread_arg->no, thread_arg->messageの値を出力. */
    sleep(1); /* 1秒休止 */

  }

  /* スレッドの終了 */
  return NULL; /* NULLを返す. */

}

/* main関数の定義 */
int main(void){

  /* 変数・配列の宣言 */
  int i; /* ループ用変数i */
  pthread_t thread[5]; /* pthread_t型配列thread(要素数5) */
  THREAD_ARG thread_arg[5]; /* 引数として渡すTHREAD_ARG型配列thread_arg.(要素数5) */
  int result;/* pthread_createの結果を格納するint型変数result. */

  /* スレッドの一斉開始 */
  /* スレッド0 */
  thread_arg[0].no = 0; /* no = 0 */
  strcpy(thread_arg[0].message, "No.0"); /* message = "No.0" */
  result = pthread_create(&thread[0], NULL, start_routine, &thread_arg[0]); /* pthread_createでスレッドを生成して開始.(引数にthread_arg[0]を渡している.) */
  if (result != 0){ /* 0以外ならエラー. */
    printf("pthread_create error!\n"); /* エラーメッセージ. */
  }
  /* スレッド1 */
  thread_arg[1].no = 1; /* no = 1 */
  strcpy(thread_arg[1].message, "No.1"); /* message = "No.1" */
  result = pthread_create(&thread[1], NULL, start_routine, &thread_arg[1]); /* pthread_createでスレッドを生成して開始.(引数にthread_arg[1]を渡している.) */
  if (result != 0){ /* 0以外ならエラー. */
    printf("pthread_create error!\n"); /* エラーメッセージ. */
  }
  /* スレッド2 */
  thread_arg[2].no = 2; /* no = 2 */
  strcpy(thread_arg[2].message, "No.2"); /* message = "No.2" */
  result = pthread_create(&thread[2], NULL, start_routine, &thread_arg[2]); /* pthread_createでスレッドを生成して開始.(引数にthread_arg[2]を渡している.) */
  if (result != 0){ /* 0以外ならエラー. */
    printf("pthread_create error!\n"); /* エラーメッセージ. */
  }
  /* スレッド3 */
  thread_arg[3].no = 3; /* no = 3 */
  strcpy(thread_arg[3].message, "No.3"); /* message = "No.3" */
  result = pthread_create(&thread[3], NULL, start_routine, &thread_arg[3]); /* pthread_createでスレッドを生成して開始.(引数にthread_arg[3]を渡している.) */
  if (result != 0){ /* 0以外ならエラー. */
    printf("pthread_create error!\n"); /* エラーメッセージ. */
  }
  /* スレッド4 */
  thread_arg[4].no = 4; /* no = 4 */
  strcpy(thread_arg[4].message, "No.4"); /* message = "No.4" */
  result = pthread_create(&thread[4], NULL, start_routine, &thread_arg[4]); /* pthread_createでスレッドを生成して開始.(引数にthread_arg[4]を渡している.) */
  if (result != 0){ /* 0以外ならエラー. */
    printf("pthread_create error!\n"); /* エラーメッセージ. */
  }

  /* 全てのスレッドの終了を待機. */
  for (i = 0; i < 5; i++){ /* 5回繰り返す. */

    /* スレッド待機 */
    pthread_join(thread[i], NULL); /* pthread_joinでthreadのi番目を待機. */

  }

  /* プログラムの終了 */
  return 0;

}
