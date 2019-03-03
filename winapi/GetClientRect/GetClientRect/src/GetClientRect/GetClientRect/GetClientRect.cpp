// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <string.h>		// C文字列処理

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理をするように定義したコールバック関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// 変数の宣言
	HWND hWnd;			// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;			// ウィンドウメッセージ情報を格納するMSG構造体型変数msg.
	WNDCLASS wc;		// ウィンドウクラス情報をもつWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("GetClientRect");					// ウィンドウクラス名は"GetClientRect".
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
	if (!RegisterClass(&wc)) {	// RegisterClassでウィンドウクラスを登録し, 0が返ったらエラー.

		// エラー処理
		MessageBox(NULL, _T("RegisterClass failed!"), _T("GetClientRect"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("GetClientRect"), _T("GetClientRect"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"GetClientRect"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL) {	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("GetClientRect"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.

	// メッセージループ
	while (GetMessage(&msg, NULL, 0, 0) > 0) {	// GetMessageでメッセージを取得, 戻り値が0より大きい間はループし続ける.

		// ウィンドウメッセージの送出
		DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(この場合は独自に定義したWindowProc)に送出.

	}

	// プログラムの終了
	return (int)msg.wParam;	// 終了コード(msg.wParam)を戻り値として返す.

}

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {	// ウィンドウメッセージに対して独自の処理をするように定義したウィンドウプロシージャ.

	// スタティック変数の宣言
	static RECT rcWmSize;	// WM_SIZEで渡されたRECTを持つrcWmSize.
	static RECT rcClient;	// GetClientRectで取得したRECTを持つrcClient.

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

				// 終了メッセージの送信.
				PostQuitMessage(0);	// PostQuitMessageで終了コードを0としてWM_QUITメッセージを送信.(するとメッセージループのGetMessageの戻り値が0になるので, メッセージループから抜ける.)

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// 画面の描画を要求された時.
		case WM_PAINT:		// 画面の描画を要求された時.(uMsgがWM_PAINTの時.)

			// WM_PAINTブロック
			{

				// このブロックのローカル変数・配列の宣言と初期化.
				HDC hDC;		// デバイスコンテキストハンドルを格納するHDC型変数hDC.
				PAINTSTRUCT ps;	// ペイント情報を管理するPAINTSTRUCT構造体型の変数ps.

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にはデバイスコンテキストハンドルが返るので, hDCに格納.

				// WM_SIZEの時に渡された矩形情報の描画.
				SetTextColor(hDC, RGB(0xff, 0x00, 0x00));	// SetTextColorで赤をセット.
				TCHAR tszWmSizeLeft[64] = {0};	// tszWmSizeLeftを0で初期化.
				_stprintf(tszWmSizeLeft, _T("rcWmSize.left = %d"), rcWmSize.left);	// rcWmSize.leftを文字列に変換.
				TextOut(hDC, 0, 0, tszWmSizeLeft, _tcslen(tszWmSizeLeft));	// TextOutでtszWmSizeLeftの描画.
				TCHAR tszWmSizeTop[64] = {0};	// tszWmSizeTopを0で初期化.
				_stprintf(tszWmSizeTop, _T("rcWmSize.top = %d"), rcWmSize.top);	// rcWmSize.topを文字列に変換.
				TextOut(hDC, 0, 25, tszWmSizeTop, _tcslen(tszWmSizeTop));	// TextOutでtszWmSizeTopの描画.
				TCHAR tszWmSizeRight[64] = {0};	// tszWmSizeRightを0で初期化.
				_stprintf(tszWmSizeRight, _T("rcWmSize.right = %d"), rcWmSize.right);	// rcWmSize.rightを文字列に変換.
				TextOut(hDC, 0, 50, tszWmSizeRight, _tcslen(tszWmSizeRight));	// TextOutでtszWmSizeRightの描画.
				TCHAR tszWmSizeBottom[64] = {0};	// tszWmSizeBottomを0で初期化.
				_stprintf(tszWmSizeBottom, _T("rcWmSize.bottom = %d"), rcWmSize.bottom);	// rcWmSize.bottomを文字列に変換.
				TextOut(hDC, 0, 75, tszWmSizeBottom, _tcslen(tszWmSizeBottom));	// TextOutでtszWmSizeBottomの描画.

				// GetClientRectで取得した矩形情報の描画.
				SetTextColor(hDC, RGB(0x00, 0x00, 0xff));	// SetTextColorで青をセット.
				TCHAR tszClientLeft[64] = {0};	// tszClientLeftを0で初期化.
				_stprintf(tszClientLeft, _T("rcClient.left = %d"), rcClient.left);	// rcClient.leftを文字列に変換.
				TextOut(hDC, 0, 125, tszClientLeft, _tcslen(tszClientLeft));	// TextOutでtszClientLeftの描画.
				TCHAR tszClientTop[64] = {0};	// tszClientTopを0で初期化.
				_stprintf(tszClientTop, _T("rcClient.top = %d"), rcClient.top);	// rcClient.topを文字列に変換.
				TextOut(hDC, 0, 150, tszClientTop, _tcslen(tszClientTop));	// TextOutでtszClientTopの描画.
				TCHAR tszClientRight[64] = {0};	// tszClientRightを0で初期化.
				_stprintf(tszClientRight, _T("rcClient.right = %d"), rcClient.right);	// rcClient.rightを文字列に変換.
				TextOut(hDC, 0, 175, tszClientRight, _tcslen(tszClientRight));	// TextOutでtszClientRightの描画.
				TCHAR tszClientBottom[64] = {0};	// tszClientBottomを0で初期化.
				_stprintf(tszClientBottom, _T("rcClient.bottom = %d"), rcClient.bottom);	// rcClient.bottomを文字列に変換.
				TextOut(hDC, 0, 200, tszClientBottom, _tcslen(tszClientBottom));	// TextOutでtszClientBottomの描画.

				// ウィンドウの描画終了
				EndPaint(hwnd, &ps);	// EndPaintでこのウィンドウの描画処理を終了する.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// ウィンドウのサイズが変更された時.
		case WM_SIZE:	// ウィンドウのサイズが変更された時.(uMsgがWM_SIZEの時.)

			// WM_SIZEブロック
			{

				// クライアント領域の変更後のサイズを取得.
				rcWmSize.left = 0;	// これは0.
				rcWmSize.top = 0;	// これも0.
				rcWmSize.right = LOWORD(lParam);		// LOWORD(lParam)でクライアント領域の幅を取得.
				rcWmSize.bottom = HIWORD(lParam);	// HIWORD(lParam)でクライアント領域の高さを取得.

				// クライアント領域の矩形情報を取得.
				GetClientRect(hwnd, &rcClient);	// GetClientRectでウィンドウ矩形情報を取得し, rcClientに格納.

				// 画面の更新
				InvalidateRect(hwnd, NULL, TRUE);	// InvalidateRectでクライアント領域全体を更新.

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