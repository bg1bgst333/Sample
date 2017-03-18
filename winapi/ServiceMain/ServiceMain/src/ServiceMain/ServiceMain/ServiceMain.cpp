// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力

// 関数プロトタイプ宣言
VOID WINAPI ServiceMain(DWORD dwArgc, LPTSTR * lpszArgv);	// サービスの中核処理.
VOID WINAPI Handler(DWORD fdwControl);	// サービス制御要求に対するハンドラ処理.

// グローバル変数の初期化.
SERVICE_STATUS_HANDLE g_hStatus = NULL;	// サービス状態ハンドルSERVICE_STATUS_HANDLE型g_hStatusをNULLで初期化.
SERVICE_STATUS g_ss = {0};				// サービス状態構造体変数SERVICE_STATUS型g_ssを0で初期化.
HANDLE g_hEventLog = NULL;				// イベントログ操作に必要なハンドルHANDLE型g_hEventLogをNULLで初期化.
BOOL bRun = FALSE;						// サービス実行中であるかどうかを示すBOOL型bRunをFALSEに初期化.

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 構造体配列の初期化
	SERVICE_TABLE_ENTRY ste[] = {{_T("ServiceMain"), ServiceMain}, {NULL, NULL}};	// SERVICE_TABLE_ENTRY構造体配列steをサービス名"ServiceMain"とサービスメイン関数ServiceMainで初期化.(最後にNULL終端の必要あり.)

	// イベントソースの登録.
	g_hEventLog = RegisterEventSource(NULL, _T("ServiceMain"));	// RegisterEventSourceでイベントソース"ServiceMain"を登録し, g_hEventLogを取得.
	if (g_hEventLog == NULL){	// 登録失敗.
		return -1;	// -1を返して終了.
	}

	// ServiceMainの登録
	StartServiceCtrlDispatcher(ste);	// StartServiceCtrlDispatcherでsteを登録.

	// イベントログのハンドルを閉じる.
	DeregisterEventSource(g_hEventLog);	// DeregisterEventSourceでg_hEventLogを閉じる.

	// プログラムの終了
	return 0;

}

// ServiceMain関数の定義
VOID WINAPI ServiceMain(DWORD dwArgc, LPTSTR * lpszArgv){	// サービスの中核処理.

	// サービス制御要求に対するハンドラの登録.
	g_hStatus = RegisterServiceCtrlHandler(_T("ServiceMain"), Handler);	// RegisterServiceCtrlHandlerでHandlerを登録し, ハンドルをg_hStatusに格納.

	// サービス状態の初期化.
	g_ss.dwServiceType = SERVICE_WIN32_OWN_PROCESS;	// サービスは自身の独立したWin32プロセスで動作.
	g_ss.dwCurrentState = SERVICE_START_PENDING;	// サービス開始の保留.
	g_ss.dwControlsAccepted = SERVICE_ACCEPT_STOP;	// 停止コマンドを受け付ける.
	g_ss.dwWin32ExitCode = NO_ERROR;	// 終了コードはひとまずNO_ERROR.
	g_ss.dwServiceSpecificExitCode = 0;	// これはとりあえず0.
	g_ss.dwCheckPoint = 1;	// 開始を待っている状況にするため, とりあえず1にセット.
	g_ss.dwWaitHint = 10 * 1000;	// 待つ見込み時間は10秒ぐらい.
	SetServiceStatus(g_hStatus, &g_ss);	// SetServiceStatusで上記をセット.

	// イベントログで"SERVICE_START_PENDING"を出力.
	const TCHAR *ptszText1 = _T("SERVICE_START_PENDING");	// ptszText1に"SERVICE_START_PENDING"をセット.
	ReportEvent(g_hEventLog, EVENTLOG_INFORMATION_TYPE, 100, 1001, NULL, 1, 0, &ptszText1, NULL);	// ReportEventでptszText1をイベントログに出力.

	// サービス開始時の処理をここに書く.(今回は何もしない.)

	// サービス状態を"実行中"にする.
	g_ss.dwCurrentState = SERVICE_RUNNING;	// SERVICE_RUNNING(実行中)にセット.
	g_ss.dwCheckPoint = 0;	// 待つ状況でなくなったので0にセット.
	g_ss.dwWaitHint = 0;	// 待つ状況でなくなったので0にセット.
	SetServiceStatus(g_hStatus, &g_ss);	// SetServiceStatusで上記をセット.

	// イベントログで"SERVICE_RUNNING"を出力.
	const TCHAR *ptszText2 = _T("SERVICE_RUNNING");	// ptszText2に"SERVICE_RUNNING"をセット.
	ReportEvent(g_hEventLog, EVENTLOG_INFORMATION_TYPE, 100, 1002, NULL, 1, 0, &ptszText2, NULL);	// ReportEventでptszText2をイベントログに出力.

	// サービス実行中とする.
	bRun = TRUE;	// bRunをTRUEにする.

	// サービスメインループに入る.
	while (bRun){	// bRunが真ならループを続ける.

		// イベントログで"ServiceMainLoop!"を出力.
		const TCHAR *ptszText3 = _T("ServiceMainLoop!");	// ptszText3に"ServiceMainLoop!"をセット.
		ReportEvent(g_hEventLog, EVENTLOG_INFORMATION_TYPE, 100, 1003, NULL, 1, 0, &ptszText3, NULL);	// ReportEventでptszText3をイベントログに出力.

		// 1秒待つ.
		Sleep(1000);	// 1秒休止.

	}

	// サービス状態を停止にする.
	g_ss.dwCurrentState = SERVICE_STOPPED;	// サービス停止.
	g_ss.dwCheckPoint = 0;	// 0にセット.
	g_ss.dwWaitHint = 0;	// 0にセット.
	SetServiceStatus(g_hStatus, &g_ss);	// SetServiceStatusで上記をセット.

	// イベントログで"SERVICE_STOPPED"を出力.
	const TCHAR *ptszText6 = _T("SERVICE_STOPPED");	// ptszText6に"SERVICE_STOPPED"をセット.
	ReportEvent(g_hEventLog, EVENTLOG_INFORMATION_TYPE, 100, 1006, NULL, 1, 0, &ptszText6, NULL);	// ReportEventでptszText6をイベントログに出力.

}

