// ヘッダファイルのインクルード
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <winsock2.h>	// Windowsソケット
#include <windows.h>	// 標準WindowsAPI

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言
	WSADATA wsaData;			// WinSockの初期化に必要なWSADATA構造体変数wsaData.
	int iRet;					// 初期化の結果iRet.
	int soc;					// ソケットファイルディスクリプタsoc.
	u_short ns_port;			// ポート番号のネットワークバイトオ―ダ値.
	struct sockaddr_in addr;	// アドレス情報を持つsockaddr_in構造体addr.

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

	// ソケットの作成
	soc = socket(AF_INET, SOCK_STREAM, 0);	// socketでソケット作成.
	if (soc == -1){	// socが-1なら.

		// エラー処理
		_tprintf(_T("socket Error!\n"));	// "socket Error!"と出力.
		WSACleanup();	// WSACleanupで終了処理.
		return -1;	// -1を返して異常終了.

	}

	// socの値を出力.
	_tprintf(_T("soc = %d\n"), soc);	// socの値を出力.

	// ポート番号の変換.
	ns_port = htons(4000);	// htonsでポート番号をネットワークバイトオ―ダに変換.

	// ポート番号の出力.
	_tprintf(_T("port = %04x, ns_port = %04x\n"), 4000, ns_port);	// ポート番号とネットワークバイトオ―ダなポート番号を出力.

	// バインドするアドレス情報addrの設定.
	addr.sin_family = AF_INET;				// IPv4ファミリーAF_INET
	addr.sin_port = ns_port;				// ポート番号はns_port( == 4000).
	addr.sin_addr.S_un.S_addr = INADDR_ANY;	// すべてのローカルインターフェイスにバインド.(UNIXのin_addrとちょっと違う.)
	
	// socにaddrをバインド.
	if (bind(soc, (struct sockaddr *)&addr, sizeof(addr)) == -1){	// 戻り値が-1の時はエラー.

		// エラー処理
		_tprintf(_T("bind Error!\n"));	// "bind Error!"と出力.
		closesocket(soc);	// closesocketでsocを閉じる.
		WSACleanup();	// WSACleanupで終了処理.
		return -1;	// -1を返して異常終了.

	}

	// 成功したら"bind Success.".
	_tprintf(_T("bind Success.\n"));	// "bind Success."と出力.

	// ソケットファイルディスクリプタを閉じる.
	closesocket(soc);	// closesocketでsocを閉じる.

	// WinSockの終了処理.
	WSACleanup();	// WSACleanupで終了処理.

	// プログラムの終了.
	return 0;

}