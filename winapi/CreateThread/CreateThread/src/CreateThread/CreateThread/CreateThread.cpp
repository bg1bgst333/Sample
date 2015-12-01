// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力

// ThreadProc関数の定義
DWORD WINAPI ThreadProc(LPVOID lpParameter){

	// 変数の宣言
	int i;	// ループ用変数i

	// 1から5までを出力.
	for (i = 1; i <= 5; i++){	// 1から5まで5回繰り返す.

		// iを出力.
		_tprintf(_T("i = %d\n"), i);	// _tprintfでiの値を出力.
		Sleep(1000);	// Sleepで1秒休止.

	}

	// スレッドの終了
	return 0;	// 0を返す.

}

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 配列の宣言
	int i;					// ループ型変数i.
	HANDLE hThread[5];		// HANDLE型スレッドハンドル配列hThread(要素数5).
	DWORD dwThreadId[5];	// DWORD型スレッドID配列dwThreadId(要素数5).

	// スレッドの一斉開始
	for (i = 0; i < 5; i++){	// 5回繰り返す.

		// スレッド開始
		hThread[i] = CreateThread(NULL, 0, ThreadProc, NULL, 0, &dwThreadId[i]);	// CreateThreadでスレッド生成及び開始.
		if (hThread[i] != NULL){	// hThread[i]がNULLでない.
			CloseHandle(hThread[i]);	// CloseHandleでhThread[i]を閉じる.
		}

	}

	// スレッドが終わるまで休止.
	Sleep(5000);	// Sleepで5秒休止.

	// プログラムの終了
	return 0;

}