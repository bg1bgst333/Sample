/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */

/* main関数 */
int main(void){

  /* 配列の宣言 */
  char buf[256]; /* char型文字配列buf(長さ256) */

  /* 文字列の受け取り */
  fgets(buf, 256, stdin); /* fgetsでstdinから文字列を受け取る. */

  /* 改行の除去 */
  if (buf[strlen(buf) - 1] == '\n'){ /* 末尾が'\n'なら. */
    buf[strlen(buf) - 1] = '\0'; /* 末尾を'\0'にする. */
  }

  /* bufの出力 */
  printf("-----dest start-----\n"); /* 開始 */
  printf("%s\n", buf); /* bufを出力. */
  printf("-----dest end-----\n"); /* 終了 */

  /* プログラムの終了 */
  return 0; /* 正常終了 */

}
