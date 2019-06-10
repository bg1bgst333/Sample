/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <unistd.h> /* UNIX標準 */
#include <signal.h> /* シグナル */

/* シグナルハンドラhandlerの定義 */
void handler(int sig){

  /* 受け取ったシグナル定数を出力. */
  printf("sig = %d\n", sig); /* sigを出力. */

}
 
/* main関数の定義 */
int main(){

  /* 変数の宣言 */
  int i; /* ループ用変数i. */

  /* シグナルハンドラをセット. */
  signal(SIGINT, handler); /* signalでhandlerをセット. */
  for (i = 0; i < 10; i++){ /* 10回繰り返す. */
    printf("process running...(signal(SIGINT, handler))\n"); /* "process running...(signal(SIGINT, handler))"を出力. */
    sleep(1); /* 1秒休止. */
  }

  /* プログラムの終了. */
  return 0; /* 0を返して正常終了. */

}
