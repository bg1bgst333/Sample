// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言と初期化.
	DWORD dwSize = 0;	// サイズdwSizeを0で初期化.
	TCHAR *ptszBuf = NULL;	// 文字列バッファポインタptszBufをNULLで初期化.
	BOOL bOpen = FALSE;	// BOOL型のbOpenをFALSEで初期化.
	HANDLE hPrinter = NULL;	// HANDLE型hPrinterをNULLで初期化.
	PRINTER_DEFAULTS pd = {0};	// PRINTER_DEFAULTS構造体pdを{0}で初期化.
	DWORD dwNeeded = 0;	// DWORD型dwNeededを0で初期化.
	HGLOBAL hPrinterInfo2 = NULL;	// HGLOBAL型hPrinterInfo2をNULLで初期化.
	PRINTER_INFO_2 *pi2 = NULL;	// PRINTER_INFO_2構造体ポインタpi2をNULLで初期化.
	BOOL bRet = FALSE;	// BOOL型bRetをFALSEで初期化.
	TCHAR tszDMDeviceName[CCHDEVICENAME + 64] = {0};	// tszDMDeviceNameを{0}で初期化.(サイズはCCHDEVICENAME + 64.)

	// バッファサイズを取得.
	GetDefaultPrinter(NULL, &dwSize);	// GetDefaultPrinterにNULLを渡してバッファサイズを取得.

	// バッファの確保.
	ptszBuf = new TCHAR[dwSize];	// サイズdwSize分のバッファ確保.

	// 既定のプリンタ名を取得.
	GetDefaultPrinter(ptszBuf, &dwSize);	// GetDefaultPrinterでプリンタ名を取得し, バッファに格納.

	// 既定のプリンタ名の出力.
	_tprintf(_T("Default Printer: %s\n"), ptszBuf);	// ptszBufを出力.

	// プリンタを開く.
	pd.DesiredAccess = PRINTER_ACCESS_USE;	// ユーザ権限.
	bOpen = OpenPrinter(ptszBuf, &hPrinter, &pd);	// OpenPrinterでプリンタ名ptszBufとなるプリンタを開く.(この時, pdを渡す.)
	if (bOpen){	// プリンタを開けたら.
		if (hPrinter != NULL){	// NULLではない.
			_tprintf(_T("hPrinter = 0x%08x\n"), (unsigned long)hPrinter);	// hPrinterの値を出力.
			// プリンタ情報(Level2)の取得.
			GetPrinter(hPrinter, 2, NULL, 0, &dwNeeded);	// まずはGetPrinterにNULLを渡してLevel2で必要なサイズを取得.
			_tprintf(_T("dwNeeded = %lu\n"), dwNeeded);	// dwNeededを出力.
			if (dwNeeded > 0){	// 0より大きい.
				// メモリの確保.
				hPrinterInfo2 = GlobalAlloc(GHND, dwNeeded);	// GlobalAllocでdwNeeded分メモリ確保.
				if (hPrinterInfo2 != NULL){	// 確保成功.
					// メモリのロック.
					pi2 = (PRINTER_INFO_2 *)GlobalLock(hPrinterInfo2);	// GlobalLockでロックしてポインタを取得.
					if (pi2 != NULL){	// NULLでなければ.
						// プリンタ情報の取得.
						bRet = GetPrinter(hPrinter, 2, (LPBYTE)pi2, dwNeeded, &dwNeeded);	// GetPrinterでpi2を取得.
						if (bRet){	// TRUEなら.
							if (pi2->pDevMode){	// DEVMODEへのポインタがあれば.
								// さまざまな情報を出力.
								_tprintf(_T("pi2->pDevMode->dmDeviceName = %s\n"), pi2->pDevMode->dmDeviceName);	// pi2->pDevMode->dmDeviceNameを出力.
								_tprintf(_T("pi2->pPrinterName = %s\n"), pi2->pPrinterName);	// pi2->pPrinterNameを出力.
								_tprintf(_T("pi2->pPortName = %s\n"), pi2->pPortName);	// pi2->pPortNameを出力.
								_tprintf(_T("pi2->pDriverName = %s\n"), pi2->pDriverName);	// pi2->pDriverNameを出力.
								_tprintf(_T("pi2->pPrintProcessor = %s\n"), pi2->pPrintProcessor);	// pi2->pPrintProcessorを出力.
								_tprintf(_T("pi2->pDatatype = %s\n"), pi2->pDatatype);	// pi2->pDatatypeを出力.
							}
						}
						GlobalUnlock(hPrinterInfo2);	// アンロック.
					}
					GlobalFree(hPrinterInfo2);	// 解放.
				}
			}
			ClosePrinter(hPrinter);	// ClosePrinterでhPrinterを閉じる.
		}
	}

	// バッファの解放.
	delete[] ptszBuf;	// ptszBufの解放.

	// プログラムの終了.
	return 0;

}