// ヘッダファイルのインクルード
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <windows.h>	// 標準WindowsAPI

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数・配列の初期化.
	TCHAR tszText1[] = _T("ABCDE");	// TCHAR型文字配列tszText1を"ABCDE"で初期化.
	TCHAR tszText2[16] = {0};		// TCHAR型文字配列tszText2(長さ16)を{0}で初期化.

	// コピー前の2つのテキストを出力.
	_tprintf(_T("before:\n"));	// "before:"と出力.
	_tprintf(_T("tszText1 = %s\n"), tszText1);	// tszText1の出力.
	_tprintf(_T("tszText2 = %s\n"), tszText2);	// tszText2の出力.

	// テキストのコピー.
	lstrcpy(tszText2, tszText1);	// lstrcpyでtszText1をtszText2にコピー.

	// コピー後の2つのテキストを出力.
	_tprintf(_T("after:\n"));	// "after:"と出力.
	_tprintf(_T("tszText1 = %s\n"), tszText1);	// tszText1の出力.
	_tprintf(_T("tszText2 = %s\n"), tszText2);	// tszText2の出力.

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}
