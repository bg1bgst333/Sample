// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言と初期化.
	PRINTER_INFO_1 *pPrnInfo1 = NULL;	// プリンタ情報PRINTER_INFO_1のポインタpPrnInfo1をNULLで初期化.
	LPBYTE pPrnList = NULL;	// プリンタリストpPrnListをNULLで初期化.
	DWORD dwNeeded = 0;	// 必要なサイズdwNeededを0で初期化.
	DWORD dwReturned = 0;	// 返ってきたサイズdwReturnedを0で初期化.
	DWORD dwIndex = 0;	// ループ用変数dwIndexを0で初期化.

	// プリンタ情報を格納する必要なサイズを取得.
	EnumPrinters(PRINTER_ENUM_LOCAL, NULL, 1, NULL, 0, &dwNeeded, &dwReturned);	// EnumPrintersでNULLなどを指定して必要サイズを取得.

	// 必要なバッファを確保.
	pPrnList = (LPBYTE)LocalAlloc(LPTR, dwNeeded);	// LocalAllocでdwNeeded分メモリを確保.

	// プリンタ情報を取得.
	EnumPrinters(PRINTER_ENUM_LOCAL, NULL, 1, pPrnList, dwNeeded, &dwNeeded, &dwReturned);	// EnumPrintersでプリンタ情報を取得.

	// プリンタリストポインタをPRINTER_INFO_1ポインタにキャスト.
	pPrnInfo1 = (PRINTER_INFO_1 *)pPrnList;	// pPrnInfo1にキャスト.

	// for文でプリンタ名を出力.
	for (dwIndex = 0; dwIndex < dwReturned; dwIndex++){	// dwReturnedの分繰り返す.
		_tprintf(_T("pPrnInfo1->pName = %s\n"), pPrnInfo1->pName);	// pPrnInfo1->pNameを出力.
		pPrnInfo1++;	// pPrnInfo1をインクリメント.
	}

	// バッファの解放.
	LocalFree(pPrnList);	// LocalFreeでpPrnListを解放.

	// プログラムの終了.
	return 0;

}