// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <wininet.h>	// Win32インターネット拡張機能

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言
	HINTERNET hInternet;	// InternetHandleで返されたインターネットハンドルを格納するHINTERNET型変数hInternet.
	HINTERNET hInetFile;	// InternetOpenUrlで返されたURLハンドルを格納するHINTERNET型変数hInetFile.

	// WinInetの初期化.
	hInternet = InternetOpen(_T("B.G-STATION Sample InternetOpen"), INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);	// InternetOpenでWinInetを初期化して, 戻り値のインターネットハンドルをhInternetに格納する.

	// インターネットハンドルの出力.
	_tprintf(_T("hInternet = %08x\n"), hInternet);	// _tprintfでhInternetを文字列に変換して出力.

	// 指定のURLを開く.
	hInetFile = InternetOpenUrl(hInternet, _T("http://bgstation0.com/sample/index.html"), NULL, 0, INTERNET_FLAG_RELOAD, 0);	// InternetOpenUrlで"http://bgstation0.com/sample/index.html"を開いて, URLハンドルをhInetFileに格納.

	// URLハンドルの出力.
	_tprintf(_T("hInetFile = %08x\n"), hInetFile);	// _tprintfでhInetFileを文字列に変換して出力.

	// URLハンドルを閉じる.
	InternetCloseHandle(hInetFile);	// InternetCloseHandleでhInetFileを閉じる.

	// インターネットハンドルを閉じる.
	InternetCloseHandle(hInternet);	// InternetCloseHandleでhInternetを閉じる.

	// プログラムの終了.
	return 0;

}