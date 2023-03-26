// ヘッダファイルのインクルード
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <windows.h>	// 標準WindowsAPI

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言
	DWORD d;	// 有効なドライブを示すビットは1が立っているDWORD型ビットマスクd.
	DWORD i;	// ループDWORD型変数i.

	// 有効なドライブ一覧を取得.
	d = GetLogicalDrives();	// GetLogicalDrivesでビットマスクdを取得.

	// ドライブレターの数の分だけ繰り返す.
	for (i = 0; i < 26; i++){	// ドライブレターは'A'から'Z'の26個.
		if (d & (1 << i)){	// i == 0番目が1なら'A'ドライブが有効, i == 1番目が1なら'B'ドライブが有効, ...と続いてく.
			_tprintf(_T("%c:\n"), 'A' + i);	// 有効なドライブレターを出力.
		}
	}

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}