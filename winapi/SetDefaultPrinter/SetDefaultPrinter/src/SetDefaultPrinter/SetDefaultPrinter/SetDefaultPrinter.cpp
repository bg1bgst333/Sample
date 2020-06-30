// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言と初期化.
	DWORD dwSize = 0;	// サイズdwSizeを0で初期化.
	TCHAR *ptszBuf = NULL;	// 文字列バッファポインタptszBufをNULLで初期化.
	TCHAR tszNew[256] = {0};	// TCHAR配列(長さ256)tszNewを{0}で初期化.

	// バッファサイズを取得.
	GetDefaultPrinter(NULL, &dwSize);	// GetDefaultPrinterにNULLを渡してバッファサイズを取得.

	// バッファの確保.
	ptszBuf = new TCHAR[dwSize];	// サイズdwSize分のバッファ確保.

	// 既定のプリンタ名を取得.
	GetDefaultPrinter(ptszBuf, &dwSize);	// GetDefaultPrinterでプリンタ名を取得し, バッファに格納.

	// 既定のプリンタ名の出力.
	_tprintf(_T("Default Printer: %s\n"), ptszBuf);	// ptszBufを出力.

	// バッファの解放.
	delete[] ptszBuf;	// ptszBufの解放.
	ptszBuf = NULL;	// NULLをセット.

	// 入力フォームの出力.
	_tprintf(_T("New Default Printer: "));	// 新しい既定のプリンタの入力フォームの出力.

	// 入力の受付.
	_fgetts(tszNew, 256, stdin);	// 入力文字列をtszNewに格納.

	// 改行の除去.
	tszNew[_tcslen(tszNew) - 1] = _T('\0');	// 末尾にNULL文字をセット.

	// 既定のプリンタにセット.
	SetDefaultPrinter(tszNew);	// SetDefaultPrinterでtszNewを既定のプリンタにセット.

	// バッファサイズを取得.
	GetDefaultPrinter(NULL, &dwSize);	// GetDefaultPrinterにNULLを渡してバッファサイズを取得.

	// バッファの確保.
	ptszBuf = new TCHAR[dwSize];	// サイズdwSize分のバッファ確保.

	// 既定のプリンタ名を取得.
	GetDefaultPrinter(ptszBuf, &dwSize);	// GetDefaultPrinterでプリンタ名を取得し, バッファに格納.

	// 既定のプリンタ名の出力.
	_tprintf(_T("Default Printer: %s\n"), ptszBuf);	// ptszBufを出力.

	// バッファの解放.
	delete[] ptszBuf;	// ptszBufの解放.
	ptszBuf = NULL;	// NULLをセット.

	// プログラムの終了.
	return 0;

}