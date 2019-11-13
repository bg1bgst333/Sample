// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <wlanapi.h>	// WLAN(無線LAN)API

// 無線通知コールバック関数
void WlanNotificationCallback(PWLAN_NOTIFICATION_DATA Arg1, PVOID Arg2){

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

		// 出力.
		_tprintf(_T("pwiiList->InterfaceInfo[%lu].strInterfaceDescription = %s\n"), ul, pwiiList->InterfaceInfo[ul].strInterfaceDescription);	// pwiiList->InterfaceInfo[ul].strInterfaceDescriptionの内容を出力.

		// コールバック登録.
		dwResult = WlanRegisterNotification(hClient, WLAN_NOTIFICATION_SOURCE_ACM, FALSE, (WLAN_NOTIFICATION_CALLBACK)WlanNotificationCallback, NULL, NULL, &dwPrevNotifSource);	// WlanRegisterNotificationでWlanNotificationCallbackを登録.
		_tprintf(_T("dwResult = %lu, dwPrevNotifSource = %lu\n"), dwResult, dwPrevNotifSource);	// dwResultとdwPrevNotifSourceを出力.
		if (dwResult != ERROR_SUCCESS){	// エラー.

			// エラーメッセージ出力.
			_tprintf(_T("Error!: dwRet = %lu\n"), dwRet);	// "Error!"とdwRetの値を出力.
			iRet = -1;	// iRetに-1を代入.
			break;	// 抜ける.

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