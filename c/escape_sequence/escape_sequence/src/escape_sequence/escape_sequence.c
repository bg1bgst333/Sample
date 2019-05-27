/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <unistd.h> /* UNIX標準 */

/* main関数 */
int main(void){

  /* エスケープ文字の出力. */
  printf("[ABC\nDE]\n"); /* 改行 */
  printf("[ABC\tDE]\n"); /* タブ */
  printf("[ABC\bDE]\n"); /* バックスペース */

  /* 10秒休止 */
  sleep(10); /* sleepで10秒休止. */

  /* 画面制御コードの出力 */
  printf("clear\e[2J"); /* 画面のクリア. */
  printf("\e[1;1H"); /* 1行1列まで戻る. */
  printf("ABC\e[31mXXX\n"); /* "ABC"のあとに赤で"XXX"と出力して改行. */
  printf("DEF\e[0mYYY\n"); /* "DEF"のあとにリセットして"YYY"と出力して改行. */
  printf("GHI\e[42mZZZ\e[0mAAA\n"); /* "GHI"のあとに背景を緑にして"ZZZ"してリセットして"AAA"を出力して改行. */
  printf("ABCDE\n"); /* "ABCDE"を出力. */
  printf("ABCDE\n"); /* "ABCDE"を出力. */
  printf("ABCDE\n"); /* "ABCDE"を出力. */
  printf("ABCDE\n"); /* "ABCDE"を出力. */
  printf("ABCDE\n"); /* "ABCDE"を出力. */
  printf("\e[6;2HXX\n"); /* 6行2列に戻って"XX"を出力. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
