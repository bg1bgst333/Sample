/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* CGIとして文字列の出力. */
  printf("Content-type: text/html\n"); /* "Content-type: text/html\n"を出力. */
  printf("\n"); /* printfで改行を出力. */
  printf("<html>\n"); /* printfで"<html>"を出力. */
  printf("  <head>\n"); /* printfで"  <head>"を出力. */
  printf("    <title>form action.cgi</title>\n"); /* printfで"    <title>form action.cgi</title>"を出力. */
  printf("  </head>\n"); /* printfで"  </head>"を出力. */
  printf("  <body>\n"); /* printfで"  <body>"を出力. */
  printf("    <a href=\"http://bgstation0.com/\">B.G-STATION</a>\n"); /* printfで"    <a href=\"http://bgstation0.com/\">B.G-STATION</a>"を出力. */
  printf("  </body>\n"); /* printfで"  </body>"を出力. */
  printf("</html>\n"); /* printfで"</html>"を出力. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
