// ヘッダのインクルード
// 独自のヘッダ
#include "MainApplication.h"	// CMainApplication

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数・オブジェクトの宣言・初期化.
	CMainApplication app;	// CMainApplicationオブジェクトapp.
	HRESULT hr;	// COMの初期化の結果を格納するhr.
	TCHAR tszText[256] = {0};	// 表示するテキストtszText(長さ256)を{0}で初期化.

	// OLEの初期化
	hr = OleInitialize(NULL);	// OleInitializeにNULLを渡して初期化.
	if (hr == S_OK){	// S_OKなら初期化成功.
		_stprintf(tszText, _T("OleInitialize success!\n"));	// "OleInitialize success!"をtszTextにセット.
		OutputDebugString(tszText);	// OutputDebugStringでtszTextを出力.
	}
	else if (hr == S_FALSE){	// S_FALSEならすでに初期化されている.
		_stprintf(tszText, _T("Already initialized!\n"));	// "Already initialized!"をtszTextにセット.
		OutputDebugString(tszText);	// OutputDebugStringでtszTextを出力.
	}
	else{	// それ以外.
		_stprintf(tszText, _T("Failed!\n"));	// "Failed!"をtszTextにセット.
		OutputDebugString(tszText);	// OutputDebugStringでtszTextを出力.
		return -1;	// -1を返して異常終了.
	}

	// インスタンスの初期化.
	if (!app.InitInstance(hInstance, lpCmdLine, nShowCmd)){	// app.InitInstanceがFALSEの場合.

		// 異常終了.
		app.ExitInstance();	// app.ExitInstanceで終了処理を実行.
		// OLEの終了処理.
		OleUninitialize();	// OleUninitializeで終了処理.
		return -1;	// returnで-1を返して異常終了.

	}

	// メッセージループ処理.
	int iRet = app.Run();	// app.Runの戻り値をiRetに格納.
	// OLEの終了処理.
	OleUninitialize();	// OleUninitializeで終了処理.
	return iRet;	// iRetを返して終了.

}