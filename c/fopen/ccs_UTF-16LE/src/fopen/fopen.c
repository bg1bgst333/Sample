/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <wchar.h> /* ワイド文字 */

/* main関数の定義 */
int main(void){

  /* BOMを書き込む. */
  FILE *fp1 = fopen("test.txt", "w"); /* fopenで"test.txt"を開く. */
  if (fp1 != NULL){ /* 成功. */

    /* BOM配列の用意. */
    char bom[3] = {0xff, 0xfe, 0x0}; /* char型配列bom(長さ3)を{0xff, 0xfe, 0x0}で初期化. */

    /* BOM配列の書き込み. */
    fputs(bom, fp1); /* fputsでbomを書き込む. */

    /* いったん閉じる. */
    fclose(fp1); /* fcloseでfp1を閉じる. */

    /* 本文を書き込む. */
    FILE *fp2 = fopen("test.txt", "a,ccs=UTF-16LE"); /* fopenで"test.txt"を開く.(ccsにUTF-16LEを指定.) */
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
