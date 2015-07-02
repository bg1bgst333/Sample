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

  /* 高水準入出力関数で使われるバッファサイズを出力. */
  printf("BUFSIZ = %d\n", BUFSIZ); /* printfでBUFSIZの値を出力. */

  /* ファイルtest_1.txtを開く. */
  fd = open("test_1.txt", O_WRONLY); /* openで"test_1.txt"をO_WRONLYで開く. */
  if (fd == -1){ /* -1の時はエラー. */

    /* エラー処理 */
    printf("open error!\n"); /* "open error!"と出力. */
    return -1; /* -1を返す. */

  }

  /* 書込開始 */
  printf("write start\n"); /* "write start"と出力. */

  /* test_1.txtに"ABCD"4バイトを2048回書きこむ.(4 * 2048 = 8192でBUFSIZと同じ.) */
  for (i = 0; i < 2048; i++){ /* 2048回繰り返す. */

    /* 4バイト書きこむ. */
    write(fd, "ABCD", 4); /* writeで4バイトずつtest_1.txtに書きこむ.(純粋にwriteだけ呼びたいので出力とかはしない.) */

  }

  /* 書込終了 */
  printf("write end\n"); /* "write end"と出力. */

  /* 閉じる */
  close(fd); /* closeでfdを閉じる. */

  /* プログラムの終了 */
  return 0;

}
