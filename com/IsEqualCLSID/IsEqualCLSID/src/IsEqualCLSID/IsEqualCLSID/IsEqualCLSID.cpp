// ヘッダファイルのインクルード
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <windows.h>	// 標準WindowsAPI

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// GUID文字列をGUIDに変換.
	GUID guid1 = {0};	// GUID構造体guid1を{0}で初期化.
	WCHAR wszBuf[39] = L"{53F56307-B6BF-11D0-94F2-00A0C91EFB8B}";	// WCHAR配列wszBuf(長さ39)を"{53F56307-B6BF-11D0-94F2-00A0C91EFB8B}"で初期化.
	CLSIDFromString(wszBuf, &guid1);	// CLSIDFromStringで文字列からGUIDに変換.

	// GUIDとGUIDが同じか判定.
	int iRet = IsEqualCLSID(guid1, GUID_DEVINTERFACE_DISK);	// IsEqualCLSIDでGUID_DEVINTERFACE_DISKと同じか判定.
	if (iRet){	// TRUE
		_tprintf(_T("guid1 is GUID_DEVINTERFACE_DISK.\n"));	// "guid1 is GUID_DEVINTERFACE_DISK."と出力.
	}
	else{
		_tprintf(_T("guid1 is not GUID_DEVINTERFACE_DISK.\n"));	// "guid1 is not GUID_DEVINTERFACE_DISK."と出力.
	}

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}