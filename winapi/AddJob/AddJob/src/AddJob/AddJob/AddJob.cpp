// ヘッダファイルのインクルード
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <windows.h>	// 標準WindowsAPI

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言と初期化.
	DWORD dwSize = 0;	// バッファサイズdwSizeを0で初期化.
	TCHAR *ptszBuf = NULL;	// プリンタ名を格納する文字列バッファポインタptszBufをNULLで初期化.
	HANDLE hPrinter = NULL;	// プリンタハンドルhPrinterをNULLで初期化.
	PRINTER_DEFAULTS pd = {0};	// PRINTER_DEFAULTS構造体pdを{0}で初期化.
	BOOL bOpen = FALSE;	// プリンタが開けたかを表すbOpenをFALSEで初期化.
	int aji1Size = sizeof(ADDJOB_INFO_1) + MAX_PATH + 1;	// aji1Sizeの初期化.
	ADDJOB_INFO_1 *aji1 = NULL;	// ADDJOB_INFO_1構造体aji1をNULLで初期化.
	DWORD dwNeeded = 0;	// 必要サイズdwNeededを0で初期化.
	int rc = 0;	// AddJobの戻り値rcを0で初期化.

	// 既定のプリンタ名を取得.
	GetDefaultPrinter(NULL, &dwSize);	// GetDefaultPrinterにNULLを渡してバッファサイズを取得.
	ptszBuf = new TCHAR[dwSize];	// dwSize分のバッファを確保.
	GetDefaultPrinter(ptszBuf, &dwSize);	// GetDefaultPrinterで既定のプリンタ名を取得.
	_tprintf(_T("Default Printer: %s\n"), ptszBuf);	// ptszBufを出力.

	// 既定のプリンタを開く.
	pd.DesiredAccess = PRINTER_ACCESS_USE;	// ユーザ権限.
	bOpen = OpenPrinter(ptszBuf, &hPrinter, &pd);	// OpenPrinterでプリンタ名ptszBufのプリンタを開く.
	if (bOpen){	// 成功.
		if (hPrinter != NULL){	// プリンタハンドルはNULLではない.
			_tprintf(_T("hPrinter: 0x%08x\n"), (unsigned long)hPrinter);	// hPrinterを出力.

			// 印刷ジョブの追加.
			aji1 = (ADDJOB_INFO_1 *)new BYTE[aji1Size];	// aji1Sizeのメモリを確保し, aji1に格納.
			rc = AddJob(hPrinter, 1, (LPBYTE)aji1, aji1Size, &dwNeeded);	// AddJobで印刷ジョブ追加.
			if (rc != 0){	// rcが0以外なら成功.(AddJobの戻り値は本来BOOLだが、int型rcで取っている.この謎は別途記事を参照.)
				MessageBox(NULL, _T("Debug Stop!"), _T("AddJob"), MB_OK);	// MessageBoxでデバッグ用に一旦処理をとめる.
			}
			delete[] aji1;	// aji1を解放.

			ClosePrinter(hPrinter);	// ClosePrinterでhPrinterを閉じる.
		}
	}

	// メモリ解放.
	delete[] ptszBuf;	// ptszBufを解放.

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}