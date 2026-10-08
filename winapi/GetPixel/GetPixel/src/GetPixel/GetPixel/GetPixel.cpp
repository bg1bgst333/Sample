// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// C標準入出力

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理ができるように定義するコールバック関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;			// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;			// ウィンドウメッセージを格納するMSG構造体型変数msg.
	WNDCLASS wc;		// ウィンドウクラスを格納するWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("GetPixel");						// ウィンドウクラス名を"GetPixel".
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
	if (!RegisterClass(&wc)){	// RegisterClassでウィンドウクラスを登録し, 0が返ってきたらエラー.

		// エラー処理
		MessageBox(NULL, _T("RegisterClass failed!"), _T("GetPixel"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("GetPixel"), _T("GetPixel"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"GetPixel"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("GetPixel"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.

	// メッセージループ
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessageでメッセージを取得し, 戻り値が0より大きい間はループを続ける.

		// ウィンドウメッセージの送出
		DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(今回の場合は独自に定義するWindowProc)に送出.

	}

	// プログラムの終了
	return (int)msg.wParam;	// 終了コード(msg.wParam)を戻り値として返す.

}

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

	// ウィンドウプロシージャ全体で使うスタティック変数の宣言.
	static int x;	// マウス左ボタンが押された時のマウスカーソルの位置x座標.
	static int y;	// マウス左ボタンが押された時のマウスカーソルの位置y座標.

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-case文でuMsgの値ごとに処理を振り分ける.

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
				PostQuitMessage(0);	// PostQuitMessageで終了コードを0とするWM_QUITメッセージを送信.

			}

			// 既定の処理へ続く.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ続く.

		// 画面の描画が求められたとき.
		case WM_PAINT:		// 画面の描画が求められたとき.(uMsgがWM_PAINTの場合.)

			// WM_PAINTブロック
			{

				// このブロックのローカル変数・配列の宣言
				HDC hDC;				// デバイスコンテキストハンドルを格納するHDC型変数hDC.
				PAINTSTRUCT ps;			// ペイント情報を管理するPAINTSTRUCT構造体型の変数ps.
				COLORREF crSet;			// SetPixel(先行使用)で実際に設定した色を格納するCOLORREF型変数.
				COLORREF crGet;			// GetPixel(本トピックの主役)で読み取った, クリック位置の色を格納するCOLORREF型変数.
				COLORREF crInvalid;		// GetPixel(本トピックの主役)で, わざとクライアント領域の外側の座標を読み取ろうとした結果を格納するCOLORREF型変数.
				TCHAR tszLine1[128];	// 1行目(クリック位置の座標)を組み立てるTCHAR型配列.
				TCHAR tszLine2[128];	// 2行目(GetPixelで読み取った色が, 設定した色と一致するか)を組み立てるTCHAR型配列.
				TCHAR tszLine3[128];	// 3行目(範囲外の座標へのGetPixel)を組み立てるTCHAR型配列.

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にはデバイスコンテキストハンドルが返るので, hDCに格納.

				// クリック位置に赤い点をSetPixel(先行使用)で打つ.
				crSet = RGB(255, 0, 0);				// crSetに赤(255, 0, 0)を格納.
				SetPixel(hDC, x, y, crSet);			// SetPixelで座標(x, y)の位置に赤い点を打つ.

				// GetPixel(本トピックの主役)で, 今まさに打ったばかりの点の色を読み取る.(成功するはず.)
				crGet = GetPixel(hDC, x, y);			// GetPixelで座標(x, y)の色を読み取る.

				// GetPixel(本トピックの主役)で, わざとクライアント領域の外側の座標を読み取ろうとする.(失敗するはず.)
				crInvalid = GetPixel(hDC, -100, -100);	// GetPixelでクライアント領域の外側の座標(-100, -100)を読み取ろうとする.

				// 1行目: クリック位置の座標を表示.
				_stprintf(tszLine1, _T("クリック位置(%d, %d)にSetPixelで赤い点を打ちました。"), x, y);	// _stprintfでtszLine1を組み立てる.
				TextOut(hDC, 10, 10, tszLine1, (int)_tcslen(tszLine1));	// TextOutでtszLine1を描画.

				// 2行目: GetPixelで読み取った色が, 設定した色と一致するかを表示.
				_stprintf(tszLine2, _T("GetPixelで読み取った色 -> 0x%06lX(設定した色0x%06lXと%s)"), crGet, crSet, (crGet == crSet) ? _T("一致") : _T("不一致"));	// _stprintfでtszLine2を組み立てる.
				TextOut(hDC, 10, 30, tszLine2, (int)_tcslen(tszLine2));	// TextOutでtszLine2を描画.

				// 3行目: 範囲外の座標へのGetPixelの結果を表示.
				_stprintf(tszLine3, _T("クライアント領域の外側(-100, -100)へのGetPixel -> 0x%08lX(CLR_INVALID=0x%08lXのはず)"), crInvalid, CLR_INVALID);	// _stprintfでtszLine3を組み立てる.
				TextOut(hDC, 10, 50, tszLine3, (int)_tcslen(tszLine3));	// TextOutでtszLine3を描画.

				// ウィンドウの描画終了
				EndPaint(hwnd, &ps);	// EndPaintでこのウィンドウの描画処理を終了させる.

			}

			// 既定の処理へ続く.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ続く.

		// マウスの左ボタンが押されたとき.
		case WM_LBUTTONDOWN:	// マウスの左ボタンが押されたとき.(uMsgがWM_LBUTTONDOWNの場合.)

			// WM_LBUTTONDOWNブロック
			{

				// マウスカーソルの位置を取得.
				x = LOWORD(lParam);	// lParamの下位16ビットはマウスカーソルのx座標を表しているので, LOWORDでlParamの下位16ビットを取得し, xに格納.
				y = HIWORD(lParam);	// lParamの上位16ビットはマウスカーソルのy座標を表しているので, HIWORDでlParamの上位16ビットを取得し, yに格納.

				// マウスの左ボタンが押されたので, 画面を無効領域化することで更新を促す.
				InvalidateRect(hwnd, NULL, TRUE);	// InvalidateRectでhwndの画面を無効領域化する.(第3引数TRUEなので背景も再描画して, 前回の点を消す.)

			}

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
