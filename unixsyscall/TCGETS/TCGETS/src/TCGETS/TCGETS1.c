/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <sys/ioctl.h> /* 入出力制御 */
#include <termios.h> /* 端末入出力 */

/* main関数 */
int main(void){

  /* 構造体の初期化 */
  struct termios tty = {0}; /* ttyを{0}で初期化. */

  /* "ABCDE"の出力 */
  printf("ABCDE\n"); /* "ABCDE"の出力 */

  /* 端末属性を取得. */
  if (ioctl(1, TCGETS, &tty) == -1){ /* 標準出力の端末情報取得失敗 */

    /* エラー出力で"failure"と出力. */
    fprintf(stderr, "failure\n"); /* "failure"と標準エラー出力でエラー出力. */

    /* プログラムの終了 */
    return -1; /* 異常終了 */

  }
  else{ /* 成功 */

    /* "success"の出力 */
    printf("success\n"); /* "success"を出力. */

    /* プログラムの終了 */
    return 0; /* 正常終了 */

  }

}
