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

	// A1の値を取得.
	Excel::CRange *pRangeA1 = NULL;	// CRangeポインタpRangeA1をNULLで初期化.
	pRangeA1 = pActiveSheet->get_Range(_T("A1"));	// Excel::CWorksheet::get_RangeでpRangeA1を取得.
	_tprintf(_T("CRange * pRangeA1 = 0x%08x\n"), (unsigned long)pRangeA1);	// pRangeA1を出力.
	VARIANT varA1;	// VARIANT構造体varA1.
	VariantInit(&varA1);	// varA1をVariantInitで初期化.
	pRangeA1->get_Value(&varA1);	// Excel::CRange::get_Valueで値を取得.
	if (varA1.vt == VT_R8) {	// 8バイト実数.
		_tprintf(_T("varA1.dblVal = %le\n"), varA1.dblVal);	// varA1.dblValを出力.
	}
	else if (varA1.vt == VT_BSTR) {	// BSTR文字列
		char *old = setlocale(LC_ALL, "japanese");	// setlocaleでLC_ALL, "japanese"をセット.
		_tprintf(_T("varA1.bstrVal = %s\n"), varA1.bstrVal);	// varA1.bstrValを出力.
		setlocale(LC_ALL, old);	// setlocaleでLC_ALL, oldをセット.
	}
	VariantClear(&varA1);	// varA1をVariantClearでクリア.

	// B1の値を取得.
	Excel::CRange *pRangeB1 = NULL;	// CRangeポインタpRangeB1をNULLで初期化.
	pRangeB1 = pActiveSheet->get_Range(_T("B1"));	// Excel::CWorksheet::get_RangeでpRangeB1を取得.
	_tprintf(_T("CRange * pRangeB1 = 0x%08x\n"), (unsigned long)pRangeB1);	// pRangeB1を出力.
	VARIANT varB1;	// VARIANT構造体varB1.
	VariantInit(&varB1);	// varB1をVariantInitで初期化.
	pRangeB1->get_Value(&varB1);	// Excel::CRange::get_Valueで値を取得.
	if (varB1.vt == VT_R8) {	// 8バイト実数.
		_tprintf(_T("varB1.dblVal = %le\n"), varB1.dblVal);	// varB1.dblValを出力.
	}
	else if (varB1.vt == VT_BSTR) {	// BSTR文字列
		char *old = setlocale(LC_ALL, "japanese");	// setlocaleでLC_ALL, "japanese"をセット.
		_tprintf(_T("varB1.bstrVal = %s\n"), varB1.bstrVal);	// varB1.bstrValを出力.
		setlocale(LC_ALL, old);	// setlocaleでLC_ALL, oldをセット.
	}
	VariantClear(&varB1);	// varB1をVariantClearでクリア.

	// pRangeB1の破棄.
	if (pRangeB1 != NULL) {
		delete pRangeB1;
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