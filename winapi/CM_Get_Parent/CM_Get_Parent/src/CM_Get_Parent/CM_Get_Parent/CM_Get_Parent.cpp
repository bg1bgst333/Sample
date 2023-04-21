// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力

// 関数のプロトタイプ宣言
int GetVolumeDeviceNumber(TCHAR* ptszDriveLetter);	// ドライブレターからボリュームのデバイスナンバーを取得.

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言
	int iDeviceNumber;	// デバイスナンバー.

	// コマンドライン引数の数.
	_tprintf(_T("argc = %d\n"), argc);	// argcを出力.
	if (argc != 2){	// 2以外はエラー.
		_tprintf(_T("error: argc != 2\n"));	// "error: argc != 2"と出力.
		return -1;	// -1を返して異常終了.
	}

	// ドライブレターからボリュームのデバイスナンバーを取得.
	iDeviceNumber = GetVolumeDeviceNumber(argv[1]);	// GetVolumeDeviceNumberでiDeviceNumber取得.
	if (iDeviceNumber != -1){	// iDeviceNumberが-1でなければ成功.
		_tprintf(_T("iDeviceNumber = %d\n"), iDeviceNumber);	// iDeviceNumberを出力.
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