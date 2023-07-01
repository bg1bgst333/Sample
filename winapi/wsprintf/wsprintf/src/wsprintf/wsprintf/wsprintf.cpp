// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数・配列の宣言・初期化
	int d = 10;	// dの値を10に初期化.
	unsigned int x = 0xA;	// xの値を0xAに初期化.
	TCHAR c = _T('A');	// cの値を'A'に初期化.
	TCHAR str[] = _T("ABCDE");	// strの文字列を"ABCDE"に初期化.
	TCHAR all_str[256];	// 全ての値を連結した文字列を格納する文字配列all_str.(長さ256)

	// すべての値を連結した文字列の作成.
	wsprintf(all_str, _T("d = %d, x = 0x%X, c = %c, str = %s"), d, x, c, str);	// wsprintfで全ての値を連結した文字列を作成.

	// all_strの出力
	_tprintf(_T("all_str: %s\n"), all_str);	// _tprintfでall_str出力.

	// プログラムの終了
	return 0;

}