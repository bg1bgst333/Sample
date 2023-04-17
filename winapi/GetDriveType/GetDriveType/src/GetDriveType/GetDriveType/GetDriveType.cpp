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

	// ドライブタイプの取得.
	TCHAR tszRootPathName[MAX_PATH] = {0};	// ドライブのルートパスtszRootPathName(長さMAX_PATH)を{0}で初期化.
	_tcscat(tszRootPathName, argv[1]);		// tszRootPathNameにargv[1]を連結.
	_tcscat(tszRootPathName, _T(":\\"));	// ":\\"(表示時は":\".)を連結.
	DWORD dwRet = GetDriveType(tszRootPathName);	// GetDriveTypeでドライブタイプ取得.
	if (dwRet == DRIVE_UNKNOWN){	// 不明.
		_tprintf(_T("DRIVE_UNKNOWN\n"));	// "DRIVE_UNKNOWN"を出力.
	}
	else if (dwRet == DRIVE_NO_ROOT_DIR){	// ルートディレクトリではない.
		_tprintf(_T("DRIVE_NO_ROOT_DIR\n"));	// "DRIVE_NO_ROOT_DIR"を出力.
	}
	else if (dwRet == DRIVE_REMOVABLE){	// リムーバブル.
		_tprintf(_T("DRIVE_REMOVABLE\n"));	// "DRIVE_REMOVABLE"を出力.
	}
	else if (dwRet == DRIVE_FIXED){	// 固定.
		_tprintf(_T("DRIVE_FIXED\n"));	// "DRIVE_FIXED"を出力.
	}
	else if (dwRet == DRIVE_REMOTE){	// リモート.
		_tprintf(_T("DRIVE_REMOTE\n"));	// "DRIVE_REMOTE"を出力.
	}
	else if (dwRet == DRIVE_CDROM){	// CD-ROM.
		_tprintf(_T("DRIVE_CDROM\n"));	// "DRIVE_CDROM"を出力.
	}
	else if (dwRet == DRIVE_RAMDISK){	// RAMディスク.
		_tprintf(_T("DRIVE_RAMDISK\n"));	// "DRIVE_RAMDISK"を出力.
	}

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}