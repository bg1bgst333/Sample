/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <sys/types.h> /* 派生型 */
#include <unistd.h> /* UNIX標準 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  pid_t pid; /* プロセスIDを格納するpid_t型変数pid. */

  /* プロセスIDの取得 */
  pid = getpid(); /* getpidでプロセスIDを取得し, pidに格納. */
  printf("pid = %d\n", pid); /* printfでpidを出力. */

  /* 1分間(60秒間)待つ. */
  sleep(60); /* sleepで60秒間休止. */

  /* プログラムの終了 */
  return 0;

}
