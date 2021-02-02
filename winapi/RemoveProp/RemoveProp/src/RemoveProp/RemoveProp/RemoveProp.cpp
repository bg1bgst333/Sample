// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <string.h>		// C文字列処理

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理をするように定義したコールバック関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数・配列の宣言と初期化.
	HWND hWnd;							// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;							// ウィンドウメッセージ情報を格納するMSG構造体型変数msg.
	WNDCLASS wc;						// ウィンドウクラス情報をもつWNDCLASS構造体型変数wc.
	TCHAR tszUserData1[] = _T("ABCDE");	// TCHAR文字配列tszUserData1を"ABCDE"で初期化.
	TCHAR tszUserData2[] = _T("FGHIJ");	// TCHAR文字配列tszUserData2を"FGHIJ"で初期化.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("RemoveProp");					// ウィンドウクラス名は"RemoveProp".
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
		MessageBox(NULL, _T("RegisterClass Failure!"), _T("RemoveProp"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass Failure!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("RemoveProp"), _T("RemoveProp"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"RemoveProp"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL) {	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow Failure!"), _T("RemoveProp"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow Failure!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)

	}

	// ユーザデータのセット.
	SetProp(hWnd, _T("UserData1"), (HANDLE)tszUserData1);	// SetPropで"UserData1"をキーとして, tszUserData1を値としてセット.
	SetProp(hWnd, _T("UserData2"), (HANDLE)tszUserData2);	// SetPropで"UserData2"をキーとして, tszUserData2を値としてセット.

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

				// ウィンドウ作成成功
				return 0;	// return文で0を返して, ウィンドウ作成成功とする.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// ウィンドウが破棄された時.
		case WM_DESTROY:	// ウィンドウが破棄された時.(uMsgがWM_DESTROYの時.)

			// WM_DESTROYブロック
			{

				// このブロックのローカル変数の宣言と初期化.
				TCHAR *ptszUserData1 = NULL;	// TCHARポインタptszUserData1をNULLで初期化.
				TCHAR *ptszUserData2 = NULL;	// TCHARポインタptszUserData2をNULLで初期化.
				
				// RemovePropで削除.
				RemoveProp(hwnd, _T("UserData1"));	// RemovePropで"UserData1"をキーとする値を削除.
				ptszUserData1 = (TCHAR *)GetProp(hwnd, _T("UserData1"));	// GetPropで"UserData1"をキーとする値を取得.
				if (ptszUserData1 == NULL){	// NULLなら.
					MessageBox(NULL, _T("ptszUserData1 == NULL"), _T("RemoveProp"), MB_OK);	// MessageBoxで"ptszUserData1 == NULL"と表示.
				}
				RemoveProp(hwnd, _T("UserData2"));	// RemovePropで"UserData2"をキーとする値を削除.
				ptszUserData2 = (TCHAR *)GetProp(hwnd, _T("UserData2"));	// GetPropで"UserData2"をキーとする値を取得.
				if (ptszUserData2 == NULL){	// NULLなら.
					MessageBox(NULL, _T("ptszUserData2 == NULL"), _T("RemoveProp"), MB_OK);	// MessageBoxで"ptszUserData2 == NULL"と表示.
				}

				// 終了メッセージの送信.
				PostQuitMessage(0);	// PostQuitMessageで終了コードを0としてWM_QUITメッセージを送信.(するとメッセージループのGetMessageの戻り値が0になるので, メッセージループから抜ける.)

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// 画面の描画を要求された時.
		case WM_PAINT:		// 画面の描画を要求された時.(uMsgがWM_PAINTの時.)
 
			// WM_PAINTブロック
			{

				// このブロックのローカル変数の宣言と初期化.
				HDC hDC;						// デバイスコンテキストハンドルを格納するHDC型変数hDC.
				PAINTSTRUCT ps;					// ペイント情報を管理するPAINTSTRUCT構造体型の変数ps.
				TCHAR *ptszUserData1 = NULL;	// TCHARポインタptszUserData1をNULLで初期化.
				TCHAR *ptszUserData2 = NULL;	// TCHARポインタptszUserData2をNULLで初期化.

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にはデバイスコンテキストハンドルが返るので, hDCに格納.
				
				// ユーザデータの取得.
				ptszUserData1 = (TCHAR *)GetProp(hwnd, _T("UserData1"));	// GetPropで"UserData1"をキーとする値を取得.
				ptszUserData2 = (TCHAR *)GetProp(hwnd, _T("UserData2"));	// GetPropで"UserData2"をキーとする値を取得.

				// ユーザデータの描画.
				TextOut(hDC, 50, 50, ptszUserData1, (int)_tcslen(ptszUserData1));	// TextOutでptszUserData1を描画.
				TextOut(hDC, 50, 150, ptszUserData2, (int)_tcslen(ptszUserData2));	// TextOutでptszUserData2を描画.

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