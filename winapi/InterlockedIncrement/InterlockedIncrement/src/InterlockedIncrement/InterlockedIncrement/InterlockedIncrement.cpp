// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力

// スレッドの引数として渡す構造体THREAD_PARAMの定義.
typedef struct{
	int m_iNo;				// スレッド番号
	TCHAR m_tszMessage[32];	// スレッドが出力するメッセージ.
}THREAD_PARAM;	// これでTHREAD_PARAM型の完成.

// モジュール変数の初期化.
LONG lCount = 0;	// LONG型カウント用変数lCountを0で初期化.

// ThreadProc関数の定義
DWORD WINAPI ThreadProc(LPVOID lpParameter){

	// 変数の宣言
	int i;	// ループ用変数i
	THREAD_PARAM *pTP;	// THREAD_PARAM型ポインタpTP.

	// 引数lpParameterをTHREAD_PARAM型のポインタにキャスト.
	pTP = (THREAD_PARAM *)lpParameter;	// lpParameterをTHREAD_ARG型のポインタにキャストして, pTPに格納.

	// 20回繰り返す.
	for (i = 1; i <= 20; i++){	// 1から20まで20回繰り返す.

		// インクリメント.
		InterlockedIncrement(&lCount);	// InterlockedIncrementでlCountをインクリメント.
		// lCount, pTP->m_iNo, pTP->m_tszMessageを出力.
		_tprintf(_T("lCount = %d, m_iNo = %d, m_tszMessage = %s\n"), lCount, pTP->m_iNo, pTP->m_tszMessage);	// _tprintfでlCount, pTP->m_iNo, pTP->m_tszMessageの値を出力.
		// 休止.
		Sleep(10);	// Sleepで10ミリ秒休止.

	}

	// スレッドの終了
	ExitThread((DWORD)pTP->m_iNo);	// ExitThreadにpTP->m_iNoを(DWORD)にキャストしたものを渡してスレッドを終了する.

}

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 配列の宣言
	HANDLE hThread[5];		// HANDLE型スレッドハンドル配列hThread(要素数5)
	DWORD dwThreadId[5];	// DWORD型スレッドID配列dwThreadId(要素数5)
	THREAD_PARAM tp[5];		// 引数として渡すTHREAD_PARAM型配列tp.(要素数5)
	int i;					// ループ用変数i.
	DWORD dwExitCode[5];	// DWORD型終了コード配列dwExitCode(要素数5)

	// スレッドの一斉開始
	tp[0].m_iNo = 0;	// m_iNo = 0
	_tcscpy(tp[0].m_tszMessage, _T("No.0"));	// m_tszMessage = "No.0"
	hThread[0] = CreateThread(NULL, 0, ThreadProc, &tp[0], 0, &dwThreadId[0]);	// CreateThreadでスレッド生成及び開始.(引数にtp[0]を渡している.)
	tp[1].m_iNo = 1;	// m_iNo = 1
	_tcscpy(tp[1].m_tszMessage, _T("No.1"));	// m_tszMessage = "No.1"
	hThread[1] = CreateThread(NULL, 0, ThreadProc, &tp[1], 0, &dwThreadId[1]);	// CreateThreadでスレッド生成及び開始.(引数にtp[1]を渡している.)
	tp[2].m_iNo = 2;	// m_iNo = 2
	_tcscpy(tp[2].m_tszMessage, _T("No.2"));	// m_tszMessage = "No.2"
	hThread[2] = CreateThread(NULL, 0, ThreadProc, &tp[2], 0, &dwThreadId[2]);	// CreateThreadでスレッド生成及び開始.(引数にtp[2]を渡している.)
	tp[3].m_iNo = 3;	// m_iNo = 3
	_tcscpy(tp[3].m_tszMessage, _T("No.3"));	// m_tszMessage = "No.3"
	hThread[3] = CreateThread(NULL, 0, ThreadProc, &tp[3], 0, &dwThreadId[3]);	// CreateThreadでスレッド生成及び開始.(引数にtp[3]を渡している.)
	tp[4].m_iNo = 4;	// m_iNo = 4
	_tcscpy(tp[4].m_tszMessage, _T("No.4"));	// m_tszMessage = "No.4"
	hThread[4] = CreateThread(NULL, 0, ThreadProc, &tp[4], 0, &dwThreadId[4]);	// CreateThreadでスレッド生成及び開始.(引数にtp[4]を渡している.)

	// 全てのスレッドがシグナル状態になるまで待機.
	WaitForMultipleObjects(5, hThread, TRUE, INFINITE);	// WaitForMultipleObjectsでスレッドハンドル配列hThreadのすべてのスレッドがシグナル状態になるまで待機.

	// 終了コード取得.
	for (i = 0; i < 5; i++){	// 5回繰り返す.

		// i番目スレッドの終了コードを取得.
		GetExitCodeThread(hThread[i], &dwExitCode[i]);	// GetExitCodeThreadで各スレッドの終了コードを取得.
		_tprintf(_T("dwExitCode[%d] = %lu\n"), i, dwExitCode[i]);	// dwExitCode[i]の値を出力.
		if (hThread[i] != NULL){	// hThread[i]がNULLでない.
			CloseHandle(hThread[i]);	// CloseHandleでhThread[i]を閉じる.
		}

	}

	// プログラムの終了
	return 0;

}