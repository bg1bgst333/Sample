// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <wlanapi.h>	// WLAN(無線LAN)API

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言
	DWORD dwRet;	// WlanOpenHandleの戻り値を格納するDWORD型dwRet.
	DWORD dwVer;	// ここで使うWLANAPIのバージョンdwVer.
	HANDLE hClient;	// クライアントハンドルhClient
	WLAN_INTERFACE_INFO_LIST *pwiiList;	// WLAN_INTERFACE_INFO_LIST *型ポインタpwiiList
	unsigned long ul;	// ループ用unsigned long型変数ul

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
	for (ul = 0; ul < pwiiList->dwNumberOfItems; ul++){

		// 出力.
		_tprintf(_T("pwiiList->InterfaceInfo[%lu].strInterfaceDescription = %s\n"), ul, pwiiList->InterfaceInfo[ul].strInterfaceDescription);	// pwiiList->InterfaceInfo[ul].strInterfaceDescriptionの内容を出力.

	}

	// メモリ解放.
	WlanFreeMemory(pwiiList);	// WlanFreeMemoryでpwiiListのメモリを解放する必要あり.

	// WLANのハンドルを閉じる.
	WlanCloseHandle(hClient, NULL);	// WlanCloseHandleでハンドルを閉じる.

	// プログラムの終了
	return 0;

}