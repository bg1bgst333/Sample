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
	wc.lpszClassName = _T("GradientFill");						// ウィンドウクラス名を"GradientFill".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("GradientFill"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("GradientFill"), _T("GradientFill"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"GradientFill"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL) {	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("GradientFill"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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
				HDC hDC;				// デバイスコンテキストハンドルを格納するHDC型変数hDC.
				PAINTSTRUCT ps;			// ペイント情報を管理するPAINTSTRUCT構造体型の変数ps.
				TRIVERTEX vertH[2];		// 水平グラデーション用の頂点2個を格納するTRIVERTEX構造体型配列.
				TRIVERTEX vertV[2];		// 垂直グラデーション用の頂点2個を格納するTRIVERTEX構造体型配列.
				GRADIENT_RECT gRect;	// 頂点配列のインデックスで矩形を指定するGRADIENT_RECT構造体型変数.
				LPCTSTR pszLabelH;		// 1つ目のラベル文字列.
				LPCTSTR pszLabelV;		// 2つ目のラベル文字列.

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にはデバイスコンテキストハンドルが返るので, hDCに格納.

				// 1つ目の矩形: GRADIENT_FILL_RECT_H(左から右へ, 青→橙の水平グラデーション).
				vertH[0].x = 70;			vertH[0].y = 80;		// 左上の頂点の座標.
				vertH[0].Red = 0x6400;		vertH[0].Green = 0x9600;	vertH[0].Blue = 0xE600;	vertH[0].Alpha = 0x0000;	// 左上の色(青, RGB成分は上位8ビットに格納する).
				vertH[1].x = 330;			vertH[1].y = 340;		// 右下の頂点の座標.
				vertH[1].Red = 0xE600;		vertH[1].Green = 0x8C00;	vertH[1].Blue = 0x3C00;	vertH[1].Alpha = 0x0000;	// 右下の色(橙).
				gRect.UpperLeft = 0;		gRect.LowerRight = 1;	// vertHのインデックス0を左上, 1を右下として矩形を指定.
				GradientFill(hDC, vertH, 2, &gRect, 1, GRADIENT_FILL_RECT_H);	// GradientFillでGRADIENT_FILL_RECT_H(水平方向のグラデーション)を指定して描画.

				// 2つ目の矩形: GRADIENT_FILL_RECT_V(上から下へ, 青→橙の垂直グラデーション).
				vertV[0].x = 430;			vertV[0].y = 80;		// 左上の頂点の座標.
				vertV[0].Red = 0x6400;		vertV[0].Green = 0x9600;	vertV[0].Blue = 0xE600;	vertV[0].Alpha = 0x0000;	// 左上の色(青).
				vertV[1].x = 690;			vertV[1].y = 340;		// 右下の頂点の座標.
				vertV[1].Red = 0xE600;		vertV[1].Green = 0x8C00;	vertV[1].Blue = 0x3C00;	vertV[1].Alpha = 0x0000;	// 右下の色(橙).
				gRect.UpperLeft = 0;		gRect.LowerRight = 1;	// vertVのインデックス0を左上, 1を右下として矩形を指定.
				GradientFill(hDC, vertV, 2, &gRect, 1, GRADIENT_FILL_RECT_V);	// GradientFillでGRADIENT_FILL_RECT_V(垂直方向のグラデーション)を指定して描画.

				// 説明用のラベルを表示.(文字数は必ずlstrlenで計算し, 手打ちの数え間違いを防ぐ.)
				pszLabelH = _T("GRADIENT_FILL_RECT_H");	// 1つ目のラベル文字列.
				pszLabelV = _T("GRADIENT_FILL_RECT_V");	// 2つ目のラベル文字列.
				TextOut(hDC, 70, 360, pszLabelH, lstrlen(pszLabelH));	// TextOutで1つ目のラベルを表示.
				TextOut(hDC, 430, 360, pszLabelV, lstrlen(pszLabelV));	// TextOutで2つ目のラベルを表示.

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
