// ヘッダファイルのインクルード
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <windows.h>	// 標準WindowsAPI

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 構造体の宣言
	GUID guid1;	// GUID構造体変数guid1.

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

	// GUID文字列の出力.
	_tprintf(_T("{%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x}\n"), guid1.Data1, guid1.Data2, guid1.Data3, guid1.Data4[0], guid1.Data4[1], guid1.Data4[2], guid1.Data4[3], guid1.Data4[4], guid1.Data4[5], guid1.Data4[6], guid1.Data4[7]);	// guid1をGUID文字列の書式で出力.

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}