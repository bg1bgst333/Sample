// ヘッダのインクルード
#include <tchar.h>	// TCHAR型
#include <iostream>	// C++標準入出力

// _tmain関数の定義
int _tmain() {

	// "Hello, world!"の出力
	std::wcout << _T("Hello, world!") << std::endl;	// 出力演算子"<<"で"std::wcout"に"Hello, world!"を出力.

	// プログラムの終了
	return 0;	// 0を返して正常終了.

}