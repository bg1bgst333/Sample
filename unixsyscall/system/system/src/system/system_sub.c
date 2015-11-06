/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <sys/types.h> /* 派生型 */
#include <unistd.h> /* UNIX標準 */

/* main関数の定義 */
int main(int argc, char *argv[]){

  /* 変数の宣言 */
  pid_t pid; /* プロセスIDを格納するpid_t型変数pid. */
  int i; /* ループ用変数i */

  /* プロセスIDの取得 */
  pid = getpid(); /* getpidでプロセスIDを取得し, pidに格納. */

  /* コマンドライン引数の出力. */
  for (i = 0; i < argc; i++){ /* argcの数繰り返す. */

    /* argvの出力. */
    printf("argv[%d] = %s\n", i, argv[i]); /* argvの各要素を出力. */

  }

  /* 1分間(60秒)待つ. */
  sleep(60); /* sleepで60秒間休止. */

  /* プログラムの終了. */
  return 0;

}
