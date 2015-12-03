// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力

// スレッドの引数として渡す構造体THREAD_PARAMの定義.
typedef struct{
	int m_iNo;				// スレッド番号
	TCHAR m_tszMessage[32];	// スレッドが出力するメッセージ.
}THREAD_PARAM;	// これでTHREAD_PARAM型の完成.

// ThreadProc関数の定義
DWORD WINAPI ThreadProc(LPVOID lpParameter){

	// 変数の宣言
	int i;	// ループ用変数i
	THREAD_PARAM *pTP;	// THREAD_PARAM型ポインタpTP.

	// 引数lpParameterをTHREAD_PARAM型のポインタにキャスト.
	pTP = (THREAD_PARAM *)lpParameter;	// lpParameterをTHREAD_ARG型のポインタにキャストして, pTPに格納.

	// 1から5までを出力.
	for (i = 1; i <= 5; i++){	// 1から5まで5回繰り返す.

		// i, pTP->m_iNo, pTP->m_tszMessageを出力.
		_tprintf(_T("i = %d, m_iNo = %d, m_tszMessage = %s\n"), i, pTP->m_iNo, pTP->m_tszMessage);	// _tprintfでi, pTP->m_iNo, pTP->m_tszMessageの値を出力.
		Sleep(1000);	// Sleepで1秒休止.

	}

	// スレッドの終了
	ExitThread((DWORD)pTP->m_iNo);	// ExitThreadにpTP->m_iNoを(DWORD)にキャストしたものを渡してスレッドを終了する.

}

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言
	HANDLE hThread;		// HANDLE型スレッドハンドルhThread
	DWORD dwThreadId;	// DWORD型スレッドID dwThreadId
	THREAD_PARAM tp;	// 引数として渡すTHREAD_PARAM型tp
	DWORD dwExitCode;	// DWORD型終了コードdwExitCode

	// スレッドの開始
	tp.m_iNo = 0;	// m_iNo = 0
	_tcscpy(tp.m_tszMessage, _T("No.0"));	// m_tszMessage = "No.0"
	hThread = CreateThread(NULL, 0, ThreadProc, &tp, 0, &dwThreadId);	// CreateThreadでスレッド生成及び開始.(引数にtpを渡している.)

	// シグナル状態になるまで待機.
	WaitForSingleObject(hThread, INFINITE);	// WaitForSingleObjectでhThreadがシグナル状態になるまで待機.

	// 終了コードの取得.
	GetExitCodeThread(hThread, &dwExitCode);	// GetExitCodeThreadでスレッドの終了コードを取得.
	_tprintf(_T("dwExitCode = %lu\n"), dwExitCode);	// dwExitCodeの値を出力.
	if (hThread != NULL){	// hThreadがNULLでない.
		CloseHandle(hThread);	// CloseHandleでhThreadを閉じる.
	}

	// プログラムの終了
	return 0;

}