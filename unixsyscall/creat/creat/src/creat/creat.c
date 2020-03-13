/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <unistd.h> /* UNIX標準 */
#include <sys/types.h> /* 派生型 */
#include <sys/stat.h> /* ファイル状態 */
#include <fcntl.h> /* ファイル制御 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  int fd1; /* ファイルディスクリプタfd1 */
  int fd2; /* ファイルディスクリプタfd2 */
  int fd3; /* ファイルディスクリプタfd3 */
  char buf[32]; /* サイズ32のchar型配列バッファbuf. */

  /* ファイルを作成し, 書き込み. */
  fd1 = open("test.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH); /* openで"test.txt"を作成し, 開く. */
  if (fd1 == -1){ /* -1の時はエラー. */

    /* エラー処理 */
    perror("open(1)"); /* "open(1)とエラー内容をエラー出力. */
    return -1; /* -1を返す. */

  }

  /* "ABCDE"を書き込む. */
  write(fd1, "ABCDE", 5); /* writeで"ABCDE"を書き込む. */

  /* 閉じる. */
  close(fd1); /* closeでfd1を閉じる. */

  /* ファイルを読み込み専用で開く. */
  fd2 = open("test.txt", O_RDONLY); /* openで"test.txt"を読み込み専用で開く. */
  if (fd2 == -1){ /* -1の時はエラー. */

    /* エラー処理 */
    perror("open(2)"); /* "open(2)とエラー内容をエラー出力. */
    return -2; /* -2を返す. */

  }

  /* "ABCDE"を読み込む. */
  read(fd2, buf, 32); /* readで"ABCDE"を読み込む. */

  /* bufを出力. */
  printf("buf = %s\n", buf); /* printfでbufを出力. */

  /* 閉じる. */
  close(fd2); /* closeでfd2を閉じる. */

  /* ファイルの上書き保存. */
  fd3 = creat("test.txt", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH); /* creatで"test.txt"を開く. */
  if (fd3 == -1){ /* -1の時はエラー. */

    /* エラー処理 */
    perror("creat"); /* "creatとエラー内容をエラー出力. */
    return -3; /* -3を返す. */

  }

  /* "XYZ"を書き込む. */
  write(fd3, "XYZ", 3); /* writeで"XYZ"を書き込む. */

  /* 閉じる. */
  close(fd3); /* closeでfd3を閉じる. */

  /* プログラムの終了 */
  return 0; /* 0を返す. */

}
