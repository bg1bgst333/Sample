// ヘッダファイルのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <windowsx.h>	// GET_X_LPARAM, GET_Y_LPARAMマクロ
#include <tchar.h>		// TCHAR型

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理ができるように定義するコールバック関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// 変数の宣言
	HWND hWnd;			// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;			// ウィンドウメッセージを格納するMSG構造体型変数msg.
	WNDCLASS wc;		// ウィンドウクラスを格納するWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("OffsetRgn");						// ウィンドウクラス名は"OffsetRgn".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("OffsetRgn"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("OffsetRgn"), _T("OffsetRgn"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"OffsetRgn"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL) {	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("OffsetRgn"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowにSW_SHOWを指定してウィンドウの表示.

	// メッセージループ
	while (GetMessage(&msg, NULL, 0, 0) > 0) {	// GetMessageでメッセージを取得し, 戻り値が0より大きい間はループを続ける.

		// ウィンドウメッセージの送出
		DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(今回は独自に定義するWindowProc)に送出.

	}

	// プログラムの終了
	return (int)msg.wParam;	// 終了コード(msg.wParam)を戻り値として返す.

}

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {	// ウィンドウメッセージに対して独自の処理ができるように定義するウィンドウプロシージャ.

	// static変数の宣言
	static HRGN hRgnTest = NULL;	// OffsetRgnで動かす対象の角丸リージョンを格納するHRGN型変数hRgnTest.
	static int nLastX = 500;		// 直前のマウスのクライアントX座標を格納するint型変数nLastX.(初期値は, WM_CREATEで作ったリージョンの中心のX座標(500)にしておく.)
	static int nLastY = 300;		// 直前のマウスのクライアントY座標を格納するint型変数nLastY.(初期値は, WM_CREATEで作ったリージョンの中心のY座標(300)にしておく.)

	// ウィンドウメッセージに対する処理.
	switch (uMsg) {	// switch-case文でuMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始されたとき.
		case WM_CREATE:		// ウィンドウの作成が開始されたとき.(uMsgがWM_CREATEの場合.)

			// WM_CREATEブロック
			{

				// 動かす対象の角丸リージョンの作成
				hRgnTest = CreateRoundRectRgn(400, 225, 600, 375, 60, 60);	// CreateRoundRectRgnで(400,225)から(600,375)までの矩形を元に, 幅60・高さ60の楕円で角を丸めたリージョンを作成.

				// ウィンドウ作成続行
				return 0;	// returnして0を返すと, ウィンドウ作成を続けるとする.

			}

			// 既定の処理へ続ける.
			break;	// breakで抜けると, 既定の処理(DefWindowProc)へ続ける.

		// ウィンドウが破棄されたとき.
		case WM_DESTROY:	// ウィンドウが破棄されたとき.(uMsgがWM_DESTROYの場合.)

			// WM_DESTROYブロック
			{

				// 動かす対象のリージョンの破棄
				if (hRgnTest != NULL) {	// hRgnTestが作成済みなら.

					DeleteObject(hRgnTest);	// DeleteObjectでリージョンを破棄.
					hRgnTest = NULL;			// 破棄済みを示すためNULLに戻す.

				}

				// メッセージループを抜ける.
				PostQuitMessage(0);	// PostQuitMessageで終了コードを0とするWM_QUITメッセージを送信.(これでメッセージループのGetMessageの戻り値が0になるので, メッセージループから抜ける.)

			}

			// 既定の処理へ続ける.
			break;	// breakで抜けると, 既定の処理(DefWindowProc)へ続ける.

		// マウスが移動したとき.
		case WM_MOUSEMOVE:	// マウスが移動したとき.(uMsgがWM_MOUSEMOVEの場合.)

			// WM_MOUSEMOVEブロック
			{

				// このブロックのローカル変数の宣言.
				int x;	// マウスの今回のクライアントX座標を格納するint型変数.
				int y;	// マウスの今回のクライアントY座標を格納するint型変数.
				int dx;	// 前回からのX方向の移動量を格納するint型変数.
				int dy;	// 前回からのY方向の移動量を格納するint型変数.

				// 今回のマウス座標を取得.
				x = GET_X_LPARAM(lParam);	// GET_X_LPARAMでクライアント座標のX値を取得.
				y = GET_Y_LPARAM(lParam);	// GET_Y_LPARAMでクライアント座標のY値を取得.

				// 前回位置との差分をOffsetRgnでリージョンに反映する.(OffsetRgnは絶対位置ではなく, 今の位置からの相対移動量を指定する点に注意. nLastX/Yの初期値をリージョンの中心に合わせてあるので, 最初の1回目から正しく動く.)
				dx = x - nLastX;			// 前回からのX方向の移動量を計算.
				dy = y - nLastY;			// 前回からのY方向の移動量を計算.
				OffsetRgn(hRgnTest, dx, dy);	// OffsetRgnでhRgnTestをdx・dy分だけ移動させる.(新しい位置で作り直すのではなく, 今の位置から相対的にずらす.)

				// 今回のマウス座標を次回のために保存.
				nLastX = x;	// nLastXを今回のxで更新.
				nLastY = y;	// nLastYを今回のyで更新.

				// 移動結果を画面に反映させるため再描画を要求.
				InvalidateRect(hwnd, NULL, TRUE);	// InvalidateRectでクライアント領域全体を無効化し, 再描画(WM_PAINT)を要求.

			}

			// 既定の処理へ続ける.
			break;	// breakで抜けると, 既定の処理(DefWindowProc)へ続ける.

		// 画面の描画が求められたとき.
		case WM_PAINT:		// 画面の描画が求められたとき.(uMsgがWM_PAINTの場合.)

			// WM_PAINTブロック
			{

				// このブロックのローカル変数の宣言と初期化.
				HDC hDC;			// デバイスコンテキストハンドルを格納するHDC型変数hDC.
				PAINTSTRUCT ps;		// ペイント処理を管理するPAINTSTRUCT構造体型の変数ps.
				HBRUSH hBrushTest;	// 動かす対象のリージョンを塗るためのブラシを格納するHBRUSH型変数.
				TCHAR tszStatus[64];	// マウス座標の文字列を格納するTCHAR型配列.
				LPCTSTR pszFormat;	// wsprintfに渡す書式文字列.

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にはデバイスコンテキストハンドルが返るので, hDCに格納.

				// 動かす対象のリージョンを, 今の位置のまま水色で塗りつぶす.
				hBrushTest = CreateSolidBrush(RGB(80, 160, 210));	// CreateSolidBrushで水色のブラシを作成.
				FillRgn(hDC, hRgnTest, hBrushTest);					// FillRgnでhRgnTestを今の位置のまま塗りつぶす.(OffsetRgnで動かした分がそのまま描画に反映される.)
				DeleteObject(hBrushTest);								// DeleteObjectで使い終わったブラシを破棄.

				// 現在のマウス座標を文字列で表示.(文字数は必ずlstrlenで計算する.)
				pszFormat = _T("mouse = (%d, %d)");					// wsprintfに渡す書式文字列.
				wsprintf(tszStatus, pszFormat, nLastX, nLastY);		// wsprintfで現在のマウス座標の文字列を組み立てる.
				TextOut(hDC, 150, 420, tszStatus, lstrlen(tszStatus));	// TextOutで組み立てた文字列を表示.

				// ウィンドウの描画終了
				EndPaint(hwnd, &ps);	// EndPaintでこのウィンドウの描画処理を終了させる.

			}

			// 既定の処理へ続ける.
			break;	// breakで抜けると, 既定の処理(DefWindowProc)へ続ける.

		// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりしたとき.
		case WM_COMMAND:	// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりしたとき.(uMsgがWM_COMMANDの場合.)

			// 既定の処理へ続ける.
			break;	// breakで抜けると, 既定の処理(DefWindowProc)へ続ける.

		// 上記以外の場合.
		default:	// 上記以外の値の場合の既定処理.

			// 既定の処理へ続ける.
			break;	// breakで抜けると, 既定の処理(DefWindowProc)へ続ける.

	}

	// あとは既定の処理に任せる.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// 戻り値も含めてDefWindowProcに既定の処理を任せる.

}
