/* ヘッダファイルのインクルード */
#include <stdio.h>	/* 標準入出力 */
#include <locale.h>	/* ロケール */

/* main関数の定義 */
int main(void){

	/* ロケールのセット. */
	setlocale(LC_ALL, "japanese");	/* setlocaleでLC_ALL, "japanese"をセット. */

	/* ワイド文字の出力. */
	printf("%C\n", L'あ');	/* printfで%Cでワイド文字'あ'を出力. */

	/* ワイド文字列の出力. */
	printf("%S\n", L"あいうえお");	/* printfで%Sでワイド文字列"あいうえお"を出力. */

	/* プログラムの終了 */
	return 0;

}