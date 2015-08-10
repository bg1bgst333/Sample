// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <cstdio>		// 標準入出力
#include <tchar.h>		// TCHAR対応

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言
	HMODULE hDll;	// HMODULE型ハンドルhDll

	// LoadLibraryによるDLLの読み込み前.
	_tprintf(_T("LoadLibrary before.\n"));	// _tprintfで"LoadLibrary before.\n"と出力.

	// DllMain.dllの読み込み.
	hDll = LoadLibrary(_T("DllMain.dll"));	// LoadLibraryで"DllMain.dll"をロードし, 戻り値はhDllに格納.

	// LoadLibraryがNULLなら失敗.
	if (hDll == NULL){	// NULLなら失敗.

		// エラー処理.
		_tprintf(_T("LoadLibrary failed!\n"));	// _tprintfで"LoadLibrary failed!\n"と出力.
		return -1;

	}

	// NULLでなければ, hDllを出力.
	_tprintf(_T("hDll = %08x\n"), hDll);	// _tprintfでhDllの値を出力.

	// DllMain.dllの解放.
	FreeLibrary(hDll);	// FreeLibraryでhDllを解放.

	// FreeLibraryによるDLLの解放後.
	_tprintf(_T("FreeLibrary after.\n"));	// _tprintfで"FreeLibrary after.\n"と出力.

	// プログラムの終了
	return 0;

}