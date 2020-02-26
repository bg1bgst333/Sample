/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <sys/types.h> /* 派生型 */
#include <sys/wait.h> /* 待機 */
#include <unistd.h> /* UNIX標準 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  int i; /* ループ用変数i. */
  int j; /* ループ用変数j. */
  pid_t pid; /* プロセスIDを格納する変数pid. */
  pid_t child_pid_array[5]; /* 子プロセスID配列child_pid_array(要素数5) */
  int status; /* ステータスstatus */

  /* 子プロセスを5つ生成 */
  for (i = 0; i < 5; i++){ /* 5回繰り返す. */

    /* プロセス分岐 */
    pid = fork(); /* forkでプロセスを生成し, プロセスIDをpidに格納. */
    if (pid < 0){ /* pidが負の場合. */

      /* エラー処理 */
      perror("fork"); /* "fork"とエラーメッセージをエラー出力. */
      return -1; /* -1を返して異常終了. */

    }
    else if (pid == 0){ /* pidが0の場合. */

      /* 子プロセスの処理 */
      for (j = 0; j < i + 1; j++){ /* i回繰り返す. */
        sleep(5); /* sleepで5秒休止. */
        pid = getpid(); /* getpidで自分のプロセスIDを取得し, pidに格納. */
        printf("pid = %d\n", pid); /* pidを出力. */
      }

      /* 子プロセスの終了 */
      return 0; /* 0を返して正常終了. */

    }
    else{ /* pidが正の場合. */

      /* 親プロセスの処理 */
      child_pid_array[i] = pid; /* 取得したpidをchild_pid_array[i]に格納. */

    }

  }

  /* 子プロセスの待機. */
  for (i = 0; i < 5; i++){ /* 5回繰り返す. */
    waitpid(child_pid_array[i], &status, 0); /* child_pid_array[i]を待つ. */
    printf("finished! child_pid_array[%d] = %d\n", i, child_pid_array[i]); /* "finished! child_pid_array[i] = pid"を出力. */
    sleep(5); /* sleepで5秒休止. */
  }
  printf("all finished!\n"); /* "all finished!"と出力. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
