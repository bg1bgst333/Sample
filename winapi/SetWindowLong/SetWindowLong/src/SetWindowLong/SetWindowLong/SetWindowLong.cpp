// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <commctrl.h>	// コモンコントロール

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理をするように定義したコールバック関数WindowProc.
LRESULT CALLBACK ChildWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// 子ウィンドウ用コールバック関数ChildWindowProc.
LRESULT CALLBACK ThirdWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// 入れ替え用コールバック関数ThirdWindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;			// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;			// ウィンドウメッセージ情報を格納するMSG構造体型変数msg.
	WNDCLASS wc;		// ウィンドウクラス情報をもつWNDCLASS構造体型変数wc.
	WNDCLASS wcChild;	// 子ウィンドウクラス情報をもつWNDCLASS構造体型変数wcChild.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("SetWindowLong");					// ウィンドウクラス名は"SetWindowLong".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;							// ウィンドウプロシージャは独自の処理を定義したWindowProc.
	wc.hInstance = hInstance;								// インスタンスハンドルは_tWinMainの引数.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// アイコンはアプリケーション既定のもの.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// カーソルは矢印.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 背景は白ブラシ.
	wc.lpszMenuName = NULL;									// なし
	wc.cbClsExtra = 0;										// 0でいい.
	wc.cbWndExtra = 0;										// 0でいい.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)) {	// RegisterClassでウィンドウクラスを登録し, 0が返ったらエラー.

		// エラー処理
		MessageBox(NULL, _T("RegisterClass Failure!"), _T("SetWindowLong"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass Failure!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// 子ウィンドウクラスの設定
	wcChild.lpszClassName = _T("Child_Window");						// ウィンドウクラス名は"Child_Window".
	wcChild.style = CS_HREDRAW | CS_VREDRAW;						// スタイルはCS_HREDRAW | CS_VREDRAW.
	wcChild.lpfnWndProc = ChildWindowProc;							// ウィンドウプロシージャは独自のChildWindowProc.
	wcChild.hInstance = hInstance;									// インスタンスハンドルは_tWinMainの引数.
	wcChild.hIcon = NULL;											// アイコンはなし.
	wcChild.hCursor = LoadCursor(NULL, IDC_ARROW);					// カーソルは矢印.
	wcChild.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);	// 背景は淡灰色ブラシ.
	wcChild.lpszMenuName = NULL;									// なし
	wcChild.cbClsExtra = 0;											// 0でいい.
	wcChild.cbWndExtra = 0;											// 0でいい.

	// 子ウィンドウクラスの登録
	if (!RegisterClass(&wcChild)) {	// RegisterClassでウィンドウクラスを登録し, 0が返ったらエラー.

		// エラー処理
		MessageBox(NULL, _T("RegisterClass Failure!"), _T("SetWindowLong"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass Failure!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("SetWindowLong"), _T("SetWindowLong"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"SetWindowLong"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL) {	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow Failure!"), _T("SetWindowLong"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow Failure!"とエラーメッセージを表示.
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

	// ウィンドウプロシージャ全体で使われるスタティック変数の初期化.
	static HWND hWndChild = NULL;	// 子ウィンドウハンドルhWndChildをNULLで初期化.

	// ウィンドウメッセージに対する処理.
	switch (uMsg) {	// switch-casa文でuMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始された時.
		case WM_CREATE:		// ウィンドウの作成が開始された時.(uMsgがWM_CREATEの時.)

			// WM_CREATEブロック
			{

				// 変数の宣言と初期化.
				LPCREATESTRUCT lpCreateStruct;	// CREATESTRUCT構造体ポインタlpCreateStruct.

				// スタティックコントロールの作成.
				lpCreateStruct = (LPCREATESTRUCT)lParam;	// lParamをLPCREATESTRUCTにキャストし, lpCreateStructに格納.
				hWndChild = CreateWindow(_T("Child_Window"), _T("SetWindowLong"), WS_CHILD | WS_VISIBLE | WS_BORDER, 100, 100, 200, 200, hwnd, (HMENU)WM_APP + 1, lpCreateStruct->hInstance, NULL);	// CreateWindowでウィンドウ"SetWindowLong"を作成し, 戻り値のウィンドウハンドルをhWndChildに格納.

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

		// マウスの左ボタンが押された時.
		case WM_LBUTTONDOWN:	// マウスの左ボタンが押された時.(uMsgがWM_LBUTTONDOWNの時.)

			// WM_LBUTTONDOWNブロック
			{

				// ウィンドウプロシージャの入れ替え.
				SetWindowLong(hWndChild, GWL_WNDPROC, (LONG)ThirdWindowProc);	// SetWindowLongでhWndChildのウィンドウプロシージャとしてThirdWindowProcをセット.
				MessageBox(NULL, _T("Changed!"), _T("SetWindowLong"), MB_OK);	// MessageBoxで"Changed!"と表示.

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

// ChildWindowProc関数の定義
LRESULT CALLBACK ChildWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {	// ウィンドウメッセージに対して独自の処理をするように定義したウィンドウプロシージャ.

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-casa文でuMsgの値ごとに処理を振り分ける.

		// マウスの左ボタンが押された時.
		case WM_LBUTTONDOWN:	// マウスの左ボタンが押された時.(uMsgがWM_LBUTTONDOWNの時.)

			// WM_LBUTTONDOWNブロック
			{

				// "ChildWindowProc#Clicked!"と表示.
				MessageBox(NULL, _T("ChildWindowProc#Clicked!"), _T("SetWindowLong"), MB_OK);	// MessageBoxで"ChildWindowProc#Clicked!"と表示.

			}

		// 上記以外の時.
		default:	// 上記以外の値の時の既定処理.

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

	}

	// あとは既定の処理に任せる.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// 戻り値も含めDefWindowProcに既定の処理を任せる.

}

// ThirdWindowProc関数の定義
LRESULT CALLBACK ThirdWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {	// ウィンドウメッセージに対して独自の処理をするように定義したウィンドウプロシージャ.

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-casa文でuMsgの値ごとに処理を振り分ける.

		// マウスの左ボタンが押された時.
		case WM_LBUTTONDOWN:	// マウスの左ボタンが押された時.(uMsgがWM_LBUTTONDOWNの時.)

			// WM_LBUTTONDOWNブロック
			{

				// "ThirdWindowProc#Clicked!"と表示.
				MessageBox(NULL, _T("ThirdWindowProc#Clicked!"), _T("SetWindowLong"), MB_OK);	// MessageBoxで"ThirdWindowProc#Clicked!"と表示.

			}

		// 上記以外の時.
		default:	// 上記以外の値の時の既定処理.

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

	}

	// あとは既定の処理に任せる.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// 戻り値も含めDefWindowProcに既定の処理を任せる.

}