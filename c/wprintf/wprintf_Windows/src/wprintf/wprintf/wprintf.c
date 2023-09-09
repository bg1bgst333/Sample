/* ヘッダファイルのインクルード */
#include <stdio.h>	/* 標準入出力 */
#include <locale.h>	/* ロケール */

/* main関数の定義 */
int main(void){

	/* ロケールのセット. */
	setlocale(LC_ALL, "japanese");	/* setlocaleでLC_ALL, "japanese"をセット. */

	/* マルチバイト文字の出力.(%hc) */
	wprintf(L"%hc\n", 'A');	/* wprintfで%hcでマルチバイト文字'A'を出力. */

	/* マルチバイト文字列の出力.(%hs) */
	wprintf(L"%hs\n", "ABCDE");	/* wprintfで%hsでマルチバイト文字列"ABCDE"を出力. */

	/* ワイド文字の出力.(%c) */
	wprintf(L"%c\n", L'あ');	/* wprintfで%cでワイド文字'あ'を出力. */

	/* ワイド文字列の出力.(%s) */
	wprintf(L"%s\n", L"あいうえお");	/* wprintfで%sでワイド文字列"あいうえお"を出力. */

	/* マルチバイト文字の出力.(%C) */
	wprintf(L"%C\n", 'A');	/* wprintfで%Cでマルチバイト文字'A'を出力. */

	/* マルチバイト文字列の出力.(%S) */
	wprintf(L"%S\n", "ABCDE");	/* wprintfで%Sでマルチバイト文字列"ABCDE"を出力. */

	/* プログラムの終了 */
	return 0;

}