/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */
#include <locale.h> /* ロケール */

/* main関数 */
int main(void){

  /* 変数の宣言 */
  char str1[] = "h"; /* "h"という文字列. */
  char str2[] = "ch"; /* "ch"という文字列. */

  /* strcmpで比較. */
  if (strcmp(str1, str2) < 0){ /* str1が先. */
    printf("h, ch\n"); /* "h, ch"と出力. */
  }
  else{ /* str2が先. */
    printf("ch, h\n"); /* "ch, h"と出力. */
  }

  /* strcollで比較. */
  if (strcoll(str1, str2) < 0){ /* str1が先. */
    printf("h, ch\n"); /* "h, ch"と出力. */
  }
  else{ /* str2が先. */
    printf("ch, h\n"); /* "ch, h"と出力. */
  }

  /* ロケールをチェコに設定. */
  setlocale(LC_COLLATE, "cs_CZ.iso88592"); /* LC_COLLATEで"cs_CZ.iso88592"をセット. */

  /* strcmpで比較. */
  if (strcmp(str1, str2) < 0){ /* str1が先. */
    printf("h, ch\n"); /* "h, ch"と出力. */
  }
  else{ /* str2が先. */
    printf("ch, h\n"); /* "ch, h"と出力. */
  }

  /* strcollで比較. */
  if (strcoll(str1, str2) < 0){ /* str1が先. */
    printf("h, ch\n"); /* "h, ch"と出力. */
  }
  else{ /* str2が先. */
    printf("ch, h\n"); /* "ch, h"と出力. */
  }

  /* プログラムの終了. */
  return 0; /* 0を返して正常終了. */

}
