// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <commctrl.h>	// コモンコントロール

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
	wc.lpszClassName = _T("WM_DRAWITEM");						// ウィンドウクラス名"WM_DRAWITEM".
	wc.style = CS_HREDRAW | CS_VREDRAW;							// スタイルCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;								// ウィンドウプロシージャWindowProc.
	wc.hInstance = hInstance;									// インスタンスhInstance.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);					// アイコンはアプリケーション既定のもの.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);					// カーソルIDC_ARROW.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		// 背景WHITE_BRUSH.
	wc.lpszMenuName = NULL;										// とりあえずここではNULLにしておく.
	wc.cbClsExtra = 0;											// 0.
	wc.cbWndExtra = 0;											// 0.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)){	// RegisterClassでウィンドウクラスを登録.

		// エラー処理
		return -1;	// 異常終了(-1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("WM_DRAWITEM"), _T("WM_DRAWITEM"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowでウィンドウ作成.
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

				// Button1の作成.
				hButton1 = CreateWindow(WC_BUTTON, _T("Button1"), WS_CHILD | WS_VISIBLE | BS_OWNERDRAW, 50, 50, 200, 100, hwnd, (HMENU)ID_BUTTON1, lpCS->hInstance, NULL);	// CreateWindowで"Button1"を作成.
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

				// 押されている状態かそうでないかで分ける.
				if (lpDIS->itemState & ODS_SELECTED){	// ビットフラグODS_SELECTEDが立っている.
					SetBkMode(lpDIS->hDC, TRANSPARENT);	// SetBkModeで背景透過.
					SetTextColor(lpDIS->hDC, RGB(0xff, 0xff, 0xff));	// SetTextColorで文字色を白に.
					hBrush = CreateSolidBrush(RGB(0xff, 0x0, 0x0));	// CreateSolidBrushで赤ブラシを作成.
					hOldBrush = (HBRUSH)SelectObject(lpDIS->hDC, hBrush);	// SelectObjectでhBrushを選択.
					Rectangle(lpDIS->hDC, 0, 0, lpDIS->rcItem.right, lpDIS->rcItem.bottom);	// Rectangleで矩形を描画.
					TextOut(lpDIS->hDC, 40, 40, _T("押されている"), lstrlen( _T("押されている")));	// TextOutで"押されている"を描画.
				}
				else{
					SetBkMode(lpDIS->hDC, TRANSPARENT);	// SetBkModeで背景透過.
					SetTextColor(lpDIS->hDC, RGB(0xff, 0xff, 0xff));	// SetTextColorで文字色を白に.
					hBrush = CreateSolidBrush(RGB(0x0, 0x0, 0xff));	// CreateSolidBrushで青ブラシを作成.
					hOldBrush = (HBRUSH)SelectObject(lpDIS->hDC, hBrush);	// SelectObjectでhBrushを選択.
					Rectangle(lpDIS->hDC, 0, 0, lpDIS->rcItem.right, lpDIS->rcItem.bottom);	// Rectangleで矩形を描画.
					TextOut(lpDIS->hDC, 40, 40, _T("押されていない"), lstrlen( _T("押されていない")));	// TextOutで"押されていない"を描画.
				}
				SelectObject(lpDIS->hDC, hOldBrush);	// SelectObjectで以前のブラシに戻す.
				DeleteObject(hBrush);	// DeleteObjectでhBrushを破棄.

				// TRUEを返す.
				return TRUE;

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