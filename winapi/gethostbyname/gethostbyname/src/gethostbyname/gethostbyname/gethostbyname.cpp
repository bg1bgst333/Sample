// ヘッダファイルのインクルード
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <winsock2.h>	// Windowsソケット
#include <windows.h>	// 標準WindowsAPI

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言
	WSADATA wsaData;		// WinSockの初期化に必要なWSADATA構造体変数wsaData.
	char hostname[256];		// ホスト名hostname.
	struct hostent *host;	// ホスト情報を格納するhostent構造体へのポインタhost.
	int iRet;				// 初期化の結果iRet.

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

	// WinSockの終了処理.
	WSACleanup();	// WSACleanupで終了処理.

	// プログラムの終了.
	return 0;

}