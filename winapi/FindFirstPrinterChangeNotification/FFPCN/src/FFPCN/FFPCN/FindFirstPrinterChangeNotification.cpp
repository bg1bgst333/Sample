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
	BOOL bOpen = FALSE;	// プリンタが開けたかを表すbOpenをFALSEで初期化.
	HANDLE hChangeNotify = NULL;	// 変更通知ハンドルhChangeNotifyをNULLで初期化.

	// 既定のプリンタ名を取得.
	GetDefaultPrinter(NULL, &dwSize);	// GetDefaultPrinterにNULLを渡してバッファサイズを取得.
	ptszBuf = new TCHAR[dwSize];	// dwSize分のバッファを確保.
	GetDefaultPrinter(ptszBuf, &dwSize);	// GetDefaultPrinterで既定のプリンタ名を取得.
	_tprintf(_T("Default Printer: %s\n"), ptszBuf);	// ptszBufを出力.

	// プリンタハンドルの取得.
	bOpen = OpenPrinter(ptszBuf, &hPrinter, NULL);	// OpenPrinterでプリンタ名ptszBufのプリンタを開く.
	if (bOpen){	// 成功.
		if (hPrinter != NULL){	// プリンタハンドルはNULLではない.
			_tprintf(_T("hPrinter: 0x%08x\n"), (unsigned long)hPrinter);	// hPrinterを出力.

			// 変更通知ハンドルの取得.
			hChangeNotify = FindFirstPrinterChangeNotification(hPrinter, PRINTER_CHANGE_ALL, 0, NULL);	// FindFirstPrinterChangeNotificationで変更通知ハンドル取得.
			_tprintf(_T("hChangeNotify: 0x%08x\n"), (unsigned long)hChangeNotify);	// hChangeNotifyを出力.
			CloseHandle(hChangeNotify);	// とりあえずはhChangeNotifyをCloseHandleで閉じる.

			ClosePrinter(hPrinter);	// ClosePrinterでhPrinterを閉じる.
		}
	}

	// メモリ解放.
	delete[] ptszBuf;	// ptszBufを解放.

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}