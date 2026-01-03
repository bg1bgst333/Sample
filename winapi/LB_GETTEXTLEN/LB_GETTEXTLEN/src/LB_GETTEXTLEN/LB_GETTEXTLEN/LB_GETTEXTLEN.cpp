// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <commctrl.h>	// コモンコントロール

// マクロの宣言
#define ID_LISTBOX1	501	// ListBox1
#define ID_LISTBOX2	502	// ListBox2

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウプロシージャ

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数・配列の宣言・初期化
	HWND hWnd;					// ウィンドウハンドルhWnd.
	MSG msg;					// メッセージmsg.
	WNDCLASS wc;				// ウィンドウクラスwc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("LB_GETTEXTLEN");						// ウィンドウクラス名"LB_GETTEXTLEN".
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
	hWnd = CreateWindow(_T("LB_GETTEXTLEN"), _T("LB_GETTEXTLEN"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowでウィンドウ作成.
	if (hWnd == NULL){

		// エラー処理
		return -2;	// 異常終了(-2)

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);

	// メッセージループ
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessageでメッセージ取得.

		// ウィンドウメッセージの送出
		if (!IsDialogMessage(hWnd, &msg)){	// IsDialogMessageでダイアログメッセージでなければ.
			TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.
			DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャに送出.
		}

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
				HWND hListBox1;	// リストボックスコントロールハンドルhListBox1.
				HWND hListBox2;	// リストボックスコントロールハンドルhListBox2.

				// lpCSの取得.
				lpCS = (LPCREATESTRUCT)lParam;	// lParamをlpCSに変換.

				// ID_LISTBOX1の作成.
				hListBox1 = CreateWindow(WC_LISTBOX, _T(""), WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP | LBS_NOTIFY, 50, 50, 120, 360, hwnd, (HMENU)ID_LISTBOX1, lpCS->hInstance, NULL);	// // CreateWindowでID_LISTBOX1を作成.
				if (hListBox1 == NULL){
					return -1;
				}

				// ID_LISTBOX1にアイテムを追加.
				SendMessage(hListBox1, LB_ADDSTRING, 0, (LPARAM)(_T("aaaaa")));
				SendMessage(hListBox1, LB_ADDSTRING, 0, (LPARAM)(_T("bbbbb")));
				SendMessage(hListBox1, LB_ADDSTRING, 0, (LPARAM)(_T("ccccc")));

				// ID_LISTBOX2の作成.
				hListBox2 = CreateWindow(WC_LISTBOX, _T(""), WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP | LBS_NOTIFY, 180, 50, 120, 360, hwnd, (HMENU)ID_LISTBOX2, lpCS->hInstance, NULL);	// // CreateWindowでID_LISTBOX2を作成.
				if (hListBox2 == NULL){
					return -1;
				}

				// ID_LISTBOX2にアイテムを追加.
				SendMessage(hListBox2, LB_ADDSTRING, 0, (LPARAM)(_T("あああああ")));
				SendMessage(hListBox2, LB_ADDSTRING, 0, (LPARAM)(_T("いいいいい")));
				SendMessage(hListBox2, LB_ADDSTRING, 0, (LPARAM)(_T("ううううう")));

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

		// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりした時.
		case WM_COMMAND:	// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりした時.(uMsgがWM_COMMANDの時.)

			// WM_COMMANDブロック
			{

				// どのメニュー項目が選択されたかを判定する.
				switch (LOWORD(wParam)){	// LOWORD(wParam)で選択されたメニュー項目のIDが取得できるので, その値で判定する.

					// 取得したIDごとに処理を分岐.
					// ListBox1のイベント発生時.
					case ID_LISTBOX1:

						// ID_LISTBOX1ブロック.
						{

							// 通知コードごとに分岐.
							switch (HIWORD(wParam)){

								// LBN_SELCHANGEの時.
								case LBN_SELCHANGE:

									{

										// 選択されたインデックスを取得し, デバッグ出力.
										HWND hListBox1 = GetDlgItem(hwnd, ID_LISTBOX1);
										int idx = (int)SendMessage(hListBox1, LB_GETCURSEL, 0, 0);
										TCHAR tszIdx[256] = {0};
										_stprintf(tszIdx, _T("ID_LISTBOX1 LBN_SELCHANGE idx = %d\n"), idx);
										OutputDebugString(tszIdx);

									}

									// 既定の処理へ向かう.
									break;

								// LBN_DBLCLKの時.
								case LBN_DBLCLK:

									{

										// ダブルクリックされたインデックスを取得し, デバッグ出力.
										HWND hListBox1 = GetDlgItem(hwnd, ID_LISTBOX1);
										int idx = (int)SendMessage(hListBox1, LB_GETCURSEL, 0, 0);
										TCHAR tszIdx[256] = {0};
										_stprintf(tszIdx, _T("ID_LISTBOX1 LBN_DBLCLK idx = %d\n"), idx);
										OutputDebugString(tszIdx);
										// ダブルクリックされたアイテム文字列の文字列長を取得し, デバッグ出力.
										int len = (int)SendMessage(hListBox1, LB_GETTEXTLEN, idx, 0);
										TCHAR tszLen[256] = {0};
										_stprintf(tszLen, _T("ID_LISTBOX1 LB_GETTEXTLEN len = %d\n"), len);
										OutputDebugString(tszLen);

									}

									// 既定の処理へ向かう.
									break;

								// LBN_SETFOCUSの時.
								case LBN_SETFOCUS:

									{

										// "ID_LISTBOX1 LBN_SETFOCUS"とデバッグ出力.
										OutputDebugString(_T("ID_LISTBOX1 LBN_SETFOCUS\n"));

									}

									// 既定の処理へ向かう.
									break;

								// LBN_KILLFOCUSの時.
								case LBN_KILLFOCUS:

									{

										// "ID_LISTBOX1 LBN_KILLFOCUS"とデバッグ出力.
										OutputDebugString(_T("ID_LISTBOX1 LBN_KILLFOCUS\n"));

									}

								// 上記以外の時.
								default:

									// 既定の処理へ向かう.
									break;

							}

						}
					
						// 既定の処理へ向かう.
						break;

					// ListBox2のイベント発生時.
					case ID_LISTBOX2:

						// ID_LISTBOX2ブロック.
						{

							// 通知コードごとに分岐.
							switch (HIWORD(wParam)){

								// LBN_SELCHANGEの時.
								case LBN_SELCHANGE:

									{

										// 選択されたインデックスを取得し, デバッグ出力.
										HWND hListBox2 = GetDlgItem(hwnd, ID_LISTBOX2);
										int idx = (int)SendMessage(hListBox2, LB_GETCURSEL, 0, 0);
										TCHAR tszIdx[256] = {0};
										_stprintf(tszIdx, _T("ID_LISTBOX2 LBN_SELCHANGE idx = %d\n"), idx);
										OutputDebugString(tszIdx);

									}

									// 既定の処理へ向かう.
									break;

								// LBN_SETFOCUSの時.
								case LBN_SETFOCUS:

									{

										// "ID_LISTBOX2 LBN_SETFOCUS"とデバッグ出力.
										OutputDebugString(_T("ID_LISTBOX2 LBN_SETFOCUS\n"));

									}

									// 既定の処理へ向かう.
									break;

								// LBN_KILLFOCUSの時.
								case LBN_KILLFOCUS:

									{

										// "ID_LISTBOX2 LBN_KILLFOCUS"とデバッグ出力.
										OutputDebugString(_T("ID_LISTBOX2 LBN_KILLFOCUS\n"));

									}

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