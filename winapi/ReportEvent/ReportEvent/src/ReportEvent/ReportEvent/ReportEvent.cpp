// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <string.h>		// 文字列処理

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣
	HANDLE hEventLog;		// イベントログ操作に必要なハンドルHANDLE型hEventLog.
	TCHAR *ptszText;		// イベントログ文字列を格納するTCHAR *型バッファポインタptszText.
	
	// ログ文字列のセット.
	ptszText = new TCHAR[1024];	// TCHAR型動的配列(長さ1024)を確保.
	_tcscpy(ptszText, _T("Test EventLog Message"));	// ptszTextに"Test EventLog Message"をセット.

	// イベントソースの登録.
	hEventLog = RegisterEventSource(NULL, _T("ReportEvent"));	// RegisterEventSourceでイベントソース"ReportEvent"を登録し, hEventLogを取得.
	if (hEventLog == NULL){	// 登録失敗.

		// エラーメッセージ出力.
		_tprintf(_T("Error!\n"));	// "Error!"と出力.
		delete[] ptszText;	// ptszTextを解放.
		return -1;	// -1を返して終了.

	}

	// イベントログを書き込む.
	ReportEvent(hEventLog, EVENTLOG_INFORMATION_TYPE, 100, 1001, NULL, 1, 0, (LPCTSTR *)&ptszText, NULL);	// ReportEventでhEventLogにイベントログを書き込む.

	// イベントログのハンドルを閉じる.
	DeregisterEventSource(hEventLog);	// DeregisterEventSourceでhEventLogを閉じる.
	delete[] ptszText;	// ptszTextを解放.

	// プログラムの終了
	return 0;	// 0を返して終了.

}