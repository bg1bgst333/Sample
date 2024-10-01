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

	// A1の領域を取得.
	Excel::CRange *pRangeA1 = NULL;	// CRangeポインタpRangeA1をNULLで初期化.
	pRangeA1 = pActiveSheet->get_Range(_T("A1"));	// Excel::CWorksheet::get_RangeでpRangeA1を取得.
	_tprintf(_T("CRange * pRangeA1 = 0x%08x\n"), (unsigned long)pRangeA1);	// pRangeA1を出力.

	// A1の枠の罫線を取得.
	IDispatch *pBordersA1 = NULL;	// IDispatchポインタpBordersA1をNULLで初期化.
	pBordersA1 = pRangeA1->get_Borders();	// Excel::CRange::get_BordersでpBordersA1を取得.
	_tprintf(_T("IDispatch * pBordersA1 = 0x%08x\n"), (unsigned long)pBordersA1);	// pBordersA1を出力.

	// B2:C3の領域を取得.
	Excel::CRange *pRangeB2C3 = NULL;	// CRangeポインタpRangeB2C3をNULLで初期化.
	pRangeB2C3 = pActiveSheet->get_Range(_T("B2:C3"));	// Excel::CWorksheet::get_RangeでpRangeB2C3を取得.
	_tprintf(_T("CRange * pRangeB2C3 = 0x%08x\n"), (unsigned long)pRangeB2C3);	// pRangeB2C3を出力.

	// B2:C3の枠の罫線を取得.
	IDispatch *pBordersB2C3 = NULL;	// IDispatchポインタpBordersB2C3をNULLで初期化.
	pBordersB2C3 = pRangeB2C3->get_Borders();	// Excel::CRange::get_BordersでpBordersB2C3を取得.
	_tprintf(_T("IDispatch * pBordersB2C3 = 0x%08x\n"), (unsigned long)pBordersB2C3);	// pBordersB2C3を出力.

	// pBordersB2C3の破棄.
	if (pBordersB2C3 != NULL) {
		pBordersB2C3->Release();
		pBordersB2C3 = NULL;
	}

	// pRangeB2C3の破棄.
	if (pRangeB2C3 != NULL) {
		delete pRangeB2C3;
	}

	// pBordersA1の破棄.
	if (pBordersA1 != NULL) {
		pBordersA1->Release();
		pBordersA1 = NULL;
	}

	// pRangeA1の破棄.
	if (pRangeA1 != NULL) {
		delete pRangeA1;
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