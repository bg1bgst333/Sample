// ヘッダファイルのインクルード
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <stdlib.h>		// 標準ユーティリティ
#include <string.h>		// 文字列処理
#include <windows.h>	// 標準WindowsAPI
#include <setupapi.h>	// SetUpAPI

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// ドライブレターからボリューム名.(デバイス番号も.)
	TCHAR tszDrives[128] = {0};	// ドライブ文字列群が格納されるTCHAR型配列tszDrives(長さ128)を{0}で初期化.
	TCHAR *ptszDrive = NULL;	// ドライブ文字列を指すTCHAR型ポインタptszDriveをNULLで初期化.
	// 有効なドライブ文字列群を取得.
	GetLogicalDriveStrings(128, tszDrives);	// GetLogicalDriveStringsで有効なドライブ文字列群を取得.
	// ドライブ文字列一覧出力.
	ptszDrive = tszDrives;	// 先頭にセット.
	while (*ptszDrive != _T('\0')){	// NULL文字でない.
		_tprintf(_T("%s\n"), ptszDrive);	// ptszDriveを出力.
		// ボリューム名を出力.
		TCHAR tszVolumeName[MAX_PATH] = {0};	// ボリューム名tszVolumeName(長さMAX_PATH)を{0}で初期化.
		BOOL bRet = GetVolumeNameForVolumeMountPoint(ptszDrive, tszVolumeName, MAX_PATH);	// GetVolumeNameForVolumeMountPointでボリューム名取得.
		if (bRet){	// 成功.
			_tprintf(_T("tszVolumeName = %s\n"), tszVolumeName);	// tszVolumeNameを出力.
		}
		// デバイス番号を出力.
		TCHAR tszPath[MAX_PATH] = {0};
		_tcscat(tszPath, _T("\\\\.\\"));
		_tcscat(tszPath, ptszDrive);
		tszPath[_tcslen(tszPath) - 1] = _T('\0');
		HANDLE hVolume = CreateFile(tszPath, 0, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);	// CreateFileでhVolume取得.
		if (hVolume != NULL){	// 開けたら.
			DWORD dwSize = 0x400;	// これぐらい用意しておく.
			DWORD dwBytes = 0;
			BYTE *pBytes = (BYTE *)malloc(dwSize);	// メモリ確保.
			BOOL bRet = DeviceIoControl(hVolume, IOCTL_STORAGE_GET_DEVICE_NUMBER, NULL, 0, pBytes, (DWORD)dwSize, &dwBytes, NULL);	// DeviceIoControlでデバイスナンバー取得.
			STORAGE_DEVICE_NUMBER *pSDN = (STORAGE_DEVICE_NUMBER *)pBytes;	// STORAGE_DEVICE_NUMBERポインタに移し替える.
			DWORD dwDeviceNumber = pSDN->DeviceNumber;
			_tprintf(_T("dwDeviceNumber = %lu\n"), dwDeviceNumber);	// dwDeviceNumberを出力.
			free(pBytes);	// メモリ解放.
			CloseHandle(hVolume);	// 閉じる.
		}
		ptszDrive += _tcslen(ptszDrive) + 1;	// ptszDriveの(文字数 + 1)の分だけ進む.
	}

	// デバイスパスからボリューム名.
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
				// 詳細情報の取得.(SP_DEVINFO_DATAも取得.)
				SP_DEVICE_INTERFACE_DETAIL_DATA *pspdidd = NULL;	// インターフェースの詳細情報pspdiddをNULLで初期化.
				DWORD dwMemSize = 0;	// 詳細情報の取得に必要なメモリサイズdwMemSizeを0で初期化.
				SetupDiGetDeviceInterfaceDetail(hDevInfo, &spdid, NULL, 0, &dwMemSize, NULL);	// SetupDiGetDeviceInterfaceDetailでdwMemSizeだけ取得.
				DWORD dwStructSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);	// 構造体のサイズdwStructSizeをsizeofで取得.
				_tprintf(_T("dwMemSize = %lu, dwStructSize = %lu\n"), dwMemSize, dwStructSize);	// dwMemSizeとdwStructSizeを出力.
				pspdidd = (SP_DEVICE_INTERFACE_DETAIL_DATA *)malloc(dwMemSize);	// dwMemSize分のメモリを確保し, アドレスはpspdiddに格納.
				memset(pspdidd, 0, dwMemSize);	// メモリを全て0にクリア.
				pspdidd->cbSize = dwStructSize;	// pspdidd->cbSizeにdwStructSizeをセット.
				SP_DEVINFO_DATA spdd = {0};	// SP_DEVINFO_DATAのspddを{0}で初期化.
				spdd.cbSize = sizeof(SP_DEVINFO_DATA);	// 構造体のサイズをsizeofで取得し, spdd.cbSizeにセット.
				BOOL bRet = SetupDiGetDeviceInterfaceDetail(hDevInfo, &spdid, pspdidd, dwMemSize, &dwMemSize, &spdd);	// SetupDiGetDeviceInterfaceDetailでpspdiddの中身を取得.(spddも取得.)
				if (bRet){	// TRUEなら.
					// デバイスパスを出力.
					_tprintf(_T("pspdidd->DevicePath = %s\n"), pspdidd->DevicePath);	// pspdidd->DevicePathを出力.
					// ボリューム名を出力.
					TCHAR tszVolumeName[MAX_PATH] = {0};	// ボリューム名tszVolumeName(長さMAX_PATH)を{0}で初期化.
					// デバイスパスに"\"を追加.
					TCHAR path[MAX_PATH] = {0};
					_tcscat(path,  pspdidd->DevicePath);
					_tcscat(path, _T("\\"));	// これがないと失敗!
					BOOL bRet = GetVolumeNameForVolumeMountPoint(path, tszVolumeName, MAX_PATH);	// GetVolumeNameForVolumeMountPointでボリューム名取得.
					if (bRet){	// 成功.
						_tprintf(_T("tszVolumeName = %s\n"), tszVolumeName);	// tszVolumeNameを出力.
					}
					// DevInstを出力.
					_tprintf(_T("spdd.DevInst = %lu\n"), spdd.DevInst);	// spdd.DevInstを出力.
					// デバイス番号を出力.
					TCHAR tszPath[MAX_PATH] = {0};
					_tcscat(tszPath, path);
					HANDLE hVolume = CreateFile(tszPath, 0, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);	// CreateFileでhVolume取得.
					if (hVolume != NULL){	// 開けたら.
						DWORD dwSize = 0x400;	// これぐらい用意しておく.
						DWORD dwBytes = 0;
						BYTE *pBytes = (BYTE *)malloc(dwSize);	// メモリ確保.
						BOOL bRet = DeviceIoControl(hVolume, IOCTL_STORAGE_GET_DEVICE_NUMBER, NULL, 0, pBytes, (DWORD)dwSize, &dwBytes, NULL);	// DeviceIoControlでデバイスナンバー取得.
						STORAGE_DEVICE_NUMBER *pSDN = (STORAGE_DEVICE_NUMBER *)pBytes;	// STORAGE_DEVICE_NUMBERポインタに移し替える.
						DWORD dwDeviceNumber = pSDN->DeviceNumber;
						_tprintf(_T("dwDeviceNumber = %lu\n"), dwDeviceNumber);	// dwDeviceNumberを出力.
						free(pBytes);	// メモリ解放.
						CloseHandle(hVolume);	// 閉じる.
					}
				}
				free(pspdidd);	// pspdiddを解放.
				i++;	// iをインクリメント.
			}
		}
		// 破棄.
		SetupDiDestroyDeviceInfoList(hDevInfo);	// SetupDiDestroyDeviceInfoListでhDevInfoを破棄.
	}

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}