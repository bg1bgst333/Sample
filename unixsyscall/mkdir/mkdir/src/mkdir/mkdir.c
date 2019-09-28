/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <sys/types.h> /* 派生型 */
#include <sys/stat.h> /* ファイル状態 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  int result; /* ディレクトリ作成の結果を格納するint型変数result. */

  /* ディレクトリ"test_dir"を作成. */
  result = mkdir("test_dir", S_IRWXU | S_IRWXG | S_IRWXO); /* mkdirでディレクトリ"test_dir"を作成. */
  if (result < 0){ /* 失敗 */
    printf("mkdir failed!\n"); /* "mkdir failed!"と出力. */
    return -1; /* -1を返して異常終了. */
  }
  else{ /* 成功 */
    printf("mkdir success!\n"); /* "mkdir success!"と出力. */
    return 0; /* 0を返して正常終了. */
  }

}
