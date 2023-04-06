// ヘッダファイルのインクルード
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <windows.h>	// 標準WindowsAPI

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// ポインタの宣言.
	WCHAR *pwszGuidStr1;	// GUID文字列を指すWCHARポインタpwszGuidStr1.

	// ボリュームデバイスインターフェースクラスGUIDを文字列に変換.
	StringFromCLSID(GUID_DEVINTERFACE_VOLUME, &pwszGuidStr1);	// StringFromCLSIDでGUID_DEVINTERFACE_VOLUMEをGUID文字列に変換.

	// GUID文字列の出力.
	_tprintf(_T("%s\n"), pwszGuidStr1);	// pwszGuidStr1を出力.

	// pwszGuidStr1の解放.
	CoTaskMemFree(pwszGuidStr1);	// CoTaskMemFreeで解放.

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}