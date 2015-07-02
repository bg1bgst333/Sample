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
  char buf[4]; /* サイズ4のchar型配列バッファbuf. */

  /* 高水準入出力関数で使われるバッファサイズを出力 */
  printf("BUFSIZ = %d\n", BUFSIZ); /* printfでBUFSIZの値を出力. */

  /* ファイルtest_1.txtを開く. */
  fd = open("test_1.txt", O_RDONLY); /* openで"test_1.txt"をO_RDONLYで開く. */
  if (fd == -1){ /* -1の時はエラー. */

    /* エラー処理 */
    printf("open error!\n"); /* "open error!"と出力. */
    return -1; /* -1を返す. */

  }

  /* 読込開始 */
  printf("read start\n"); /* "read start"と出力. */

  /* test_1.txt(サイズ8192バイト)の内容を読み込む. */
  for (i = 0; i < 2048; i++){ /* 4バイトずつ2048回読み込む.(4 * 2048 = 8192でBUFSIZと同じ.) */

    /* 4バイト読み込む. */
    read(fd, buf, 4); /* readで4バイトずつbufに読み込む.(純粋にreadだけ呼びたいので出力とかはしない.) */

  }

  /* 読込終了 */
  printf("read end\n"); /* "read end"と出力. */

  /* 閉じる */
  close(fd); /* closeでfdを閉じる. */

  /* プログラムの終了 */
  return 0;

}
