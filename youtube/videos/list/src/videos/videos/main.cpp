// ヘッダのインクルード
// 既定のヘッダ
#include <tchar.h>			// TCHAR型
#include <iostream>			// C++標準入出力
// 独自のヘッダ
#include "credentials.h"	// 認証情報

// マクロの定義
// UNICODE切り替え
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// _tmain関数の定義
int _tmain() {

	// プログラムの終了
	return 0;	// 0を返す.

}