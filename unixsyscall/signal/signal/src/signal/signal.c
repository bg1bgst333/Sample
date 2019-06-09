/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <unistd.h> /* UNIX標準 */
#include <signal.h> /* シグナル */

/* main関数の定義 */
int main(){

  /* 変数の宣言 */
  int i; /* ループ用変数i. */

  /* シグナルの無視. */
  signal(SIGINT, SIG_IGN); /* signalでシグナルSIGINTに対して無視する設定にする. */
  for (i = 0; i < 10; i++){ /* 10回繰り返す. */
    printf("process running...(signal(SIGINT, SIG_IGN))\n"); /* "process running...(signal(SIGINT, SIG_IGN))"を出力. */
    sleep(1); /* 1秒休止. */
  }

  /* シグナル処理をデフォルト動作に戻す. */
  signal(SIGINT, SIG_DFL); /* signalでシグナルSIGINTに対してデフォルト動作をする設定にする. */
  for (i = 0; i < 10; i++){ /* 10回繰り返す. */
    printf("process running...(signal(SIGINT, SIG_DFL))\n"); /* "process running...(signal(SIGINT, SIG_DFL))"を出力. */
    sleep(1); /* 1秒休止. */
  }

  /* プログラムの終了. */
  return 0; /* 0を返して正常終了. */

}
