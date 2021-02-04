// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理をするように定義したコールバック関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数・配列の宣言と初期化.
	HWND hWnd;							// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;							// ウィンドウメッセージ情報を格納するMSG構造体型変数msg.
	WNDCLASS wc;						// ウィンドウクラス情報をもつWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("WNDCLASS");						// ウィンドウクラス名は"WNDCLASS".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;							// ウィンドウプロシージャは独自の処理を定義したWindowProc.
	wc.hInstance = hInstance;								// インスタンスハンドルは_tWinMainの引数.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// アイコンはアプリケーション既定のもの.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// カーソルは矢印.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 背景は白ブラシ.
	wc.lpszMenuName = NULL;									// なし
	wc.cbClsExtra = sizeof(HCURSOR) * 2;					// HCURSORのサイズの2倍.
	wc.cbWndExtra = 0;										// 0でいい.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)) {	// RegisterClassでウィンドウクラスを登録し, 0が返ったらエラー.

		// エラー処理
		MessageBox(NULL, _T("RegisterClass Failure!"), _T("WNDCLASS"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass Failure!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("WNDCLASS"), _T("WNDCLASS"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"WNDCLASS"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL) {	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow Failure!"), _T("WNDCLASS"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow Failure!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.

	// メッセージループ
	while (GetMessage(&msg, NULL, 0, 0) > 0) {	// GetMessageでメッセージを取得, 戻り値が0より大きい間はループし続ける.

		// ウィンドウメッセージ処理
		TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.
		DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(この場合は独自に定義したWindowProc)に送出.

	}

	// プログラムの終了
	return (int)msg.wParam;	// 終了コード(msg.wParam)を戻り値として返す.

}

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {	// ウィンドウメッセージに対して独自の処理をするように定義したウィンドウプロシージャ.

	// スタティック変数の初期化.
	static HCURSOR hOldCursor = NULL;	// hOldCursorをNULLで初期化.

	// ウィンドウメッセージに対する処理.
	switch (uMsg) {	// switch-casa文でuMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始された時.
		case WM_CREATE:		// ウィンドウの作成が開始された時.(uMsgがWM_CREATEの時.)

			// WM_CREATEブロック
			{

				// 変数の宣言と初期化.
				HCURSOR hCrossCursor;	// クロスカーソルハンドルhCrossCursor.
				HCURSOR hWaitCursor;	// ウェイトカーソルハンドルhWaitCursor.

				// クロスカーソルのロード.
				hCrossCursor = (HCURSOR)LoadImage(NULL, IDC_CROSS, IMAGE_CURSOR, 0, 0, LR_SHARED);	// LoadImageでIDC_CROSSをロードし, ハンドルをhCrossCursorに格納.

				// クラス拡張メモリにクロスカーソルハンドルをセット.
				SetClassLong(hwnd, 0, (LONG)hCrossCursor);	// SetClassLongでクラス拡張メモリの先頭位置0にhCrossCursorをセット.

				// ウェイトカーソルのロード.
				hWaitCursor = (HCURSOR)LoadImage(NULL, IDC_WAIT, IMAGE_CURSOR, 0, 0, LR_SHARED);	// LoadImageでIDC_WAITをロードし, ハンドルをhWaitCursorに格納.

				// クラス拡張メモリにウェイトカーソルハンドルをセット.
				SetClassLong(hwnd, 4, (LONG)hWaitCursor);	// SetClassLongでクラス拡張メモリの先頭から4バイトの位置4にhWaitCursorをセット.

				// ウィンドウ作成成功
				return 0;	// return文で0を返して, ウィンドウ作成成功とする.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// ウィンドウが破棄された時.
		case WM_DESTROY:	// ウィンドウが破棄された時.(uMsgがWM_DESTROYの時.)

			// WM_DESTROYブロック
			{

				// 以前のカーソルに戻す.
				SetCursor(hOldCursor);	// SetCursorにhOldCursorをセット.

				// 終了メッセージの送信.
				PostQuitMessage(0);	// PostQuitMessageで終了コードを0としてWM_QUITメッセージを送信.(するとメッセージループのGetMessageの戻り値が0になるので, メッセージループから抜ける.)

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// マウスの左ボタンが押された時.
		case WM_LBUTTONDOWN:	// マウスの左ボタンが押された時.(uMsgがWM_LBUTTONDOWNの時.)

			// WM_LBUTTONDOWNブロック
			{

				// 変数の宣言と初期化.
				HCURSOR hCrossCursor;	// クロスカーソルハンドルhCrossCursor.
				HCURSOR hArrowCursor;	// アローカーソルハンドルhArrowCursor.
				HCURSOR hWaitCursor;	// ウェイトカーソルハンドルhWaitCursor.

				// クロスカーソルの取得.
				hCrossCursor = (HCURSOR)GetClassLong(hwnd, 0);	// GetClassLongでクラス拡張メモリ先頭位置0の値を取得し, hCrossCursorに格納.

				// クロスカーソルをセット.
				hOldCursor = SetCursor(hCrossCursor);	// SetCursorにhCrossCursorをセットし, 以前のカーソルはhOldCursorに格納.

				// 5秒休止.
				Sleep(5000);	// Sleepで5000ミリ秒休止.

				// GetClassLongで既定のカーソル(つまりアローカーソル.)を取得.
				hArrowCursor = (HCURSOR)GetClassLong(hwnd, GCL_HCURSOR);	// GetClassLongで既定のカーソルを取得し, hArrowCursorに格納.

				// アローカーソルをセット.
				SetCursor(hArrowCursor);	// SetCursorにhArrowCursorをセット.

				// 5秒休止.
				Sleep(5000);	// Sleepで5000ミリ秒休止.

				// ウェイトカーソルの取得.
				hWaitCursor = (HCURSOR)GetClassLong(hwnd, 4);	// GetClassLongでクラス拡張メモリ先頭から4バイトの位置4の値を取得し, hWaitCursorに格納.

				// ウェイトカーソルをセット.
				SetCursor(hWaitCursor);	// SetCursorにhWaitCursorをセット.

				// 5秒休止.
				Sleep(5000);	// Sleepで5000ミリ秒休止.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// 上記以外の時.
		default:	// 上記以外の値の時の既定処理.

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

	}

	// あとは既定の処理に任せる.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// 戻り値も含めDefWindowProcに既定の処理を任せる.

}