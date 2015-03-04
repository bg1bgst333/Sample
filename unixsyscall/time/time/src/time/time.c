/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <time.h> /* UNIX時間 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  time_t t; /* 取得したUNIX時間を格納しておくtime_t型変数t. */

  /* 現在のUNIX時間の取得と出力. */
  t = time(NULL); /* timeの引数にNULLを指定すると, 戻り値として現在のUNIX時間が返る. */
  printf("UNIX Time: %ld\n", t); /* printfでtを"%ld"で出力. */

  /* プログラムの終了 */
  return 0;

}
