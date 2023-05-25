// ヘッダファイルのインクルード
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <windows.h>	// 標準WindowsAPI
#include <setupapi.h>	// SetUpAPI
#include <cfgmgr32.h>	// Configuration Manager

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言
	HDEVINFO hDevInfo;	// デバイス情報ハンドルhDevInfo

	// すべてのデバイス一覧を取得.
	hDevInfo = SetupDiGetClassDevs(NULL, NULL, NULL, DIGCF_PRESENT | DIGCF_ALLCLASSES);	// SetupDiGetClassDevsでhDevInfo取得.
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

				// プロパティの取得.(サービス名.)
				DWORD dwRegType;	// プロパティの型.
				DWORD dwSize;	// プロパティのサイズ.
				SetupDiGetDeviceRegistryProperty(hDevInfo, &spdd, SPDRP_SERVICE, &dwRegType, NULL, 0, &dwSize);	// SetupDiGetDeviceRegistryPropertyでサービス名のサイズ取得.
				if (dwRegType == REG_SZ){	// 文字列.
					//_tprintf(_T("dwSize = %lu\n"), dwSize);	// dwSizeを出力.
					BYTE *pBytes = new BYTE[dwSize];	// newでBYTE配列の確保.
					SetupDiGetDeviceRegistryProperty(hDevInfo, &spdd, SPDRP_SERVICE, &dwRegType, pBytes, dwSize, &dwSize);	// SetupDiGetDeviceRegistryPropertyでサービス名を取得.
					//_tprintf(_T("SPDRP_SERVICE: %s\n"), (TCHAR *)pBytes);	// pBytesを出力.
					// "USBSTOR"の場合.
					if (_tcscmp((TCHAR *)pBytes, _T("USBSTOR")) == 0){	// pBytesが"USBSTOR"の場合.
						_tprintf(_T("SPDRP_SERVICE: %s\n"), (TCHAR *)pBytes);	// pBytesを出力.
						// デバイスの状態を取得し, リムーバブルか判定.
						unsigned long ulStatus = 0;	// 状態ulStatusを0で初期化.
						unsigned long ulProblem = 0;	// 問題ulProblemを0で初期化.
						DWORD dwRet = CM_Get_DevNode_Status(&ulStatus, &ulProblem, spdd.DevInst, 0);	// CM_Get_DevNode_Statusで状態を取得.
						if (dwRet == CR_SUCCESS){	// 成功.
							if ((ulStatus & DN_DISABLEABLE) && (ulStatus & DN_REMOVABLE)){	// 無効化可能かつ取り外し可能.
								_tprintf(_T("DN_DISABLEABLE and DN_REMOVABLE\n"));	// "DN_DISABLEABLE and DN_REMOVABLE"を出力.
								// プロパティの取得.(クラス名.)
								DWORD dwRegType;	// プロパティの型.
								DWORD dwSize;	// プロパティのサイズ.
								SetupDiGetDeviceRegistryProperty(hDevInfo, &spdd, SPDRP_CLASS, &dwRegType, NULL, 0, &dwSize);	// SetupDiGetDeviceRegistryPropertyでクラス名のサイズ取得.
								if (dwRegType == REG_SZ){	// 文字列.
									//_tprintf(_T("dwSize = %lu\n"), dwSize);	// dwSizeを出力.
									BYTE *ptszClass = new BYTE[dwSize];	// newでBYTE配列の確保.
									SetupDiGetDeviceRegistryProperty(hDevInfo, &spdd, SPDRP_CLASS, &dwRegType, ptszClass, dwSize, &dwSize);	// SetupDiGetDeviceRegistryPropertyでクラス名を取得.
									_tprintf(_T("SPDRP_CLASS: %s\n"), (TCHAR *)ptszClass);	// ptszClassを出力.
									delete [] ptszClass;	// ptszClassを解放.
								}
								// デバイスIDを格納するバッファの長さを取得.
								unsigned long ulBufLen = 0;	// バッファの長さulBufLenを0で初期化.
								BOOL bRet = SetupDiGetDeviceInstanceId(hDevInfo, &spdd, NULL, 0, &ulBufLen);	// SetupDiGetDeviceInstanceIdでulBufLenを取得.
								_tprintf(_T("ulBufLen = %lu\n"), ulBufLen);	// ulBufLenを出力.
								TCHAR *ptszDevID = new TCHAR[ulBufLen];	// サイズがulBufLenなTCHAR動的配列をnewで確保し, ポインタをptszDevIDに格納.(ulBufLenはNULL文字含む.)
								// デバイスIDの取得.
								bRet = SetupDiGetDeviceInstanceId(hDevInfo, &spdd, ptszDevID, ulBufLen, &ulBufLen);	// SetupDiGetDeviceInstanceIdでptszDevIDを取得.
								if (bRet){	// bRetがTRUE.
									_tprintf(_T("ptszDevID = %s\n"), ptszDevID);	// ptszDevIDを出力.
								}
								delete [] ptszDevID;	// 解放.
								// デバイスの取り出し
								PNP_VETO_TYPE pvtVetoType;
								TCHAR tszVetoName[MAX_PATH] = {0};
								int iResult = CM_Request_Device_Eject(spdd.DevInst, &pvtVetoType, tszVetoName, MAX_PATH, 0);	// CM_Request_Device_Ejectでspdd.DevInstの指すデバイスの取り出し.
								if (iResult == 0){	// iResultが0なら.
									_tprintf(_T("CM_Request_Device_Eject succeed.\n"));	// "CM_Request_Device_Eject succeed."と出力.
								}
								else{
									_tprintf(_T("CM_Request_Device_Eject failure.\n"));	// "CM_Request_Device_Eject failure."と出力.
								}
							}
						}
					}
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