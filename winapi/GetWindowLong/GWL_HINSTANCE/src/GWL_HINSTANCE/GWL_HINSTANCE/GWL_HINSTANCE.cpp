// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// C標準入出力
#include <string.h>		// C文字列処理

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理をするように定義したコールバック関数WindowProc.
LRESULT CALLBACK WindowProc2(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理をするように定義したコールバック関数WindowProc2.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;						// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;						// ウィンドウメッセージ情報を格納するMSG構造体型変数msg.
	WNDCLASS wc;					// ウィンドウクラス情報をもつWNDCLASS構造体型変数wc.
	WNDCLASS wc2;					// ウィンドウクラス情報をもつWNDCLASS構造体型変数wc2.
	TCHAR tszHInstance[256] = {0};	// アプリケーションインスタンスハンドル文字列tszHInstance(長さ256)を{0}で初期化.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("GWL_HINSTANCE");					// ウィンドウクラス名は"GWL_HINSTANCE".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;							// ウィンドウプロシージャは独自の処理を定義したWindowProc.
	wc.hInstance = hInstance;								// インスタンスハンドルは_tWinMainの引数.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// アイコンはアプリケーション既定のもの.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// カーソルは矢印.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 背景は白ブラシ.
	wc.lpszMenuName = NULL;									// なし
	wc.cbClsExtra = 0;										// 0でいい.
	wc.cbWndExtra = 0;										// 0でいい.

	// アプリケーションインスタンスハンドル文字列の表示.
	_stprintf(tszHInstance, _T("_tWinMain#hInstance = 0x%08x"), (unsigned long)hInstance);	// hInstanceを文字列に変換.
	MessageBox(NULL, tszHInstance, _T("GWL_HINSTANCE"), MB_OK);	// MessageBoxでtszHInstanceを表示.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)) {	// RegisterClassでウィンドウクラスを登録し, 0が返ったらエラー.

		// エラー処理
		MessageBox(NULL, _T("RegisterClass Failure!"), _T("GWL_HINSTANCE"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass Failure!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// 子ウィンドウクラスの設定
	wc2.lpszClassName = _T("Child_Window");						// ウィンドウクラス名は"Child_Window".
	wc2.style = CS_HREDRAW | CS_VREDRAW;						// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc2.lpfnWndProc = WindowProc2;								// ウィンドウプロシージャは独自の処理を定義したWindowProc2.
	wc2.hInstance = hInstance;									// インスタンスハンドルは_tWinMainの引数.
	wc2.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// アイコンはアプリケーション既定のもの.
	wc2.hCursor = LoadCursor(NULL, IDC_ARROW);					// カーソルは矢印.
	wc2.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 背景は白ブラシ.
	wc2.lpszMenuName = NULL;										// なし
	wc2.cbClsExtra = 0;											// 0でいい.
	wc2.cbWndExtra = 0;											// 0でいい.

	// 子ウィンドウクラスの登録
	if (!RegisterClass(&wc2)) {	// RegisterClassで子ウィンドウクラスを登録し, 0が返ったらエラー.

		// エラー処理
		MessageBox(NULL, _T("RegisterClass Failure!"), _T("GWL_HINSTANCE"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass Failure!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("GWL_HINSTANCE"), _T("GWL_HINSTANCE"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"GWL_HINSTANCE"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL) {	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow Failure!"), _T("GWL_HINSTANCE"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow Failure!"とエラーメッセージを表示.
		return -3;	// 異常終了(3)

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.

	// メッセージループ
	while (GetMessage(&msg, NULL, 0, 0) > 0) {	// GetMessageでメッセージを取得, 戻り値が0より大きい間はループし続ける.

		// ウィンドウメッセージ処理
		TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.
		DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(この場合は独自に定義したWindowProc)に送出.

	}

	// プログラムの終了
	return (int)msg.wParam;	// 終了コード(msg.wParam)を戻り値として返す.

}

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {	// ウィンドウメッセージに対して独自の処理をするように定義したウィンドウプロシージャ.

	// ウィンドウメッセージに対する処理.
	switch (uMsg) {	// switch-casa文でuMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始された時.
		case WM_CREATE:		// ウィンドウの作成が開始された時.(uMsgがWM_CREATEの時.)

			// WM_CREATEブロック
			{

				// 変数の初期化
				HINSTANCE hInstance;	// アプリケーションインスタンスハンドルhInstance.
				TCHAR tszHInstance[256] = {0};	// アプリケーションインスタンスハンドル文字列tszHInstance(長さ256)を{0}で初期化.

				// アプリケーションインスタンスハンドル文字列の表示.
				hInstance = (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE);	// GetWindowLongにGWL_HINSTANCEを指定してhInstanceを取得.
				_stprintf(tszHInstance, _T("WindowProc#hInstance = 0x%08x"), (unsigned long)hInstance);	// hInstanceを文字列に変換.
				MessageBox(NULL, tszHInstance, _T("GWL_HINSTANCE"), MB_OK);	// MessageBoxでtszHInstanceを表示.

				// 子ウィンドウの作成(子ウィンドウなので明示的な破棄は不要.)
				CreateWindow(_T("Child_Window"), _T("GWL_HINSTANCE"), WS_CHILD | WS_VISIBLE | WS_BORDER, 100, 100, 200, 200, hwnd, (HMENU)WM_APP + 1, hInstance, NULL);	// CreateWindowでhwndを親とする子ウィンドウの作成.(取得したhInstanceを指定.)

				// ウィンドウ作成成功
				return 0;	// return文で0を返して, ウィンドウ作成成功とする.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// ウィンドウが破棄された時.
		case WM_DESTROY:	// ウィンドウが破棄された時.(uMsgがWM_DESTROYの時.)

			// WM_DESTROYブロック
			{

				// 終了メッセージの送信.
				PostQuitMessage(0);	// PostQuitMessageで終了コードを0としてWM_QUITメッセージを送信.(するとメッセージループのGetMessageの戻り値が0になるので, メッセージループから抜ける.)

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// 上記以外の時.
		default:	// 上記以外の値の時の既定処理.

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

	}

	// あとは既定の処理に任せる.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// 戻り値も含めDefWindowProcに既定の処理を任せる.

}

// WindowProc2関数の定義
LRESULT CALLBACK WindowProc2(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {	// ウィンドウメッセージに対して独自の処理をするように定義したウィンドウプロシージャ.

	// ウィンドウメッセージに対する処理.
	switch (uMsg) {	// switch-casa文でuMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始された時.
		case WM_CREATE:		// ウィンドウの作成が開始された時.(uMsgがWM_CREATEの時.)

			// WM_CREATEブロック
			{

				// ウィンドウ作成成功
				return 0;	// return文で0を返して, ウィンドウ作成成功とする.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// 上記以外の時.
		default:	// 上記以外の値の時の既定処理.

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

	}

	// あとは既定の処理に任せる.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// 戻り値も含めDefWindowProcに既定の処理を任せる.

}