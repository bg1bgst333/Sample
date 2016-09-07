/* ヘッダファイルのインクルード */
/* 独自のヘッダファイル */
#include "test.h" /* #include文で関数funcが宣言されているtest.hを("")で括った場合はこのソースの位置から探して取り込む. */
/* 既定のヘッダファイル */
#include <stdio.h> /* #include文で標準関printfが宣言されているstdio.hを(<>)で括った場合はシステムのインクルードパス(/usr/includeなど)の位置から探して取り込む. */

/* main関数の定義 */
int main(void){

  /* funcを呼ぶ. */
  func(); /* funcを呼ぶ. */

  /* printfを呼ぶ. */
  printf("main\n"); /* printfで"main"を出力. */

  /* プログラムの終了 */
  return 0;

}
