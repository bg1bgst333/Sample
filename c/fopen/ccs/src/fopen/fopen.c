/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <wchar.h> /* ワイド文字 */

/* main関数の定義 */
int main(void){

  /* ファイルを開く. */
  FILE *fp = fopen("test.txt", "w,ccs=EUC-JP"); /* fopenで"test.txt"を開く.(ccsにEUC-JPを指定.) */
  if (fp != NULL){ /* 成功. */

    /* ワイド文字で"あいうえお"を出力. */
    fwprintf(fp, L"%ls", L"あいうえお"); /* fwprintfでL"あいうえお"を出力. */

    /* 閉じる. */
    fclose(fp); /* fcloseでfpを閉じる. */

    /* プログラムの終了 */
    return 0;

  }

  /* 異常終了 */
  wprintf(L"error"); /* L"error"と出力. */
  return -1; /* -1を返す. */

}
