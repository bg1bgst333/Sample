// ヘッダファイルのインクルード
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <windows.h>	// 標準WindowsAPI

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 構造体・配列の宣言・初期化
	GUID guid1;	// GUID構造体変数guid1.
	WCHAR wszGuidStr1[39] = {0};	// GUID文字列を格納するWCHAR文字配列wszGuidStr1(長さ39)を{0}で初期化.

	// 値のセット.
	guid1.Data1 = 0x11111111;	// guid1.Data1に0x11111111をセット.
	guid1.Data2 = 0x2222;	// guid1.Data2に0x2222をセット.
	guid1.Data3 = 0x3333;	// guid1.Data3に0x3333をセット.
	guid1.Data4[0] = 0x44;	// guid1.Data4[0]に0x44をセット.
	guid1.Data4[1] = 0x55;	// guid1.Data4[1]に0x55をセット.
	guid1.Data4[2] = 0x66;	// guid1.Data4[2]に0x66をセット.
	guid1.Data4[3] = 0x66;	// guid1.Data4[3]に0x66をセット.
	guid1.Data4[4] = 0x66;	// guid1.Data4[4]に0x66をセット.
	guid1.Data4[5] = 0x66;	// guid1.Data4[5]に0x66をセット.
	guid1.Data4[6] = 0x66;	// guid1.Data4[6]に0x66をセット.
	guid1.Data4[7] = 0x66;	// guid1.Data4[7]に0x66をセット.

	// GUID文字列への変換.
	StringFromGUID2(guid1, wszGuidStr1, 39);	// StringFromGUID2でGUIDを文字列に変換.

	// GUID文字列の出力.
	_tprintf(_T("%s\n"), wszGuidStr1);	// wszGuidStr1を出力.

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}