// ヘッダのインクルード
// 既定のヘッダ
#include <tchar.h>			// TCHAR型
#include <iostream>			// C++標準入出力
#include <string>			// std::string
#include <winsock2.h>		// Windowsソケット
#include <ws2tcpip.h>		// WinSock2 TCP/IP
#include <openssl/bio.h>	// BIO 
#include <openssl/ssl.h>	// SSL
#include <openssl/err.h>	// エラー
// 独自のヘッダ
#include "credentials.h"	// 認証情報

// マクロの定義
// UNICODE切り替え
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// _tmain関数の定義
int _tmain() {

	// 変数の宣言と初期化.
	WSADATA wsaData;	// WSADATA型wsaData.
	int iRet;	// int型iRet.
	struct addrinfo hint = { 0 };	// addrinfo構造体hintを0で初期化.
	struct addrinfo *ai;			// addrinfo構造体ポインタai.
	int soc = -1;	// ソケットファイルディスクリプタsocを-1に初期化.
	SSL_CTX *ctx = NULL;	// SSL_CTX構造体へのポインタctxをNULLに初期化.
	SSL *ssl = NULL;	// SSL接続情報を持つSSL構造体へのポインタsslをNULLに初期化.
	std::string credentials_str;	// クレデンシャル構成文字列credentials_str.
	BIO *mem = NULL;	// メモリデータシンクBIOをNULLにセット.
	BIO *base64 = NULL;	// Base64フィルタBIOをNULLにセット.
	char base64_str[1024] = { 0 };	// char型配列base64_strを0で初期化.
	tstring request_tstr;	// リクエスト文字列request_tstr.
	int written = 0;	// SSL_writeでの書き込みに成功した長さwritten.
	char response_buf[1024] = { 0 };	// char型配列response_buf(要素数1024)を0で初期化.
	int response_len = 0;	// SSL_readで読み込んだ長さを格納するresponse_lenを0で初期化.

	// WinSockの初期化.
	iRet = WSAStartup(MAKEWORD(2, 2), &wsaData);	// WSAStartupでWinSockの初期化.
	if (iRet) {	// 0でない場合.

		// エラー処理.
		_tprintf(_T("Error!(iRet = %d.)\n"), iRet);	// _tprintfでiRetを出力.
		WSACleanup();	// WSACleanupで終了処理.
		return -1;	// -1を返す.

	}

	// 初期化成功メッセージ.
	_tprintf(_T("WSAStartup success!\n"));	// "WSAStartup success!"と出力.

	// ファミリーとソケットタイプのセット.
	hint.ai_family = AF_INET;	// ファミリーはAF_INET.
	hint.ai_socktype = SOCK_STREAM;	// ソケットタイプはSOCK_STREAM.

	// addrinfo構造体の取得.
	iRet = getaddrinfo("api.twitter.com", "https", &hint, &ai);	// getaddrinfoでホスト情報取得.
	if (iRet) {	// 0以外はエラー.

		// エラー処理.
		_tprintf(_T("Error!(iRet = %d.)\n"), iRet);	// _tprintfでiRetを出力.
		WSACleanup();	// WSACleanupで終了処理.
		return -2;	// -2を返す.

	}

	// ソケットの生成.
	soc = socket(ai->ai_family, ai->ai_socktype, ai->ai_protocol);	// socketでaiのメンバを渡してsocを生成.
	if (soc == -1) {	// -1でエラー.

		// エラー処理.
		_tprintf(_T("Error!(soc = %d.)\n"), soc);	// _tprintfでsocを出力.
		freeaddrinfo(ai);	// freeaddrinfoでaiを解放.
		WSACleanup();	// WSACleanupで終了処理.
		return -3;	// -3を返す.

	}

	// socを出力.
	_tprintf(_T("soc = %d\n"), soc);	// _tprintfでsocを出力.

	// 接続
	iRet = connect(soc, ai->ai_addr, ai->ai_addrlen);	// connectで接続.
	if (iRet == -1) {	// -1だとエラー.

		// エラー処理.
		closesocket(soc);	// closesocketでsocを閉じる.
		freeaddrinfo(ai);	// freeaddrinfoでaiを解放.
		WSACleanup();	// WSACleanupで終了処理.
		return -4;	// -4を返す.

	}

	// 接続成功.
	_tprintf(_T("connect success!\n"));	// _tprintfで"connect success!"を出力.

	// SSLライブラリの初期化.
	SSL_library_init();	// SSL_library_initでSSLライブラリの初期化.
	SSL_load_error_strings();	// SSL_load_error_stringsでエラー文字列をロード.

	// SSLコンテキストの作成.
	ctx = SSL_CTX_new(SSLv23_client_method());	// SSL_CTX_newでSSLコンテキストを作成し, SSL_CTX型ポインタとしてctxに格納.

	// ctxの指すアドレスを出力.
	_tprintf(_T("ctx = %08x\n"), (unsigned int)ctx);	// _tprintfでctxの指すアドレスを出力.
	
	// SSL接続情報の作成.
	ssl = SSL_new(ctx);	// SSL_newでctxからSSL接続情報を作成し, ポインタをsslに格納.

	// sslの指すアドレスを出力.
	_tprintf(_T("ssl = %08x\n"), (unsigned int)ssl);	// _tprintfでsslの指すアドレスを出力.

	// SSL接続情報にソケットファイルディスクリプタをセット.
	if (SSL_set_fd(ssl, soc) == 0) {	// SSL_set_fdでsslにsocをセット.(戻り値が0なら失敗, 1なら成功.)

		// エラー処理
		_tprintf(_T("SSL_set_fd error!\n"));	// "SSL_set_fd error!"と出力.
		ERR_print_errors_fp(stderr);	// ERR_print_errors_fpにstderrを渡して標準エラー出力にエラーメッセージを出力.
		SSL_free(ssl);	// SSL_freeでsslを解放.
		SSL_CTX_free(ctx);	// SSL_CTX_freeでctxを解放.
		closesocket(soc);	// closesocketでsocを閉じる.
		freeaddrinfo(ai);	// freeaddrinfoでaiを解放.
		WSACleanup();	// WSACleanupで終了処理.
		return -5;	// -5を返す.

	}

	// 成功
	_tprintf(_T("SSL_set_fd success!\n"));	// "SSL_set_fd success!"と出力.

	// SSL接続
	iRet = SSL_connect(ssl);	// SSL_connectにsslを渡してSSLハンドシェイクを行う.
	if (iRet == 1) {	// 成功
		_tprintf(_T("SSL_connect success!\n"));	// "SSL_connect success!"と出力.
	}
	else {	// エラー

		// エラー処理
		_tprintf(_T("SSL_connect error!\n"));	// "SSL_connect error!"と出力.
		SSL_free(ssl);	// SSL_freeでsslを解放.
		SSL_CTX_free(ctx);	// SSL_CTX_freeでctxを解放.
		closesocket(soc);	// closesocketでsocを閉じる.
		freeaddrinfo(ai);	// freeaddrinfoでaiを解放.
		WSACleanup();	// WSACleanupで終了処理.
		return -6;	// -6を返す.

	}

	// クレデンシャル作成.
	credentials_str = API_KEY;	// credentials_strにAPI_KEYを格納.
	credentials_str = credentials_str + ":";		// ":"を連結.
	credentials_str = credentials_str + API_SECRET;	// API_SECRETを連結.

	// クレデンシャル文字列を出力.
	printf("credentials_str = %s\n", credentials_str.c_str());

	// base64に変換.
	mem = BIO_new(BIO_s_mem());	// BIO_new()にBIO_s_mem()を渡してmemを作成.
	base64 = BIO_new(BIO_f_base64());	// BIO_new()にBIO_f_base64()を渡してbase64を作成.
	BIO_set_flags(base64, BIO_FLAGS_BASE64_NO_NL);	// BIO_set_flagsでBIO_FLAGS_BASE64_NO_NLをセットしないとBase64文字列に改行が含まれてしまうので要注意!
	BIO_push(base64, mem);	// BIO_pushでbase64とmemを連結.
	BIO_write(base64, credentials_str.c_str(), credentials_str.length());	// base64にcredentials_strを書き込み.
	BIO_flush(base64);	// BIO_flushでフラッシュ.
	BIO_read(mem, base64_str, 1024);	// BIO_readでmemを読み込み, base64_strに格納.

	// base64_strの出力.
	printf("base64_str = %s\n", base64_str);	// printfでbase64_strの出力.

	// base64_strの文字コード変換(Shift-JIS => Unicode)
	TCHAR tbase64[1024];
	DWORD len = MultiByteToWideChar(CP_ACP, 0, base64_str, -1, NULL, 0);	// ワイド文字に変換するためのサイズ取得.
	MultiByteToWideChar(CP_ACP, 0, base64_str, -1, tbase64, len);	// ワイド文字に変換.

	// POSTリクエスト文字列の作成.
	request_tstr = _T("POST /oauth2/token HTTP/1.1");	// request_tstrに"POST /oauth2/token HTTP/1.1"を格納.
	request_tstr = request_tstr + _T("\r\n");	// 改行
	request_tstr = request_tstr + _T("Host: api.twitter.com");	// request_tstrに"Host: api.twitter.com"を連結.
	request_tstr = request_tstr + _T("\r\n");	// 改行
	request_tstr = request_tstr + _T("User-Agent: bgst1tw1test1");	// request_tstrに"User-Agent: bgst1tw1test1"を連結.
	request_tstr = request_tstr + _T("\r\n");	// 改行
	request_tstr = request_tstr + _T("Authorization: Basic ");	// request_tstrに"Authorization: Basic "を連結.
	request_tstr = request_tstr + tbase64;	// request_tstrにtbase64を連結.
	request_tstr = request_tstr + _T("\r\n");	// 改行
	request_tstr = request_tstr + _T("Content-Type: application/x-www-form-urlencoded;charset=UTF-8");	// request_tstrに"Content-Type: application/x-www-form-urlencoded;charset=UTF-8"を連結.
	request_tstr = request_tstr + _T("\r\n");	// 改行
	request_tstr = request_tstr + _T("Content-Length: 29");	// request_tstrに"Content-Length: 29"を連結.
	request_tstr = request_tstr + _T("\r\n\r\n");	// 空行
	request_tstr = request_tstr + _T("grant_type=client_credentials");	// request_tstrに"grant_type=client_credentials"を連結.

	// request_tstrの文字コード変換(Unicode => utf-8)
	char request_str[4096];
	DWORD len2 = WideCharToMultiByte(CP_UTF8, 0, request_tstr.c_str(), -1, NULL, 0, NULL, NULL);	// マルチバイトに変換するためのサイズを取得.
	WideCharToMultiByte(CP_UTF8, 0, request_tstr.c_str(), -1, request_str, len2, NULL, NULL);	// マルチバイトに変換.

	// リクエストの書き込み.
	written = SSL_write(ssl, request_str, len2);	// SSL_writeでrequest_strを書き込む.
	printf("SSL_write written = %d\n", written);	// SSL_writeで書き込み成功した文字数を出力.

	// レスポンスの読み込み.
	while ((response_len = SSL_read(ssl, response_buf, 1024 - 1)) > 0) {	// SSL_readで読み込んだレスポンスをresponse_bufに格納.(1バイト以上なら続ける.)

		// response_bufの内容を出力.
		printf("%s", response_buf);	// printfでresponse_bufを出力.
		memset(response_buf, 0, sizeof(char) * 1024);	// memsetでresponse_bufをクリア.

	}

	// 改行
	printf("\n");	// printfで改行.

	// SSL切断.
	SSL_shutdown(ssl);	// SSL_shutdownでSSL切断する.

	// 解放
	BIO_free_all(base64);	// base64と連結しているmemも解放される.

	// SSL接続情報の破棄.
	SSL_free(ssl);	// SSL_freeでsslを解放.

	// SSLコンテキストの解放.
	SSL_CTX_free(ctx);	// SSL_CTX_freeでctxを解放.

	// socを閉じる.
	closesocket(soc);	// closesocketでsocを閉じる.

	// aiを解放.
	freeaddrinfo(ai);	// freeaddrinfoでaiを解放.

	// WinSockの終了処理.
	WSACleanup();	// WSACleanupで終了処理.

	// プログラムの終了
	return 0;	// 0を返す.

}