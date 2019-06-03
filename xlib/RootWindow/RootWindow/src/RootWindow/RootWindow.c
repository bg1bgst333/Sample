/* ヘッダファイルのインクルード */
#include <stdio.h> /* C標準入出力 */
#include <unistd.h> /* UNIX標準 */
#include <X11/Xlib.h> /* Xlib */

/* main関数 */
int main(void){

  /* 変数の宣言 */
  Display *d; /* Display構造体へのポインタd. */
  Window wr; /* ウィンドウ生成の結果を表す値wr.(Window == XID == unsigned long) */
  int result; /* マップの結果result. */

  /* Xサーバとの接続. */
  d = XOpenDisplay(":1"); /* XOpenDisplayでXサーバに接続し, 戻り値のアドレスをdに格納.(ディスプレイの名前は":1".) */

  /* dを出力. */
  printf("d = %08x\n", d); /* dの値を16進数で出力. */

  /* ウィンドウの生成. */
  wr = XCreateSimpleWindow(d, RootWindow(d, 1), 100, 100, 640, 480, 1, 0xffffff, 0xffffff); /* XCreateSimpleWindowでウィンドウ生成し, 結果はwrに格納.(RootWindowでスクリーン1を指定.) */

  /* ウィンドウ生成の結果を出力. */
  printf("wr = %08x\n", wr); /* wrを出力. */

  /* ウィンドウのマッピング(表示要求) */
  result = XMapWindow(d, wr); /* XMapWindowでマッピング. */

  /* マッピング結果を出力. */
  printf("result = %d\n", result); /* resultの値を出力. */

  /* 表示要求イベントをフラッシュ. */
  XFlush(d); /* XFlushでフラッシュ. */

  /* 60秒待つ. */
  printf("sleep 60 seconds...\n"); /* "sleep 60 seconds..."と出力. */
  sleep(60); /* sleepで60秒休止. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
