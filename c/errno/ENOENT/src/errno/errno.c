/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <errno.h> /* errno */

/* main関数の定義 */
int main(void){

  /* ポインタの宣言 */
  FILE *fp;

  /* ファイルを開く. */
  fp = fopen("test.txt", "r");
  if (fp == NULL){ /* NULLなら失敗. */

    /* errnoがENOENTの場合, "errno == ENOENT"と出力. */
    if (errno == ENOENT){
      printf("errno == ENOENT\n");
    }

    /* perrorでエラー内容を出力. */
    perror("fopen");
    return 1;

  }

  /* ファイルを閉じる. */
  fclose(fp);

  /* プログラムの終了 */
  return 0; 

}
