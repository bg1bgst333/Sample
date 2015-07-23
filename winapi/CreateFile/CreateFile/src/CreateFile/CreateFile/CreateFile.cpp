// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言
	HANDLE hFile;			// HANDLE型ファイルハンドルhFile

	// ファイルを開く
	hFile = CreateFile(_T("test.txt"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFileで"test.txt"を開いて, 取得したハンドルをhFileに格納.
	if (hFile == INVALID_HANDLE_VALUE){	// hFileがINVALID_HANDLE_VALUEなら.

		// エラー処理
		_tprintf(_T("CreateFile Error!\n"));	// _tprintfで"CreateFile Error!"と出力.
		return -1;	// -1を返す.

	}

	// hFileの値を出力.
	_tprintf(_T("hFile = 0x%08x\n"), hFile);	// _tprintfでhFileの値を出力.

	// 閉じる.
	CloseHandle(hFile);	// CloseHandleでhFileを閉じる.

	// プログラムの終了.
	return 0;

}