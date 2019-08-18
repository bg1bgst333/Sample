/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */
#include <errno.h> /* errno */

/* main関数 */
int main(void){

  /* 変数の宣言 */
  FILE *fp; /* ファイルポインタfp */

  /* errnoの出力 */
  printf("errno = %d\n", errno); /* errnoの出力 */

  /* 存在しないファイルを開く.(わざと失敗する.) */
  fp = fopen("test.txt", "r"); /* fopenで"test.txt"を開く. */
  if (fp == NULL){ /* NULLなら. */

    /* errnoの出力 */
    printf("errno = %d\n", errno); /* errnoの出力 */

    /* strerrorで出力 */
    printf("strerror(errno) = %s\n", strerror(errno)); /* strerrorでエラーメッセージを出力. */

    /* 標準エラー出力にエラーメッセージを出力. */
    perror("fopen error!"); /* perrorで"fopen error!"と出力.(その後, 詳細なエラーメッセージも付加される.) */

    /* 異常終了 */
    return -1; /* -1を返して異常終了. */

  }

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
