// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <cstdio>		// 標準入出力
#include <tchar.h>		// TCHAR対応

// DllMain関数の定義
int WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved){	// DLLの読み込み時や解放時に呼ばれるエントリポイント.

	// "DllMain"と出力.
	_tprintf(_T("DllMain\n"));	// _tprintfで"DllMain\n"と出力.

	// 成功ならTRUE.
	return TRUE;	// 今回はDllMainの処理を成功とするのでTRUE.

}