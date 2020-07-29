// ヘッダファイルのインクルード
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <string.h>		// 文字列処理
#include <winsock2.h>	// Windowsソケット
#include <windows.h>	// 標準WindowsAPI
#include <af_irda.h>	// IrDA

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言と初期化.
	WSADATA wsaData;	// WinSockの初期化に必要なWSADATA構造体変数wsaData.
	int iRet;			// WSAStartupの結果を格納するiRet.
	int soc;			// ソケットsoc.
	int iBind;			// バインド結果iBind.
	int iListen;		// リッスン結果iListen.
	SOCKADDR_IRDA soc_addr = {AF_IRDA, 0, 0, 0, 0, "OBEX"};	// soc_addrをこのように初期化.
	int acc;			// ソケットacc.
	SOCKADDR_IRDA acc_addr;	// 相手のアドレス情報acc_addr.
	int acc_addr_len = sizeof(SOCKADDR_IRDA);	// 相手のアドレス情報の長さacc_addr_lenをSOCKADDR_IRDAのサイズで初期化.
	TCHAR tszServerName[256] = {0};	// サーバー名tszServerNameを{0}で初期化.
	int iServerNameLen = 0;	// サーバー名iServerNameLenを0で初期化.
	BYTE btBytes[4096] = {0};	// BYTE配列btBytes(サイズ4096)を{0}で初期化.
	int iRecvLen = 0;	// 受信したデータの長さiRecvLenを0で初期化.
	int i = 0;	// ループ用変数iを0で初期化.
	BYTE btResponseBytes[4096] = {0};	// レスポンスBYTE配列btResponseBytes(サイズ4096)を{0}で初期化.
	WORD wPacketSize = 0;	// パケットサイズwPacketSizeを0で初期化.
	TCHAR tszName[256] = {0};	// tszNameを{0}で初期化.
	WORD wNameSize = 0;	// NameのサイズwNameSizeを0で初期化.
	char szName[256] = {0};	// char型配列szName(長さ256)を{0}で初期化.

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

			// バインド
			iBind = bind(soc, (const struct sockaddr *)&soc_addr, sizeof(SOCKADDR_IRDA));	// bindでsocにsoc_addrをバインド.
			if (iBind != SOCKET_ERROR){	// SOCKET_ERRORでなければ.

				// 結果成功の出力.
				_tprintf(_T("bind success!\n"));	// "bind success!"と出力.

				// リッスン
				iListen = listen(soc, 1);	// listenで1つ待ち受ける.
				if (iListen != SOCKET_ERROR){	// SOCKET_ERRORでなければ.

					// 結果成功の出力.
					_tprintf(_T("listen success!\n"));	// "listen success!"と出力.

					// アクセプト
					acc = accept(soc, (struct sockaddr *)&acc_addr, &acc_addr_len);	// acceptで待ち受けて, アクセプトソケットをaccに格納.
					if (soc != INVALID_SOCKET){	// INVALID_SOCKETでない時.

						// アクセプトソケットディスクリプタやアドレス情報を出力.
						_tprintf(_T("acc = %d\n"), acc);	// accを出力.
						_tprintf(_T("acc_addr.irdaAddressFamily = %hu\n"), acc_addr.irdaAddressFamily);	// acc_addr.irdaAddressFamilyを出力.
						_tprintf(_T("acc_addr.irdaDeviceID = %02X %02X %02X %02X\n"), acc_addr.irdaDeviceID[3], acc_addr.irdaDeviceID[2], acc_addr.irdaDeviceID[1], acc_addr.irdaDeviceID[0]);	// acc_addr.irdaDeviceIDを出力.
						iServerNameLen = MultiByteToWideChar(CP_ACP, 0, acc_addr.irdaServiceName, -1, NULL, 0);	// MultiByteToWideCharで長さを取得.
						MultiByteToWideChar(CP_ACP, 0, acc_addr.irdaServiceName, -1, tszServerName, iServerNameLen);	// MultiByteToWideCharで変換.
						_tprintf(_T("acc_addr.irdaServiceName = %s\n"), tszServerName);	// tszServerNameを出力.

						// データの受信
						while (TRUE){
							ZeroMemory(btBytes,  sizeof(btBytes));	// メモリクリア.
							iRecvLen = recv(acc, (char *)btBytes, sizeof(btBytes), 0);	// recvでデータを受信し, btBytesに格納.
							_tprintf(_T("btBytes = "));	// "btBytes = "と出力.
							if (iRecvLen == 0){	// 受信出来なかった.
								// 終了処理.
								break;	// 抜ける.
							}
							else{	// 受信出来た.
								for (i = 0; i < iRecvLen; i++){	// iRecvLen分繰り返す.
									_tprintf(_T("%02X "), btBytes[i]);	// btBytesのi番目を出力.
								}
								_tprintf(_T("\n"));	// 改行を出力.
								ZeroMemory(btResponseBytes,  sizeof(btResponseBytes));	// メモリクリア.
								if (btBytes[0] == 0x80){	// 最初の接続リクエストが来たとき.
									btResponseBytes[0] = 0xA0;	// 成功.
									btResponseBytes[1] = 0x00;
									btResponseBytes[2] = 0x07;	// サイズは7バイト.
									btResponseBytes[3] = 0x10;	// OBEXバージョン1.0.
									btResponseBytes[4] = 0x00;	// 接続フラグなし.
									btResponseBytes[5] = 0x10;
									btResponseBytes[6] = 0x00;	// 最大パケットサイズ4K
									send(acc, (const char *)btResponseBytes, btResponseBytes[2], 0);	// sendでbtResponseBytesを送る.
								}
								else if (btBytes[0] == 0x82){	// 最後かつデータ書き込みされている.
									wPacketSize = MAKEWORD(btBytes[2], btBytes[1]);	// wPacketSizeの取得.
									_tprintf(_T("wPacketSize = %hu\n"), wPacketSize);	// wPacketSizeの出力.
									int iIndex = 3;
									// HIの取り出しループ.
									while (TRUE){
										// HIごとに分ける.
										if (btBytes[iIndex] == 0x01){	// Name
											int iTemp = iIndex;
											wNameSize = MAKEWORD(btBytes[iIndex + 2], btBytes[iIndex + 1]);	// wNameSizeの取得.
											int iTemp2 = wNameSize;
											wNameSize = wNameSize - 3;	// HI for NameとName Lengthの3バイトを引かないといけない.
											_tprintf(_T("wNameSize = %hu\n"), wNameSize);	// wNameSizeの出力.
											memcpy(szName, (const char *)&btBytes[iIndex + 3], wNameSize);	// szNameにNameをコピー.
											for (i = 0; i < (wNameSize - 1) / 2; i++){	// (wNameSize - 1) / 2の分繰り返す.
												TCHAR t[2] = {0};	// tを{0}で初期化.
												t[0] = MAKEWORD(szName[2 * i + 1], szName[2 * i]);	// ワイド文字tを生成.
												t[1] = 0;	// t[1]は0.
												_tcscat(tszName, t);	// tszNameにtを連結.
											}
											tszName[(wNameSize - 1) / 2] = 0;	// 最後に0をセット.
											_tprintf(_T("tszName = %s\n"), tszName);
											iTemp = iTemp + iTemp2;
											iIndex = iTemp;
										}
										else if (btBytes[iIndex] == 0xC3){	// Length
											int iTemp = iIndex;
											WORD w1 = MAKEWORD(btBytes[iIndex + 2], btBytes[iIndex + 1]);
											WORD w2 = MAKEWORD(btBytes[iIndex + 4], btBytes[iIndex + 3]);
											DWORD dwLength = MAKELONG(w2, w1);
											_tprintf(_T("dwLength = %08x\n"), dwLength);
											iIndex = iTemp + 5;
										}
										else if (btBytes[iIndex] == 0x49){	// End-of-Body
											WORD wSize = MAKEWORD(btBytes[iIndex + 2], btBytes[iIndex + 1]);
											WORD wBodySize = wSize - 3;
											_tprintf(_T("wBodySize = %08x\n"), wBodySize);
											btResponseBytes[0] = 0xA0;	// 成功.
											btResponseBytes[1] = 0x00;
											btResponseBytes[2] = 0x03;	// サイズは3バイト.
											send(acc, (const char *)btResponseBytes, 3, 0);	// 成功完了を送信.
											FILE *fp = _tfopen(tszName, _T("wb"));	// tszNameで開く.
											if (fp != NULL){	// fpがNULLでない.
												int len = fwrite(&btBytes[iIndex + 3], sizeof(BYTE), wBodySize, fp);	// 書き込む.
												fclose(fp);	// 閉じる.
											}
											break;
										}
									}
								}
								else{
									break;
								}
							}
						}

						// 改行.
						_tprintf(_T("\n"));	// 改行を出力.

						// accを閉じる.
						closesocket(acc);	// closesocketでaccを閉じる.

					}
					
				}
				else{	// SOCKET_ERROR.

					// 結果失敗の出力.
					_tprintf(_T("listen failed!\n"));	// "listen failed!"と出力.

				}

			}
			else{	// SOCKET_ERROR.

				// 結果失敗の出力.
				_tprintf(_T("bind failed!\n"));	// "bind failed!"と出力.

			}

			// socを閉じる.
			closesocket(soc);	// closesocketでsocを閉じる.

		}

		// 終了処理.
		WSACleanup();	// WSACleanupで終了処理.

	}

	// プログラムの終了.
	return 0;

}