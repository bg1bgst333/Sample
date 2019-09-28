/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <unistd.h> /* UNIX標準 */
#include <sys/types.h> /* 派生型 */
#include <sys/stat.h> /* ファイル状態 */
#include <fcntl.h> /* ファイル制御 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  int oldfd; /* 古いファイルディスクリプタoldfd */
  int newfd; /* 新しいファイルディスクリプタnewfd */

  /* ファイルtest.txtを追加書き込みモードで開く. */
  oldfd = open("test.txt", O_RDWR | O_CREAT | O_APPEND); /* "test.txt"をO_APPENDで開いて, ファイルディスクリプタをoldfdに格納. */
  printf("oldfd = %d\n", oldfd); /* oldfdを出力. */
  if (oldfd < 0){ /* 失敗 */
    return -1; /* -1を返して異常終了. */
  }

  /* "ABC"を書き込み. */
  write(oldfd, "ABC", 3); /* writeで"ABC"を書き込む. */

  /* ファイルディスクリプタを複製. */
  newfd = dup(oldfd); /* dupでoldfdを複製し, 複製したファイルディスクリプタをnewfdに格納. */
  printf("newfd = %d\n", newfd); /* newfdを出力. */
  if (newfd < 0){ /* 失敗 */
    close(oldfd); /* oldfdを閉じる. */
    return -2; /* -2を返して異常終了. */
  }

  /* "DEF"を書き込み. */
  write(newfd, "DEF", 3); /* writeで"DEF"を書き込む. */

  /* "test.txt"を閉じる. */
  close(newfd); /* newfdを閉じる. */
  close(oldfd); /* oldfdを閉じる. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
