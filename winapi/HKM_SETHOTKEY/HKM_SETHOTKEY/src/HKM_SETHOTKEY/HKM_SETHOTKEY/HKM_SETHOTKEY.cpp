// ヘッダファイルのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <commctrl.h>	// コモンコントロール

// 独自のヘッダファイル
#include "resource.h"	// リソースID

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理ができるように定義するコールバック関数WindowProc.

// 子コントロールのウィンドウハンドル
HWND g_hWndHotkey = NULL;	// ホットキー欄のウィンドウハンドルを格納するHWND型変数g_hWndHotkey.
HWND g_hWndStatic = NULL;	// 設定前後の値を表示するSTATICのウィンドウハンドルを格納するHWND型変数g_hWndStatic.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// 変数の宣言
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージを格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラスを格納するWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("HKM_SETHOTKEY");						// ウィンドウクラス名は"HKM_SETHOTKEY".
	wc.style = CS_HREDRAW | CS_VREDRAW;							// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;								// ウィンドウプロシージャは独自の処理を定義したWindowProc.
	wc.hInstance = hInstance;									// インスタンスハンドルは_tWinMainの引数.
	wc.hIcon = LoadIcon(hInstance, IDI_APPLICATION);			// アイコンはアプリケーション既定のもの.
	wc.hCursor = LoadCursor(hInstance, IDC_ARROW);				// カーソルは矢印.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		// 背景は白ブラシ.
	wc.lpszMenuName = NULL;										// メニューは無し.
	wc.cbClsExtra = 0;											// 0でよい.
	wc.cbWndExtra = 0;											// 0でよい.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)) {	// RegisterClassでウィンドウクラスを登録し, 0が返ってきたらエラー.

		// エラー処理
		MessageBox(NULL, _T("RegisterClass failed!"), _T("HKM_SETHOTKEY"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("HKM_SETHOTKEY"), _T("HKM_SETHOTKEY"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 940, 200, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"HKM_SETHOTKEY"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL) {	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("HKM_SETHOTKEY"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowにSW_SHOWを指定してウィンドウの表示.

	// メッセージループ
	while (GetMessage(&msg, NULL, 0, 0) > 0) {	// GetMessageでメッセージを取得し, 戻り値が0より大きい間はループを続ける.

		// ウィンドウメッセージの送出
		DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(今回は独自に定義するWindowProc)に送出.
		TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.

	}

	// プログラムの終了
	return (int)msg.wParam;	// 終了コード(msg.wParam)を戻り値として返す.

}

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {	// ウィンドウメッセージに対して独自の処理ができるように定義するウィンドウプロシージャ.

	// ウィンドウメッセージに対する処理.
	switch (uMsg) {	// switch-case文でuMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始されたとき.
		case WM_CREATE:		// ウィンドウの作成が開始されたとき.(uMsgがWM_CREATEの場合.)

			// WM_CREATEブロック
			{

				// 変数の宣言
				INITCOMMONCONTROLSEX icex;		// 初期化するコモンコントロールの種類を指定するINITCOMMONCONTROLSEX構造体型変数.
				HINSTANCE hInst;				// アプリケーションインスタンスハンドル.
				WORD wBefore;					// 設定前の値を格納するWORD型変数wBefore.
				WORD wAfter;					// 設定後の値を格納するWORD型変数wAfter.
				WCHAR szText[256];				// 表示用の文字列バッファ.

				// コモンコントロールの初期化
				icex.dwSize = sizeof(INITCOMMONCONTROLSEX);	// dwSizeは構造体自身のサイズ.
				icex.dwICC = ICC_HOTKEY_CLASS;				// dwICCにICC_HOTKEY_CLASSを指定.(ホットキー欄を使うために必要.)
				InitCommonControlsEx(&icex);				// InitCommonControlsExでコモンコントロールを初期化.

				// インスタンスハンドルを取得.
				hInst = ((LPCREATESTRUCT)lParam)->hInstance;	// 作成時の情報からインスタンスハンドルを取得.

				// ホットキー欄の作成.
				g_hWndHotkey = CreateWindowEx(0, HOTKEY_CLASS, _T(""),
					WS_CHILD | WS_VISIBLE | WS_TABSTOP,
					10, 10, 200, 24, hwnd, NULL, hInst, NULL);	// ホットキー欄を, 親ウィンドウhwndの子として作成.

				// 設定前の値をHKM_GETHOTKEYで取得.
				wBefore = (WORD)SendMessage(g_hWndHotkey, HKM_GETHOTKEY, 0, 0);	// HKM_GETHOTKEYで, 設定前の値を取得.

				// HKM_SETHOTKEYで, 仮想キー'A'と修飾キーCtrl+Shiftを設定.
				SendMessage(g_hWndHotkey, HKM_SETHOTKEY, MAKEWORD('A', HOTKEYF_CONTROL | HOTKEYF_SHIFT), 0);	// wParamの下位バイトに仮想キー, 上位バイトに修飾キーを入れて設定.

				// 設定後の値をHKM_GETHOTKEYで取得.
				wAfter = (WORD)SendMessage(g_hWndHotkey, HKM_GETHOTKEY, 0, 0);	// HKM_GETHOTKEYで, 設定後の値を取得.

				// 設定前後の値を表示.
				wsprintfW(szText, L"設定前=0x%04X 設定後=0x%04X (Ctrl+Shift+A)", wBefore, wAfter);	// wsprintfWで, 設定前後の値を文字列にする.

				// 結果を表示するSTATICの作成.
				g_hWndStatic = CreateWindowEx(0, _T("STATIC"), szText,
					WS_CHILD | WS_VISIBLE,
					10, 60, 920, 50, hwnd, NULL, hInst, NULL);	// STATICを, 親ウィンドウhwndの子として作成.

				// ウィンドウ作成続行
				return 0;	// returnして0を返すと, ウィンドウ作成を続けるとする.

			}

			// 既定の処理へ続ける.
			break;	// breakで抜けると, 既定の処理(DefWindowProc)へ続ける.

		// ウィンドウが破棄されたとき.
		case WM_DESTROY:	// ウィンドウが破棄されたとき.(uMsgがWM_DESTROYの場合.)

			// WM_DESTROYブロック
			{

				// メッセージループを抜ける.
				PostQuitMessage(0);	// PostQuitMessageで終了コードを0とするWM_QUITメッセージを送信.

			}

			// 既定の処理へ続ける.
			break;	// breakで抜けると, 既定の処理(DefWindowProc)へ続ける.

		// 上記以外の場合.
		default:

			// 既定の処理へ続ける.
			break;	// breakで抜けると, 既定の処理(DefWindowProc)へ続ける.

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}