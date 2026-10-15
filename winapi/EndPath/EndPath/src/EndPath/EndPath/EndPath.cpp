// ヘッダファイルのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理ができるように定義するコールバック関数WindowProc.
void DrawStarPath(HDC hDC, int cx, int cy);	// 星形のパスを描画する補助関数DrawStarPath.(BeginPath/EndPathの外側で呼び出す.)

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// 変数の宣言
	HWND hWnd;			// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;			// ウィンドウメッセージを格納するMSG構造体型変数msg.
	WNDCLASS wc;		// ウィンドウクラスを格納するWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("EndPath");						// ウィンドウクラス名を"EndPath".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("EndPath"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("EndPath"), _T("EndPath"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"EndPath"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL) {	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("EndPath"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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

// 星形のパスを描画する補助関数DrawStarPath.(中心(cx,cy)・外側半径100・内側半径40の5稜星を, MoveToEx/LineToで組み立てる.)
void DrawStarPath(HDC hDC, int cx, int cy) {

	// 事前計算済みの, 中心からの相対オフセット(外側・内側を交互に10点).
	static const POINT offsets[10] = {
		{0, -100}, {24, -32}, {95, -31}, {38, 12}, {59, 81},
		{0, 40}, {-59, 81}, {-38, 12}, {-95, -31}, {-24, -32}
	};
	int i;	// ループカウンタ用のint型変数.

	// 1点目へ現在位置を移動してから, 残り9点へ順番にLineToで線を引く.
	MoveToEx(hDC, cx + offsets[0].x, cy + offsets[0].y, NULL);	// MoveToExで星の1点目(先端)へ現在位置を移動.
	for (i = 1; i < 10; i++) {	// forループで残り9点を順番に結ぶ.

		LineTo(hDC, cx + offsets[i].x, cy + offsets[i].y);	// LineToで次の点まで線を引く.

	}
	LineTo(hDC, cx + offsets[0].x, cy + offsets[0].y);	// LineToで最後に1点目へ戻り, 星形を閉じる.

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
				HBRUSH hBrushStar;		// 星の塗りつぶし用ブラシを格納するHBRUSH型変数.
				HBRUSH hBrushOld;		// 退避用のHBRUSH型変数.
				BOOL bFillResult1;		// 1つ目(EndPathあり)のFillPathの戻り値を格納するBOOL型変数.
				BOOL bFillResult2;		// 2つ目(EndPathなし)のFillPathの戻り値を格納するBOOL型変数.
				TCHAR szLabel1[48];		// 1つ目のラベル文字列を組み立てるTCHAR型配列.
				TCHAR szLabel2[48];		// 2つ目のラベル文字列を組み立てるTCHAR型配列.

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にはデバイスコンテキストハンドルが返るので, hDCに格納.

				hBrushStar = CreateSolidBrush(RGB(230, 170, 60));	// CreateSolidBrushで橙色のブラシを作成.
				hBrushOld = (HBRUSH)SelectObject(hDC, hBrushStar);	// SelectObjectで橙色ブラシを選択し, 元のブラシをhBrushOldに退避.

				// 1つ目(左): BeginPath→星形を描画→EndPathでパスを正しく閉じてからFillPathで塗りつぶす.
				BeginPath(hDC);				// BeginPathでパスの記録を開始.(以降の描画命令は画面に直接描かれず, パスとして記録される.)
				DrawStarPath(hDC, 220, 220);	// DrawStarPathで星形の輪郭をパスとして記録.
				EndPath(hDC);					// EndPathでパスの記録を終了し, パスを確定(クローズ)する.
				bFillResult1 = FillPath(hDC);	// FillPathで確定したパスを現在のブラシで塗りつぶす.(成功すれば0以外を返す.)

				// 2つ目(右): BeginPath→星形を描画→EndPathを呼ばずに, そのままFillPathを試みる.
				BeginPath(hDC);				// BeginPathでパスの記録を開始.
				DrawStarPath(hDC, 680, 220);	// DrawStarPathで星形の輪郭をパスとして記録.
				bFillResult2 = FillPath(hDC);	// EndPathを呼ばずに(パスがまだ開いたままの状態で)FillPathを試みる.(失敗して0を返すはず.)
				AbortPath(hDC);				// AbortPathで, 開いたままになっているパスブラケットを強制的に破棄する.(これを呼ばないと, 以降のSelectObject/TextOut等の描画操作までパス記録モードの影響を受けてしまう.)

				SelectObject(hDC, hBrushOld);	// SelectObjectで元のブラシに戻す.
				DeleteObject(hBrushStar);			// DeleteObjectで橙色ブラシを破棄.

				// 結果のラベルを表示.(文字数は必ずlstrlenで計算する.)
				wsprintf(szLabel1, _T("EndPath -> FillPath: %s"), bFillResult1 ? _T("TRUE") : _T("FALSE"));	// wsprintfで1つ目の結果ラベルを組み立てる.
				wsprintf(szLabel2, _T("no EndPath -> FillPath: %s"), bFillResult2 ? _T("TRUE") : _T("FALSE"));	// wsprintfで2つ目の結果ラベルを組み立てる.
				TextOut(hDC, 100, 340, szLabel1, lstrlen(szLabel1));	// TextOutで1つ目のラベルを表示.
				TextOut(hDC, 560, 340, szLabel2, lstrlen(szLabel2));	// TextOutで2つ目のラベルを表示.

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
