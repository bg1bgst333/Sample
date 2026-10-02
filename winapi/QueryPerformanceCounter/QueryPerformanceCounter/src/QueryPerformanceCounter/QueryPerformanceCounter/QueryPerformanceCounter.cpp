// ヘッダファイルのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <windowsx.h>	// マクロ
#include <tchar.h>		// TCHAR型

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理ができるように定義したコールバック関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージを格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラスを格納するWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("QueryPerformanceCounter");				// ウィンドウクラス名は"QueryPerformanceCounter".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("QueryPerformanceCounter"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("QueryPerformanceCounter"), _T("QueryPerformanceCounter"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 820, 420, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"QueryPerformanceCounter"ウィンドウクラスのウィンドウを作成.(結果を複数行表示するため少し広めのサイズを指定.)
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("QueryPerformanceCounter"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.

	// メッセージループ
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessageでメッセージを取得, 戻り値が0より大きい間はループを続ける.

		// ウィンドウメッセージの送出
		DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(この場合は独自に定義するWindowProc)に送出.
		TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.

	}

	// プログラムの終了
	return (int)msg.wParam;	// 終了コード(msg.wParam)を戻り値として返す.

}

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// ウィンドウメッセージに対して独自の処理ができるように定義したウィンドウプロシージャ.

	// static変数の宣言
	static LARGE_INTEGER liFreq;				// QueryPerformanceFrequencyで取得する, 1秒あたりのカウント数を格納するstatic変数liFreq.
	static LARGE_INTEGER liLast;				// 前回SPACEキーを押したときのカウント値を格納するstatic変数liLast.
	static BOOL bFirst = TRUE;					// まだ1回もSPACEキーを押していないかどうかを表すstatic変数bFirst.(経過時間を計算できるのは2回目以降のため.)
	static BOOL bFreqQueried = FALSE;			// liFreqを取得済みかどうかを表すstatic変数bFreqQueried.
	static TCHAR tszResult[2048] = _T("");		// これまでの結果を積み上げて表示するstatic変数tszResult.

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-case文でuMsgの値ごとに処理を振り分ける.

		// キーが押されたとき.
		case WM_KEYDOWN:	// キーが押されたとき.(uMsgがWM_KEYDOWNの場合.)

			// WM_KEYDOWNブロック
			{

				// SPACEキーが押された場合のみ処理する.
				if (wParam == VK_SPACE){	// wParamがVK_SPACEの場合.

					// このブロックのローカル変数の宣言
					LARGE_INTEGER liNow;	// 今回のカウント値を格納するLARGE_INTEGER型変数liNow.
					TCHAR tszLine[192];		// 今回の1行分の結果文字列を組み立てるTCHAR型配列tszLine.

					// まだliFreqを取得していなければ, QueryPerformanceFrequencyで1回だけ取得する.(これも今回の主役.)
					if (!bFreqQueried){	// bFreqQueriedが偽(まだ取得していない)の場合.

						QueryPerformanceFrequency(&liFreq);	// QueryPerformanceFrequencyでliFreq(1秒あたりのカウント数)を取得する.
						bFreqQueried = TRUE;	// bFreqQueriedをTRUEにする.

					}

					// 現在のカウント値を取得する.(これが今回の主役.)
					QueryPerformanceCounter(&liNow);	// QueryPerformanceCounterで現在のカウント値をliNowに格納する.

					// 1回目は経過時間を計算できないので, 基準点の記録だけ行う.
					if (bFirst){	// bFirstが真(まだ1回も押していない)場合.

						wsprintf(tszLine, _T("1回目: QueryPerformanceFrequency=%d(1秒あたりのカウント数) カウント値=%d(基準点として記録)\r\n"), liFreq.LowPart, liNow.LowPart);	// wsprintfで1行分組み立てる.(値は32bit範囲で収まる想定のためLowPartのみ表示.)
						bFirst = FALSE;	// bFirstをFALSEにする.

					}
					else{	// 2回目以降.

						// このブロックのローカル変数の宣言
						double dElapsedMs;	// 前回からの経過時間(ミリ秒)を格納するdouble型変数dElapsedMs.
						long lDiff;			// カウント値の差分を格納するlong型変数lDiff.

						// (今回 - 前回)のカウント差分を, liFreq(1秒あたりのカウント数)で割ってミリ秒に変換する.
						lDiff = liNow.LowPart - liLast.LowPart;	// lDiffに今回と前回のカウント差分を格納する.
						dElapsedMs = (double)lDiff * 1000.0 / (double)liFreq.LowPart;	// dElapsedMsにミリ秒換算した経過時間を格納する.(差分 * 1000 / 1秒あたりのカウント数.)

						// 結果を1行分組み立てる.(小数点以下3桁まで表示したいが, wsprintfは%fに対応していないため, 整数部とミリ秒未満の端数(マイクロ秒)に分けて組み立てる.)
						wsprintf(tszLine, _T("前回から%d.%03dミリ秒経過(GetTickCountの分解能1ミリ秒より細かく計測できる)\r\n"), (int)dElapsedMs, (int)((dElapsedMs - (int)dElapsedMs) * 1000));	// wsprintfで整数部と小数部(マイクロ秒換算)に分けて1行分組み立てる.

					}

					// 組み立てた1行をこれまでの結果に追記する.
					lstrcat(tszResult, tszLine);	// lstrcatでtszResultの末尾にtszLineを連結.

					// 次回の計算のため, 今回のカウント値を記録しておく.
					liLast = liNow;	// liLastにliNowを代入(次回の基準点として保存).

					// 表示を更新するため再描画要求.
					InvalidateRect(hwnd, NULL, TRUE);	// InvalidateRectで再描画要求.

				}

			}

			// 次の処理へ続く.
			break;	// breakで抜けても, 次の処理(DefWindowProc)へ続く.

		// ウィンドウが破棄されたとき.
		case WM_DESTROY:	// ウィンドウが破棄されたとき.(uMsgがWM_DESTROYの場合.)

			// WM_DESTROYブロック
			{

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
				wsprintf(tszAll, _T("SPACEキーを押すたびに、QueryPerformanceCounterで前回との経過時間を高精度に計測します。\r\n\r\n%s"), tszResult);	// 案内文とtszResultを連結.
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
