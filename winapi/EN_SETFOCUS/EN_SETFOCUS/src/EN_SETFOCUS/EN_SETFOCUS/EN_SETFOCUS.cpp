// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <commctrl.h>	// コモンコントロール

// マクロの宣言
#define ID_EDIT1	501	// Edit1
#define ID_EDIT2	502	// Edit2

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウプロシージャ

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数・配列の宣言・初期化
	HWND hWnd;					// ウィンドウハンドルhWnd.
	MSG msg;					// メッセージmsg.
	WNDCLASS wc;				// ウィンドウクラスwc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("EN_SETFOCUS");						// ウィンドウクラス名"EN_SETFOCUS".
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
	hWnd = CreateWindow(_T("EN_SETFOCUS"), _T("EN_SETFOCUS"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowでウィンドウ作成.
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
				HWND hEdit1;	// エディットコントロールハンドルhEdit1.
				HWND hEdit2;	// エディットコントロールハンドルhEdit2.

				// lpCSの取得.
				lpCS = (LPCREATESTRUCT)lParam;	// lParamをlpCSに変換.

				// Edit1の作成.
				hEdit1 = CreateWindow(WC_EDIT, _T("Edit1"), WS_CHILD | WS_VISIBLE | WS_BORDER, 50, 50, 200, 200, hwnd, (HMENU)ID_EDIT1, lpCS->hInstance, NULL);	// CreateWindowで"Edit1"を作成.
				if (hEdit1 == NULL){
					return -1;
				}

				// Edit2の作成.
				hEdit2 = CreateWindow(WC_EDIT, _T("Edit2"), WS_CHILD | WS_VISIBLE | WS_BORDER, 50, 270, 200, 200, hwnd, (HMENU)ID_EDIT2, lpCS->hInstance, NULL);	// CreateWindowで"Edit2"を作成.
				if (hEdit2 == NULL){
					return -2;
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

		// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりした時.
		case WM_COMMAND:	// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりした時.(uMsgがWM_COMMANDの時.)

			// WM_COMMANDブロック
			{

				// どのメニュー項目が選択されたかを判定する.
				switch (LOWORD(wParam)){	// LOWORD(wParam)で選択されたメニュー項目のIDが取得できるので, その値で判定する.

					// 取得したIDごとに処理を分岐.
					// Edit1のイベント発生時.
					case ID_EDIT1:

						// ID_EDIT1ブロック.
						{

							// 通知コードごとに分岐.
							switch (HIWORD(wParam)){

								// EN_SETFOCUSの時.
								case EN_SETFOCUS:

									{

										// "ID_EDIT1 EN_SETFOCUS"とデバッグ出力.
										OutputDebugString(_T("ID_EDIT1 EN_SETFOCUS\n"));

									}

									// 既定の処理へ向かう.
									break;

								// EN_CHANGEの時.
								case EN_CHANGE:

									// EN_CHANGEブロック.
									{

										// "ID_EDIT1 EN_CHANGE"とデバッグ出力.
										//OutputDebugString(_T("ID_EDIT1 EN_CHANGE\n"));

									}

									// 既定の処理へ向かう.
									break;

								// EN_UPDATEの時.
								case EN_UPDATE:

									// EN_UPDATEブロック.
									{

										// "ID_EDIT1 EN_UPDATE"とデバッグ出力.
										//OutputDebugString(_T("ID_EDIT1 EN_UPDATE\n"));
										
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