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

	// プリンタを開く.
	bOpen = OpenPrinter(ptszBuf, &hPrinter, NULL);	// OpenPrinterでプリンタ名ptszBufとなるプリンタを開く.
	if (bOpen){	// プリンタを開けたら.
		if (hPrinter != NULL){	// NULLではない.
			_tprintf(_T("hPrinter = 0x%08x\n"), (unsigned long)hPrinter);	// hPrinterの値を出力.
			// di1の設定.
			di1.pDocName = _T("WritePrinter");	// ドキュメント名は"WritePrinter".
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