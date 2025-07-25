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
	wc.lpszClassName = _T("CreateToolbarEx");					// ウィンドウクラス名"CreateToolbarEx".
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
	hWnd = CreateWindow(_T("CreateToolbarEx"), _T("CreateToolbarEx"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowでウィンドウ作成.
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
		{0, IDM_ZERO, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0},
		{1, IDM_ONE, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0},
		{STD_FILENEW, ID_FILE_NEW, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0},
		{VIEW_PARENTFOLDER, ID_FOLDER_PARENT, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0}
	};
	static int stdid;
	static HINSTANCE hInstance;

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// uMsgごとに処理振り分け.

		// ウィンドウの作成が開始された時.
		case WM_CREATE:

			// WM_CREATEブロック
			{

				// 変数・配列の宣言
				LPCREATESTRUCT lpCS;	// CREATESTRUCT構造体ポインタlpCS.
				TBADDBITMAP tbab;		// TBADDBITMAP構造体tbab.
				int iZero;
				int iOne;

				// lpCSの取得.
				lpCS = (LPCREATESTRUCT)lParam;	// lParamをlpCSに変換.

				// コモンコントロールの初期化.
				//InitCommonControls();	// InitCommonControlsでコモンコントロールの初期化.
				INITCOMMONCONTROLSEX icex = {sizeof(icex), ICC_BAR_CLASSES};
				InitCommonControlsEx(&icex);	// どっちでもいいけどこっち推奨.

				// ステータスバーの作成.
				hStatusBar = CreateStatusWindow(WS_CHILD | WS_VISIBLE, _T("ABCDE"), hwnd, ID_STATUS);	// CreateStatusWindowでステータスバー作成.
				if (hStatusBar == NULL){	// hStatusBarがNULL.
						
					// ウィンドウ作成失敗
					return -1;	// -1を返す.

				}

				// ツールバーの作成.(16x16の256色以下じゃないと落ちるというか関数から出てこない.)
				hToolBar = CreateToolbarEx(hwnd, WS_CHILD | WS_VISIBLE, ID_TOOLBAR1, 2, lpCS->hInstance, IDB_BITMAP1, tbb, 2, 16, 16, 16, 16, sizeof(TBBUTTON));	// CreateToolbarExでツールバー作成.(こういう風に書かないと落ちる.)
				if (hToolBar == NULL){	// hToolBarがNULL.

					// ウィンドウ作成失敗.
					DestroyWindow(hStatusBar);
					return -2;	// -2を返す.

				}
				hInstance = lpCS->hInstance;
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
					// Set Textが選択された時.
					case ID_ITEM_SETTEXT:

						// ID_ITEM_SETTEXTブロック
						{

							// ステータスバーにテキストをセット.
							SendMessage(hStatusBar, SB_SETTEXT, (WPARAM)255 | 0, (LPARAM)_T("あいうえお"));	// SB_SETTEXTでhStatusBarの0番目に"あいうえお"をセット.

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// Add Buttonsが選択された時.
					case ID_ITEM_ADDBUTTONS:

						// ID_ITEM_ADDBUTTONSブロック
						{

							// ボタンの追加.
							TBBUTTON tbb2[] = {
								{2, IDM_TWO, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0},
								{3, IDM_THREE, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0}
							};
							TBADDBITMAP tbab2;		// TBADDBITMAP構造体tbab2.
							SendMessage(hToolBar, TB_BUTTONSTRUCTSIZE, (WPARAM)sizeof(TBBUTTON), 0);
							tbab2.hInst = NULL;
							tbab2.nID = (int)LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAP2));
							stdid = SendMessage(hToolBar, TB_ADDBITMAP, (WPARAM)2, (LPARAM)&tbab2);
							tbb2[0].iBitmap = stdid;
							stdid++;
							tbb2[1].iBitmap = stdid;
							stdid++;
							int iTwo = SendMessage(hToolBar, TB_ADDSTRING, 0, (LPARAM)_T("Two"));
							tbb2[0].iString = iTwo;
							int iThree = SendMessage(hToolBar, TB_ADDSTRING, 0, (LPARAM)_T("Three"));
							tbb2[1].iString = iThree;
							SendMessage(hToolBar, TB_ADDBUTTONS, (WPARAM)2, (LPARAM)(LPTBBUTTON)&tbb2);
							TBBUTTON tbb3 = {
								STD_FILEOPEN, ID_FILE_OPEN, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0
							};
							TBADDBITMAP tbab3;		// TBADDBITMAP構造体tbab3.
							tbab3.hInst =  HINST_COMMCTRL;
							tbab3.nID = IDB_STD_SMALL_COLOR;
							stdid = SendMessage(hToolBar, TB_ADDBITMAP, (WPARAM)1, (LPARAM)&tbab3);
							tbb3.iBitmap = stdid + STD_FILEOPEN;	// なぜかこう.
							stdid++;
							int iOpen = SendMessage(hToolBar, TB_ADDSTRING, 0, (LPARAM)_T("Open"));
							tbb3.iString = iOpen;
							SendMessage(hToolBar, TB_INSERTBUTTON, 3, (LPARAM)&tbb3);

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// ツールバーボタンのZeroが押された時.
					case IDM_ZERO:

						// IDM_ZEROブロック
						{

							// "Zero"と表示.
							MessageBox(hwnd, _T("Zero"), _T("CreateToolbarEx"), MB_OK);

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// ツールバーボタンのOneが押された時.
					case IDM_ONE:

						// IDM_ONEブロック
						{

							// "One"と表示.
							MessageBox(hwnd, _T("One"), _T("CreateToolbarEx"), MB_OK);

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// ツールバーボタンのTwoが押された時.
					case IDM_TWO:

						// IDM_TWOブロック
						{

							// "Two"と表示.
							MessageBox(hwnd, _T("Two"), _T("CreateToolbarEx"), MB_OK);

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// ツールバーボタンのThreeが押された時.
					case IDM_THREE:

						// IDM_THREEブロック
						{

							// "Three"と表示.
							MessageBox(hwnd, _T("Three"), _T("CreateToolbarEx"), MB_OK);

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// ツールバーボタンの新規が押された時.
					case ID_FILE_NEW:

						// ID_FILE_NEWブロック
						{

							// "ID_FILE_NEW"と表示.
							MessageBox(hwnd, _T("ID_FILE_NEW"), _T("CreateToolbarEx"), MB_OK);

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// ツールバーボタンの親フォルダが押された時.
					case ID_FOLDER_PARENT:

						// ID_FOLDER_PARENTブロック
						{

							// "ID_FOLDER_PARENT"と表示.
							MessageBox(hwnd, _T("ID_FOLDER_PARENT"), _T("CreateToolbarEx"), MB_OK);

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// ツールバーボタンの開くが押された時.
					case ID_FILE_OPEN:

						// ID_FILE_OPENブロック
						{

							// "ID_FILE_OPEN"と表示.
							MessageBox(hwnd, _T("ID_FILE_OPEN"), _T("CreateToolbarEx"), MB_OK);

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