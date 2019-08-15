/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力(ファイル入出力も含む.) */

/* main関数の定義 */
int main(void){

  /* ポインタの宣言 */
  FILE *fp; /* ファイルポインタfp */

  /* ファイルtest.txtを開く. */
  fp = fopen("test.txt", "r"); /* fopenで"test.txt"を読込専用("r")で開く. */
  if (fp != NULL){ /* fpがNULLでなければ. */

    /* ファイルディスクリプタの値を出力. */
    printf("fp->_fileno = %d\n", fp->_fileno); /* fp->_filenoの値を出力. */

    /* ファイルを閉じる. */
    fclose(fp); /* fcloseでfpを閉じる. */

  }

  /* プログラムの終了 */
  return 0; /* 正常終了 */

}
