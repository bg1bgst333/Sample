/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <sys/types.h> /* 派生型 */
#include <unistd.h> /* UNIX標準 */
#include <signal.h> /* シグナル */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  pid_t pid; /* fork前のgetpidで取得した自分のプロセスID pid. */
  pid_t result; /* fork時の戻り値result. */
  pid_t child; /* fork時の戻り値, または, getpidの戻り値で取得した子プロセスID child. */
  int i; /* ループ用変数i */

  /* fork前の自分のプロセスIDを取得. */
  pid = getpid(); /* getpidで自分のプロセスIDを取得. */
  printf("pid = %d\n", pid); /* pidを出力. */

  /* 子プロセスの生成 */
  result = fork(); /* forkで子プロセスを生成し, 戻り値をresultに格納. */
  if (result < 0){ /* 失敗 */

    /* エラー処理 */
    printf("fork error!\n"); /* "fork error!"と出力. */
    return -1; /* -1を返して異常終了. */

  }
  else if (result == 0){ /* 子プロセス */

    /* 自分が子プロセスならgetpidでプロセスIDを取得. */
    child = getpid(); /* getpidの戻り値をchildに格納. */
    /* 1秒ごとに出力. */
    for (i = 0; i < 10; i++){ /* 10回繰り返す. */
      printf("I am child, child = %d\n", child); /* "I am child"とchildの値を出力. */
      sleep(1); /* 1秒休止. */
    }

  }
  else{ /* 親プロセス */

    /* 親プロセスならresultをchildに代入. */
    child = result; /* resultが子プロセスのID. */
    /* 1秒ごとに出力. */
    for (i = 0; i < 10; i++){ /* 10回繰り返す. */
      if (i == 5){ /* iが5の時, 子プロセスにSIGKILLを送信. */
        if (kill(child, SIGKILL) == -1){ /* killに失敗. */
          printf("kill error!\n"); /* "kill error!"と出力. */
        }
        else{ /* killに成功. */
          printf("kill child = %d success!\n", child); /* killしたchildを出力. */
        }
      }
      printf("I am parent, pid = %d, child = %d\n", pid, child); /* "I am parent"とpidとchildの値を出力. */
      sleep(1); /* 1秒休止. */
    }

  }

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
