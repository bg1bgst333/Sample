// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <commctrl.h>	// コモンコントロール

// 独自のヘッダファイル
#include "resource.h"	// リソースID

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理をするように定義したコールバック関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数・配列の宣言・初期化
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージ情報を格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラス情報をもつWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("EM_SETMODIFY");							// ウィンドウクラス名は"EM_SETMODIFY".
	wc.style = CS_HREDRAW | CS_VREDRAW;								// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;									// ウィンドウプロシージャは独自の処理を定義したWindowProc.
	wc.hInstance = hInstance;										// インスタンスハンドルは_tWinMainの引数.
	wc.hIcon = LoadIcon(hInstance, NULL);							// アイコンはNULL.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);						// カーソルは矢印.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);			// 背景は白ブラシ.
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MAINMENU);				// メニューにはIDR_MAINMENUをMAKEINTRESOURCEマクロで指定.
	wc.cbClsExtra = 0;												// 0でいい.
	wc.cbWndExtra = 0;												// 0でいい.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)){	// RegisterClassでウィンドウクラスを登録し, 0が返ったらエラー.

		// エラー処理
		MessageBox(NULL, _T("RegisterClass failed!"), _T("EM_SETMODIFY"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("EM_SETMODIFY"), _T("EM_SETMODIFY"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"EM_SETMODIFY"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("EM_SETMODIFY"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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
inline LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// ウィンドウメッセージに対して独自の処理をするように定義したウィンドウプロシージャ.

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-casa文でuMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始された時.
		case WM_CREATE:		// ウィンドウの作成が開始された時.(uMsgがWM_CREATEの時.)

			// WM_CREATEブロック
			{

				// 変数の宣言
				HWND hEdit;			// エディットコントロールのウィンドウハンドルhEdit.
				LPCREATESTRUCT lpCS;	// CreateStruct構造体のポインタlpCS.

				// アプリケーションインスタンスハンドルの取得.
				lpCS = (LPCREATESTRUCT)lParam;	// lParamをLPCREATESTRUCTにキャストして, lpCSに格納.

				// エディットコントロールの作成.
				hEdit = CreateWindow(WC_EDIT, _T(""), WS_CHILD | WS_VISIBLE | WS_BORDER, 0, 0, 200, 200, hwnd, (HMENU)ID_EDIT1, lpCS->hInstance, NULL);	// CreateWindowのWC_EDITでエディットコントロールを作成.
				if (hEdit == NULL){	// hEditがNULLなら.

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

			// 終了メッセージの送信.
			PostQuitMessage(0);	// PostQuitMessageで終了コードを0としてWM_QUITメッセージを送信.(するとメッセージループのGetMessageの戻り値が0になるので, メッセージループから抜ける.)

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// ウィンドウが閉じられた時.
		case WM_CLOSE:	// ウィンドウが閉じられた時.(uMsgがWM_CLOSEの時.)

			// WM_CLOSEブロック
			{

				// エディットコントロールが更新されたかをチェック.
				HWND hEdit = GetDlgItem(hwnd, ID_EDIT1);	// GetDlgItemでエディットコントロールのハンドルhEditを取得.
				BOOL bRet = (BOOL)SendMessage(hEdit, EM_GETMODIFY, 0, 0);	// SendMessageでEM_GETMODIFYを送信すると, 戻り値としてエディットコントロールが更新されたかどうかが返る.
				if (bRet){	// TRUEなら.

					// "Modify!"と表示.
					MessageBox(hwnd, _T("Modify!"), _T("EM_SETMODIFY"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"Modify!"と表示.

				}

			}

			// 抜ける.
			break;	// breakで抜ける.

		// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりして, コマンドが発生した時.
		case WM_COMMAND:	// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりして, コマンドが発生した時.(uMsgがWM_COMMANDの時.)

			// WM_COMMANDブロック
			{

				// どのメニュー項目, またはコントロールが選択されたかを判定する.
				switch (LOWORD(wParam)){	// LOWORD(wParam)で選択されたメニュー項目, またはコントロールのIDが取得できるので, その値で判定する.

					// 取得したIDごとに処理を分岐.
					// "Check Modify"が選択された時.
					case ID_ITEM_CHECK_MODIFY:

						// ID_ITEM_CHECK_MODIFYブロック
						{

							// エディットコントロールが更新されたかをチェック.
							HWND hEdit = GetDlgItem(hwnd, ID_EDIT1);	// GetDlgItemでエディットコントロールのハンドルhEditを取得.
							BOOL bRet = (BOOL)SendMessage(hEdit, EM_GETMODIFY, 0, 0);	// SendMessageでEM_GETMODIFYを送信すると, 戻り値としてエディットコントロールが更新されたかどうかが返る.
							if (bRet){	// TRUEなら.

								// "Modify!"と表示.
								MessageBox(hwnd, _T("Modify!"), _T("EM_SETMODIFY"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"Modify!"と表示.

							}

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// "Reset Modify"が選択された時.
					case ID_ITEM_RESET_MODIFY:

						// ID_ITEM_RESET_MODIFYブロック
						{

							// エディットコントロールの変更状態フラグをリセット.
							HWND hEdit = GetDlgItem(hwnd, ID_EDIT1);	// GetDlgItemでエディットコントロールのハンドルhEditを取得.
							SendMessage(hEdit, EM_SETMODIFY, (WPARAM)FALSE, 0);	// SendMessageで第3引数にFALSEを指定してEM_SETMODIFYを送信すると, エディットコントロールが変更された状態のフラグが立っていたら降ろす.(変更されてない状態となる.)

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// 上記以外の時.
					default:

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

				}

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