/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <time.h> /* UNIX時間 */

/* main関数の定義 */
int main(void){

  /* 変数・構造体の宣言 */
  time_t t; /* 取得したUNIX時間を格納しておくtime_t型変数t. */
  struct tm *tm_ptr; /* 時刻情報を格納するtm構造体ポインタtm_ptr. */
  char *str; /* 時刻文字列へのポインタstr. */

  /* 現在のUNIX時間の取得. */
  t = time(NULL); /* timeで現在のUNIX時間を取得. */

  /* UNIX時間をローカル時刻情報(日本の場合はJST(日本標準時))に変換. */
  tm_ptr = localtime(&t); /* localtimeで指定されたUNIX時間をローカル時刻情報(JST(日本標準時))に変換, tm構造体ポインタtm_ptrとして返ってくる. */

  /* ローカル時刻情報を時刻文字列に変換. */
  str = asctime(tm_ptr); /* asctimeでtm_ptrの指すローカル時刻情報を時刻文字列に変換, その文字列を返す. */

  /* 時刻文字列の出力. */
  printf("%s", str); /* printfで時刻文字列strを出力.(改行は既に付いているので不要.) */

  /* プログラムの終了 */
  return 0;

}

  


