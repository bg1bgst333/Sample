// ヘッダファイルのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
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
	wc.lpszClassName = _T("FloodFill");						// ウィンドウクラス名を"FloodFill".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;							// ウィンドウプロシージャは独自の処理を定義するWindowProc.
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("FloodFill"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("FloodFill"), _T("FloodFill"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"FloodFill"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL) {	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("FloodFill"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.

	// メッセージループ
	while (GetMessage(&msg, NULL, 0, 0) > 0) {	// GetMessageでメッセージを取得し, 戻り値が0より大きい間はループを続ける.

		// ウィンドウメッセージの送出
		DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(今回の場合は独自に定義するWindowProc)に送出.

	}

	// プログラムの終了
	return (int)msg.wParam;	// 終了コード(msg.wParam)を戻り値として返す.

}

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {	// ウィンドウメッセージに対して独自の処理ができるように定義するウィンドウプロシージャ.

	// ウィンドウメッセージに対する処理.
	switch (uMsg) {	// switch-case文でuMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始されたとき.
		case WM_CREATE:		// ウィンドウの作成が開始されたとき.(uMsgがWM_CREATEの場合.)

			// WM_CREATEブロック
			{

				// ウィンドウ作成続行
				return 0;	// returnで0を返して, ウィンドウ作成続行とする.

			}

			// 既定の処理へ続く.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ続く.

		// ウィンドウが破棄されたとき.
		case WM_DESTROY:	// ウィンドウが破棄されたとき.(uMsgがWM_DESTROYの場合.)

			// WM_DESTROYブロック
			{

				// 終了メッセージの送信.
				PostQuitMessage(0);	// PostQuitMessageで終了コードを0とするWM_QUITメッセージを送信.(これでメッセージループのGetMessageの戻り値が0になるので, メッセージループから抜ける.)

			}

			// 既定の処理へ続く.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ続く.

		// 画面の描画が求められたとき.
		case WM_PAINT:		// 画面の描画が求められたとき.(uMsgがWM_PAINTの場合.)

			// WM_PAINTブロック
			{

				// このブロックのローカル変数・配列の宣言と初期化.
				HDC hDC;		// デバイスコンテキストハンドルを格納するHDC型変数hDC.
				PAINTSTRUCT ps;	// ペイント情報を管理するPAINTSTRUCT構造体型の変数ps.
				COLORREF crBorder;	// 境界線の色(黒)を格納するCOLORREF型変数.

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にはデバイスコンテキストハンドルが返るので, hDCに格納.

				// 黒い輪郭線だけの(中身が白い)楕円を描いておく.
				{

					HBRUSH hBrushOld;	// 退避用のHBRUSH型変数hBrushOld.
					crBorder = RGB(0, 0, 0);							// crBorderに黒(0, 0, 0)を格納.(輪郭線の色として使う.)
					hBrushOld = (HBRUSH)SelectObject(hDC, GetStockObject(NULL_BRUSH));	// SelectObjectでNULL_BRUSH(塗りつぶし無し)を選択し, 元のブラシをhBrushOldに退避.
					Ellipse(hDC, 100, 50, 400, 350);						// Ellipseで黒い輪郭線だけの楕円を描画.(既定のペインが黒のため, 輪郭線は黒になる.)
					SelectObject(hDC, hBrushOld);							// SelectObjectで元のブラシに戻す.

				}

				// FloodFill(本トピックの主役)で, 楕円の内側を紫色のブラシで塗りつぶす.
				{

					HBRUSH hBrushPurple;	// 塗りつぶし用のHBRUSH型変数hBrushPurple.
					HBRUSH hBrushOld;		// 退避用のHBRUSH型変数hBrushOld.
					hBrushPurple = CreateSolidBrush(RGB(200, 170, 230));	// CreateSolidBrushで紫色のブラシを作成.
					hBrushOld = (HBRUSH)SelectObject(hDC, hBrushPurple);	// SelectObjectで紫色ブラシを選択し, 元のブラシをhBrushOldに退避.

					// 塗りつぶしの実行
					FloodFill(hDC, 250, 200, crBorder);	// FloodFillで楕円の内側の1点(250, 200)から, 黒(crBorder)に囲まれた領域全体を, 現在のブラシ(紫色)で塗りつぶす.(境界(黒い輪郭線)に突き当たるまで塗り広がる.)

					SelectObject(hDC, hBrushOld);	// SelectObjectで元のブラシに戻す.
					DeleteObject(hBrushPurple);		// DeleteObjectで紫色ブラシを破棄.

				}

				// ウィンドウの描画終了
				EndPaint(hwnd, &ps);	// EndPaintでこのウィンドウの描画処理を終了させる.

			}

			// 既定の処理へ続く.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ続く.

		// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりしたとき.
		case WM_COMMAND:	// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりしたとき.(uMsgがWM_COMMANDの場合.)

			// 既定の処理へ続く.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ続く.

		// 上記以外の場合.
		default:	// 上記以外の値の場合の既定処理.

			// 既定の処理へ続く.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ続く.

	}

	// あとは既定の処理に任せる.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// 戻り値をまるごとDefWindowProcに既定の処理を任せる.

}
