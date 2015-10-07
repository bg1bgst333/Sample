// ヘッダファイルのインクルード
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <winsock2.h>	// Windowsソケット
#include <windows.h>	// 標準WindowsAPI

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言・初期化
	WSADATA wsaData;					// WinSockの初期化に必要なWSADATA構造体変数wsaData.
	char hostname[256];					// ホスト名hostname.
	int port;							// ポート番号port.
	u_short ns_port;					// ポート番号のネットワークバイトオ―ダ値.
	struct hostent *host;				// ホスト情報を格納するhostent構造体へのポインタhost.
	int iRet;							// 初期化の結果iRet.
	SOCKET soc;							// SOCKET型のソケットファイルディスクリプタsoc.
	struct sockaddr_in saiTargetAddr;	// 接続先サーバのの情報saiTargetAddr.
	char tmp = '\0';					// 改行文字読み飛ばし用変数tmpを'\0'に初期化.

	// WinSockの初期化
	iRet = WSAStartup(MAKEWORD(2, 2), &wsaData);	// WSAStartupでWinSockの初期化.
	if (iRet){	// 0でない場合.

		// エラー処理.
		_tprintf(_T("Error!(iRet = %d.)\n"), iRet);	// 戻り値を出力.
		WSACleanup();	// WSACleanupで終了処理.
		return -1;	// -1を返して異常終了.

	}

	// 初期化成功メッセージ.
	_tprintf(_T("WSAStartup success!\n"));	// "WSAStartup success!"と出力.

	// ホスト名の入力.
	_tprintf(_T("hostname: "));	// hostnameの入力フォーム.
	scanf("%s", hostname);	// 入力されたホスト名をhostnameに格納.

	// ポート番号の入力.
	_tprintf(_T("port: "));		// portの入力フォーム.
	scanf("%d", &port);			// 入力されたポート番号をportに格納.

	// 改行読み飛ばし.
	scanf("%*c", tmp);	// この後の入力に影響を残さないため.

	// ホスト情報の取得.
	host = gethostbyname(hostname);	// gethostbynameで指定したホスト名のホスト情報を取得.
	if (host == NULL){	// hostがNULLなら.

		// エラー
		_tprintf(_T("gethostbyname Error!\n"));	// エラーメッセージ出力.
		WSACleanup();	// WSACleanupで終了処理.
		return -1;	// -1を返して終了.

	}

	// ホスト名から導き出されたIPアドレス情報.
	_tprintf(_T("host->h_addr_list[0][0] = %02x, host->h_addr_list[0][1] = %02x, host->h_addr_list[0][3] = %02x, host->h_addr_list[0][3] = %02x\n"), host->h_addr_list[0][0], host->h_addr_list[0][1], host->h_addr_list[0][2], host->h_addr_list[0][3]);	// host->h_addr_listの中身を出力.

	// ソケットの作成
	soc = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, 0);	// WSASocketでソケット作成.
	if (soc == INVALID_SOCKET){	// socがINVALID_SOCKET( == -1)なら.

		// エラー処理
		_tprintf(_T("WSASocket Error!\n"));	// "WSASocket Error!"と出力.
		WSACleanup();	// WSACleanupで終了処理.
		return -1;	// -1を返して異常終了.

	}

	// socの値を出力.
	_tprintf(_T("soc = %lu\n"), soc);	// socの値を出力.

	// ポート番号の変換.
	WSAHtons(soc, port, &ns_port);	// WSAHtonsでポート番号をネットワークバイトオ―ダに変換.

	// ポート番号の出力.
	_tprintf(_T("port = %04x, ns_port = %04x\n"), port, ns_port);	// ポート番号とネットワークバイトオ―ダなポート番号を出力.

	// 接続先サーバ情報saiTargetAddrの設定.
	saiTargetAddr.sin_family = AF_INET;														// IPv4ファミリーAF_INET
	saiTargetAddr.sin_port = ns_port;														// ポート番号はns_port.
	saiTargetAddr.sin_addr.S_un.S_addr = *(u_long *)host->h_addr_list[0];					// hostのIPアドレス情報をセット.(u_longとする.)

	// 接続
	if (WSAConnect(soc, (struct sockaddr *)&saiTargetAddr, sizeof(saiTargetAddr), NULL, NULL, NULL, NULL) == SOCKET_ERROR){	// WSAConnectで接続し, SOCKET_ERRORならエラー.

		// エラー処理
		_tprintf(_T("WSAConnect Error!\n"));	// "WSAConnect Error!"と出力.
		closesocket(soc);	// closesocketでsocを閉じる.
		WSACleanup();	// WSACleanupで終了処理.
		return -1;	// -1を返して異常終了.

	}

	// 成功したら"WSAConnect success."
	_tprintf(_T("WSAConnect success.\n"));	// _tprintfで"WSAConnect success."と出力.

	// ソケットを閉じる.
	closesocket(soc);	// closesocketでsocを閉じる.

	// WinSockの終了処理.
	WSACleanup();	// WSACleanupで終了処理.

	// プログラムの終了.
	return 0;

}