// Handler関数の定義
VOID WINAPI Handler(DWORD fdwControl){	// サービス制御要求に対するハンドラ.

	// fdwControlの値で振り分ける.
	switch (fdwControl){	// switch-case文でfdwControlの値で振り分け.

		// サービス停止要求
		case SERVICE_CONTROL_STOP:

			// SERVICE_CONTROL_STOPブロック
			{

				// サービス状態を"停止中"にセット.
				g_ss.dwCurrentState = SERVICE_STOP_PENDING;	// サービス停止処理中.
				g_ss.dwCheckPoint = 0;	// とりあえず0.
				g_ss.dwWaitHint = 10 * 1000;	// 待つ見込み時間は10秒ぐらい.
				SetServiceStatus(g_hStatus, &g_ss);	// SetServiceStatusで上記をセット.

				// イベントログで"SERVICE_STOP_PENDING"を出力.
				const TCHAR *ptszText4 = _T("SERVICE_STOP_PENDING");	// ptszText4に"SERVICE_STOP_PENDING"をセット.
				ReportEvent(g_hEventLog, EVENTLOG_INFORMATION_TYPE, 100, 1004, NULL, 1, 0, &ptszText4, NULL);	// ReportEventでptszText4をイベントログに出力.

				// サービス停止処理.
				bRun = FALSE;	// bRunをFALSEにしてループを抜けさせる.

			}

			// 抜ける.
			break;	// breakで抜ける.

		// サービス状態の更新要求
		case SERVICE_CONTROL_INTERROGATE:

			// SERVICE_CONTROL_INTERROGATEブロック
			{

				// サービス状態をSCMに送る.
				SetServiceStatus(g_hStatus, &g_ss);	// SetServiceStatusで上記をセット.

				// イベントログで"SERVICE_CONTROL_INTERROGATE"を出力.
				const TCHAR *ptszText5 = _T("SERVICE_CONTROL_INTERROGATE");	// ptszText5に"SERVICE_CONTROL_INTERROGATE"をセット.
				ReportEvent(g_hEventLog, EVENTLOG_INFORMATION_TYPE, 100, 1005, NULL, 1, 0, &ptszText5, NULL);	// ReportEventでptszText5をイベントログに出力.

			}

			// 抜ける.
			break;	// breakで抜ける.

		// それ以外.
		default:

			// 抜ける.
			break;	// breakで抜ける.

	}

}