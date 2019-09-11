/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <unistd.h> /* UNIX標準 */
#include <signal.h> /* シグナル */

/* シグナルハンドラhandlerの定義 */
void handler(int sig){

  /* 受け取ったシグナル定数を出力. */
  printf("sig = %d\n", sig); /* sigを出力. */
  if (sig == SIGALRM){ /* sigがSIGALRMなら. */
    printf("This is SIGALRM!\n"); /* "This is SIGALRM!"と出力. */
  }

}
 
/* main関数の定義 */
int main(){

  /* 変数の宣言 */
  int i; /* ループ用変数i. */

  /* SIGALRMに対するシグナルハンドラをセット. */
  signal(SIGALRM, handler); /* signalでSIGALRMにhandlerをセット. */
  alarm(3); /* 3秒経過したらSIGALRM発生. */
  for (i = 0; i < 10; i++){ /* 10回繰り返す. */
    printf("process running...(signal(SIGALRM, handler))\n"); /* "process running...(signal(SIGALRM, handler))"を出力. */
    sleep(1); /* 1秒休止. */
  }

  /* プログラムの終了. */
  return 0; /* 0を返して正常終了. */

}
