// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <shlwapi.h>	// シェルAPI

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言と初期化.
	TCHAR tszFilePath[] = _T("C:\\Users\\B.G\\Documents\\test\\test.txt");	// tszFilePathを"test.txt"のパスで初期化.
	TCHAR tszFolderPath[] = _T("C:\\Users\\B.G\\Documents\\test\\folder");	// tszFolderPathを"folder"のパスで初期化.
	TCHAR tszDrivePath[] = _T("C:");	// tszDrivePathを"C:"のパスで初期化.
	TCHAR tszDeviceName[] = _T("\\Device\\HarddiskVolume2\\Windows\\explorer.exe");	// tszDeviceNameを"explorer.exe"のデバイス名で初期化.

	// ファイル名のみ取得.
	PathStripPath(tszFilePath);	// PathStripPathでファイル名だけ残す.

	// 最下層のフォルダ名のみ取得.
	PathStripPath(tszFolderPath);	// PathStripPathで最下層のフォルダ名だけ残す.

	// ドライブのルートフォルダの場合.
	PathStripPath(tszDrivePath);	// PathStripPathでドライブ名などはそのまま.

	// デバイス名の場合.
	PathStripPath(tszDeviceName);	// tszDeviceNameでファイル名だけ残す.

	// 結果の出力.
	_tprintf(_T("tszFilePath = %s\n"), tszFilePath);	// tszFilePathの出力.
	_tprintf(_T("tszFolderPath = %s\n"), tszFolderPath);	// tszFolderPathの出力.
	_tprintf(_T("tszDrivePath = %s\n"), tszDrivePath);	// tszDrivePathの出力.
	_tprintf(_T("tszDeviceName = %s\n"), tszDeviceName);	// tszDeviceNameの出力.

	// プログラムの終了.
	return 0;

}