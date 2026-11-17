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
HWND g_hWndStatic = NULL;	// クリック結果を表示するSTATICのウィンドウハンドルを格納するHWND型変数g_hWndStatic.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// 変数の宣言
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージを格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラスを格納するWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("WC_LINK");						// ウィンドウクラス名は"WC_LINK".(組み込みのSysLinkクラスと名前が衝突しないようにしている.)
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("WC_LINK"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("WC_LINK"), _T("WC_LINK"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 940, 200, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"WC_LINK"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL) {	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("WC_LINK"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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
				icex.dwICC = ICC_LINK_CLASS;				// dwICCにICC_LINK_CLASSを指定.(SysLinkを使うために必要.)
				InitCommonControlsEx(&icex);				// InitCommonControlsExでコモンコントロールを初期化.

				// SysLinkの作成. <a id="..." href="...">で, クリック時にIDとURLを受け取れる.
				g_hWndLink = CreateWindowEx(0, WC_LINK,
					_T("参考: <a id=\"msdn\" href=\"https://learn.microsoft.com/ja-jp/windows/win32/controls/syslink-control\">MSDN</a> / <a id=\"gh\" href=\"https://github.com/bg1bgst333/Sample\">GitHub</a>"),
					WS_CHILD | WS_VISIBLE | WS_TABSTOP,
					10, 10, 920, 40, hwnd, NULL, ((LPCREATESTRUCT)lParam)->hInstance, NULL);	// SysLinkを, 親ウィンドウhwndの子として作成.

				// クリック結果を表示するSTATICの作成.
				g_hWndStatic = CreateWindowEx(0, _T("STATIC"), _T("リンクをクリックしてください。"),
					WS_CHILD | WS_VISIBLE,
					10, 60, 920, 50, hwnd, NULL, ((LPCREATESTRUCT)lParam)->hInstance, NULL);	// STATICを, 親ウィンドウhwndの子として作成.

				// ウィンドウ作成続行
				return 0;	// returnして0を返すと, ウィンドウ作成を続けるとする.

			}

			// 既定の処理へ続ける.
			break;	// breakで抜けると, 既定の処理(DefWindowProc)へ続ける.

		// リンクなどの通知を受け取ったとき.
		case WM_NOTIFY:		// 子コントロールから通知が来たとき.(uMsgがWM_NOTIFYの場合.)

			// WM_NOTIFYブロック
			{

				// 通知元のヘッダを取得.
				NMHDR *pnmhdr = (NMHDR *)lParam;	// lParamはNMHDR構造体へのポインタ.

				// SysLinkのクリック通知の場合.
				if (pnmhdr->hwndFrom == g_hWndLink && (pnmhdr->code == NM_CLICK || pnmhdr->code == NM_RETURN)) {

					// クリックされたリンクの情報を取得.
					NMLINK *pnmlink = (NMLINK *)lParam;	// NMLINK構造体へのポインタ. (lParamは同じアドレス.)
					WCHAR szText[512];					// 表示用の文字列バッファ.

					// IDとURLを表示.
					wsprintfW(szText, L"クリックされたリンク: ID=%s URL=%s", pnmlink->item.szID, pnmlink->item.szUrl);	// wsprintfWで, リンクのIDとURLを文字列にする.
					SetWindowTextW(g_hWndStatic, szText);	// STATICの文字列を書き換える.

					// 処理したので0を返す.
					return 0;

				}

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

		// 上記以外の場合.
		default:

			// 既定の処理へ続ける.
			break;	// breakで抜けると, 既定の処理(DefWindowProc)へ続ける.

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}