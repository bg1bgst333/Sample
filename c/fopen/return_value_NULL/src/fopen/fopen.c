/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* ポインタの宣言 */
  FILE *fp;

  /* ファイルを開く. */
  fp = fopen("test.txt", "r");
  if (fp == NULL){ /* NULLなら失敗. */

    /* perrorでエラー内容を出力. */
    perror("fopen");
    return 1;

  }

  /* ファイルを閉じる. */
  fclose(fp);

  /* プログラムの終了 */
  return 0; 

}
