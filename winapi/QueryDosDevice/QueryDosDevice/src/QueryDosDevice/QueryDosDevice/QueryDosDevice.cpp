// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// コマンドライン引数の数.
	_tprintf(_T("argc = %d\n"), argc);	// argcを出力.
	if (argc != 2){	// 2以外はエラー.
		_tprintf(_T("error: argc != 2\n"));	// "error: argc != 2"と出力.
		return -1;	// -1を返して異常終了.
	}

	// MS-DOSデバイス名の取得.
	TCHAR tszDrive[3] = {0};	// ドライブレターtszDrive(長さ3.)を{0}で初期化.
	_tcscat(tszDrive, argv[1]);	// argv[1]を連結.
	_tcscat(tszDrive, _T(":"));	// ":"を連結.
	TCHAR tszDeviceName[MAX_PATH] = {0};	// デバイス名tszDeviceName(長さMAX_PATH.)を{0}で初期化.
	QueryDosDevice(tszDrive, tszDeviceName, MAX_PATH);	// QueryDosDeviceでtszDeviceNameを取得.
	_tprintf(_T("%s\n"), tszDeviceName);	// tszDeviceNameの出力.

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}