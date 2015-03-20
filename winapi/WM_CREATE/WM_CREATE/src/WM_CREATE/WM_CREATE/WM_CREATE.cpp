// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// C標準入出力
#include <string.h>		// C文字列処理

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理をするように定義したコールバンク関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;			// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;			// ウィンドウメッセージ情報を格納するMSG構造体型変数msg.
	WNDCLASS wc;		// ウィンドウクラス情報をもつWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("WM_CREATE");						// ウィンドウクラス名は"WM_CREATE".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;							// ウィンドウプロシージャは独自の処理を定義したWindowProc.
	wc.hInstance = hInstance;								// インスタンスハンドルは_tWinMainの引数.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// アイコンはアプリケーション既定のもの.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// カーソルは矢印.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 背景は白ブラシ.
	wc.lpszMenuName = NULL;									// メニューはなし.
	wc.cbClsExtra = 0;										// 0でいい.
	wc.cbWndExtra = 0;										// 0でいい.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)){	// RegisterClassでウィンドウクラスを登録し, 0が返ったらエラー.

		// エラー処理
		MessageBox(NULL, _T("RegisterClass failed!"), _T("WM_CREATE"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("WM_CREATE"), _T("WM_CREATE"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"WM_CREATE"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("WM_CREATE"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.

	// メッセージループ
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessageでメッセージを取得, 戻り値が0より大きい間はループし続ける.

		// ウィンドウメッセージの送出
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

				// このブロックのローカル変数・配列の宣言
				TCHAR tszMsg[1024] = {0}; // メッセージボックスで表示する最終的なメッセージを格納するTCHAR型配列tszMsg(長さ1024)をすべて0(_T('\0'))で初期化.
				TCHAR tszTmp[1024] = {0}; // 一時的な格納に使うTCHAR型配列tszTmp(長さ1024)をすべて0(_T('\0'))で初期化.
				LPCREATESTRUCT lpcs; // lParamから渡されたCREATESTRUCTへのポインタを格納するlpcs.

				// lParamをlpcsに渡す.
				lpcs = (LPCREATESTRUCT)lParam; // lParamをLPCREATESTRUCTにキャストしてlpcsに格納.

				// "WM_CREATE"をtszMsgに連結.
				_stprintf(tszTmp, _T("WM_CREATE"));	// _stprintfでtszTmpに"WM_CREATE"をセット.
				_tcscat(tszMsg, tszTmp);	// _tcscatでtszMsgにtszTmpを連結.

				// hwndの値をtszMsgに連結.
				_stprintf(tszTmp, _T("\nhwnd = 0x%08x"), hwnd);	// _stprintfでtszTmpにhwndの値を16進数にしたものをセット.
				_tcscat(tszMsg, tszTmp);	// _tcscatでtszMsgにtszTmpを連結.

				// lpcs->lpszNameの文字列をtszMsgに連結.
				_stprintf(tszTmp, _T("\nlpcs->lpszName = %s"), lpcs->lpszName);	// _stprintfでtszTmpにlpcs->lpszNameの文字列をセット.
				_tcscat(tszMsg, tszTmp);	// _tcscatでtszMsgにtszTmpを連結.

				// lpcs->xの値をtszMsgに連結.
				_stprintf(tszTmp, _T("\nlpcs->x = %d"), lpcs->x);	// _stprintfでtszTmpにlpcs->xの値をセット.
				_tcscat(tszMsg, tszTmp);	// _tcscatでtszMsgにtszTmpを連結.

				// lpcs->yの値をtszMsgに連結.
				_stprintf(tszTmp, _T("\nlpcs->y = %d"), lpcs->y);	// _stprintfでtszTmpにlpcs->yの値をセット.
				_tcscat(tszMsg, tszTmp);	// _tcscatでtszMsgにtszTmpを連結.

				// 渡されたCREATESTRUCTの内容の一部を表示.
				MessageBox(hwnd, tszMsg, _T("WM_CREATE"), MB_OK | MB_ICONASTERISK);	// MessageBoxでtszMsgの内容を表示.

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

		// 上記以外の時.
		default:	// 上記以外の値の時の既定処理.

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

	}

	// あとは既定の処理に任せる.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// 戻り値も含めDefWindowProcに既定の処理を任せる.

}