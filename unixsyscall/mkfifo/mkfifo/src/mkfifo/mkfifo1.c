/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */
#include <unistd.h> /* UNIX標準 */
#include <sys/types.h> /* 派生型 */
#include <sys/stat.h> /* ファイル状態 */
#include <sys/fcntl.h> /* ファイル制御 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言・初期化. */
  int fd[2]; /* int型ファイルディスクリプタ配列fd.(要素数2) */
  char buf[256]; /* 入力バッファ. */
  char *msg = "I am mkfifo1!"; /* 出力メッセージ"I am mkfifo1!". */

  /* 名前付きパイプTEST1の作成(FIFO)の作成. */
  if (mkfifo("TEST1", 0666) == -1){ /* -1なら失敗. */

    /* エラー出力. */
    printf("mkfifo error!\n"); /* "mkfifo error!"と出力. */
    return -1; /* -1を返して終了. */

  }

  /* 名前付きパイプTEST2の作成(FIFO)の作成. */
  if (mkfifo("TEST2", 0666) == -1){ /* -1なら失敗. */

    /* エラー出力. */
    printf("mkfifo error!\n"); /* "mkfifo error!"と出力. */
    return -2; /* -2を返して終了. */

  }

  /* 3秒待つ. */
  sleep(3); /* sleepで3秒待つ. */

  /* 書き込み用パイプを開く. */
  printf("mkfifo1 fd[1]: %s\n", msg); /* 書き込むmsgを出力. */
  if ((fd[1] = open("TEST1", O_WRONLY)) == -1){ /* -1なら失敗. */

    /* エラー出力. */
    printf("open error!\n"); /* "open error!"と出力. */
    return -3; /* -3を返して終了. */

  }

  /* TEST1にmsgを書き込む. */
  write(fd[1], msg, strlen(msg)); /* writeでmsgをfd[1]に書き込む. */

  /* 閉じる. */
  close(fd[1]); /* fd[1]を閉じる. */

  /* 9秒待つ. */
  sleep(9); /* sleepで9秒待つ. */

  /* 読み込み用パイプを開く. */
  if ((fd[0] = open("TEST2", O_RDONLY)) == -1){ /* -1なら失敗. */

    /* エラー出力. */
    printf("open error!\n"); /* "open error!"と出力. */
    return -4; /* -4を返して終了. */

  }

  /* TEST2から読み込んでbufに格納. */
  memset(buf, 0, sizeof(buf)); /* bufを0で埋める. */
  read(fd[0], buf, sizeof(buf)); /* readでbufにfd[0]から読み込む. */
  printf("mkfifo1 fd[0]: %s\n", buf); /* 読み込んだbufを出力. */

  /* 閉じる. */
  close(fd[0]); /* fd[0]を閉じる. */

  /* プログラムの終了 */
  return 0;

}
