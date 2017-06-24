// ヘッダのインクルード
// 既定のヘッダ
#include <tchar.h>			// TCHAR型
#include <stdio.h>			// C標準入出力
#include <string.h>			// C文字列処理
#include <iostream>			// C++標準入出力
#include <string>			// std::string
#include <time.h>			// 時刻
#include <winsock2.h>		// Windowsソケット
#include <ws2tcpip.h>		// WinSock2 TCP/IP
#include <openssl/bio.h>	// BIO 
#include <openssl/ssl.h>	// SSL
#include <openssl/err.h>	// エラー
#include <openssl/sha.h>	// SHA
#include <openssl/evp.h>	// EVP
#include <openssl/hmac.h>	// HMAC

// 独自のヘッダ
#include "credentials.h"	// 認証情報

// マクロの定義
// UNICODE切り替え
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// 関数のプロトタイプ宣言
void urlencode(char dst[], const char src[], int src_len);	// URLエンコード.

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
	char api_secret_str[1024] = { 0 };	// char型APIシークレットutf-8文字列を0で初期化.
	char urlencoded_api_secret_str[1024] = { 0 };	// URLエンコード済みのAPIシークレットutf-8文字列を0で初期化.
	char signature_key[1024] = { 0 };	// 署名キーsignature_keyを0で初期化.
	tstring request_params_tstr = _T("");	// リクエストパラメータrequest_params_tstrを""で初期化.
	char request_params_str[1024] = { 0 };	// リクエストパラメータrequest_params_str(utf8)を0で初期化.
	char urlencoded_request_params_str[1024] = { 0 };	// URLエンコード済みパラメータ urlencoded_request_params_strを0で初期化.
	tstring request_method_tstr = _T("POST");	// リクエストメソッドは"POST".
	char request_method_str[1024] = { 0 };	// utf8.
	char urlencoded_request_method_str[1024] = { 0 };	// URLエンコード済み.
	tstring request_url_tstr = _T("https://api.twitter.com/oauth/request_token");	// リクエストURLは"https://api.twitter.com/oauth/request_token".
	char request_url_str[1024] = { 0 };	// utf8.
	char urlencoded_request_url_str[1024] = { 0 };	// URLエンコード済み.
	TCHAR urlencoded_request_url_tstr[1024] = { 0 };	// URLエンコード済み.
	char signature_data[4096] = { 0 };	// 署名データsignature_dataを0で初期化.
	char hmac_sha1[SHA_DIGEST_LENGTH + 1];	// char型配列hmac_sha1.
	unsigned int hmac_sha1_len;	// unsigned int型hmac_sha1_len.
	BIO *mem = NULL;	// メモリデータシンクBIO
	BIO *base64 = NULL;	// Base64フィルタBIO
	char base64_str[1024] = { 0 };	// char型配列base64_strを0で初期化.
	char urlencoded_base64_str[1024] = { 0 };	// char型配列urlencoded_base64_strを0で初期化.
	tstring request_tstr;	// リクエスト文字列request_tstr.
	TCHAR base64_tstr[1024] = { 0 };	// TCHAR型配列base64_tstrを0で初期化.
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

	// 署名キーの作成.
	// API_SECRETの文字コード変換(Unicode => utf-8)
	DWORD len = WideCharToMultiByte(CP_UTF8, 0, API_SECRET, -1, NULL, 0, NULL, NULL);	// マルチバイトに変換するためのサイズを取得.
	WideCharToMultiByte(CP_UTF8, 0, API_SECRET, -1, api_secret_str, len, NULL, NULL);	// マルチバイトに変換.
	urlencode(urlencoded_api_secret_str, api_secret_str, len - 1);	// 自作関数urlencodeでapi_secret_strをURLエンコード.
	strcat_s(signature_key, sizeof(char) * 1024, urlencoded_api_secret_str);	// signature_keyにurlencoded_api_secret_strを連結.
	strcat_s(signature_key, sizeof(char) * 1024, "&");	// signature_keyに'&'を連結.

	// 現在時刻の取得.
	time_t t = time(NULL);	// timeで取得した現在時刻をtime_t型tに格納.
	TCHAR time_tstr[64] = { 0 };	// time_tstrを0で初期化.
	_stprintf_s(time_tstr, sizeof(char) * 64, _T("%lld"), t);	// UNIX時刻tを文字列time_tstrに変換.

	// リクエストパラメータの作成.
	request_params_tstr = _T("oauth_callback");	// request_params_tstrに"oauth_callback"を連結.
	request_params_tstr = request_params_tstr + _T("=");	// "="を連結.
	request_params_tstr = request_params_tstr + CALLBACK_URL;	// CALLBACK_URLを連結.
	request_params_tstr = request_params_tstr + _T("&");	// "&"を連結.
	request_params_tstr = request_params_tstr + _T("oauth_consumer_key");	// request_params_tstrに"oauth_consumer_key"を連結.
	request_params_tstr = request_params_tstr + _T("=");	// "="を連結.
	request_params_tstr = request_params_tstr + API_KEY;	// API_KEYを連結.
	request_params_tstr = request_params_tstr + _T("&");	// "&"を連結.
	request_params_tstr = request_params_tstr + _T("oauth_nonce");	// request_params_tstrに"oauth_nonce"を連結.
	request_params_tstr = request_params_tstr + _T("=");	// "="を連結.
	request_params_tstr = request_params_tstr + time_tstr;	// とりあえずtime_tstrをもう一度連結.
	request_params_tstr = request_params_tstr + _T("&");	// "&"を連結.
	request_params_tstr = request_params_tstr + _T("oauth_signature_method");	// request_params_tstrに"oauth_signature_method"を連結.
	request_params_tstr = request_params_tstr + _T("=");	// "="を連結.
	request_params_tstr = request_params_tstr + _T("HMAC-SHA1");	// "HMAC-SHA1"を連結.
	request_params_tstr = request_params_tstr + _T("&");	// "&"を連結.
	request_params_tstr = request_params_tstr + _T("oauth_timestamp");	// request_params_tstrに"oauth_timestamp"を連結.
	request_params_tstr = request_params_tstr + _T("=");	// "="を連結.
	request_params_tstr = request_params_tstr + time_tstr;	// time_tstrを連結.
	request_params_tstr = request_params_tstr + _T("&");	// "&"を連結.
	request_params_tstr = request_params_tstr + _T("oauth_version");	// request_params_tstrに"oauth_version"を連結.
	request_params_tstr = request_params_tstr + _T("=");	// "="を連結.
	request_params_tstr = request_params_tstr + _T("1.0");	// "1.0"を連結.
	len = WideCharToMultiByte(CP_UTF8, 0, request_params_tstr.c_str(), -1, NULL, 0, NULL, NULL);	// マルチバイトに変換するためのサイズを取得.
	WideCharToMultiByte(CP_UTF8, 0, request_params_tstr.c_str(), -1, request_params_str, len, NULL, NULL);	// マルチバイトに変換.
	urlencode(urlencoded_request_params_str, request_params_str, len - 1);	// 自作関数urlencodeでrequest_params_strをURLエンコード.

	// リクエストメソッドの作成.
	len = WideCharToMultiByte(CP_UTF8, 0, request_method_tstr.c_str(), -1, NULL, 0, NULL, NULL);	// マルチバイトに変換するためのサイズを取得.
	WideCharToMultiByte(CP_UTF8, 0, request_method_tstr.c_str(), -1, request_method_str, len, NULL, NULL);	// マルチバイトに変換.
	urlencode(urlencoded_request_method_str, request_method_str, len - 1);	// 自作関数urlencodeでrequest_method_strをURLエンコード.

	// リクエストURLの作成.
	len = WideCharToMultiByte(CP_UTF8, 0, request_url_tstr.c_str(), -1, NULL, 0, NULL, NULL);	// マルチバイトに変換するためのサイズを取得.
	WideCharToMultiByte(CP_UTF8, 0, request_url_tstr.c_str(), -1, request_url_str, len, NULL, NULL);	// マルチバイトに変換.
	urlencode(urlencoded_request_url_str, request_url_str, len - 1);	// 自作関数urlencodeでrequest_url_strをURLエンコード.

	// 署名データの作成.
	strcat_s(signature_data, sizeof(char) * 4096, urlencoded_request_method_str);	// signature_dataにurlencoded_request_method_strを連結.
	strcat_s(signature_data, sizeof(char) * 4096, "&");	// "&"を連結.
	strcat_s(signature_data, sizeof(char) * 4096, urlencoded_request_url_str);	// signature_dataにurlencoded_request_url_strを連結.
	strcat_s(signature_data, sizeof(char) * 4096, "&");	// "&"を連結.
	strcat_s(signature_data, sizeof(char) * 4096, urlencoded_request_params_str);	// signature_dataにurlencoded_request_params_strを連結.

	// 署名.
	HMAC(EVP_sha1(), (const unsigned char *)signature_key, strlen(signature_key), (const unsigned char *)signature_data, strlen(signature_data), (unsigned char *)hmac_sha1, &hmac_sha1_len);	// HMAC()でHMAC-SHA1を計算.
	
	// Base64変換.
	mem = BIO_new(BIO_s_mem());	// BIO_new()にBIO_s_mem()を渡してmemを作成.
	base64 = BIO_new(BIO_f_base64());	// BIO_new()にBIO_f_base64()を渡してbase64を作成.
	BIO_set_flags(base64, BIO_FLAGS_BASE64_NO_NL);	// BIO_set_flagsでBIO_FLAGS_BASE64_NO_NLをセットしないとBase64文字列に改行が含まれてしまうので要注意!
	BIO_push(base64, mem);	// BIO_pushでbase64とmemを連結.
	BIO_write(base64, hmac_sha1, hmac_sha1_len);	// base64にhmac_sha1を書き込み.
	BIO_flush(base64);	// BIO_flushでフラッシュ.
	BIO_read(mem, base64_str, 1024);	// BIO_readでmemを読み込み, base64_strに格納.
	BIO_free_all(base64);	// base64と連結しているmemも解放される.
	urlencode(urlencoded_base64_str, base64_str, strlen(base64_str));	// URLエンコード
	len = MultiByteToWideChar(CP_UTF8, 0, urlencoded_base64_str, -1, NULL, 0);	// ワイド文字に変換するためのサイズ取得.
	MultiByteToWideChar(CP_UTF8, 0, urlencoded_base64_str, -1, base64_tstr, len);	// ワイド文字に変換.

	// POSTリクエストの作成.
