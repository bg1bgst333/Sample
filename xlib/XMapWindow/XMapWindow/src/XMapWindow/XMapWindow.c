/* ヘッダファイルのインクルード */
#include <stdio.h> /* C標準入出力 */
#include <X11/Xlib.h> /* Xlib */

/* main関数 */
int main(void){

  /* 変数の宣言 */
  Display *d; /* Display構造体へのポインタd. */
  Window wr; /* ウィンドウ生成の結果を表す値wr.(Window == XID == unsigned long) */
  int result; /* マップの結果result. */

  /* Xサーバとの接続. */
  d = XOpenDisplay(NULL); /* XOpenDisplayでXサーバに接続し, 戻り値のアドレスをdに格納. */

  /* dを出力. */
  printf("d = %08x\n", d); /* dの値を16進数で出力. */

  /* ウィンドウの生成 */
  wr = XCreateSimpleWindow(d, RootWindow(d, 0), 100, 100, 640, 480, 1, 0, 0); /* XCreateSimpleWindowでウィンドウ生成し, 結果はwrに格納. */

  /* ウィンドウ生成の結果を出力. */
  printf("wr = %08x\n", wr); /* wrを出力. */

  /* ウィンドウのマッピング(表示要求) */
  result = XMapWindow(d, wr); /* XMapWindowでマッピング. */

  /* マッピング結果を出力. */
  printf("result = %d\n", result); /* resultの値を出力. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
