// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <cstdio>		// 標準入出力
#include <tchar.h>		// TCHAR対応

// 外部から参照できる関数の宣言.
extern "C" __declspec(dllimport) void DllFunc(void);	// dllimportにすると, 関数を参照できる.

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// Dllfuncを呼ぶ.
	DllFunc();	// 外部から参照できる関数DllFuncを呼ぶ.

	// プログラムの終了
	return 0;

}