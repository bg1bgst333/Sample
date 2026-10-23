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
	wc.lpszClassName = _T("GetRgnBox");						// ウィンドウクラス名は"GetRgnBox".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("GetRgnBox"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("GetRgnBox"), _T("GetRgnBox"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"GetRgnBox"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL) {	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("GetRgnBox"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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
				HRGN hRgnA;				// 1つ目の円のリージョンを格納するHRGN型変数.
				HRGN hRgnB;				// 2つ目の円のリージョンを格納するHRGN型変数.
				HRGN hRgnCombined;		// 2つの円をまとめた(OR結合した)リージョンを格納するHRGN型変数.
				RECT rcBox;				// GetRgnBoxで取得する外接矩形を格納するRECT型変数.
				HBRUSH hBrushFill;		// リージョンの塗りつぶし用のブラシを格納するHBRUSH型変数.
				HPEN hPenBox;			// 外接矩形の枠線用のペンを格納するHPEN型変数.
				HBRUSH hBrushNull;		// 外接矩形の内側を透明にするためのNULL_BRUSHを格納するHBRUSH型変数.
				HPEN hOldPen;			// 退避用, 選択前のペンを格納するHPEN型変数.
				HBRUSH hOldBrush;		// 退避用, 選択前のブラシを格納するHBRUSH型変数.
				TCHAR tszStatus[64];	// 外接矩形の座標の文字列を格納するTCHAR型配列.
				LPCTSTR pszFormat;		// wsprintfに渡す書式文字列.

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にはデバイスコンテキストハンドルが返るので, hDCに格納.

				// 離れた位置に2つの円のリージョンを作り, OR結合で1つのリージョンにまとめる.(間に隙間が空いた, 2つに分かれたリージョンになる.)
				hRgnA = CreateEllipticRgn(100, 100, 260, 260);			// CreateEllipticRgnで1つ目の円のリージョンを作成.
				hRgnB = CreateEllipticRgn(600, 300, 760, 460);			// CreateEllipticRgnで2つ目の円のリージョンを作成.(1つ目から離れた位置.)
				hRgnCombined = CreateRectRgn(0, 0, 0, 0);				// CreateRectRgnで空のリージョンを作成.(CombineRgnの出力先として必要.)
				CombineRgn(hRgnCombined, hRgnA, hRgnB, RGN_OR);		// CombineRgnのRGN_ORでhRgnAとhRgnBを合体させ, hRgnCombinedに格納.
				DeleteObject(hRgnA);									// DeleteObjectでhRgnAを破棄.(hRgnCombinedに結合済みなので, 元の2つはもう不要.)
				DeleteObject(hRgnB);									// DeleteObjectでhRgnBを破棄.

				// 結合したリージョンを水色で塗りつぶす.
				hBrushFill = CreateSolidBrush(RGB(80, 160, 210));		// CreateSolidBrushで水色のブラシを作成.
				FillRgn(hDC, hRgnCombined, hBrushFill);				// FillRgnでhRgnCombinedを水色で塗りつぶす.(2つの円それぞれが塗られ, 間は白のまま残る.)
				DeleteObject(hBrushFill);								// DeleteObjectで使い終わったブラシを破棄.

				// GetRgnBoxで, 結合したリージョン全体を囲む外接矩形を取得する.
				GetRgnBox(hRgnCombined, &rcBox);						// GetRgnBoxでhRgnCombinedの外接矩形をrcBoxに取得.(2つの円の間の隙間も含めた, 全体を囲む1つの矩形になる.)

				// 外接矩形の枠線を, 赤い太めの点線で描く.(中は透明なので, 間の隙間が白いまま見える.)
				hPenBox = CreatePen(PS_DASH, 2, RGB(190, 60, 60));		// CreatePenで赤い点線のペンを作成.(PS_DASHは線幅1でないと点線にならない環境があるため, 太さ2でも実線になる場合がある点に注意.)
				hBrushNull = (HBRUSH)GetStockObject(NULL_BRUSH);		// GetStockObjectでNULL_BRUSH(透明なブラシ)を取得.
				hOldPen = (HPEN)SelectObject(hDC, hPenBox);			// SelectObjectでペンを選択し, 元のペンを退避.
				hOldBrush = (HBRUSH)SelectObject(hDC, hBrushNull);		// SelectObjectでNULL_BRUSHを選択し, 元のブラシを退避.
				Rectangle(hDC, rcBox.left, rcBox.top, rcBox.right, rcBox.bottom);	// Rectangleで外接矩形の枠線だけを描画.
				SelectObject(hDC, hOldPen);							// SelectObjectで元のペンに戻す.
				SelectObject(hDC, hOldBrush);							// SelectObjectで元のブラシに戻す.
				DeleteObject(hPenBox);									// DeleteObjectで使い終わったペンを破棄.

				DeleteObject(hRgnCombined);								// DeleteObjectで結合済みリージョンを破棄.

				// 外接矩形の座標を文字列で表示.(文字数は必ずlstrlenで計算する.)
				pszFormat = _T("GetRgnBox = (%d, %d)-(%d, %d)");		// wsprintfに渡す書式文字列.
				wsprintf(tszStatus, pszFormat, rcBox.left, rcBox.top, rcBox.right, rcBox.bottom);	// wsprintfで外接矩形の座標の文字列を組み立てる.
				TextOut(hDC, 100, 500, tszStatus, lstrlen(tszStatus));	// TextOutで組み立てた文字列を表示.

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
