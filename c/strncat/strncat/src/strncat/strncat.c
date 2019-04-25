/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */

/* main関数の定義 */
int main(void){

  /* 配列の宣言 */
  char str1[256]; /* char型配列str1 */

  /* str1を初期化. */
  memset(str1, '\0', 256); /* memsetでstr1をクリア. */

  /* str1に"ABCDE"をセット. */
  strncat(str1, "ABCDE", 5); /* strncatで空文字のstr1に"ABCDE"を連結. */

  /* str1の出力. */
  printf("str1 = %s\n", str1); /* str1を出力. */

  /* str1に"FGH"のうち, 2文字を連結. */
  strncat(str1, "FGH", 2); /* strncatでstr1に"FGH"のうち, 2文字("FG")を連結. */

  /* str1の出力. */
  printf("str1 = %s\n", str1); /* str1を出力. */

  /* str1に"IJKLM"を連結.(10文字連結としておく.) */
  strncat(str1, "IJKLM", 10); /* strncatでstr1に"IJKLM"を連結.(10文字連結としておく.) */

  /* str1の出力. */
  printf("str1 = %s\n", str1); /* str1を出力. */
  
  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
