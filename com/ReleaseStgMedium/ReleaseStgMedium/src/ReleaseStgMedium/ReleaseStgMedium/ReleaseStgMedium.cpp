// ヘッダファイルのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <windowsx.h>	// マクロ
#include <tchar.h>		// TCHAR型
#include <ole2.h>		// STGMEDIUM, ReleaseStgMedium
#include <psapi.h>		// GetProcessMemoryInfo
#include <string.h>		// memset

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理ができるように定義したコールバック関数WindowProc.
static void UpdateMemoryInfoText(TCHAR *tszBuf, int cchBuf, LPCTSTR lpctszLabel);	// メモリ使用量を表示するための文字列を組み立てる関数UpdateMemoryInfoTextのプロトタイプ宣言.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージを格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラスを格納するWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("ReleaseStgMedium");				// ウィンドウクラス名は"ReleaseStgMedium".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("ReleaseStgMedium"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("ReleaseStgMedium"), _T("ReleaseStgMedium"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"ReleaseStgMedium"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("ReleaseStgMedium"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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

// メモリ使用量を表示するための文字列を組み立てる関数UpdateMemoryInfoText.(WindowProc内から呼ぶ, ファイル内限定の補助関数.)
static void UpdateMemoryInfoText(TCHAR *tszBuf, int cchBuf, LPCTSTR lpctszLabel){

	// ローカル変数の宣言
	PROCESS_MEMORY_COUNTERS pmc;	// 自プロセスのメモリ使用量を格納するPROCESS_MEMORY_COUNTERS構造体型変数pmc.

	// GetProcessMemoryInfoで自プロセス(GetCurrentProcess())の現在のメモリ使用量を取得する.
	GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));	// GetProcessMemoryInfoでpmcに現在のメモリ使用量を取得.

	// 表示用の文字列を組み立てる.(ワーキングセットサイズ=実際に物理メモリに載っている量.)
	wsprintf(tszBuf, _T("%s\r\nワーキングセットサイズ: %d KB"), lpctszLabel, (int)(pmc.WorkingSetSize / 1024));	// wsprintfでラベルとメモリ使用量を埋め込んだ文字列を組み立てる.

}

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// ウィンドウメッセージに対して独自の処理ができるように定義したウィンドウプロシージャ.

	// static変数の宣言
	static TCHAR tszInfo[256] = _T("");	// メモリ使用量を表示するための文字列バッファtszInfo.
	static BOOL bDone = FALSE;				// 既にSPACEキーの操作を実行済みかどうかを表すBOOL型変数bDone.

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-case文でuMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始されたとき.
		case WM_CREATE:		// ウィンドウの作成が開始されたとき.(uMsgがWM_CREATEの場合.)

			// WM_CREATEブロック
			{

				// 初期状態のメモリ使用量を表示用文字列にセットしておく.
				UpdateMemoryInfoText(tszInfo, 256, _T("SPACEキーで、50MBのSTGMEDIUMを確保してすぐReleaseStgMediumで解放します。"));	// UpdateMemoryInfoTextで初期状態の表示を組み立てる.

				// ウィンドウ作成続行
				return 0;	// returnして0を返すと, ウィンドウ作成を続けるという扱い.

			}

			// 次の処理へ続く.
			break;	// breakで抜けても, 次の処理(DefWindowProc)へ続く.

		// キーが押されたとき.
		case WM_KEYDOWN:	// キーが押されたとき.(uMsgがWM_KEYDOWNの場合.)

			// WM_KEYDOWNブロック
			{

				// SPACEキーが押され, まだ実行していない場合のみ処理する.
				if (wParam == VK_SPACE && !bDone){	// wParamがVK_SPACEで, かつbDoneがFALSE(未実行)の場合.

					// このブロックのローカル変数の宣言
					STGMEDIUM stg;			// 組み立てるSTGMEDIUM構造体型変数stg.
					TCHAR tszBefore[256];	// 解放前のメモリ使用量を表す文字列を格納するTCHAR型配列tszBefore.
					TCHAR tszAfter[256];	// 解放後のメモリ使用量を表す文字列を格納するTCHAR型配列tszAfter.

					// 50MB分のメモリをGlobalAllocで確保する.(GMEM_FIXEDなので, 戻り値のHGLOBALがそのままポインタとして使える.)
					stg.tymed = TYMED_HGLOBAL;								// tymedにTYMED_HGLOBALをセット.
					stg.hGlobal = GlobalAlloc(GMEM_FIXED, 50 * 1024 * 1024);	// GlobalAllocでGMEM_FIXED・50MBを確保し, hGlobalに格納.
					stg.pUnkForRelease = NULL;								// pUnkForReleaseはNULL(呼び出し元=ReleaseStgMedium自身が解放責任を持つ).

					// 確保しただけでは実際のページが割り当てられない場合があるため, memsetで全域に書き込んで実メモリに載せる.
					if (stg.hGlobal != NULL){	// 確保に成功した場合.

						memset(stg.hGlobal, 0xAA, 50 * 1024 * 1024);	// memsetで全域を0xAAで埋め, 実際にページをタッチする.

					}

					// 解放前のメモリ使用量を記録しておく.
					UpdateMemoryInfoText(tszBefore, 256, _T("解放前:"));	// UpdateMemoryInfoTextで解放前の表示を組み立てる.

					// ReleaseStgMediumで, 確保した50MBを解放する.(tymed=TYMED_HGLOBAL・pUnkForRelease=NULLなので, 内部でGlobalFree(hGlobal)相当の解放が行われる. これが今回の主役.)
					ReleaseStgMedium(&stg);	// ReleaseStgMediumにstgのアドレスを渡し, 解放する.(戻り値はvoidなので受け取らない.)

					// 解放後のメモリ使用量を記録する.
					UpdateMemoryInfoText(tszAfter, 256, _T("解放後:"));	// UpdateMemoryInfoTextで解放後の表示を組み立てる.

					// 解放前後の表示を1つにまとめる.
					wsprintf(tszInfo, _T("%s\r\n%s"), tszBefore, tszAfter);	// wsprintfで解放前後の文字列をつなげる.

					// 実行済みフラグを立てる.
					bDone = TRUE;	// bDoneをTRUEにする.

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

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にはデバイスコンテキストハンドルが返るので, hDCに格納.

				// クライアント領域を取得し, その中にtszInfoをDrawTextで折り返し表示.
				GetClientRect(hwnd, &rcClient);	// GetClientRectでクライアント領域のサイズを取得.
				InflateRect(&rcClient, -20, -20);	// InflateRectで少し内側に余白をとる.
				DrawText(hDC, tszInfo, -1, &rcClient, DT_LEFT | DT_TOP | DT_WORDBREAK);	// DrawTextでtszInfoを折り返しながら表示.

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
