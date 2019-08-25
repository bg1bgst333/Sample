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
  int i; /* ループ用変数i */

  /* シリアルポートを開く. */
  fd = open("/dev/ttyS0", O_RDWR); /* openで"/dev/ttyS0"を開く. */
  if (fd < 0){ /* 負の値なら失敗. */
    perror("open error"); /* perrorで"open error"と出力. */
    return -1; /* 異常終了 */
  }

  /* シリアル通信設定 */
  memset(&old, 0, sizeof(struct termios)); /* memsetでoldを初期化. */
  ioctl(fd, TCGETS, &old); /* oldに古い端末情報を格納. */
  printf("old.c_iflag = %08o\n", old.c_iflag); /* old.c_iflagを8進数出力. */
  printf("old.c_oflag = %08o\n", old.c_oflag); /* old.c_oflagを8進数出力. */
  printf("old.c_cflag = %08o\n", old.c_cflag); /* old.c_cflagを8進数出力. */
  printf("old.c_lflag = %08o\n", old.c_lflag); /* old.c_lflagを8進数出力. */
  for (i = 0; i < NCCS; i++){ /* NCCS分繰り返す. */
    printf("old.c_cc[%d] = %d\n", i, old.c_cc[i]); /* old.c_cc[i]を出力. */
  }
  memset(&tty, 0, sizeof(struct termios)); /* memsetでttyを初期化. */
  tty.c_cflag |= CREAD; /* 受信の有効 */
  tty.c_cflag |= CLOCAL; /* モデム制御の無視 */
  tty.c_cflag |= CS8; /* データビットは8bit. */
  cfsetospeed(&tty, B115200); /* 出力スピード115200 */
  cfsetispeed(&tty, B115200); /* 入力スピード115200 */
  tcsetattr(fd, TCSANOW, &tty); /* 即時に変更が有効となる. */
  ioctl(fd, TCSETS, &tty); /* 設定の反映 */
  printf("tty.c_iflag = %08o\n", tty.c_iflag); /* tty.c_iflagを8進数出力. */
  printf("tty.c_oflag = %08o\n", tty.c_oflag); /* tty.c_oflagを8進数出力. */
  printf("tty.c_cflag = %08o\n", tty.c_cflag); /* tty.c_cflagを8進数出力. */
  printf("tty.c_lflag = %08o\n", tty.c_lflag); /* tty.c_lflagを8進数出力. */
  for (i = 0; i < NCCS; i++){ /* NCCS分繰り返す. */
    printf("tty.c_cc[%d] = %d\n", i, tty.c_cc[i]); /* tty.c_cc[i]を出力. */
  }

  /* 受信ループ */ 
  while (1){ /* 無限ループ */
    len = read(fd, buf, sizeof(buf)); /* 読み込んでbufに格納. */
    if (len > 0){ /* 0より大きい. */
      printf("buf = [%s]\n", buf); /* bufを出力. */
      if (strcmp(buf, "q") == 0){ /* qが来たら. */
        break; /* 抜ける. */
      }
    }
  }

  /* シリアルポートを閉じる. */
  ioctl(fd, TCSETS, &old); /* 古い端末情報に戻す. */
  close(fd); /* closeでfdを閉じる. */

  /* プログラムの終了 */
  return 0; /* 正常終了 */

}
