// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言
	HANDLE hFile;	// HANDLE型ファイルハンドルhFile
	DWORD dwSize;	// DWORD型ファイルサイズdwSize

	// ファイルを開く
	hFile = CreateFile(_T("test.txt"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFileで"test.txt"を開いて, 取得したハンドルをhFileに格納.
	if (hFile == INVALID_HANDLE_VALUE){	// hFileがINVALID_HANDLE_VALUEなら.

		// エラー処理
		_tprintf(_T("CreateFile Error!\n"));	// _tprintfで"CreateFile Error!"と出力.
		return -1;	// -1を返す.

	}

	// ファイルサイズの取得.
	dwSize = GetFileSize(hFile, NULL);	// GetFileSizeで"test.txt"のファイルサイズを取得する.

	// ファイルサイズの出力.
	_tprintf(_T("dwSize = %lu\n"), dwSize);	// _tprintfでdwSizeを出力.

	// 閉じる.
	CloseHandle(hFile);	// CloseHandleでhFileを閉じる.

	// プログラムの終了.
	return 0;

}