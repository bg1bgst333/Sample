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
	wc.lpszClassName = _T("ExtFloodFill");						// ウィンドウクラス名を"ExtFloodFill".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("ExtFloodFill"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("ExtFloodFill"), _T("ExtFloodFill"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"ExtFloodFill"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL) {	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("ExtFloodFill"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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
				HPEN hPenBlack;			// 黒い輪郭線用のHPEN型変数.
				HPEN hPenOld;			// 退避用のHPEN型変数.
				HBRUSH hBrushNull;		// 中身を塗らないNULL_BRUSHを格納するHBRUSH型変数.
				HBRUSH hBrushOld;		// 退避用のHBRUSH型変数.
				HBRUSH hBrushGreen;		// 左半分用の黄緑色ブラシを格納するHBRUSH型変数.
				HBRUSH hBrushYellow;	// 右半分用の黄色ブラシを格納するHBRUSH型変数.
				LPCTSTR pszLabelBorder;	// 1つ目のラベル文字列.
				LPCTSTR pszLabelSurface;	// 2つ目のラベル文字列.

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にはデバイスコンテキストハンドルが返るので, hDCに格納.

				// 1つ目: FLOODFILLBORDER(境界塗りつぶし). 黒い輪郭線だけの楕円(中身は白)を描いてから, 内側を紫色で境界塗りつぶしする.
				hPenBlack = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));	// CreatePenで黒の実線ペンを作成.
				hPenOld = (HPEN)SelectObject(hDC, hPenBlack);		// SelectObjectで黒ペンを選択し, 元のペンをhPenOldに退避.
				hBrushNull = (HBRUSH)GetStockObject(NULL_BRUSH);	// GetStockObjectでNULL_BRUSH(塗りつぶし無し)を取得.
				hBrushOld = (HBRUSH)SelectObject(hDC, hBrushNull);	// SelectObjectでNULL_BRUSHを選択し, 元のブラシをhBrushOldに退避.
				Ellipse(hDC, 100, 80, 400, 330);					// Ellipseで黒い輪郭線だけの楕円を描画.(中身は背景の白のまま.)
				SelectObject(hDC, hBrushOld);						// SelectObjectで元のブラシに戻す.
				SelectObject(hDC, hPenOld);						// SelectObjectで元のペンに戻す.
				DeleteObject(hPenBlack);							// DeleteObjectで黒ペンを破棄.

				hBrushOld = (HBRUSH)SelectObject(hDC, CreateSolidBrush(RGB(200, 170, 230)));	// SelectObjectで紫色のブラシを選択し, 元のブラシをhBrushOldに退避.
				ExtFloodFill(hDC, 250, 200, RGB(0, 0, 0), FLOODFILLBORDER);	// ExtFloodFillでFLOODFILLBORDERを指定し, 楕円の内側(250,200)から黒い境界に突き当たるまで紫色で塗りつぶす.
				DeleteObject(SelectObject(hDC, hBrushOld));		// SelectObjectで元のブラシに戻しつつ, 戻り値(紫色ブラシ)をDeleteObjectで破棄.

				// 2つ目: FLOODFILLSURFACE(同色塗りつぶし). 黄緑色と黄色の2色に分かれた矩形を描いてから, 黄緑色の領域だけを同色塗りつぶしで赤に変える.(境界線は無い.)
				hBrushGreen = CreateSolidBrush(RGB(200, 230, 170));	// CreateSolidBrushで黄緑色のブラシを作成.
				hBrushOld = (HBRUSH)SelectObject(hDC, hBrushGreen);	// SelectObjectで黄緑色のブラシを選択し, 元のブラシをhBrushOldに退避.
				Rectangle(hDC, 450, 80, 600, 330);					// Rectangleで左半分(黄緑色)を描画.
				SelectObject(hDC, hBrushOld);						// SelectObjectで元のブラシに戻す.
				DeleteObject(hBrushGreen);							// DeleteObjectで黄緑色ブラシを破棄.

				hBrushYellow = CreateSolidBrush(RGB(250, 240, 180));	// CreateSolidBrushで黄色のブラシを作成.
				hBrushOld = (HBRUSH)SelectObject(hDC, hBrushYellow);	// SelectObjectで黄色のブラシを選択し, 元のブラシをhBrushOldに退避.
				Rectangle(hDC, 600, 80, 750, 330);					// Rectangleで右半分(黄色)を描画.(黄緑色との境界線は引かない, 色の違いだけが境目.)
				SelectObject(hDC, hBrushOld);						// SelectObjectで元のブラシに戻す.
				DeleteObject(hBrushYellow);							// DeleteObjectで黄色ブラシを破棄.

				hBrushOld = (HBRUSH)SelectObject(hDC, CreateSolidBrush(RGB(230, 80, 80)));	// SelectObjectで赤色のブラシを選択し, 元のブラシをhBrushOldに退避.
				ExtFloodFill(hDC, 500, 200, RGB(200, 230, 170), FLOODFILLSURFACE);	// ExtFloodFillでFLOODFILLSURFACEを指定し, 黄緑色の領域(500,200)と同じ色が続く範囲だけを赤色で塗りつぶす.(境界線が無くても, 色が黄緑色でなくなった時点で止まる.)
				DeleteObject(SelectObject(hDC, hBrushOld));		// SelectObjectで元のブラシに戻しつつ, 戻り値(赤色ブラシ)をDeleteObjectで破棄.

				// 説明用のラベルを表示.(文字数は必ずlstrlenで計算し, 手打ちの数え間違いを防ぐ.)
				pszLabelBorder = _T("FLOODFILLBORDER");	// 1つ目のラベル文字列.
				pszLabelSurface = _T("FLOODFILLSURFACE");	// 2つ目のラベル文字列.
				TextOut(hDC, 100, 350, pszLabelBorder, lstrlen(pszLabelBorder));	// TextOutで1つ目のラベルを表示.
				TextOut(hDC, 450, 350, pszLabelSurface, lstrlen(pszLabelSurface));	// TextOutで2つ目のラベルを表示.

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
