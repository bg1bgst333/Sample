// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言
	HANDLE hFile;		// HANDLE型ファイルハンドルhFile
	BYTE btBuf[128];	// BYTE型配列btBuf(長さ128)
	DWORD dwReadBytes;	// DWORD型読み込んだバイト数dwReadBytes.

	// ファイルを開く
	hFile = CreateFile(_T("test.txt"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFileで"test.txt"を開いて, 取得したハンドルをhFileに格納.
	if (hFile == INVALID_HANDLE_VALUE){	// hFileがINVALID_HANDLE_VALUEなら.

		// エラー処理
		_tprintf(_T("CreateFile Error!\n"));	// _tprintfで"CreateFile Error!"と出力.
		return -1;	// -1を返す.

	}

	// ファイルの内容を読み込む.
	ReadFile(hFile, btBuf, 128, &dwReadBytes, NULL);	// ReadFileでhFileの内容をbtBufに読み込む.
	btBuf[dwReadBytes] = 0x0;	// 末尾を'\0'( = 0x0)で埋める.

	// btBufを出力.
	printf("btBuf = %s\n", btBuf);	// printfでbtBufの内容を出力.

	// 閉じる.
	CloseHandle(hFile);	// CloseHandleでhFileを閉じる.

	// プログラムの終了.
	return 0;

}