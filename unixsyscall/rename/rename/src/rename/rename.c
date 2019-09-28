/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  int result; /* リネームの結果を格納するint型変数result. */

  /* "test.txt"を"test1.txt"にリネームする. */
  result = rename("test.txt", "test1.txt"); /* "test.txt"を"test1.txt"にリネーム. */
  if (result < 0){ /* 失敗 */
    printf("rename failed!\n"); /* "rename failed!"と出力. */
    return -1; /* -1を返して異常終了. */
  }
  else{ /* 成功 */
    printf("rename success!\n"); /* "rename success!"と出力. */
    return 0; /* 0を返して正常終了. */
  }

} 
