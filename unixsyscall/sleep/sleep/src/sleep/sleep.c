/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <time.h> /* UNIX時間 */
#include <unistd.h> /* UNIX標準 */

/* main関数の定義 */
int main(void){

  /* 変数・構造体の宣言 */
  time_t t; /* time_t型変数t. */
  char *start_str; /* 開始時刻文字列. */
  char *end_str; /* 終了時刻文字列. */

  /* スレッドの休止を開始. */
  t = time(NULL); /* timeでUNIX時間取得. */
  start_str = ctime(&t); /* ctimeで開始時刻文字列(GMT)を取得. */
  printf("sleep start! %s", start_str); /* printfで"sleep start!"と開始時刻文字列を出力. */

  /* 5秒間休止. */
  sleep(5); /* sleepで5秒間休止. */

  /* 休止の終了. */
  t = time(NULL); /* timeでUNIX時間取得. */
  end_str = ctime(&t); /* ctimeで終了時刻文字列(GMT)を取得. */
  printf("sleep end! %s", end_str); /* printfで"sleep end!"と終了時刻文字列を出力. */

  /* プログラムの終了 */
  return 0;

}
