// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <windowsx.h>	// GET_X_LPARAM, GET_Y_LPARAMマクロ
#include <tchar.h>		// TCHAR型

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理をするように定義するコールバック関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// 変数の宣言
	HWND hWnd;			// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;			// ウィンドウメッセージを格納するMSG構造体型変数msg.
	WNDCLASS wc;		// ウィンドウクラスを格納するWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("PtInRegion");						// ウィンドウクラス名は"PtInRegion".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;							// ウィンドウプロシージャは独自の処理を定義したWindowProc.
	wc.hInstance = hInstance;								// インスタンスハンドルは_tWinMainの引数.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// アイコンはアプリケーション既定のもの.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// カーソルは矢印.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 背景は白ブラシ.
	wc.lpszMenuName = NULL;									// メニューは無し.
	wc.cbClsExtra = 0;										// 0でよい.
	wc.cbWndExtra = 0;										// 0でよい.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)) {	// RegisterClassでウィンドウクラスを登録し, 0が返ってきたらエラー.

		// エラー処理
		MessageBox(NULL, _T("RegisterClass failed!"), _T("PtInRegion"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("PtInRegion"), _T("PtInRegion"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"PtInRegion"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL) {	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("PtInRegion"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.

	// メッセージループ
	while (GetMessage(&msg, NULL, 0, 0) > 0) {	// GetMessageでメッセージを取得し, 戻り値が0より大きい間はループを続ける.

		// ウィンドウメッセージの送出
		DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(今回は独自に定義したWindowProc)に送出.

	}

	// プログラムの終了
	return (int)msg.wParam;	// 終了コード(msg.wParam)を戻り値として返す.

}

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {	// ウィンドウメッセージに対して独自の処理をするように定義したウィンドウプロシージャ.

	// static変数の宣言
	static HRGN hRgnTest = NULL;	// PtInRegionで判定対象にする角丸リージョンを格納するHRGN型変数hRgnTest.
	static BOOL bInside = FALSE;	// 直前のマウス座標がhRgnTestの内側だったかどうかを格納するBOOL型変数bInside.
	static POINT ptMouse = { 0, 0 };	// 直前のマウス座標を格納するPOINT型変数ptMouse.

	// ウィンドウメッセージに対する処理.
	switch (uMsg) {	// switch-case文でuMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始されたとき.
		case WM_CREATE:		// ウィンドウの作成が開始されたとき.(uMsgがWM_CREATEの場合.)

			// WM_CREATEブロック
			{

				// 判定対象の角丸リージョンの作成
				hRgnTest = CreateRoundRectRgn(150, 100, 650, 350, 80, 80);	// CreateRoundRectRgnで(150,100)から(650,350)までの矩形から, 幅80・高さ80の楕円で角を丸めたリージョンを作成.

				// ウィンドウ作成成功
				return 0;	// return文で0を返して, ウィンドウ作成成功とする.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// ウィンドウが破棄されたとき.
		case WM_DESTROY:	// ウィンドウが破棄されたとき.(uMsgがWM_DESTROYの場合.)

			// WM_DESTROYブロック
			{

				// 判定対象のリージョンの破棄
				if (hRgnTest != NULL) {	// hRgnTestが作成済みなら.

					DeleteObject(hRgnTest);	// DeleteObjectでリージョンを破棄.
					hRgnTest = NULL;			// 破棄済みを示すためNULLに戻す.

				}

				// メッセージループを抜ける.
				PostQuitMessage(0);	// PostQuitMessageで終了コードを0としてWM_QUITメッセージを送信.(これでメッセージループのGetMessageの戻り値が0になるので, メッセージループから抜ける.)

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// マウスが移動したとき.
		case WM_MOUSEMOVE:	// マウスが移動したとき.(uMsgがWM_MOUSEMOVEの場合.)

			// WM_MOUSEMOVEブロック
			{

				// マウス座標がリージョンの内側かどうかをPtInRegionで判定.
				ptMouse.x = GET_X_LPARAM(lParam);	// GET_X_LPARAMでクライアント座標のX値を取得.
				ptMouse.y = GET_Y_LPARAM(lParam);	// GET_Y_LPARAMでクライアント座標のY値を取得.
				bInside = PtInRegion(hRgnTest, ptMouse.x, ptMouse.y);	// PtInRegionで(ptMouse.x, ptMouse.y)がhRgnTestの内側かどうかを判定し, 結果をbInsideに格納.

				// 判定結果を画面に反映させるため再描画を要求.
				InvalidateRect(hwnd, NULL, TRUE);	// InvalidateRectでクライアント領域全体を無効化し, 再描画(WM_PAINT)を要求.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// 画面の描画が求められたとき.
		case WM_PAINT:		// 画面の描画が求められたとき.(uMsgがWM_PAINTの場合.)

			// WM_PAINTブロック
			{

				// このブロックのローカル変数の宣言と初期化.
				HDC hDC;			// デバイスコンテキストハンドルを格納するHDC型変数hDC.
				PAINTSTRUCT ps;		// ペイント情報を管理するPAINTSTRUCT構造体型の変数ps.
				HBRUSH hBrushResult;	// 判定結果に応じた色のブラシを格納するHBRUSH型変数.
				TCHAR tszStatus[128];	// 判定結果の文字列を格納するTCHAR型配列.
				LPCTSTR pszFormat;	// wsprintfに渡す書式文字列.

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にデバイスコンテキストハンドルが返るので, hDCに格納.

				// 判定結果(内側か外側か)に応じてリージョンを塗る色を変える.
				hBrushResult = CreateSolidBrush(bInside ? RGB(50, 170, 70) : RGB(190, 60, 60));	// 内側なら緑, 外側なら赤のブラシを作成.
				FillRgn(hDC, hRgnTest, hBrushResult);										// FillRgnでリージョンをhBrushResultで塗る.
				DeleteObject(hBrushResult);													// DeleteObjectで使い終わったブラシを破棄.

				// マウス座標と判定結果を文字列で表示.(文字数は必ずlstrlenで計算する.)
				pszFormat = _T("mouse = (%d, %d)  PtInRegion = %s");			// wsprintfに渡す書式文字列.
				wsprintf(tszStatus, pszFormat, ptMouse.x, ptMouse.y, bInside ? _T("INSIDE") : _T("OUTSIDE"));	// wsprintfで判定結果の文字列を組み立てる.
				TextOut(hDC, 150, 370, tszStatus, lstrlen(tszStatus));			// TextOutで組み立てた文字列を表示.

				// ウィンドウの描画終了
				EndPaint(hwnd, &ps);	// EndPaintでこのウィンドウの描画処理を終了する.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりしたとき.
		case WM_COMMAND:	// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりしたとき.(uMsgがWM_COMMANDの場合.)

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// 上記以外の場合.
		default:	// 上記以外の値の場合の既定処理.

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

	}

	// あとは既定の処理に任せる.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// 戻り値もまるごとDefWindowProcに既定の処理を任せる.

}
