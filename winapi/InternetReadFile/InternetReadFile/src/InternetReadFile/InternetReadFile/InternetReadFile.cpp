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
	DWORD dwReadSize;		// 読み込んだバイト数dwReadSize.
	BYTE btBuf[1024 + 1];	// バッファbtBuf.(長さ1025)

	// WinInetの初期化.
	hInternet = InternetOpen(_T("B.G-STATION Sample InternetOpen"), INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);	// InternetOpenでWinInetを初期化して, 戻り値のインターネットハンドルをhInternetに格納する.

	// インターネットハンドルの出力.
	_tprintf(_T("hInternet = %08x\n"), hInternet);	// _tprintfでhInternetを文字列に変換して出力.

	// 指定のURLを開く.
	hInetFile = InternetOpenUrl(hInternet, _T("http://bgstation0.com/sample/index.html"), NULL, 0, INTERNET_FLAG_RELOAD, 0);	// InternetOpenUrlで"http://bgstation0.com/sample/index.html"を開いて, URLハンドルをhInetFileに格納.

	// URLハンドルの出力.
	_tprintf(_T("hInetFile = %08x\n"), hInetFile);	// _tprintfでhInetFileを文字列に変換して出力.

	// 指定のURLにアクセスして返されたHTTPレスポンスを読み込む.
	while (1){	// 無限ループ.

		// レスポンスの読み込み.
		if (!InternetReadFile(hInetFile, btBuf, 1024, &dwReadSize)){	// InternetReadFileでレスポンスを読み込んで, btBufに1024バイト分格納. エラーならFALSE.

			// エラー処理.
			_tprintf(_T("InternetReadFile Error!\n"));	// "InternetReadFile Error!"と出力.
			InternetCloseHandle(hInetFile);				// InternetCloseHandleでhInetFileを閉じる.
			InternetCloseHandle(hInternet);				// InternetCloseHandleでhInternetを閉じる.
			return -1;	// プログラムの異常終了.

		}

		// 全て読み込んだらこのループから抜ける.
		if (dwReadSize == 0){	// dwReadSizeが0なら.

			// 抜ける.
			_tprintf(_T("\n"));	// 改行.
			break;				// breakで抜ける.

		}

		// 読み込んだバッファの出力.
		btBuf[dwReadSize] = 0x0;		// dwReadSize番目に0x0を入れてNULL終端.
		printf("%s", (char *)btBuf);	// printfでbtBufを出力.

	}

	// URLハンドルを閉じる.
	InternetCloseHandle(hInetFile);	// InternetCloseHandleでhInetFileを閉じる.

	// インターネットハンドルを閉じる.
	InternetCloseHandle(hInternet);	// InternetCloseHandleでhInternetを閉じる.

	// プログラムの終了.
	return 0;

}