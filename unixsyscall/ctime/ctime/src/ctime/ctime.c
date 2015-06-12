/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <time.h> /* UNIX時間 */

/* main関数の定義 */
int main(void){

  /* 変数・構造体の宣言 */
  time_t t; /* 取得したUNIX時間を格納しておくtime_t型変数t. */
  char *str; /* 時刻文字列へのポインタstr. */

  /* 現在のUNIX時間の取得. */
  t = time(NULL); /* timeで現在のUNIX時間を取得. */

  /* UNIX時間を時刻文字列に変換. */
  str = ctime(&t); /* ctimeでUNIX時間tを時刻文字列に変換, それを返す. */

  /* 時刻文字列の出力. */
  printf("%s", str); /* printfで時刻文字列strを出力.(改行は既に付いているので不要.) */

  /* プログラムの終了 */
  return 0;

}
