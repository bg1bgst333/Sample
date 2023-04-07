// ヘッダファイルのインクルード
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <string.h>		// 文字列処理
#include <windows.h>	// 標準WindowsAPI

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// ポインタ・配列の宣言・初期化.
	WCHAR *pwszGuidStr1;	// GUID文字列を指すWCHARポインタpwszGuidStr1.
	WCHAR wszBuf[39] = {0};	// WCHAR配列wszBuf(長さ39)を{0}で初期化.

	// ボリュームデバイスインターフェースクラスGUIDを文字列に変換.
	StringFromCLSID(GUID_DEVINTERFACE_VOLUME, &pwszGuidStr1);	// StringFromCLSIDでGUID_DEVINTERFACE_VOLUMEをGUID文字列に変換.

	// GUID文字列の出力.
	_tprintf(_T("%s\n"), pwszGuidStr1);	// pwszGuidStr1を出力.

	// バッファにコピー.
	_tcscpy(wszBuf, pwszGuidStr1);	// pwszGuidStr1をwszBufにコピー.

	// pwszGuidStr1の解放.
	CoTaskMemFree(pwszGuidStr1);	// CoTaskMemFreeで解放.

	// GUID文字列をGUIDに変換.
	GUID guid2 = {0};	// GUID構造体guid2を{0}で初期化.
	CLSIDFromString(wszBuf, &guid2);	// CLSIDFromStringで文字列からGUIDに変換.

	// GUID文字列の出力.
	_tprintf(_T("{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}\n"), guid2.Data1, guid2.Data2, guid2.Data3, guid2.Data4[0], guid2.Data4[1], guid2.Data4[2], guid2.Data4[3], guid2.Data4[4], guid2.Data4[5], guid2.Data4[6], guid2.Data4[7]);	// guid2をGUID文字列の書式で出力.

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}