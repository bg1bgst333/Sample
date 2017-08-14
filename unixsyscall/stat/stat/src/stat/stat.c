/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <unistd.h> /* UNIX標準 */
#include <sys/types.h> /* 派生型 */
#include <sys/stat.h> /* ファイル状態 */

/* main関数 */
int main(void){

  /* 構造体の宣言 */
  struct stat sst; /* stat構造体変数sst. */

  /* ファイル情報を取得. */
  if (stat("test.txt", &sst) == 0){ /* statで"test.txt"のファイル情報を取得し, sstに格納.(0なら成功.) */

    /* 取得できたら, ファイルサイズを出力. */
    printf("sst.st_size = %d\n", sst.st_size); /* sst.st_sizeを出力. */

  }

  /* プログラムの終了. */
  return 0; /* 0を返して正常終了. */

}
