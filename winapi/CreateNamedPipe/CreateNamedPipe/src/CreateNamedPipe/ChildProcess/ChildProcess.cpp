// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言
	HANDLE hNamedPipe;	// 名前付きパイプハンドルHANDLE型hNamedPipe.

	// 名前付きパイプを開く.
	hNamedPipe = CreateFile(_T("\\\\.\\pipe\\TEST"), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);	// CreateFileで"\\.\pipe\TEST"を開いて, hNamedPipeに格納.
	if (hNamedPipe == INVALID_HANDLE_VALUE){	// パイプ作成に失敗なら.

		// エラーの出力.
		_tperror(_T("Error: CreateFile!"));	// _tperrorで"Error: CreateFile!"と出力.
		return -1;	// -1を返して終了.

	}

	// 6秒待つ.
	Sleep(6000);	// 6秒休止.

	// hNamedPipeから読み込み.
	char szBuf[1024] = {0};	// char型バッファszBufを0で初期化.
	DWORD read = 0;
	if (!ReadFile(hNamedPipe, szBuf, 1024, &read, NULL)){	// ReadFileでszBufにhNamedPipeから読み込んだ内容を格納し, 失敗なら.

		// エラーの出力.
		_tperror(_T("Error: ReadFile!"));	// _tperrorで"Error: ReadFile!"と出力.
		CloseHandle(hNamedPipe);	// hNamedPipeを閉じる.
		return -2;	// -2を返して終了.

	}
	TCHAR tszBuf[1024] = {0};	// TCHAR型tszBufを0で初期化.
	DWORD len = MultiByteToWideChar(CP_ACP, 0, szBuf, -1, NULL, 0);	// ワイド文字に変換するためのサイズ取得.
	MultiByteToWideChar(CP_ACP, 0, szBuf, -1, tszBuf, len);	// ワイド文字に変換.
	_tprintf(_T("Child: %s\n"), tszBuf);	// tszBufを出力.

	// 3秒待つ.
	Sleep(3000);	// 3秒休止.

	// hNamedPipeに書き込み.
	TCHAR tszBuf2[1024] = {0};	// バッファTCHAR型配列tszBuf2(長さ1024)を0に初期化.
	char szBuf2[1024] = {0};	// char型バッファszBuf2を0で初期化.
	_tcscpy(tszBuf2, _T("I am Child!"));	// tszBuf2に"I am Child!"をセット.
	DWORD len2 = WideCharToMultiByte(CP_ACP, 0, tszBuf2, -1, NULL, 0, NULL, NULL);	// マルチバイトに変換するためのサイズを取得.
	WideCharToMultiByte(CP_ACP, 0, tszBuf2, -1, szBuf2, len2, NULL, NULL);	// マルチバイトに変換.
	DWORD written = 0;
	_tprintf(_T("Child: %s\n"), tszBuf2);	// tszBufを出力.
	if (!WriteFile(hNamedPipe, szBuf2, (DWORD)strlen(szBuf2), &written, NULL)){	// WriteFileでszBuf2をhNamedPipeに書き込み, 失敗なら.

		// エラーの出力.
		_tperror(_T("Error: WriteFile!"));	// _tperrorで"Error: WriteFile!"と出力.
		CloseHandle(hNamedPipe);	// hNamedPipeを閉じる.
		return -3;	// -3を返して終了.

	}

	// 終了処理.
	CloseHandle(hNamedPipe);	// hNamePipeを閉じる.

	// プログラムの終了
	return 0;

}