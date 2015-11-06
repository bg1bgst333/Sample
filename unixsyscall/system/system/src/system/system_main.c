/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <stdlib.h> /* 標準ユーティリティ */
#include <sys/types.h> /* 派生型 */
#include <unistd.h> /* UNIX標準 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  pid_t pid; /* getpidでプロセスIDを取得し, pidに格納. */

  /* プロセスIDの取得 */
  pid = getpid(); /* getpidでプロセスIDを取得し, pidに格納. */
  printf("pid = %d\n", pid); /* printfでpidを出力. */

  /* 1分間(60秒間)待つ. */
  sleep(60); /* sleepで60秒間休止. */

  /* systemを呼ぶ直前. */
  printf("system before.\n"); /* "system before."を出力する. */

  /* プロセスの実行. */
  system("./system_sub 123 abc xyz"); /* systemで"./system_sub"を引数"123", "abb", "xyz"として実行.(systemにより, system_mainのプロセスとは別にsystem_subのプロセスが生成される.) */

  /* 1分間(60秒間)待つ. */
  sleep(60); /* sleepで60秒間休止. */

  /* プログラムの終了 */
  return 0;

}
