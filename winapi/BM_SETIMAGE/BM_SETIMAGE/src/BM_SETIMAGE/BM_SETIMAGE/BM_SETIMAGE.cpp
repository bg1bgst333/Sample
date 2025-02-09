// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <commctrl.h>	// コモンコントロール
// 独自のヘッダファイル
#include "resource.h"	// リソースID

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウプロシージャ
INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ダイアログプロシージャ

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数・配列の宣言・初期化
	HWND hWnd;					// ウィンドウハンドルhWnd.
	MSG msg;					// メッセージmsg.
	WNDCLASS wc;				// ウィンドウクラスwc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("BM_SETIMAGE");						// ウィンドウクラス名"BM_SETIMAGE".
	wc.style = CS_HREDRAW | CS_VREDRAW;							// スタイルCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;								// ウィンドウプロシージャWindowProc.
	wc.hInstance = hInstance;									// インスタンスhInstance.
	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));	// アイコンIDI_ICON1.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);					// カーソルIDC_ARROW.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		// 背景WHITE_BRUSH.
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MAINMENU);			// メニュー名IDR_MAINMENU.
	wc.cbClsExtra = 0;											// 0.
	wc.cbWndExtra = 0;											// 0.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)){	// RegisterClassでウィンドウクラスを登録.

		// エラー処理
		return -1;	// 異常終了(-1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("BM_SETIMAGE"), _T("BM_SETIMAGE"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowでウィンドウ作成.
	if (hWnd == NULL){

		// エラー処理
		return -2;	// 異常終了(-2)

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);

	// メッセージループ
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessageでメッセージ取得.

		// ウィンドウメッセージの送出
		TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.
		DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャに送出.

	}

	// プログラムの終了
	return (int)msg.wParam;	// msg.wParamを返す.

}

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

	// static変数の宣言.
	static HBITMAP hBitmap1 = NULL;	// ビットマップハンドルhBitmap1.(ビットマップ破棄必要.)

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// uMsgごとに処理振り分け.

		// ウィンドウの作成が開始された時.
		case WM_CREATE:

			// WM_CREATEブロック
			{

				// 変数の宣言
				LPCREATESTRUCT lpCS;	// CREATESTRUCT構造体ポインタlpCS.
				HWND hButton1;	// ボタンハンドルhButton1.
				HWND hButton2;	// ボタンハンドルhButton2.
				HICON hIcon1;	// アイコンハンドルhIcon1.(アイコンは破棄不要.)

				// lpCSの取得.
				lpCS = (LPCREATESTRUCT)lParam;	// lParamをlpCSに変換.

				// Button1の作成.
				hButton1 = CreateWindow(WC_BUTTON, _T("Button1"), WS_CHILD | WS_VISIBLE | BS_ICON, 50, 50, 100, 100, hwnd, (HMENU)ID_BUTTON1, lpCS->hInstance, NULL);	// CreateWindowで"Button1"を作成.
				if (hButton1 == NULL){
					return -1;
				}

				// Button2の作成.
				hButton2 = CreateWindow(WC_BUTTON, _T("Button2"), WS_CHILD | WS_VISIBLE | BS_BITMAP, 250, 50, 200, 100, hwnd, (HMENU)ID_BUTTON2, lpCS->hInstance, NULL);	// CreateWindowで"Button2"を作成.
				if (hButton2 == NULL){
					return -2;
				}

				// アイコンのロード.
				hIcon1 = LoadIcon(lpCS->hInstance, MAKEINTRESOURCE(IDI_ICON1));	// LoadIconでIDI_ICON1をロード.

				// ビットマップのロード.
				hBitmap1 = (HBITMAP)LoadImage(lpCS->hInstance, MAKEINTRESOURCE(IDB_BITMAP1), IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR);	// LoadImageでIDB_BITMAP1をロード.

				// Button1にアイコンをセット.
				SendMessage(hButton1, BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIcon1);	// BM_SETIMAGEでhIcon1をセット.

				// Button2にビットマップをセット.
				SendMessage(hButton2, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap1);	// BM_SETIMAGEでhBitmap1をセット.

				// ウィンドウ作成成功
				return 0;	// 0を返すとウィンドウ作成成功となる.

			}

			// 既定の処理へ向かう.
			break;

		// ウィンドウが破棄された時.
		case WM_DESTROY:

			// WM_DESTROYブロック
			{

				// ビットマップの破棄.
				if (hBitmap1 != NULL){
					DeleteObject(hBitmap1);
					hBitmap1 = NULL;
				}

				// 終了メッセージの送信.
				PostQuitMessage(0);	// PostQuitMessageで終了コードを0とするWM_QUITを送信.

			}

			// 既定の処理へ向かう.
			break;

		// コマンドが発生した時.
		case WM_COMMAND:

			// WM_COMMANDブロック
			{

				// どれが選択されたか判定.
				switch (LOWORD(wParam)){

					// Dialogが選択された時.
					case ID_ITEM_DIALOG:

						// ID_ITEM_DIALOGブロック
						{

							// 変数の宣言
							HINSTANCE hInstance;	// インスタンスハンドルhInstance.

							// hInstanceを取得.
							hInstance = (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE);	// GetWindowLongでhInstance取得.

							// ダイアログボックスの表示
							DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG), hwnd, DialogProc);	// DialogBoxでIDD_DIALOGを表示.

							// 0を返す.
							return 0;	// 処理したので戻り値として0を返す.

						}

						// 既定の処理へ向かう.
						break;

					// 上記以外の時.
					default:

						// 既定の処理へ向かう.
						break;

				}

			}

			// 既定の処理へ向かう.
			break;

		// 上記以外の時.
		default:

			// 既定の処理へ向かう.
			break;

	}

	// 既定の処理に任せる.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// DefWindowProcを呼び, 戻り値をそのまま返す.

}

