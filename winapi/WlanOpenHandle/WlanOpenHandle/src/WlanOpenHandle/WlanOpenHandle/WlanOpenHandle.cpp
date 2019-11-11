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

	// WLANのハンドルを開く.
	dwRet = WlanOpenHandle(2, NULL, &dwVer, &hClient);	// WlanOpenHandleでハンドルを開く.(結果をdwRetに格納.バージョンは2.)
	if (dwRet != ERROR_SUCCESS){

		// エラーメッセージ出力.
		_tprintf(_T("Error!: dwRet = %lu\n"), dwRet);	// "Error!"とdwRetの値を出力.
		return -1;	// -1を返して終了.

	}

	// バージョンとクライアントハンドルを出力.
	_tprintf(_T("dwVer = %u, hClient = 0x%08x\n"), dwVer, (DWORD)hClient);	// dwVerとhClientを出力.

	// WLANのハンドルを閉じる.
	WlanCloseHandle(hClient, NULL);	// WlanCloseHandleでハンドルを閉じる.

	// プログラムの終了
	return 0;

}