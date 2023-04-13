// ヘッダファイルのインクルード
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <windows.h>	// 標準WindowsAPI
#include <setupapi.h>	// SetUpAPI

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言
	HDEVINFO hDevInfo;	// デバイス情報ハンドルhDevInfo

	// ボリュームデバイス一覧を取得.
	hDevInfo = SetupDiGetClassDevs(&GUID_DEVINTERFACE_VOLUME, NULL, NULL, DIGCF_PRESENT | DIGCF_INTERFACEDEVICE);	// SetupDiGetClassDevsでhDevInfo取得.
	if (hDevInfo != INVALID_HANDLE_VALUE){	// INVALID_HANDLE_VALUEでなければ.

		// 出力.
		_tprintf(_T("hDevInfo = 0x%08x\n"), (unsigned long)hDevInfo);	// hDevInfoを出力.

		// 列挙ループ.
		int i = 0;	// インデックスiを0で初期化.
		BOOL bLoop = TRUE;	// ループするかのbLoopをTRUEで初期化.
		while (bLoop){	// bLoopがTRUEの間は続ける.

			// デバイス情報の取得.
			SP_DEVINFO_DATA spdd = {0};	// SP_DEVINFO_DATAのspddを{0}で初期化.
			spdd.cbSize = sizeof(SP_DEVINFO_DATA);	// 構造体のサイズをsizeofで取得し, spdd.cbSizeにセット.
			BOOL bRet = SetupDiEnumDeviceInfo(hDevInfo, i, &spdd);	// SetupDiEnumDeviceInfoで列挙.
			if (!bRet){	// FALSEなら.
				bLoop = FALSE;	// bLoopをFALSEに.
			}
			else{	// TRUEなら.
				// spdd.ClassGuidを出力.
				WCHAR *pwszGuidStr1;	// GUID文字列を指すWCHARポインタpwszGuidStr1.
				StringFromCLSID(spdd.ClassGuid, &pwszGuidStr1);	// StringFromCLSIDでspdd.ClassGuidをGUID文字列に変換.
				_tprintf(_T("%s\n"), pwszGuidStr1);	// pwszGuidStr1を出力.
				CoTaskMemFree(pwszGuidStr1);	// pwszGuidStr1を解放.
				// プロパティの取得.(クラス名.)
				DWORD dwRegType;	// プロパティの型.
				DWORD dwSize;	// プロパティのサイズ.
				SetupDiGetDeviceRegistryProperty(hDevInfo, &spdd, SPDRP_CLASS, &dwRegType, NULL, 0, &dwSize);	// SetupDiGetDeviceRegistryPropertyでクラス名のサイズ取得.
				if (dwRegType == REG_SZ){	// 文字列.
					_tprintf(_T("dwSize = %lu\n"), dwSize);	// dwSizeを出力.
					BYTE *pBytes = new BYTE[dwSize];	// newでBYTE配列の確保.
					SetupDiGetDeviceRegistryProperty(hDevInfo, &spdd, SPDRP_CLASS, &dwRegType, pBytes, dwSize, &dwSize);	// SetupDiGetDeviceRegistryPropertyでクラス名を取得.
					_tprintf(_T("SPDRP_CLASS: %s\n"), (TCHAR *)pBytes);	// pBytesを出力.
					delete [] pBytes;	// pBytesを解放.
				}
				// プロパティの取得.(クラスGUID.)
				SetupDiGetDeviceRegistryProperty(hDevInfo, &spdd, SPDRP_CLASSGUID, &dwRegType, NULL, 0, &dwSize);	// SetupDiGetDeviceRegistryPropertyでクラスGUIDのサイズ取得.
				if (dwRegType == REG_SZ){	// 文字列.
					_tprintf(_T("dwSize = %lu\n"), dwSize);	// dwSizeを出力.
					BYTE *pBytes = new BYTE[dwSize];	// newでBYTE配列の確保.
					SetupDiGetDeviceRegistryProperty(hDevInfo, &spdd, SPDRP_CLASSGUID, &dwRegType, pBytes, dwSize, &dwSize);	// SetupDiGetDeviceRegistryPropertyでクラスGUIDを取得.
					_tprintf(_T("SPDRP_CLASSGUID: %s\n"), (TCHAR *)pBytes);	// pBytesを出力.
					delete [] pBytes;	// pBytesを解放.
				}
				// プロパティの取得.(デバイスの説明.)
				SetupDiGetDeviceRegistryProperty(hDevInfo, &spdd, SPDRP_DEVICEDESC, &dwRegType, NULL, 0, &dwSize);	// SetupDiGetDeviceRegistryPropertyでデバイスの説明のサイズ取得.
				if (dwRegType == REG_SZ){	// 文字列.
					_tprintf(_T("dwSize = %lu\n"), dwSize);	// dwSizeを出力.
					BYTE *pBytes = new BYTE[dwSize];	// newでBYTE配列の確保.
					SetupDiGetDeviceRegistryProperty(hDevInfo, &spdd, SPDRP_DEVICEDESC, &dwRegType, pBytes, dwSize, &dwSize);	// SetupDiGetDeviceRegistryPropertyでデバイスの説明を取得.
					_tprintf(_T("SPDRP_DEVICEDESC: %s\n"), (TCHAR *)pBytes);	// pBytesを出力.
					delete [] pBytes;	// pBytesを解放.
				}
				i++;	// iをインクリメント.
			}

		}

		// 破棄.
		SetupDiDestroyDeviceInfoList(hDevInfo);	// SetupDiDestroyDeviceInfoListでhDevInfoを破棄.

	}

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}