// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <shlwapi.h>	// シェルAPI

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言と初期化.
	TCHAR tszModulePath[MAX_PATH] = {0};	// tszModulePath(長さMAX_PATH)を{0}で初期化.
	HANDLE hFile = NULL;	// HANDLE型ファイルハンドルhFileをNULLで初期化.
	DWORD dwFileSize = 0;	// ファイルサイズdwFileSizeを0で初期化.
	BYTE *pBytes = NULL;	// BYTE動的配列ポインタpBytesをNULLで初期化.
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
	LONG lFlag = 0;	// LONG型lFlagを0で初期化.
	HGLOBAL hDevMode = NULL;	// HGLOBAL型hDevModeをNULLで初期化.
	DOC_INFO_1 di1 = {0};	// DOC_INFO_1構造体di1を{0}で初期化.
	DWORD dwJob = 0;	// DWORD型dwJobを0で初期化.
	BOOL bPage = FALSE;	// BOOL型のbPageをFALSEで初期化.
	BOOL bWrite = FALSE;	// BOOL型のbWriteをFALSEで初期化.
	DWORD dwWritten = 0;	// DWORD型のdwWrittenを0で初期化.

	// test_text.txtのパスを生成.
	GetModuleFileName(NULL, tszModulePath, MAX_PATH);	// GetModuleFileNameでこの実行ファイルのフルパスを取得.
	PathRemoveFileSpec(tszModulePath);	// PathRemoveFileSpecでファイル名の部分を取り除く.
	_tcscat(tszModulePath, _T("\\test_text.txt"));	// _tcscatで"\test_text.txt"を連結.
	_tprintf(_T("tszModulePath = %s\n"), tszModulePath);	// tszModulePathを出力.

	// test_text.txtの読み込み.
	hFile = CreateFile(tszModulePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFileでtszModulePathを開いて, 取得したハンドルをhFileに格納.
	if (hFile == INVALID_HANDLE_VALUE){	// hFileがINVALID_HANDLE_VALUEなら.
		_tprintf(_T("test_text.txt not found.\n"));	// "test_text.txt not found."を出力.
		return -1;	// -1を返して異常終了.
	}
	dwFileSize = GetFileSize(hFile, NULL);	// GetFileSizeで"test_text.txt"のファイルサイズを取得する.
	_tprintf(_T("dwFileSize = %lu\n"), dwFileSize);	// dwFileSizeの出力.
	pBytes = new BYTE[dwFileSize];	// BYTE配列を確保.
	ReadFile(hFile, pBytes, dwFileSize, &dwFileSize, NULL);	// ReadFileでhFileの内容をpBytesに読み込む.
	CloseHandle(hFile);	// CloseHandleでhFileを閉じる.

	// バッファサイズを取得.
	GetDefaultPrinter(NULL, &dwSize);	// GetDefaultPrinterにNULLを渡してバッファサイズを取得.

	// バッファの確保.
	ptszBuf = new TCHAR[dwSize];	// サイズdwSize分のバッファ確保.

	// 既定のプリンタ名を取得.
	GetDefaultPrinter(ptszBuf, &dwSize);	// GetDefaultPrinterでプリンタ名を取得し, バッファに格納.

	// 既定のプリンタ名の出力.
	_tprintf(_T("Default Printer: %s\n"), ptszBuf);	// ptszBufを出力.

	// 設定変更.
	// プリンタを開く.
	//pd.DesiredAccess = PRINTER_ACCESS_USE;	// ユーザ権限.
	pd.DesiredAccess = PRINTER_ALL_ACCESS;	// 全ての権限.
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
							if (pi2->pDevMode != NULL){	// DEVMODEへのポインタがあれば.
								_tprintf(_T("GetPrinter Get OK!\n"));	// "GetPrinter Get OK!"と出力.
								// さまざまな情報を出力.
								_tprintf(_T("pi2->pDevMode->dmDeviceName = %s\n"), pi2->pDevMode->dmDeviceName);	// pi2->pDevMode->dmDeviceNameを出力.
								_tprintf(_T("pi2->pPrinterName = %s\n"), pi2->pPrinterName);	// pi2->pPrinterNameを出力.
								_tprintf(_T("pi2->pPortName = %s\n"), pi2->pPortName);	// pi2->pPortNameを出力.
								_tprintf(_T("pi2->pDriverName = %s\n"), pi2->pDriverName);	// pi2->pDriverNameを出力.
								_tprintf(_T("pi2->pPrintProcessor = %s\n"), pi2->pPrintProcessor);	// pi2->pPrintProcessorを出力.
								_tprintf(_T("pi2->pDatatype = %s\n"), pi2->pDatatype);	// pi2->pDatatypeを出力.
								// 印刷方向を横にする.
								pi2->pDevMode->dmFields = DM_ORIENTATION;	// 方向を設定.
								pi2->pDevMode->dmOrientation = DMORIENT_LANDSCAPE;	// 横に設定.
								lFlag = DocumentProperties(NULL, hPrinter, ptszBuf, pi2->pDevMode, pi2->pDevMode, DM_IN_BUFFER | DM_OUT_BUFFER);	// DocumentPropertiesでデバイス依存部分のアップデート.
								if (lFlag == IDOK){	// IDOKなら.
									_tprintf(_T("DocumentProperties Update OK!\n"));	// "DocumentProperties Update OK!"と出力.
									lFlag = SetPrinter(hPrinter, 2, (LPBYTE)pi2, 0);	// SetPrinterで更新した設定をプリンタに反映.
									if (lFlag > 0){	// 0以上.
										_tprintf(_T("SetPrinter OK!\n"));	// "SetPrinter OK!"を出力.
									}
									else{	// 負の値.
										DWORD e = GetLastError();	// GetLstErrorでエラー番号取得.
										_tprintf(_T("SetPrinter NG! e = %lu\n"), e);	// "SetPrinter NG!"とエラー番号を出力.
									}
								}
							}
							else{	// DEVMODEのポインタがNULLの時.
								_tprintf(_T("pi2->pDevMode == NULL!\n"));	// NULLであることを出力.
								// DocumentPropertiesで取得する方法.
								dwNeeded = DocumentProperties(NULL, hPrinter, ptszBuf, NULL, NULL, 0);	// まずサイズを取得.
								if (dwNeeded > 0){	// 0より大きい.
									hDevMode = GlobalAlloc(GHND, dwNeeded);	// dwNeeded分のメモリ確保.
									if (hDevMode != NULL){	// NULLでない時.
										pi2->pDevMode = (DEVMODE *)GlobalLock(hDevMode);	// pi2->pDevModeにロックしたメモリのポインタを格納.
										if (pi2->pDevMode != NULL){	// NULLでない.
											lFlag = DocumentProperties(NULL, hPrinter, ptszBuf, pi2->pDevMode, NULL, DM_OUT_BUFFER);	// DocumentPropertiesでDEVMODEを取得.
											if (lFlag == IDOK){	// IDOKなら.
												_tprintf(_T("DocumentProperties Get OK!\n"));	// "DocumentProperties Get OK!"と出力.
												// 印刷方向を横にする.
												pi2->pDevMode->dmFields = DM_ORIENTATION;	// 方向を設定.
												pi2->pDevMode->dmOrientation = DMORIENT_LANDSCAPE;	// 横に設定.
												lFlag = DocumentProperties(NULL, hPrinter, ptszBuf, pi2->pDevMode, pi2->pDevMode, DM_IN_BUFFER | DM_OUT_BUFFER);	// DocumentPropertiesでデバイス依存部分のアップデート.
												if (lFlag == IDOK){	// IDOKなら.
													_tprintf(_T("DocumentProperties Update OK!\n"));	// "DocumentProperties Update OK!"と出力.
													lFlag = SetPrinter(hPrinter, 2, (LPBYTE)pi2, 0);	// SetPrinterで更新した設定をプリンタに反映.
													if (lFlag > 0){	// 0より大きい.
														_tprintf(_T("SetPrinter OK!\n"));	// "SetPrinter OK!"を出力.
													}
													else{	// 負の値.
														DWORD e = GetLastError();	// GetLstErrorでエラー番号取得.
														_tprintf(_T("SetPrinter NG! e = %lu\n"), e);	// "SetPrinter NG!"とエラー番号を出力.
													}
												}
											}
											GlobalUnlock(hDevMode);	// アンロック.
										}
										GlobalFree(hDevMode);	// 解放.
									}
								}
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

	// 印刷.
	// プリンタを開く.
	bOpen = OpenPrinter(ptszBuf, &hPrinter, NULL);	// OpenPrinterでプリンタ名ptszBufとなるプリンタを開く.
	if (bOpen){	// プリンタを開けたら.
		if (hPrinter != NULL){	// NULLではない.
			_tprintf(_T("hPrinter = 0x%08x\n"), (unsigned long)hPrinter);	// hPrinterの値を出力.
			// di1の設定.
			di1.pDocName = _T("StartPagePrinter");	// ドキュメント名は"StartPagePrinter".
			di1.pOutputFile = NULL;	// 出力ファイルはひとまずNULL.
			di1.pDatatype = _T("TEXT");	// "TEXT"モードにしてみる.
			// ドキュメントの開始.
			dwJob = StartDocPrinter(hPrinter, 1, (LPBYTE)&di1);	// StartDocPrinterでドキュメント開始, dwJobを取得.
			if (dwJob > 0){	// 0より大きいなら成功.
				_tprintf(_T("dwJob = %lu\n"), dwJob);	// dwJobを出力.
				// ページの開始.
				bPage = StartPagePrinter(hPrinter);	// StartPagePrinterでページの開始.
				if (bPage){	// TRUEなら成功.
					bWrite = WritePrinter(hPrinter, pBytes, dwFileSize, &dwWritten);	// WritePrinterで書き込み.
					if (bWrite){	// TRUEなら成功.
						_tprintf(_T("dwFileSize = %lu\n"), dwFileSize);	// dwFileSizeを出力.
						_tprintf(_T("dwWritten = %lu\n"), dwWritten);	// dwWrittenを出力.
					}
					EndPagePrinter(hPrinter);	// EndPagePrinterでページの終了.
				}
				EndDocPrinter(hPrinter);	// ドキュメントの終了.
			}
			ClosePrinter(hPrinter);	// ClosePrinterでhPrinterを閉じる.
		}
	}

	// バッファの解放.
	delete[] ptszBuf;	// ptszBufの解放.
	delete[] pBytes;	// pBytesを解放.

	// プログラムの終了.
	return 0;

}