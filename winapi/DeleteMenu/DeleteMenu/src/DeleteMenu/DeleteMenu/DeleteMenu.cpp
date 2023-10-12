// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型

// リソースIDの定義
#define ID_ITEM_1	101
#define ID_ITEM_1_1 10101
#define ID_ITEM_1_2 10102
#define ID_ITEM_1_3 10103

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
	wc.lpszClassName = _T("DeleteMenu");					// ウィンドウクラス名は"DeleteMenu".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("DeleteMenu"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("DeleteMenu"), _T("DeleteMenu"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, hMenu, hInstance, NULL);	// CreateWindowで, 上で登録した"DeleteMenu"ウィンドウクラスのウィンドウを作成.(9番目にhMenuを指定する.)
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("DeleteMenu"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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

				// ポップアップメニューhPopupMenu1にメニュー項目を追加.
				AppendMenu(hPopupMenu1, MF_ENABLED | MF_STRING, ID_ITEM_1_1, _T("Item1-1(&B)"));	// AppendMenuでhPopupMenu1にメニュー項目Item1-1を追加.
				AppendMenu(hPopupMenu1, MF_ENABLED | MF_STRING, ID_ITEM_1_2, _T("Item1-2(&C)"));	// AppendMenuでhPopupMenu1にメニュー項目Item1-2を追加.
				AppendMenu(hPopupMenu1, MF_ENABLED | MF_STRING, ID_ITEM_1_3, _T("Item1-3(&D)"));	// AppendMenuでhPopupMenu1にメニュー項目Item1-3を追加.

				// ID_ITEM_1_2だけ, すぐ削除.
				DeleteMenu(hPopupMenu1, ID_ITEM_1_2, MF_BYCOMMAND);	// DeleteMenuでID_ITEM_1_2を削除.

				// メニューhMenuにポップアップメニューhPopupMenu1を追加.
				AppendMenu(hMenu, MF_ENABLED | MF_POPUP, (UINT_PTR)hPopupMenu1, _T("Item1(&A)"));	// AppendMenuでhMenuにhPopupMenu1を追加.

				// ウィンドウにメニューをセット.
				SetMenu(hwnd, hMenu);	// SetMenuでhwndにhMenuをセット.	

				// ウィンドウ作成成功
				return 0;	// return文で0を返して, ウィンドウ作成成功とする.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// ウィンドウが破棄された時.
		case WM_DESTROY:	// ウィンドウが破棄された時.(uMsgがWM_DESTROYの時.)

			// WM_DESTROYブロック
			{

				// ポップアップメニュー項目の削除.
				DeleteMenu(hPopupMenu1, ID_ITEM_1_3, MF_BYCOMMAND);	// DeleteMenuでID_ITEM_1_3を削除.
				DeleteMenu(hPopupMenu1, ID_ITEM_1_1, MF_BYCOMMAND);	// DeleteMenuでID_ITEM_1_1を削除.

				// ポップアップメニューの破棄.
				if (hPopupMenu1 != NULL){	// NULLでない.
					DestroyMenu(hPopupMenu1);	// DestroyMenuでhPopupMenu1を破棄.
				}

				// メニュー項目の削除.
				DeleteMenu(hMenu, ID_ITEM_1, MF_BYCOMMAND);	// DeleteMenuでID_ITEM_1を削除.

				// メニューの破棄.
				if (hMenu != NULL){	// NULLでない.
					DestroyMenu(hMenu);	// DestroyMenuでhMenuを破棄.
				}

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