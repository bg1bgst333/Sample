/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* 文字列の標準出力. */
  fputs("ABCDE\n", stdout); /* fputsの第2引数にstdoutを指定することで標準出力に"ABCDE"を出力. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
