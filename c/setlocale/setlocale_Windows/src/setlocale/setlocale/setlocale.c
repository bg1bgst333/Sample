/* ヘッダファイルのインクルード */
#include <stdio.h>	/* 標準入出力 */
#include <locale.h>	/* ロケール */

/* main関数の定義 */
int main(void){

	/* 変数の宣言 */
	char *loc1;
	char *loc2;
	char *loc3;
	char *loc4;
	char *loc5;
	char *loc6;
	char *loc7;
	char *loc8;
	char *loc9;

	/* NULL指定 */
	loc1 = setlocale(LC_ALL, NULL);	/* setlocaleにLC_ALL, NULLを指定. */
	printf("loc1 = %s\n", loc1);	/* loc1を出力. */

	/* ""指定 */
	loc2 = setlocale(LC_ALL, "");	/* setlocaleにLC_ALL, ""を指定. */
	printf("loc2 = %s\n", loc2);	/* loc2を出力. */

	/* "C"指定 */
	loc3 = setlocale(LC_ALL, "C");	/* setlocaleにLC_ALL, "C"を指定. */
	printf("loc3 = %s\n", loc3);	/* loc3を出力. */

	/* "Japanese_Japan.932"指定 */
	loc4 = setlocale(LC_ALL, "Japanese_Japan.932");	/* setlocaleにLC_ALL, "Japanese_Japan.932"を指定. */
	printf("loc4 = %s\n", loc4);	/* loc4を出力. */

	/* ここでNULL指定. */
	loc5 = setlocale(LC_ALL, NULL);	/* setlocaleにLC_ALL, NULLを指定. */
	printf("loc5 = %s\n", loc5);	/* loc5を出力. */

	/* ここで"C"指定. */
	loc6 = setlocale(LC_ALL, "C");	/* setlocaleにLC_ALL, "C"を指定. */
	printf("loc6 = %s\n", loc6);	/* loc6を出力. */

	/* ここで""指定. */
	loc7 = setlocale(LC_ALL, "");	/* setlocaleにLC_ALL, ""を指定. */
	printf("loc7 = %s\n", loc7);	/* loc7を出力. */

	/* "Japanese"指定 */
	loc8 = setlocale(LC_ALL, "Japanese");	/* setlocaleにLC_ALL, "Japanese"を指定. */
	printf("loc8 = %s\n", loc8);	/* loc8を出力. */

	/* "UTF-8"指定 */
	loc9 = setlocale(LC_ALL, "UTF-8");	/* setlocaleにLC_ALL, "UTF-8"を指定. */
	printf("loc9 = %s\n", loc9);	/* loc9を出力. */

	/* プログラムの終了 */
	return 0;

}