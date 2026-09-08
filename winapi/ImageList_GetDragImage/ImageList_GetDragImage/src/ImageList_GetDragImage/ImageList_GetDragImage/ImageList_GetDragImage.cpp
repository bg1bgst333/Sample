// ヘッダファイルのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <windowsx.h>	// マクロ
#include <tchar.h>		// TCHAR型
#include <commctrl.h>	// コモンコントロール
#include <stdio.h>		// wsprintf用

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理ができるように定義したコールバック関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージを格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラスを格納するWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("ImageList_GetDragImage");				// ウィンドウクラス名は"ImageList_GetDragImage".
	wc.style = CS_HREDRAW | CS_VREDRAW;							// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;								// ウィンドウプロシージャは独自の処理を定義したWindowProc.
	wc.hInstance = hInstance;									// インスタンスハンドルは_tWinMainの引数.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);					// アイコンはアプリケーション既定のもの.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);					// カーソルは矢印.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		// 背景は白ブラシ.
	wc.lpszMenuName = NULL;										// メニューは無し.
	wc.cbClsExtra = 0;											// 0でよい.
	wc.cbWndExtra = 0;											// 0でよい.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)){	// RegisterClassでウィンドウクラスを登録し, 0が返ってきたらエラー.

		// エラー処理
		MessageBox(NULL, _T("RegisterClass failed!"), _T("ImageList_GetDragImage"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("ImageList_GetDragImage"), _T("ImageList_GetDragImage"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"ImageList_GetDragImage"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("ImageList_GetDragImage"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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
	static RECT rcLimit;					// ドラッグ画像の移動を制限するエリア(枠として描画する領域)を表すRECT型スタティック変数rcLimit.
	static RECT rcHotspotLimit;			// ホットスポット(pt, 画像中心)の可動範囲を表すRECT型スタティック変数rcHotspotLimit. rcLimitの全辺を画像中心までの距離(16px)ぶん内側に縮めたもの.
	static TCHAR tszDragInfo[128] = _T("");	// ImageList_GetDragImageで取得した情報を表示するための文字列バッファtszDragInfo.

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-case文でuMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始されたとき.
		case WM_CREATE:		// ウィンドウの作成が開始されたとき.(uMsgがWM_CREATEの場合.)

			// WM_CREATEブロック
			{

				// CREATESTRUCT構造体へのポインタを取得.
				LPCREATESTRUCT lpcs = (LPCREATESTRUCT)lParam;	// lParamをLPCREATESTRUCTにキャストし, CREATESTRUCT構造体へのポインタをlpcsに格納.

				// ビットマップのロード.
				hBitmap = (HBITMAP)LoadImage(lpcs->hInstance, _T("image1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);	// LoadImageで"image1.bmp"をロードし, 戻り値のビットマップハンドルをhBitmapに格納する.
				if (hBitmap == NULL){	// hBitmapがNULLならロード失敗.

					// エラー処理
					MessageBox(hwnd, _T("LoadImage failed!"), _T("ImageList_GetDragImage"), MB_OK | MB_ICONHAND);	// MessageBoxで"LoadImage failed!"とエラーメッセージを表示.
					return -1;	// ウィンドウ作成失敗.

				}

				// イメージリストの作成.
				hImageList = ImageList_Create(32, 32, ILC_COLOR24, 1, 1);	// ImageList_Createでイメージリストを作成.
				if (hImageList == NULL){	// hImageListがNULLなら失敗.

					// エラー処理
					MessageBox(hwnd, _T("ImageList_Create failed!"), _T("ImageList_GetDragImage"), MB_OK | MB_ICONHAND);	// MessageBoxで"ImageList_Create failed!"とエラーメッセージを表示.
					if (hBitmap != NULL){	// hBitmapがNULLでない場合.
						DeleteObject(hBitmap);	// DeleteObjectでhBitmapの破棄.
						hBitmap = NULL;			// hBitmapをNULLにしておく.
					}
					return -1;	// ウィンドウ作成失敗.

				}

				// ビットマップをイメージリストに追加.
				ImageList_Add(hImageList, hBitmap, NULL);	// ImageList_AddでhBitmapをhImageListに追加.

				// ドラッグ画像の移動を制限するエリアを, ウィンドウの中央に設定.
				{
					RECT rcClient;
					GetClientRect(hwnd, &rcClient);	// GetClientRectでクライアント領域のサイズを取得.

					SetRect(&rcLimit, 0, 0, 300, 200);	// SetRectで(0, 0)-(300, 200)の300x200の矩形をrcLimitに設定.

					// OffsetRectでrcLimitをクライアント領域の中央に移動.
					OffsetRect(&rcLimit, (rcClient.right - rcClient.left - 300) / 2, (rcClient.bottom - rcClient.top - 200) / 2);

					// ドラッグ画像(32x32, ホットスポットは左上(0, 0))がrcLimitからはみ出さないよう,
					// ホットスポットの可動範囲rcHotspotLimitを, 右辺・下辺を画像サイズ(32px)ぶん内側に縮める.
					SetRect(&rcHotspotLimit, rcLimit.left + 16, rcLimit.top + 16, rcLimit.right - 16, rcLimit.bottom - 16);
				}

				// ウィンドウ作成続行
				return 0;	// returnして0を返すと, ウィンドウ作成を続けるということ.

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
					hImageList = NULL;				// hImageListをNULLにしておく.
				}

				// ビットマップの破棄.
				if (hBitmap != NULL){	// hBitmapがNULLでない場合.
					DeleteObject(hBitmap);	// DeleteObjectでhBitmapの破棄.
					hBitmap = NULL;			// hBitmapをNULLにしておく.
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
				PAINTSTRUCT ps;		// ペイント処理を管理するPAINTSTRUCT構造体型の変数ps.

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にはデバイスコンテキストハンドルが返るので, hDCに格納.

				// ドラッグ画像の移動を制限するエリアの枠を描画.
				FrameRect(hDC, &rcLimit, (HBRUSH)GetStockObject(BLACK_BRUSH));	// FrameRectでrcLimitの枠を黒ブラシで描画.

				// ImageList_GetDragImageで取得した情報を, rcLimitの下に表示.
				TextOut(hDC, rcLimit.left, rcLimit.bottom + 10, tszDragInfo, lstrlen(tszDragInfo));	// TextOutでtszDragInfoをrcLimitの下に表示.

				// ウィンドウの描画終了
				EndPaint(hwnd, &ps);	// EndPaintでこのウィンドウの描画処理を終了させる.

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
		case WM_MOUSEMOVE:	// マウスが移動したとき.(uMsgがWM_MOUSEMOVEの場合.)

			// WM_MOUSEMOVEブロック
			{

				// ドラッグ中なら, ドラッグ画像を制限エリア内に収めながら移動.
				if (bDragging){

					// マウス位置を取得.
					POINT pt;
					pt.x = GET_X_LPARAM(lParam);
					pt.y = GET_Y_LPARAM(lParam);

					// PtInRectでホットスポットがrcHotspotLimit(画像がrcLimitに収まる範囲)内かどうかを判定.
					if (!PtInRect(&rcHotspotLimit, pt)){	// rcHotspotLimit外に出ようとした場合.

						// rcHotspotLimitの境界に座標をクランプ(壁に当たったように止める).
						if (pt.x < rcHotspotLimit.left){
							pt.x = rcHotspotLimit.left;
						}
						if (pt.x >= rcHotspotLimit.right){
							pt.x = rcHotspotLimit.right - 1;
						}
						if (pt.y < rcHotspotLimit.top){
							pt.y = rcHotspotLimit.top;
						}
						if (pt.y >= rcHotspotLimit.bottom){
							pt.y = rcHotspotLimit.bottom - 1;
						}

					}

					// クライアント座標ptを, ImageList_DragEnter/ImageList_DragMoveが要求するウィンドウ座標に変換.
					POINT ptWin = pt;
					ClientToScreen(hwnd, &ptWin);	// ClientToScreenでクライアント座標からスクリーン座標に変換.

					RECT rcWindow;
					GetWindowRect(hwnd, &rcWindow);	// GetWindowRectでウィンドウ全体(タイトルバー・枠含む)のスクリーン座標での矩形を取得.
					ptWin.x -= rcWindow.left;			// ウィンドウの左上を原点とした座標に変換.
					ptWin.y -= rcWindow.top;

					ImageList_DragMove(ptWin.x, ptWin.y);	// ImageList_DragMoveでドラッグ画像を(ptWin.x, ptWin.y)(ウィンドウ内座標)の位置に移動.

					// ImageList_GetDragImageで, 現在のドラッグ画像の位置とホットスポットを取得する.
					{
						POINT ptImage = { 0 };		// ドラッグ画像の現在位置を受け取るPOINT型変数ptImage.
						POINT ptHotspot = { 0 };	// ホットスポットの位置を受け取るPOINT型変数ptHotspot.
						if (ImageList_GetDragImage(&ptImage, &ptHotspot)){	// ImageList_GetDragImageで現在のドラッグ画像の情報を取得.
							wsprintf(tszDragInfo, _T("GetDragImage: pos=(%d,%d) hotspot=(%d,%d)"), ptImage.x, ptImage.y, ptHotspot.x, ptHotspot.y);	// wsprintfで取得した値を文字列に整形.
							InvalidateRect(hwnd, NULL, FALSE);	// InvalidateRectで再描画要求.(表示を更新するため.)
						}
					}

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

				// 枠(rcLimit)の外でクリックした場合は, ドラッグ自体を開始しない(何も表示しない).
				if (PtInRect(&rcLimit, pt)){

					// クリック位置(画像の左上になる)が枠の右端・下端に近く, 画像がはみ出す場合をクランプする.
					if (pt.x >= rcHotspotLimit.right){
						pt.x = rcHotspotLimit.right - 1;
					}
					if (pt.y >= rcHotspotLimit.bottom){
						pt.y = rcHotspotLimit.bottom - 1;
					}

					if (ImageList_BeginDrag(hImageList, 0, 16, 16)){	// ImageList_BeginDragでhImageListの0番目の画像をドラッグ開始. ホットスポットは画像中心(16, 16).

						// ImageList_DragEnterは, hwndの左上角(タイトルバー・枠含む)基準にした座標を要求する.
						POINT ptWin = pt;
						ClientToScreen(hwnd, &ptWin);	// ClientToScreenでクライアント座標からスクリーン座標に変換.

						RECT rcWindow;
						GetWindowRect(hwnd, &rcWindow);	// GetWindowRectでウィンドウ全体のスクリーン座標での矩形を取得.
						ptWin.x -= rcWindow.left;			// ウィンドウの左上を原点とした座標に変換.
						ptWin.y -= rcWindow.top;

						if (ImageList_DragEnter(hwnd, ptWin.x, ptWin.y)){	// ImageList_DragEnterでhwndをロックしてドラッグ画像をクリック位置(ptWin)(ウィンドウ内座標)に表示.
							SetCapture(hwnd);		// SetCaptureでマウスキャプチャを設定.
							bDragging = TRUE;		// bDraggingをTRUEに設定.

							// ドラッグ開始時点でも, ImageList_GetDragImageで情報を取得して表示しておく.
							{
								POINT ptImage = { 0 };
								POINT ptHotspot = { 0 };
								if (ImageList_GetDragImage(&ptImage, &ptHotspot)){
									wsprintf(tszDragInfo, _T("GetDragImage: pos=(%d,%d) hotspot=(%d,%d)"), ptImage.x, ptImage.y, ptHotspot.x, ptHotspot.y);
									InvalidateRect(hwnd, NULL, FALSE);
								}
							}

						}
						else{	// ImageList_DragEnterが失敗した場合.
							ImageList_EndDrag();	// ImageList_EndDragでドラッグを終了.
						}
					}

				}

			}

			// 次の処理へ続く.
			break;	// breakで抜けて, 次の処理(DefWindowProc)へ続く.

		// マウスの左ボタンが離されたとき.
		case WM_LBUTTONUP:	// マウスの左ボタンが離されたとき.(uMsgがWM_LBUTTONUPの場合.)

			// WM_LBUTTONUPブロック
			{

				// ドラッグ中なら終了.
				if (bDragging){
					ImageList_DragLeave(hwnd);	// ImageList_DragLeaveでhwndのロックを解除.
					ImageList_EndDrag();		// ImageList_EndDragでドラッグを終了.
					ReleaseCapture();			// ReleaseCaptureでマウスキャプチャを解除.
					bDragging = FALSE;			// bDraggingをFALSEに設定.

					// ドラッグ終了後は表示をクリア.
					tszDragInfo[0] = _T('\0');
					InvalidateRect(hwnd, NULL, FALSE);
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
