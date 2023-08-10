/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <locale.h> /* ロケール */
#include <wchar.h> /* ワイド文字 */

/* main関数の定義 */
int main(void){

  /* 変数と配列の初期化. */
  wchar_t wc = L'あ'; /* wchar_t型変数wcをL'あ'で初期化. */
  wchar_t ws[] = L"あいうえお"; /* wchar_t型配列wsをL"あいうえお"で初期化. */

  /* ロケールのセット. */
  setlocale(LC_ALL, "ja_JP.UTF-8"); /* setlocaleでLC_ALL, "ja_JP.UTF-8"をセット.(ja_JPだけでは文字化けするので, UTF-8を付ける.) */

  /* wcの出力. */
  printf("wc = %lc\n", wc); /* printfでwcを出力. */

  /* wsの出力. */
  printf("ws = %ls\n", ws); /* printfでwsを出力. */

  /* プログラムの終了 */
  return 0;

}
