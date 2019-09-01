/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <unistd.h> /* UNIX標準 */
#include <sys/types.h> /* 派生型 */
#include <sys/stat.h> /* ファイル状態 */
#include <fcntl.h> /* ファイル制御 */ 

/* main関数 */
int main(void){

  /* 変数の初期化 */
  int fd = 0; /* ファイルディスクリプタfdを0で初期化. */
  int len = 0; /* 長さlenを0で初期化. */

  /* GPIO2のエクスポート */
  fd = open("/sys/class/gpio/export", O_WRONLY); /* "/sys/class/gpio/export"を開く. */
  if (fd < 0){ /* 0以下なら失敗. */
    perror("export error"); /* perrorで"export error"と出力. */
    return -1; /* -1を返して異常終了. */
  }
  len = write(fd, "2", 2); /* "2"を書き込む. */
  if (len > 0){ /* 書き込めたら成功. */
    printf("export ok!\n"); /* "export ok!"と出力. */
  }
  close(fd); /* fdを閉じる. */

  /* 0.1秒待つ. */
  usleep(100000); /* 0.1秒は100000マイクロ秒. */

  /* GPIO2のディレクション */
  fd = open("/sys/class/gpio/gpio2/direction", O_WRONLY); /* "/sys/class/gpio/gpio2/direction"を開く. */
  if (fd < 0){ /* 0以下なら失敗. */
    perror("direction error"); /* perrorで"direction error"と出力. */
    return -1; /* -1を返して異常終了. */
  }
  len = write(fd, "out", 4); /* "out"を書き込む. */
  if (len > 0){ /* 書き込めたら成功. */
    printf("direction ok!\n"); /* "direction ok!"と出力. */
  }
  close(fd); /* fdを閉じる. */

  /* GPIO2のON/OFF */
  fd = open("/sys/class/gpio/gpio2/value", O_WRONLY); /* "/sys/class/gpio/gpio2/value"を開く. */
  if (fd < 0){ /* 0以下なら失敗. */
    perror("on/off error"); /* perrorで"on/off error"と出力. */
    return -1; /* -1を返して異常終了. */
  }
  len = write(fd, "1", 2); /* "1"を書き込む. */
  if (len > 0){ /* 書き込めたら成功. */
    printf("on ok!\n"); /* "on ok!"と出力. */
  }
  /* 1秒待つ. */
  usleep(1000000); /* 1秒は1000000マイクロ秒. */
  len = write(fd, "0", 2); /* "0"を書き込む. */
  if (len > 0){ /* 書き込めたら成功. */
    printf("off ok!\n"); /* "off ok!"と出力. */
  }
  /* 1秒待つ. */
  usleep(1000000); /* 1秒は1000000マイクロ秒. */
  len = write(fd, "1", 2); /* "1"を書き込む. */
  if (len > 0){ /* 書き込めたら成功. */
    printf("on ok!\n"); /* "on ok!"と出力. */
  }
  /* 1秒待つ. */
  usleep(1000000); /* 1秒は1000000マイクロ秒. */
  len = write(fd, "0", 2); /* "0"を書き込む. */
  if (len > 0){ /* 書き込めたら成功. */
    printf("off ok!\n"); /* "off ok!"と出力. */
  }
  close(fd); /* fdを閉じる. */

  /* GPIO2のアンエクスポート */
  fd = open("/sys/class/gpio/unexport", O_WRONLY); /* "/sys/class/gpio/unexport"を開く. */
  if (fd < 0){ /* 0以下なら失敗. */
    perror("unexport error"); /* perrorで"unexport error"と出力. */
    return -1; /* -1を返して異常終了. */
  }
  len = write(fd, "2", 2); /* "2"を書き込む. */
  if (len > 0){ /* 書き込めたら成功. */
    printf("unexport ok!\n"); /* "unexport ok!"と出力. */
  }
  close(fd); /* fdを閉じる. */

  /* プログラムの終了. */
  return 0; /* 0 を返して正常終了. */

}
