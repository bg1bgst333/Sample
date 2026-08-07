// ヘッダファイルのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <windowsx.h>	// マクロ
#include <tchar.h>		// TCHAR型
#include <commctrl.h>	// コモンコントロール

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理ができるように定義したコールバック関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージを格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラスを格納するWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("ImageList_BeginDrag");				// ウィンドウクラス名は"ImageList_BeginDrag".
	wc.style = CS_HREDRAW | CS_VREDRAW;							// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;								// ウィンドウプロシージャは独自の処理を定義したWindowProc.
	wc.hInstance = hInstance;									// インスタンスハンドルは_tWinMainの引数.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);					// アイコンはアプリケーション既定のもの.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);					// カーソルは矢印.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		// 背景は白ブラシ.
	wc.lpszMenuName = NULL;										// メニューは無し.
	wc.cbClsExtra = 0;											// 0でいい.
	wc.cbWndExtra = 0;											// 0でいい.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)){	// RegisterClassでウィンドウクラスを登録し, 0が返ってきたらエラー.

		// エラー処理
		MessageBox(NULL, _T("RegisterClass failed!"), _T("ImageList_BeginDrag"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("ImageList_BeginDrag"), _T("ImageList_BeginDrag"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"ImageList_BeginDrag"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("ImageList_BeginDrag"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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
	static HIMAGELIST hImageList = NULL;	// イメージリストハンドルを格納するHIMAGELIST型スタティック変数hImageList.
	static HBITMAP hBitmap = NULL;			// ビットマップハンドルを格納するHBITMAP型スタティック変数hBitmap.
	static BOOL bDragging = FALSE;			// ドラッグ中かどうかを示すBOOL型スタティック変数bDragging.

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-case文でuMsgの値をもとに処理を振り分ける.

		// ウィンドウの作成が開始されたとき.
		case WM_CREATE:		// ウィンドウの作成が開始されたとき.(uMsgがWM_CREATEの場合.)

			// WM_CREATEブロック
			{

				// CREATESTRUCT構造体へのポインタを取得.
				LPCREATESTRUCT lpcs = (LPCREATESTRUCT)lParam;	// lParamをLPCREATESTRUCTにキャストして, CREATESTRUCT構造体へのポインタをlpcsに格納.

				// ビットマップのロード.
				hBitmap = (HBITMAP)LoadImage(lpcs->hInstance, _T("image1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);	// LoadImageで"image1.bmp"をロードし, 戻り値のビットマップハンドルはhBitmapに格納する.
				if (hBitmap == NULL){	// hBitmapがNULLならロード失敗.

					// エラー処理
					MessageBox(hwnd, _T("LoadImage failed!"), _T("ImageList_BeginDrag"), MB_OK | MB_ICONHAND);	// MessageBoxで"LoadImage failed!"とエラーメッセージを表示.
					return -1;	// ウィンドウ作成失敗.

				}

				// イメージリストの作成.
				hImageList = ImageList_Create(32, 32, ILC_COLOR24, 1, 1);	// ImageList_Createでイメージリストを作成.
				if (hImageList == NULL){	// hImageListがNULLなら失敗.

					// エラー処理
					MessageBox(hwnd, _T("ImageList_Create failed!"), _T("ImageList_BeginDrag"), MB_OK | MB_ICONHAND);	// MessageBoxで"ImageList_Create failed!"とエラーメッセージを表示.
					if (hBitmap != NULL){	// hBitmapがNULLでない場合.
						DeleteObject(hBitmap);	// DeleteObjectでhBitmapの破棄.
						hBitmap = NULL;			// hBitmapはNULLにしておく.
					}
					return -1;	// ウィンドウ作成失敗.

				}

				// ビットマップをイメージリストに追加.
				ImageList_Add(hImageList, hBitmap, NULL);	// ImageList_AddでhBitmapをhImageListに追加.

				// ウィンドウ作成処理
				return 0;	// return文で0を返して, ウィンドウ作成を続けるとする.

			}

			// 次の処理へ続く.
			break;	// breakで抜けて, 次の処理(DefWindowProc)へ続く.

		// ウィンドウが破棄されたとき.
		case WM_DESTROY:	// ウィンドウが破棄されたとき.(uMsgがWM_DESTROYの場合.)

			// WM_DESTROYブロック
			{

				// イメージリストの破棄.
				if (hImageList != NULL){	// hImageListがNULLでない場合.
					ImageList_Destroy(hImageList);	// ImageList_DestroyでhImageListを破棄.
					hImageList = NULL;				// hImageListはNULLにしておく.
				}

				// ビットマップの破棄.
				if (hBitmap != NULL){	// hBitmapがNULLでない場合.
					DeleteObject(hBitmap);	// DeleteObjectでhBitmapの破棄.
					hBitmap = NULL;			// hBitmapはNULLにしておく.
				}

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

		// マウスが移動したとき.
		case WM_MOUSEMOVE:

			// WM_MOUSEMOVEブロック
			{

				// ドラッグ中ならドラッグ画像を移動.
				if (bDragging){
					POINT pt;
					pt.x = GET_X_LPARAM(lParam);
					pt.y = GET_Y_LPARAM(lParam);
					ImageList_DragMove(pt.x, pt.y);	// ImageList_DragMoveでドラッグ画像をカーソル位置に移動.
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

				if (ImageList_BeginDrag(hImageList, 0, 16, 16)){	// ImageList_BeginDragでhImageListの0番目の画像をドラッグ開始. ホットスポットは画像中央(16, 16).
					ImageList_DragEnter(hwnd, pt.x, pt.y);	// ImageList_DragEnterでhwndをロックしてドラッグ画像を表示.
					SetCapture(hwnd);		// SetCaptureでマウスキャプチャを設定.
					bDragging = TRUE;		// bDraggingをTRUEに設定.
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
					ImageList_DragLeave(hwnd);	// ImageList_DragLeaveでhwndのロックを解除.
					ImageList_EndDrag();		// ImageList_EndDragでドラッグを終了.
					ReleaseCapture();			// ReleaseCaptureでマウスキャプチャを解放.
					bDragging = FALSE;			// bDraggingをFALSEに設定.
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

		// それ以外の場合.
		default:

			// 次の処理へ続く.
			break;	// breakで抜けて, 次の処理(DefWindowProc)へ続く.

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}
