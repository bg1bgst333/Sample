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

	// (1, 1)の領域を取得.
	Excel::CRange *pRange11 = NULL;	// CRangeポインタpRange11をNULLで初期化.
	pRange11 = pActiveSheet->get_Cells(1, 1);	// Excel::CWorksheet::get_CellsでpRange11を取得.
	_tprintf(_T("CRange * pRange11 = 0x%08x\n"), (unsigned long)pRange11);	// pRange11を出力.

	// (2, 3)の領域を取得.
	Excel::CRange *pRange23 = NULL;	// CRangeポインタpRange23をNULLで初期化.
	pRange23 = pActiveSheet->get_Cells(2, 3);	// Excel::CWorksheet::get_CellsでpRange23を取得.
	_tprintf(_T("CRange * pRange23 = 0x%08x\n"), (unsigned long)pRange23);	// pRange23を出力.

	// (1, 1)から(2, 3)の領域を取得.
	Excel::CRange *pRange1123 = NULL;	// CRangeポインタpRange1123をNULLで初期化.
	pRange1123 = pActiveSheet->get_Range(pRange11, pRange23);	// Excel::CWorksheet::get_RangeでpRange1123を取得.
	_tprintf(_T("CRange * pRange1123 = 0x%08x\n"), (unsigned long)pRange1123);	// pRange1123を出力.

	// (1, 1)から(2, 3)の領域の罫線を破線にする.
	Excel::CBorders *pBorders1123 = NULL;	// CBordersポインタpBorders1123をNULLで初期化.
	pBorders1123 = pRange1123->get_Borders();	// Excel::CRange::get_BordersでpBorders1123を取得.
	_tprintf(_T("CBorders * pBorders1123 = 0x%08x\n"), (unsigned long)pBorders1123);	// pBorders1123を出力.
	pBorders1123->put_LineStyle(Excel::XlLineStyle::xlDash);	// Excel::CBorders::put_LineStyleで罫線スタイルを破線に.

	// pBorders1123の破棄.
	if (pBorders1123 != NULL) {
		delete pBorders1123;
	}

	// pRange1123の破棄.
	if (pRange1123 != NULL) {
		delete pRange1123;
	}

	// pRange23の破棄.
	if (pRange23 != NULL) {
		delete pRange23;
	}

	// pRange11の破棄.
	if (pRange11 != NULL) {
		delete pRange11;
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