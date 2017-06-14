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