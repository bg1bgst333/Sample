/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <locale.h> /* ロケール */
#include <wchar.h> /* ワイド文字 */

/* main関数の定義 */
int main(void){

  /* 変数と配列の初期化. */
  char c = 'A'; /* char型変数cを'A'で初期化. */
  wchar_t wc = L'あ'; /* wchar_t型変数wcをL'あ'で初期化. */
  char s[] = "ABCDE"; /* char型配列sを"ABCDE"で初期化. */
  wchar_t ws[] = L"あいうえお"; /* wchar_t型配列wsをL"あいうえお"で初期化. */

  /* ロケールのセット. */
  setlocale(LC_ALL, "ja_JP.UTF-8"); /* setlocaleでLC_ALL, "ja_JP.UTF-8"をセット.(ja_JPだけでは文字化けするので, UTF-8を付ける.) */

  /* cの出力. */
  wprintf(L"c = %c\n", c); /* wprintfでcを出力. */

  /* wcの出力. */
  wprintf(L"wc = %lc\n", wc); /* wprintfでwcを出力. */

  /* sの出力. */
  wprintf(L"s = %hs\n", s); /* wprintfでsを出力. */

  /* wsの出力. */
  wprintf(L"ws = %ls\n", ws); /* wprintfでwsを出力. */

  /* プログラムの終了 */
  return 0;

}
