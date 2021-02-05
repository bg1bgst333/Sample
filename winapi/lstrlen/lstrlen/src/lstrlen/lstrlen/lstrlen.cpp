// ヘッダファイルのインクルード
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <windows.h>	// 標準WindowsAPI

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数・配列の初期化.
	TCHAR tszText[] = _T("ABCDE");	// TCHAR型文字配列tszTextを"ABCDE"で初期化.
	int iLen = 0;	// テキストの長さiLenを0で初期化.

	// テキストの長さを取得.
	iLen = lstrlen(tszText);	// lstrlenでtszTextの長さを取得し, iLenに格納.

	// テキストと長さの出力.
	_tprintf(_T("tszText = %s\n"), tszText);	// tszTextの出力.
	_tprintf(_T("iLen = %d\n"), iLen);	// iLenの出力.

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}