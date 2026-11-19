// ヘッダファイルのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <commctrl.h>	// コモンコントロール

// 独自のヘッダファイル
#include "resource.h"	// リソースID

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理ができるように定義するコールバック関数WindowProc.

// 子コントロールのウィンドウハンドル
HWND g_hWndLink = NULL;		// SysLinkのウィンドウハンドルを格納するHWND型変数g_hWndLink.
HWND g_hWndStatic = NULL;	// 判定結果を表示するSTATICのウィンドウハンドルを格納するHWND型変数g_hWndStatic.

// SysLinkを作成するときの高さ.
#define LINK_HEIGHT	40	// SysLinkの高さLINK_HEIGHT.

// マウス位置を調べるタイマーのID.
#define TIMER_ID_HITTEST	1	// タイマーのIDTIMER_ID_HITTEST.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// 変数の宣言
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージを格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラスを格納するWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("LM_HITTEST");						// ウィンドウクラス名は"LM_HITTEST".
	wc.style = CS_HREDRAW | CS_VREDRAW;							// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;								// ウィンドウプロシージャは独自の処理を定義したWindowProc.
	wc.hInstance = hInstance;									// インスタンスハンドルは_tWinMainの引数.
	wc.hIcon = LoadIcon(hInstance, IDI_APPLICATION);			// アイコンはアプリケーション既定のもの.
	wc.hCursor = LoadCursor(hInstance, IDC_ARROW);				// カーソルは矢印.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		// 背景は白ブラシ.
	wc.lpszMenuName = NULL;										// メニューは無し.
	wc.cbClsExtra = 0;											// 0でよい.
	wc.cbWndExtra = 0;											// 0でよい.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)) {	// RegisterClassでウィンドウクラスを登録し, 0が返ってきたらエラー.

		// エラー処理
		MessageBox(NULL, _T("RegisterClass failed!"), _T("LM_HITTEST"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("LM_HITTEST"), _T("LM_HITTEST"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 940, 200, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"LM_HITTEST"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL) {	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("LM_HITTEST"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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
				INITCOMMONCONTROLSEX icex;		// 初期化するコモンコントロールの種類を指定するINITCOMMONCONTROLSEX構造体型変数.
				HINSTANCE hInst;				// アプリケーションインスタンスハンドル.

				// コモンコントロールの初期化
				icex.dwSize = sizeof(INITCOMMONCONTROLSEX);	// dwSizeは構造体自身のサイズ.
				icex.dwICC = ICC_LINK_CLASS;				// dwICCにICC_LINK_CLASSを指定.(SysLinkを使うために必要.)
				InitCommonControlsEx(&icex);				// InitCommonControlsExでコモンコントロールを初期化.

				// インスタンスハンドルを取得.
				hInst = ((LPCREATESTRUCT)lParam)->hInstance;	// 作成時の情報からインスタンスハンドルを取得.

				// SysLinkの作成.
				g_hWndLink = CreateWindowEx(0, WC_LINK,
					_T("参考: <a id=\"msdn\" href=\"https://learn.microsoft.com/ja-jp/windows/win32/controls/syslink-overview\">MSDN</a> / <a id=\"gh\" href=\"https://github.com/bg1bgst333/Sample\">GitHub</a>"),
					WS_CHILD | WS_VISIBLE | WS_TABSTOP,
					10, 10, 920, LINK_HEIGHT, hwnd, NULL, hInst, NULL);	// SysLinkを, 親ウィンドウhwndの子として作成.

				// 判定結果を表示するSTATICの作成.
				g_hWndStatic = CreateWindowEx(0, _T("STATIC"), _T("リンクの上にマウスを移動してください。"),
					WS_CHILD | WS_VISIBLE,
					10, 60, 920, 50, hwnd, NULL, hInst, NULL);	// STATICを, 親ウィンドウhwndの子として作成.

				// 100ミリ秒ごとにマウス位置を調べるタイマーを作成.
				SetTimer(hwnd, TIMER_ID_HITTEST, 100, NULL);	// SetTimerで, 100ミリ秒間隔のタイマーを作成.

				// ウィンドウ作成続行
				return 0;	// returnして0を返すと, ウィンドウ作成を続けるとする.

			}

			// 既定の処理へ続ける.
			break;	// breakで抜けると, 既定の処理(DefWindowProc)へ続ける.

		// タイマーが発生したとき.
		case WM_TIMER:		// タイマーが発生したとき.(uMsgがWM_TIMERの場合.)

			// WM_TIMERブロック
			{

				// 変数の宣言
				POINT pt;				// マウスのスクリーン座標を格納するPOINT構造体型変数pt.
				LHITTESTINFO lhti;		// LM_HITTESTに渡す判定情報を格納するLHITTESTINFO構造体型変数lhti.
				BOOL bHit;				// 判定結果を格納するBOOL型変数bHit.
				static WCHAR s_szLastHit[512];	// 最後にヒットしたリンクの表示文字列.
				WCHAR szText[512];		// 表示用の文字列バッファ.

				// マウスのスクリーン座標を取得し, SysLinkのクライアント座標に変換.
				GetCursorPos(&pt);					// GetCursorPosでマウスのスクリーン座標を取得.
				ScreenToClient(g_hWndLink, &pt);	// ScreenToClientで, SysLinkのクライアント座標に変換.

				// LM_HITTESTで, その座標にあるリンクを判定.
				ZeroMemory(&lhti, sizeof(lhti));						// lhtiをゼロクリア.
				lhti.pt = pt;											// 判定する座標をptに指定.
				lhti.item.mask = LIF_ITEMINDEX | LIF_ITEMID | LIF_URL;	// 取得する項目としてインデックス・IDとURLを指定.
				bHit = (BOOL)SendMessage(g_hWndLink, LM_HITTEST, 0, (LPARAM)&lhti);	// LM_HITTESTで, 座標にリンクがあればTRUEを返す.

				// 判定結果を表示.
				if (bHit) {	// リンクの上にある場合.

					// リンクのIDとURLを表示.
					LITEM li;						// ヒットしたリンクの情報を格納するLITEM構造体型変数li.
					ZeroMemory(&li, sizeof(li));	// liをゼロクリア.
					li.mask = LIF_ITEMINDEX | LIF_ITEMID | LIF_URL;	// 取得する項目としてインデックス・IDとURLを指定.
					li.iLink = lhti.item.iLink;		// LM_HITTESTで判定されたリンクの番号を指定.
					SendMessage(g_hWndLink, LM_GETITEM, 0, (LPARAM)&li);	// LM_GETITEMで, そのリンクのIDとURLを取得.
					wsprintfW(s_szLastHit, L"LM_HITTEST: ヒット ID=%s URL=%s", li.szID, li.szUrl);	// 取得したIDとURLを最後のヒットとして保存する.
					wsprintfW(szText, L"%s", s_szLastHit);	// 表示用の文字列にもコピーする.

				} else {	// リンクの外にある場合.

					// リンクの外であることを表示.
					wsprintfW(szText, (s_szLastHit[0] == L'\0') ? L"LM_HITTEST: まだヒットしていない（現在はリンクの外）" : L"%s（現在はリンクの外）", s_szLastHit);	// 最後のヒットがあればそれを表示し, 現在はリンクの外であることを添える.

				}

				// 表示欄の文字列を更新.
				SetWindowTextW(g_hWndStatic, szText);	// STATICの文字列を書き換える.

			}

			// 既定の処理へ続ける.
			break;	// breakで抜けると, 既定の処理(DefWindowProc)へ続ける.

		// ウィンドウが破棄されたとき.
		case WM_DESTROY:	// ウィンドウが破棄されたとき.(uMsgがWM_DESTROYの場合.)

			// WM_DESTROYブロック
			{

				// タイマーを止める.
				KillTimer(hwnd, TIMER_ID_HITTEST);	// KillTimerで, 作成したタイマーを停止.

				// メッセージループを抜ける.
				PostQuitMessage(0);	// PostQuitMessageで終了コードを0とするWM_QUITメッセージを送信.

			}

			// 既定の処理へ続ける.
			break;	// breakで抜けると, 既定の処理(DefWindowProc)へ続ける.

		// 上記以外の場合.
		default:

			// 既定の処理へ続ける.
			break;	// breakで抜けると, 既定の処理(DefWindowProc)へ続ける.

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}