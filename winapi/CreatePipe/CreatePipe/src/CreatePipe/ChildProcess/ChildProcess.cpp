// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <string.h>		// 文字列処理

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 6秒待つ.
	Sleep(6000);	// 6秒休止.

	// 標準入力を読み込む.
	char buf[1024] = {0};		// char型bufを0で初期化.
	TCHAR tbuf[512] = {0};		// TCHAR型tbufを0で初期化.
	TCHAR outtbuf[512] = {0};	// TCHAR型outtbufを0で初期化.
	fgets(buf, 1024, stdin);	// fgetsで標準入力から読み込む.
	DWORD len = MultiByteToWideChar(CP_ACP, 0, buf, -1, NULL, 0);	// ワイド文字に変換するためのサイズ取得.
	MultiByteToWideChar(CP_ACP, 0, buf, -1, tbuf, len);	// ワイド文字に変換.
	_stprintf(outtbuf, _T("Child: %s"), tbuf);	// 前に"Child: "とつけてouttbufに.
	_tperror(outtbuf);	// 読み込んだ文字列を出力. 

	// 3秒待つ.
	Sleep(3000);	//3秒休止.

	// 標準出力で書き込む.
	TCHAR tmsg[512] = {0};	// TCHAR型配列tmsg.
	TCHAR outtmsg[512] = {0};	// TCHAR型配列outtmsg.
	char msg[1024] = {0};		// char型配列msg.
	_tcscpy(tmsg, _T("I am Child!"));	// tmsgに"I am Parent!"をコピー.
	_stprintf(outtmsg, _T("Child: %s"), tmsg);	// 前に"Child: "とつけてouttmsgに.
	_tperror(outtmsg);	// outtmsgを出力.
	DWORD len2 = WideCharToMultiByte(CP_ACP, 0, tmsg, -1, NULL, 0, NULL, NULL);	// マルチバイトに変換するためのサイズを取得.
	WideCharToMultiByte(CP_ACP, 0, tmsg, -1, msg, len, NULL, NULL);	// マルチバイトに変換.
	fputs(msg, stdout);	// fputsで標準出力に書き込み.

	// プログラムの終了
	return 0;

}