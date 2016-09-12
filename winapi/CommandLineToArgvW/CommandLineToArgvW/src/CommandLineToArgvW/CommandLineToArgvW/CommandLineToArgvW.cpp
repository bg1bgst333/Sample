// ヘッダのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <string.h>		// C文字列処理

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// 独自のウィンドウプロシージャWindowProc.

// グローバル変数の宣言
int iArgc = 0;	// 引数の数iArgcを0に初期化.
LPTSTR *lplptszArgs = NULL;	// 引数文字列配列へのポインタlplptszArgsをNULLに初期化.

// _tWindMain関数
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// 変数の宣言
	HWND hWnd;		// ウィンドウハンドルhWnd
	MSG msg;		// ウィンドウメッセージ情報msg
	WNDCLASS wc;	// ウィンドウクラスwc

	// 引数文字列のパース
	lplptszArgs = CommandLineToArgvW(GetCommandLine(), &iArgc);	// CommandLineToArgvWでGetCommandLineで取得した引数文字列をパースして, 1つ1つの引数文字列配列へのポインタを返す.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("CommandLineToArgvW");			// 独自に定義したウィンドウクラス"CommandLineToArgvW".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// とりあえずCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;							// 独自に定義したウィンドウプロシージャWindowProc.
	wc.hInstance = hInstance;								// インスタンスハンドルhInstanceを指定.
	wc.hIcon = LoadIcon(hInstance, IDI_APPLICATION);		// アプリケーション既定アイコンIDI_APPLICATION.
	wc.hCursor = LoadCursor(hInstance, IDC_ARROW);			// 既定の矢印カーソル.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 背景は白(WHITE_BRUSH).
	wc.lpszMenuName = NULL;									// メニューはなし.
	wc.cbClsExtra = 0;										// 0でいい.
	wc.cbWndExtra = 0;										// 0でいい.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)){	// RegisterClassでウィンドウクラスを登録し, 0が返ったらエラー.

		// エラー処理
		MessageBox(NULL, _T("RegisterClass failed!"), _T("CommandLineToArgvW"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("CommandLineToArgvW"), _T("CommandLineToArgvW"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"CommandLineToArgvW"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("CommandLineToArgvW"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.

	// メッセージループ
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessageでメッセージを取得, 戻り値が0より大きい間はループし続ける.

		// ウィンドウメッセージの送出
		TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.
		DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(この場合は独自に定義したWindowProc)に送出.

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

				// 終了メッセージの送信.
				PostQuitMessage(0);	// PostQuitMessageで終了コードを0としてWM_QUITメッセージを送信.(するとメッセージループのGetMessageの戻り値が0になるので, メッセージループから抜ける.)
 
			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// 画面の描画を要求された時.
		case WM_PAINT:		// 画面の描画を要求された時.(uMsgがWM_PAINTの時.)
 
			// WM_PAINTブロック
			{
 
				// このブロックのローカル変数の宣言.
				HDC hDC;	// デバイスコンテキストハンドルを格納するHDC型変数hDC.
				PAINTSTRUCT ps;		// ペイント情報を管理するPAINTSTRUCT構造体型の変数ps.
				int i;	// int型ループ変数i.

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にはデバイスコンテキストハンドルが返るので, hDCに格納.

				// コマンドライン引数の描画
				for (i = 0; i < iArgc; i++){	// iArgcの数だけ描画.

					// lplptszArgsの指す引数配列を描画.
					TextOut(hDC, 0, i * 50, lplptszArgs[i], (int)_tcslen(lplptszArgs[i]));	// TextOutでlplptszArgs[i]を描画.

				}

				// ウィンドウの描画終了
				EndPaint(hwnd, &ps);	// EndPaintでこのウィンドウの描画処理を終了する.
 
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