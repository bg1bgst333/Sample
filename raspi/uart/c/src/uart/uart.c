/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */
#include <unistd.h> /* UNIX標準 */
#include <sys/types.h> /* 派生型 */
#include <sys/stat.h> /* ファイル状態 */
#include <sys/ioctl.h> /* 入出力制御 */
#include <fcntl.h> /* ファイル制御 */
#include <termios.h> /* 端末入出力 */

/* main関数 */
int main(void){

  /* 変数の宣言 */
  char buf[256]; /* バッファbuf(長さ256) */
  int fd; /* ファイルディスクリプタfd */
  struct termios tty; /* 端末情報tty */
  struct termios old; /* 古い端末情報old */
  int len; /* 読み込んだ長さlen. */

  /* シリアルポートを開く. */
  fd = open("/dev/ttyAMA0", O_RDWR); /* openで"/dev/ttyAMA0"を開く. */
  if (fd < 0){ /* 負の値なら失敗. */
    perror("open error"); /* perrorで"open error"と出力. */
    return -1; /* 異常終了 */
  }

  /* シリアル通信設定 */
  memset(&old, 0, sizeof(struct termios)); /* memsetでoldを初期化. */
  ioctl(fd, TCGETS, &old); /* oldに古い端末情報を格納. */
  memset(&tty, 0, sizeof(struct termios)); /* memsetでttyを初期化. */
  tty.c_cflag |= CREAD; /* 受信の有効 */
  tty.c_cflag |= CLOCAL; /* モデム制御の無視 */
  tty.c_cflag |= CS8; /* データビットは8bit. */
  cfsetospeed(&tty, B115200); /* 出力スピード115200 */
  cfsetispeed(&tty, B115200); /* 入力スピード115200 */
  tcsetattr(fd, TCSANOW, &tty); /* 即時に変更が有効となる. */
  ioctl(fd, TCSETS, &tty); /* 設定の反映 */

  /* 受信ループ */
  while (1){ /* 無限ループ */
    len = read(fd, buf, sizeof(buf)); /* 読み込んでbufに格納. */
    if (len > 0){ /* 0より大きい. */
      printf("buf = [%s]\n", buf); /* bufを出力. */
      if (strcmp(buf, "q") == 0){ /* "q"が来たら. */
        break;
      }
    }
  }

  /* シリアルポートを閉じる. */
  ioctl(fd, TCSETS, &old); /* 古い端末情報に戻す. */
  close(fd); /* closeでfdを閉じる. */

  /* プログラムの終了 */
  return 0; /* 正常終了 */

}
