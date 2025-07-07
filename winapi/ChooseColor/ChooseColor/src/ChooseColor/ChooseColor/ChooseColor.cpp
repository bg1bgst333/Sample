// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <commctrl.h>	// コモンコントロール
// 独自のヘッダファイル
#include "resource.h"	// リソースID

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウプロシージャ

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数・配列の宣言・初期化
	HWND hWnd;					// ウィンドウハンドルhWnd.
	MSG msg;					// メッセージmsg.
	WNDCLASS wc;				// ウィンドウクラスwc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("ChooseColor");						// ウィンドウクラス名"ChooseColor".
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
	hWnd = CreateWindow(_T("ChooseColor"), _T("ChooseColor"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowでウィンドウ作成.
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
	static HWND hStatusBar;	// ステータスバーハンドルhStatusBar.
	static HWND hToolBar;	// ツールバーハンドルhToolBar.
	TBBUTTON tbb[] = {
		{0, ID_COLOR_CHOOSE, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0}
	};
	static int stdid;
	static HINSTANCE hInstance;
	static CHOOSECOLOR cc = {0};
	static COLORREF color = 0;
	static COLORREF customColors[16];

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// uMsgごとに処理振り分け.

		// ウィンドウの作成が開始された時.
		case WM_CREATE:

			// WM_CREATEブロック
			{

				// 変数・配列の宣言
				LPCREATESTRUCT lpCS;	// CREATESTRUCT構造体ポインタlpCS.
				TBADDBITMAP tbab;		// TBADDBITMAP構造体tbab.
				int iColorChoose;

				// lpCSの取得.
				lpCS = (LPCREATESTRUCT)lParam;	// lParamをlpCSに変換.

				// コモンコントロールの初期化.
				InitCommonControls();	// InitCommonControlsでコモンコントロールの初期化.

				// ステータスバーの作成.
				hStatusBar = CreateStatusWindow(WS_CHILD | WS_VISIBLE, _T("ABCDE"), hwnd, ID_STATUS);	// CreateStatusWindowでステータスバー作成.
				if (hStatusBar == NULL){	// hStatusBarがNULL.
						
					// ウィンドウ作成失敗
					return -1;	// -1を返す.

				}

				// ツールバーの作成.
				hToolBar = CreateWindowEx(0, TOOLBARCLASSNAME, NULL, WS_CHILD | WS_VISIBLE | CCS_ADJUSTABLE | TBSTYLE_TOOLTIPS, 0, 0, 1152, 80, hwnd, (HMENU)ID_TOOLBAR1, lpCS->hInstance, NULL);	// CreateWindowExでツールバー作成.
				if (hToolBar == NULL){	// hToolBarがNULL.

					// ウィンドウ作成失敗.
					DestroyWindow(hStatusBar);
					return -2;	// -2を返す.

				}
				SendMessage(hToolBar, TB_BUTTONSTRUCTSIZE, (WPARAM)sizeof(TBBUTTON), 0);
				SendMessage(hToolBar, TB_SETBITMAPSIZE, 0, MAKELPARAM(16, 15));
				tbab.hInst = NULL;
				tbab.nID = (int)LoadBitmap(lpCS->hInstance, MAKEINTRESOURCE(IDB_BITMAP1));
				stdid = SendMessage(hToolBar, TB_ADDBITMAP, (WPARAM)1, (LPARAM)&tbab);
				tbb[0].iBitmap = stdid;
				stdid++;
				iColorChoose = SendMessage(hToolBar, TB_ADDSTRING, 0, (LPARAM)_T("Color"));
				tbb[0].iString = iColorChoose;
				SendMessage(hToolBar, TB_ADDBUTTONS, (WPARAM)1, (LPARAM)(LPTBBUTTON)&tbb);
				hInstance = lpCS->hInstance;
				SendMessage(hToolBar, TB_AUTOSIZE, 0, 0);	// TB_AUTOSIZEでツールバーの高さを自動で調整.

				// 色選択ダイアログの初期化.
				cc.lStructSize = sizeof(CHOOSECOLOR);
				cc.hwndOwner = hwnd;
				cc.rgbResult = color;
				cc.lpCustColors = customColors;
				cc.Flags = CC_FULLOPEN | CC_RGBINIT;

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

		// ウィンドウのサイズが変更された時.
		case WM_SIZE:	// ウィンドウのサイズが変	更された時.(uMsgがWM_SIZEの時.)

			// WM_SIZEブロック
			{

				// ステータスバーのサイズを渡す.
				SendMessage(hStatusBar, WM_SIZE, wParam, lParam);

				// ツールバーのサイズをウィンドウのクライアント領域に合わせてリサイズ.
				RECT rc;
				GetClientRect(hwnd, &rc);
				SendMessage(hToolBar, WM_SIZE, rc.right, rc.bottom);

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりした時.
		case WM_COMMAND:	// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりした時.(uMsgがWM_COMMANDの時.)

			// WM_COMMANDブロック
			{

				// どのメニュー項目が選択されたかを判定する.
				switch (LOWORD(wParam)){	// LOWORD(wParam)で選択されたメニュー項目のIDが取得できるので, その値で判定する.

					// 取得したIDごとに処理を分岐.
					// ID_COLOR_CHOOSE(Choose Color)が選択された時.
					case ID_COLOR_CHOOSE:

						// ID_COLOR_CHOOSEブロック
						{

							// 色選択ダイアログ表示.
							BOOL bRet = ChooseColor(&cc);	// ChooseColorで色選択ダイアログを表示.

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

		// コモンコントロールから通知が来た時.
		case WM_NOTIFY:

			// WM_NOTIFYブロック
			{

				// NMHDRポインタへの変換.
				NMHDR *pNMHDR = (NMHDR *)lParam;

				// pNMHDR->codeで振り分け.
				switch (pNMHDR->code){

					// ツールチップテキストを要求された時.
					case TTN_NEEDTEXT:

						// TTN_NEEDTEXTブロック.
						{

							// TOOLTIPTEXTポインタへの変換.
							TOOLTIPTEXT *pTTT = (TOOLTIPTEXT *)lParam;
							pTTT->hinst = hInstance;

							// lpTTT->hdr.idFromで振り分け.
							switch (pTTT->hdr.idFrom){

								// ID_COLOR_CHOOSE
								case ID_COLOR_CHOOSE:

									// IDM_ZEROブロック.
									{

										// ツールチップに"Color"をセット.
										pTTT->lpszText = _T("Color");
										break;

									}

								// それ以外.
								default:

									break;

							}

							break;

						}

					// それ以外.
					default:

						break;

				}

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