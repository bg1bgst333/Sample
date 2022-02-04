// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR対応
#include <stdio.h>		// C標準入出力

// スレッドの引数として渡す構造体THREAD_PARAMの定義.
typedef struct{
	int m_iNo;				// スレッド番号
}THREAD_PARAM;	// これでTHREAD_PARAM型の完成.

// ThreadProc関数の定義
DWORD WINAPI ThreadProc(LPVOID lpParameter){

	// 変数の宣言
	THREAD_PARAM *pTP;	// THREAD_PARAM型ポインタpTP.

	// 引数lpParameterをTHREAD_PARAM型のポインタにキャスト.
	pTP = (THREAD_PARAM *)lpParameter;	// lpParameterをTHREAD_ARG型のポインタにキャストして, pTPに格納.

	// "Thread Begin"
	_tprintf(_T("Thread Begin\n"));	// "Thread Begin"と出力.

	// ThreadProcの中でCOMの初期化.
	HRESULT hr = CoInitialize(NULL);	// CoInitializeでCOMを初期化し, 戻り値をhrに格納.
	if (hr == S_OK){	// S_OKなら初期化成功.
		_tprintf(_T("ThreadProc: CoInitialize success!\n"));	// "CoInitialize success!"と出力.
	}

	// 5秒休止.
	Sleep(5000);	// Sleepで5000ミリ秒休止.

	// COMの終了処理.
	CoUninitialize();	// CoUninitializeで終了処理.

	// "Thread End"
	_tprintf(_T("Thread End\n"));	// "Thread End"と出力.

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

	// COMの初期化.
	HRESULT hr = CoInitialize(NULL);	// CoInitializeでCOMを初期化し, 戻り値をhrに格納.
	if (hr == S_OK){	// S_OKなら初期化成功.
		_tprintf(_T("CoInitialize success!\n"));	// "CoInitialize success!"と出力.
	}

	// 2回目のCOMの初期化.
	HRESULT hr2 = CoInitialize(NULL);	// CoInitializeでCOMを初期化し, 戻り値をhr2に格納.
	if (hr2 == S_FALSE){	// S_FALSEならすでに初期化されている.
		_tprintf(_T("Already initialized!\n"));	// "Already initialized!"と出力.
	}

	// スレッドの開始
	tp.m_iNo = 0;	// m_iNo = 0
	hThread = CreateThread(NULL, 0, ThreadProc, &tp, 0, &dwThreadId);	// CreateThreadでスレッド生成及び開始.(引数にtpを渡している.)

	// シグナル状態になるまで待機.
	WaitForSingleObject(hThread, INFINITE);	// WaitForSingleObjectでhThreadがシグナル状態になるまで待機.

	// 終了コードの取得.
	GetExitCodeThread(hThread, &dwExitCode);	// GetExitCodeThreadでスレッドの終了コードを取得.
	_tprintf(_T("dwExitCode = %lu\n"), dwExitCode);	// dwExitCodeの値を出力.
	if (hThread != NULL){	// hThreadがNULLでない.
		CloseHandle(hThread);	// CloseHandleでhThreadを閉じる.
	}

	// COMの終了処理.
	CoUninitialize();	// CoUninitializeで終了処理.

	// プログラムの終了.
	return 0;	// 0を返して終了.

}