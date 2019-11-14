// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <wlanapi.h>	// WLAN(無線LAN)API

// 無線通知コールバック関数
static void WlanNotificationCallback(PWLAN_NOTIFICATION_DATA Arg1, PVOID Arg2){

	// 通知された状態を出力.
	if (Arg1->NotificationSource == WLAN_NOTIFICATION_SOURCE_ACM){	// 通知元がACMの時.
		_tprintf(_T("WLAN_NOTIFICATION_SOURCE_ACM\n"));	// "WLAN_NOTIFICATION_SOURCE_ACM"と出力.
	}

}

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言
	DWORD dwRet;	// WlanOpenHandleの戻り値を格納するDWORD型dwRet.
	DWORD dwVer;	// ここで使うWLANAPIのバージョンdwVer.
	HANDLE hClient;	// クライアントハンドルhClient
	WLAN_INTERFACE_INFO_LIST *pwiiList;	// WLAN_INTERFACE_INFO_LIST *型ポインタpwiiList
	WLAN_INTERFACE_INFO *pwii;	// WLAN_INTERFACE_INFO * 型ポインタpwii
	unsigned long ul;	// ループ用unsigned long型変数ul
	DWORD dwPrevNotifSource;	// 以前の通知元.
	DWORD dwResult;	// コールバック登録の結果.
	int iRet;	// プログラムの戻り値.

	// WLANのハンドルを開く.
	dwRet = WlanOpenHandle(WLAN_API_MAKE_VERSION(1, 0), NULL, &dwVer, &hClient);	// WlanOpenHandleでハンドルを開く.(結果をdwRetに格納.)
	if (dwRet != ERROR_SUCCESS){

		// エラーメッセージ出力.
		_tprintf(_T("Error!: dwRet = %lu\n"), dwRet);	// "Error!"とdwRetの値を出力.
		return -1;	// -1を返して終了.

	}

	// 無線インターフェース一覧を取得.
	WlanEnumInterfaces(hClient, NULL, &pwiiList);	// WlanEnumInterfacesでインターフェースリストを取得し, pwiiListに格納.

	// 無線インターフェース一覧の出力.
	iRet = 0;	// iRetに0を代入.
	for (ul = 0; ul < pwiiList->dwNumberOfItems; ul++){

		// 変数の初期化.
		unsigned long ul2 = 0;	// ループ用ul2を0で初期化.
		WLAN_AVAILABLE_NETWORK_LIST *pNetworkList = NULL;	// WLAN_AVAILABLE_NETWORK_LIST構造体ポインタpNetworkListをNULLで初期化.
		DWORD dwRet = 0;	// 結果dwRetを0で初期化.

		// pwiiの取得.
		pwii = (WLAN_INTERFACE_INFO *)&pwiiList->InterfaceInfo[ul];	// ul番目のインターフェース情報をpwiiに格納.

		// 出力.
		_tprintf(_T("pwiiList->InterfaceInfo[%lu].strInterfaceDescription = %s\n"), ul, pwiiList->InterfaceInfo[ul].strInterfaceDescription);	// pwiiList->InterfaceInfo[ul].strInterfaceDescriptionの内容を出力.

		// コールバック登録.
		dwResult = WlanRegisterNotification(hClient, WLAN_NOTIFICATION_SOURCE_ACM, FALSE, (WLAN_NOTIFICATION_CALLBACK)WlanNotificationCallback, NULL, NULL, &dwPrevNotifSource);	// WlanRegisterNotificationでWlanNotificationCallbackを登録.
		_tprintf(_T("dwResult = %lu, dwPrevNotifSource = %lu\n"), dwResult, dwPrevNotifSource);	// dwResultとdwPrevNotifSourceを出力.
		if (dwResult != ERROR_SUCCESS){	// エラー.

			// エラーメッセージ出力.
			_tprintf(_T("RegisterError!: dwRet = %lu\n"), dwRet);	// "RegisterError!"とdwRetの値を出力.
			iRet = -1;	// iRetに-1を代入.
			break;	// 抜ける.

		}

		// スキャン.
		dwResult = WlanScan(hClient, &pwii->InterfaceGuid, NULL, NULL, NULL);	// WlanScanでスキャン.
		if (dwResult != ERROR_SUCCESS){	// エラー.

			// エラーメッセージ出力.
			_tprintf(_T("ScanError!: dwRet = %lu\n"), dwRet);	// "ScanError!"とdwRetの値を出力.
			iRet = -1;	// iRetに-1を代入.
			break;	// 抜ける.

		}

		// 一定時間休止.
		Sleep(500);	// 0.5秒休止.

		// ネットワークリストの取得.
		dwRet = WlanGetAvailableNetworkList(hClient, &pwiiList->InterfaceInfo[ul].InterfaceGuid, 0, NULL, &pNetworkList);	// WlanGetAvailableNetworkListでネットワークリストの取得.
		if (dwRet == ERROR_SUCCESS){	// 成功.

			// SSID一覧の出力.
			for (ul2 = 0; ul < pNetworkList->dwNumberOfItems; ul2++){

				// networkを取得してSSID出力.
				WLAN_AVAILABLE_NETWORK *network = &pNetworkList->Network[ul2];	// netowrkの取得.
				DOT11_SSID *ssid = &network->dot11Ssid;	// ssidの取得.
				wchar_t wszSSID[256] = {0};	// wszSSIDを{0}で初期化.
				mbstowcs(wszSSID, (const char *)ssid->ucSSID, ssid->uSSIDLength);	// mbstowcsで変換.
				wprintf(L"wszSSID = %s\n", wszSSID);	// wszSSIDを出力.

			}

			// ネットワークリストの解放
			WlanFreeMemory(pNetworkList);	// WlanFreeMemoryでpNetworkListを解放.

		}

	}

	// コールバック解除.
	if (hClient != NULL){	// hClientがNULLでない場合.
		dwResult = WlanRegisterNotification(hClient, WLAN_NOTIFICATION_SOURCE_NONE, TRUE, NULL, NULL, NULL, &dwPrevNotifSource);	// NULLをセットして解除.
		_tprintf(_T("dwResult = %lu, dwPrevNotifSource = %lu\n"), dwResult, dwPrevNotifSource);	// dwResultとdwPrevNotifSourceを出力.
	}

	// メモリ解放.
	WlanFreeMemory(pwiiList);	// WlanFreeMemoryでpwiiListのメモリを解放する必要あり.

	// WLANのハンドルを閉じる.
	WlanCloseHandle(hClient, NULL);	// WlanCloseHandleでハンドルを閉じる.

	// プログラムの終了
	return iRet;	// iRetを返す.

}