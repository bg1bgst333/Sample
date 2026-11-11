// ヘッダファイルのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <commctrl.h>	// コモンコントロール
#include <stddef.h>		// offsetofマクロ

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
	wc.lpszClassName = _T("REBARCLASSNAME");						// ウィンドウクラス名は"REBARCLASSNAME".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("REBARCLASSNAME"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("REBARCLASSNAME"), _T("REBARCLASSNAME"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"REBARCLASSNAME"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL) {	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("REBARCLASSNAME"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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

				// 変数の宣言
				INITCOMMONCONTROLSEX icex;	// 初期化するコモンコントロールの種類を指定するINITCOMMONCONTROLSEX構造体型変数.

				// コモンコントロールの初期化
				icex.dwSize = sizeof(INITCOMMONCONTROLSEX);	// dwSizeは構造体自身のサイズ.
				icex.dwICC = ICC_COOL_CLASSES;					// dwICCにICC_COOL_CLASSESを指定.(REBARCLASSNAMEは, 旧来のInitCommonControlsが初期化する既定セットには含まれておらず, InitCommonControlsExで明示的に指定する必要がある.)
				InitCommonControlsEx(&icex);					// InitCommonControlsExでコモンコントロールを初期化.

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
				HWND hWndRebar;		// リバーコントロールのウィンドウハンドルを格納するHWND型変数.
				HWND hWndButton0;	// 1個目のバンドに載せるボタンのウィンドウハンドルを格納するHWND型変数.
				HWND hWndButton1;	// 2個目のバンドに載せるボタンのウィンドウハンドルを格納するHWND型変数.
				HINSTANCE hInstance;	// アプリケーションインスタンスハンドル.
				REBARBANDINFO rbbi;	// バンド1個分の情報を格納するREBARBANDINFO構造体型変数.

				// リバーコントロールのウィンドウハンドルを取得
				hWndRebar = GetDlgItem(hwndDlg, IDC_REBAR);	// GetDlgItemでIDC_REBARのウィンドウハンドルを取得.

				// hInstanceを取得
				hInstance = (HINSTANCE)GetWindowLong(hwndDlg, GWL_HINSTANCE);	// GetWindowLongでアプリケーションインスタンスハンドルを取得し, hInstanceに格納.

				// バンドに載せる子ウィンドウ(ボタン)を2個作成する.(バンドの親はリバーコントロール自身にする.)
				hWndButton0 = CreateWindow(_T("BUTTON"), _T("Button0"), WS_CHILD | WS_VISIBLE, 0, 0, 80, 22, hWndRebar, (HMENU)IDC_BUTTON0, hInstance, NULL);	// CreateWindowで1個目のボタンを作成.(親はhWndRebar.)
				hWndButton1 = CreateWindow(_T("BUTTON"), _T("Button1"), WS_CHILD | WS_VISIBLE, 0, 0, 80, 22, hWndRebar, (HMENU)IDC_BUTTON1, hInstance, NULL);	// CreateWindowで2個目のボタンを作成.(親はhWndRebar.)

				// 1個目のバンドを組み立てて挿入する.
				ZeroMemory(&rbbi, sizeof(rbbi));	// ZeroMemoryで構造体をゼロクリア.
				rbbi.cbSize = (UINT)(offsetof(REBARBANDINFO, cx) + sizeof(UINT));	// cbSizeは, cxメンバまでの旧バージョンのREBARBANDINFOサイズ(環境によっては48)を明示的に指定する.(マニフェストでCOMCTL32 v6を宣言していない環境では, sizeof(REBARBANDINFO)そのまま(新しいhbmBack以降のメンバを含む全サイズ)を渡すと, バージョン不一致でRB_INSERTBANDが常に失敗する.)
				rbbi.fMask = RBBIM_TEXT | RBBIM_CHILD | RBBIM_CHILDSIZE | RBBIM_SIZE | RBBIM_STYLE;	// fMaskで, 今回設定するメンバ(表示文字列・子ウィンドウ・子ウィンドウサイズ・バンド幅・スタイル)を指定.
				rbbi.fStyle = RBBS_CHILDEDGE | RBBS_GRIPPERALWAYS;	// fStyleで, 子ウィンドウの周りに枠を付け(RBBS_CHILDEDGE), 常にグリップ(つまみ)を表示する(RBBS_GRIPPERALWAYS)ことを指定.
				rbbi.lpText = _T("Band0");	// lpTextにバンドの表示文字列を指定.
				rbbi.hwndChild = hWndButton0;	// hwndChildにバンドへ載せる子ウィンドウを指定.
				rbbi.cxMinChild = 80;	// cxMinChildに子ウィンドウの最小幅を指定.
				rbbi.cyMinChild = 22;	// cyMinChildに子ウィンドウの最小高さを指定.
				rbbi.cx = 150;			// cxにバンド自体の幅を指定.
				SendMessage(hWndRebar, RB_INSERTBAND, (WPARAM)-1, (LPARAM)&rbbi);	// SendMessageにRB_INSERTBANDを指定し, 末尾(-1)にバンドを挿入.(RebarにはTabCtrl_InsertItemのような専用マクロが無いので, SendMessageを直接使う.)

				// 2個目のバンドを組み立てて挿入する.
				ZeroMemory(&rbbi, sizeof(rbbi));	// ZeroMemoryで構造体をゼロクリア.
				rbbi.cbSize = (UINT)(offsetof(REBARBANDINFO, cx) + sizeof(UINT));	// cbSizeは1個目と同じく旧バージョンサイズを指定.
				rbbi.fMask = RBBIM_TEXT | RBBIM_CHILD | RBBIM_CHILDSIZE | RBBIM_SIZE | RBBIM_STYLE;	// fMaskで, 今回設定するメンバを指定.
				rbbi.fStyle = RBBS_CHILDEDGE | RBBS_GRIPPERALWAYS;	// fStyleで, 1個目と同じスタイルを指定.
				rbbi.lpText = _T("Band1");	// lpTextにバンドの表示文字列を指定.
				rbbi.hwndChild = hWndButton1;	// hwndChildにバンドへ載せる子ウィンドウを指定.
				rbbi.cxMinChild = 80;	// cxMinChildに子ウィンドウの最小幅を指定.
				rbbi.cyMinChild = 22;	// cyMinChildに子ウィンドウの最小高さを指定.
				rbbi.cx = 150;			// cxにバンド自体の幅を指定.
				SendMessage(hWndRebar, RB_INSERTBAND, (WPARAM)-1, (LPARAM)&rbbi);	// SendMessageにRB_INSERTBANDを指定し, 末尾(-1)にバンドを挿入.

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

		// 上記以外の場合.
		default:

			// 抜ける.
			break;	// breakで抜ける.

	}

	// ここに来たときは処理できていない.
	return FALSE;	// 処理できていないのでFALSE.

}
