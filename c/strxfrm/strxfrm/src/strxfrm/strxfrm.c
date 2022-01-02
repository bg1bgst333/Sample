/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <stdlib.h> /* 標準ユーティリティ */
#include <string.h> /* 文字列処理 */
#include <locale.h> /* ロケール */

/* main関数 */
int main(void){

  /* 変数の宣言 */
  char str1[] = "h"; /* "h"という文字列. */
  char str2[] = "ch"; /* "ch"という文字列. */
  int str1_after_len = 0; /* 変換後のstr1の長さstr1_after_lenを0で初期化. */
  int str2_after_len = 0; /* 変換後のstr2の長さstr2_after_lenを0で初期化. */
  char *str1_after_ptr = NULL; /* 変換後のstr1ポインタ. */
  char *str2_after_ptr = NULL; /* 変換後のstr2ポインタ. */

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

  /* 変換後の文字列の長さを取得. */
  str1_after_len = strxfrm(NULL, str1, 0); /* 変換後のstr1の長さを取得. */
  str2_after_len = strxfrm(NULL, str2, 0); /* 変換後のstr2の長さを取得. */

  /* 変換後の文字列を格納するメモリを確保. */
  str1_after_ptr = (char *)malloc((str1_after_len + 1) * sizeof(char));
  str2_after_ptr = (char *)malloc((str2_after_len + 1) * sizeof(char));

  /* 変換 */
  strxfrm(str1_after_ptr, str1, str1_after_len + 1); /* str1をstr1_after_ptrに変換. */
  strxfrm(str2_after_ptr, str2, str2_after_len + 1); /* str2をstr2_after_ptrに変換. */

  /* strcmpで比較. */
  if (strcmp(str1_after_ptr, str2_after_ptr) < 0){ /* str1_after_ptrが先. */
    printf("h, ch\n"); /* "h, ch"と出力. */
  }
  else{ /* str2_after_ptrが先. */
    printf("ch, h\n"); /* "ch, h"と出力. */
  }

  /* メモリを解放. */
  free(str1_after_ptr);
  free(str2_after_ptr);

  /* プログラムの終了. */
  return 0; /* 0を返して正常終了. */

}
