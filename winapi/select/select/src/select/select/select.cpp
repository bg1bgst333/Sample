// ヘッダファイルのインクルード
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <string.h>		// 文字列処理
#include <winsock2.h>	// Windowsソケット
#include <windows.h>	// 標準WindowsAPI

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言
	WSADATA wsaData;				// WinSockの初期化に必要なWSADATA構造体変数wsaData.
	int iRet;						// 初期化の結果iRet.
	int soc;						// ソケットファイルディスクリプタsoc.
	u_short ns_port;				// ポート番号のネットワークバイトオ―ダ値.
	struct sockaddr_in server_addr;	// アドレス情報を持つsockaddr_in構造体server_addr.
	int optval = 1;					// オプション値optvalを1に初期化.
	int acc;						// アクセプトソケットファイルディスクリプタacc.
	struct sockaddr_in client_addr;	// アクセプトしたクライアントのアドレス情報client_addr.
	int client_addr_len;			// client_addrのサイズclient_addr_len.
	char *client_ip_addr_str;		// クライアントのIPアドレス文字列client_ip_addr_str.
	u_short client_port;			// アクセプトしたクライアントのボート番号.
	char buf[256];					// char型バッファbuf.
	int exit_flg = 0;				// メッセージループを抜けるフラグexit_flgを0に初期化.
	int recv_len;					// 受信したメッセージの長さrecv_len.
	int send_len;					// 送信したメッセージ文字列の長さsend_len.
	int client_acc[5];				// クライアントのアクセプトソケット配列client_acc.(最大5個クライアントを受信可能.)
	fd_set mask;					// select用のfd_set型mask.
	int range;						// 監視するソケットの範囲range.
	int i;							// ループ用変数i.
	int count;						// 接続中のクライアントの数count.
	struct timeval timeout;			// timeval型タイムアウト値timeout.
	int select_result;				// selectの戻り値select_result.
	int pos;						// 空き要素インデックス一時保存用pos.
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

	// バインドするアドレス情報server_addrの設定.
	server_addr.sin_family = AF_INET;				// IPv4ファミリーAF_INET
	server_addr.sin_port = ns_port;					// ポート番号はns_port( == 4000).
	server_addr.sin_addr.S_un.S_addr = INADDR_ANY;	// すべてのローカルインターフェイスにバインド.(UNIXのin_addrとちょっと違う.)

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

	// socにserver_addrをバインド.
	if (bind(soc, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1){	// 戻り値が-1の時はエラー.

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

	// クライアントのアクセプトソケット配列の初期化.
	for (i = 0; i < 5; i++){	// 0から4まで繰り返す.

		// クライアントアクセプトソケットを-1に初期化.
		client_acc[i] = -1;	// client_accを全て-1にセット.

	}
	count = 0;	// 接続中のクライアント数countは0.

	// アクセプトループ
	while (TRUE){	// 常にTRUE(真)なので無限ループ

		// マスクの初期化
		FD_ZERO(&mask);	// FD_ZEROマクロでmaskを初期化.
		FD_SET(soc, &mask);	// FD_SETで監視するソケットとマスクを紐付ける.
		range = soc + 1;	// 個の時点で監視する範囲はsocだけ.(ただし, rangeにはそれより1つ多いsoc + 1と指定する.)
		for (i = 0; i < count; i++){	// アクセプトソケットがいる場合, それも監視対称にし, countの数だけ繰り返す.
			if (client_acc[i] != -1){	// client_acc[i]が-1でない場合.
				FD_SET(client_acc[i], &mask);	// client_acc[i]もマスクと紐付け.
				if (client_acc[i] + 1 > range){	// client_acc[i] + 1がrangeを超える場合.
					range = client_acc[i] + 1;	// rangeをclient_acc[i] + 1に更新.
				}
			}
		}
		printf("count = %d\n", count);	// 接続中のクライアント数を出力.

		// タイムアウト値の設定.
		timeout.tv_sec = 5;		// 5秒.
		timeout.tv_usec = 0;	// 0マイクロ秒.

		// selectによるソケットファイルディスクリプタ監視.
		select_result = select(range, (fd_set *)&mask, NULL, NULL, &timeout);	// selectでrangeの範囲でmaskでセットしたソケットを監視.
		if (select_result < 0){	// 0以下ならエラー.
			printf("select error!\n");	// "select error!"を出力.
		}
		else if (select_result == 0){	// 0はタイムアウト.
			printf("timeout!\n");	// "timeout!"を出力.
		}
		else{	// それ以外.

			// 反応のあったソケットごとに処理.
			// サーバソケットの場合.
			if (FD_ISSET(soc, &mask)){	// socの場合.

				// アクセプト.
				// acceptに渡すclient_addr_lenのセット.
				client_addr_len = sizeof(client_addr);	// client_addr_lenにsizeof(client_addr)でサイズをセット.(これをやらないと, クライアント情報がclient_addrに格納されない.)

				// アクセプト(接続受理)待ち
				acc = accept(soc, (struct sockaddr *)&client_addr, &client_addr_len);	// acceptでアクセプトしたら, クライアントソケットをaccに格納.
				if (acc == -1){	// accが-1の時はエラー.

					// エラー処理
					printf("accept error!\n");	// "accept error!"と出力.
          
				}

				// クライアント情報の表示
				client_ip_addr_str = inet_ntoa(client_addr.sin_addr);	// inet_ntoaでクライアントのclient_addr.sin_addrをIPアドレス文字列に変換.
				client_port = ntohs(client_addr.sin_port);	// ntohsでクライアントのclient_addr.sin_portを符号なし10進整数のポート番号に変換.
				printf("accept!(IPAddress = %s, Port = %hu)\n", client_ip_addr_str, client_port);	// IPアドレスとポートを表示.

				// client_accへの格納.
				pos = -1;	// posを-1に初期化.
				for (i = 0; i < count; i++){	// countの分だけ検索.
					if (client_acc[i] == -1){
						pos = i;
					}
				}
				if (pos == -1){	// 空いてない.
					if (count >= 5){	// 本当に空いていない.
						printf("error!(client_acc full!)\n");	// "error!(client_acc full!)"と出力.
						closesocket(acc);	// accをclosesocketで閉じる.
					}
					else{	// それ以外.
						pos = count;	// posはcountの位置とする.
						count++;	// countを増やす.
					}
				}
				if (pos != -1){	// posが-1じゃない場合.
					client_acc[pos] = acc;	// accをclient_acc[pos]に格納.
				}

			}

			// アクセプトソケットの場合.
			for (i = 0; i < count; i++){	// countの分だけ繰り返す.
				if (client_acc[i] != -1){	// client_acc[i]が-1ではない時.
					if (FD_ISSET(client_acc[i], &mask)){	// client_acc[i]の時.
						// 送受信.
						// バッファクリア.
						memset(buf, 0, sizeof(char) * 256);	// memsetでbufを0で埋める.
						recv_len = recv(client_acc[i], buf, sizeof(char) * 256, 0);	// recvでclient_acc[i]からのメッセージをbufに格納.
						if (recv_len <= 0){	// 0以下の時.
							closesocket(client_acc[i]);	// 閉じる.
							client_acc[i] = -1;	// 不要なclient_accを-1にして再利用可能に.
							continue;	// 次へ.
						}
						// 改行コードの除去
						buf[recv_len - 1] = '\0';	// "\r\n"がbufに入ってしまうので, 最後の文字から"\n"を除去.
						buf[recv_len - 2] = '\0';	// "\r\n"がbufに入ってしまうので, 最後から2番目の文字から"\r"を除去.
						// server_exit判定.
						if (strcmp(buf, "end") == 0){	// "end"なら.
							closesocket(client_acc[i]);	// 閉じる.
							client_acc[i] = -1;	// 不要なclient_accを-1にして再利用可能に.
							server_exit = 1;	// server_exit = 1とする.
							break;	// 抜ける.
						}
						// bufの内容を出力.
						printf("%s\n", buf);	// printfでbufの内容を出力.
						// 除去した改行コードを再び付ける.
						buf[recv_len - 1] = '\n';	// '\n'を付ける.
						buf[recv_len - 2] = '\r';	// '\r'を付ける.
						//bufの内容を送り返す.
						send_len = send(client_acc[i], buf, strlen(buf), 0);	// sendでbufの内容を返す.
						if (send_len <= 0){	// send_lenが0以下.
							closesocket(client_acc[i]);	// 閉じる.
							client_acc[i] = -1;	// 不要なclient_accを-1にして再利用可能に.
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

	// clinet_accを全て閉じる.
	for (i = 0; i < 5; i++){	// 5個全て.
		if (client_acc[i] != -1){	// -1じゃない時.
			closesocket(client_acc[i]);	// closesocketでclient_acc[i]を閉じる.
		}
	}

	// サーバソケットファイルディスクリプタを閉じる.
	closesocket(soc);	// closesocketでsocを閉じる.

	// WinSockの終了処理.
	WSACleanup();	// WSACleanupで終了処理.

	// プログラムの終了
	return 0;

}