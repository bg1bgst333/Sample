/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <time.h> /* UNIX時間 */

/* main関数の定義 */
int main(void){

  /* 変数・の定義 */
  time_t t; /* 取得したUNIX時間を格納しておくtime_t型変数t. */
  struct tm *tm_ptr; /* 時刻情報を格納するtm構造体ポインタtm_ptr. */

  /* 現在のUNIX時間の取得. */
  t = time(NULL); /* timeで現在のUNIX時間を取得. */

  /* UNIX時間をローカル時刻情報(日本の場合はJST(日本標準時))に変換. */
  tm_ptr = localtime(&t); /* localtimeで指定されたUNIX時間をローカル時刻情報(JST(日本標準時))に変換, tm構造体ポインタtm_ptrとして返ってくる. */

  /* ローカル時刻(JST)の現在時刻を出力. */
  printf("[JST] %d/%d/%d %d:%02d:%02d\n", tm_ptr->tm_year + 1900, tm_ptr->tm_mon + 1, tm_ptr->tm_mday, tm_ptr->tm_hour, tm_ptr->tm_min, tm_ptr->tm_sec); /* printfでtm_ptrの内容を時刻文字列形式で出力. */

  /* プログラムの終了 */
  return 0;

}
