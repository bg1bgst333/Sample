/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <stdlib.h> /* 標準ユーティリティ */

/* main関数の定義 */
int main(void){

  /* QUERY_STRINGの取得. */
  char *query_string = getenv("QUERY_STRING"); /* getenvでCGI環境変数QUERY_STRINGの取得. */

  /* CGIとして文字列の出力. */
  printf("Content-type: text/html\n"); /* "Content-type: text/html\n"を出力. */
  printf("Status: 200 OK\n"); /* "Status: 200 OK\n"を出力. */
  printf("\n"); /* printfで改行を出力. */
  printf("<html>\n"); /* printfで"<html>"を出力. */
  printf("  <head>\n"); /* printfで"  <head>"を出力. */
  printf("    <title>QUERY_STRING</title>\n"); /* printfで"    <title>QUERY_STRING</title>"を出力. */
  printf("  </head>\n"); /* printfで"  </head>"を出力. */
  printf("  <body>\n"); /* printfで"  <body>"を出力. */
  printf("    %s\n", query_string); /* printfでquery_stringを出力. */
  printf("  </body>\n"); /* printfで"  </body>"を出力. */
  printf("</html>\n"); /* printfで"</html>"を出力. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
