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
HWND g_hWndStatic = NULL;	// 取得した値を表示するSTATICのウィンドウハンドルを格納するHWND型変数g_hWndStatic.

// 値を調べるタイマーのID.
#define TIMER_ID_GETHOTKEY	1	// タイマーのIDTIMER_ID_GETHOTKEY.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// 変数の宣言
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージを格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラスを格納するWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("HKM_SETRULES");						// ウィンドウクラス名は"HKM_SETRULES".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("HKM_SETRULES"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("HKM_SETRULES"), _T("HKM_SETRULES"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 940, 200, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"HKM_SETRULES"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL) {	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("HKM_SETRULES"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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

				// コモンコントロールの初期化
				icex.dwSize = sizeof(INITCOMMONCONTROLSEX);	// dwSizeは構造体自身のサイズ.
				icex.dwICC = ICC_HOTKEY_CLASS;				// dwICCにICC_HOTKEY_CLASSを指定.(ホットキー欄を使うために必要.)
				InitCommonControlsEx(&icex);				// InitCommonControlsExでコモンコントロールを初期化.

				// インスタンスハンドルを取得.
				hInst = ((LPCREATESTRUCT)lParam)->hInstance;	// 作成時の情報からインスタンスハンドルを取得.

				// ホットキー欄の作成.
				// 修飾キーなしとShiftのみの組み合わせを無効にし, 無効な入力はCtrl+Altに置き換える.(HKM_SETRULESのwParamは無効な組み合わせ, lParamは代わりの修飾キー.)
				g_hWndHotkey = CreateWindowEx(0, HOTKEY_CLASS, _T(""),
					WS_CHILD | WS_VISIBLE | WS_TABSTOP,
					10, 10, 200, 24, hwnd, NULL, hInst, NULL);	// ホットキー欄を, 親ウィンドウhwndの子として作成.

				// ルールを設定.(修飾キーなし(HKCOMB_NONE)とShiftのみ(HKCOMB_S)を無効にし, 代わりの修飾キーをCtrl+Altにする.)
				SendMessage(g_hWndHotkey, HKM_SETRULES, HKCOMB_NONE | HKCOMB_S, MAKELPARAM(HOTKEYF_CONTROL | HOTKEYF_ALT, 0));	// HKM_SETRULESで, 無効な組み合わせとその代わりの修飾キーを設定.

				// 取得した値を表示するSTATICの作成.
				g_hWndStatic = CreateWindowEx(0, _T("STATIC"), _T("修飾キーなし・Shiftのみは, Ctrl+Altに置き換わります。"),
					WS_CHILD | WS_VISIBLE,
					10, 60, 920, 50, hwnd, NULL, hInst, NULL);	// STATICを, 親ウィンドウhwndの子として作成.

				// 100ミリ秒ごとに値を取得するタイマーを作成.
				SetTimer(hwnd, TIMER_ID_GETHOTKEY, 100, NULL);	// SetTimerで, 100ミリ秒間隔のタイマーを作成.

				// ウィンドウ作成続行
				return 0;	// returnして0を返すと, ウィンドウ作成を続けるとする.

			}

			// 既定の処理へ続ける.
			break;	// breakで抜けると, 既定の処理(DefWindowProc)へ続ける.

		// タイマーが発生したとき.
		case WM_TIMER:		// タイマーが発生したとき.(uMsgがWM_TIMERの場合.)

			// WM_TIMERブロック
			{

				// 変数の宣言
				static WORD wLastHotkey = 0;	// 前回表示した値を格納するWORD型変数wLastHotkey.
				WORD wHotkey;					// HKM_SETRULESで取得した値を格納するWORD型変数wHotkey.
				WCHAR szHotkey[64];				// ホットキーの表示文字列を格納するバッファ.
				WCHAR szKey[32];				// 仮想キーのキー名を格納するバッファ.
				WCHAR szText[256];				// 表示用の文字列バッファ.

				// HKM_SETRULESで現在の値を取得.
				wHotkey = (WORD)SendMessage(g_hWndHotkey, HKM_GETHOTKEY, 0, 0);	// HKM_GETHOTKEYで, 下位バイトが仮想キー, 上位バイトが修飾キーの値を取得.

				// 値が変わったときだけ表示を更新.
				if (wHotkey != wLastHotkey) {	// 前回と値が違う場合.

					// 修飾キーと仮想キーから表示文字列を組み立てる.
					szHotkey[0] = L'\0';	// 表示文字列を空にしてから組み立てる.
					if (HIBYTE(wHotkey) & HOTKEYF_CONTROL) lstrcatW(szHotkey, L"Ctrl+");	// Ctrlがあれば追加.
					if (HIBYTE(wHotkey) & HOTKEYF_SHIFT) lstrcatW(szHotkey, L"Shift+");	// Shiftがあれば追加.
					if (HIBYTE(wHotkey) & HOTKEYF_ALT) lstrcatW(szHotkey, L"Alt+");	// Altがあれば追加.
					GetKeyNameTextW(MapVirtualKeyW(LOBYTE(wHotkey), MAPVK_VK_TO_VSC) << 16, szKey, 32);	// 仮想キーからキー名(例: A)を取得.
					lstrcatW(szHotkey, szKey);	// キー名を末尾に追加.

					// 値と表示文字列を表示.
					wsprintfW(szText, L"HKM_SETRULES=0x%04X 表示=%s", wHotkey, szHotkey);	// wsprintfWで, 取得した値と表示文字列を文字列にする.
					SetWindowTextW(g_hWndStatic, szText);	// STATICの文字列を書き換える.

					// 今回の値を保存.
					wLastHotkey = wHotkey;	// 次回比較するために今回の値を保存.

				}

			}

			// 既定の処理へ続ける.
			break;	// breakで抜けると, 既定の処理(DefWindowProc)へ続ける.

		// ウィンドウが破棄されたとき.
		case WM_DESTROY:	// ウィンドウが破棄されたとき.(uMsgがWM_DESTROYの場合.)

			// WM_DESTROYブロック
			{

				// タイマーを止める.
				KillTimer(hwnd, TIMER_ID_GETHOTKEY);	// KillTimerで, 作成したタイマーを停止.

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