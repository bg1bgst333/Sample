// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <shlwapi.h>	// シェルAPI

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 配列の初期化
	TCHAR tszModulePath[MAX_PATH] = {0};	// tszModulePath(長さMAX_PATH)を{0}で初期化.

	// 現在実行中の実行ファイルのフルパスを取得.
	GetModuleFileName(NULL, tszModulePath, MAX_PATH);	// GetModuleFileNameでこの実行ファイルのフルパスを取得.

	// パスを出力.
	_tprintf(_T("tszModulePath = %s\n"), tszModulePath);	// tszModulePathを出力.

	// ファイル名の部分を取り除き, 所属するフォルダパスを取得する.
	PathRemoveFileSpec(tszModulePath);	// PathRemoveFileSpecでファイル名の部分を取り除く.

	// パスを出力.
	_tprintf(_T("tszModulePath = %s\n"), tszModulePath);	// tszModulePathを出力.

	// プログラムの終了.
	return 0;

}