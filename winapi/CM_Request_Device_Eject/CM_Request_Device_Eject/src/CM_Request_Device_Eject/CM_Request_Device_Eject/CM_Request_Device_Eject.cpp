// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <setupapi.h>	// SetUpAPI
#include <cfgmgr32.h>	// Configuration Manager

// 関数のプロトタイプ宣言
int GetVolumeDeviceNumber(TCHAR* ptszDriveLetter);	// ドライブレターからボリュームのデバイスナンバーを取得.
int GetDeviceNumberByDevicePath(TCHAR* ptszDevicePath);	// デバイスパスからデバイスナンバーを取得.
int GetDiskDevInst(DWORD dwDeviceNumber);	// デバイスナンバーからディスクのDevInstを取得.

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// コマンドライン引数の数.
	_tprintf(_T("argc = %d\n"), argc);	// argcを出力.
	if (argc != 2){	// 2以外はエラー.
		_tprintf(_T("error: argc != 2\n"));	// "error: argc != 2"と出力.
		return -1;	// -1を返して異常終了.
	}

	// ドライブレターからボリュームのデバイスナンバーを取得.
	int iDeviceNumber = GetVolumeDeviceNumber(argv[1]);	// GetVolumeDeviceNumberでiDeviceNumber取得.
	if (iDeviceNumber != -1){	// iDeviceNumberが-1でなければ成功.
		_tprintf(_T("iDeviceNumber = %d\n"), iDeviceNumber);	// iDeviceNumberを出力.
	}

	// デバイスナンバーからディスクのDevInstを取得.
	int iDiskDevInst = -1;	// iDiskDevInstを-1で初期化.
	if (iDeviceNumber != -1){	// iDeviceNumberが-1でなければ.
		iDiskDevInst = GetDiskDevInst((DWORD)iDeviceNumber);	// GetDiskDevInstでiDiskDevInstを取得.
		if (iDiskDevInst != -1){	// iDiskDevInstが-1でなければ成功.
			_tprintf(_T("iDiskDevInst = %d\n"), iDiskDevInst);	// iDiskDevInstを出力.
		}
	}

	// iDiskDevInstの親のDevInstを取得.
	DWORD dwDevInstParent;	// 親のDevInstであるdwDevInstParent.
	if (iDiskDevInst != -1){	// iDiskDevInstが-1でなければ.
		CM_Get_Parent(&dwDevInstParent, (DWORD)iDiskDevInst, 0);	// CM_Get_ParentでiDiskDevInstの親のデバイスのDevInstであるdwDevInstParent取得.
		_tprintf(_T("dwDevInstParent = %lu\n"), dwDevInstParent);	// dwDevInstParentを出力.
	}

	// デバイスの取り出し
	PNP_VETO_TYPE pvtVetoType;
	TCHAR tszVetoName[MAX_PATH] = {0};
	int iResult = CM_Request_Device_Eject(dwDevInstParent, &pvtVetoType, tszVetoName, MAX_PATH, 0);	// CM_Request_Device_EjectでdwDevInstParentの指すデバイスの取り出し.
	if (iResult == 0){	// iResultが0なら.
		_tprintf(_T("CM_Request_Device_Eject succeed.\n"));	// "CM_Request_Device_Eject succeed."と出力.
	}
	else{
		_tprintf(_T("CM_Request_Device_Eject failure.\n"));	// "CM_Request_Device_Eject failure."と出力.
	}

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}

// ドライブレターからボリュームのデバイスナンバーを取得.
int GetVolumeDeviceNumber(TCHAR* ptszDriveLetter){

	// 配列の初期化
	TCHAR tszPath[MAX_PATH] = {0};

	// パスの整形
	_tcscat(tszPath, _T("\\\\.\\"));
	_tcscat(tszPath, ptszDriveLetter);
	_tcscat(tszPath, _T(":"));

	// 開く.
	HANDLE hVolume = CreateFile(tszPath, 0, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);	// CreateFileでhVolume取得.
	if (hVolume != INVALID_HANDLE_VALUE){	// 開けたら.
		DWORD dwSize = 0x400;	// これぐらい用意しておく.
		DWORD dwBytes = 0;
		BYTE *pBytes = (BYTE *)malloc(dwSize);	// メモリ確保.
		BOOL bRet = DeviceIoControl(hVolume, IOCTL_STORAGE_GET_DEVICE_NUMBER, NULL, 0, pBytes, (DWORD)dwSize, &dwBytes, NULL);	// DeviceIoControlでデバイスナンバー取得.
		STORAGE_DEVICE_NUMBER *pSDN = (STORAGE_DEVICE_NUMBER *)pBytes;	// STORAGE_DEVICE_NUMBERポインタに移し替える.
		DWORD dwDeviceNumber = pSDN->DeviceNumber;
		free(pBytes);	// メモリ解放.
		CloseHandle(hVolume);	// 閉じる.
		return (int)dwDeviceNumber;	// dwDeviceNumberをintにキャストして返す.
	}
	else{	// 失敗.
		return -1;	// -1を返す.
	}

}

