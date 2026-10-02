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
	wc.lpszClassName = _T("GetLastError");						// ウィンドウクラス名は"GetLastError".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("GetLastError"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("GetLastError"), _T("GetLastError"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 820, 420, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"GetLastError"ウィンドウクラスのウィンドウを作成.(結果を複数行表示するため少し広めのサイズを指定.)
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("GetLastError"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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
	static TCHAR tszResult[2048] = _T("");		// これまでの結果を積み上げて表示するstatic変数tszResult.
	static BOOL bDone = FALSE;					// 既に実演済みかどうかを表すstatic変数bDone.(SPACEキーの二重押下対策.)

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-case文でuMsgの値ごとに処理を振り分ける.

		// キーが押されたとき.
		case WM_KEYDOWN:	// キーが押されたとき.(uMsgがWM_KEYDOWNの場合.)

			// WM_KEYDOWNブロック
			{

				// SPACEキーが押された場合のみ処理する.
				if (wParam == VK_SPACE && !bDone){	// wParamがVK_SPACEかつ, まだ実演していない場合.

					// このブロックのローカル変数の宣言
					DWORD dwErr1, dwErr2, dwErr3;	// 各段階のGetLastErrorの戻り値を格納するDWORD型変数.
					TCHAR tszLine[640];				// 3行分の結果文字列を組み立てるTCHAR型配列tszLine.

					// 3段階を, 途中でウィンドウメッセージ処理(WM_PAINT等)を挟まず, 連続して実行する.
					// (途中にWM_PAINTを挟むと, その中のGDI呼び出しが成功時にSetLastErrorを0にしてしまい,
					//  本当にGetTickCountが原因なのか切り分けできなくなるため, あえて1回のキー入力内で完結させている.)

					// 1段階目: わざと失敗する呼び出しをして, GetLastErrorで直後に確認する.
					CloseHandle(NULL);	// NULLは無効なハンドルなので, CloseHandleは失敗する.(戻り値はFALSE, 内部でSetLastErrorが呼ばれる.)
					dwErr1 = GetLastError();	// 直後に取得.(本トピックの主役.)

					// 2段階目: 最後のエラーコードを設定しない(と文書化されている)関数を間に挟んでから確認する.
					GetTickCount();	// GetTickCount(既存トピック)は, 成功・失敗の概念が無く, 最後のエラーコードを変更しないと文書化されている関数の一例.
					dwErr2 = GetLastError();	// 直後に取得.

					// 3段階目: SetLastErrorで明示的にリセットしてから確認する.
					SetLastError(0);	// SetLastErrorに0を渡すと, 最後のエラーコードを明示的にクリアできる.
					dwErr3 = GetLastError();	// 直後に取得.

					// 3段階分の結果をまとめて組み立てる.
					wsprintf(tszLine, _T("[1]CloseHandle(NULL)直後: GetLastError=%u(ERROR_INVALID_HANDLE=6のはず)\r\n[2]GetTickCountを挟んだ直後: GetLastError=%u\r\n[3]SetLastError(0)直後: GetLastError=%u(0にリセットされているはず)\r\n"), dwErr1, dwErr2, dwErr3);	// wsprintfで3行分まとめて組み立てる.

					// 実演済みフラグを立てる.(以降のSPACEキーは無視.)
					bDone = TRUE;	// bDoneをTRUEにする.

					// 組み立てた結果をこれまでの結果に追記する.
					lstrcat(tszResult, tszLine);	// lstrcatでtszResultの末尾にtszLineを連結.

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
				wsprintf(tszAll, _T("SPACEキーを押すと、わざと失敗→成功する別の関数を挟んで確認→SetLastErrorでリセット、の3段階を連続実行します。\r\n\r\n%s"), tszResult);	// 案内文とtszResultを連結.
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
