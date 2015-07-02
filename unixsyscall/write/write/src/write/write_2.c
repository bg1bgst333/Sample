/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <unistd.h> /* UNIX標準 */
#include <sys/types.h> /* 派生型 */
#include <sys/stat.h> /* ファイル状態 */
#include <fcntl.h> /* ファイル制御 */
#include <string.h> /* 文字列 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  int fd; /* ファイルディスクリプタfd */
  char buf[819200]; /* サイズ819200のバッファを用意. */

  /* 高水準入出力関数で使われるバッファサイズを出力. */
  printf("BUFSIZ = %d\n", BUFSIZ); /* printfでBUFSIZの値を出力. */

  /* ファイルtest_2.txtを開く. */
  fd = open("test_2.txt", O_WRONLY); /* openで"test_2.txt"をO_WRONLYで開く. */
  if (fd == -1){ /* -1の時はエラー. */

    /* エラー処理 */
    printf("open error!\n"); /* "open error!"と出力. */
    return -1; /* -1を返す. */

  }

  /* 書込開始 */
  printf("write start\n"); /* "write start"と出力. */

  /* 'A'を819200個セット. */
  memset(buf, 'A', 819200); /* memsetで819200個の'A'をセット. */

  /* 819200バイト一気に書きこむ. */
  write(fd, buf, 819200); /* writeで819200バイト一気に書きこむ.(純粋にwriteだけ呼びたいので出力とかはしない.) */

  /* 書込終了 */
  printf("write end\n"); /* "write end"と出力. */

  /* 閉じる */
  close(fd); /* closeでfdを閉じる. */

  /* プログラムの終了 */
  return 0;

}
