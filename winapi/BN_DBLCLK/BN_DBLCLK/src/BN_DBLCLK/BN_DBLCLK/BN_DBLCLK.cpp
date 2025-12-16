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
	wc.lpszClassName = _T("BN_DBLCLK");							// ウィンドウクラス名"BN_DBLCLK".
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
	hWnd = CreateWindow(_T("BN_DBLCLK"), _T("BN_DBLCLK"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowでウィンドウ作成.
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

	// static変数の初期化.
	static HBITMAP hBitmapButtonReleased = NULL;
	static HBITMAP hBitmapButtonPressed = NULL;

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
				hButton1 = CreateWindow(WC_BUTTON, _T("Button1"), WS_CHILD | WS_VISIBLE | BS_OWNERDRAW, 50, 50, 120, 40, hwnd, (HMENU)ID_BUTTON1, lpCS->hInstance, NULL);	// CreateWindowで"Button1"を作成.
				if (hButton1 == NULL){
					return -1;
				}

				// ビットマップのロード.
				hBitmapButtonReleased = (HBITMAP)LoadImage(lpCS->hInstance, _T("button_released.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
				if (hBitmapButtonReleased == NULL){
					return -1;
				}
				hBitmapButtonPressed = (HBITMAP)LoadImage(lpCS->hInstance, _T("button_pressed.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
				if (hBitmapButtonPressed == NULL){
					DeleteObject(hBitmapButtonReleased);
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

				// ビットマップの破棄.
				if (hBitmapButtonPressed != NULL){
					DeleteObject(hBitmapButtonPressed);
					hBitmapButtonPressed = NULL;
				}
				if (hBitmapButtonReleased != NULL){
					DeleteObject(hBitmapButtonReleased);
					hBitmapButtonReleased = NULL;
				}

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

				// lpDISの取得.
				lpDIS = (LPDRAWITEMSTRUCT)lParam;	// lParamをlpDISに変換.

				// 押されている状態かそうでないかで分ける.
				HDC hMemDC = NULL;
				HBITMAP hOld = NULL;
				hMemDC = CreateCompatibleDC(lpDIS->hDC);
				int i = 0;
				if (lpDIS->itemState & ODS_SELECTED){	// ビットフラグODS_SELECTEDが立っている.
					hOld = (HBITMAP)SelectObject(hMemDC, hBitmapButtonPressed);
					i = 2;
				}
				else{
					hOld = (HBITMAP)SelectObject(hMemDC, hBitmapButtonReleased);
				}
				BitBlt(lpDIS->hDC, 0, 0, 120, 40, hMemDC, 0, 0, SRCCOPY);
				if (lpDIS->itemState & ODS_DISABLED){	// 無効状態.
					SetTextColor(lpDIS->hDC, RGB(0x7f, 0x7f, 0x7f));
				}
				TextOut(lpDIS->hDC, 36 + i, 10 + i, _T("Button1"), lstrlen(_T("Button1")));
				DeleteDC(hMemDC);

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
					// Button1が押された時.
					case ID_BUTTON1:

						// ID_BUTTON1ブロック.
						{

							// 通知コードごとに分岐.
							switch (HIWORD(wParam)){

								// BN_DBLCLKの時.
								case BN_DBLCLK:

									// BN_DBLCLKブロック.
									{

										// "BN_DBLCLK"とデバッグ出力.
										OutputDebugString(_T("BN_DBLCLK\n"));

									}

									// 既定の処理へ向かう.
									break;

								// 上記以外の時.
								default:

									// 既定の処理へ向かう.
									break;

							}

							// 既定の処理へ向かう.
							break;

						}

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