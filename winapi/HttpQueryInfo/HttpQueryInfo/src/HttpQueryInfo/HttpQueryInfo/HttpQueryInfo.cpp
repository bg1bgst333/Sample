// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <wininet.h>	// Win32インターネット拡張機能

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言
	HINTERNET hInternet;				// InternetHandleで返されたインターネットハンドルを格納するHINTERNET型変数hInternet.
	HINTERNET hSession;					// InternetConnectで返されたセッションハンドルを格納するHINTERNET型変数hSession.
	HINTERNET hRequest;					// HttpOpenRequestで返されたリクエストハンドルを格納するHINTERNET型変数hRequest.
	LPBYTE lpbtBuf;						// バッファへのポインタlpbtBuf.
	TCHAR tszContentLengthBuf[32];		// Content-Lengthの値を文字列にしたものを格納するバッファ.
	DWORD dwReadSize = 0;				// 1回で読み込んだバイト数dwReadSizeを0に初期化.
	DWORD dwTotalReadSize = 0;			// 読み込んだバイト総数dwTotalReadSizeを0に初期化.
	DWORD dwContentLengthBufLen = 32;	// tszContentLengthBufのサイズを格納するDWORD型変数を32に初期化.
	DWORD dwContentLength = 0;			// tszContentLengthBufをDWORD型数値にしたdwContentLengthを0に初期化.

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

	// Content-Lengthの取得.
	HttpQueryInfo(hRequest, HTTP_QUERY_CONTENT_LENGTH, tszContentLengthBuf, &dwContentLengthBufLen, NULL);	// HttpQueryInfoでContent-Lengthを取得.(dwContentLengthBufLenにはバイト単位の必要バッファサイズが格納される.)
	dwContentLength = _ttoi(tszContentLengthBuf);	// _ttoiでtszContentLengthBufをDWORD型数値に変換.

	// バッファの生成.
	lpbtBuf = new BYTE[dwContentLength + 1];	// newでdwContentLength + 1の長さのBYTE型バッファ配列を生成し, lpbtBufにポインタを格納.

	// 指定のURLにアクセスして返されたHTTPレスポンスを読み込む.
	while (1){	// 無限ループ.

		// レスポンスの読み込み.
		if (!InternetReadFile(hRequest, lpbtBuf + dwTotalReadSize, dwContentLength, &dwReadSize)){	// InternetReadFileでレスポンスを読み込んで, lpbtBufに格納. エラーならFALSE.

			// エラー処理.
			delete [] lpbtBuf;							// delete [] でlpbtBuf解放.
			_tprintf(_T("InternetReadFile Error!\n"));	// "InternetReadFile Error!"と出力.
			InternetCloseHandle(hRequest);				// InternetCloseHandleでhRequestを閉じる.
			InternetCloseHandle(hSession);				// InternetCloseHandleでhSessionを閉じる.
			InternetCloseHandle(hInternet);				// InternetCloseHandleでhInternetを閉じる.
			return -1;	// プログラムの異常終了.

		}

		// 読み込んだ総数の加算.
		dwTotalReadSize = dwTotalReadSize + dwReadSize;	// 総数dwTotalReadSizeに1回の読み込み数dwReadSizeを加算.

		// 全て読み込んだらこのループから抜ける.
		if (dwTotalReadSize == dwContentLength){	// dwReadSizeがdwContentLengthなら.

			// 抜ける.
			break;	// breakで抜ける.

		}

	}

	// 読み込んだバッファの出力.
	lpbtBuf[dwTotalReadSize] = 0x0;	// 最後に0x0で終端.
	printf("%s\n", lpbtBuf);	// printfでlpbtBufを出力.

	// メモリ解放
	delete [] lpbtBuf;	// delete [] でlpbtBuf解放.

	// リクエストハンドルを閉じる.
	InternetCloseHandle(hRequest);	// InternetCloseHandleでhRequestを閉じる.

	// セッションハンドルを閉じる.
	InternetCloseHandle(hSession);	// InternetCloseHandleでhSessionを閉じる.

	// インターネットハンドルを閉じる.
	InternetCloseHandle(hInternet);	// InternetCloseHandleでhInternetを閉じる.

	// プログラムの終了.
	return 0;

}