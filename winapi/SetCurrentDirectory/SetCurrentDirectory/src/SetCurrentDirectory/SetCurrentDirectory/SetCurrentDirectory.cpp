// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 配列の初期化
	TCHAR tszCurrentPath[MAX_PATH] = {0};	// このプロセスの現在のディレクトリパスを指すTCHAR配列tszCurrentPath(長さMAX_PATH)を{0}で初期化.

	// このプロセスの現在のディレクトリパスを取得.
	DWORD dwRet = GetCurrentDirectory(MAX_PATH, tszCurrentPath);	// GetCurrentDirectoryでtszCurrentPathを取得.
	if (dwRet != 0){	// 成功.
		_tprintf(_T("tszCurrentPath = %s\n"), tszCurrentPath);	// tszCurrentPathを出力.
	}
	else{	// 失敗.
		_tprintf(_T("GetCurrentDirectory failed.\n"));	// "GetCurrentDirectory failed."を出力.
	}

	// 絶対パス設定
	// 2つ上のディレクトリパスを取得する.
	TCHAR tszTwoUpPath[MAX_PATH] = {0};	// 2つ上のディレクトリパスを格納するTCHAR型配列tszTwoUpPath(長さMAX_PATH)を{0}で初期化.
	TCHAR *ptszFilePart = NULL;	// パスのファイル名部分を指すTCHAR型ポインタptszFilePartをNULLで初期化.
	TCHAR tszRelativePath[MAX_PATH] = {0};	// 相対パスtszRelativePath(長さMAX_PATH)を{0}で初期化.
	_stprintf(tszRelativePath, _T("%s\\..\\.."), tszCurrentPath);	// tszRelativePathに"\\..\\.."を連結.
	dwRet = GetFullPathName(tszRelativePath, MAX_PATH, tszTwoUpPath, &ptszFilePart);	// GetFullPathNameでtszRelativePathのフルパスtszTwoUpPathを取得.
	if (dwRet != 0){	// 0以外なら成功.
		_tprintf(_T("tszTwoUpPath = %s\n"), tszTwoUpPath);	// tszTwoUpPathを出力.
	}
	else{	// 0なら失敗.
		_tprintf(_T("GetFullPathName failed.\n"));	// "GetFullPathName failed."を出力.
	}
	// このプロセスの現在のディレクトリパスに, 2つ上のディレクトリパスを設定する.
	BOOL bRet = SetCurrentDirectory(tszTwoUpPath);	// SetCurrentDirectoryでtszTwoUpPathをセット.
	if (bRet){	// TRUEなら成功.
		_tprintf(_T("SetCurrentDirectory success.\n"));	// "GetCurrentDirectory success."を出力.
		// 再び現在のパス取得.
		TCHAR tszCurrentPath[MAX_PATH] = {0};	// このプロセスの現在のディレクトリパスを指すTCHAR配列tszCurrentPath(長さMAX_PATH)を{0}で初期化.
		DWORD dwRet = GetCurrentDirectory(MAX_PATH, tszCurrentPath);	// GetCurrentDirectoryでtszCurrentPathを取得.
		if (dwRet != 0){	// 成功.
			_tprintf(_T("tszCurrentPath = %s\n"), tszCurrentPath);	// tszCurrentPathを出力.
		}
		else{	// 失敗.
			_tprintf(_T("GetCurrentDirectory failed.\n"));	// "GetCurrentDirectory failed."を出力.
		}
	}
	else{
		_tprintf(_T("SetCurrentDirectory failed.\n"));	// "SetCurrentDirectory failed."を出力.
	}

	// 相対パス設定
	// さらに1つ上のパスを設定.
	bRet = SetCurrentDirectory(_T(".."));	// SetCurrentDirectoryで".."をセット.
	if (bRet){	// TRUEなら成功.
		_tprintf(_T("SetCurrentDirectory success.\n"));	// "GetCurrentDirectory success."を出力.
		// 再び現在のパス取得.
		TCHAR tszCurrentPath[MAX_PATH] = {0};	// このプロセスの現在のディレクトリパスを指すTCHAR配列tszCurrentPath(長さMAX_PATH)を{0}で初期化.
		DWORD dwRet = GetCurrentDirectory(MAX_PATH, tszCurrentPath);	// GetCurrentDirectoryでtszCurrentPathを取得.
		if (dwRet != 0){	// 成功.
			_tprintf(_T("tszCurrentPath = %s\n"), tszCurrentPath);	// tszCurrentPathを出力.
		}
		else{	// 失敗.
			_tprintf(_T("GetCurrentDirectory failed.\n"));	// "GetCurrentDirectory failed."を出力.
		}
	}
	else{
		_tprintf(_T("SetCurrentDirectory failed.\n"));	// "SetCurrentDirectory failed."を出力.
	}

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}