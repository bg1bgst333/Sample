// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理をするように定義したコールバック関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数・配列の宣言・初期化
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージ情報を格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラス情報をもつWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("ScrollWindow");					// ウィンドウクラス名は"ScrollWindow".
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
		MessageBox(NULL, _T("RegisterClass Failure!"), _T("ScrollWindow"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass Failure!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("ScrollWindow"), _T("ScrollWindow"), WS_OVERLAPPEDWINDOW | WS_VSCROLL, 0, 0, 480, 360, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"ScrollWindow"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow Failure!"), _T("ScrollWindow"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow Failure!"とエラーメッセージを表示.
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
	static SCROLLINFO scrVert = {0};	// 垂直方向スクロール情報scrVertを{0}で初期化.

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
					MessageBox(hwnd, _T("LoadImage failed!"), _T("ScrollWindow"), MB_OK | MB_ICONHAND);	// MessageBoxで"LoadImage failed!"とエラーメッセージを表示.
					return -1;	// 異常終了なので-1を返して, ウィンドウ生成失敗とする.

				}

				// ウィンドウデバイスコンテキストハンドルの取得.
				hDC = GetDC(hwnd);	// GetDCでhDC取得.
				if (hDC == NULL){	// NULLなら.

					// エラー処理
					MessageBox(hwnd, _T("GetDC failed!"), _T("ScrollWindow"), MB_OK | MB_ICONHAND);	// MessageBoxで"GetDC failed!"とエラーメッセージを表示.
					if (hBitmap != NULL){	// NULLでなければ.
						DeleteObject(hBitmap);	// DeleteObjectでhBitmapを破棄.
						hBitmap = NULL;	// NULLをセット.
					}
					return -2;	// 異常終了なので-2を返して, ウィンドウ生成失敗とする.

				}

				// メモリデバイスコンテキストの生成.
				hMemDC = CreateCompatibleDC(hDC);	// CreateCompatibleDCでhMemDC取得.
				if (hMemDC == NULL){	// NULLでなければ.

					// エラー処理
					MessageBox(hwnd, _T("CreateCompatibleDC failed!"), _T("ScrollWindow"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateCompatibleDC failed!"とエラーメッセージを表示.
					if (hDC != NULL){	// NULLでなければ.
						ReleaseDC(hwnd, hDC);	// ReleaseDCでhDCの解放.
						hDC = NULL;	// NULLをセット.
					}
					if (hBitmap != NULL){	// NULLでなければ.
						DeleteObject(hBitmap);	// DeleteObjectでhBitmapを破棄.
						hBitmap = NULL;	// NULLをセット.
					}
					return -3;	// 異常終了なので-3を返して, ウィンドウ生成失敗とする.

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

		// 垂直スクロールバーがスクロールされた時.
		case WM_VSCROLL:	// 垂直スクロールバーがスクロールされた時.(uMsgがWM_VSCROLLの時.)

			// WM_VSCROLLブロック
			{

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

					// 1行上
					case SB_LINEUP:

						// 1行上に戻す.
						if (scrVert.nPos > 0){	// scrVert.nPosが1以上なら.
							scrVert.nPos--;	// scrVert.nPosを減らす.
							// 変化量だけスクロール.
							ScrollWindow(hwnd, 0, 1, NULL, NULL);	// ScrollWindowでスクロール.
						}
						break;	// 抜ける.

					// 1行下
					case SB_LINEDOWN:

						// 1行下に進める.
						if (scrVert.nPos < scrVert.nMax - (int)scrVert.nPage + 1){	// scrVert.nPosが最後の位置より前なら.
							scrVert.nPos++;	// scrVert.nPosを増やす.
							// 変化量だけスクロール.
							ScrollWindow(hwnd, 0, -1, NULL, NULL);	// ScrollWindowでスクロール.
						}
						break;	// 抜ける.

					// 1ページ上
					case SB_PAGEUP:

						// SB_PAGEUPブロック.
						{

							// 1ページ戻る.	
							int pos = scrVert.nPos;	// 以前の位置
							int page = scrVert.nPage;	// ページサイズ
							int vMax = scrVert.nMax;	// 最大値
							int after = pos - page;	// ページサイズを引いた時の位置.
							int f = 0;	// 実際の最初の位置.
							int d = 0;	// 変化量.
							if (after <= f){	// ページサイズを引いた時の位置が0以下.
								scrVert.nPos = f;	// 位置は0.
								d = pos;	// 以前の位置が変化量.
							}
							else{	// 超えてない.
								scrVert.nPos -= page;	// ページサイズを引く.
								d = page;	// ページサイズが変化量.
							}
							// 変化量だけスクロール.
							ScrollWindow(hwnd, 0, d, NULL, NULL);	// ScrollWindowでスクロール.

						}

						// 抜ける.
						break;	// breakで抜ける.

					// 1ページ下
					case SB_PAGEDOWN:

						// SB_PAGEDOWNブロック.
						{

							// 1ページ進む.
							int pos = scrVert.nPos;	// 以前の位置
							int page = scrVert.nPage;	// ページサイズ
							int vMax = scrVert.nMax;	// 最大値
							int after = pos + page;	// ページサイズを足した時の位置.
							int f = vMax - page + 1;	// 実際の最後の位置.
							int d = 0;	// 変化量.
							if (after >= f){	// ページサイズを足した時の位置が, 実際の最後の位置を超えている.
								scrVert.nPos = f;	// 実際の最後の位置をセット.
								d = f - pos;	// 最後の位置から以前の位置までが変化量.
							}
							else{	// 超えていない.
								scrVert.nPos += page;	// ページサイズを足す.
								d = page;	// ページサイズが変化量.
							}
							// 変化量だけスクロール.
							ScrollWindow(hwnd, 0, -1 * d, NULL, NULL);	// ScrollWindowでスクロール.

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
							scrVert.nPos = after;	// HIWORD(wParam)に離された位置が格納されているのでscrVert.nPosにセット.
							// 変化量だけスクロール.
							ScrollWindow(hwnd, 0, before - after, NULL, NULL);	// ScrollWindowでスクロール.

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

			}

			// 抜ける.
			break;	// breakで抜ける.

		// マウスの左ボタンが押された時.
		case WM_LBUTTONDOWN:	// マウスの左ボタンが押された時.(uMsgがWM_LBUTTONDOWNの時.)

			// WM_LBUTTONDOWNブロック
			{

				// ビット転送.
				RECT rc = {0};	// RECT型rcを{0}で初期化.
				GetClientRect(hwnd, &rc);	// クライアント領域のRECTを取得.
				scrVert.cbSize = sizeof(SCROLLINFO);	// sizeofで構造体サイズ指定.
				scrVert.nMin = 0;	// 最小値は0.
				scrVert.nMax = 480 - 1;	// 最大値は479.
				scrVert.nPage = rc.bottom - rc.top + 1;	// ページサイズはrc.bottom - rc.top + 1.
				scrVert.fMask = SIF_PAGE | SIF_RANGE;	// ページ, レンジをセット.
				SetScrollInfo(hwnd, SB_VERT, &scrVert, TRUE);	// スクロール情報をセット.
				scrVert.nPos = 0;	// 現在位置は0.
				scrVert.fMask = SIF_POS;	// 位置をセット.
				SetScrollInfo(hwnd, SB_VERT, &scrVert, TRUE);	// スクロール情報をセット.
				BOOL b = BitBlt(hDC, 0, 0, rc.right - rc.left + 1, rc.bottom - rc.top + 1, hMemDC, 0, 0, SRCCOPY);	// BitBltでhMemDCからhDCに転送.

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