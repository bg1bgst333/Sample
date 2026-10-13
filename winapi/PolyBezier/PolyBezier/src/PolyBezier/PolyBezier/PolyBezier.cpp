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
	wc.lpszClassName = _T("PolyBezier");						// ウィンドウクラス名を"PolyBezier".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("PolyBezier"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("PolyBezier"), _T("PolyBezier"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"PolyBezier"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL) {	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("PolyBezier"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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
				HDC hDC;			// デバイスコンテキストハンドルを格納するHDC型変数hDC.
				PAINTSTRUCT ps;		// ペイント情報を管理するPAINTSTRUCT構造体型の変数ps.
				HPEN hPenDot;		// 制御多角形用の点線ペンを格納するHPEN型変数.
				HPEN hPenRed;		// 制御点の丸用の赤色ペンを格納するHPEN型変数.
				HPEN hPenBlue;		// ベジェ曲線用の青色の太いペンを格納するHPEN型変数.
				HPEN hPenOld;		// 退避用のHPEN型変数.
				HBRUSH hBrushOld;	// 退避用のHBRUSH型変数.
				POINT points[4];	// PolyBezierに渡す4点(始点, 制御点1, 制御点2, 終点)を格納するPOINT構造体型配列.
				int i;				// ループカウンタ用のint型変数.
				LPCTSTR pszLabel;	// ラベル文字列.

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にはデバイスコンテキストハンドルが返るので, hDCに格納.

				// ベジェ曲線の4点(始点・制御点1・制御点2・終点)を用意する.
				points[0].x = 100;	points[0].y = 300;	// 始点.
				points[1].x = 200;	points[1].y = 50;	// 制御点1.
				points[2].x = 400;	points[2].y = 350;	// 制御点2.
				points[3].x = 500;	points[3].y = 100;	// 終点.

				// 比較用に, 4点を順番に結んだ制御多角形を, 薄い灰色の点線で描いておく.(曲線が制御点にどう引っ張られるかを見せるため.)
				hPenDot = CreatePen(PS_DOT, 1, RGB(170, 170, 170));	// CreatePenで薄い灰色の点線ペンを作成.
				hPenOld = (HPEN)SelectObject(hDC, hPenDot);			// SelectObjectで点線ペンを選択し, 元のペンをhPenOldに退避.
				MoveToEx(hDC, points[0].x, points[0].y, NULL);			// MoveToExで始点に現在位置を移動.
				for (i = 1; i < 4; i++) {	// forループで残り3点へ順番に線を引く.

					LineTo(hDC, points[i].x, points[i].y);	// LineToで次の点まで点線を引く.

				}
				SelectObject(hDC, hPenOld);	// SelectObjectで元のペンに戻す.
				DeleteObject(hPenDot);			// DeleteObjectで点線ペンを破棄.

				// 4点それぞれに赤色の小さな丸を描き, 点の位置自体を分かりやすくする.
				hPenRed = CreatePen(PS_SOLID, 1, RGB(230, 80, 80));	// CreatePenで赤色のペンを作成.
				hPenOld = (HPEN)SelectObject(hDC, hPenRed);			// SelectObjectで赤色ペンを選択し, 元のペンをhPenOldに退避.
				for (i = 0; i < 4; i++) {	// forループで4点すべてに対して処理.

					Ellipse(hDC, points[i].x - 5, points[i].y - 5, points[i].x + 5, points[i].y + 5);	// Ellipseで点の位置に小さな丸を描画.

				}
				SelectObject(hDC, hPenOld);	// SelectObjectで元のペンに戻す.
				DeleteObject(hPenRed);			// DeleteObjectで赤色ペンを破棄.

				// PolyBezierで, 同じ4点(始点・制御点1・制御点2・終点)から1本のベジェ曲線を, 青色の太いペンで描画する.
				hPenBlue = CreatePen(PS_SOLID, 3, RGB(80, 110, 230));	// CreatePenで青色の太い(3ピクセル)実線ペンを作成.
				hPenOld = (HPEN)SelectObject(hDC, hPenBlue);			// SelectObjectで青色ペンを選択し, 元のペンをhPenOldに退避.
				PolyBezier(hDC, points, 4);								// PolyBezierで4点(始点+制御点2個+終点)から3次ベジェ曲線を1本描画.
				SelectObject(hDC, hPenOld);							// SelectObjectで元のペンに戻す.
				DeleteObject(hPenBlue);									// DeleteObjectで青色ペンを破棄.

				// 説明用のラベルを表示.(文字数は必ずlstrlenで計算する.)
				pszLabel = _T("PolyBezier(hDC, points, 4)");	// ラベル文字列.
				TextOut(hDC, 100, 380, pszLabel, lstrlen(pszLabel));	// TextOutでラベルを表示.

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
