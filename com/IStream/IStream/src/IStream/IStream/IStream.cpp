// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR対応
#include <stdio.h>		// C標準入出力
#include <string.h>		// C文字列処理
#include <shlwapi.h>	// シェルAPI
#include <shobjidl.h>	// シェルオブジェクトIDL

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// COMの初期化.
	CoInitialize(NULL);	// CoInitializeでCOMを初期化.

	// 変数の宣言と初期化.
	TCHAR tszPath[MAX_PATH] = {0};	// tszPath(長さMAX_PATH)を{0}で初期化.
	HANDLE hFile;	// ファイルハンドルhFile
	DWORD dwFileSize;	// ファイルサイズhFileSize
	HGLOBAL hGlobal;	// グローバルハンドルhGlobal
	LPVOID lpBuf;	// バッファポインタlpBuf
	IStream *pStream;	// IStreamポインタpStream

	// 実行ファイルがあるフォルダのパスを取得.
	GetModuleFileName(NULL, tszPath, MAX_PATH);	// GetModuleFileNameでこの実行ファイルのフルパスを取得.
	PathRemoveFileSpec(tszPath);	// PathRemoveFileSpecでファイル名の部分を取り除く.

	// ファイルの実体は上記パスの下の"test.txt".
	_tcscat(tszPath, _T("\\test.txt"));	// 上記パスに"\test.txt"を連結.

	// 実体パスを出力.
	_tprintf(_T("tszPath = %s\n"), tszPath);	// tszPathを出力.

	// 画像ファイルを開く.
	hFile = CreateFile(tszPath, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);	// "test.txt"を開く.

	// ファイルサイズを取得.
	dwFileSize = GetFileSize(hFile, NULL);	// GetFileSizeでファイルサイズを取得.

	// メモリ確保.
	hGlobal = GlobalAlloc(GMEM_MOVEABLE, dwFileSize);	// dwFileSize分メモリ確保.

	// ロック.
	lpBuf = GlobalLock(hGlobal);	// ロックしてポインタ取得.

	// 読み込み.
	ReadFile(hFile, lpBuf, dwFileSize, &dwFileSize, NULL);	// ReadFileで読み込み.

	// 閉じる.
	CloseHandle(hFile);	// ファイルハンドルを閉じる.

	// アンロック
	GlobalUnlock(hGlobal);	// アンロック.

	// グローバルメモリからIStreamを作成.
	HRESULT hr = CreateStreamOnHGlobal(hGlobal, TRUE, &pStream);	// CreateStreamOnHGlobalでpStreamにIStreamポインタが格納される.
	if (SUCCEEDED(hr)){
		
		// pStream->Statでストリーム情報を取得.
		STATSTG statstg = {0};	// statstgを{0}で初期化.
		pStream->Stat(&statstg, 0);	// pStream->Statでストリーム情報をstatstgに格納.
		_tprintf(_T("statstg.cbSize = %d\n"), statstg.cbSize);	// ストリームサイズstatstg.cbSizeを出力.

		// 解放.
		pStream->Release();	// IStreamオブジェクトポインタを解放.

	}

	// 解放.
	GlobalFree(hGlobal);	// 解放.

	// COMの終了処理.
	CoUninitialize();	// CoUninitializeで終了処理.

	// プログラムの終了.
	return 0;	// 0を返して終了.

}