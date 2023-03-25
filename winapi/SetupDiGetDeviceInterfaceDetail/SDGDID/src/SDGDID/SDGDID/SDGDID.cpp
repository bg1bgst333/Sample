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
		
		// 出力.
		_tprintf(_T("hDevInfo = 0x%08x\n"), (unsigned long)hDevInfo);	// hDevInfoを出力.

		// 列挙ループ.
		int i = 0;	// インデックスiを0で初期化.
		BOOL bLoop = TRUE;	// ループするかのbLoopをTRUEで初期化.
		while (bLoop){	// bLoopがTRUEの間は続ける.

			// デバイスインターフェースデータの取得.
			SP_DEVICE_INTERFACE_DATA spdid = {0};	// SP_DEVICE_INTERFACE_DATAのspdidを{0}で初期化.
			spdid.cbSize = sizeof(SP_DEVICE_INTERFACE_DATA);	// spdid.cbSizeにsizeofで測ったSP_DEVICE_INTERFACE_DATAのサイズをセット.
			BOOL bRet = SetupDiEnumDeviceInterfaces(hDevInfo, NULL, &GUID_DEVINTERFACE_VOLUME, i, &spdid);	// SetupDiEnumDeviceInterfacesで列挙.
			if (!bRet){	// falseなら
				bLoop = FALSE;	// bLoopをFALSEに.
			}
			else{

				// 詳細情報の取得.(まずはメモリサイズだけ取得.)
				SP_DEVICE_INTERFACE_DETAIL_DATA *pspdidd = NULL;	// インターフェースの詳細情報pspdiddをNULLで初期化.
				DWORD dwMemSize = 0;	// 詳細情報の取得に必要なメモリサイズdwMemSizeを0で初期化.
				SetupDiGetDeviceInterfaceDetail(hDevInfo, &spdid, NULL, 0, &dwMemSize, NULL);	// SetupDiGetDeviceInterfaceDetailでdwMemSizeだけ取得.
				DWORD dwStructSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);	// 構造体のサイズdwStructSizeをsizeofで取得.
				_tprintf(_T("dwMemSize = %lu, dwStructSize = %lu\n"), dwMemSize, dwStructSize);	// dwMemSizeとdwStructSizeを出力.
				i++;	// iをインクリメント.

			}
		}

		// 破棄.
		SetupDiDestroyDeviceInfoList(hDevInfo);	// SetupDiDestroyDeviceInfoListでhDevInfoを破棄.
	}

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}