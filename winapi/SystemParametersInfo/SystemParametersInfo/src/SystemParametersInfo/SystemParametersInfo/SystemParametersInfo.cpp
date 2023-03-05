// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// C標準入出力
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
	wc.lpszClassName = _T("SystemParametersInfo");			// ウィンドウクラス名は"SystemParametersInfo".
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
		MessageBox(NULL, _T("RegisterClass Failure!"), _T("SystemParametersInfo"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass Failure!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("SystemParametersInfo"), _T("SystemParametersInfo"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"SystemParametersInfo"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow Failure!"), _T("SystemParametersInfo"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow Failure!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.

	// メッセージループ
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessageでメッセージを取得, 戻り値が0より大きい間はループし続ける.

		// ウィンドウメッセージ処理
		TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.
		DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(この場合は独自に定義したWindowProc)に送出.

	}

	// プログラムの終了
	return (int)msg.wParam;	// 終了コード(msg.wParam)を戻り値として返す.

}

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// ウィンドウメッセージに対して独自の処理をするように定義したウィンドウプロシージャ.

	// スタティック変数の初期化.
	static SHFILEINFO sfi = {0};	// ファイル情報を持つSHFILEINFO型変数sfiを{0}で初期化.
	static RECT rc = {0};	// デスクトップ領域のサイズrcを{0}で初期化.

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

				// 描画開始.
				PAINTSTRUCT ps = {0};	// PAINTSTRUCT型psを{0}で初期化.
				HDC hDC = BeginPaint(hwnd, &ps);	// BeginPaintでhDC取得.

				// 表示名と種類とアイコンハンドルを描画.
				TextOut(hDC, 50, 50, sfi.szDisplayName, lstrlen(sfi.szDisplayName));	// TextOutでsfi.szDisplayNameを描画.
				TextOut(hDC, 50, 100, sfi.szTypeName, lstrlen(sfi.szTypeName));	// TextOutでsfi.szTypeNameを描画.
				TCHAR tszHIcon[64] = {0};	// sfi.hIconを文字列にしたものを格納するTCHAR型配列tszHIcon(長さ64)を{0}で初期化.
				_stprintf(tszHIcon, _T("sfi.hIcon = 0x%08x"), (unsigned int)sfi.hIcon);	// sfi.hIconを文字列に変換し, tszHIconに格納.
				TextOut(hDC, 50, 150, tszHIcon, lstrlen(tszHIcon));	// TextOutでtszHIconを描画.

				// デスクトップ領域のサイズを描画.
				TCHAR tszLeft[64] = {0};	// rc.leftを文字列にしたものを格納するTCHAR型配列tszLeft(長さ64)を{0}で初期化.
				_stprintf(tszLeft, _T("rc.left = %d"), rc.left);	// rc.leftを文字列に変換し, tszLeftに格納.
				TextOut(hDC, 250, 50, tszLeft, lstrlen(tszLeft));	// TextOutでtszLeftを描画.
				TCHAR tszTop[64] = {0};	// rc.topを文字列にしたものを格納するTCHAR型配列tszTop(長さ64)を{0}で初期化.
				_stprintf(tszTop, _T("rc.top = %d"), rc.top);	// rc.topを文字列に変換し, tszTopに格納.
				TextOut(hDC, 250, 100, tszTop, lstrlen(tszTop));	// TextOutでtszTopを描画.
				TCHAR tszRight[64] = {0};	// rc.rightを文字列にしたものを格納するTCHAR型配列tszRight(長さ64)を{0}で初期化.
				_stprintf(tszRight, _T("rc.right = %d"), rc.right);	// rc.rightを文字列に変換し, tszRightに格納.
				TextOut(hDC, 250, 150, tszRight, lstrlen(tszRight));	// TextOutでtszRightを描画.
				TCHAR tszBottom[64] = {0};	// rc.bottomを文字列にしたものを格納するTCHAR型配列tszBottom(長さ64)を{0}で初期化.
				_stprintf(tszBottom, _T("rc.bottom = %d"), rc.bottom);	// rc.bottomを文字列に変換し, tszBottomに格納.
				TextOut(hDC, 250, 200, tszBottom, lstrlen(tszBottom));	// TextOutでtszBottomを描画.

				// 描画終了.
				EndPaint(hwnd, &ps);	// EndPaintで描画終了.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// ウィンドウが閉じられた時.
		case WM_CLOSE:	// ウィンドウが閉じられた時.(uMsgがWM_CLOSEの時.)

			// WM_CLOSEブロック
			{

				// sfi.hIconの破棄.
				if (sfi.hIcon != NULL){	// sfi.hIconがNULLでなければ.
					DestroyIcon(sfi.hIcon);	// DestroyIconでsfi.hIconを破棄.
					sfi.hIcon = NULL;	// sfi.hIconにNULLをセット.
				}

			}

			// 抜ける.
			break;	// breakで抜ける.

		// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりした時.
		case WM_COMMAND:	// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりした時.(uMsgがWM_COMMANDの時.)

			// WM_COMMANDブロック
			{

				// どのメニュー項目が選択されたかを判定する.
				switch (LOWORD(wParam)){	// LOWORD(wParam)で選択されたメニュー項目のIDが取得できるので, その値で判定する.

					// 取得したIDごとに処理を分岐.
					// Openが選択された時.
					case ID_FILE_OPEN:

						// ID_FILE_OPENブロック
						{

							// 変数の宣言・初期化.
							OPENFILENAME ofn = {0};	// OPENFILENAME構造体変数ofnを{0}で初期化.
							TCHAR tszFilePath[MAX_PATH] = {0};	// ファイルパスtszFilePath(長さMAX_PATH)を0で初期化.

							// ofnに値をセット.
							ofn.lStructSize = sizeof(OPENFILENAME);	// 構造体のサイズ.
							ofn.lpstrFile = tszFilePath;	// ファイルパス.
							ofn.nMaxFile = MAX_PATH;	// ファイルパスの最大長.

							// ファイル選択.
							if (!GetOpenFileName(&ofn)){	// GetOpenFileNameでファイルを選択.

								// 選択しなかった場合.(キャンセル)
								return 0;	// 処理したので戻り値として0を返す.

							}

							// ファイル名部分だけ取得.
							TCHAR tszFileTitle[64] = {0};	// ファイル名部分tszFileTitle(長さ64)を{0}で初期化.
							GetFileTitle(tszFilePath, tszFileTitle, 64);	// GetFileTitleでtszFileTitleを取得.

							// ウィンドウタイトルにtszFileTitleをセット.
							SetWindowText(hwnd, tszFileTitle);	// SetWindowTextでtszFileTitleをセット.

							// ファイル情報を取得.
							SHGetFileInfo(tszFilePath, 0, &sfi, sizeof(SHFILEINFO), SHGFI_DISPLAYNAME | SHGFI_TYPENAME | SHGFI_ICON);	// SHGetFileInfoで表示名と種類とアイコンを取得.

							// 画面更新.
							InvalidateRect(hwnd, NULL, TRUE);	// InvalidateRectで全体を無効領域とする.

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// Infoが選択された時.
					case ID_SYSTEM_INFO:

						// ID_SYSTEM_INFOブロック
						{

							// システム情報(デスクトップ領域のサイズ)を取得.
							SystemParametersInfo(SPI_GETWORKAREA, 0, &rc, 0);	// SystemParametersInfoでデスクトップ領域のサイズrcを取得.

							// 画面更新.
							InvalidateRect(hwnd, NULL, TRUE);	// InvalidateRectで全体を無効領域とする.

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