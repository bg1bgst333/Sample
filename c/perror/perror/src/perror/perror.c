/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数 */
int main(void){

  /* 変数の宣言 */
  FILE *fp; /* ファイルポインタfp */

  /* 存在しないファイルを開く.(わざと失敗する.) */
  fp = fopen("test.txt", "r"); /* fopenで"test.txt"を開く. */
  if (fp == NULL){ /* NULLなら. */

    /* 標準エラー出力にエラーメッセージを出力. */
    perror("fopen error!"); /* perrorで"fopen error!"と出力.(その後, 詳細なエラーメッセージも付加される.) */
    return -1; /* -1を返して異常終了. */

  }

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
