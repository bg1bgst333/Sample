// ヘッダファイルのインクルード
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <windows.h>	// 標準WindowsAPI
#include <setupapi.h>	// SetUpAPI

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言
	HDEVINFO hDevInfo;	// デバイス情報ハンドルhDevInfo

	// ボリュームデバイスのデバイスインターフェースクラスのデバイス情報を取得.
	hDevInfo = SetupDiGetClassDevs(&GUID_DEVINTERFACE_VOLUME, NULL, NULL, DIGCF_PRESENT | DIGCF_INTERFACEDEVICE);	// SetupDiGetClassDevsでGUID_DEVINTERFACE_VOLUMEのhDevInfo取得.
	if (hDevInfo != INVALID_HANDLE_VALUE){	// INVALID_HANDLE_VALUEでなければ.
		_tprintf(_T("hDevInfo = 0x%08x\n"), (unsigned long)hDevInfo);	// hDevInfoを出力.
		SetupDiDestroyDeviceInfoList(hDevInfo);	// SetupDiDestroyDeviceInfoListでhDevInfoを破棄.
	}

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}