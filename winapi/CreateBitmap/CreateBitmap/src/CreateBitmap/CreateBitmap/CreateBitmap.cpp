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
	wc.lpszClassName = _T("CreateBitmap");						// ウィンドウクラス名を"CreateBitmap".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("CreateBitmap"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("CreateBitmap"), _T("CreateBitmap"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"CreateBitmap"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL) {	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("CreateBitmap"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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
				HBITMAP hBitmap;	// CreateBitmapで作成するビットマップを格納するHBITMAP型変数.
				HBITMAP hBitmapOld;	// 退避用のHBITMAP型変数.
				HDC hMemDC;			// StretchBltの転送元として使う互換メモリDCを格納するHDC型変数.
				COLORREF crOldText;	// 退避用のCOLORREF型変数(文字色).
				COLORREF crOldBk;	// 退避用のCOLORREF型変数(背景色).

				// 8x8の市松模様を表す, モノクロビットマップ(1ピクセル1ビット)の生のピクセルデータ.
				// 1行あたり8ピクセル=1バイトだが, GDIの仕様で1行はWORD(2バイト)境界にパディングする必要があるため, 各行2バイトで構成する(2バイト目は常に0で未使用).
				static BYTE bits[16] = {
					0xAA, 0x00,	// 1行目: 10101010 (1=白, 0=黒のつもりだが, 実際の色は描画時のテキスト色/背景色で決まる)
					0x55, 0x00,	// 2行目: 01010101
					0xAA, 0x00,	// 3行目: 10101010
					0x55, 0x00,	// 4行目: 01010101
					0xAA, 0x00,	// 5行目: 10101010
					0x55, 0x00,	// 6行目: 01010101
					0xAA, 0x00,	// 7行目: 10101010
					0x55, 0x00	// 8行目: 01010101
				};

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にはデバイスコンテキストハンドルが返るので, hDCに格納.

				// CreateBitmapで, 上記の生ピクセルデータから8x8・1プレーン・1ビット/ピクセルのモノクロビットマップを作成.
				hBitmap = CreateBitmap(8, 8, 1, 1, bits);	// CreateBitmapで幅8, 高さ8, プレーン数1, 1ピクセルあたり1ビットのビットマップを, bits配列のデータから直接作成.

				// 作成したビットマップを描画するため, 互換メモリDCを用意してビットマップを選択.
				hMemDC = CreateCompatibleDC(hDC);				// CreateCompatibleDCでhDCと互換のメモリDCを作成.
				hBitmapOld = (HBITMAP)SelectObject(hMemDC, hBitmap);	// SelectObjectでメモリDCに作成したビットマップを選択し, 元のビットマップをhBitmapOldに退避.

				// モノクロビットマップの0/1それぞれの色を, 転送先hDCのテキスト色/背景色として指定しておく.
				crOldText = SetTextColor(hDC, RGB(40, 40, 40));		// SetTextColorで0ビットに対応する色(濃い灰色)を設定し, 元の色をcrOldTextに退避.
				crOldBk = SetBkColor(hDC, RGB(230, 140, 60));		// SetBkColorで1ビットに対応する色(橙色)を設定し, 元の色をcrOldBkに退避.

				// StretchBltで, 8x8のビットマップを40倍(320x320)に拡大して転送.(市松模様がはっきり見えるようにする.)
				StretchBlt(hDC, 100, 80, 320, 320, hMemDC, 0, 0, 8, 8, SRCCOPY);	// StretchBltで8x8の転送元を320x320に引き伸ばしながらhDCへコピー.

				// 転送先hDCの色を元に戻す.
				SetTextColor(hDC, crOldText);	// SetTextColorで元の文字色に戻す.
				SetBkColor(hDC, crOldBk);		// SetBkColorで元の背景色に戻す.

				// 説明用のラベルを表示.
				TextOut(hDC, 100, 420, _T("CreateBitmap(8, 8, 1, 1, bits)"), lstrlen(_T("CreateBitmap(8, 8, 1, 1, bits)")));	// TextOutでラベルを表示.(lstrlenで文字数を数え間違えないようにする.)
				TextOut(hDC, 100, 440, _T("16bytes of raw pixel data -> 8x8 monochrome bitmap"), lstrlen(_T("16bytes of raw pixel data -> 8x8 monochrome bitmap")));	// TextOutでラベルを表示.

				// 転送元ビットマップ・メモリDCの後始末.
				SelectObject(hMemDC, hBitmapOld);	// SelectObjectで元のビットマップに戻す.
				DeleteObject(hBitmap);				// DeleteObjectでCreateBitmapしたビットマップを破棄.
				DeleteDC(hMemDC);					// DeleteDCでメモリDCを破棄.

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
