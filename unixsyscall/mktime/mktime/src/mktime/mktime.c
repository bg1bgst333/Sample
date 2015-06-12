/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <time.h> /* UNIX時間 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  time_t t1; /* timeで取得したUNIX時間を格納しておくtime_t型変数t1. */
  struct tm *tm_ptr; /* 時刻情報を格納するtm構造体ポインタtm_ptr. */
  char *str; /* 時刻文字列へのポインタstr. */
  struct tm stm; /* 時刻情報を格納するtm構造体変数stm. */
  time_t t2; /* mktimeで取得したUNIX時間を格納しておくtime_t型変数t2. */

  /* 現在のUNIX時間の取得. */
  t1 = time(NULL); /* timeの引数にNULLを指定すると, 戻り値として現在のUNIX時間が返る. */

  /* UNIX時間の出力 */
  printf("[UNIXTime]: %ld\n", t1); /* printfでt1を"%ld"で出力. */

  /* UNIX時間をローカル時刻情報(日本の場合はJST(日本標準時))に変換. */
  tm_ptr = localtime(&t1); /* localtimeで指定されたUNIX時間をローカル時刻情報(JST(日本標準時))に変換, tm構造体ポインタtm_ptrとして返ってくる. */

  /* ローカル時刻(JST)の現在時刻を出力. */
  printf("[JST]: %d/%d/%d %d:%02d:%02d\n", tm_ptr->tm_year + 1900, tm_ptr->tm_mon + 1, tm_ptr->tm_mday, tm_ptr->tm_hour, tm_ptr->tm_min, tm_ptr->tm_sec); /* printfでtm_ptrの内容を時刻文字列形式で出力. */

  /* ローカル時刻情報を時刻文字列に変換. */
  str = asctime(tm_ptr); /* asctimeでtm_ptrの指すローカル時刻情報を時刻文字列に変換, その文字列を返す. */

  /* 時刻文字列の出力. */
  printf("[TimeString]: %s", str); /* printfで時刻文字列strを出力.(改行は既に付いているので不要.) */

  /* 時刻文字列をtm構造体に変換. */
  strptime(str, "%a %b %d %H:%M:%S %Y", &stm); /* strptimeで時刻文字列strを書式文字列"%a %b %d %H:%M:%S %Y"に従ってtm構造体stmに変換. */

  /* stmの各要素を出力. */
  printf("[TimeString To JST]: %4d/%02d/%02d %2d:%02d:%02d\n", stm.tm_year + 1900, stm.tm_mon + 1, stm.tm_mday, stm.tm_hour, stm.tm_min, stm.tm_sec); /* printfでstmの内容を時刻文字列形式で出力. */

  /* tm構造体をUNIX時間に変換. */
  t2 = mktime(&stm); /* mktimeでtm構造体stmをGMTのUNIX時間に変換し, t2に格納.(mktimeはtm構造体をローカル時刻としてみている.) */

  /* UNIX時間の出力 */
  printf("[JST To UNIXTime]: %ld\n", t2); /* printfでt2を"%ld"で出力. */

  /* プログラムの終了 */
  return 0;

}
