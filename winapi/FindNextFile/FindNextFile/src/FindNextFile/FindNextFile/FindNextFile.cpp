// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言
	HANDLE hFind;			// 検索ハンドルhFind.
	WIN32_FIND_DATA wfd;	// ファイル検索情報wfd.

	// "test"フォルダ以下のファイルの中から最初に見つかったファイルの情報を取得.
	hFind = FindFirstFile(_T("test\\*"), &wfd);	// FindFirstFileで"test"フォルダ以下のファイルを探し, 最初に見つかったファイル情報をwfdに格納.
	if (hFind == INVALID_HANDLE_VALUE){	// INVALID_HANDLE_VALUEなら失敗.

		// エラー処理.
		_tprintf(_T("FindFirstFile Error!\n"));	// _tprintfで"FindFirstFile Error!"と出力.
		return -1;	// -1を返す.

	}

	// do-while文とFindNextFileで2つ目以降も探す.
	do{	// doブロック

		// 見つかったファイルのファイル名を出力.
		_tprintf(_T("wfd.cFileName = %s\n"), wfd.cFileName);	// 見つかったファイルのファイル名wfd.cFileNameを出力.

	} while(FindNextFile(hFind, &wfd));	// FindNextFileで戻り値が真なら次のファイルも見つかったということなので繰り返す.

	// ハンドルを閉じる.
	FindClose(hFind);	// FindCloseでhFindを閉じる.

	// プログラムの終了.
	return 0;

}