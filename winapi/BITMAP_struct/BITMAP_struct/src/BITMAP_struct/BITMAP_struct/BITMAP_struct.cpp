// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// C標準入出力

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理をするように定義したコールバック関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数・配列の宣言・初期化
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージ情報を格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラス情報をもつWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("BITMAP_struct");					// ウィンドウクラス名は"BITMAP_struct".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;							// ウィンドウプロシージャは独自の処理を定義したWindowProc.
	wc.hInstance = hInstance;								// インスタンスハンドルは_tWinMainの引数.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// アイコンはアプリケーション既定のもの.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// カーソルは矢印.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 背景は白ブラシ.
	wc.lpszMenuName = NULL;									// なし
	wc.cbClsExtra = 0;										// 0でいい.
	wc.cbWndExtra = 0;										// 0でいい.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)){	// RegisterClassでウィンドウクラスを登録し, 0が返ったらエラー.

		// エラー処理
		MessageBox(NULL, _T("RegisterClass Failure!"), _T("BITMAP_struct"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass Failure!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("BITMAP_struct"), _T("BITMAP_struct"), WS_OVERLAPPEDWINDOW | WS_HSCROLL | WS_VSCROLL, 0, 0, 480, 360, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"BITMAP_struct"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow Failure!"), _T("BITMAP_struct"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow Failure!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.

	// メッセージループ
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessageでメッセージを取得, 戻り値が0より大きい間はループし続ける.

		// ウィンドウメッセージ処理
		TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.
		DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(この場合は独自に定義したWindowProc)に送出.

	}

	// プログラムの終了
	return (int)msg.wParam;	// 終了コード(msg.wParam)を戻り値として返す.

}

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// ウィンドウメッセージに対して独自の処理をするように定義したウィンドウプロシージャ.

	// スタティック変数の初期化.
	static HBITMAP hBitmap = NULL;	// ビットマップハンドルhBitmapをNULLで初期化.
	static HDC hDC = NULL;	// デバイスコンテキストハンドルhDCをNULLで初期化.
	static HDC hMemDC = NULL;	// メモリデバイスコンテキストハンドルhMemDCをNULLで初期化.
	static HBITMAP hOld = NULL;	// 以前のビットマップハンドルhOldをNULLで初期化.
	static int dx = 0;	// 水平方向の変化量dx.(左が-, 右が+.)
	static int dy = 0;	// 垂直方向の変化量dy.(上が-, 下が+.)
	static BITMAP bitmap = {0};	// BITMAP構造体オブジェクトbitmapを{0}で初期化.

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-casa文でuMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始された時.
		case WM_CREATE:		// ウィンドウの作成が開始された時.(uMsgがWM_CREATEの時.)

			// WM_CREATEブロック
			{

				// 変数の宣言
				LPCREATESTRUCT lpCS;	// CreateStruct構造体のポインタlpCS.

				// アプリケーションインスタンスハンドルの取得.
				lpCS = (LPCREATESTRUCT)lParam;	// lParamをLPCREATESTRUCTにキャストして, lpCSに格納.

				// ビットマップのロード
				hBitmap = (HBITMAP)LoadImage(lpCS->hInstance, _T("bitmap1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);	// LoadImageで"bitmap1.bmp"をロードし, 戻り値のビットマップハンドルはhBitmapに格納する.
				if (hBitmap == NULL){	// hBitmapがNULLならロード失敗.

					// エラー処理
					MessageBox(hwnd, _T("LoadImage failed!"), _T("BITMAP_struct"), MB_OK | MB_ICONHAND);	// MessageBoxで"LoadImage failed!"とエラーメッセージを表示.
					return -1;	// 異常終了なので-1を返して, ウィンドウ生成失敗とする.

				}

				// ビットマップの幅と高さを取得.
				int iRet = GetObject(hBitmap, sizeof(BITMAP), &bitmap);	// GetObjectでビットマップ情報bitmapを取得.
				if (iRet <= 0){	// 失敗.

					// エラー処理
					MessageBox(hwnd, _T("GetObject failed!"), _T("BITMAP_struct"), MB_OK | MB_ICONHAND);	// MessageBoxで"GetObject failed!"とエラーメッセージを表示.
					return -2;	// 異常終了なので-2を返して, ウィンドウ生成失敗とする.

				}

				// ウィンドウデバイスコンテキストハンドルの取得.
				hDC = GetDC(hwnd);	// GetDCでhDC取得.
				if (hDC == NULL){	// NULLなら.

					// エラー処理
					MessageBox(hwnd, _T("GetDC failed!"), _T("BITMAP_struct"), MB_OK | MB_ICONHAND);	// MessageBoxで"GetDC failed!"とエラーメッセージを表示.
					if (hBitmap != NULL){	// NULLでなければ.
						DeleteObject(hBitmap);	// DeleteObjectでhBitmapを破棄.
						hBitmap = NULL;	// NULLをセット.
					}
					return -3;	// 異常終了なので-3を返して, ウィンドウ生成失敗とする.

				}

				// メモリデバイスコンテキストの生成.
				hMemDC = CreateCompatibleDC(hDC);	// CreateCompatibleDCでhMemDC取得.
				if (hMemDC == NULL){	// NULLでなければ.

					// エラー処理
					MessageBox(hwnd, _T("CreateCompatibleDC failed!"), _T("BITMAP_struct"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateCompatibleDC failed!"とエラーメッセージを表示.
					if (hDC != NULL){	// NULLでなければ.
						ReleaseDC(hwnd, hDC);	// ReleaseDCでhDCの解放.
						hDC = NULL;	// NULLをセット.
					}
					if (hBitmap != NULL){	// NULLでなければ.
						DeleteObject(hBitmap);	// DeleteObjectでhBitmapを破棄.
						hBitmap = NULL;	// NULLをセット.
					}
					return -4;	// 異常終了なので-4を返して, ウィンドウ生成失敗とする.

				}

				// ビットマップを選択.
				hOld = (HBITMAP)SelectObject(hMemDC, hBitmap);	// SelectObjectでhMemDCでhBitmapを選択.

				// ウィンドウ作成成功
				return 0;	// return文で0を返して, ウィンドウ作成成功とする.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// ウィンドウが破棄された時.
		case WM_DESTROY:	// ウィンドウが破棄された時.(uMsgがWM_DESTROYの時.)

			// WM_DESTROYブロック
			{

				// 終了メッセージの送信.
				PostQuitMessage(0);	// PostQuitMessageで終了コードを0としてWM_QUITメッセージを送信.(するとメッセージループのGetMessageの戻り値が0になるので, メッセージループから抜ける.)

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// 画面の描画を要求された時.
		case WM_PAINT:		// 画面の描画を要求された時.(uMsgがWM_PAINTの時.)

			// WM_PAINTブロック
			{

				// 更新領域の取得.
				RECT rcClient = {0};	// クライアント領域rcClientを{0}で初期化.
				GetClientRect(hwnd, &rcClient);	// GetClientRectで現在のクライアント領域のRECTであるrcClientを取得.
				RECT rcUpdate = {0};	// 更新領域rcUpdateを{0}で初期化.
				GetUpdateRect(hwnd, &rcUpdate, FALSE);	// GetUpdateRectで更新領域rcUpdateを取得.
				// スクロール情報の取得.
				SCROLLINFO siHorz = {0};	// 水平方向スクロール情報siHorz.
				siHorz.cbSize = sizeof(SCROLLINFO);	// sizeof(SCROLLINFO)
				siHorz.fMask = SIF_POS | SIF_PAGE | SIF_RANGE;	// 位置, ページ, レンジ.
				GetScrollInfo(hwnd, SB_HORZ, &siHorz);	// GetScrollInfoでsiHorz取得.
				SCROLLINFO siVert = {0};	// 垂直方向スクロール情報siVert.
				siVert.cbSize = sizeof(SCROLLINFO);	// sizeof(SCROLLINFO)
				siVert.fMask = SIF_POS | SIF_PAGE | SIF_RANGE;	// 位置, ページ, レンジ.
				GetScrollInfo(hwnd, SB_VERT, &siVert);	// GetScrollInfoでsiVert取得.

				// 描画開始.
				PAINTSTRUCT ps = {0};	// PAINTSTRUCT型psを{0}で初期化.
				HDC hDC = BeginPaint(hwnd, &ps);	// BeginPaintでhDC取得.

				// 描画.
				int x1 = 0;	// 転送先x1を0で初期化.
				int y1 = 0;	// 転送先y1を0で初期化.
				if (dx > 0){	// dxがプラス.
					x1 = siHorz.nPage + siHorz.nPos - (rcUpdate.right - rcUpdate.left);	// x1はページ数 + 位置 - 1 - (再描画する範囲).
				}
				else{	// dxが0以下.
					x1 = siHorz.nPos;	// x1は位置.
				}
				if (dy > 0){	// dyがプラス.
					y1 = siVert.nPage + siVert.nPos - (rcUpdate.bottom - rcUpdate.top);	// y1はページ数 + 位置 - 1 - (再描画する範囲).
				}
				else{	// dyが0以下.
					y1 = siVert.nPos;	// y1は位置.
				}
				BitBlt(hDC, rcUpdate.left, rcUpdate.top, rcUpdate.right - rcUpdate.left, rcUpdate.bottom - rcUpdate.top, hMemDC, x1, y1, SRCCOPY);	// BitBltで転送.

				// 描画終了.
				EndPaint(hwnd, &ps);	// EndPaintで描画終了.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// ウィンドウが閉じられた時.
		case WM_CLOSE:	// ウィンドウが閉じられた時.(uMsgがWM_CLOSEの時.)

			// WM_CLOSEブロック
			{

				// 以前のビットマップに戻す.
				if (hOld != NULL){	// NULLでなければ.
					SelectObject(hMemDC, hOld);	// SelectObjectでhOldを選択.
					hOld = NULL;	// NULLをセット.
				}

				// メモリデバイスコンテキストの破棄.
				if (hMemDC != NULL){	// NULLでなければ.
					DeleteDC(hMemDC);	// DeleteDCでhMemDCの破棄.
					hMemDC = NULL;	// NULLをセット.
				}

				// ウィンドウデバイスコンテキストハンドルの解放.
				if (hDC != NULL){	// NULLでなければ.
					ReleaseDC(hwnd, hDC);	// ReleaseDCでhDCの解放.
					hDC = NULL;	// NULLをセット.
				}

				// ビットマップの破棄.
				if (hBitmap != NULL){	// NULLでなければ.
					DeleteObject(hBitmap);	// DeleteObjectでhBitmapを破棄.
					hBitmap = NULL;	// NULLをセット.
				}

			}

			// 抜ける.
			break;	// breakで抜ける.

		// 水平スクロールバーがスクロールされた時.
		case WM_HSCROLL:	// 水平スクロールバーがスクロールされた時.(uMsgがWM_HSCROLLの時.)

			// WM_HSCROLLブロック
			{

				// 水平方向スクロールバー情報を取得.
				SCROLLINFO scrHorz = {0};	// 水平方向スクロール情報scrHorzを{0}で初期化.
				scrHorz.cbSize = sizeof(SCROLLINFO);	// sizeofで構造体サイズ指定.
				scrHorz.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// ページ, レンジ, 位置を取得.
				GetScrollInfo(hwnd, SB_HORZ, &scrHorz);	// GetScrollInfoでscrHorzを取得.

				// つまみの最大位置を計算.
				int iMaxPos = scrHorz.nMax + 1 - scrHorz.nPage;	// セットした最大値 + 1が大きさで, そこからページ数を引くと, つまみの最大の位置.

				// 変化量を0にリセット.
				dx = 0;	// dxを0にリセット.
			
				// 通知コード処理
				switch (LOWORD(wParam)){	// LOWORD(wParam)に行われた操作の通知コードが格納されているので, それで判定する.

					// 1番左
					case SB_LEFT:

						// 1番左にセット.
						scrHorz.nPos = scrHorz.nMin;	// 現在位置を1番左にセット.
						break;	// 抜ける.

					// 1番右
					case SB_RIGHT:

						// 1番右にセット.
						scrHorz.nPos = scrHorz.nMax;	// 現在位置を1番右にセット.
						break;	// 抜ける.

					// 1列左
					case SB_LINELEFT:

						// 1列左に戻す.
						if (scrHorz.nPos > scrHorz.nMin){	// scrHorz.nPosがscrHorz.nMinより大きい場合.
							dx = -1;	// 変化量-1.
							scrHorz.nPos--;	// 1戻る.
						}
						break;	// 抜ける.

					// 1列右
					case SB_LINERIGHT:

						// 1列右に進める.
						if (scrHorz.nPos < iMaxPos){	// scrHorz.nPosがiMaxPosより小さい場合.
							dx = 1;	// 変化量1.
							scrHorz.nPos++;	// 1進む.
						}
						break;	// 抜ける.

					// 1ページ左
					case SB_PAGELEFT:

						// SB_PAGELEFTブロック.
						{

							// 1ページ戻る.
							int after = scrHorz.nPos - scrHorz.nPage;	// 現在位置から1ページ分引く.
							if (after >= scrHorz.nMin){	// 下限を超えてなければ.
								dx = -1 * scrHorz.nPage;	// 1ページ分マイナス.
								scrHorz.nPos -= scrHorz.nPage;	// 1ページ分マイナス.
							}
							else{	// 下限を超えたら.
								dx = -1 * (scrHorz.nPos - scrHorz.nMin);	// 現在位置から最小値までの差に-1をかけて変化量とする.
								scrHorz.nPos = scrHorz.nMin;	// 最小値に.
							}

						}

						// 抜ける.
						break;	// breakで抜ける.

					// 1ページ右
					case SB_PAGERIGHT:

						// SB_PAGERIGHTブロック.
						{

							// 1ページ進む.
							int after = scrHorz.nPos + scrHorz.nPage;	// 現在位置から1ページ分足す.
							if (after <= iMaxPos){	// 上限を超えてなければ.
								dx = scrHorz.nPage;	// 1ページ分プラス.
								scrHorz.nPos += scrHorz.nPage;	// 1ページ分プラス.
							}
							else{	// 上限を超えたら.
								dx = iMaxPos - scrHorz.nPos;	// iMaxPosから現在位置までの差を変化量とする.
								scrHorz.nPos = scrHorz.nMax;	// 最大値に.
							}

						}

						// 抜ける.
						break;	// breakで抜ける.

					// スクロールつまみが離された時.
					case SB_THUMBPOSITION:


						// SB_THUMBPOSITIONブロック.
						{

							// 離された位置をセット.
							int before = scrHorz.nPos;	// 以前.
							int after = HIWORD(wParam);	// 以後.
							dx = after - before;	// 変化量はafterが大きいと+, beforeが大きいと-.
							scrHorz.nPos = after;	// HIWORD(wParam)に離された位置が格納されているのでscrHorz.nPosにセット.

						}

						// 抜ける.
						break;	// breakで抜ける.

					// それ以外.
					default:

						// 抜ける.
						break;	// breakで抜ける.

				}

				// scrHorz.nPosをhwndのSB_HORZにセット.
				SetScrollInfo(hwnd, SB_HORZ, &scrHorz, TRUE);	// SetScrollInfoで現在のscrHorz.nPosをhwndにセット.
				// クライアント領域のスクロール.
				ScrollWindow(hwnd, -dx, 0, NULL, NULL);	// ScrollWindowで-dx分スクロール.
				// 無効領域の計算.
				RECT rcClient = {0};	// クライアント領域rcClientを{0}で初期化.
				GetClientRect(hwnd, &rcClient);	// GetClientRectで現在のクライアント領域のRECTであるrcClientを取得.
				RECT rcInvalidate = {0};	// 無効領域rcInvalidateを{0}で初期化.
				if (dx < 0){	// dxがマイナスの時.
					rcInvalidate.left = rcClient.left;	// 0.
					rcInvalidate.top = rcClient.top;	// 0.
					rcInvalidate.right = -dx;	// 左から-dx(プラス)
					rcInvalidate.bottom = rcClient.bottom;	// 縦.
				}
				else{	// dxが0かプラスの時.
					rcInvalidate.left = rcClient.right - dx;	// 右から-dx(マイナス)
					rcInvalidate.top = rcClient.top;	// 0.
					rcInvalidate.right= rcClient.right;	// 横.
					rcInvalidate.bottom = rcClient.bottom;	// 縦.
				}
				// 無効領域の作成.
				InvalidateRect(hwnd, &rcInvalidate, FALSE);	// InvalidateRectで無効領域rcInvalidate作成.
				// ウィンドウの更新.
				UpdateWindow(hwnd);	// UpdateWinowでhwndの更新.

			}

			// 抜ける.
			break;	// breakで抜ける.

		// 垂直スクロールバーがスクロールされた時.
		case WM_VSCROLL:	// 垂直スクロールバーがスクロールされた時.(uMsgがWM_VSCROLLの時.)

			// WM_VSCROLLブロック
			{

				// 垂直方向スクロールバー情報を取得.
				SCROLLINFO scrVert = {0};	// 垂直方向スクロール情報scrVertを{0}で初期化.
				scrVert.cbSize = sizeof(SCROLLINFO);	// sizeofで構造体サイズ指定.
				scrVert.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// ページ, レンジ, 位置を取得.
				GetScrollInfo(hwnd, SB_VERT, &scrVert);	// GetScrollInfoでscrVertを取得.

				// つまみの最大位置を計算.
				int iMaxPos = scrVert.nMax + 1 - scrVert.nPage;	// セットした最大値 + 1が大きさで, そこからページ数を引くと, つまみの最大の位置.

				// 変化量を0にリセット.
				dy = 0;	// dyを0にリセット.
			
				// 通知コード処理
				switch (LOWORD(wParam)){	// LOWORD(wParam)に行われた操作の通知コードが格納されているので, それで判定する.

					// 1番上
					case SB_TOP:

						// 1番上にセット.
						scrVert.nPos = scrVert.nMin;	// 現在位置を1番上にセット.
						break;	// 抜ける.

					// 1番下
					case SB_BOTTOM:

						// 1番下にセット.
						scrVert.nPos = scrVert.nMax;	// 現在位置を1番下にセット.
						break;	// 抜ける.

					// 1列上
					case SB_LINEUP:

						// 1列上に戻す.
						if (scrVert.nPos > scrVert.nMin){	// scrVert.nPosがscrVert.nMinより大きい場合.
							dy = -1;	// 変化量-1.
							scrVert.nPos--;	// 1戻る.
						}
						break;	// 抜ける.

					// 1列下
					case SB_LINEDOWN:

						// 1列下に進める.
						if (scrVert.nPos < iMaxPos){	// scrVert.nPosがiMaxPosより小さい場合.
							dy = 1;	// 変化量1.
							scrVert.nPos++;	// 1進む.
						}
						break;	// 抜ける.

					// 1ページ上
					case SB_PAGEUP:

						// SB_PAGEUPブロック.
						{

							// 1ページ戻る.
							int after = scrVert.nPos - scrVert.nPage;	// 現在位置から1ページ分引く.
							if (after >= scrVert.nMin){	// 下限を超えてなければ.
								dy = -1 * scrVert.nPage;	// 1ページ分マイナス.
								scrVert.nPos -= scrVert.nPage;	// 1ページ分マイナス.
							}
							else{	// 下限を超えたら.
								dy = -1 * (scrVert.nPos - scrVert.nMin);	// 現在位置から最小値までの差に-1をかけて変化量とする.
								scrVert.nPos = scrVert.nMin;	// 最小値に.
							}

						}

						// 抜ける.
						break;	// breakで抜ける.

					// 1ページ下
					case SB_PAGEDOWN:

						// SB_PAGEDOWNブロック.
						{

							// 1ページ進む.
							int after = scrVert.nPos + scrVert.nPage;	// 現在位置から1ページ分足す.
							if (after <= iMaxPos){	// 上限を超えてなければ.
								dy = scrVert.nPage;	// 1ページ分プラス.
								scrVert.nPos += scrVert.nPage;	// 1ページ分プラス.
							}
							else{	// 上限を超えたら.
								dy = iMaxPos - scrVert.nPos;	// iMaxPosから現在位置までの差を変化量とする.
								scrVert.nPos = scrVert.nMax;	// 最大値に.
							}

						}

						// 抜ける.
						break;	// breakで抜ける.

					// スクロールつまみが離された時.
					case SB_THUMBPOSITION:


						// SB_THUMBPOSITIONブロック.
						{

							// 離された位置をセット.
							int before = scrVert.nPos;	// 以前.
							int after = HIWORD(wParam);	// 以後.
							dy = after - before;	// 変化量はafterが大きいと+, beforeが大きいと-.
							scrVert.nPos = after;	// HIWORD(wParam)に離された位置が格納されているのでscrVert.nPosにセット.

						}

						// 抜ける.
						break;	// breakで抜ける.

					// それ以外.
					default:

						// 抜ける.
						break;	// breakで抜ける.

				}

				// scrVert.nPosをhwndのSB_VERTにセット.
				SetScrollInfo(hwnd, SB_VERT, &scrVert, TRUE);	// SetScrollInfoで現在のscrVert.nPosをhwndにセット.
				// クライアント領域のスクロール.
				ScrollWindow(hwnd, 0, -dy, NULL, NULL);	// ScrollWindowで-dy分スクロール.
				// 無効領域の計算.
				RECT rcClient = {0};	// クライアント領域rcClientを{0}で初期化.
				GetClientRect(hwnd, &rcClient);	// GetClientRectで現在のクライアント領域のRECTであるrcClientを取得.
				RECT rcInvalidate = {0};	// 無効領域rcInvalidateを{0}で初期化.
				if (dy < 0){	// dyがマイナスの時.
					rcInvalidate.left = rcClient.left;	// 0.
					rcInvalidate.top = rcClient.top;	// 0.
					rcInvalidate.right = rcClient.right;	// 横.
					rcInvalidate.bottom = -dy;	// 上から-dy(プラス)
				}
				else{	// dyが0かプラスの時.
					rcInvalidate.left = rcClient.left;	// 0.
					rcInvalidate.top = rcClient.bottom - dy;	// 下から-dy(マイナス)
					rcInvalidate.right= rcClient.right;	// 横.
					rcInvalidate.bottom = rcClient.bottom;	// 縦.
				}
				// 無効領域の作成.
				InvalidateRect(hwnd, &rcInvalidate, FALSE);	// InvalidateRectで無効領域rcInvalidate作成.
				// ウィンドウの更新.
				UpdateWindow(hwnd);	// UpdateWinowでhwndの更新.

			}

			// 抜ける.
			break;	// breakで抜ける.

		// マウスの左ボタンが押された時.
		case WM_LBUTTONDOWN:	// マウスの左ボタンが押された時.(uMsgがWM_LBUTTONDOWNの時.)

			// WM_LBUTTONDOWNブロック
			{

				// クライアント領域のRECTを取得.
				RECT rc = {0};	// RECT型rcを{0}で初期化.
				GetClientRect(hwnd, &rc);	// クライアント領域のRECTを取得.

				// 水平方向スクロールバーの初期化.
				SCROLLINFO scrHorz = {0};	// 水平方向スクロール情報scrHorzを{0}で初期化.
				scrHorz.cbSize = sizeof(SCROLLINFO);	// sizeofで構造体サイズ指定.
				scrHorz.nMin = 0;	// 最小値は0.
				scrHorz.nMax = bitmap.bmWidth - 1;	// 最大値はbitmap.bmWidth.
				scrHorz.nPage = rc.right - rc.left;	// ページサイズはrc.right - rc.left.
				scrHorz.nPos = 0;	// 現在位置は0.
				scrHorz.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// ページ, レンジ, 位置をセット.
				SetScrollInfo(hwnd, SB_HORZ, &scrHorz, TRUE);	// スクロール情報をセット.

				// 垂直方向スクロールバーの初期化.
				SCROLLINFO scrVert = {0};	// 垂直方向スクロール情報scrVertを{0}で初期化.
				scrVert.cbSize = sizeof(SCROLLINFO);	// sizeofで構造体サイズ指定.
				scrVert.nMin = 0;	// 最小値は0.
				scrVert.nMax = bitmap.bmHeight - 1;	// 最大値はbitmap.bmHeight.
				scrVert.nPage = rc.bottom - rc.top;	// ページサイズはrc.bottom - rc.top.
				scrVert.nPos = 0;	// 現在位置は0.
				scrVert.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// ページ, レンジ, 位置をセット.
				SetScrollInfo(hwnd, SB_VERT, &scrVert, TRUE);	// スクロール情報をセット.

				// ビット転送.
				BOOL b = BitBlt(hDC, 0, 0, rc.right - rc.left, rc.bottom - rc.top, hMemDC, 0, 0, SRCCOPY);	// BitBltでhMemDCからhDCに転送.

				// メッセージボックスにサイズ情報を表示.
				TCHAR tszBitmap[256] = {0};	// TCHAR文字配列tszBitmap(長さ256)を{0}で初期化.
				_stprintf(tszBitmap, _T("bitmap.bmWidth = %d\nbitmap.bmHeight = %d\nbitmap.bmBitsPixel = %d\nbitmap.bmPlanes = %d\nbitmap.bmType = %d\nbitmap.bmWidthBytes = %d"), bitmap.bmWidth, bitmap.bmHeight, bitmap.bmBitsPixel, bitmap.bmPlanes, bitmap.bmType, bitmap.bmWidthBytes);	// bitmapの各要素を文字列に変換.
				MessageBox(hwnd, tszBitmap, _T("BITMAP_struct"), MB_OK);	// tszBitmapをメッセージボックス表示.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// 上記以外の時.
		default:	// 上記以外の値の時の既定処理.

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

	}

	// あとは既定の処理に任せる.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// 戻り値も含めDefWindowProcに既定の処理を任せる.

}