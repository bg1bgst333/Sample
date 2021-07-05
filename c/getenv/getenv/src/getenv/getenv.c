/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <stdlib.h> /* 標準ユーティリティ */

/* main関数 */
int main(void){

  /* 変数の初期化 */
  char *path = NULL; /* char型ポインタpathをNULLで初期化. */

  /* 環境変数PATHの取得 */
  path = getenv("PATH"); /* getenvで環境変数PATHの値を取得. */
  if (path == NULL){ /* NULLなら失敗. */
    printf("path == NULL\n"); /* "path == NULL"を出力. */
    return -1; /* -1を返して異常終了. */
  }

  /* NULLでないなら成功. */
  printf("path = %s\n", path); /* pathの内容を出力. */

  /* プログラムの終了. */
  return 0; /* 0を返して正常終了. */

}
