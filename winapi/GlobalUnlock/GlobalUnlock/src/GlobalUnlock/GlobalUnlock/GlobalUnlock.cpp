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
	wc.lpszClassName = _T("GlobalUnlock");							// ウィンドウクラス名は"GlobalUnlock".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("GlobalUnlock"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("GlobalUnlock"), _T("GlobalUnlock"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 820, 420, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"GlobalUnlock"ウィンドウクラスのウィンドウを作成.(結果を複数行表示するため少し広めのサイズを指定.)
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("GlobalUnlock"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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
	static int iStep = 0;			// 現在どこまで進んだかを表すstatic変数iStep.(0?7の8段階.)
	static HGLOBAL hMem = NULL;		// GlobalAllocで確保するメモリハンドルを保持するstatic変数hMem.
	static LPVOID lpMem = NULL;		// GlobalLockで取得するポインタを保持するstatic変数lpMem.
	static TCHAR tszResult[2048] = _T("");	// これまでの結果を積み上げて表示するstatic変数tszResult.

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-case文でuMsgの値ごとに処理を振り分ける.

		// キーが押されたとき.
		case WM_KEYDOWN:	// キーが押されたとき.(uMsgがWM_KEYDOWNの場合.)

			// WM_KEYDOWNブロック
			{

				// SPACEキーが押された場合のみ処理する.
				if (wParam == VK_SPACE){	// wParamがVK_SPACEの場合.

					// このブロックのローカル変数の宣言
					TCHAR tszLine[256];		// 今回の1行分の結果文字列を組み立てるTCHAR型配列tszLine.
					BOOL bRet;				// GlobalUnlockの戻り値を格納するBOOL型変数bRet.
					DWORD dwErr;			// GetLastErrorの結果を格納するDWORD型変数dwErr.

					// iStepの値に応じて, 1段階ずつ進める.
					switch (iStep){	// iStepの値ごとに処理を振り分ける.

						// GlobalAllocでメモリを確保する.
						case 0:	// まだ何もしていない状態.

							hMem = GlobalAlloc(GMEM_MOVEABLE, 16);	// GlobalAllocでGMEM_MOVEABLE・16バイトを確保し, hMemに格納.(別プロセスへのマーシャリングも可能な移動可能メモリ.)
							wsprintf(tszLine, _T("GlobalAlloc(GMEM_MOVEABLE, 16) -> hMem=0x%08X\r\n"), (unsigned int)(UINT_PTR)hMem);	// 結果を1行分組み立てる.
							break;

						// GlobalLockで1回目のロック.
						case 1:	// GlobalAlloc直後の状態.

							lpMem = GlobalLock(hMem);	// GlobalLockでhMemをロックし, 書き込み可能なポインタをlpMemに格納.(内部のロックカウントが1増える.)
							wsprintf(tszLine, _T("1回目のGlobalLock -> ptr=0x%08X, ロックカウント=%d\r\n"), (unsigned int)(UINT_PTR)lpMem, (int)(GlobalFlags(hMem) & GMEM_LOCKCOUNT));	// GlobalFlagsのGMEM_LOCKCOUNTビットで現在のロックカウントを取得して表示.
							break;

						// GlobalLockで2回目のロック(同じハンドルに対して重ねてロックする).
						case 2:	// 1回ロック済みの状態.

							lpMem = GlobalLock(hMem);	// 同じhMemに対してもう一度GlobalLock.(ロックカウントがさらに1増え, ポインタ自体は1回目と同じ値が返る.)
							wsprintf(tszLine, _T("2回目のGlobalLock(同じハンドル) -> ptr=0x%08X(1回目と同じ), ロックカウント=%d\r\n"), (unsigned int)(UINT_PTR)lpMem, (int)(GlobalFlags(hMem) & GMEM_LOCKCOUNT));	// ロックカウントが2になっていることを示す.
							break;

						// GlobalUnlockで1回目のアンロック(今回の主役).
						case 3:	// 2回ロック済みの状態.

							bRet = GlobalUnlock(hMem);	// GlobalUnlockでロックカウントを1減らす.(今回の主役.)
							dwErr = GetLastError();	// GetLastErrorで直後のエラー状態を取得.
							wsprintf(tszLine, _T("1回目のGlobalUnlock -> 戻り値=%d(まだロックカウント=%dで残っているので非0), GetLastError=%d\r\n"), bRet, (int)(GlobalFlags(hMem) & GMEM_LOCKCOUNT), dwErr);	// まだロックが残っているので戻り値は非0になる.
							break;

						// GlobalUnlockで2回目のアンロック(完全に外れる).
						case 4:	// 1回アンロック済み(ロックカウント=1)の状態.

							bRet = GlobalUnlock(hMem);	// 2回目のGlobalUnlock.(ロックカウントが0になり, 完全にアンロックされる.)
							dwErr = GetLastError();	// GetLastErrorで直後のエラー状態を取得.
							wsprintf(tszLine, _T("2回目のGlobalUnlock -> 戻り値=%d(完全に外れたので0=FALSE), GetLastError=%d(NO_ERRORなら正常終了という意味)\r\n"), bRet, dwErr);	// 戻り値0だが, これは正常(完全に外れた)ことを示しているだけで失敗ではない.
							break;

						// GlobalUnlockで3回目のアンロック(既に完全に外れた状態でさらに呼んでみる、本当の失敗の実演).
						case 5:	// 既に完全にアンロック済みの状態.

							bRet = GlobalUnlock(hMem);	// 既にロックカウントが0の状態でさらにGlobalUnlockを呼ぶ.(これも戻り値は0になるが, 今度は本当の失敗.)
							dwErr = GetLastError();	// GetLastErrorで直後のエラー状態を取得.
							wsprintf(tszLine, _T("3回目のGlobalUnlock(既に完全に外れた状態) -> 戻り値=%d(FALSE), GetLastError=%d(ERROR_NOT_LOCKED。今度は本当の失敗で, 2回目(GetLastError=0)との違いはGetLastErrorでしか分からない)\r\n"), bRet, dwErr);	// 戻り値0だけでは「正常にアンロックされた」のか「そもそもロックされていなかった」のか区別できず, GetLastErrorを見て初めて区別できることを示す行.
							break;

						// GlobalFreeで後始末.
						case 6:	// 一連の確認が終わった状態.

							GlobalFree(hMem);	// GlobalFreeでhMemを解放.(GlobalUnlock自体は既存トピックのReleaseStgMedium等と異なり, メモリの解放そのものは行わない点に注意.)
							hMem = NULL;		// 二重解放を防ぐためNULLに戻す.
							lpMem = NULL;		// 同様にNULLに戻す.
							wsprintf(tszLine, _T("GlobalFreeで解放完了。(GlobalUnlockはロックを外すだけで, メモリの解放自体はGlobalFreeの役目。)\r\n"));	// 後始末の行.
							break;

						// それ以外(既に最後まで進んでいる場合)は何もしない.
						default:	// iStepが7以上(既に最後まで進んでいる)場合.

							return 0;	// 何もせず抜ける.(これ以上SPACEキーを押しても反応しない.)

					}

					// 組み立てた1行をこれまでの結果に追記する.
					lstrcat(tszResult, tszLine);	// lstrcatでtszResultの末尾にtszLineを連結.
					iStep++;	// iStepを1つ進める.

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
				wsprintf(tszAll, _T("SPACEキーを押すたびに、GlobalAlloc→GlobalLock×2→GlobalUnlock×3→GlobalFreeの順に1段階ずつ進めます(今回の主役はGlobalUnlock)。\r\n\r\n%s"), tszResult);	// 案内文とtszResultを連結.
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
