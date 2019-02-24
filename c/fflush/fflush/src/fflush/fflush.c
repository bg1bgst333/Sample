/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <unistd.h> /* UNIX標準 */

/* main関数の定義 */
int main(void){

  /* 1つ目の文字列を出力. */
  printf("str1"); /* "str1"と改行なしで出力. */

  /* いったんフラッシュ(バッファの内容を出力)する. */
  fflush(stdout); /* fflushでstdoutをいったんフラッシュする. */

  /* 5秒スリープ */
  sleep(5); /* sleepで5秒待つ. */

  /* 2つ目の文字列を出力. */
  printf("str2"); /* "str2"と改行なしで出力. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
