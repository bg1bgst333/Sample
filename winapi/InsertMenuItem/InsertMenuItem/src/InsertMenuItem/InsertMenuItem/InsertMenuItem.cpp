// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型

// メニューのリソースIDの定義.
#define ID_MENU_ITEM1 101
#define ID_MENU_ITEM1_1	10101
#define ID_MENU_ITEM1_2	10102
#define ID_MENU_ITEM1_3	10103
#define ID_MENU_ITEM2 102
#define ID_MENU_ITEM2_1	10201
#define ID_MENU_ITEM2_2	10202
#define ID_MENU_ITEM2_3	10203

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
	wc.lpszClassName = _T("InsertMenuItem");				// ウィンドウクラス名は"InsertMenuItem".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("InsertMenuItem"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("InsertMenuItem"), _T("InsertMenuItem"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"InsertMenuItem"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("InsertMenuItem"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-casa文でuMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始された時.
		case WM_CREATE:		// ウィンドウの作成が開始された時.(uMsgがWM_CREATEの時.)

			// WM_CREATEブロック
			{

				// メニューの作成.
				hMenu = CreateMenu();	// CreateMenuでメニューを作成し, ハンドルをhMenuに格納.

				// ポップアップメニューハンドル1の初期化.
				HMENU hPopupMenu1 = NULL;	// hPopupMenu1をNULLで初期化.
				// ポップアップメニュー1の作成.
				hPopupMenu1 = CreatePopupMenu();	// hPopupMenu1の作成.
				// メニューアイテム情報構造体の宣言.
				MENUITEMINFO mii1;	// mii1を宣言.
				// 初期化.
				ZeroMemory(&mii1, sizeof(MENUITEMINFO));	// mii1をZeroMemoryで初期化.
				// 値のセット.
				mii1.cbSize = sizeof(MENUITEMINFO);	// サイズ.
				mii1.fMask = MIIM_TYPE | MIIM_SUBMENU;	// サブメニュー.
				mii1.fType = MFT_STRING;	// 文字列.
				mii1.fState = MFS_ENABLED;	// 有効.
				mii1.wID = ID_MENU_ITEM1;	// ID_MENU_ITEM1.
				mii1.hSubMenu = hPopupMenu1;	// hPopupMenu1をサブメニューとする.
				mii1.dwTypeData = _T("Item1");	// "Item1".
				// 挿入.
				InsertMenuItem(hMenu, 0, TRUE, &mii1);	// InsertMenuItemでmii1を挿入.

				// サブアイテム1-1の作成.
				MENUITEMINFO mii11;	// mii11を宣言.
				// 初期化.
				ZeroMemory(&mii11, sizeof(MENUITEMINFO));	// mii11をZeroMemoryで初期化.
				// 値のセット.
				mii11.cbSize = sizeof(MENUITEMINFO);	// サイズ.
				mii11.fMask = MIIM_TYPE | MIIM_ID;	// ID.
				mii11.fType = MFT_STRING;	// 文字列.
				mii11.fState = MFS_ENABLED;	// 有効.
				mii11.wID = ID_MENU_ITEM1_1;	// ID_MENU_ITEM1_1.
				mii11.dwTypeData = _T("Item1-1");	// "Item1-1".
				// 挿入.
				InsertMenuItem(hPopupMenu1, 0, TRUE, &mii11);	// InsertMenuItemでmii11をhPopupMenu1に挿入.

				// サブアイテム1-2の作成.
				MENUITEMINFO mii12;	// mii12を宣言.
				// 初期化.
				ZeroMemory(&mii12, sizeof(MENUITEMINFO));	// mii12をZeroMemoryで初期化.
				// 値のセット.
				mii12.cbSize = sizeof(MENUITEMINFO);	// サイズ.
				mii12.fMask = MIIM_TYPE | MIIM_ID;	// ID.
				mii12.fType = MFT_STRING;	// 文字列.
				mii12.fState = MFS_ENABLED;	// 有効.
				mii12.wID = ID_MENU_ITEM1_2;	// ID_MENU_ITEM1_2.
				mii12.dwTypeData = _T("Item1-2");	// "Item1-2".
				// 挿入.
				InsertMenuItem(hPopupMenu1, 1, TRUE, &mii12);	// InsertMenuItemでmii12をhPopupMenu1に挿入.

				// サブアイテム1-3の作成.
				MENUITEMINFO mii13;	// mii13を宣言.
				// 初期化.
				ZeroMemory(&mii13, sizeof(MENUITEMINFO));	// mii13をZeroMemoryで初期化.
				// 値のセット.
				mii13.cbSize = sizeof(MENUITEMINFO);	// サイズ.
				mii13.fMask = MIIM_TYPE | MIIM_ID;	// ID.
				mii13.fType = MFT_STRING;	// 文字列.
				mii13.fState = MFS_ENABLED;	// 有効.
				mii13.wID = ID_MENU_ITEM1_3;	// ID_MENU_ITEM1_3.
				mii13.dwTypeData = _T("Item1-3");	// "Item1-3".
				// 挿入.
				InsertMenuItem(hPopupMenu1, 2, TRUE, &mii13);	// InsertMenuItemでmii13をhPopupMenu1に挿入.

				// ポップアップメニューハンドル2の初期化.
				HMENU hPopupMenu2 = NULL;	// hPopupMenu2をNULLで初期化.
				// ポップアップメニュー2の作成.
				hPopupMenu2 = CreatePopupMenu();	// hPopupMenu2の作成.
				// メニューアイテム情報構造体の宣言.
				MENUITEMINFO mii2;	// mii2を宣言.
				// 初期化.
				ZeroMemory(&mii2, sizeof(MENUITEMINFO));	// mii2をZeroMemoryで初期化.
				// 値のセット.
				mii2.cbSize = sizeof(MENUITEMINFO);	// サイズ.
				mii2.fMask = MIIM_TYPE | MIIM_SUBMENU;	// サブメニュー.
				mii2.fType = MFT_STRING;	// 文字列.
				mii2.fState = MFS_ENABLED;	// 有効.
				mii2.wID = ID_MENU_ITEM2;	// ID_MENU_ITEM2.
				mii2.hSubMenu = hPopupMenu2;	// hPopupMenu2をサブメニューとする.
				mii2.dwTypeData = _T("Item2");	// "Item2".
				// 挿入.
				InsertMenuItem(hMenu, ID_MENU_ITEM2, FALSE, &mii2);	// InsertMenuItemでmii2を挿入.

				// サブアイテム2-1の作成.
				MENUITEMINFO mii21;	// mii21を宣言.
				// 初期化.
				ZeroMemory(&mii21, sizeof(MENUITEMINFO));	// mii21をZeroMemoryで初期化.
				// 値のセット.
				mii21.cbSize = sizeof(MENUITEMINFO);	// サイズ.
				mii21.fMask = MIIM_TYPE | MIIM_ID;	// ID.
				mii21.fType = MFT_STRING;	// 文字列.
				mii21.fState = MFS_ENABLED;	// 有効.
				mii21.wID = ID_MENU_ITEM2_1;	// ID_MENU_ITEM2_1.
				mii21.dwTypeData = _T("Item2-1");	// "Item2-1".
				// 挿入.
				InsertMenuItem(hPopupMenu2, ID_MENU_ITEM2_1, FALSE, &mii21);	// InsertMenuItemでmii21をhPopupMenu2に挿入.

				// サブアイテム2-2の作成.
				MENUITEMINFO mii22;	// mii22を宣言.
				// 初期化.
				ZeroMemory(&mii22, sizeof(MENUITEMINFO));	// mii22をZeroMemoryで初期化.
				// 値のセット.
				mii22.cbSize = sizeof(MENUITEMINFO);	// サイズ.
				mii22.fMask = MIIM_TYPE | MIIM_ID;	// ID.
				mii22.fType = MFT_STRING;	// 文字列.
				mii22.fState = MFS_ENABLED;	// 有効.
				mii22.wID = ID_MENU_ITEM2_2;	// ID_MENU_ITEM2_2.
				mii22.dwTypeData = _T("Item2-2");	// "Item2-2".
				// 挿入.
				InsertMenuItem(hPopupMenu2, ID_MENU_ITEM2_2, FALSE, &mii22);	// InsertMenuItemでmii22をhPopupMenu2に挿入.

				// サブアイテム2-3の作成.
				MENUITEMINFO mii23;	// mii23を宣言.
				// 初期化.
				ZeroMemory(&mii23, sizeof(MENUITEMINFO));	// mii23をZeroMemoryで初期化.
				// 値のセット.
				mii23.cbSize = sizeof(MENUITEMINFO);	// サイズ.
				mii23.fMask = MIIM_TYPE | MIIM_ID;	// ID.
				mii23.fType = MFT_STRING;	// 文字列.
				mii23.fState = MFS_ENABLED;	// 有効.
				mii23.wID = ID_MENU_ITEM2_3;	// ID_MENU_ITEM2_3.
				mii23.dwTypeData = _T("Item2-3");	// "Item2-3".
				// 挿入.
				InsertMenuItem(hPopupMenu2, ID_MENU_ITEM2_3, FALSE, &mii23);	// InsertMenuItemでmii23をhPopupMenu2に挿入.

				// メニューのセット.
				SetMenu(hwnd, hMenu);	// SetMenuでhMenuのセット.

				// ウィンドウ作成成功
				return 0;	// return文で0を返して, ウィンドウ作成成功とする.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// ウィンドウが破棄された時.
		case WM_DESTROY:	// ウィンドウが破棄された時.(uMsgがWM_DESTROYの時.)

			// WM_DESTROYブロック
			{

				// メニュー破棄
				DestroyMenu(hMenu);	// DestroyMenuでhMenuを破棄.

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