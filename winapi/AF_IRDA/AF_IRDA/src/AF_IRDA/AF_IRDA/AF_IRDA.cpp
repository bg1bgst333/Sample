// ヘッダファイルのインクルード
#include <tchar.h>		// TCHAR型
#include <winsock2.h>	// Windowsソケット
#include <windows.h>	// 標準WindowsAPI
#include <af_irda.h>	// IrDA

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言.
	WSADATA wsaData;	// WinSockの初期化に必要なWSADATA構造体変数wsaData.
	int iRet;	// WSAStartupの結果を格納するiRet.
	int soc;	// ソケットsoc.

	// WinSockの初期化.
	iRet = WSAStartup(MAKEWORD(2,2), &wsaData);	// WSAStartupでWinSockの初期化.
	if (iRet == 0){	// 0なら成功.

		// 結果成功の出力.
		_tprintf(_T("WSAStartup success!\n"));	// "WSAStartup success!"を出力.

		// 赤外線ソケットの作成.
		soc = socket(AF_IRDA, SOCK_STREAM, 0);	// socketでAF_IRDAなsocを作成.
		if (soc != INVALID_SOCKET){	// INVALID_SOCKETでない時.

			// ソケットディスクリプタを出力.
			_tprintf(_T("soc = %d\n"), soc);	// socを出力.

			// socを閉じる.
			closesocket(soc);	// closesocketでsocを閉じる.

		}

		// 終了処理.
		WSACleanup();	// WSACleanupで終了処理.

	}

	// プログラムの終了.
	return 0;

}