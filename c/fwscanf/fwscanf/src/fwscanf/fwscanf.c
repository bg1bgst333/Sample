/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <locale.h> /* ロケール */
#include <wchar.h> /* ワイド文字 */

/* main関数の定義 */
int main(void){

  /* ロケールのセット. */
  setlocale(LC_ALL, "ja_JP.EUC-JP"); /* setlocaleでLC_ALL, "ja_JP.EUC-JP"をセット. */

  /* ファイルを開く. */
  FILE *fp = fopen("test.txt", "r"); /* fopenで"test.txt"を開く. */
  if (fp != NULL){ /* 成功. */

    /* fpの内容をワイド文字で読み込み. */
    wchar_t wstr[128] = {0}; /* wchar_t文字配列wstr(長さ128)を{0}で初期化. */
    fwscanf(fp, L"%ls", wstr); /* fwscanfでfpの内容を読み込み, wstrに格納. */

    /* wstrを出力. */
    setlocale(LC_ALL, "ja_JP.UTF-8"); /* setlocaleでLC_ALL, "ja_JP.UTF-8"をセット.(これに戻さないと文字化けする.) */
    wprintf(L"%ls\n", wstr); /* wprintfでwstrを出力. */

    /* 閉じる. */
    fclose(fp); /* fcloseでfpを閉じる. */

    /* プログラムの終了 */
    return 0;

  }

  /* 異常終了 */
  wprintf(L"error"); /* L"error"と出力. */
  return -1; /* -1を返す. */

}
