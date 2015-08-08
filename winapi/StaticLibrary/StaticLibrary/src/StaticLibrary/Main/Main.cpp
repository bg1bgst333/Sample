// ヘッダファイルのインクルード
#include <cstdio>				// 標準入出力
#include <tchar.h>				// TCHAR対応
#include "StaticLibrary_1.h"	// 関数StaticLibraryFunc_1
#include "StaticLibrary_2.h"	// 関数StaticLibraryFunc_2

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// StaticLibraryFunc_1を呼ぶ.
	StaticLibraryFunc_1();	// スタティックライブラリ(StaticLibrary.lib)に定義されている関数StaticLibraryFunc_1を呼ぶ.

	// StaticLibraryFunc_2を呼ぶ.
	StaticLibraryFunc_2();	// スタティックライブラリ(StaticLibrary.lib)に定義されている関数StaticLibraryFunc_2を呼ぶ.

	// プログラムの終了
	return 0;

}