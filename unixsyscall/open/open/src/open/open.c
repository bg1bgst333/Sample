/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <unistd.h> /* UNIX標準 */
#include <sys/types.h> /* 派生型 */
#include <sys/stat.h> /* ファイル状態 */
#include <fcntl.h> /* ファイル制御 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  int fd; /* ファイルディスクリプタfd */

  /* 低水準ファイル入力 */
  fd = open("test.txt", O_RDONLY); /* openで"test.txt"を読込専用(O_RDONLY)で開く. */
  if (fd == -1){ /* -1の時はエラー. */

    /* エラー処理 */
    printf("open error!\n"); /* "open error!"と出力. */
    return -1; /* -1を返す. */

  }

  /* ファイルディスクリプタの出力 */
  printf("fd = %d\n", fd); /* printfでfdの値を出力. */

  /* ファイルディスクリプタを閉じる. */
  close(fd); /* closeでfdを閉じる. */

  /* プログラムの終了 */
  return 0;
  
}
