/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <locale.h> /* ロケール */
#include <wchar.h> /* ワイド文字 */

/* main関数の定義 */
int main(void){

  /* ロケールのセット. */
  setlocale(LC_ALL, "ja_JP.EUC-JP"); /* setlocaleでLC_ALL, "ja_JP.EUC-JP"をセット. */

  /* ファイルを開く. */
  FILE *fp1 = fopen("test1.txt", "w"); /* fopenで"test1.txt"を開く. */
  if (fp1 != NULL){ /* 成功. */

    /* ワイド文字で"あいうえお"を出力. */
    fwprintf(fp1, L"%ls", L"あいうえお"); /* fwprintfでL"あいうえお"を出力. */

    /* 閉じる. */
    fclose(fp1); /* fcloseでfp1を閉じる. */

    /* ロケールのセット. */
    setlocale(LC_ALL, "ja_JP.UTF-8"); /* setlocaleでLC_ALL, "ja_JP.UTF-8"をセット. */

    /* ファイルを開く. */
    FILE *fp2 = fopen("test2.txt", "w"); /* fopenで"test2.txt"を開く. */
    if (fp2 != NULL){ /* 成功. */

      /* ワイド文字で"あいうえお"を出力. */
      fwprintf(fp2, L"%ls", L"あいうえお"); /* fwprintfでL"あいうえお"を出力. */

      /* 閉じる. */
      fclose(fp2); /* fcloseでfp2を閉じる. */

      /* プログラムの終了 */
      return 0;

    }

    /* 異常終了 */
    wprintf(L"error2"); /* L"error2"と出力. */
    return -2; /* -2を返す. */

  }

  /* 異常終了 */
  wprintf(L"error1"); /* L"error1"と出力. */
  return -1; /* -1を返す. */

}
