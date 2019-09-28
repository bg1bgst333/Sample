/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <unistd.h> /* UNIX標準 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  int result; /* symlinkの戻り値result. */

  /* シンボリックリンクを作成する. */
  result = symlink("test1/test1.txt", "test1_symlink"); /* symlinkで"test1/test1.txt"のシンボリックリンクを"test1_symlink"に作成. */
  if (result == 0){ /* 成功 */
    printf("create test1_symlink success!\n"); /* "create test1_symlink success!"と出力. */
    return 0; /* 0を返して正常終了. */
  }
  else{ /* 失敗 */
    printf("create test1_symlink failed!\n"); /* "create test1_symlink failed!"と出力. */
    perror("symlink"); /* perrorで"link"のエラー出力. */
    return -1; /* -1を返して異常終了. */
  }

}
