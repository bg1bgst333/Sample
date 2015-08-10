// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <cstdio>		// 標準入出力
#include <tchar.h>		// TCHAR対応

// DllFunc用の関数ポインタ型
typedef void (*DLLFUNC)(void);	// typedefで引数, 戻り値, ともにvoidな関数ポインタ型DLLFUNCを定義.

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言
	HMODULE hDll;		// HMODULE型ハンドルhDll
	DLLFUNC DllFunc;	// GetProcAddressが返す指名した関数へのポインタ.

	// LoadLibraryによるDLLの読み込み前.
	_tprintf(_T("LoadLibrary before.\n"));	// _tprintfで"LoadLibrary before.\n"と出力.

	// GetProcAddress.dllの読み込み.
	hDll = LoadLibrary(_T("GetProcAddress.dll"));	// LoadLibraryで"GetProcAddress.dll"をロードし, 戻り値はhDllに格納.

	// LoadLibraryがNULLなら失敗.
	if (hDll == NULL){	// NULLなら失敗.

		// エラー処理.
		_tprintf(_T("LoadLibrary failed!\n"));	// _tprintfで"LoadLibrary failed!\n"と出力.
		return -1;

	}

	// NULLでなければ, hDllを出力.
	_tprintf(_T("hDll = %08x\n"), hDll);	// _tprintfでhDllの値を出力.

	// DLLにある外部参照可能な関数へのポインタを取得する.
	DllFunc = (DLLFUNC)GetProcAddress(hDll, "DllFunc");	// GetProcAddressで"DllFunc"へのポインタを取得.
	if (DllFunc == NULL){	// DllFuncなら呼び出し失敗.

		// エラー処理.
		FreeLibrary(hDll);	// FreeLibraryでhDllを解放.
		_tprintf(_T("GetProcAddress failed!\n"));	// _tprintfで"GetProcAddress failed!\n"と出力.
		return -1;

	}

	// DllFuncを呼ぶ.
	DllFunc();	// GetProcAddressで取得したDllFuncを呼び出す.

	// GetProcAddress.dllの解放.
	FreeLibrary(hDll);	// FreeLibraryでhDllを解放.

	// FreeLibraryによるDLLの解放後.
	_tprintf(_T("FreeLibrary after.\n"));	// _tprintfで"FreeLibrary after.\n"と出力.

	// プログラムの終了
	return 0;

}