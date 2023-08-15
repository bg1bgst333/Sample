/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <locale.h> /* ロケール */
#include <wchar.h> /* ワイド文字 */

/* main関数の定義 */
int main(void){

  /* ロケールのセット. */
  setlocale(LC_ALL, "ja_JP.EUC-JP"); /* setlocaleでLC_ALL, "ja_JP.EUC-JP"をセット. */

  /* ファイルを開く. */
  FILE *fp = fopen("test.txt", "w"); /* fopenで"test.txt"を開く. */
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
