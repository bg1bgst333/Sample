// ヘッダファイルのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <windowsx.h>	// マクロ
#include <tchar.h>		// TCHAR型
#include <psapi.h>		// GetProcessMemoryInfo
#include <stdlib.h>		// malloc, free
#include <string.h>		// memset

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理ができるように定義したコールバック関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージを格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラスを格納するWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("GetProcessMemoryInfo");				// ウィンドウクラス名は"GetProcessMemoryInfo".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("GetProcessMemoryInfo"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("GetProcessMemoryInfo"), _T("GetProcessMemoryInfo"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"GetProcessMemoryInfo"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("GetProcessMemoryInfo"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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

	// 表示用の文字列を組み立てる.(ワーキングセットサイズ=実際に物理メモリに載っている量, ページファイル使用量=コミット済みの量.)
	wsprintf(tszBuf, _T("%s\r\nワーキングセットサイズ: %d KB\r\nページファイル使用量: %d KB"), lpctszLabel, (int)(pmc.WorkingSetSize / 1024), (int)(pmc.PagefileUsage / 1024));	// wsprintfでラベルと2つのメモリ使用量を埋め込んだ文字列を組み立てる.

}

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// ウィンドウメッセージに対して独自の処理ができるように定義したウィンドウプロシージャ.

	// static変数の宣言
	static TCHAR tszInfo[256] = _T("");	// メモリ使用量を表示するための文字列バッファtszInfo.
	static LPVOID lpBigBlock = NULL;	// SPACEキーで確保する大きなメモリブロックへのポインタlpBigBlock.(NULLならまだ確保していない.)

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-case文でuMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始されたとき.
		case WM_CREATE:		// ウィンドウの作成が開始されたとき.(uMsgがWM_CREATEの場合.)

			// WM_CREATEブロック
			{

				// 初期状態のメモリ使用量を表示用文字列にセットしておく.
				UpdateMemoryInfoText(tszInfo, 256, _T("SPACEキーで50MBのメモリを確保します。"));	// UpdateMemoryInfoTextで初期状態の表示を組み立てる.

				// ウィンドウ作成続行
				return 0;	// returnして0を返すと, ウィンドウ作成を続けるという扱い.

			}

			// 次の処理へ続く.
			break;	// breakで抜けても, 次の処理(DefWindowProc)へ続く.

		// ウィンドウが破棄されたとき.
		case WM_DESTROY:	// ウィンドウが破棄されたとき.(uMsgがWM_DESTROYの場合.)

			// WM_DESTROYブロック
			{

				// 確保していたメモリがあれば解放しておく.(ウィンドウ破棄前の後始末.)
				if (lpBigBlock != NULL){	// lpBigBlockがNULLでない(確保済みの)場合.

					free(lpBigBlock);	// freeでlpBigBlockを解放.
					lpBigBlock = NULL;	// lpBigBlockをNULLに戻す.

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

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にはデバイスコンテキストハンドルが返るので, hDCに格納.

				// クライアント領域を取得し, その中にtszInfoをDrawTextで折り返し表示.
				GetClientRect(hwnd, &rcClient);	// GetClientRectでクライアント領域のサイズを取得.
				InflateRect(&rcClient, -20, -20);	// InflateRectで少し内側に余白をとる.
				DrawText(hDC, tszInfo, -1, &rcClient, DT_LEFT | DT_TOP | DT_WORDBREAK);	// DrawTextでtszInfoを折り返しながら表示.(改行文字はそのまま改行として扱われる.)

				// ウィンドウの描画終了
				EndPaint(hwnd, &ps);	// EndPaintでこのウィンドウの描画処理を終了させる.

			}

			// 次の処理へ続く.
			break;	// breakで抜けても, 次の処理(DefWindowProc)へ続く.

		// キーが押されたとき.
		case WM_KEYDOWN:	// キーが押されたとき.(uMsgがWM_KEYDOWNの場合.)

			// WM_KEYDOWNブロック
			{

				// SPACEキーが押され, まだメモリを確保していない場合のみ処理する.
				if (wParam == VK_SPACE && lpBigBlock == NULL){	// wParamがVK_SPACEで, かつlpBigBlockがNULL(未確保)の場合.

					// 50MB分のメモリをmallocで確保する.
					lpBigBlock = malloc(50 * 1024 * 1024);	// mallocで50MBを確保し, lpBigBlockに格納.

					// 確保しただけでは実際のページが割り当てられない(コミットはされてもワーキングセットに載らない)場合があるため, memsetで全域に書き込んで実メモリに載せる.
					if (lpBigBlock != NULL){	// 確保に成功した場合.

						memset(lpBigBlock, 0xAA, 50 * 1024 * 1024);	// memsetで全域を0xAAで埋め, 実際にページをタッチする.

					}

					// 表示用文字列を更新する.
					UpdateMemoryInfoText(tszInfo, 256, _T("50MBのメモリを確保しました。"));	// UpdateMemoryInfoTextで確保後の表示を組み立てる.

					// 表示を更新するため再描画要求.
					InvalidateRect(hwnd, NULL, TRUE);	// InvalidateRectで再描画要求.

				}

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
