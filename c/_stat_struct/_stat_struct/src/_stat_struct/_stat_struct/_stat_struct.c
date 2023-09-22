/* ヘッダファイルのインクルード */
#include <stdio.h>	/* 標準入出力 */
#include <sys/types.h>	/* 派生型 */
#include <sys/stat.h>	/* ファイル状態 */

/* main関数の定義 */
int main(void){

	/* 構造体の宣言 */
	struct _stat sst;	/* _stat構造体変数sst. */

	/* ファイル情報を取得. */
	if (_stat("test.txt", &sst) == 0){	/* _statで"test.txt"のファイル情報を取得し, sstに格納.(0なら成功.) */

		/* 取得できたら, ファイルサイズとドライブレターを出力. */
		printf("sst.st_size = %d\n", sst.st_size);	/* sst.st_sizeを出力. */
		printf("sst.st_dev = %d(drive = %c)\n", sst.st_dev, 'A' + sst.st_dev);	/* sst.st_devを出力. */

	}

	/* 正常終了 */
	return 0;	/* 0を返して正常終了. */

}