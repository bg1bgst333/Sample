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
	wc.lpszClassName = _T("AlphaBlend");						// ウィンドウクラス名を"AlphaBlend".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("AlphaBlend"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("AlphaBlend"), _T("AlphaBlend"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"AlphaBlend"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL) {	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("AlphaBlend"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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
				HBRUSH hBrushBlue;		// 下地用の青色ブラシを格納するHBRUSH型変数.
				HBRUSH hBrushOld;		// 退避用のHBRUSH型変数.
				HDC hMemDC;				// AlphaBltの転送元として使う互換メモリDCを格納するHDC型変数.
				HBITMAP hBitmapOrange;	// 転送元の橙色ビットマップを格納するHBITMAP型変数.
				HBITMAP hBitmapOld;		// 退避用のHBITMAP型変数.
				BLENDFUNCTION bf;		// AlphaBlendの合成方法を指定するBLENDFUNCTION構造体型変数.
				int alphaValues[4] = { 64, 128, 192, 255 };	// 4本の帯それぞれに使うSourceConstantAlpha値の配列.
				TCHAR szLabel[16];		// ラベル文字列を組み立てるTCHAR型配列.
				int i;					// ループカウンタ用のint型変数.

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にはデバイスコンテキストハンドルが返るので, hDCに格納.

				// 4つの帯すべての下地として, 青色の矩形を敷いておく.(アルファ値による見え方の違いを分かりやすくするため, 下地に色が必要.)
				hBrushBlue = CreateSolidBrush(RGB(100, 150, 230));	// CreateSolidBrushで青色のブラシを作成.
				hBrushOld = (HBRUSH)SelectObject(hDC, hBrushBlue);	// SelectObjectで青色ブラシを選択し, 元のブラシをhBrushOldに退避.
				Rectangle(hDC, 50, 50, 850, 350);					// Rectangleで下地の青い矩形を描画.
				SelectObject(hDC, hBrushOld);						// SelectObjectで元のブラシに戻す.
				DeleteObject(hBrushBlue);							// DeleteObjectで青色ブラシを破棄.

				// AlphaBlendの転送元として, 橙色で塗りつぶした180x260の互換ビットマップを用意する.
				hMemDC = CreateCompatibleDC(hDC);					// CreateCompatibleDCでhDCと互換のメモリDCを作成.
				hBitmapOrange = CreateCompatibleBitmap(hDC, 180, 260);	// CreateCompatibleBitmapで180x260の互換ビットマップを作成.
				hBitmapOld = (HBITMAP)SelectObject(hMemDC, hBitmapOrange);	// SelectObjectでメモリDCにビットマップを選択し, 元のビットマップをhBitmapOldに退避.
				hBrushOld = (HBRUSH)SelectObject(hMemDC, GetStockObject(DC_BRUSH));	// SelectObjectでDC_BRUSH(動的に色を変えられるブラシ)を選択.
				SetDCBrushColor(hMemDC, RGB(230, 140, 60));		// SetDCBrushColorでDC_BRUSHの色を橙色に設定.
				Rectangle(hMemDC, 0, 0, 180, 260);					// Rectangleでビットマップ全体を橙色で塗りつぶす.
				SelectObject(hMemDC, hBrushOld);					// SelectObjectで元のブラシに戻す.

				// BLENDFUNCTIONの共通項目を設定.(SourceConstantAlphaだけを帯ごとに変える.)
				bf.BlendOp = AC_SRC_OVER;			// BlendOpはAC_SRC_OVER(現状これ以外の値は無い).
				bf.BlendFlags = 0;					// BlendFlagsは0固定.
				bf.AlphaFormat = 0;					// AlphaFormatは0(ビットマップ自体のアルファチャンネルは使わず, SourceConstantAlphaだけで合成する).

				// 4本の帯: SourceConstantAlphaを64, 128, 192, 255と変えながらAlphaBlend.
				for (i = 0; i < 4; i++) {	// forループで4本の帯を順に処理.

					bf.SourceConstantAlpha = (BYTE)alphaValues[i];	// このループのSourceConstantAlpha値を設定.
					AlphaBlend(hDC, 70 + i * 190, 70, 180, 260, hMemDC, 0, 0, 180, 260, bf);	// AlphaBlendで橙色ビットマップを指定の透明度で下地に合成.
					wsprintf(szLabel, _T("alpha=%d"), alphaValues[i]);	// wsprintfでラベル文字列を組み立てる.
					TextOut(hDC, 70 + i * 190, 360, szLabel, lstrlen(szLabel));	// TextOutでラベルを表示.

				}

				// 転送元ビットマップ・メモリDCの後始末.
				SelectObject(hMemDC, hBitmapOld);		// SelectObjectで元のビットマップに戻す.
				DeleteObject(hBitmapOrange);			// DeleteObjectで橙色ビットマップを破棄.
				DeleteDC(hMemDC);						// DeleteDCでメモリDCを破棄.

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
