// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言
	HFILE hFile;			// HFILE型ファイルハンドルhFile
	OFSTRUCT ofst = {0};	// OFSTRUCT構造体ofstを0で初期化.

	// ファイルを開く
	hFile = OpenFile("test.txt", &ofst, OF_READ);	// OpenFileで"test.txt"を開いて, 取得したファイルハンドルをhFileに格納.
	if (hFile == HFILE_ERROR){	// HFILE_ERRORなら.

		// エラー処理
		_tprintf(_T("OpenFile Error!\n"));	// _tprintfで"OpenFile Error!"と出力.
		return -1;	// -1を返す.

	}

	// hFileの値を出力.
	_tprintf(_T("hFile = 0x%08x\n"), hFile);	// _tprintfでhFileの値を出力.

	// 閉じる.
	CloseHandle((HANDLE)hFile);	// CloseHandleでhFileを閉じる.

	// プログラムの終了.
	return 0;

}