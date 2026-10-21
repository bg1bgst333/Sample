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
	wc.lpszClassName = _T("EqualRgn");							// ウィンドウクラス名は"EqualRgn".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("EqualRgn"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("EqualRgn"), _T("EqualRgn"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"EqualRgn"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL) {	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("EqualRgn"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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

	// ウィンドウメッセージに対する処理.
	switch (uMsg) {	// switch-case文でuMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始されたとき.
		case WM_CREATE:		// ウィンドウの作成が開始されたとき.(uMsgがWM_CREATEの場合.)

			// WM_CREATEブロック
			{

				// ウィンドウ作成続行
				return 0;	// returnして0を返すと, ウィンドウ作成を続けるとする.

			}

			// 既定の処理へ続ける.
			break;	// breakで抜けると, 既定の処理(DefWindowProc)へ続ける.

		// ウィンドウが破棄されたとき.
		case WM_DESTROY:	// ウィンドウが破棄されたとき.(uMsgがWM_DESTROYの場合.)

			// WM_DESTROYブロック
			{

				// メッセージループを抜ける.
				PostQuitMessage(0);	// PostQuitMessageで終了コードを0とするWM_QUITメッセージを送信.(これでメッセージループのGetMessageの戻り値が0になるので, メッセージループから抜ける.)

			}

			// 既定の処理へ続ける.
			break;	// breakで抜けると, 既定の処理(DefWindowProc)へ続ける.

		// 画面の描画が求められたとき.
		case WM_PAINT:		// 画面の描画が求められたとき.(uMsgがWM_PAINTの場合.)

			// WM_PAINTブロック
			{

				// このブロックのローカル変数の宣言と初期化.
				HDC hDC;				// デバイスコンテキストハンドルを格納するHDC型変数hDC.
				PAINTSTRUCT ps;			// ペイント処理を管理するPAINTSTRUCT構造体型の変数ps.
				HRGN hRgnA1;			// 1組目(左)の1つ目のリージョンを格納するHRGN型変数.
				HRGN hRgnA2;			// 1組目(左)の2つ目のリージョンを格納するHRGN型変数.
				HRGN hRgnB1;			// 2組目(右)の1つ目のリージョンを格納するHRGN型変数.
				HRGN hRgnB2;			// 2組目(右)の2つ目のリージョンを格納するHRGN型変数.
				HBRUSH hBrushFill;		// 下地の塗りつぶし用の薄い色のブラシを格納するHBRUSH型変数.
				HBRUSH hBrushFrame;		// 判定結果に応じた色の枠線用ブラシを格納するHBRUSH型変数.
				BOOL bResultA;			// 1組目のEqualRgnの判定結果を格納するBOOL型変数.
				BOOL bResultB;			// 2組目のEqualRgnの判定結果を格納するBOOL型変数.
				LPCTSTR pszLabelA;		// 1組目の説明文字列.
				LPCTSTR pszLabelB;		// 2組目の説明文字列.
				LPCTSTR pszResultA;		// 1組目の判定結果文字列.
				LPCTSTR pszResultB;		// 2組目の判定結果文字列.

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にはデバイスコンテキストハンドルが返るので, hDCに格納.

				hBrushFill = CreateSolidBrush(RGB(210, 210, 230));	// CreateSolidBrushで下地用の薄い色のブラシを作成.

				// 1組目(左): 全く同じパラメータでCreateRoundRectRgnを2回呼び, 同じ形・同じ位置のリージョンを2つ作る.(形も位置も完全に一致するので, EqualRgnはTRUEになる.)
				hRgnA1 = CreateRoundRectRgn(100, 100, 300, 250, 40, 40);	// CreateRoundRectRgnで1つ目の角丸リージョンを作成.
				hRgnA2 = CreateRoundRectRgn(100, 100, 300, 250, 40, 40);	// 全く同じ引数で2つ目の角丸リージョンを作成.
				bResultA = EqualRgn(hRgnA1, hRgnA2);						// EqualRgnで2つのリージョンが等しいかどうかを判定.
				FillRgn(hDC, hRgnA1, hBrushFill);							// FillRgnで1つ目のリージョンを下地色で塗りつぶす.
				hBrushFrame = CreateSolidBrush(bResultA ? RGB(50, 170, 70) : RGB(190, 60, 60));	// 判定結果がTRUEなら緑, FALSEなら赤の枠線用ブラシを作成.
				FrameRgn(hDC, hRgnA2, hBrushFrame, 4, 4);					// FrameRgnで2つ目のリージョンの輪郭を枠線として描画.(TRUEの場合, 1つ目の塗りつぶしとぴったり重なって見える.)
				DeleteObject(hBrushFrame);									// DeleteObjectで枠線用ブラシを破棄.
				DeleteObject(hRgnA1);										// DeleteObjectで1つ目のリージョンを破棄.
				DeleteObject(hRgnA2);										// DeleteObjectで2つ目のリージョンを破棄.

				// 2組目(右): 同じ形・同じ大きさだが, 位置だけを15ピクセルずらして2つ目のリージョンを作る.(形は同じでも位置がずれているので, EqualRgnはFALSEになる.)
				hRgnB1 = CreateRoundRectRgn(550, 100, 750, 250, 40, 40);			// CreateRoundRectRgnで1つ目の角丸リージョンを作成.
				hRgnB2 = CreateRoundRectRgn(565, 115, 765, 265, 40, 40);			// 同じ大きさのまま, 右に15・下に15ピクセルずらした2つ目の角丸リージョンを作成.
				bResultB = EqualRgn(hRgnB1, hRgnB2);								// EqualRgnで2つのリージョンが等しいかどうかを判定.
				FillRgn(hDC, hRgnB1, hBrushFill);									// FillRgnで1つ目のリージョンを下地色で塗りつぶす.
				hBrushFrame = CreateSolidBrush(bResultB ? RGB(50, 170, 70) : RGB(190, 60, 60));	// 判定結果がTRUEなら緑, FALSEなら赤の枠線用ブラシを作成.
				FrameRgn(hDC, hRgnB2, hBrushFrame, 4, 4);							// FrameRgnで2つ目のリージョンの輪郭を枠線として描画.(FALSEの場合, 1つ目の塗りつぶしから枠線がずれて見える.)
				DeleteObject(hBrushFrame);											// DeleteObjectで枠線用ブラシを破棄.
				DeleteObject(hRgnB1);												// DeleteObjectで1つ目のリージョンを破棄.
				DeleteObject(hRgnB2);												// DeleteObjectで2つ目のリージョンを破棄.

				DeleteObject(hBrushFill);	// DeleteObjectで下地用ブラシを破棄.

				// 各組の説明と判定結果を表示.(文字数は必ずlstrlenで計算する.)
				pszLabelA = _T("same size & position");						// 1組目の説明文字列.
				pszLabelB = _T("shifted by 15px");								// 2組目の説明文字列.
				pszResultA = bResultA ? _T("EqualRgn = TRUE") : _T("EqualRgn = FALSE");	// 1組目の判定結果文字列.
				pszResultB = bResultB ? _T("EqualRgn = TRUE") : _T("EqualRgn = FALSE");	// 2組目の判定結果文字列.
				TextOut(hDC, 100, 330, pszLabelA, lstrlen(pszLabelA));		// TextOutで1組目の説明を表示.
				TextOut(hDC, 100, 355, pszResultA, lstrlen(pszResultA));		// TextOutで1組目の判定結果を表示.
				TextOut(hDC, 550, 330, pszLabelB, lstrlen(pszLabelB));		// TextOutで2組目の説明を表示.
				TextOut(hDC, 550, 355, pszResultB, lstrlen(pszResultB));		// TextOutで2組目の判定結果を表示.

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