#if 0
	char callback_url[1024] = { 0 };	// コールバックURL.
	char urlencoded_callback_url[1024] = { 0 };	// URLエンコード済み.
	TCHAR urlencoded_callback_url_tstr[1024] = { 0 };	// THCAR.
	len = WideCharToMultiByte(CP_UTF8, 0, CALLBACK_URL, -1, NULL, 0, NULL, NULL);	// マルチバイトに変換するためのサイズを取得.
	WideCharToMultiByte(CP_UTF8, 0, CALLBACK_URL, -1, callback_url, len, NULL, NULL);	// マルチバイトに変換.
	urlencode(urlencoded_callback_url, callback_url, strlen(callback_url));	// URLエンコード.
	len = MultiByteToWideChar(CP_UTF8, 0, urlencoded_callback_url, -1, NULL, 0);	// ワイド文字に変換するためのサイズ取得.
	MultiByteToWideChar(CP_UTF8, 0, urlencoded_callback_url, -1, urlencoded_callback_url_tstr, len);	// ワイド文字に変換.
#endif
	request_tstr = _T("POST /oauth/request_token HTTP/1.1");	// request_tstrに"POST /oauth/request_token HTTP/1.1"を格納.
	request_tstr = request_tstr + _T("\r\n");	// 改行
	request_tstr = request_tstr + _T("Host: api.twitter.com");	// request_tstrに"Host: api.twitter.com"を連結.
	request_tstr = request_tstr + _T("\r\n");	// 改行
	request_tstr = request_tstr + _T("User-Agent: bgst1tw1test1");	// request_tstrに"User-Agent: bgst1tw1test1"を連結.
	request_tstr = request_tstr + _T("\r\n");	// 改行
	request_tstr = request_tstr + _T("Authorization: OAuth ");	// request_tstrに"Authorization: OAuth "を格納.
	request_tstr = request_tstr + _T("oauth_callback=");	// "oauth_callback="を連結.
	request_tstr = request_tstr + _T("\"");	// "\""を連結.
	//request_tstr = request_tstr + urlencoded_callback_url_tstr;	// urlencoded_callback_url_tstrを連結.
	request_tstr = request_tstr + CALLBACK_URL;	// CALLBACK_URLを連結.
	request_tstr = request_tstr + _T("\"");	// "\""を連結.
	request_tstr = request_tstr + _T(", ");	// ", "を連結.
	request_tstr = request_tstr + _T("oauth_consumer_key=");	// "oauth_consumer_key="を連結.
	request_tstr = request_tstr + _T("\"");	// "\""を連結.
	request_tstr = request_tstr + API_KEY;	// API_KEYを連結.
	request_tstr = request_tstr + _T("\"");	// "\""を連結.
	request_tstr = request_tstr + _T(", ");	// ", "を連結.
	request_tstr = request_tstr + _T("oauth_nonce=");	// "oauth_nonce="を連結.
	request_tstr = request_tstr + _T("\"");	// "\""を連結.
	request_tstr = request_tstr + time_tstr;	// time_tstrを連結.
	request_tstr = request_tstr + _T("\"");	// "\""を連結.
	request_tstr = request_tstr + _T(", ");	// ", "を連結.
	request_tstr = request_tstr + _T("oauth_signature_method=");	// "oauth_signature_method="を連結.
	request_tstr = request_tstr + _T("\"");	// "\""を連結.
	request_tstr = request_tstr + _T("HMAC-SHA1");	// "HMAC-SHA1"を連結.
	request_tstr = request_tstr + _T("\"");	// "\""を連結.
	request_tstr = request_tstr + _T(", ");	// ", "を連結.
	request_tstr = request_tstr + _T("oauth_signature=");	// "oauth_signature="を連結.
	request_tstr = request_tstr + _T("\"");	// "\""を連結.
	request_tstr = request_tstr + base64_tstr;	// base64_tstrを連結.
	request_tstr = request_tstr + _T("\"");	// "\""を連結.
	request_tstr = request_tstr + _T(", ");	// ", "を連結.
	request_tstr = request_tstr + _T("oauth_timestamp=");	// "oauth_timestamp="を連結.
	request_tstr = request_tstr + _T("\"");	// "\""を連結.
	request_tstr = request_tstr + time_tstr;	// time_tstrを連結.
	request_tstr = request_tstr + _T("\"");	// "\""を連結.
	request_tstr = request_tstr + _T(", ");	// ", "を連結.
	request_tstr = request_tstr + _T("oauth_version=");	// "oauth_version="を連結.
	request_tstr = request_tstr + _T("\"");	// "\""を連結.
	request_tstr = request_tstr + _T("1.0");	// "1.0"を連結.
	request_tstr = request_tstr + _T("\"");	// "\""を連結.
	request_tstr = request_tstr + _T("\r\n\r\n");	// 空行
	
	// request_tstrの文字コード変換(Unicode => utf-8)
	char request_str[4096];
	DWORD len2 = WideCharToMultiByte(CP_UTF8, 0, request_tstr.c_str(), -1, NULL, 0, NULL, NULL);	// マルチバイトに変換するためのサイズを取得.
	WideCharToMultiByte(CP_UTF8, 0, request_tstr.c_str(), -1, request_str, len2, NULL, NULL);	// マルチバイトに変換.

	// リクエストの書き込み.
	written = SSL_write(ssl, request_str, len2);	// SSL_writeでrequest_strを書き込む.
	printf("SSL_write written = %d\n", written);	// SSL_writeで書き込み成功した文字数を出力.

	// 改行
	printf("\n");	// printfで改行.

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

