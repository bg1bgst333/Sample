// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の初期化.
	HANDLE hNamedPipe;	// 名前付きパイプハンドルHANDLE型hNamedPipe.
	TCHAR tszBuf[1024];	// バッファTCHAR型配列tszBuf(長さ1024)

	// 名前付きパイプの作成.
	hNamedPipe = CreateNamedPipe(_T("\\\\.\\pipe\\TEST"), PIPE_ACCESS_DUPLEX, PIPE_TYPE_BYTE, 1, 0, 0, 3000, NULL);	//  CreateNamedPipeで名前付きパイプ"\\.\pipe\TEST"を作成し, hNamedPipeに格納.
	if (hNamedPipe == INVALID_HANDLE_VALUE){	// パイプ作成に失敗なら.

		// エラーの出力.
		_tperror(_T("Error: CreateNamedPipe!"));	// _tperrorで"Error: CreateNamedPipe!"と出力.
		return -1;	// -1を返して終了.

	}

	// 名前付きパイプに接続.
	if (!ConnectNamedPipe(hNamedPipe, NULL)){	// ConnectNamedPipeでhNamedPipeに接続し, 失敗なら.

		// エラーの出力.
		_tperror(_T("Error: ConnectNamedPipe!"));	// _tperrorで"Error: ConnectNamedPipe!"と出力.
		CloseHandle(hNamedPipe);	// hNamedPipeを閉じる.
		return -2;	// -2を返して終了.

	}

	// 3秒待つ.
	Sleep(3000);	// 3秒休止.

	// hNamedPipeに書き込み.
	char szBuf[1024] = {0};	// char型バッファszBufを0で初期化.
	_tcscpy(tszBuf, _T("I am Parent!"));	// tszBufに"I am Parent!"をセット.
	DWORD len = WideCharToMultiByte(CP_ACP, 0, tszBuf, -1, NULL, 0, NULL, NULL);	// マルチバイトに変換するためのサイズを取得.
	WideCharToMultiByte(CP_ACP, 0, tszBuf, -1, szBuf, len, NULL, NULL);	// マルチバイトに変換.
	DWORD written = 0;
	_tprintf(_T("Parent: %s\n"), tszBuf);	// tszBufを出力.
	if (!WriteFile(hNamedPipe, szBuf, (DWORD)strlen(szBuf), &written, NULL)){	// WriteFileでszBufをhNamedPipeに書き込み, 失敗なら.

		// エラーの出力.
		_tperror(_T("Error: WriteFile!"));	// _tperrorで"Error: WriteFile!"と出力.
		CloseHandle(hNamedPipe);	// hNamedPipeを閉じる.
		return -3;	// -3を返して終了.

	}

	// 9秒待つ.
	Sleep(9000);	// 9秒休止.

	// hNamedPipeから読み込み.
	char szBuf2[1024] = {0};	// char型バッファszBuf2を0で初期化.
	DWORD read = 0;
	if (!ReadFile(hNamedPipe, szBuf2, 1024, &read, NULL)){	// ReadFileでszBuf2にhNamedPipeから読み込んだ内容を格納し, 失敗なら.

		// エラーの出力.
		_tperror(_T("Error: ReadFile!"));	// _tperrorで"Error: ReadFile!"と出力.
		CloseHandle(hNamedPipe);	// hNamedPipeを閉じる.
		return -4;	// -4を返して終了.

	}
	TCHAR tszBuf2[1024] = {0};	// TCHAR型tszBuf2を0で初期化.
	DWORD len2 = MultiByteToWideChar(CP_ACP, 0, szBuf2, -1, NULL, 0);	// ワイド文字に変換するためのサイズ取得.
	MultiByteToWideChar(CP_ACP, 0, szBuf2, -1, tszBuf2, len2);	// ワイド文字に変換.
	_tprintf(_T("Parent: %s\n"), tszBuf2);	// tszBuf2を出力.

	// 終了処理.
	FlushFileBuffers(hNamedPipe);	// FlushFileBuffersでバッファをフラッシュ.
	DisconnectNamedPipe(hNamedPipe);	// DisconnectNamedPipeでパイプとの通信を切断.
	CloseHandle(hNamedPipe);	// hNamePipeを閉じる.

	// プログラムの終了
	return 0;

}