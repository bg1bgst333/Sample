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
	wc.lpszClassName = _T("CreatePolyPolygonRgn");				// ウィンドウクラス名を"CreatePolyPolygonRgn".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("CreatePolyPolygonRgn"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("CreatePolyPolygonRgn"), _T("CreatePolyPolygonRgn"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"CreatePolyPolygonRgn"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL) {	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("CreatePolyPolygonRgn"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.

	// メッセージループ
	while (GetMessage(&msg, NULL, 0, 0) > 0) {	// GetMessageでメッセージを取得し, 戻り値が0より大きい間はループし続ける.

		// ウィンドウメッセージの送出
		DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(今回は独自に定義したWindowProc)に送出.

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

				// ウィンドウ作成成功
				return 0;	// return文で0を返して, ウィンドウ作成成功とする.

			}

			// 既定の処理へ続く.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ続く.

		// ウィンドウが破棄されたとき.
		case WM_DESTROY:	// ウィンドウが破棄されたとき.(uMsgがWM_DESTROYの場合.)

			// WM_DESTROYブロック
			{

				// メッセージループを抜ける.
				PostQuitMessage(0);	// PostQuitMessageで終了コードを0としてWM_QUITメッセージを送信.(これでメッセージループのGetMessageの戻り値が0になるので, メッセージループから抜ける.)

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
				POINT points[8];		// 外側の四角形4頂点+内側の四角形4頂点を格納するPOINT構造体型配列.
				INT polyCounts[2];		// 各多角形の頂点数(今回はどちらも4)を格納するINT型配列.
				HRGN hRgnAlt;			// ALTERNATE(交差ルール)で作成するリージョンを格納するHRGN型変数.
				HRGN hRgnWind;			// WINDING(非ゼロ巻数ルール)で作成するリージョンを格納するHRGN型変数.
				HBRUSH hBrushOrange;	// 塗りつぶし用の橙色ブラシを格納するHBRUSH型変数.
				int i;					// ループカウンタ用のint型変数.
				LPCTSTR pszLabelAlt;	// 1つ目のラベル文字列.
				LPCTSTR pszLabelWind;	// 2つ目のラベル文字列.

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にはデバイスコンテキストハンドルが返るので, hDCに格納.

				hBrushOrange = CreateSolidBrush(RGB(230, 150, 60));	// CreateSolidBrushで橙色のブラシを作成.

				// 1つ目(左): 外側の四角形と内側の四角形(どちらも左回り)をまとめてALTERNATEでリージョン化.(2つの輪郭の交差回数が偶数になる内側の四角形部分は塗られずに穴になる.)
				polyCounts[0] = 4;	// 1つ目の多角形(外側の四角形)の頂点数.
				polyCounts[1] = 4;	// 2つ目の多角形(内側の四角形)の頂点数.
				points[0].x = 100;	points[0].y = 100;	// 外側の四角形の4頂点.
				points[1].x = 300;	points[1].y = 100;
				points[2].x = 300;	points[2].y = 300;
				points[3].x = 100;	points[3].y = 300;
				points[4].x = 150;	points[4].y = 150;	// 内側の四角形の4頂点.(外側と同じ向きで用意する.)
				points[5].x = 250;	points[5].y = 150;
				points[6].x = 250;	points[6].y = 250;
				points[7].x = 150;	points[7].y = 250;
				hRgnAlt = CreatePolyPolygonRgn(points, polyCounts, 2, ALTERNATE);	// CreatePolyPolygonRgnで2つの四角形をまとめ, ALTERNATEモードでリージョンを作成.
				FillRgn(hDC, hRgnAlt, hBrushOrange);									// FillRgnで作成したリージョンを橙色のブラシで塗りつぶす.
				DeleteObject(hRgnAlt);													// DeleteObjectで使い終わったリージョンを破棄.

				// 2つ目(右): 同じ8頂点をそのまま右へずらし, 今度はWINDINGでリージョン化.(外側・内側とも同じ向きのため, 内側部分の巻数が2になり非ゼロ扱いで塗りつぶされ, 穴が無くなる.)
				for (i = 0; i < 8; i++) {	// forループで8頂点すべてに対して処理.

					points[i].x += 450;	// 右側に表示するため, X座標を450だけ右へずらす.

				}
				hRgnWind = CreatePolyPolygonRgn(points, polyCounts, 2, WINDING);	// CreatePolyPolygonRgnで同じ2つの四角形をまとめ, WINDINGモードでリージョンを作成.
				FillRgn(hDC, hRgnWind, hBrushOrange);									// FillRgnで作成したリージョンを橙色のブラシで塗りつぶす.
				DeleteObject(hRgnWind);												// DeleteObjectで使い終わったリージョンを破棄.

				DeleteObject(hBrushOrange);	// DeleteObjectで橙色ブラシを破棄.

				// 説明用のラベルを表示.(文字数は必ずlstrlenで計算する.)
				pszLabelAlt = _T("ALTERNATE (hole in center)");	// 1つ目のラベル文字列.
				pszLabelWind = _T("WINDING (filled solid)");		// 2つ目のラベル文字列.
				TextOut(hDC, 80, 330, pszLabelAlt, lstrlen(pszLabelAlt));		// TextOutで1つ目のラベルを表示.
				TextOut(hDC, 530, 330, pszLabelWind, lstrlen(pszLabelWind));	// TextOutで2つ目のラベルを表示.

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
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// 戻り値もまるごとDefWindowProcに既定の処理を任せる.

}
