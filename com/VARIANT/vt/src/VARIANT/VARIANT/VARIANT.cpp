// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR対応
#include <stdio.h>		// C標準入出力

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// VARIANT構造体の宣言
	VARIANT vr;

	// VARIANT構造体変数vrの初期化
	VariantInit(&vr);	// VariantInitでvrを初期化.

	// 入力する値の型をセット.
	vr.vt = VT_I4;	// INT

	// プログラムの終了.
	return 0;	// 0を返して終了.

}