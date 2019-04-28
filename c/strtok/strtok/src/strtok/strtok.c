/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */

/* main関数の定義 */
int main(void){

  /* 初期化 */
  char target[] = "ABC,DEF,GHI\nJKL MNO PQR"; /* targetを"ABC,DEF,GHI\nJKL MNO PQR"で初期化. */
  char *token = NULL; /* tokenをNULLで初期化. */
  int i = 0; /* iを0で初期化. */

  /* do-while文でトークン切り出し. */
  do{ /* do-while文 */

    /* 最初は文字列を渡し, 2回目以降はNULLを渡す. */
    if (i == 0){ /* 最初 */
      /* 文字列を渡して, トークンを取得. */
      token = strtok(target, ",\n "); /* ",\n "のいずれかで区切り, トークンのアドレスをtokenに格納. */
    }
    else{ /* 2回目以降 */
      /* NULLを渡して, 次のトークンを取得. */
      token = strtok(NULL, ",\n "); /* ",\n "のいずれかで区切り, トークンのアドレスをtokenに格納. */
    }
    if (token != NULL){ /* NULLでない. */
      printf("token = %s\n", token); /* tokenを出力. */
    }
    i++; /* iをインクリメント. */

  }
  while (token != NULL); /* tokenがNULLでない間は繰り返す. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
