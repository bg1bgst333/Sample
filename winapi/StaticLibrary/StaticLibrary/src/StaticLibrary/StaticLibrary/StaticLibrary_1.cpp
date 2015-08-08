// ヘッダファイルのインクルード
#include <cstdio>	// 標準入出力
#include <tchar.h>	// TCHAR対応
#include "StaticLibrary_1.h"	// 関数StaticLibraryFunc_1のプロトタイプ宣言.

// 関数StaticLibraryFunc_1の定義
void StaticLibraryFunc_1(){

	// "StaticLibraryFunc_1!"と出力.
	_tprintf(_T("StaticLibraryFunc_1!\n"));	// _tprintfで"StaticLibraryFunc_1!\n"と出力.

}