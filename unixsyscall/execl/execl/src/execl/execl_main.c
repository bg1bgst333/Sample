/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
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

  /* execlを呼ぶ直前. */
  printf("execl before.\n"); /* "execl before."を出力する. */

  /* プロセスの実行. */
  execl("./execl_sub", "./execl_sub", "123", "abc", "xyz", NULL); /* execlで"./execl_sub"を引数"123", "abc", "xyz"として実行.(execlにより, execl_mainのプロセスはexecl_subのプロセスに置換される.) */

  /* execlの後は実行されない. */
  printf("execl after.\n"); /* "execl after."は出力されない. */

  /* プログラムの終了 */
  return 0;

}
