/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <sys/ioctl.h> /* 入出力制御 */
#include <termios.h> /* 端末入出力 */

/* main関数 */
int main(void){

  /* 配列, 構造体の初期化 */
  char buf[256] = {0}; /* bufを{0}で初期化. */
  struct termios tty = {0}; /* ttyを{0}で初期化. */

  /* bufの入力 */
  scanf("%s", buf); /* bufの入力 */

  /* 端末属性を取得. */
  if (ioctl(0, TCGETS, &tty) == -1){ /* 標準入力の端末情報取得失敗 */

    /* エラー出力で"failure"と出力. */
    fprintf(stderr, "failure\n"); /* "failure"と標準エラー出力でエラー出力. */

    /* bufの出力 */
    printf("buf = %s\n", buf); /* bufを出力 */

    /* プログラムの終了 */
    return -1; /* 異常終了 */

  }
  else{ /* 成功 */

    /* "success"と出力. */
    printf("success\n"); /* "success"と出力. */

    /* bufの出力 */
    printf("buf = %s\n", buf); /* bufを出力 */

    /* プログラムの終了 */
    return 0; /* 正常終了 */

  }

}
