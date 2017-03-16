// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <string.h>		// 文字列処理

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言
	HANDLE hPipe1[2];	// 親から子へのパイプ.(hPipe1[0]は使わない.)
	HANDLE hPipe2[2];	// 子から親へのパイプ.(hPipe2[1]は使わない.)
	HANDLE hChildRead;	// 子が親からの読み込みに使うパイプ.
	HANDLE hChildWrite;	// 子が親への書き込みに使うパイプ.

	// 親から子へのパイプを作成.
	if (!CreatePipe(&hPipe1[0], &hPipe1[1], NULL, 0)){	// CreatePipeで親から子へのパイプ作成.(いったん継承不可のパイプを作成.)

		// perrorでエラー出力.
		_tperror(_T("CreatePipe(hPipe1)"));	// _tperrorで"CreatePipe(hPipe1)"とエラー出力.
		return -1;	// -1を返して終了.

	}

	// 子プロセスの読み込みハンドルの複製.
	if (!DuplicateHandle(GetCurrentProcess(), hPipe1[0], GetCurrentProcess(), &hChildRead, 0, TRUE, DUPLICATE_SAME_ACCESS)){	// DuplicateHandleでhPipe1[0]をhChildReadに複製.

		// perrorでエラー出力.
		_tperror(_T("DuplicateHandle(hChildRead)"));	// _tperrorで"DuplicateHandle(hChildRead)"と出力.
		CloseHandle(hPipe1[0]);	// hPipe1[0]を閉じる.
		CloseHandle(hPipe1[1]);	// hPipe1[1]を閉じる.
		return -2;	// -2を返して終了.

	}

	// 使わないハンドルを閉じる.
	CloseHandle(hPipe1[0]);	// hPipe1[0]を閉じる.

	// 子から親へのパイプを作成.
	if (!CreatePipe(&hPipe2[0], &hPipe2[1], NULL, 0)){	// CreatePipeで子から親へのパイプ作成.(いったん継承不可のパイプを作成.)

		// perrorでエラー出力.
		_tperror(_T("CreatePipe(hPipe2)"));	// _tperrorで"CreatePipe(hPipe2)"とエラー出力.
		CloseHandle(hPipe1[1]);	// hPipe1[1]を閉じる.
		CloseHandle(hChildRead);	// hChildReadを閉じる.
		return -3;	// -3を返して終了.

	}

	// 子プロセスの書き込みハンドルの複製.
	if (!DuplicateHandle(GetCurrentProcess(), hPipe2[1], GetCurrentProcess(), &hChildWrite, 0, TRUE, DUPLICATE_SAME_ACCESS)){	// DuplicateHandleでhPipe2[1]をhChildWriteに複製.

		// perrorでエラー出力.
		_tperror(_T("DuplicateHandle(hChildWrite)"));	// _tperrorで"DuplicateHandle(hChildWrite)"と出力.
		CloseHandle(hPipe2[0]);	// hPipe2[0]を閉じる.
		CloseHandle(hPipe2[1]);	// hPipe2[1]を閉じる.
		CloseHandle(hPipe1[1]);	// hPipe1[1]を閉じる.
		CloseHandle(hChildRead);	// hChildReadを閉じる.
		return -4;	// -4を返して終了.

	}

	// 使わないハンドルを閉じる.
	CloseHandle(hPipe2[1]);	// hPipe2[1]を閉じる.

	// プロセスの生成.
	STARTUPINFO si;	// STARTUPINFO型si.
	TCHAR command[1024];
	_tcscpy(command, _T("ChildProcess.exe"));	// commandに"ChildProcess.exe"をコピー.
	ZeroMemory(&si, sizeof(si));	// siをZeroMemoryで初期化.
	si.cb = sizeof(STARTUPINFO);	// STARTUPINFOのサイズ.
	si.dwFlags = STARTF_USESTDHANDLES;	// 標準入出力のリダイレクト.
	si.hStdInput = hChildRead;		// 子プロセスの入力はhChildRead.
	si.hStdOutput = hChildWrite;	// 子プロセスの出力はhChildWrite.
	si.hStdError = GetStdHandle(STD_ERROR_HANDLE);	// 子プロセスのエラー出力はGetStdHandleで取得した標準エラー出力.
	PROCESS_INFORMATION pi;	// PROCESS_INFORMATION型pi.
	ZeroMemory(&pi, sizeof(pi));	// piをZeroMemoryで初期化.
	if (!CreateProcess(NULL, command, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi)){

		// すべてのパイプを閉じる.
		CloseHandle(hPipe1[1]);		// hPipe1[1]を閉じる.
		CloseHandle(hPipe2[0]);		// hPipe2[0]を閉じる.
		CloseHandle(hChildRead);	// hChildReadを閉じる.
		CloseHandle(hChildWrite);	// hChildWriteを閉じる.
		return -5;	// -5を返して終了.

	}
	CloseHandle(pi.hThread);	// pi.hThreadを閉じる.
	CloseHandle(hChildRead);	// 親側では使わないので閉じる.
	CloseHandle(hChildWrite);	// 親側では使わないので閉じる.

	// 3秒待つ.
	Sleep(3000);	// 3秒休止.

	// 子プロセスへの書き込み.
	TCHAR tmsg[512];	// TCHAR型配列tmsg.
	TCHAR outtmsg[512];	// TCHAR型配列outtmsg.
	char msg[1024];		// char型配列msg.
	_tcscpy(tmsg, _T("I am Parent!"));	// tmsgに"I am Parent!"をコピー.
	_stprintf(outtmsg, _T("Parent: %s"), tmsg);	// 前に"Parent: "とつけてouttmsgに.
	_tperror(outtmsg);	// outtmsgを出力.
	DWORD len = WideCharToMultiByte(CP_ACP, 0, tmsg, -1, NULL, 0, NULL, NULL);	// マルチバイトに変換するためのサイズを取得.
	WideCharToMultiByte(CP_ACP, 0, tmsg, -1, msg, len, NULL, NULL);	// マルチバイトに変換.
	DWORD written = 0;	// 実際の書き込みバイト数wrttenを0に初期化.
	if (!WriteFile(hPipe1[1], msg, (DWORD)strlen(msg), &written, NULL)){

		// すべてのパイプを閉じる.
		CloseHandle(hPipe1[1]);		// hPipe1[1]を閉じる.
		CloseHandle(hPipe2[0]);		// hPipe2[0]を閉じる.
		return -6;	// -6を返して終了.

	}

	// 親から子への書き込みだけ閉じる.
	CloseHandle(hPipe1[1]);		// hPipe1[1]を閉じる.

	// 9秒待つ.
	Sleep(9000);	// 9秒休止.

	// 子プロセスからの読み込み.
	TCHAR tbuf[512];	// TCHAR型配列tbuf.
	TCHAR outtbuf[512];	// TCHAR型配列outtbuf.
	char buf[1024] = {0};	// char型配列bufを0で初期化..
	DWORD read = 0;	// 実際の読み込みバイト数readを0に初期化.
	if (!ReadFile(hPipe2[0], buf, 1024, &read, NULL)){

		// すべてのパイプを閉じる.
		CloseHandle(hPipe2[0]);	// hPipe2[0]を閉じる.
		return -7;	// -7を返して終了.

	}
	DWORD len2 = MultiByteToWideChar(CP_ACP, 0, buf, -1, NULL, 0);	// ワイド文字に変換するためのサイズ取得.
	MultiByteToWideChar(CP_ACP, 0, buf, -1, tbuf, len2);	// ワイド文字に変換.
	_stprintf(outtbuf, _T("Parent: %s"), tbuf);	// 前に"Parent: "とつけてouttbufに.
	_tperror(outtbuf);	// 読み込んだ文字列を出力. 

	// 子から親への読み込みだけ閉じる.
	CloseHandle(hPipe2[0]);		// hPipe2[0]を閉じる.

	// プログラムの終了
	return 0;

}