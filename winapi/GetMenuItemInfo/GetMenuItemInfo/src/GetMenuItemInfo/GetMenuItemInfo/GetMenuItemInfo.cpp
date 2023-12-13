// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型

// リソースIDの定義
#define ID_ITEM_1_1 10101
#define ID_ITEM_1_2 10102
#define ID_ITEM_1_3 10103
#define ID_ITEM_2_1 10201
#define ID_ITEM_2_2 10202
#define ID_ITEM_2_3 10203
#define ID_ITEM_3_1 10301
#define ID_ITEM_3_2 10302
#define ID_ITEM_3_3 10303

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理をするように定義したコールバック関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数・配列の宣言・初期化
	HWND hWnd;				// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;				// ウィンドウメッセージ情報を格納するMSG構造体型変数msg.
	WNDCLASS wc;			// ウィンドウクラス情報をもつWNDCLASS構造体型変数wc.
	HDC hDC = NULL;			// このウィンドウのデバイスコンテキストハンドルhDCをNULLに初期化.
	HMENU hMenu = NULL;		// このウィンドウのメニューハンドルhMenuをNULLに初期化.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("GetMenuItemInfo");				// ウィンドウクラス名は"GetMenuItemInfo".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;							// ウィンドウプロシージャは独自の処理を定義したWindowProc.
	wc.hInstance = hInstance;								// インスタンスハンドルは_tWinMainの引数.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// アイコンはアプリケーション既定のもの.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// カーソルは矢印.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 背景は白ブラシ.
	wc.lpszMenuName = NULL;									// とりあえずここではNULLにしておく.
	wc.cbClsExtra = 0;										// 0でいい.
	wc.cbWndExtra = 0;										// 0でいい.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)){	// RegisterClassでウィンドウクラスを登録し, 0が返ったらエラー.

		// エラー処理
		MessageBox(NULL, _T("RegisterClass failed!"), _T("GetMenuItemInfo"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("GetMenuItemInfo"), _T("GetMenuItemInfo"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, hMenu, hInstance, NULL);	// CreateWindowで, 上で登録した"GetMenuItemInfo"ウィンドウクラスのウィンドウを作成.(9番目にhMenuを指定する.)
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("GetMenuItemInfo"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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

	// 変数の宣言
	static HMENU hMenu;		// メインメニューのハンドルhMenuをスタティック変数で宣言.
	static HMENU hPopupMenu1 = NULL;	// hMenuの子メニューとなるポップアップメニューのハンドルhPopupMenu1をNULLに初期化.
	static HMENU hPopupMenu2 = NULL;	// hMenuの子メニューとなるポップアップメニューのハンドルhPopupMenu2をNULLに初期化.
	static HMENU hPopupMenu3 = NULL;	// hMenuの子メニューとなるポップアップメニューのハンドルhPopupMenu3をNULLに初期化.

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-casa文でuMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始された時.
		case WM_CREATE:		// ウィンドウの作成が開始された時.(uMsgがWM_CREATEの時.)

			// WM_CREATEブロック
			{

				// メニューの作成.
				hMenu = CreateMenu();	// CreateMenuでメニューを作成し, ハンドルをhMenuに格納.

				// ポップアップメニュー(ドロップダウンメニュー)作成
				hPopupMenu1 = CreatePopupMenu();	// CreatePopupMenuでポップアップメニューを作成し, ハンドルをhPopupMenu1に格納.
				hPopupMenu2 = CreatePopupMenu();	// CreatePopupMenuでポップアップメニューを作成し, ハンドルをhPopupMenu2に格納.
				hPopupMenu3 = CreatePopupMenu();	// CreatePopupMenuでポップアップメニューを作成し, ハンドルをhPopupMenu3に格納.

				// ポップアップメニューhPopupMenu1にメニュー項目を追加.
				AppendMenu(hPopupMenu1, MF_ENABLED | MF_STRING, ID_ITEM_1_1, _T("Item1-1(&D)"));	// AppendMenuでhPopupMenu1にメニュー項目Item1-1を追加.
				AppendMenu(hPopupMenu1, MF_ENABLED | MF_STRING, ID_ITEM_1_2, _T("Item1-2(&E)"));	// AppendMenuでhPopupMenu1にメニュー項目Item1-2を追加.
				AppendMenu(hPopupMenu1, MF_ENABLED | MF_STRING, ID_ITEM_1_3, _T("Item1-3(&F)"));	// AppendMenuでhPopupMenu1にメニュー項目Item1-3を追加.

				// ポップアップメニューhPopupMenu2にメニュー項目を追加.
				AppendMenu(hPopupMenu2, MF_ENABLED | MF_STRING, ID_ITEM_2_1, _T("Item2-1(&G)"));	// AppendMenuでhPopupMenu2にメニュー項目Item2-1を追加.
				AppendMenu(hPopupMenu2, MF_ENABLED | MF_STRING, ID_ITEM_2_2, _T("Item2-2(&H)"));	// AppendMenuでhPopupMenu2にメニュー項目Item2-2を追加.
				AppendMenu(hPopupMenu2, MF_ENABLED | MF_STRING, ID_ITEM_2_3, _T("Item2-3(&I)"));	// AppendMenuでhPopupMenu2にメニュー項目Item2-3を追加.

				// ポップアップメニューhPopupMenu3にメニュー項目を追加.
				AppendMenu(hPopupMenu3, MF_ENABLED | MF_STRING, ID_ITEM_3_1, _T("Item3-1(&J)"));	// AppendMenuでhPopupMenu3にメニュー項目Item3-1を追加.
				AppendMenu(hPopupMenu3, MF_ENABLED | MF_STRING, ID_ITEM_3_2, _T("Item3-2(&K)"));	// AppendMenuでhPopupMenu3にメニュー項目Item3-2を追加.
				AppendMenu(hPopupMenu3, MF_ENABLED | MF_STRING, ID_ITEM_3_3, _T("Item3-3(&L)"));	// AppendMenuでhPopupMenu3にメニュー項目Item3-3を追加.

				// メニューhMenuにポップアップメニューhPopupMenu1を追加.
				AppendMenu(hMenu, MF_ENABLED | MF_POPUP, (UINT_PTR)hPopupMenu1, _T("Item1(&A)"));	// AppendMenuでhMenuにhPopupMenu1を追加.

				// メニューhMenuにポップアップメニューhPopupMenu2を追加.
				AppendMenu(hMenu, MF_ENABLED | MF_POPUP, (UINT_PTR)hPopupMenu2, _T("Item2(&B)"));	// AppendMenuでhMenuにhPopupMenu2を追加.

				// メニューhMenuにポップアップメニューhPopupMenu3を追加.
				AppendMenu(hMenu, MF_ENABLED | MF_POPUP, (UINT_PTR)hPopupMenu3, _T("Item3(&C)"));	// AppendMenuでhMenuにhPopupMenu3を追加.

				// ウィンドウにメニューをセット.
				SetMenu(hwnd, hMenu);	// SetMenuでhwndにhMenuをセット.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// ウィンドウが破棄された時.
		case WM_DESTROY:	// ウィンドウが破棄された時.(uMsgがWM_DESTROYの時.)

			// WM_DESTROYブロック
			{

				// ポップアップメニュー項目の削除.
				DeleteMenu(hPopupMenu3, 0, MF_BYPOSITION);	// DeleteMenuでhPopupMenu3の0番目を削除.
				DeleteMenu(hPopupMenu3, 0, MF_BYPOSITION);	// DeleteMenuでhPopupMenu3の0番目を削除.
				DeleteMenu(hPopupMenu3, 0, MF_BYPOSITION);	// DeleteMenuでhPopupMenu3の0番目を削除.
				DeleteMenu(hPopupMenu2, 0, MF_BYPOSITION);	// DeleteMenuでhPopupMenu2の0番目を削除.
				DeleteMenu(hPopupMenu2, 0, MF_BYPOSITION);	// DeleteMenuでhPopupMenu2の0番目を削除.
				DeleteMenu(hPopupMenu2, 0, MF_BYPOSITION);	// DeleteMenuでhPopupMenu2の0番目を削除.
				DeleteMenu(hPopupMenu1, 0, MF_BYPOSITION);	// DeleteMenuでhPopupMenu1の0番目を削除.
				DeleteMenu(hPopupMenu1, 0, MF_BYPOSITION);	// DeleteMenuでhPopupMenu1の0番目を削除.
				DeleteMenu(hPopupMenu1, 0, MF_BYPOSITION);	// DeleteMenuでhPopupMenu1の0番目を削除.

				// ポップアップメニューの破棄.
				if (hPopupMenu3 != NULL){	// NULLでない.
					DestroyMenu(hPopupMenu3);	// DestroyMenuでhPopupMenu3を破棄.
				}
				if (hPopupMenu2 != NULL){	// NULLでない.
					DestroyMenu(hPopupMenu2);	// DestroyMenuでhPopupMenu2を破棄.
				}
				if (hPopupMenu1 != NULL){	// NULLでない.
					DestroyMenu(hPopupMenu1);	// DestroyMenuでhPopupMenu1を破棄.
				}

				// メニュー項目の削除.
				DeleteMenu(hMenu, 0, MF_BYPOSITION);	// DeleteMenuで0番目を削除.
				DeleteMenu(hMenu, 0, MF_BYPOSITION);	// DeleteMenuで0番目を削除.
				DeleteMenu(hMenu, 0, MF_BYPOSITION);	// DeleteMenuで0番目を削除.

				// メニューの破棄.
				if (hMenu != NULL){	// NULLでない.
					DestroyMenu(hMenu);	// DestroyMenuでhMenuを破棄.
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

							// メニュー項目名の取得.
							MENUITEMINFO miiMenuItemInfo = {0};
							miiMenuItemInfo.cbSize = sizeof(miiMenuItemInfo);
							miiMenuItemInfo.fMask = MIIM_TYPE;
							miiMenuItemInfo.fType = MIIM_STRING;
							miiMenuItemInfo.dwTypeData = NULL;
							GetMenuItemInfo(hPopupMenu1, 0, TRUE, &miiMenuItemInfo);
							miiMenuItemInfo.cch = miiMenuItemInfo.cch + 1;
							TCHAR *ptszText = new TCHAR[miiMenuItemInfo.cch];
							miiMenuItemInfo.dwTypeData = ptszText;
							GetMenuItemInfo(hPopupMenu1, 0, TRUE, &miiMenuItemInfo);
							MessageBox(hwnd, miiMenuItemInfo.dwTypeData, _T("GetMenuItemInfo"), MB_OK);
							delete [] ptszText;

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// Item1-2が選択された時.
					case ID_ITEM_1_2:

						// ID_ITEM_1_2ブロック
						{

							// メニュー項目名の取得.
							MENUITEMINFO miiMenuItemInfo = {0};
							miiMenuItemInfo.cbSize = sizeof(miiMenuItemInfo);
							miiMenuItemInfo.fMask = MIIM_TYPE;
							miiMenuItemInfo.fType = MIIM_STRING;
							miiMenuItemInfo.dwTypeData = NULL;
							GetMenuItemInfo(hPopupMenu1, 1, TRUE, &miiMenuItemInfo);
							miiMenuItemInfo.cch = miiMenuItemInfo.cch + 1;
							TCHAR *ptszText = new TCHAR[miiMenuItemInfo.cch];
							miiMenuItemInfo.dwTypeData = ptszText;
							GetMenuItemInfo(hPopupMenu1, 1, TRUE, &miiMenuItemInfo);
							MessageBox(hwnd, miiMenuItemInfo.dwTypeData, _T("GetMenuItemInfo"), MB_OK);
							delete [] ptszText;

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// Item1-3が選択された時.
					case ID_ITEM_1_3:

						// ID_ITEM_1_3ブロック
						{

							// メニュー項目名の取得.
							MENUITEMINFO miiMenuItemInfo = {0};
							miiMenuItemInfo.cbSize = sizeof(miiMenuItemInfo);
							miiMenuItemInfo.fMask = MIIM_TYPE;
							miiMenuItemInfo.fType = MIIM_STRING;
							miiMenuItemInfo.dwTypeData = NULL;
							GetMenuItemInfo(hPopupMenu1, 2, TRUE, &miiMenuItemInfo);
							miiMenuItemInfo.cch = miiMenuItemInfo.cch + 1;
							TCHAR *ptszText = new TCHAR[miiMenuItemInfo.cch];
							miiMenuItemInfo.dwTypeData = ptszText;
							GetMenuItemInfo(hPopupMenu1, 2, TRUE, &miiMenuItemInfo);
							MessageBox(hwnd, miiMenuItemInfo.dwTypeData, _T("GetMenuItemInfo"), MB_OK);
							delete [] ptszText;

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

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// Item2-3が選択された時.
					case ID_ITEM_2_3:

						// ID_ITEM_2_3ブロック
						{

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// Item3-1が選択された時.
					case ID_ITEM_3_1:

						// ID_ITEM_3_1ブロック
						{

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// Item3-2が選択された時.
					case ID_ITEM_3_2:

						// ID_ITEM_3_2ブロック
						{

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// Item3-3が選択された時.
					case ID_ITEM_3_3:

						// ID_ITEM_3_3ブロック
						{

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