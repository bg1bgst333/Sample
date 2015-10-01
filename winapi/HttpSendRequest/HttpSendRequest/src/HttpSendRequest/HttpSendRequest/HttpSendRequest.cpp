// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <wininet.h>	// Win32インターネット拡張機能

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言
	HINTERNET hInternet;	// InternetHandleで返されたインターネットハンドルを格納するHINTERNET型変数hInternet.
	HINTERNET hSession;		// InternetConnectで返されたセッションハンドルを格納するHINTERNET型変数hSession.
	HINTERNET hRequest;		// HttpOpenRequestで返されたリクエストハンドルを格納するHINTERNET型変数hRequest.
	DWORD dwReadSize;		// 読み込んだバイト数dwReadSize.
	BYTE btBuf[1024 + 1];	// バッファbtBuf.(長さ1025)

	// WinInetの初期化.
	hInternet = InternetOpen(_T("B.G-STATION Sample InternetOpen"), INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);	// InternetOpenでWinInetを初期化して, 戻り値のインターネットハンドルをhInternetに格納する.

	// インターネットハンドルの出力.
	_tprintf(_T("hInternet = %08x\n"), hInternet);	// _tprintfでhInternetを文字列に変換して出力.

	// 指定のサーバに接続.
	hSession = InternetConnect(hInternet, _T("bgstation0.com"), INTERNET_DEFAULT_HTTP_PORT, NULL, NULL, INTERNET_SERVICE_HTTP, 0, 0);	// InternetConnectで"bgstation0.com"にHTTPで接続.
	
	// セッションハンドルの出力.
	_tprintf(_T("hSession = %08x\n"), hSession);	// _tprintfでhSessionを文字列に変換して出力.

	// HTTPリクエストの作成.
	hRequest = HttpOpenRequest(hSession, _T("GET"), _T("/sample/index.html"), NULL, _T("http://bgstation0.com/"), NULL, 0, 0);	// HttpOpenRequestで"/sample/index.html"へのGETリクエストを作成.

	// リクエストハンドルの出力.
	_tprintf(_T("hRequest = %08x\n"), hRequest);	// _tprintfでhRequestを文字列に変換して出力.

	// HTTPリクエストの送信.
	HttpSendRequest(hRequest, NULL, 0, NULL, 0);	// HttpSendRequestで作成したリクエストhRequestを送信.

	// 指定のURLにアクセスして返されたHTTPレスポンスを読み込む.
	while (1){	// 無限ループ.

		// レスポンスの読み込み.
		if (!InternetReadFile(hRequest, btBuf, 1024, &dwReadSize)){	// InternetReadFileでレスポンスを読み込んで, btBufに1024バイト分格納. エラーならFALSE.

			// エラー処理.
			_tprintf(_T("InternetReadFile Error!\n"));	// "InternetReadFile Error!"と出力.
			InternetCloseHandle(hRequest);				// InternetCloseHandleでhRequestを閉じる.
			InternetCloseHandle(hSession);				// InternetCloseHandleでhSessionを閉じる.
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

	// リクエストハンドルを閉じる.
	InternetCloseHandle(hRequest);	// InternetCloseHandleでhRequestを閉じる.

	// セッションハンドルを閉じる.
	InternetCloseHandle(hSession);	// InternetCloseHandleでhSessionを閉じる.

	// インターネットハンドルを閉じる.
	InternetCloseHandle(hInternet);	// InternetCloseHandleでhInternetを閉じる.

	// プログラムの終了.
	return 0;

}