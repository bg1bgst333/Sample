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

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}