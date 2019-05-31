/* ヘッダファイルのインクルード */
#include <stdio.h> /* C標準入出力 */
#include <X11/Xlib.h> /* Xlib */

/* main関数 */
int main(void){

  /* 変数の宣言 */
  Display *d; /* Display構造体へのポインタd. */

  /* Xサーバとの接続. */
  d = XOpenDisplay(NULL); /* XOpenDisplayでXサーバに接続し, 戻り値のアドレスをdに格納. */

  /* dを出力. */
  printf("d = %08x\n", d); /* dの値を16進数で出力. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
