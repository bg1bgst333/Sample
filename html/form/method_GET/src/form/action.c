/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <stdlib.h> /* 標準ユーティリティ */

/* main関数の定義 */
int main(void){

  /* 変数の宣言・初期化 */
  char buf[4096] = {0}; /* char型バッファbuf(長さ4096)を{0}で初期化. */
  char *query_string = NULL; /* char型ポインタquery_stringをNULLで初期化. */
  int len = 0; /* int型lenを0で初期化. */

  /* CGI処理. */
  printf("Content-type: text/plain\n"); /* "Content-type: text/plain\n"を出力. */
  printf("\n"); /* printfで改行を出力. */
  query_string = getenv("QUERY_STRING"); /* getenvでquery_string取得. */
  printf("query_string: %s\n", query_string); /* query_stringを出力. */
  len = fread(buf, sizeof(char), 4096, stdin); /* freadでstdinから読み込んでbufに格納. */
  printf("len: %d\n", len); /* lenを出力. */
  printf("-----\n"); /* 区切り */
  printf("%s\n", buf); /* bufを出力. */  
  printf("-----\n"); /* 区切り */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
