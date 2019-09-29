/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <unistd.h> /* UNIX標準 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  int r; /* 読み込み権限があるかどうかの結果を格納するint型変数r. */
  int w; /* 書き込み権限があるかどうかの結果を格納するint型変数w. */
  int x; /* 実行権限があるかどうかの結果を格納するint型変数x. */

  /* 読み込み権限のチェック. */
  r = access("test.txt", R_OK); /* accessで"test.txt"の読み込み権限をチェック. */
  if (r < 0){ /* 権限なし */
    printf("Read NG\n"); /* "Read NG"と出力. */
  }
  else{ /* 権限あり */
    printf("Read OK\n"); /* "Read OK"と出力. */
  }

  /* 書き込み権限のチェック. */
  w = access("test.txt", W_OK); /* accessで"test.txt"の書き込み権限をチェック. */
  if (w < 0){ /* 権限なし */
    printf("Write NG\n"); /* "Write NG"と出力. */
  }
  else{ /* 権限あり */
    printf("Write OK\n"); /* "Write OK"と出力. */
  }

  /* 実行権限のチェック. */
  x = access("test.txt", X_OK); /* accessで"test.txt"の実行権限をチェック. */
  if (x < 0){ /* 権限なし */
    printf("Exec NG\n"); /* "Exec NG"と出力. */
  }
  else{ /* 権限あり */
    printf("Exec OK\n"); /* "Exec OK"と出力. */
  }

  /* プログラムの終了. */
  return 0; /* 0を返して正常終了. */

}
