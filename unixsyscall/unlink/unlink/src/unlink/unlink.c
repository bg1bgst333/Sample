/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <unistd.h> /* UNIX標準 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  int result; /* 削除結果を格納するint型変数result. */

  /* ファイルを削除. */
  result = unlink("test1.txt"); /* unlinkで"test1.txt"を削除. */
  if (result < 0){ /* 失敗 */
    printf("unlink test1.txt failed!\n"); /* "unlink test1.txt failed!"と出力. */
    return -1; /* -1を返して異常終了. */
  }
  else{ /* 成功 */
    printf("unlink test1.txt success!\n"); /* "unlink test1.txt success!"と出力. */
    return 0; /* 0を返して正常終了. */
  }

}
