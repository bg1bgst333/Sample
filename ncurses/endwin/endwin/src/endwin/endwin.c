/* ヘッダファイルのインクルード */
#include <curses.h> /* curses */

/* main関数 */
int main(void){

  /* 画面の初期化 */
  initscr(); /* initscrで画面の初期化. */

  /* ウィンドウモードの終了 */
  endwin(); /* endwinでウィンドウモードの終了. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
