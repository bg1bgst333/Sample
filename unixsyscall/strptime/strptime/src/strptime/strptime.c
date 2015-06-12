/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#define _XOPEN_SOURCE /* 機能検査マクロ */
#include <time.h> /* UNIX時間 */

/* main関数の定義 */
int main(void){

  /* 構造体・ポインタの宣言 */
  struct tm stm; /* 時刻情報を格納するtm構造体変数stm. */
  const char *str = "2015/06/01 12:00:00"; /* 変換元の時刻文字列"2015/06/01 12:00:00"へのポインタ. */

  /* 時刻文字列をtm構造体に変換. */
  strptime(str, "%Y/%m/%d %H:%M:%S", &stm); /* strptimeで時刻文字列strを書式文字列"%Y/%m/%d %H:%M:%S"に従ってtm構造体stmに変換. */

  /* stmの各要素を出力. */
  printf("%4d/%02d/%02d %2d:%02d:%02d\n", stm.tm_year + 1900, stm.tm_mon + 1, stm.tm_mday, stm.tm_hour, stm.tm_min, stm.tm_sec); /* printfでstmの内容を時刻文字列形式で出力. */

  /* プログラムの終了 */
  return 0;

}
