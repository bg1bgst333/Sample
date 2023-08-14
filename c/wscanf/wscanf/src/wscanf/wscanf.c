/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <locale.h> /* ロケール */
#include <wchar.h> /* ワイド文字 */

/* main関数の定義 */
int main(void){

  /* 配列の初期化. */
  wchar_t wstr[128] = {0}; /* wchar_t配列wstr(長さ128)を{0}で初期化. */

  /* ロケールのセット. */
  setlocale(LC_ALL, "ja_JP.UTF-8"); /* setlocaleでLC_ALL, "ja_JP.UTF-8"をセット.(ja_JPだけでは文字化けするので, UTF-8を付ける.) */

  /* 文字列の入力. */
  wscanf(L"%ls", wstr); /* wscanfで読み込んだワイド文字列をwstrに格納. */

  /* wstrの出力. */
  wprintf(L"wstr = %ls\n", wstr); /* wprintfでwstrを出力. */

  /* プログラムの終了 */
  return 0;

}
