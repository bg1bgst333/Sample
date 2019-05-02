/* ヘッダファイルのインクルード */
#include <stdio.h>	/* 標準入出力 */
#define _USE_MATH_DEFINES	/* これがないとM_PIなどのマクロが使えない. */
#include <math.h>	/* 数学関数 */

/* main関数の定義 */
int main(void){

	/* 円周率π */
	printf("M_PI = %f\n", M_PI);	/* 円周率πの値はM_PIに定義されている. */

	/* プログラムの終了 */
	return 0;	/* 0を返して正常終了. */

}