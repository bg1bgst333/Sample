/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <unistd.h> /* UNIX標準 */
#include <sys/types.h> /* 派生型 */
#include <sys/stat.h> /* ファイル状態 */
#include <fcntl.h> /* ファイル制御 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  int result; /* mknodの戻り値result. */

  /* mknodで空のファイルを作成. */
  result = mknod("test.txt", S_IFREG | S_IRWXU | S_IRWXG | S_IRWXO, 0); /* mknodで"test.txt"を作成. */
  if (result == 0){ /* 成功 */
    printf("create test.txt success!\n"); /* "create test.txt success!"と出力. */
  }
  else{ /* 失敗 */
    printf("create test.txt failed!\n"); /* "create test.txt failed!"と出力. */
  }

  /* mknodで名前付きパイプを作成. */
  result = mknod("TEST1", S_IFIFO | S_IRWXU | S_IRWXG | S_IRWXO, 0); /* mknodで"TEST1"を作成. */
  if (result == 0){ /* 成功 */
    printf("create TEST1 success!\n"); /* "create TEST1 success!"と出力. */
  }
  else{ /* 失敗 */
    printf("create TEST1 failed!\n"); /* "create TEST1 failed!"と出力. */
  }

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
