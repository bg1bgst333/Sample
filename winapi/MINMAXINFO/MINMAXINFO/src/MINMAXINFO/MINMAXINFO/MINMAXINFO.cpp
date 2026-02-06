// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理をするように定義したコールバック関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージ情報を格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラス情報をもつWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("MINMAXINFO");						// ウィンドウクラス名は"MINMAXINFO".
	wc.style = CS_HREDRAW | CS_VREDRAW;							// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;								// ウィンドウプロシージャは独自の処理を定義したWindowProc.
	wc.hInstance = hInstance;									// インスタンスハンドルは_tWinMainの引数.
	wc.hIcon = LoadIcon(hInstance, IDI_APPLICATION);			// アイコンはアプリケーション既定のもの.
	wc.hCursor = LoadCursor(hInstance, IDC_ARROW);				// カーソルは矢印.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		// 背景は白ブラシ.
	wc.lpszMenuName = NULL;										// メニューは無し.
	wc.cbClsExtra = 0;											// 0でいい.
	wc.cbWndExtra = 0;											// 0でいい.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)){	// RegisterClassでウィンドウクラスを登録し, 0が返ったらエラー.

		// エラー処理
		MessageBox(NULL, _T("RegisterClass failed!"), _T("MINMAXINFO"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("MINMAXINFO"), _T("MINMAXINFO"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"MINMAXINFO"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("MINMAXINFO"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.

	// メッセージループ
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessageでメッセージを取得, 戻り値が0より大きい間はループし続ける.

		// ウィンドウメッセージの送出
		DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(この場合は独自に定義したWindowProc)に送出.
		TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.

	}

	// プログラムの終了
	return (int)msg.wParam;	// 終了コード(msg.wParam)を戻り値として返す.

}

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// ウィンドウメッセージに対して独自の処理をするように定義したウィンドウプロシージャ.

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-casa文でuMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始された時.
		case WM_CREATE:		// ウィンドウの作成が開始された時.(uMsgがWM_CREATEの時.)
		
			// WM_CREATEブロック
			{

				// ウィンドウ作成成功
				return 0;	// return文で0を返して, ウィンドウ作成成功とする.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// ウィンドウが破棄された時.
		case WM_DESTROY:	// ウィンドウが破棄された時.(uMsgがWM_DESTROYの時.)

			// WM_DESTROYブロック
			{

				// メッセージループを抜ける.
				PostQuitMessage(0);	// PostQuitMessageで抜ける.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりした時.
		case WM_COMMAND:	// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりした時.(uMsgがWM_COMMANDの時.)

			// WM_COMMANDブロック
			{

			}

		// ウィンドウのサイズ制限に関する情報をOSから要求された時.
		case WM_GETMINMAXINFO:

			// WM_GETMINMAXINFOブロック
			{

				// 最小サイズを(640, 480)にセット.
				MINMAXINFO *mmi = (MINMAXINFO *)lParam;
				mmi->ptMinTrackSize.x = 640;
				mmi->ptMinTrackSize.y = 480;

			}

		// それ以外の時.
		default:

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}
