// ヘッダファイルのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <commctrl.h>	// コモンコントロール

// 独自のヘッダファイル
#include "resource.h"	// リソースID

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理ができるように定義するコールバック関数WindowProc.
INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ダイアログの処理をするコールバック関数DialogProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// 変数の宣言
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージを格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラスを格納するWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("TRACKBAR_CLASS");						// ウィンドウクラス名は"TRACKBAR_CLASS".
	wc.style = CS_HREDRAW | CS_VREDRAW;							// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;								// ウィンドウプロシージャは独自の処理を定義したWindowProc.
	wc.hInstance = hInstance;									// インスタンスハンドルは_tWinMainの引数.
	wc.hIcon = LoadIcon(hInstance, IDI_APPLICATION);			// アイコンはアプリケーション既定のもの.
	wc.hCursor = LoadCursor(hInstance, IDC_ARROW);				// カーソルは矢印.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		// 背景は白ブラシ.
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MAINMENU);			// メニューにはIDR_MAINMENUをMAKEINTRESOURCEマクロで指定.
	wc.cbClsExtra = 0;											// 0でよい.
	wc.cbWndExtra = 0;											// 0でよい.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)) {	// RegisterClassでウィンドウクラスを登録し, 0が返ってきたらエラー.

		// エラー処理
		MessageBox(NULL, _T("RegisterClass failed!"), _T("TRACKBAR_CLASS"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("TRACKBAR_CLASS"), _T("TRACKBAR_CLASS"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"TRACKBAR_CLASS"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL) {	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("TRACKBAR_CLASS"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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

				// コモンコントロールの初期化
				InitCommonControls();	// InitCommonControlsでコモンコントロールを初期化.(TRACKBAR_CLASSを使うために必要.)

				// ウィンドウ作成続行
				return 0;	// returnして0を返すと, ウィンドウ作成を続けるとする.

			}

			// 既定の処理へ続ける.
			break;	// breakで抜けると, 既定の処理(DefWindowProc)へ続ける.

		// ウィンドウが破棄されたとき.
		case WM_DESTROY:	// ウィンドウが破棄されたとき.(uMsgがWM_DESTROYの場合.)

			// WM_DESTROYブロック
			{

				// メッセージループを抜ける.
				PostQuitMessage(0);	// PostQuitMessageで終了コードを0とするWM_QUITメッセージを送信.

			}

			// 既定の処理へ続ける.
			break;	// breakで抜けると, 既定の処理(DefWindowProc)へ続ける.

		// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりしたとき.
		case WM_COMMAND:	// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりしたとき.(uMsgがWM_COMMANDの場合.)

			// WM_COMMANDブロック
			{

				// どのメニュー項目が選択されたかを判定する.
				switch (LOWORD(wParam)) {	// LOWORD(wParam)で選択されたメニュー項目のIDが取得できるので, その値で判定する.

					// 取得したIDごとに処理を分岐.
					// Dialogが選択されたとき.
					case ID_DIALOG:

						// ID_DIALOGブロック
						{

							// 変数の宣言
							HINSTANCE hInstance;	// アプリケーションインスタンスハンドル

							// hInstanceを取得
							hInstance = (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE);	// GetWindowLongでアプリケーションインスタンスハンドルを取得し, hInstanceに格納.

							// ダイアログボックスの表示
							DialogBox(hInstance, MAKEINTRESOURCEW(IDD_DIALOG1), hwnd, DialogProc);	// DialogBoxでダイアログボックスを表示.(ダイアログの処理はDialogProcに書いてある.)

							// 0を返す.
							return 0;	// 処理したので戻り値として0を返す.

						}

						// 既定の処理へ続ける.
						break;	// breakで抜けると, 既定の処理(DefWindowProc)へ続ける.

						// 上記以外の場合.
					default:

						// 既定の処理へ続ける.
						break;	// breakで抜けると, 既定の処理(DefWindowProc)へ続ける.

				}

			}

		// 上記以外の場合.
		default:

			// 既定の処理へ続ける.
			break;	// breakで抜けると, 既定の処理(DefWindowProc)へ続ける.

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}

// DialogProc関数の定義
INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam) {	// ダイアログの処理をするコールバック関数.

	// ダイアログのメッセージ処理
	switch (uMsg) {	// uMsgの内容で判断.

		// ダイアログが初期化されたとき.
		case WM_INITDIALOG:	// ダイアログが初期化されたとき.(uMsgがWM_INITDIALOGの場合.)

			// WM_INITDIALOGブロック
			{

				// 変数の宣言
				HWND hWndTrackbar;	// トラックバーのウィンドウハンドルを格納するHWND型変数.

				// トラックバーのウィンドウハンドルを取得
				hWndTrackbar = GetDlgItem(hwndDlg, IDC_TRACKBAR1);	// GetDlgItemでIDC_TRACKBAR1のウィンドウハンドルを取得.

				// トラックバーの範囲と初期位置を設定
				SendMessage(hWndTrackbar, TBM_SETRANGE, TRUE, MAKELONG(0, 10));	// TBM_SETRANGEで範囲を0?10に設定.(wParamにTRUEを指定すると即座に再描画される.)
				SendMessage(hWndTrackbar, TBM_SETPOS, TRUE, 5);				// TBM_SETPOSで初期位置を5(中央)に設定.
				SetDlgItemText(hwndDlg, IDC_STATIC_POS, _T("pos = 5"));		// SetDlgItemTextで初期位置の表示テキストも合わせておく.

				// TRUEを返す.
				return TRUE;	// 成功できたのでTRUE.

			}

			// 抜ける.
			break;	// breakで抜ける.

		// ダイアログが閉じられたとき.
		case WM_CLOSE:	// ダイアログが閉じられたとき.(uMsgがWM_CLOSEの場合.)

			// WM_CLOSEブロック
			{

				// ダイアログを終了させる.
				EndDialog(hwndDlg, IDOK);	// EndDialogでダイアログを終了させる.

				// TRUEを返す.
				return TRUE;	// 処理できたのでTRUE.

			}

			// 抜ける.
			break;	// breakで抜ける.

		// トラックバーが操作されたとき.
		case WM_HSCROLL:	// トラックバーが操作されたとき.(uMsgがWM_HSCROLLの場合.)

			// WM_HSCROLLブロック
			{

				// 変数の宣言
				HWND hWndTrackbar;	// トラックバーのウィンドウハンドルを格納するHWND型変数.
				int iPos;			// トラックバーの現在位置を格納するint型変数.
				TCHAR tszBuffer[64];	// 表示文字列を組み立てるバッファ.
				LPCTSTR pszFormat;	// 表示の書式文字列.

				// トラックバーの現在位置を取得して, 常時表示用のテキストを更新する.
				hWndTrackbar = GetDlgItem(hwndDlg, IDC_TRACKBAR1);	// GetDlgItemでIDC_TRACKBAR1のウィンドウハンドルを取得.
				iPos = (int)SendMessage(hWndTrackbar, TBM_GETPOS, 0, 0);	// TBM_GETPOSで現在のつまみの位置を取得.(lParamがトラックバーのハンドルと一致するはずだが, 確実にIDで取り直す.)

				pszFormat = _T("pos = %d");	// 書式文字列.
				wsprintf(tszBuffer, pszFormat, iPos);	// wsprintfで表示文字列を組み立てる.
				SetDlgItemText(hwndDlg, IDC_STATIC_POS, tszBuffer);	// SetDlgItemTextでIDC_STATIC_POSのテキストを更新.(つまみを動かすたびに即座に反映される.)

				// 0を返す.
				return 0;	// 処理したので戻り値として0を返す.

			}

			// 抜ける.
			break;	// breakで抜ける.
		// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりし, コマンドが発生したとき.
		case WM_COMMAND:	// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりし, コマンドが発生したとき.(uMsgがWM_COMMANDの場合.)

			// WM_COMMANDブロック
			{

				// どのコントロールかを判定する.
				switch (LOWORD(wParam)) {	// LOWORD(wParam)でコントロールのリソースIDが取得できるので, その値で判定する.

					// Button1のとき.
					case ID_BUTTON1:

						// ID_BUTTON1ブロック
						{

							// 変数の宣言
							HWND hWndTrackbar;	// トラックバーのウィンドウハンドルを格納するHWND型変数.
							int iPos;			// トラックバーの現在位置を格納するint型変数.
							TCHAR tszBuffer[64];	// メッセージ文字列を組み立てるバッファ.
							LPCTSTR pszFormat;	// メッセージの書式文字列.

							// トラックバーの現在位置を取得して表示
							hWndTrackbar = GetDlgItem(hwndDlg, IDC_TRACKBAR1);	// GetDlgItemでIDC_TRACKBAR1のウィンドウハンドルを取得.
							iPos = (int)SendMessage(hWndTrackbar, TBM_GETPOS, 0, 0);	// TBM_GETPOSで現在のつまみの位置を取得.

							pszFormat = _T("TBM_GETPOS = %d");	// 書式文字列.
							wsprintf(tszBuffer, pszFormat, iPos);	// wsprintfでメッセージ文字列を組み立てる.
							MessageBox(hwndDlg, tszBuffer, _T("TRACKBAR_CLASS"), MB_OK);	// MessageBoxで現在位置を表示.

							// TRUEを返す.
							return TRUE;	// 処理できたのでTRUE.

						}

						// 既定の処理へ続ける.
						break;	// breakで抜ける.

					// 上記以外の場合.
					default:

						// 既定の処理へ続ける.
						break;	// breakで抜ける.

				}

			}

			// 抜ける.
			break;	// breakで抜ける.

		// 上記以外の場合.
		default:

			// 抜ける.
			break;	// breakで抜ける.

	}

	// ここに来たときは処理できていない.
	return FALSE;	// 処理できていないのでFALSE.

}
