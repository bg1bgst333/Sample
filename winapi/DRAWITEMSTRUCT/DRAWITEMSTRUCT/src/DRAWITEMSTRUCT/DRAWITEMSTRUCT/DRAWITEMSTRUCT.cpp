// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <commctrl.h>	// コモンコントロール
// 独自のヘッダファイル
#include "resource.h"	// リソースID

// マクロの宣言
#define ID_BUTTON1	501	// Button1

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウプロシージャ

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数・配列の宣言・初期化
	HWND hWnd;					// ウィンドウハンドルhWnd.
	MSG msg;					// メッセージmsg.
	WNDCLASS wc;				// ウィンドウクラスwc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("DRAWITEMSTRUCT");						// ウィンドウクラス名"DRAWITEMSTRUCT".
	wc.style = CS_HREDRAW | CS_VREDRAW;							// スタイルCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;								// ウィンドウプロシージャWindowProc.
	wc.hInstance = hInstance;									// インスタンスhInstance.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);					// アイコンはアプリケーション既定のもの.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);					// カーソルIDC_ARROW.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		// 背景WHITE_BRUSH.
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MAINMENU);			// メニューにはIDR_MAINMENUをMAKEINTRESOURCEマクロで指定.
	wc.cbClsExtra = 0;											// 0.
	wc.cbWndExtra = 0;											// 0.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)){	// RegisterClassでウィンドウクラスを登録.

		// エラー処理
		return -1;	// 異常終了(-1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("DRAWITEMSTRUCT"), _T("DRAWITEMSTRUCT"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowでウィンドウ作成.
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

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// uMsgごとに処理振り分け.

		// ウィンドウの作成が開始された時.
		case WM_CREATE:

			// WM_CREATEブロック
			{

				// 変数の宣言
				LPCREATESTRUCT lpCS;	// CREATESTRUCT構造体ポインタlpCS.
				HWND hButton1;	// ボタンハンドルhButton1.

				// lpCSの取得.
				lpCS = (LPCREATESTRUCT)lParam;	// lParamをlpCSに変換.

				// Button1の作成.(無効にしておく.)
				hButton1 = CreateWindow(WC_BUTTON, _T("Button1"), WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | WS_DISABLED, 50, 50, 200, 100, hwnd, (HMENU)ID_BUTTON1, lpCS->hInstance, NULL);	// CreateWindowで"Button1"を作成.
				if (hButton1 == NULL){
					return -1;
				}

				// ウィンドウ作成成功
				return 0;	// 0を返すとウィンドウ作成成功となる.

			}

			// 既定の処理へ向かう.
			break;

		// ウィンドウが破棄された時.
		case WM_DESTROY:

			// WM_DESTROYブロック
			{

				// 終了メッセージの送信.
				PostQuitMessage(0);	// PostQuitMessageで終了コードを0とするWM_QUITを送信.

			}

			// 既定の処理へ向かう.
			break;

		// オーナードローで描画が要求された時.
		case WM_DRAWITEM:

			// WM_DRAWITEMブロック
			{

				// 変数の宣言
				LPDRAWITEMSTRUCT lpDIS;	// DRAWITEMSTRUCT構造体ポインタlpDIS.
				HBRUSH hBrush;		// ブラシハンドルhBrush.
				HBRUSH hOldBrush;	// 以前のブラシハンドルhOldBrush.

				// lpDISの取得.
				lpDIS = (LPDRAWITEMSTRUCT)lParam;	// lParamをlpDISに変換.

				// ボタンが無効か.
				if (lpDIS->itemState & ODS_DISABLED){	// 無効.
					SetBkMode(lpDIS->hDC, TRANSPARENT);	// SetBkModeで背景透過.
						SetTextColor(lpDIS->hDC, RGB(0xff, 0xff, 0xff));	// SetTextColorで文字色を白に.
						hBrush = CreateSolidBrush(RGB(0x80, 0x80, 0x80));	// CreateSolidBrushで灰ブラシを作成.
						hOldBrush = (HBRUSH)SelectObject(lpDIS->hDC, hBrush);	// SelectObjectでhBrushを選択.
						Rectangle(lpDIS->hDC, 0, 0, lpDIS->rcItem.right, lpDIS->rcItem.bottom);	// Rectangleで矩形を描画.
						TextOut(lpDIS->hDC, 40, 40, _T("無効になっている"), lstrlen( _T("無効になっている")));	// TextOutで"無効になっている"を描画.
				}
				else{	// 有効.
					// 押されている状態か.
					if (lpDIS->itemState & ODS_SELECTED){	// ビットフラグODS_SELECTEDが立っている.
						SetBkMode(lpDIS->hDC, TRANSPARENT);	// SetBkModeで背景透過.
						SetTextColor(lpDIS->hDC, RGB(0xff, 0xff, 0xff));	// SetTextColorで文字色を白に.
						hBrush = CreateSolidBrush(RGB(0xff, 0x0, 0x0));	// CreateSolidBrushで赤ブラシを作成.
						hOldBrush = (HBRUSH)SelectObject(lpDIS->hDC, hBrush);	// SelectObjectでhBrushを選択.
						Rectangle(lpDIS->hDC, 0, 0, lpDIS->rcItem.right, lpDIS->rcItem.bottom);	// Rectangleで矩形を描画.
						TextOut(lpDIS->hDC, 40, 40, _T("押されている"), lstrlen( _T("押されている")));	// TextOutで"押されている"を描画.
					}
					else{	// 押されていない. 
						SetBkMode(lpDIS->hDC, TRANSPARENT);	// SetBkModeで背景透過.
						SetTextColor(lpDIS->hDC, RGB(0xff, 0xff, 0xff));	// SetTextColorで文字色を白に.
						hBrush = CreateSolidBrush(RGB(0x0, 0x0, 0xff));	// CreateSolidBrushで青ブラシを作成.
						hOldBrush = (HBRUSH)SelectObject(lpDIS->hDC, hBrush);	// SelectObjectでhBrushを選択.
						Rectangle(lpDIS->hDC, 0, 0, lpDIS->rcItem.right, lpDIS->rcItem.bottom);	// Rectangleで矩形を描画.
						TextOut(lpDIS->hDC, 40, 40, _T("押されていない"), lstrlen( _T("押されていない")));	// TextOutで"押されていない"を描画.
					}
				}
				SelectObject(lpDIS->hDC, hOldBrush);	// SelectObjectで以前のブラシに戻す.
				DeleteObject(hBrush);	// DeleteObjectでhBrushを破棄.

				// TRUEを返す.
				return TRUE;

			}

			// 既定の処理へ向かう.
			break;

		// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりした時.
		case WM_COMMAND:	// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりした時.(uMsgがWM_COMMANDの時.)

			// WM_COMMANDブロック
			{

				// どのメニュー項目が選択されたかを判定する.
				switch (LOWORD(wParam)){	// LOWORD(wParam)で選択されたメニュー項目のIDが取得できるので, その値で判定する.

					// 取得したIDごとに処理を分岐.
					// Enable Buttonが選択された時.
					case ID_ITEM_ENABLE_BUTTON:

						// ID_ITEM_ENABLE_BUTTONブロック
						{

							// チェック済みかそうでないか調べる.
							UINT uiRet = GetMenuState(GetMenu(hwnd), ID_ITEM_ENABLE_BUTTON, MF_BYCOMMAND);	// GetMenuStateでID_ITEM_ENABLE_BUTTONがチェックされてるか取得.
							if (uiRet & MF_CHECKED){	// チェックされている.
								EnableWindow(GetDlgItem(hwnd, ID_BUTTON1), FALSE);	// EnableWindowでID_BUTTON1を無効化.
								// Enable Buttonのチェックを外す.
								CheckMenuItem(GetMenu(hwnd), ID_ITEM_ENABLE_BUTTON, MF_BYCOMMAND | MF_UNCHECKED);	// CheckMenuItemでID_ITEM_ENABLE_BUTTONのチェックを外す.
							}
							else{	// チェックされていない.
								EnableWindow(GetDlgItem(hwnd, ID_BUTTON1), TRUE);	// EnableWindowでID_BUTTON1を有効化.
								// Enable Buttonにチェックを入れる.
								CheckMenuItem(GetMenu(hwnd), ID_ITEM_ENABLE_BUTTON, MF_BYCOMMAND | MF_CHECKED);	// CheckMenuItemでID_ITEM_ENABLE_BUTTONにチェック.
							}

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// 上記以外の時.
					default:

						// 既定の処理へ向かう.
						break;

				}

				// 既定の処理へ向かう.
				break;

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