// デバイスパスからデバイスナンバーを取得.
int GetDeviceNumberByDevicePath(TCHAR* ptszDevicePath){

	// 配列の初期化
	TCHAR tszPath[MAX_PATH] = {0};

	// パスの整形
	_tcscat(tszPath, ptszDevicePath);

	// 開く.
	HANDLE handle = CreateFile(tszPath, 0, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);	// CreateFileでhandle取得.
	if (handle != INVALID_HANDLE_VALUE){	// 開けたら.
		DWORD dwSize = 0x400;	// これぐらい用意しておく.
		DWORD dwBytes = 0;
		BYTE *pBytes = (BYTE *)malloc(dwSize);	// メモリ確保.
		BOOL bRet = DeviceIoControl(handle, IOCTL_STORAGE_GET_DEVICE_NUMBER, NULL, 0, pBytes, (DWORD)dwSize, &dwBytes, NULL);	// DeviceIoControlでデバイスナンバー取得.
		STORAGE_DEVICE_NUMBER *pSDN = (STORAGE_DEVICE_NUMBER *)pBytes;	// STORAGE_DEVICE_NUMBERポインタに移し替える.
		DWORD dwDeviceNumber = pSDN->DeviceNumber;
		free(pBytes);	// メモリ解放.
		CloseHandle(handle);	// 閉じる.
		return (int)dwDeviceNumber;	// dwDeviceNumberをintにキャストして返す.
	}
	else{	// 失敗.
		return -1;	// -1を返す.
	}

}

// デバイスナンバーからディスクのDevInstを取得.
int GetDiskDevInst(DWORD dwDeviceNumber){

	// デバイスインターフェースデータの列挙
	HDEVINFO hDevInfo;	// デバイス情報ハンドルhDevInfo
	int iDevInst = -1;	// 返すDevInstの値iDevInstを-1で初期化.
	// ディスクデバイスのデバイスインターフェースクラスのデバイス情報を取得.
	hDevInfo = SetupDiGetClassDevs(&GUID_DEVINTERFACE_DISK, NULL, NULL, DIGCF_PRESENT | DIGCF_INTERFACEDEVICE);	// SetupDiGetClassDevsでGUID_DEVINTERFACE_DISKのhDevInfo取得.
	if (hDevInfo != INVALID_HANDLE_VALUE){	// INVALID_HANDLE_VALUEでなければ.
		// 列挙ループ.
		int i = 0;	// インデックスiを0で初期化.
		BOOL bLoop = TRUE;	// ループするかのbLoopをTRUEで初期化.
		while (bLoop){	// bLoopがTRUEの間は続ける.
			// デバイスインターフェースデータの取得.
			SP_DEVICE_INTERFACE_DATA spdid = {0};	// SP_DEVICE_INTERFACE_DATAのspdidを{0}で初期化.
			spdid.cbSize = sizeof(SP_DEVICE_INTERFACE_DATA);	// spdid.cbSizeにsizeofで測ったSP_DEVICE_INTERFACE_DATAのサイズをセット.
			BOOL bRet = SetupDiEnumDeviceInterfaces(hDevInfo, NULL, &GUID_DEVINTERFACE_DISK, i, &spdid);	// SetupDiEnumDeviceInterfacesで列挙.
			if (!bRet){	// falseなら
				bLoop = FALSE;	// bLoopをFALSEに.
			}
			else{
				// 詳細情報の取得.(SP_DEVINFO_DATAも取得.)
				SP_DEVICE_INTERFACE_DETAIL_DATA *pspdidd = NULL;	// インターフェースの詳細情報pspdiddをNULLで初期化.
				DWORD dwMemSize = 0;	// 詳細情報の取得に必要なメモリサイズdwMemSizeを0で初期化.
				SetupDiGetDeviceInterfaceDetail(hDevInfo, &spdid, NULL, 0, &dwMemSize, NULL);	// SetupDiGetDeviceInterfaceDetailでdwMemSizeだけ取得.
				DWORD dwStructSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);	// 構造体のサイズdwStructSizeをsizeofで取得.
				pspdidd = (SP_DEVICE_INTERFACE_DETAIL_DATA *)malloc(dwMemSize);	// dwMemSize分のメモリを確保し, アドレスはpspdiddに格納.
				memset(pspdidd, 0, dwMemSize);	// メモリを全て0にクリア.
				pspdidd->cbSize = dwStructSize;	// pspdidd->cbSizeにdwStructSizeをセット.
				SP_DEVINFO_DATA spdd = {0};	// SP_DEVINFO_DATAのspddを{0}で初期化.
				spdd.cbSize = sizeof(SP_DEVINFO_DATA);	// 構造体のサイズをsizeofで取得し, spdd.cbSizeにセット.
				BOOL bRet = SetupDiGetDeviceInterfaceDetail(hDevInfo, &spdid, pspdidd, dwMemSize, &dwMemSize, &spdd);	// SetupDiGetDeviceInterfaceDetailでpspdiddの中身を取得.(spddも取得.)
				if (bRet){	// TRUEなら.
					// DevInstを出力.
					_tprintf(_T("spdd.DevInst = %lu\n"), spdd.DevInst);	// spdd.DevInstを出力.
					// デバイスナンバーを取得.
					int iDeviceNumber = GetDeviceNumberByDevicePath(pspdidd->DevicePath);	// GetDeviceNumberByDevicePathでデバイスナンバー取得.
					if (iDeviceNumber == (int)dwDeviceNumber){	// 同じ.
						iDevInst = spdd.DevInst;	// spdd.DevInstをiDevInstに代入.
					}
				}
				free(pspdidd);	// pspdiddを解放.
				i++;	// iをインクリメント.
			}
		}
		// 破棄.
		SetupDiDestroyDeviceInfoList(hDevInfo);	// SetupDiDestroyDeviceInfoListでhDevInfoを破棄.
	}

	// 関数の終わり.
	return iDevInst;	// iDevInstを返す.

}