/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <locale.h> /* ロケール */

/* main関数の定義 */
int main(void){

  /* ロケールのセット. */
  setlocale(LC_ALL, "ja_JP.UTF-8"); /* setlocaleでLC_ALL, "ja_JP.UTF-8"をセット.(ja_JPだけでは文字化けするので, UTF-8を付ける.) */

  /* ワイド文字の出力. */
  printf("%lc\n", L'あ'); /* printfで%lcでワイド文字'あ'を出力. */

  /* ワイド文字列の出力. */
  printf("%ls\n", L"あいうえお"); /* printfで%lsでワイド文字列"あいうえお"を出力. */

  /* プログラムの終了 */
  return 0;

}
