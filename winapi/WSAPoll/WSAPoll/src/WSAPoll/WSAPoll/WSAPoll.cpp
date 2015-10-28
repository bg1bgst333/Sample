// ヘッダファイルのインクルード
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <string.h>		// 文字列処理
#include <winsock2.h>	// Windowsソケット
#include <windows.h>	// 標準WindowsAPI

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言・初期化.
	WSADATA wsaData;					// WinSockの初期化に必要なWSADATA構造体変数wsaData.
	int iRet;							// 初期化の結果iRet.
	SOCKET soc;							// SOCKET型のソケットファイルディスクリプタsoc.
	u_short ns_port;					// ポート番号のネットワークバイトオ―ダ値.
	struct sockaddr_in saiServerAddr;	// アドレス情報を持つsockaddr_in構造体saiServerAddr.
	int optval = 1;						// オプション値optvalを1に初期化.
	WSAPOLLFD wsaPollFds[6];			// WSAPOLLFD型配列wsaPollFds.(長さ6.)
	int i;								// ループ用変数i
	int count = 0;						// 接続中クライアントの数countを0に初期化.
	int poll_result;					// pollの戻り値poll_result.
	struct sockaddr_in saiClientAddr;	// アクセプトしたクライアントのアドレス情報saiClientAddr.
	int iClientAddrLen;					// saiClientAddrのサイズiClientAddrLen.
	SOCKET acc;							// SOCKET型のアクセプトソケットファイルディスクリプタacc.
	char *client_ip_addr_str;			// クライアントのIPアドレス文字列client_ip_addr_str.
	u_short client_port;				// アクセプトしたクライアントのポート番号.
	int pos;							// 空き要素インデックス一時保存用pos.
	WSABUF wsaBuf;						// WSABUF型変数wsaBuf.
	BYTE btBuf[256];					// BYTE型バッファbtBuf.
	DWORD dwRecvLen = 0;				// 受信したメッセージの長さdwRecvLen.
	DWORD dwFlags = 0;					// WSARecvに指定するフラグ.(必要.)
	DWORD dwSendLen = 0;				// 送信データの長さdwSendLenを0に初期化.
	int server_exit = 0;			// server_exitを0に初期化.

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
	WSAHtons(soc, 4000, &ns_port);	// WSAHtonsでポート番号をネットワークバイトオ―ダに変換.

	// ポート番号の出力.
	_tprintf(_T("port = %04x, ns_port = %04x\n"), 4000, ns_port);	// ポート番号とネットワークバイトオ―ダなポート番号を出力.

	// バインドするアドレス情報addrの設定.
	saiServerAddr.sin_family = AF_INET;					// IPv4ファミリーAF_INET
	saiServerAddr.sin_port = ns_port;					// ポート番号はns_port( == 4000).
	saiServerAddr.sin_addr.S_un.S_addr = INADDR_ANY;	// すべてのローカルインターフェイスにバインド.(UNIXのin_addrとちょっと違う.)

	// SO_REUSEADDRの有効化.
	if (setsockopt(soc, SOL_SOCKET, SO_REUSEADDR, (const char *)&optval, sizeof(optval)) == -1){	// setsockoptでSO_REUSEADDRを有効化.

		// エラー処理
		_tprintf(_T("setsockopt(SO_REUSEADDR) error!\n"));	// "setsockopt(SO_REUSEADDR) error!"と出力.
		closesocket(soc);	// closesocketでsocを閉じる.
		WSACleanup();	// WSACleanupで終了処理.
		return -1;	// -1を返して異常終了.

	}

	// 成功したら"setsockopt(SO_REUSEADDR) success."と出力.
	_tprintf(_T("setsockopt(SO_REUSEADDR) success.\n"));	// "setsockopt(SO_REUSEADDR) success."と出力.

	// socにsaiServerAddrをバインド.
	if (bind(soc, (struct sockaddr *)&saiServerAddr, sizeof(saiServerAddr)) == -1){	// 戻り値が-1の時はエラー.

		// エラー処理
		_tprintf(_T("bind Error!\n"));	// "bind Error!"と出力.
		closesocket(soc);	// closesocketでsocを閉じる.
		WSACleanup();	// WSACleanupで終了処理.
		return -1;	// -1を返して異常終了.

	}

	// 成功したら"bind Success.".
	_tprintf(_T("bind Success.\n"));	// "bind Success."と出力.

	// リッスン開始.
	if (listen(soc, 5) == -1){	// listenで5つまで接続をリッスンする.

		// エラー処理
		_tprintf(_T("listen Error!\n"));	// "listen Error!"と出力.
		closesocket(soc);	// closesocketでsocを閉じる.
		WSACleanup();	// WSACleanupで終了処理.
		return -1;	// -1を返して異常終了.

	}

	// 成功したら"listen success."と出力.
	_tprintf(_T("listen success.\n"));	// "listen success."と出力.

	// pollfd構造体配列の初期化.
	wsaPollFds[0].fd = soc;	// 0番目はサーバソケットsoc.
	wsaPollFds[0].events = POLLIN;	// 0番目はPOLLIN.
	wsaPollFds[0].revents = 0;					// reventsは0.
	memset(&wsaPollFds[1], 0, sizeof(WSAPOLLFD) * 5);	// memsetでwsaPollFdsを初期化.
	for (i = 1; i <= 5; i++){	// 1から5まで.
		wsaPollFds[i].fd = -1;	// wsaPollFds[i].fdを-1に.
	}	
	count = 0;	// countを0に.

	// アクセプトループ
	while (TRUE){	// 常にTRUE(真)なので無限ループ.

		// ソケット監視.
		poll_result = WSAPoll(wsaPollFds, count + 1, 1000);	// WSAPollで監視.
	    if (poll_result < 0){	// poll_result < 0の時.
			printf("WSAPoll error!\n");	// "WSAPoll error!"と出力.
		}
		else if (poll_result == 0){	// 0はタイムアウト.
			printf("timeout!\n");	// "timeout!"と出力.
		}
		else{	// それ以外.

			// 反応のあったソケットごとに処理.
			// サーバソケットsoc.
			if (wsaPollFds[0].revents & POLLIN){	// wsaPollFds[0].revents & POLLINが真.

				// アクセプトの前準備.
				// iClientAddrLenのセット.
				iClientAddrLen = sizeof(saiClientAddr);	// iClientAddrLenにsizeof(saiClientAddr)でサイズをセット.

				// アクセプト待ち.
				acc = WSAAccept(soc, (struct sockaddr *)&saiClientAddr, &iClientAddrLen, NULL, NULL);	// WSAAcceptでアクセプトしたら, クライアントソケットをaccに格納.
				if (acc == INVALID_SOCKET){	// accがINVALID_SOCKET( == -1)なら.

					// エラー処理
					_tprintf(_T("WSAAccept Error!\n"));	// "WSAAccept Error!"と出力.

				}

				// クライアントのIPアドレス文字列とポート番号を出力.
				client_ip_addr_str = inet_ntoa(saiClientAddr.sin_addr);								// inet_ntoaでクライアントのsaiClientAddr.sin_addrをIPアドレス文字列に変換.
				WSANtohs(acc, saiClientAddr.sin_port, &client_port);								// WSANtohsでクライアントのポート番号をホストバイトオーダに変換.
				printf("accept!(IPAddress = %s, Port = %hu)\n", client_ip_addr_str, client_port);	// IPアドレスとポート番号を出力.

				// fdsへの格納.
				pos = -1;	// posを-1に初期化.
				for (i = 1; i < count + 1; i++){	// countの分だけ検索.
					if (wsaPollFds[i].fd == -1){
						pos = i;	// 空いてればiとする.
					}
				}
				if (pos == -1){
					if (count >= 5){	// 本当に空いてない.
						printf("error!(fds full!)\n");	// 一杯
						closesocket(acc);	// 閉じる.
					}
					else{
						pos = count + 1;	// posはcount + 1とする.
						count++;	// count増やす.
					}
				}
				if (pos != -1){	// 見つかった.
					wsaPollFds[pos].fd = acc;	// wsaPollFds[pos].fdをaccに.
					wsaPollFds[pos].events = POLLIN;	// wsaPollFds[pos].eventsをPOLLINに.
				}

			}

			// アクセプトソケットwsaPollFds
			for (i = 1; i < count + 1; i++){	// countの分繰り返す.
				if (wsaPollFds[i].fd != -1){	// wsaPollFds[i].fdが-1ではない時.
					if (wsaPollFds[i].revents & POLLIN){	// wsaPollFds[i].revents & POLLINが真.
						// 送受信.
						// バッファをクリア.
						memset(btBuf, 0, sizeof(BYTE) * 256);	// memsetでbtBufを0で埋める.
						// wsaBufのセット.
						wsaBuf.buf = (char *)btBuf;				// wsaBuf.bufにbtBufをキャストしてセット.
						wsaBuf.len = sizeof(BYTE) * 256;		// wsaBuf.lenにsizeof(BYTE) * 256をセット.
						// クライアントからメッセージ受信.
						WSARecv(wsaPollFds[i].fd, &wsaBuf, 1, &dwRecvLen, &dwFlags, NULL, NULL);	// WSARecvで受信.
						if (dwRecvLen <= 0){	// 0以下の時.
							closesocket(wsaPollFds[i].fd);	// 閉じる.
							wsaPollFds[i].fd = -1;		// -1にして再利用可能に.
							wsaPollFds[i].events = 0;	// 0にして再利用可能に.
							wsaPollFds[i].revents = 0;	// 0にして再利用可能に.
							continue;	// 次へ.
						}
						// 改行コードの除去
						wsaBuf.buf[dwRecvLen - 1] = '\0';	// "\r\n"がwsaBuf.bufに入ってしまうので, 最後の文字から"\n"を除去.
						wsaBuf.buf[dwRecvLen - 2] = '\0';	// "\r\n"がwsaBuf.bufに入ってしまうので, 最後から2番目の文字から"\r"を除去.
						// server_exit判定.
						if (strcmp(wsaBuf.buf, "end") == 0){	// "end"なら.
							closesocket(wsaPollFds[i].fd);	// 閉じる.
							wsaPollFds[i].fd = -1;		// -1にして再利用可能に.
							wsaPollFds[i].events = 0;	// 0にして再利用可能に.
							wsaPollFds[i].revents = 0;	// 0にして再利用可能に.
							server_exit = 1;	// server_exit = 1とする.
							break;	// 抜ける.
						}
						// wsaBuf.bufの内容を出力.
						printf("%s\n", wsaBuf.buf);	// printfでwsaBuf.bufの内容を出力.
						// 除去した改行コードを再び付ける.
						wsaBuf.buf[dwRecvLen - 1] = '\n';	// '\n'を付ける.
						wsaBuf.buf[dwRecvLen - 2] = '\r';	// '\r'を付ける.
						//wsaBuf.bufの内容を送り返す.
						WSASend(wsaPollFds[i].fd, &wsaBuf, 1, &dwSendLen, dwFlags, NULL, NULL);	// WSASendで送信.						
						if (dwSendLen <= 0){	// dwSendLenが0以下.
							closesocket(wsaPollFds[i].fd);	// 閉じる.
							wsaPollFds[i].fd = -1;		// -1にして再利用可能に.
							wsaPollFds[i].events = 0;	// 0にして再利用可能に.
							wsaPollFds[i].revents = 0;	// 00にして再利用可能に.
							continue;	// 次へ.
						}
					}
				}
			}

			// サーバ停止.
			if (server_exit == 1){	// server_exitが1なら.
				break;	// 抜ける.
			}

		}

	}

	// wsaPollFdsを全て閉じる.
	for (i = 5; i >= 0; i--){	// 6個全て.
		if (wsaPollFds[i].fd != -1){	// -1じゃない時.
			closesocket(wsaPollFds[i].fd);	// loseでfds[i].fdを閉じる.
			wsaPollFds[i].fd = -1;		// -1にする.
			wsaPollFds[i].events = 0;	// 0にする.
			wsaPollFds[i].revents = 0;	// 0にする.
		}
	}
	
	// WinSockの終了処理.
	WSACleanup();	// WSACleanupで終了処理.

	// プログラムの終了.
	return 0;

}