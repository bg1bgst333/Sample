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
int main(void){

  /* SIGALRMに対するシグナルハンドラをセット. */
  signal(SIGALRM, handler); /* signalでSIGALRMにhandlerをセット. */
  alarm(10); /* 10秒経過したらSIGALRM発生. */
  printf("pause before!\n"); /* "pause before!"を出力. */
  pause(); /* SIGALRMが発生するまで待つ. */
  printf("pause after!\n"); /* "pause after!"を出力. */

  /* プログラムの終了. */
  return 0; /* 0を返して正常終了. */

}
