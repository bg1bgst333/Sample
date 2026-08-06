// ヘッダファイルのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <windowsx.h>	// マクロ
#include <tchar.h>		// TCHAR型

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理ができるように定義したコールバック関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージを格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラスを格納するWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("DragDetect");					// ウィンドウクラス名を"DragDetect".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// スタイルをCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;							// ウィンドウプロシージャは独自の処理を定義したWindowProc.
	wc.hInstance = hInstance;								// インスタンスハンドルは_tWinMainの引数.
	wc.hIcon = LoadIcon(hInstance, IDI_APPLICATION);		// アイコンはアプリケーションデフォルトのもの.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// カーソルは矢印.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 背景は白ブラシ.
	wc.lpszMenuName = NULL;									// メニューは無し.
	wc.cbClsExtra = 0;										// 0でいい.
	wc.cbWndExtra = 0;										// 0でいい.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)){	// RegisterClassでウィンドウクラスを登録し, 0が返ってきたらエラー.

		// エラー処理
		MessageBox(NULL, _T("RegisterClass failed!"), _T("DragDetect"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("DragDetect"), _T("DragDetect"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 先に登録した"DragDetect"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("DragDetect"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.

	// メッセージループ
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessageでメッセージを取得, 戻り値が0より大きい間はループを続ける.

		// ウィンドウメッセージの送出
		DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(この場合は独自に定義したWindowProc)に送出.
		TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.

	}

	// プログラムの終了
	return (int)msg.wParam;	// 終了コード(msg.wParam)を戻り値として返す.

}

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// ウィンドウメッセージに対して独自の処理ができるように定義したウィンドウプロシージャ.

	// static変数の宣言
	static RECT rc = {100, 100, 250, 200};
	static BOOL bDragging = FALSE;
	static POINT ptOffset;

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-case文でuMsgの値をもとに処理を振り分ける.

		// ウィンドウの作成が開始されたとき.
		case WM_CREATE:		// ウィンドウの作成が開始されたとき.(uMsgがWM_CREATEの場合.)

			// WM_CREATEブロック
			{

				// ウィンドウ作成処理
				return 0;	// return文で0を返して, ウィンドウ作成を続けるとする.

			}

			// 次の処理へ続く.
			break;	// breakで抜けて, 次の処理(DefWindowProc)へ続く.

		// ウィンドウが破棄されたとき.
		case WM_DESTROY:	// ウィンドウが破棄されたとき.(uMsgがWM_DESTROYの場合.)

			// WM_DESTROYブロック
			{

				// メッセージループを抜ける.
				PostQuitMessage(0);	// PostQuitMessageで抜ける.

			}

			// 次の処理へ続く.
			break;	// breakで抜けて, 次の処理(DefWindowProc)へ続く.

		// 画面の描画が求められたとき.
		case WM_PAINT:		// 画面の描画が求められたとき.(uMsgがWM_PAINTの場合.)

			// WM_PAINTブロック
			{

				// このブロックのローカル変数の宣言
				HDC hDC;			// デバイスコンテキストハンドルを格納するHDC型変数hDC.
				PAINTSTRUCT ps;		// ペイント情報を管理するPAINTSTRUCT構造体型の変数ps.

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にはデバイスコンテキストハンドルが返るので, hDCに格納.

				// 矩形を描画.
				Rectangle(hDC, rc.left, rc.top, rc.right, rc.bottom);

				// ウィンドウの描画終了
				EndPaint(hwnd, &ps);	// EndPaintでこのウィンドウの描画処理を終了する.

			}

			// 次の処理へ続く.
			break;	// breakで抜けて, 次の処理(DefWindowProc)へ続く.

		// メニュー項目が選ばれたとき, ボタンなどのコントロールが操作されたりしたとき.
		case WM_COMMAND:	// メニュー項目が選ばれたとき, ボタンなどのコントロールが操作されたりしたとき.(uMsgがWM_COMMANDの場合.)

			// WM_COMMANDブロック
			{

			}

			// 次の処理へ続く.
			break;	// breakで抜けて, 次の処理(DefWindowProc)へ続く.

		// マウスカーソルの変更タイミングになったとき.
		case WM_SETCURSOR:

			// WM_SETCURSORブロック
			{

			}

			// 次の処理へ続く.
			break;	// breakで抜けて, 次の処理(DefWindowProc)へ続く.

		// ウィンドウのサイズ変更に関わる情報をOSから求められたとき.
		case WM_GETMINMAXINFO:

			// WM_GETMINMAXINFOブロック
			{

			}

			// 次の処理へ続く.
			break;	// breakで抜けて, 次の処理(DefWindowProc)へ続く.

		// マウスが移動したとき.
		case WM_MOUSEMOVE:

			// WM_MOUSEMOVEブロック
			{

				// ドラッグ中なら矩形を移動.
				if (bDragging){
					POINT pt;
					pt.x = GET_X_LPARAM(lParam);
					pt.y = GET_Y_LPARAM(lParam);
					OffsetRect(&rc, pt.x - ptOffset.x - rc.left, pt.y - ptOffset.y - rc.top);
					InvalidateRect(hwnd, NULL, TRUE);
				}

			}

			// 次の処理へ続く.
			break;	// breakで抜けて, 次の処理(DefWindowProc)へ続く.

		// マウスの左ボタンが押されたとき.
		case WM_LBUTTONDOWN:	// マウスの左ボタンが押されたとき.(uMsgがWM_LBUTTONDOWNの場合.)

			// WM_LBUTTONDOWNブロック
			{

				// クリック位置を取得.
				POINT pt;
				pt.x = GET_X_LPARAM(lParam);
				pt.y = GET_Y_LPARAM(lParam);

				// 矩形内をクリックしたときにドラッグ判定.
				if (PtInRect(&rc, pt)){
					POINT ptScreen = pt;
					ClientToScreen(hwnd, &ptScreen);
					if (DragDetect(hwnd, ptScreen)){
						SetCapture(hwnd);
						bDragging = TRUE;
						ptOffset.x = pt.x - rc.left;
						ptOffset.y = pt.y - rc.top;
					}
				}

			}

			// 次の処理へ続く.
			break;	// breakで抜けて, 次の処理(DefWindowProc)へ続く.

		// マウスの左ボタンが離されたとき.
		case WM_LBUTTONUP:	// マウスの左ボタンが離されたとき.(uMsgがWM_LBUTTONUPの場合.)

			// WM_LBUTTONUPブロック
			{

				// ドラッグ中なら解放.
				if (bDragging){
					ReleaseCapture();
					bDragging = FALSE;
				}

			}

			// 次の処理へ続く.
			break;	// breakで抜けて, 次の処理(DefWindowProc)へ続く.

		// マウスキャプチャが変化したとき.
		case WM_CAPTURECHANGED:	// マウスキャプチャが変化したとき.(uMsgがWM_CAPTURECHANGEDの場合.)

			// WM_CAPTURECHANGEDブロック
			{

				// ドラッグ状態をリセット.
				bDragging = FALSE;

			}

			// 次の処理へ続く.
			break;	// breakで抜けて, 次の処理(DefWindowProc)へ続く.

		// マウスがウィンドウのクライアント領域内で一定時間ホバー状態になったとき.
		case WM_MOUSEHOVER:

			// WM_MOUSEHOVERブロック
			{

			}

			// 次の処理へ続く.
			break;	// breakで抜けて, 次の処理(DefWindowProc)へ続く.

		// マウスがウィンドウのクライアント領域を離れたとき.
		case WM_MOUSELEAVE:

			// WM_MOUSELEAVEブロック
			{

			}

			// 次の処理へ続く.
			break;	// breakで抜けて, 次の処理(DefWindowProc)へ続く.

		// それ以外の場合.
		default:

			// 次の処理へ続く.
			break;	// breakで抜けて, 次の処理(DefWindowProc)へ続く.

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}
