// ヘッダファイルのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <windowsx.h>	// マクロ
#include <mmsystem.h>	// timeSetEvent/timeKillEvent(マルチメディアタイマー関連. winmm.libのリンクが必要.)
#include <tchar.h>		// TCHAR型

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理ができるように定義したコールバック関数WindowProc.
void CALLBACK TimeSetEventProc(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2);	// timeSetEventに渡すコールバック関数TimeSetEventProc.

// グローバル変数の宣言
UINT g_uTimerID = 0;	// timeSetEventの戻り値(タイマーID)を格納するグローバル変数g_uTimerID.(WM_DESTROYでのtimeKillEventに使うため.)

// 定数の定義
#define WM_APP_TIMER_FIRED (WM_APP + 1)	// コールバック(別スレッド)からメインスレッドへ通知するための独自メッセージ.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージを格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラスを格納するWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("timeSetEvent");						// ウィンドウクラス名は"timeSetEvent".
	wc.style = CS_HREDRAW | CS_VREDRAW;							// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;								// ウィンドウプロシージャは独自の処理を定義したWindowProc.
	wc.hInstance = hInstance;									// インスタンスハンドルは_tWinMainの引数.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);					// アイコンはアプリケーション既定のもの.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);					// カーソルは矢印.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		// 背景は白ブラシ.
	wc.lpszMenuName = NULL;										// メニューは無し.
	wc.cbClsExtra = 0;											// 0でよい.
	wc.cbWndExtra = 0;											// 0でよい.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)){	// RegisterClassでウィンドウクラスを登録し, 0が返ってきたらエラー.

		// エラー処理
		MessageBox(NULL, _T("RegisterClass failed!"), _T("timeSetEvent"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("timeSetEvent"), _T("timeSetEvent"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 820, 420, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"timeSetEvent"ウィンドウクラスのウィンドウを作成.(結果を複数行表示するため少し広めのサイズを指定.)
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("timeSetEvent"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.

	// 周期タイマーの開始
	g_uTimerID = timeSetEvent(500, 10, TimeSetEventProc, (DWORD_PTR)hWnd, TIME_PERIODIC);	// timeSetEventに500(間隔500ミリ秒)・10(要求分解能10ミリ秒)・コールバック関数TimeSetEventProc・ユーザーデータとしてhWnd・TIME_PERIODIC(繰り返し)を渡し, 周期タイマーを開始する. 戻り値(0以外ならタイマーID)をg_uTimerIDに格納.
	if (g_uTimerID == 0){	// timeSetEventに失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("timeSetEvent failed!"), _T("timeSetEvent"), MB_OK | MB_ICONHAND);	// MessageBoxで"timeSetEvent failed!"とエラーメッセージを表示.

	}

	// メッセージループ
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessageでメッセージを取得, 戻り値が0より大きい間はループを続ける.

		// ウィンドウメッセージの送出
		DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(この場合は独自に定義するWindowProc)に送出.
		TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.

	}

	// プログラムの終了
	return (int)msg.wParam;	// 終了コード(msg.wParam)を戻り値として返す.

}

// TimeSetEventProc関数の定義
void CALLBACK TimeSetEventProc(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2){	// timeSetEventが内部で作る専用スレッドから, 指定した間隔ごとに呼ばれるコールバック関数.(メインスレッドとは別スレッドで動く点に注意.)

	// static変数の宣言
	static int iCount = 0;		// このコールバック自身だけがアクセスする呼び出し回数カウンタstatic変数iCount.(別スレッドで動くため, メインスレッド側のtszResult等には直接触れない.)

	// 呼び出し回数を1つ進める.
	iCount++;	// iCountをインクリメント.

	// メインスレッドへ, 呼び出し回数と現在時刻を安全に伝える.
	PostMessage((HWND)dwUser, WM_APP_TIMER_FIRED, (WPARAM)iCount, (LPARAM)GetTickCount());	// PostMessageでメインスレッドのウィンドウへ通知.(別スレッドからウィンドウプロシージャを直接呼ばず, 必ずメッセージキュー経由にすることでスレッドをまたぐ競合を避ける.)

}

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// ウィンドウメッセージに対して独自の処理ができるように定義したウィンドウプロシージャ.

	// static変数の宣言
	static TCHAR tszResult[2048] = _T("");		// これまでの結果を積み上げて表示するstatic変数tszResult.
	static DWORD dwPrevTick = 0;				// 前回のコールバック時刻を格納するstatic変数dwPrevTick.(間隔の実測に使う.)

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-case文でuMsgの値ごとに処理を振り分ける.

		// タイマーのコールバックから通知されたとき.
		case WM_APP_TIMER_FIRED:	// タイマーのコールバックから通知されたとき.(uMsgがWM_APP_TIMER_FIREDの場合.)

			// WM_APP_TIMER_FIREDブロック
			{

				// このブロックのローカル変数の宣言
				int iCount;			// 通知された呼び出し回数を格納するint型変数iCount.
				DWORD dwTick;		// 通知された時刻を格納するDWORD型変数dwTick.
				DWORD dwDelta;		// 前回との差を格納するDWORD型変数dwDelta.
				TCHAR tszLine[128];	// 今回の1行分の結果文字列を組み立てるTCHAR型配列tszLine.

				// wParam・lParamから値を取り出す.
				iCount = (int)wParam;	// wParamから呼び出し回数を取得.
				dwTick = (DWORD)lParam;	// lParamから時刻を取得.

				// 前回との差を計算する.
				dwDelta = (dwPrevTick == 0) ? 0 : (dwTick - dwPrevTick);	// 初回(dwPrevTickが0)は差を0扱いにする.
				dwPrevTick = dwTick;	// 今回の時刻を次回のために保存.

				// 組み立てた1行をこれまでの結果に追記する.
				wsprintf(tszLine, _T("%d回目のコールバック: GetTickCount=%u ms(前回との差=%u ms)\r\n"), iCount, dwTick, dwDelta);	// wsprintfで結果を1行にまとめる.
				lstrcat(tszResult, tszLine);	// lstrcatでtszResultの末尾にtszLineを連結.

				// 表示を更新するため再描画要求.
				InvalidateRect(hwnd, NULL, TRUE);	// InvalidateRectで再描画要求.

			}

			// 次の処理へ続く.
			break;	// breakで抜けても, 次の処理(DefWindowProc)へ続く.

		// ウィンドウが破棄されたとき.
		case WM_DESTROY:	// ウィンドウが破棄されたとき.(uMsgがWM_DESTROYの場合.)

			// WM_DESTROYブロック
			{

				// 周期タイマーの後始末
				if (g_uTimerID != 0){	// タイマーが開始できていた場合のみ.

					timeKillEvent(g_uTimerID);	// timeKillEventにタイマーIDを渡し, 周期タイマーを停止する.(timeSetEventで開始したタイマーは, 必ずtimeKillEventで停止する決まりになっている.)
					g_uTimerID = 0;	// 二重停止を避けるため0に戻す.

				}

				// メッセージループを抜ける.
				PostQuitMessage(0);	// PostQuitMessageで抜ける.

			}

			// 次の処理へ続く.
			break;	// breakで抜けても, 次の処理(DefWindowProc)へ続く.

		// 画面の描画が求められたとき.
		case WM_PAINT:		// 画面の描画が求められたとき.(uMsgがWM_PAINTの場合.)

			// WM_PAINTブロック
			{

				// このブロックのローカル変数の宣言
				HDC hDC;			// デバイスコンテキストハンドルを格納するHDC型変数hDC.
				PAINTSTRUCT ps;		// ペイント情報を管理するPAINTSTRUCT構造体型の変数ps.
				RECT rcClient;		// クライアント領域を格納するRECT型変数rcClient.
				RECT rcText;		// 描画領域を格納するRECT型変数rcText.
				TCHAR tszAll[2304];	// 案内文+結果をまとめて表示するためのTCHAR型配列tszAll.

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にはデバイスコンテキストハンドルが返るので, hDCに格納.

				// 案内文とこれまでの結果を表示する.
				GetClientRect(hwnd, &rcClient);	// GetClientRectでクライアント領域のサイズを取得.
				rcText = rcClient;					// rcTextにrcClientをコピー.
				InflateRect(&rcText, -20, -20);	// InflateRectで少し内側に余白をとる.(既存トピックのInflateRectを流用.)
				wsprintf(tszAll, _T("timeSetEventで500ミリ秒間隔の周期タイマーを開始しました。コールバックが呼ばれるたびに下に追記されます。\r\n\r\n%s"), tszResult);	// 案内文とtszResultを連結.
				DrawText(hDC, tszAll, -1, &rcText, DT_LEFT | DT_TOP | DT_WORDBREAK);	// DrawTextで折り返しながら表示.

				// ウィンドウの描画終了
				EndPaint(hwnd, &ps);	// EndPaintでこのウィンドウの描画処理を終了させる.

			}

			// 次の処理へ続く.
			break;	// breakで抜けても, 次の処理(DefWindowProc)へ続く.

		// それ以外の場合.
		default:

			// 次の処理へ続く.
			break;	// breakで抜けても, 次の処理(DefWindowProc)へ続く.

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}
