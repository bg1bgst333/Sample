/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <time.h> /* UNIX時間 */

/* main関数の定義 */
int main(void){

  /* 変数, 構造体, 配列の初期化 */
  time_t t; /* 取得したUNIX時間を格納しておくtime_t型変数t. */
  struct tm *tm_ptr; /* 時刻情報を格納するtm構造体ポインタtm_ptr. */
  char wday_str[7][4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"}; /* 2次元配列wday_strを曜日文字列で初期化. */

  /* 現在のUNIX時間の取得. */
  t = time(NULL); /* timeで現在のUNIX時間を取得. */

  /* UNIX時間をローカル時刻情報に変換. */
  tm_ptr = localtime(&t); /* localtimeで指定されたUNIX時間をローカル時刻情報に変換, tm構造体ポインタtm_ptrとして返ってくる. */
  printf("%d/%d/%d(%s) %d:%02d:%02d\n", tm_ptr->tm_year + 1900, tm_ptr->tm_mon + 1, tm_ptr->tm_mday, wday_str[tm_ptr->tm_wday], tm_ptr->tm_hour, tm_ptr->tm_min, tm_ptr->tm_sec); /* tm_ptrの内容を時刻文字列形式で出力. */

  /* プログラムの終了 */
  return 0;

}
