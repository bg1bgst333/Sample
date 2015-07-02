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
  int i; /* ループ用変数i */
  char buf[819200]; /* サイズ819200のchar型配列バッファbuf. */

  /* 高水準入出力関数で使われるバッファサイズを出力 */
  printf("BUFSIZ = %d\n", BUFSIZ); /* printfでBUFSIZの値を出力. */

  /* ファイルtest_2.txtを開く. */
  fd = open("test_2.txt", O_RDONLY); /* openで"test_2.txt"をO_RDONLYで開く. */
  if (fd == -1){ /* -1の時はエラー. */

    /* エラー処理 */
    printf("open error!\n"); /* "open error!"と出力. */
    return -1; /* -1を返す. */

  }

  /* 読込開始 */
  printf("read start\n"); /* "read start"と出力. */

  /* 819200バイト一気に読み込む. */
  read(fd, buf, 819200); /* readで819200バイト一気にbufに読み込む.(純粋にreadだけ呼びたいので出力とかはしない.) */

  /* 読込終了 */
  printf("read end\n"); /* "read end"と出力. */

  /* 閉じる */
  close(fd); /* closeでfdを閉じる. */

  /* プログラムの終了 */
  return 0;

}
