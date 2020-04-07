/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <unistd.h> /* UNIX標準 */

/* main関数の定義 */
int main(void){

  /* 配列の初期化. */
  char *const cmdline[] = {"./execv_sub", "123", "abc", "xyz", NULL}; /* 配列cmdlineを初期化. */

  /* プロセスの実行. */
  execv("./execv_sub", cmdline); /* execvで"./execv_sub"を実行. */

  /* プログラムの終了. */
  return 0; /* 0を返して正常終了. */

}
