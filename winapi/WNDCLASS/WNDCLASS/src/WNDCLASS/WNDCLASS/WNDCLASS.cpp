// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理をするように定義したコールバック関数WindowProc.
LRESULT CALLBACK WindowProc2(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// 子のウィンドウのウィンドウプロシージャWindowProc2.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;		// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;		// ウィンドウメッセージ情報を格納するMSG構造体型変数msg.
	WNDCLASS wcParent;	// 親のウィンドウクラス情報をもつWNDCLASS構造体型変数wcParent.
	WNDCLASS wcChild;	// 子のウィンドウクラス情報をもつWNDCLASS構造体型変数wcChild.

	// 親のウィンドウクラスの設定
	wcParent.lpszClassName = _T("WNDCLASS_Parent");					// ウィンドウクラス名は"WNDCLASS_Parent".
	wcParent.style = CS_HREDRAW | CS_VREDRAW;						// スタイルはCS_HREDRAW | CS_VREDRAW.
	wcParent.lpfnWndProc = WindowProc;								// ウィンドウプロシージャは独自の処理を定義したWindowProc.
	wcParent.hInstance = hInstance;									// インスタンスハンドルは_tWinMainの引数.
	wcParent.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// アイコンはアプリケーション既定のもの.
	wcParent.hCursor = LoadCursor(NULL, IDC_ARROW);					// カーソルは矢印.
	wcParent.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 背景は白ブラシ.
	wcParent.lpszMenuName = NULL;									// なし
	wcParent.cbClsExtra = 0;										// 0でいい.
	wcParent.cbWndExtra = 0;										// 0でいい.

	// 親のウィンドウクラスの登録
	if (!RegisterClass(&wcParent)){	// RegisterClassでウィンドウクラスを登録し, 0が返ったらエラー.
 
		// エラー処理
		MessageBox(NULL, _T("Parent: RegisterClass failed!"), _T("WNDCLASS"), MB_OK | MB_ICONHAND);	// MessageBoxで"Parent: RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)
 
	}

	// 子のウィンドウクラスの設定
	wcChild.lpszClassName = _T("WNDCLASS_Child");					// ウィンドウクラス名は"WNDCLASS_Child".
	wcChild.style = CS_HREDRAW | CS_VREDRAW;						// スタイルはCS_HREDRAW | CS_VREDRAW.
	wcChild.lpfnWndProc = WindowProc2;								// ウィンドウプロシージャは子のウィンドウ用のWindowProc2.
	wcChild.hInstance = hInstance;									// インスタンスハンドルは_tWinMainの引数.
	wcChild.hIcon = NULL;											// アイコンはなし.
	wcChild.hCursor = NULL;											// カーソルはなし.
	wcChild.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);	// 背景は淡灰色ブラシ.
	wcChild.lpszMenuName = NULL;									// なし
	wcChild.cbClsExtra = 0;											// 0でいい.
	wcChild.cbWndExtra = 0;											// 0でいい.

	// 子のウィンドウクラスの登録
	if (!RegisterClass(&wcChild)){	// RegisterClassでウィンドウクラスを登録し, 0が返ったらエラー.
 
		// エラー処理
		MessageBox(NULL, _T("Child: RegisterClass failed!"), _T("WNDCLASS"), MB_OK | MB_ICONHAND);	// MessageBoxで"Child: RegisterClass failed!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)
 
	}

	// 親のウィンドウの作成.
	hWnd = CreateWindow(_T("WNDCLASS_Parent"), _T("WNDCLASS"), WS_OVERLAPPEDWINDOW, 50, 50, 640, 480, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"WNDCLASS_Parent"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("Parent: CreateWindow failed!"), _T("WNDCLASS"), MB_OK | MB_ICONHAND);	// MessageBoxで"Parent: CreateWindow failed!"とエラーメッセージを表示.
		return -3;	// 異常終了(3)
 
	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定して親のウィンドウの表示.

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

				// 変数の宣言
				HWND hChild;	// 子のウィンドウハンドルhChild.
				LPCREATESTRUCT lpCS;	// CreateStruct構造体のポインタlpCS.

				// アプリケーションインスタンスハンドルの取得.
				lpCS = (LPCREATESTRUCT)lParam;	// lParamをLPCREATESTRUCTにキャストして, lpCSに格納.

				// 子のウィンドウの作成.
				hChild = CreateWindow(_T("WNDCLASS_Child"), _T(""), WS_CHILD | WS_VISIBLE, 50, 50, 250, 250, hwnd, (HMENU)501, lpCS->hInstance, NULL);	// CreateWindowで子のウィンドウを作成.
				if (hChild == NULL){	// hChildがNULLなら.

					// エラー処理.
					return -1;	// -1を返す.

				}

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
LRESULT CALLBACK WindowProc2(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// 子のウィンドウのウィンドウプロシージャWindowProc2.

	// あとは既定の処理に任せる.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// 戻り値も含めDefWindowProcに既定の処理を任せる.

}