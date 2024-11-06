// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型

// 独自のヘッダファイル
#include "resource.h"	// リソースID

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理をするように定義したコールバック関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数・配列の宣言・初期化
	HWND hWnd;				// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;				// ウィンドウメッセージ情報を格納するMSG構造体型変数msg.
	WNDCLASS wc;			// ウィンドウクラス情報をもつWNDCLASS構造体型変数wc.
	HDC hDC = NULL;			// このウィンドウのデバイスコンテキストハンドルhDCをNULLに初期化.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("CheckMenuRadioItem");			// ウィンドウクラス名は"CheckMenuRadioItem".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;							// ウィンドウプロシージャは独自の処理を定義したWindowProc.
	wc.hInstance = hInstance;								// インスタンスハンドルは_tWinMainの引数.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// アイコンはアプリケーション既定のもの.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// カーソルは矢印.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 背景は白ブラシ.
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MAINMENU);		// メニューにはIDR_MAINMENUをMAKEINTRESOURCEマクロで指定.
	wc.cbClsExtra = 0;										// 0でいい.
	wc.cbWndExtra = 0;										// 0でいい.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)){	// RegisterClassでウィンドウクラスを登録し, 0が返ったらエラー.

		// エラー処理
		MessageBox(NULL, _T("RegisterClass failed!"), _T("CheckMenuRadioItem"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("CheckMenuRadioItem"), _T("CheckMenuRadioItem"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"CheckMenuRadioItem"ウィンドウクラスのウィンドウを作成.(9番目にNULLを指定する.)
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("CheckMenuRadioItem"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.

	// デバイスコンテキストの取得.
	hDC = GetDC(hWnd);	// GetDCでデバイスコンテキストハンドルhDCを取得.

	// PeekMessageによるメインループ.
	while (TRUE){	// 常に真(TRUE)なので無限ループ.

		// ウィンドウメッセージが来ているかを確認する.
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE)){	// PeekMessageでウィンドウメッセージが来ているかを確認し, 真なら来ている.(PM_NOREMOVEなのでメッセージキューからこのメッセージを削除しない.次のGetMessageがそのメッセージを処理する.)

			// 来ていたらそのメッセージを取得.
			if (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessageでPeekMessageで確認したメッセージを取得.

				// ウィンドウメッセージの送出
				TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.
				DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(この場合は独自に定義したWindowProc)に送出.

			}
			else{	// 正常終了(0), またはエラーによる異常終了(-1).

				// メインループを抜ける.
				break;	// breakでメインループを抜ける.

			}

		}
		else{	// 偽ならウィンドウメッセージが来ていないとき.

			// 何もしない.

		}

	}

	// デバイスコンテキストの解放.
	if (hDC != NULL){	// hDCが解放されていなければ.

		// デバイスコンテキストを解放する.
		ReleaseDC(hWnd, hDC);	// ReleaseDCでhDCを解放.
		hDC = NULL;	// NULLをセット.

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

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// ウィンドウが破棄された時.
		case WM_DESTROY:	// ウィンドウが破棄された時.(uMsgがWM_DESTROYの時.)

			// WM_DESTROYブロック
			{

				// メニューの破棄.
				HMENU hMenu = GetMenu(hwnd);	// GetMenuでこのウィンドウhwndのメニューハンドルhMenuを取得.
				if (hMenu != NULL){	// NULLでない.
					BOOL bRet = DestroyMenu(hMenu);	// DestroyMenuでhMenuを破棄.
					if (bRet){
						MessageBox(hwnd, _T("DestroyMenu success!"), _T("CheckMenuRadioItem"), MB_OK);	// "DestroyMenu success!"と表示.
					}
					else{
						MessageBox(hwnd, _T("DestroyMenu failed!"), _T("CheckMenuRadioItem"), MB_OK);	// "DestroyMenu failed!"と表示.
					}
				}

				// 終了メッセージの送信.
				PostQuitMessage(0);	// PostQuitMessageで終了コードを0としてWM_QUITメッセージを送信.(するとメッセージループのGetMessageの戻り値が0になるので, メッセージループから抜ける.)

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりした時.
		case WM_COMMAND:	// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりした時.(uMsgがWM_COMMANDの時.)

			// WM_COMMANDブロック
			{

				// どのメニュー項目が選択されたかを判定する.
				switch (LOWORD(wParam)){	// LOWORD(wParam)で選択されたメニュー項目のIDが取得できるので, その値で判定する.

					// 取得したIDごとに処理を分岐.
					// Item1-1が選択された時.
					case ID_ITEM_1_1:

						// ID_ITEM_1_1ブロック
						{

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// Item1-2が選択された時.
					case ID_ITEM_1_2:

						// ID_ITEM_1_2ブロック
						{

							// Item1-1を無効にする.
							EnableMenuItem(GetMenu(hwnd), ID_ITEM_1_1, MF_BYCOMMAND | MF_DISABLED);	// EnableMenuItemでID_ITEM_1_1を無効にする.

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// Item1-3が選択された時.
					case ID_ITEM_1_3:

						// ID_ITEM_1_3ブロック
						{

							// Item1-1を有効にする.
							EnableMenuItem(GetMenu(hwnd), ID_ITEM_1_1, MF_BYCOMMAND | MF_ENABLED);	// EnableMenuItemでID_ITEM_1_1を有効にする.

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// Item2-1が選択された時.
					case ID_ITEM_2_1:

						// ID_ITEM_2_1ブロック
						{

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// Item2-2が選択された時.
					case ID_ITEM_2_2:

						// ID_ITEM_2_2ブロック
						{

							// Item2-1にチェックを入れる.
							CheckMenuItem(GetMenu(hwnd), ID_ITEM_2_1, MF_BYCOMMAND | MF_CHECKED);	// CheckMenuItemでID_ITEM_2_1にチェック.

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// Item2-3が選択された時.
					case ID_ITEM_2_3:

						// ID_ITEM_2_3ブロック
						{

							// Item2-1からチェックを外す.
							CheckMenuItem(GetMenu(hwnd), ID_ITEM_2_1, MF_BYCOMMAND | MF_UNCHECKED);	// CheckMenuItemでID_ITEM_2_1からチェックを外す.

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// Item3-1が選択された時.
					case ID_ITEM_3_1:

						// ID_ITEM_3_1ブロック
						{

							// Item3-1をラジオチェック.
							CheckMenuRadioItem(GetMenu(hwnd), ID_ITEM_3_1, ID_ITEM_3_3, ID_ITEM_3_1, MF_BYCOMMAND);	// CheckMenuRadioItemでID_ITEM_3_1を選択.

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// Item3-2が選択された時.
					case ID_ITEM_3_2:

						// ID_ITEM_3_2ブロック
						{

							// Item3-2をラジオチェック.
							CheckMenuRadioItem(GetMenu(hwnd), ID_ITEM_3_1, ID_ITEM_3_3, ID_ITEM_3_2, MF_BYCOMMAND);	// CheckMenuRadioItemでID_ITEM_3_2を選択.

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// Item3-3が選択された時.
					case ID_ITEM_3_3:

						// ID_ITEM_3_3ブロック
						{

							// Item3-3をラジオチェック.
							CheckMenuRadioItem(GetMenu(hwnd), ID_ITEM_3_1, ID_ITEM_3_3, ID_ITEM_3_3, MF_BYCOMMAND);	// CheckMenuRadioItemでID_ITEM_3_3を選択.

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