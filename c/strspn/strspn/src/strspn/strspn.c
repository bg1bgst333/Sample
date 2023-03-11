/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <stdlib.h> /* 標準ユーティリティ */
#include <string.h> /* 文字列処理 */

/* main関数 */
int main(void){

  /* 変数の宣言 */
  char str1[256] = {0}; /* char型配列str1(長さ256)に入力文字列を格納するので, まずは{0}で初期化. */
  char str2[] = "abcde"; /* 文字群str2を"abcde"とする. */
  size_t len1; /* str1の長さlen1. */
  size_t len2; /* 文字群str2のどれかの文字が先頭から続く時の長さlen2. */

  /* 入力フォームの出力. */
  printf("str1: "); /* printfで"str1: "を出力. */

  /* 入力文字列の取得. */
  fgets(str1, 256, stdin); /* fgetsでstdinから読み込んだ文字列をstr1に格納. */

  /* str1の長さを取得. */
  len1 = strlen(str1); /* strlenでstr1の長さを取得し, len1に格納. */

  /* 末尾に'\n'があったら, '\0'に置き換える. */
  if (str1[len1 - 1] == '\n'){ /* len1 - 1番目が'\n'なら. */
    str1[len1 - 1] = '\0'; /* str1[len1 - 1]に'\0'を格納. */
  }

  /* 文字群str2のどれかの文字が先頭からどれぐらい続くかを調べる. */
  len2 = strspn(str1, str2); /* strspnでstr1ではstr2のどれかがどれくらい先頭から続くか最大の長さlen2を返す. */

  /* len2の値を出力. */
  printf("len2 = %d\n", len2); /* len2を出力. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
