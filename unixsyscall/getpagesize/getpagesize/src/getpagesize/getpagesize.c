/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <unistd.h> /* UNIX標準 */

/* main関数 */
int main(void){

  /* 変数の宣言 */
  int page_size; /* メモリのページサイズpage_size. */

  /* メモリのページサイズを取得する. */
  page_size = getpagesize(); /* getpagesizeで取得したサイズをpage_sizeに格納. */

  /* ページサイズの出力. */
  printf("page_size = %d\n", page_size); /* page_sizeを出力. */

  /* プログラムの終了. */
  return 0; /* 0を返して正常終了. */

}
  
