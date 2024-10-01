// ヘッダファイルのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR対応
#include <locale.h>		// ロケール

// 独自のヘッダ
#include "Excel/Application.h"	// Excel::CApplication

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]) {	// main関数のTCHAR版.

	// COMの初期化.
	CoInitialize(NULL);	// CoInitializeでCOMを初期化.

	// Excel::CApplicationの生成
	Excel::CApplication *pApplication = Excel::CApplication::CreateInstance();	// Excel::CApplication::CreateInstanceで作成.

	// 取得したpApplicationを出力.
	_tprintf(_T("pApplication = 0x%08x\n"), (unsigned long)pApplication);	// pApplicationを出力.

	// アプリケーションの表示.
	pApplication->put_Visible(TRUE);	// Excel::CApplication::put_VisibleにTRUE渡して表示.

	// Workbooksの取得.
	Excel::CWorkbooks * pWorkbooks = NULL;	// CWorkbooksポインタpWorkbooksをNULLで初期化.
	pWorkbooks = pApplication->get_Workbooks();	// Excel::CApplication::get_WorkbooksでpWorkbooksを取得.

	// 取得したpWorkbooksを出力.
	_tprintf(_T("CWorkbooks * pWorkbooks = 0x%08x\n"), (unsigned long)pWorkbooks);	// pWorkbooksを出力.

	// xlsxファイルのパス生成.
	TCHAR tszCurrentPath[MAX_PATH] = { 0 };	// このプロセスの現在のディレクトリパスを指すTCHAR配列tszCurrentPath(長さMAX_PATH)を{0}で初期化.
	GetCurrentDirectory(MAX_PATH, tszCurrentPath);	// GetCurrentDirectoryでtszCurrentPathを取得.
	_tcscat(tszCurrentPath, _T("\\"));	// "\"を連結.
	_tcscat(tszCurrentPath, _T("test.xlsx"));	// "test.xlsx"を連結.

	// Workbookを開く.
	Excel::CWorkbook * pWorkbook = NULL;	// CWorkbookポインタpWorkbookをNULLで初期化.
	pWorkbook = pWorkbooks->Open(tszCurrentPath);	// Excel::CWorkbooks::OpenでtszCurrentPathを開き, それを取得.

	// 追加したpWorkbookを出力.
	_tprintf(_T("CWorkbook * pWorkbook = 0x%08x\n"), (unsigned long)pWorkbook);	// pWorkbookを出力.

	// ActiveSheetの取得.
	Excel::CWorksheet * pActiveSheet = NULL;	// CWorksheetポインタpActiveSheetをNULLで初期化.
	pActiveSheet = pWorkbook->get_ActiveSheet();	// Excel::CWorkbook::get_ActiveSheetでpActiveSheetを取得.

	// 取得したpActiveSheetを出力.
	_tprintf(_T("CWorksheet * pActiveSheet = 0x%08x\n"), (unsigned long)pActiveSheet);	// pActiveSheetを出力.

	// Rangeの取得.
	Excel::CRange * pRange = NULL;	// CRangeポインタpRangeをNULLで初期化.
	pRange = pActiveSheet->get_Cells();	// Excel::CWorksheet::get_CellsでpRangeを取得.

	// 取得したpRangeを出力.
	_tprintf(_T("CRange * pRange = 0x%08x\n"), (unsigned long)pRange);	// pRangeを出力.

	// Itemで1行目の1列目のRangeを取得.
	Excel::CRange *pRange11 = NULL;	// CRangeポインタpRange11をNULLで初期化.
	pRange11 = pRange->get_Item(1, 1);	// Excel::CRange::get_Item(1, 1)でpRange11を取得.

	// 取得したpRange11を出力.
	_tprintf(_T("CRange * pRange11 = 0x%08x\n"), (unsigned long)pRange11);	// pRange11を出力.

	// 1行目の1列目の値を取得.
	VARIANT var11;	// VARIANT構造体var11.
	VariantInit(&var11);	// var11をVariantInitで初期化.
	pRange11->get_Value(&var11);	// Excel::CRange::get_Valueで値を取得.
	if (var11.vt == VT_R8) {	// 8バイト実数.
		_tprintf(_T("var11.dblVal = %le\n"), var11.dblVal);	// var11.dblValを出力.
	}
	else if (var11.vt == VT_BSTR) {	// BSTR文字列
		char *old = setlocale(LC_ALL, "japanese");	// setlocaleでLC_ALL, "japanese"をセット.
		_tprintf(_T("var11.bstrVal = %s\n"), var11.bstrVal);	// var11.bstrValを出力.
		setlocale(LC_ALL, old);	// setlocaleでLC_ALL, oldをセット.
	}
	VariantClear(&var11);	// var11をVariantClearでクリア.

	// Itemで1行目の2列目のRangeを取得.
	Excel::CRange *pRange12 = NULL;	// CRangeポインタpRange12をNULLで初期化.
	pRange12 = pRange->get_Item(1, 2);	// Excel::CRange::get_Item(1, 2)でpRange12を取得.

	// 取得したpRange12を出力.
	_tprintf(_T("CRange * pRange12 = 0x%08x\n"), (unsigned long)pRange12);	// pRange12を出力.

	// 1行目の2列目の値を取得.
	VARIANT var12;	// VARIANT構造体var12.
	VariantInit(&var12);	// var12をVariantInitで初期化.
	pRange12->get_Value(&var12);	// Excel::CRange::get_Valueで値を取得.
	if (var12.vt == VT_R8) {	// 8バイト実数.
		_tprintf(_T("var12.dblVal = %le\n"), var12.dblVal);	// var12.dblValを出力.
	}
	else if (var12.vt == VT_BSTR) {	// BSTR文字列
		char *old = setlocale(LC_ALL, "japanese");	// setlocaleでLC_ALL, "japanese"をセット.
		_tprintf(_T("var12.bstrVal = %s\n"), var12.bstrVal);	// var12.bstrValを出力.
		setlocale(LC_ALL, old);	// setlocaleでLC_ALL, oldをセット.
	}
	VariantClear(&var12);	// var12をVariantClearでクリア.

	// pRange12の破棄.
	if (pRange12 != NULL) {
		delete pRange12;
	}

	// pRange11の破棄.
	if (pRange11 != NULL) {
		delete pRange11;
	}

	// pRangeの破棄.
	if (pRange != NULL) {
		delete pRange;
	}

	// pActiveSheetの破棄.
	if (pActiveSheet != NULL) {
		delete pActiveSheet;
	}

	// pWorkbookの破棄.
	if (pWorkbook != NULL) {
		delete pWorkbook;
	}

	// pWorkbooksの破棄.
	if (pWorkbooks != NULL) {
		delete pWorkbooks;
	}

	// pApplicationの破棄.
	if (pApplication != NULL) {
		delete pApplication;
	}

	// COMの終了処理.
	CoUninitialize();	// CoUninitializeで終了処理.

	// プログラムの終了.
	return 0;	// 0を返して終了.

}