// URLエンコード.
void urlencode(char dst[], const char src[], int src_len){

	// 変数の宣言.
	int i = 0;	// ループ用変数iを0で初期化.
	int j = 0;	// 格納先の位置変数jを0で初期化.
	char c;	// 取り出した文字c.
	char urlenc[4];	// 変換済み文字列urlenc.
	char buf[1024] = { 0 };	// 一時バッファを0で初期化.

	// srcをbufにコピー.(srcは維持されてるとは限らないので.)
	strcpy_s(buf, sizeof(char) * 1024, src);	// strcpy_sでsrcをbufにコピー.

	// URLエンコード処理.
	for (i = 0; i < src_len; i++) {	// lenの数だけ繰り返す.
		c = buf[i];	// bufのi番目をcに格納.
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '-' || c == '_' || c == '.' || c == '~') {	// アルファベット, 数字, ハイフン, アンダースコア, ドット, チルダなら.
			dst[j] = c;	// dst[j]にcを格納.
			dst[j + 1] = '\0';	// dst[j + 1]に'\0'を格納.
			j++;	// jを1増やす.
		}
		else {
			snprintf(urlenc, sizeof(urlenc), "%%%02x", c & 0xff);	// cを"%xx"形式にしてurlencに格納.
			for (int k = 0; k < 3; k++) {
				urlenc[k] = toupper(urlenc[k]);
			}
			strcat_s(dst, sizeof(char) * 1024, urlenc);	// urlencをdstに連結.
			j = j + 3;	// jを3増やす.
		}
	}

}




