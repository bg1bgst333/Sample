// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <cstdio>		// 標準入出力
#include <tchar.h>		// TCHAR対応

// 外部から参照できる関数の宣言.
extern "C" __declspec(dllexport) void DllFunc(void);	// 関数DllFunc

// DllMain関数の定義
int WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved){	// DLLの読み込み時や解放時に呼ばれるエントリポイント.

	// DllMainを呼び出す理由を表すマクロが格納されたfdwReasonごとに振り分ける.
	switch (fdwReason){	// fdwReasonごとにswitch-case文で分岐.

		// プロセスがアタッチされた時.
		case DLL_PROCESS_ATTACH:	// DLL_PROCESS_ATTACHの時.

			// DLL_PROCESS_ATTACHブロック
			{

				// "DLL_PROCESS_ATTACH\n"を出力.
				_tprintf(_T("DLL_PROCESS_ATTACH\n"));	// _tprintfで"DLL_PROCESS_ATTACH\n"と出力.

			}

			// 抜ける.
			break;	// breakで抜ける.

		// プロセスがデタッチされた時.
		case DLL_PROCESS_DETACH:	// DLL_PROCESS_DETACHの時.

			// DLL_PROCESS_DETACHブロック
			{

				// "DLL_PROCESS_DETACH\n"を出力.
				_tprintf(_T("DLL_PROCESS_DETACH\n"));	// _tprintfで"DLL_PROCESS_DETACH\n"と出力.

			}

			// 抜ける.
			break;	// breakで抜ける.

		// スレッドがアタッチされた時.
		case DLL_THREAD_ATTACH:	// DLL_THREAD_ATTACHの時.
			
			// DLL_THREAD_ATTACHブロック
			{

				// "DLL_THREAD_ATTACH\n"を出力.
				_tprintf(_T("DLL_THREAD_ATTACH\n"));	// _tprintfで"DLL_THREAD_ATTACH\n"と出力.

			}

			// 抜ける.
			break;	// breakで抜ける.

		// スレッドがデタッチされた時.
		case DLL_THREAD_DETACH:	// DLL_THREAD_DETACHの時.

			// DLL_THREAD_DETACHブロック
			{

				// "DLL_THREAD_DETACH\n"を出力.
				_tprintf(_T("DLL_THREAD_DETACH\n"));	// _tprintfで"DLL_THREAD_DETACH\n"と出力.

			}

			// 抜ける.
			break;	// breakで抜ける.

		// それ以外.
		default:

			// 抜ける.
			break;	// breakで抜ける.

	}

	// 成功ならTRUE.
	return TRUE;	// 今回はDllMainの処理を成功とするのでTRUE.

}

// 関数DllFuncの定義.
extern "C" __declspec(dllexport) void DllFunc(void){	// 外部から呼び出せる関数DllFunc.

	// "DllFunc 1!\n"と出力.
	_tprintf(_T("DllFunc 1!\n"));	// _tprintfで"DllFunc 1!\n"と出力.

}