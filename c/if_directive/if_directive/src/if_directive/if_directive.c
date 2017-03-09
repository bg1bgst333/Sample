/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* マクロの定義 */
#define SWITCH 1

/* main関数の定義 */
int main(void){

/* SWITCHが真ならコンパイル対象になるので実行される. */
#if SWITCH

  /* "Switch On"と出力 */
  printf("Switch On\n"); /* printfで"Switch On"と出力. */
  
#endif

  /* "ABCDE"と出力 */
  printf("ABCDE\n"); /* printfで"ABCDE"と出力. */

  /* プログラムの終了 */
  return 0;

}
