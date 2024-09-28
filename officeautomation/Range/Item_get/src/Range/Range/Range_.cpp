// ヘッダファイルのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR対応
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

	// Worksheetsの取得.
	Excel::CWorksheets * pWorksheets = NULL;	// CWorksheetsポインタpWorksheetsをNULLで初期化.
	pWorksheets = pWorkbook->get_Worksheets();	// Excel::CWorkbook::get_WorksheetsでpWorksheetsを取得.

	// 取得したpWorksheetsを出力.
	_tprintf(_T("CWorksheets * pWorksheets = 0x%08x\n"), (unsigned long)pWorksheets);	// pWorksheetsを出力.

	// Worksheetを追加.
	Excel::CWorksheet * pWorksheet = NULL;	// CWorksheetポインタpWorksheetをNULLで初期化.
	pWorksheet = pWorksheets->Add();	// Excel::CWorksheets::AddでWorksheetを追加し, それを取得.

	// 追加したpWorksheetを出力.
	_tprintf(_T("CWorksheet * pWorksheet = 0x%08x\n"), (unsigned long)pWorksheet);	// pWorksheetを出力.

	// Rangeの取得.
	Excel::CRange * pRange = NULL;	// CRangeポインタpRangeをNULLで初期化.
	pRange = pWorksheet->get_Cells();	// Excel::CWorksheet::get_CellsでpRangeを取得.

	// 取得したpRangeを出力.
	_tprintf(_T("CRange * pRange = 0x%08x\n"), (unsigned long)pRange);	// pRangeを出力.

	// Itemで3行目の2列目のRangeを取得.
	Excel::CRange *pRange2 = NULL;	// CRangeポインタpRange2をNULLで初期化.
	pRange2 = pRange->get_Item(3, 2);	// Excel::CRange::get_Item(3, 2)でpRange2を取得.

	// 取得したpRange2を出力.
	_tprintf(_T("CRange * pRange2 = 0x%08x\n"), (unsigned long)pRange2);	// pRange2を出力.

	// pRange2の破棄.
	if (pRange2 != NULL) {
		delete pRange2;
	}

	// pRangeの破棄.
	if (pRange != NULL) {
		delete pRange;
	}

	// pWorksheetの破棄.
	if (pWorksheet != NULL) {
		delete pWorksheet;
	}

	// pWorksheetsの破棄.
	if (pWorksheets != NULL) {
		delete pWorksheets;
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