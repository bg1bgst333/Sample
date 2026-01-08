// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <commctrl.h>	// コモンコントロール

// マクロの宣言
#define ID_COMBOBOX1	501	// ComboBox1
#define ID_COMBOBOX2	502	// ComboBox2

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウプロシージャ

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数・配列の宣言・初期化
	HWND hWnd;					// ウィンドウハンドルhWnd.
	MSG msg;					// メッセージmsg.
	WNDCLASS wc;				// ウィンドウクラスwc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("CBN_SETFOCUS");						// ウィンドウクラス名"CBN_SETFOCUS".
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
	hWnd = CreateWindow(_T("CBN_SETFOCUS"), _T("CBN_SETFOCUS"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowでウィンドウ作成.
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
				HWND hComboBox1;	// コンボボックスコントロールハンドルhComboBox1.
				HWND hComboBox2;	// コンボボックスコントロールハンドルhComboBox2.

				// lpCSの取得.
				lpCS = (LPCREATESTRUCT)lParam;	// lParamをlpCSに変換.

				// ID_COMBOBOX1の作成.
				hComboBox1 = CreateWindow(WC_COMBOBOX, _T(""), WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP | CBS_SIMPLE, 50, 50, 120, 360, hwnd, (HMENU)ID_COMBOBOX1, lpCS->hInstance, NULL);	// CreateWindowでID_COMBOBOX1を作成.
				if (hComboBox1 == NULL){
					return -1;
				}

				// ID_COMBOBOX2の作成.
				hComboBox2 = CreateWindow(WC_COMBOBOX, _T(""), WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP | CBS_SIMPLE, 180, 50, 120, 360, hwnd, (HMENU)ID_COMBOBOX2, lpCS->hInstance, NULL);	// CreateWindowでID_COMBOBOX2を作成.
				if (hComboBox1 == NULL){
					return -1;
				}

				// ID_COMBOBOX1にアイテムを追加.
				SendMessage(hComboBox1, CB_ADDSTRING, 0, (LPARAM)(_T("aaaaa")));
				SendMessage(hComboBox1, CB_ADDSTRING, 0, (LPARAM)(_T("bbbbb")));
				SendMessage(hComboBox1, CB_ADDSTRING, 0, (LPARAM)(_T("ccccc")));

				// ID_COMBOBOX2にアイテムを追加.
				SendMessage(hComboBox2, CB_ADDSTRING, 0, (LPARAM)(_T("あああああ")));
				SendMessage(hComboBox2, CB_ADDSTRING, 0, (LPARAM)(_T("いいいいい")));
				SendMessage(hComboBox2, CB_ADDSTRING, 0, (LPARAM)(_T("ううううう")));

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
					// ComboBox1のイベント発生時.
					case ID_COMBOBOX1:

						// ID_COMBOBOX1ブロック.
						{

							// 通知コードごとに分岐.
							switch (HIWORD(wParam)){

								// CBN_SELCHANGEの時.
								case CBN_SELCHANGE:

									{

										// "ID_COMBOBOX1 CBN_SELCHANGE"とデバッグ出力.
										OutputDebugString(_T("ID_COMBOBOX1 CBN_SELCHANGE\n"));

									}

									// 既定の処理へ向かう.
									break;

								// CBN_DBLCLKの時.
								case CBN_DBLCLK:

									{

										// "ID_COMBOBOX1 CBN_DBLCLK"とデバッグ出力.
										OutputDebugString(_T("ID_COMBOBOX1 CBN_DBLCLK\n"));

									}

									// 既定の処理へ向かう.
									break;

								// CBN_SETFOCUSの時.
								case CBN_SETFOCUS:

									{

										// "ID_COMBOBOX1 CBN_SETFOCUS"とデバッグ出力.
										OutputDebugString(_T("ID_COMBOBOX1 CBN_SETFOCUS\n"));

									}

									// 既定の処理へ向かう.
									break;

								// CBN_DROPDOWNの時.
								case CBN_DROPDOWN:

									{

										// "ID_COMBOBOX1 CBN_DROPDOWN"とデバッグ出力.
										OutputDebugString(_T("ID_COMBOBOX1 CBN_DROPDOWN\n"));

									}

									// 既定の処理へ向かう.
									break;

								// CBN_CLOSEUPの時.
								case CBN_CLOSEUP:

									{

										// "ID_COMBOBOX1 CBN_CLOSEUP"とデバッグ出力.
										OutputDebugString(_T("ID_COMBOBOX1 CBN_CLOSEUP\n"));

									}

									// 既定の処理へ向かう.
									break;

								// CBN_SELENDOKの時.
								case CBN_SELENDOK:

									{

										// "ID_COMBOBOX1 CBN_SELENDOK"とデバッグ出力.
										OutputDebugString(_T("ID_COMBOBOX1 CBN_SELENDOK\n"));

									}

									// 既定の処理へ向かう.
									break;

								// CBN_SELENDCANCELの時.
								case CBN_SELENDCANCEL:

									{

										// "ID_COMBOBOX1 CBN_SELENDCANCEL"とデバッグ出力.
										OutputDebugString(_T("ID_COMBOBOX1 CBN_SELENDCANCEL\n"));

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

					// 取得したIDごとに処理を分岐.
					// ComboBox2のイベント発生時.
					case ID_COMBOBOX2:

						// ID_COMBOBOX2ブロック.
						{

							// 通知コードごとに分岐.
							switch (HIWORD(wParam)){

								// CBN_SETFOCUSの時.
								case CBN_SETFOCUS:

									{

										// "ID_COMBOBOX2 CBN_SETFOCUS"とデバッグ出力.
										OutputDebugString(_T("ID_COMBOBOX2 CBN_SETFOCUS\n"));

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