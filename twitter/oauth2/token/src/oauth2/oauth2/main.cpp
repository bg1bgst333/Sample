// ヘッダのインクルード
// 既定のヘッダ
#include <tchar.h>			// TCHAR型
#include <iostream>			// C++標準入出力
#include <string>			// std::string
#include <winsock2.h>		// Windowsソケット
#include <ws2tcpip.h>		// WinSock2 TCP/IP
#include <openssl/bio.h>	// BIO 

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

	// socを閉じる.
	closesocket(soc);	// closesocketでsocを閉じる.

	// aiを解放.
	freeaddrinfo(ai);	// freeaddrinfoでaiを解放.

	// WinSockの終了処理.
	WSACleanup();	// WSACleanupで終了処理.

	// プログラムの終了
	return 0;	// 0を返す.

}