/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <unistd.h> /* UNIX標準 */

/* main関数 */
int main(void){

  /* 変数の宣言 */
  int ret; /* linkの戻り値ret. */

  /* ハードリンクを作成する. */
  ret = link("test1/test1.txt", "test1_hlnk"); /* linkで"test1/test1.txt"のハードリンクを"test1_hlnk"に作成. */
  if (ret == 0){ /* 成功 */
    printf("create test1_hlnk success!\n"); /* "create test1_hlnk success!"と出力. */
    return 0; /* 0を返して正常終了. */
  }
  else{ /* 失敗 */
    printf("create test1_hlnk failed!\n"); /* "create test1_hlnk failed!"と出力. */
    perror("link"); /* perrorで"link"のエラー出力. */
    return -1; /* -1を返して異常終了. */
  }

}
