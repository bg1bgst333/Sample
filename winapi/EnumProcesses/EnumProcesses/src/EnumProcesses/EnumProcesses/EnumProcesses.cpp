// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <psapi.h>		// プロセス

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言と初期化.
	DWORD dwProcessIds[1024] = {0};	// プロセスID配列dwProcessIds(要素数1024)を{0}で初期化.
	DWORD cbNeeded = 0;	// 実際のサイズcbNeededを0で初期化.
	BOOL bEnum = FALSE;	// EnumProcessesの結果を保持するbEnumをFALSEで初期化.
	DWORD dwNum = 0;	// 実際の要素数dwNumを0で初期化.
	DWORD dwIndex = 0;	// ループ用変数dwIndexを0で初期化.
	
	// プロセスIDの列挙
	bEnum = EnumProcesses(dwProcessIds, sizeof(dwProcessIds), &cbNeeded);	// EnumProcessesでプロセス配列を取得.
	if (bEnum){	// TRUEなら.
		// 配列サイズの出力.
		_tprintf(_T("sizeof(dwProcessIds) = %lu\n"), sizeof(dwProcessIds));	// 配列サイズの出力.
		// 実際に必要なサイズの出力.
		_tprintf(_T("cbNeeded = %lu\n"), cbNeeded);	// 実際のサイズを出力.
		// 実際に必要な要素数.
		dwNum = cbNeeded / sizeof(DWORD);	// 実際のサイズをDWORDのサイズで割る.
		_tprintf(_T("dwNum = %lu\n"), dwNum);	// 実際の要素数を出力.
		// 各要素の出力.
		for (dwIndex = 0; dwIndex < dwNum; dwIndex++){	// dwNum分繰り返す.
			_tprintf(_T("dwProcessIds[%lu] = %lu\n"), dwIndex, dwProcessIds[dwIndex]);	// プロセスIDの出力.
		}
	}

	// プログラムの終了
	return 0;

}