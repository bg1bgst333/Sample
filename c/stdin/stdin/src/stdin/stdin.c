/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列操作 */

/* main関数の定義 */
int main(void){

  /* 変数, 配列の初期化 */
  int len = 0; /* textの長さlenを0にする. */
  char text[256] = {'\0'}; /* textを'\0'で埋める. */
  
  /* 文字列の取得 */
  fgets(text, 256, stdin); /* 標準入力stdinからfgetsで1行読み込み, textに格納. */

  /* いったん出力. */
  printf("[%s]\n", text); /* textを出力. */

  /* 最後の文字をチェック. */
  len = strlen(text); /* textの長さを取得. */
  if (text[len - 1] == '\n'){ /* 最後の文字が'\n'. */
    text[len - 1] = '\0'; /* '\0'を代入. */
  }

  /* 出力 */
  printf("[%s]\n", text); /* textを出力. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
  
