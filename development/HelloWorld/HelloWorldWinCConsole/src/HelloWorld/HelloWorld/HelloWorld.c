/* ヘッダファイルのインクルード */
#include <tchar.h>	/* TCHAR型 */
#include <stdio.h>	/* C標準入出力 */

/* _tmain関数の定義 */
int _tmain(void) {

	/* "Hello, world!"の出力 */
	_tprintf(_T("Hello, world!\n"));	/* _tprintfで"Hello, world!"を出力. */

	/* プログラムの終了 */
	return 0;	/* 0を返して正常終了. */

}