/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <time.h> /* UNIX時間 */

/* main関数の定義 */
int main(void){

  /* 構造体・ポインタの宣言 */
  struct tm stm; /* 時刻情報を格納するtm構造体変数stm. */
  const char *src_str = "2015/06/01 12:00:00"; /* 変換元の時刻文字列"2015/06/01 12:00:00"へのポインタ. */
  char dest_str[64]; /* tm構造体から再び指定の書式に変換した時刻文字列を格納するchar型配列.(長さ64.) */

  /* 時刻文字列をtm構造体に変換. */
  strptime(src_str, "%Y/%m/%d %H:%M:%S", &stm); /* strptimeで時刻文字列src_strを書式文字列"%Y/%m/%d %H:%M:%S"に従ってtm構造体stmに変換. */

  /* tm構造体を再び時刻文字列に変換. */
  strftime(dest_str, 64, "%Y年%m月%d日 %H時%M分%S秒", &stm); /* strftimeでtm構造体stmから時刻文字列"%Y年%m月%d日 %H時%M分%S秒"に再び変換し, dest_strに格納. */

  /* 時刻文字列の出力 */
  printf("%s\n", dest_str); /* printfで時刻文字列dest_strを出力. */

  /* プログラムの終了 */
  return 0;

}
