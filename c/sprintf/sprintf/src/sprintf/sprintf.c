/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* 変数・配列の宣言・初期化 */
  int d = 10; /* dの値を10に初期化. */
  unsigned int x = 0xA; /* xの値を0xAに初期化. */
  float f = 0.123; /* fの値を0.123に初期化. */
  char c = 'A'; /* cの値を'A'に初期化. */
  char str[] = "ABCDE"; /* strの文字列を"ABCDE"に初期化. */
  char all_str[256]; /* 全ての値を連結した文字列を格納する文字配列all_str.(長さ256) */

  /* すべての値を連結した文字列の作成. */
  sprintf(all_str, "d = %d, x = 0x%X, f = %f, c = %c, str = %s", d, x, f, c, str); /* sprintfで全ての値を連結した文字列を作成. */

  /* all_strの出力 */
  printf("all_str: %s\n", all_str); /* printfでall_str出力. */

  /* プログラムの終了 */
  return 0;

}
