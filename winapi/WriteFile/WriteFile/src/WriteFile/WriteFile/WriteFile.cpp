// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言
	HANDLE hFile;			// HANDLE型ファイルハンドルhFile
	DWORD dwWrittenBytes;	// DWORD型書きこんだバイト数dwWrittenBytes.

	// ファイルを開く
	hFile = CreateFile(_T("test.txt"), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFileで"test.txt"を書込みモード(GENERIC_WRITE)開いて, 取得したハンドルをhFileに格納.
	if (hFile == INVALID_HANDLE_VALUE){	// hFileがINVALID_HANDLE_VALUEなら.

		// エラー処理
		_tprintf(_T("CreateFile Error!\n"));	// _tprintfで"CreateFile Error!"と出力.
		return -1;	// -1を返す.

	}

	// ファイルの内容を読み込む.
	WriteFile(hFile, "ABCDE", 5, &dwWrittenBytes, NULL);	// WriteFileでhFileに"ABCDE"を書きこむ.

	// 閉じる.
	CloseHandle(hFile);	// CloseHandleでhFileを閉じる.

	// プログラムの終了.
	return 0;

}