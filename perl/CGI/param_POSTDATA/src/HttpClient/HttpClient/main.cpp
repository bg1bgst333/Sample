// ヘッダファイルのインクルード
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <stdlib.h>		// 標準ライブラリ
#include <winsock2.h>	// Windowsソケット
#include <windows.h>	// 標準WindowsAPI

// _tmain関数の定義
int _tmain() {	// main関数のtchar版.

	// 変数の宣言・初期化
	WSADATA wsaData;					// WinSockの初期化に必要なWSADATA構造体変数wsaData.
	int iRet;							// 初期化の結果iRet.
	char hostname[256] = "localhost";	// ホスト名hostnameを"localhost"で初期化.
	int port = 80;						// ポート番号portを80で初期化.
	struct hostent* host;				// ホスト情報を格納するhostent構造体へのポインタhost.
	SOCKET soc;							// SOCKET型のソケットファイルディスクリプタsoc.
	u_short ns_port;					// ポート番号のネットワークバイトオ―ダ値.
	struct sockaddr_in saiTargetAddr;	// 接続先サーバのの情報saiTargetAddr.
	char request_str[1024];				// リクエスト文字列request_str.(長さ1024)
	HANDLE hFile;						// HANDLE型ファイルハンドルhFile
	DWORD dwSize;						// DWORD型ファイルサイズdwSize
	BYTE* pbtBuf = NULL;				// BYTE型ポインタpbtBufをNULLで初期化.
	DWORD dwReadBytes;					// DWORD型読み込んだバイト数dwReadBytes.
	char content_len_str[256];			// Content-Length行の文字列content_len_str
	char response_buf[4096];			// レスポンスバッファresponse_buf.(長さ4096)

	// WinSockの初期化
	iRet = WSAStartup(MAKEWORD(2, 2), &wsaData);	// WSAStartupでWinSockの初期化.
	if (iRet) {	// 0でない場合.

		// エラー処理.
		_tprintf(_T("Error!(iRet = %d.)\n"), iRet);	// 戻り値を出力.
		WSACleanup();	// WSACleanupで終了処理.
		return -1;	// -1を返して異常終了.

	}

	// 初期化成功メッセージ.
	_tprintf(_T("WSAStartup success!\n"));	// "WSAStartup success!"と出力.

	// ホスト情報の取得.
	host = gethostbyname(hostname);	// gethostbynameで指定したホスト名のホスト情報を取得.
	if (host == NULL) {	// hostがNULLなら.

		// エラー
		_tprintf(_T("gethostbyname Error!\n"));	// エラーメッセージ出力.
		WSACleanup();	// WSACleanupで終了処理.
		return -1;	// -1を返して終了.

	}

	// ホスト名から導き出されたIPアドレス情報.
	_tprintf(_T("host->h_addr_list[0][0] = %02x, host->h_addr_list[0][1] = %02x, host->h_addr_list[0][3] = %02x, host->h_addr_list[0][3] = %02x\n"), host->h_addr_list[0][0], host->h_addr_list[0][1], host->h_addr_list[0][2], host->h_addr_list[0][3]);	// host->h_addr_listの中身を出力.

	// ソケットの作成
	soc = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, 0);	// WSASocketでソケット作成.
	if (soc == INVALID_SOCKET) {	// socがINVALID_SOCKET( == -1)なら.

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
	saiTargetAddr.sin_addr.S_un.S_addr = *(u_long*)host->h_addr_list[0];					// hostのIPアドレス情報をセット.(u_longとする.)

	// 接続
	if (WSAConnect(soc, (struct sockaddr*)&saiTargetAddr, sizeof(saiTargetAddr), NULL, NULL, NULL, NULL) == SOCKET_ERROR) {	// WSAConnectで接続し, SOCKET_ERRORならエラー.

		// エラー処理
		_tprintf(_T("WSAConnect Error!\n"));	// "WSAConnect Error!"と出力.
		closesocket(soc);	// closesocketでsocを閉じる.
		WSACleanup();	// WSACleanupで終了処理.
		return -1;	// -1を返して異常終了.

	}

	// 成功したら"WSAConnect success."
	_tprintf(_T("WSAConnect success.\n"));	// _tprintfで"WSAConnect success."と出力.

	// ファイルを開く
	hFile = CreateFile(_T("image1.bmp"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFileで"image1.bmp"を開いて, 取得したハンドルをhFileに格納.
	if (hFile == INVALID_HANDLE_VALUE) {	// hFileがINVALID_HANDLE_VALUEなら.

		// エラー処理
		_tprintf(_T("CreateFile Error!\n"));	// _tprintfで"CreateFile Error!"と出力.
		closesocket(soc);	// closesocketでsocを閉じる.
		WSACleanup();	// WSACleanupで終了処理.
		return -1;	// -1を返す.

	}

	// ファイルサイズの取得.
	dwSize = GetFileSize(hFile, NULL);	// GetFileSizeで"test.txt"のファイルサイズを取得する.

	// メモリの確保.
	pbtBuf = (BYTE*)malloc(sizeof(BYTE) * (dwSize + 1));	// mallocで(dwSize + 1)分確保.

	// ファイルの読み込み.
	ReadFile(hFile, pbtBuf, dwSize, &dwReadBytes, NULL);	// hFileを読み込み, pbtBuf
	pbtBuf[dwReadBytes] = 0;

	// リクエスト文字列のクリア.
	memset(request_str, 0, sizeof(char) * 1024);	// memsetでrequest_strを0で埋める.

	// リクエスト文字列のセット.
	sprintf(request_str, "POST %s HTTP/1.0\r\n", "/cgi-bin/CGI.cgi");	// sprintfでPOSTリクエストをセット.
	sprintf(content_len_str, "Content-Length: %d\r\n", dwSize);	// Content-Lengthの行を組み立て.
	strcat(request_str, content_len_str);	// content_len_strを連結.
	strcat(request_str, "Content-Type: image/bmp\r\n");	// Content-Typeの行を連結.
	strcat(request_str, "\r\n");	// 1行空ける.

	// 送信
	send(soc, request_str, strlen(request_str), 0);	// sendでrequest_strを送信.

	// ファイルバイナリの送信.
	send(soc, (char*)pbtBuf, dwSize, 0);	// sendでpbtBufを送信.

	// レスポンス文字列のクリア.
	memset(response_buf, 0, sizeof(char) * 4096);	// memsetでresponse_bufを0で埋める.

	// 受信
	recv(soc, response_buf, sizeof(char) * 4096, 0);	// 受信したメッセージをresponse_bufに格納.

	// 解放.
	free(pbtBuf);	// pbtBufを解放.

	// レスポンス文字列を出力.
	printf("%s\n", response_buf);	// response_bufを出力.

	// ファイルを閉じる.
	CloseHandle(hFile);

	// ソケットを閉じる.
	closesocket(soc);	// closesocketでsocを閉じる.

	// WinSockの終了処理.
	WSACleanup();	// WSACleanupで終了処理.

	// プログラムの終了.
	return 0;

}