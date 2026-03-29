// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <windowsx.h>	// マクロ
#include <tchar.h>		// TCHAR型

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理をするように定義したコールバック関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージ情報を格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラス情報をもつWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("LoadCursor");						// ウィンドウクラス名は"LoadCursor".
	wc.style = CS_HREDRAW | CS_VREDRAW;							// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;								// ウィンドウプロシージャは独自の処理を定義したWindowProc.
	wc.hInstance = hInstance;									// インスタンスハンドルは_tWinMainの引数.
	wc.hIcon = LoadIcon(hInstance, IDI_APPLICATION);			// アイコンはアプリケーション既定のもの.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// カーソルは矢印.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		// 背景は白ブラシ.
	wc.lpszMenuName = NULL;										// メニューは無し.
	wc.cbClsExtra = 0;											// 0でいい.
	wc.cbWndExtra = 0;											// 0でいい.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)){	// RegisterClassでウィンドウクラスを登録し, 0が返ったらエラー.

		// エラー処理
		MessageBox(NULL, _T("RegisterClass failed!"), _T("LoadCursor"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("LoadCursor"), _T("LoadCursor"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"LoadCursor"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("LoadCursor"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.

	// メッセージループ
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessageでメッセージを取得, 戻り値が0より大きい間はループし続ける.

		// ウィンドウメッセージの送出
		DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(この場合は独自に定義したWindowProc)に送出.
		TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.

	}

	// プログラムの終了
	return (int)msg.wParam;	// 終了コード(msg.wParam)を戻り値として返す.

}

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// ウィンドウメッセージに対して独自の処理をするように定義したウィンドウプロシージャ.

	// static変数の宣言
	static BOOL bTracking = FALSE;
	static BOOL bDragging = FALSE;
	static POINT ptStart = {0};
	static POINT ptEnd = {0};
	static RECT rcFix = {50, 50, 50 + 320, 50 + 240};

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-casa文でuMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始された時.
		case WM_CREATE:		// ウィンドウの作成が開始された時.(uMsgがWM_CREATEの時.)
		
			// WM_CREATEブロック
			{

				// ウィンドウ作成成功
				return 0;	// return文で0を返して, ウィンドウ作成成功とする.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// ウィンドウが破棄された時.
		case WM_DESTROY:	// ウィンドウが破棄された時.(uMsgがWM_DESTROYの時.)

			// WM_DESTROYブロック
			{

				// メッセージループを抜ける.
				PostQuitMessage(0);	// PostQuitMessageで抜ける.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// 画面の描画を要求された時.
		case WM_PAINT:		// 画面の描画を要求された時.(uMsgがWM_PAINTの時.)
 
			// WM_PAINTブロック
			{

				// このブロックのローカル変数の宣言
				HDC hDC;				// デバイスコンテキストハンドルを格納するHDC型変数hDC.
				PAINTSTRUCT ps;			// ペイント情報を管理するPAINTSTRUCT構造体型の変数ps.

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にはデバイスコンテキストハンドルが返るので, hDCに格納.

				// 矩形の描画
				Rectangle(hDC, rcFix.left, rcFix.top, rcFix.right, rcFix.bottom);

				// ウィンドウの描画終了
				EndPaint(hwnd, &ps);	// EndPaintでこのウィンドウの描画処理を終了する.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりした時.
		case WM_COMMAND:	// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりした時.(uMsgがWM_COMMANDの時.)

			// WM_COMMANDブロック
			{

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// マウスカーソルの変更タイミングになった時.
		case WM_SETCURSOR:

			// WM_SETCURSORブロック
			{
			
				// 矩形内にある時は, マウスカーソルをIDC_HANDにする.
				POINT pt;
				GetCursorPos(&pt);
				ScreenToClient(hwnd, &pt);
				if (PtInRect(&rcFix, pt)){
					SetCursor(LoadCursor(NULL, IDC_HAND));
					return TRUE;
				}

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// ウィンドウのサイズ制限に関する情報をOSから要求された時.
		case WM_GETMINMAXINFO:

			// WM_GETMINMAXINFOブロック
			{

				// 最小サイズを(640, 480)にセット.
				MINMAXINFO *mmi = (MINMAXINFO *)lParam;
				mmi->ptMinTrackSize.x = 640;
				mmi->ptMinTrackSize.y = 480;

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// マウスが移動した時.
		case WM_MOUSEMOVE:

			// WM_MOUSEMOVEブロック
			{

				// ドラッグで矩形を移動.
				if (bDragging){
					POINT pt = {0};
					pt.x = GET_X_LPARAM(lParam);
					pt.y = GET_Y_LPARAM(lParam);
					int dx = pt.x - ptStart.x;
					int dy = pt.y - ptStart.y;
					OffsetRect(&rcFix, dx, dy);
					ptStart = pt;
					InvalidateRect(hwnd, NULL, TRUE);
					TCHAR tszTemp[256] = {0};
					_stprintf(tszTemp, _T("OffsetRect: dx = %d, dy = %d\n"), dx, dy);
					OutputDebugString(tszTemp);
				}

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// マウスの左ボタンが押された時.
		case WM_LBUTTONDOWN:	// マウスの左ボタンが押された時.(uMsgがWM_LBUTTONDOWNの時.)

			// WM_LBUTTONDOWNブロック
			{

				// 矩形内かどうかを判定.
				POINT pt = {0};
				pt.x = GET_X_LPARAM(lParam);
				pt.y = GET_Y_LPARAM(lParam);
				if (PtInRect(&rcFix, pt)){	// 矩形内なら.
					// キャプチャ開始.
					bDragging = TRUE;
					ptStart = pt;
					SetCapture(hwnd);
					TCHAR tszTemp[256] = {0};
					_stprintf(tszTemp, _T("PtInRect, SetCapture: x = %hd, y = %hd\n"), ptStart.x, ptStart.y);
					OutputDebugString(tszTemp);
				}

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// マウスの左ボタンが離された時.
		case WM_LBUTTONUP:	// マウスの左ボタンが離された時.(uMsgがWM_LBUTTONUPの時.)

			// WM_LBUTTONUPブロック
			{

				// キャプチャ終了.
				if (bDragging){
					bDragging = FALSE;
					ptEnd.x = GET_X_LPARAM(lParam);
					ptEnd.y = GET_Y_LPARAM(lParam);
					ReleaseCapture();
					TCHAR tszTemp[256] = {0};
					_stprintf(tszTemp, _T("ReleaseCapture: x = %hd, y = %hd\n"), ptEnd.x, ptEnd.y);
					OutputDebugString(tszTemp);
				}

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// マウスキャプチャが失われた時.
		case WM_CAPTURECHANGED:	// マウスキャプチャが失われた時.(uMsgがWM_CAPTURECHANGEDの時.)

			// WM_CAPTURECHANGEDブロック
			{

				// キャプチャを失ったので, bDraggingをFALSEに.
				if (bDragging){
					bDragging = FALSE;
				}
				OutputDebugString(_T("WM_CAPTURECHANGED\n"));

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// マウスがウィンドウのクライアント領域上で一定時間ホバー状態だった時.
		case WM_MOUSEHOVER:

			// WM_MOUSEHOVERブロック
			{

				// デバッグ出力.
				OutputDebugString(_T("WM_MOUSEHOVER\n"));

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// マウスがウィンドウのクライアント領域を離れた時.
		case WM_MOUSELEAVE:

			// WM_MOUSELEAVEブロック
			{

				// bTrackingをFALSEに戻す.
				bTracking = FALSE;

				// デバッグ出力.
				OutputDebugString(_T("WM_MOUSELEAVE\n"));

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// それ以外の時.
		default:

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}