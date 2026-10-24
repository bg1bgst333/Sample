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
	wc.lpszClassName = _T("ExtSelectClipRgn");						// ウィンドウクラス名は"ExtSelectClipRgn".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("ExtSelectClipRgn"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("ExtSelectClipRgn"), _T("ExtSelectClipRgn"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"ExtSelectClipRgn"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL) {	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("ExtSelectClipRgn"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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
				HDC hDC;			// デバイスコンテキストハンドルを格納するHDC型変数hDC.
				PAINTSTRUCT ps;		// ペイント処理を管理するPAINTSTRUCT構造体型の変数ps.
				HBRUSH hBrushFill;	// 矩形の塗りつぶし用のブラシを格納するHBRUSH型変数.
				RECT rcLeft;		// 左側(クリップ無し)の塗りつぶし範囲を格納するRECT型変数.
				RECT rcRight;		// 右側(クリップ有り)の塗りつぶし範囲を格納するRECT型変数.
				HRGN hRgnClip;		// 右側だけに適用する楕円のクリップリージョンを格納するHRGN型変数.
				LPCTSTR pszLabelLeft;	// 左側のラベル文字列.
				LPCTSTR pszLabelRight;	// 右側のラベル文字列.

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にはデバイスコンテキストハンドルが返るので, hDCに格納.

				hBrushFill = CreateSolidBrush(RGB(80, 160, 210));	// CreateSolidBrushで塗りつぶし用の水色のブラシを作成.

				// 左側(クリップ無し): そのまま矩形を塗りつぶすだけ.
				rcLeft.left = 100;	rcLeft.top = 100;	rcLeft.right = 400;	rcLeft.bottom = 350;	// 左側の矩形範囲を設定.
				FillRect(hDC, &rcLeft, hBrushFill);	// FillRectで左側をそのまま塗りつぶす.

				// 右側(クリップ有り): ExtSelectClipRgnで楕円のクリップリージョンを設定してから, 同じ大きさの矩形を塗りつぶす.
				hRgnClip = CreateEllipticRgn(620, 150, 780, 300);	// CreateEllipticRgnで右側の中央に重なる楕円リージョンを作成.
				ExtSelectClipRgn(hDC, hRgnClip, RGN_COPY);			// ExtSelectClipRgnにRGN_COPYを指定し, このDCのクリップ領域をこの楕円リージョンだけに置き換える.
				DeleteObject(hRgnClip);							// DeleteObjectで使い終わったリージョンを破棄.(クリップ領域への設定はDCが独自に保持するのでコピー後は不要.)

				rcRight.left = 550;	rcRight.top = 100;	rcRight.right = 850;	rcRight.bottom = 350;	// 右側の矩形範囲を設定.(左側と同じ大きさ.)
				FillRect(hDC, &rcRight, hBrushFill);	// FillRectで右側も同じ範囲に塗りつぶそうとするが, クリップ領域(楕円)の外側は描画されない.

				SelectClipRgn(hDC, NULL);	// SelectClipRgnにNULLを指定し, クリップ領域を解除しておく.(以降のTextOutが見切れないようにするため.)

				DeleteObject(hBrushFill);	// DeleteObjectで塗りつぶし用ブラシを破棄.

				// 各側の説明を表示.(文字数は必ずlstrlenで計算する.)
				pszLabelLeft = _T("no clip");								// 左側のラベル文字列.
				pszLabelRight = _T("after: ExtSelectClipRgn on ellipse");	// 右側のラベル文字列.
				TextOut(hDC, 100, 380, pszLabelLeft, lstrlen(pszLabelLeft));		// TextOutで左側のラベルを表示.
				TextOut(hDC, 550, 380, pszLabelRight, lstrlen(pszLabelRight));		// TextOutで右側のラベルを表示.

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
