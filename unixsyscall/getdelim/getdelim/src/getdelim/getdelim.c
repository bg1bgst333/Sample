/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <stdlib.h> /* 標準ユーティリティ */
#include <string.h> /* 文字列処理 */

/* main関数 */
int main(void){

  /* 変数の初期化 */
  FILE *fp = NULL; /* ファイルポインタfpをNULLで初期化. */
  char *line = NULL; /* 行の文字列へのポインタlineをNULLで初期化. */
  size_t len = 0; /* 配列のサイズlenを0で初期化. */
  int read = 0; /* 読み込んだ文字数readを0で初期化. */

  /* バッファの確保. */
  line = (char *)malloc(256 * sizeof(char)); /* lineの長さは256バイト. */
  len = 256; /* lenに256を代入. */
  memset(line, '\0', len); /* lineを'\0'で埋める. */

  /* ファイルを開く. */
  fp = fopen("test.txt", "r"); /* "test.txt"を読み込み専用で開く. */
  if (fp == NULL){ /* fpがNULLの時. */
    free(line); /* lineを解放. */
    return -1; /* -1を返して異常終了. */
  }

  /* 1行(';'で区切られた場合.)ずつ読み込み. */
  while ((read = getdelim(&line, &len, ';', fp)) != -1){ /* getdelimが読み込める間. */
    printf("line = [%s]\n", line); /* lineを出力. */
    memset(line, '\0', 256); /* lineを'\0'で埋める. */
  }

  /* ファイルを閉じる. */
  fclose(fp); /* fpを閉じる. */

  /* バッファの解放. */
  free(line); /* lineを解放. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