// DialogProc関数の定義
INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam){

	// static変数の宣言.
	static HBITMAP hBitmap2 = NULL;	// ビットマップハンドルhBitmap2.(ビットマップ破棄必要.)

	// ダイアログメッセージに対する処理.
	switch (uMsg){	// uMsgごとに処理振り分け.

		// ダイアログの初期化時.
		case WM_INITDIALOG:

			// WM_INITDIALOGブロック
			{

				// 変数の宣言
				HINSTANCE hInstance;	// インスタンスハンドルhInstance.
				HICON hIcon2;	// アイコンハンドルhIcon2.(アイコンは破棄不要.)
				HWND hButton3;	// ボタンハンドルhButton3.
				HWND hButton4;	// ボタンハンドルhButton4.

				// hInstanceを取得.
				hInstance = (HINSTANCE)GetWindowLong(hwndDlg, GWL_HINSTANCE);	// GetWindowLongでhInstance取得.

				// アイコンのロード.
				hIcon2 = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON2));	// LoadIconでIDI_ICON2をロード.

				// ビットマップのロード.
				hBitmap2 = (HBITMAP)LoadImage(hInstance, MAKEINTRESOURCE(IDB_BITMAP2), IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR);	// LoadImageでIDB_BITMAP2をロード.

				// Button3にアイコンをセット.
				hButton3 = GetDlgItem(hwndDlg, ID_BUTTON3);	// GetDlgItemでhButton3取得.
				SendMessage(hButton3, BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIcon2);	// BM_SETIMAGEでhIcon2をセット.

				// Button4にビットマップをセット.
				hButton4 = GetDlgItem(hwndDlg, ID_BUTTON4);	// GetDlgItemでhButton4取得.
				SendMessage(hButton4, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap2);	// BM_SETIMAGEでhBitmap2をセット.


				// 処理できたのでTRUEを返す.
				return TRUE;

			}

			// breakで抜ける.
			break;

		// ダイアログが閉じられた時.
		case WM_CLOSE:

			// WM_CLOSEブロック
			{

				// ビットマップの破棄.
				if (hBitmap2 != NULL){
					DeleteObject(hBitmap2);
					hBitmap2 = NULL;
				}

				// ダイアログを終了する.
				EndDialog(hwndDlg, IDOK);	// EndDialogでダイアログを終了する.

				// 処理できたのでTRUEを返す.
				return TRUE;

			}

			// breakで抜ける.
			break;

		// 上記以外の処理.
		default:

			// breakで抜ける.
			break;

	}

	// 処理できてないのでFALSEを返す.
	return FALSE;

}