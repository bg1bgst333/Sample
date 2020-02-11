/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <unistd.h> /* UNIX標準 */

/* main関数の定義 */
int main(void){

  /* stdoutのバッファにNULLを指定. */
  setvbuf(stdout, NULL, _IONBF, 0); /* setvbufにNULLを指定.(_IONBFなのでバッファリングしない.) */

  /* 1つ目の文字列を出力. */
  printf("ABCDE"); /* printfで"ABCDE"を出力. */

  /* 5秒スリープ */
  sleep(5); /* sleepで5秒待つ. */

  /* 2つ目の文字列を出力. */
  printf("FGHIJ"); /* printfで"FGHIJ"を出力. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
