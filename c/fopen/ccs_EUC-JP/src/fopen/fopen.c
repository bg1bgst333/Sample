/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <wchar.h> /* ワイド文字 */

/* main関数の定義 */
int main(void){

  /* ファイルを開く. */
  FILE *fp1 = fopen("test1.txt", "r,ccs=UTF-8"); /* fopenで"test1.txt"を開く.(ccsにUTF-8を指定.) */
  if (fp1 != NULL){ /* 成功. */

    /* ワイド文字の読み込み. */
    wchar_t wstr[128] = {0}; /* wchar_t型配列wstr(長さ128)を{0}で初期化. */
    fwscanf(fp1, L"%ls", wstr); /* fwscanfで読み込んだワイド文字をwstrに格納. */

    /* 閉じる. */
    fclose(fp1); /* fcloseでfp1を閉じる. */

    /* 再びファイルを開く. */
    FILE *fp2 = fopen("test2.txt", "w,ccs=EUC-JP"); /* fopenで"test2.txt"を開く.(ccsにEUC-JPを指定.) */
    if (fp2 != NULL){ /* 成功. */

      /* ワイド文字の書き込み. */
      fwprintf(fp2, L"%ls", wstr); /* fwprintfでwstrを書き込み. */

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
