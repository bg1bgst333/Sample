/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* 配列の初期化 */
  char text[256] = {'\0'}; /* textを'\0'で埋める. */

  /* 文字列の取得 */
  gets(text); /* 入力文字列をgetsでtextに格納. */

  /* 文字列の出力 */
  printf("text = %s\n", text); /* textの内容をprintfで出力. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
