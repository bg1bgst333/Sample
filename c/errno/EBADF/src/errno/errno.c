/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */
#include <errno.h> /* errno */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  int ret_e;
  char buf[256];
  FILE *fp;
  int ret;

  /* 標準出力が閉じられている時, printfは失敗する. */
  fclose(stdout);
  ret_e = printf("ABCDE\n");
  if (ret_e < 0){ /* 戻り値が負の値の場合は失敗. */
    if (errno == EBADF){ /* すでに閉じられているのでファイルディスクリプタが不正. */
      sprintf(buf, "printf(%s)", "errno == EBADF");
      perror(buf);
    }
    else{
      sprintf(buf, "printf(%s)", "errno != EBADF");
      perror(buf);
    }
  }
  else{
    printf("NO ERROR\n");
  }

  /* errnoをリセット */
  errno = 0;

  /* ファイルが開ける時, fprintfは成功する. */
  fp = fopen("test.txt", "w");
  if (fp == NULL){
    return -1;
  }
  ret = fprintf(fp, "ABCDE");
  if (ret < 0){
    fclose(fp);
    return -2;
  }
  fclose(fp);
  /* ファイルが閉じられている時, fprintfは失敗する. */
  memset(buf, 0, 256);
  ret_e = fprintf(fp, "ABCDE");
  if (ret_e < 0){ /* 戻り値が負の値の場合は失敗. */
    if (errno == EBADF){ /* すでに閉じられているのでファイルディスクリプタが不正. */
      sprintf(buf, "fprintf(%s)", "errno == EBADF");
      perror(buf);
    }
    else{
      sprintf(buf, "fprintf(%s)", "errno != EBADF");
      perror(buf);
    }
  }
  else{
    printf("NO ERROR\n");
  }

  /* プログラムの終了 */
  return 0;

}
