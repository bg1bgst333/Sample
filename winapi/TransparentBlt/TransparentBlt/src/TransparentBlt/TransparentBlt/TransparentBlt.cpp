// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理ができるように定義したコールバック関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;			// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;			// ウィンドウメッセージを格納するMSG構造体型変数msg.
	WNDCLASS wc;		// ウィンドウクラスを設定するWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("TransparentBlt");					// ウィンドウクラス名は"TransparentBlt".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;								// ウィンドウプロシージャは独自の処理を定義したWindowProc.
	wc.hInstance = hInstance;									// インスタンスハンドルは_tWinMainの引数.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// アイコンはアプリケーション既定のもの.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);					// カーソルは矢印.
	wc.hbrBackground = CreateSolidBrush(RGB(200, 220, 255));	// 背景は水色ブラシ.(白背景だとBitBltの白い部分と見分けがつかなくなるため.)
	wc.lpszMenuName = NULL;										// メニューはなし.
	wc.cbClsExtra = 0;											// 0でよい.
	wc.cbWndExtra = 0;											// 0でよい.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)){	// RegisterClassでウィンドウクラスを登録し, 0が返ったらエラー.

		// エラー処理
		MessageBox(NULL, _T("RegisterClass failed!"), _T("TransparentBlt"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("TransparentBlt"), _T("TransparentBlt"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"TransparentBlt"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("TransparentBlt"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.

	// メッセージループ
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessageでメッセージを取得, 戻り値が0より大きい間はループを続ける.

		// ウィンドウメッセージの送出
		DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(この場合は独自に定義したWindowProc)に送出.

	}

	// プログラムの終了
	return (int)msg.wParam;	// 終了コード(msg.wParam)を戻り値として返す.

}

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// ウィンドウメッセージに対して独自の処理ができるように定義したウィンドウプロシージャ.

	// ウィンドウプロシージャ全体で使うスタティック変数の宣言.
	static HBITMAP hBitmap;	// ロードしたビットマップのハンドルを格納するHBITMAP型スタティック変数hBitmap.
	static COLORREF crTransparent;	// 透過色として使うCOLORREF型スタティック変数crTransparent.

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-case文でuMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始されたとき.
		case WM_CREATE:		// ウィンドウの作成が開始されたとき.(uMsgがWM_CREATEの場合.)

			// WM_CREATEブロック
			{

				// このブロックのローカル変数の宣言
				LPCREATESTRUCT lpcs;	// lParamから渡されたCREATESTRUCTへのポインタを格納するlpcs.

				// lParamをlpcsに渡す.
				lpcs = (LPCREATESTRUCT)lParam; // lParamをLPCREATESTRUCTにキャストしてlpcsに格納.

				// ビットマップのロード
				hBitmap = (HBITMAP)LoadImage(lpcs->hInstance, _T("icon_clean.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);	// LoadImageで"icon_clean.bmp"をロードし, 戻り値のビットマップハンドルをhBitmapに格納する.
				if (hBitmap == NULL){	// hBitmapがNULLならロード失敗.

					// エラー処理
					MessageBox(hwnd, _T("LoadImage failed!"), _T("TransparentBlt"), MB_OK | MB_ICONHAND);	// MessageBoxで"LoadImage failed!"とエラーメッセージを表示.
					return -1;	// 異常終了なので-1を返して, ウィンドウ作成失敗とする.

				}

				// 透過色のサンプリング.(左上(0, 0)のピクセルの色を透過色として使う. 見た目は白でも, 実際の値は完全な白(255, 255, 255)とは限らないため.)
				{

					// このブロックのローカル変数の宣言
					HDC hDCTemp;			// サンプリング用のデバイスコンテキストハンドルhDCTemp.
					HDC hMemDCTemp;			// サンプリング用のメモリデバイスコンテキストハンドルhMemDCTemp.
					HBITMAP hOldBitmapTemp;	// サンプリング用のSelectObject前のビットマップハンドルhOldBitmapTemp.

					// デバイスコンテキストの取得とメモリデバイスコンテキストの生成.
					hDCTemp = GetDC(hwnd);	// GetDCでウィンドウのデバイスコンテキストを取得.
					hMemDCTemp = CreateCompatibleDC(hDCTemp);	// CreateCompatibleDCで互換のメモリデバイスコンテキストを生成.
					hOldBitmapTemp = (HBITMAP)SelectObject(hMemDCTemp, hBitmap);	// SelectObjectでhBitmapを選択.

					// 左上(0, 0)のピクセルの色を取得し, 透過色として保持しておく.
					crTransparent = GetPixel(hMemDCTemp, 0, 0);	// GetPixelで(0, 0)の色を取得し, crTransparentに格納.

					// 後始末.
					SelectObject(hMemDCTemp, hOldBitmapTemp);	// SelectObjectで元のビットマップに戻す.
					DeleteDC(hMemDCTemp);	// DeleteDCでhMemDCTempを破棄.
					ReleaseDC(hwnd, hDCTemp);	// ReleaseDCでhDCTempを解放.

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

				// ビットマップの終了処理
				if (hBitmap != NULL){	// hBitmapがNULLでない場合.(ロードされたままの状態の場合.)

					// ビットマップの破棄
					DeleteObject(hBitmap);	// DeleteObjectでhBitmapの破棄.
					hBitmap = NULL;	// hBitmapをNULLにしておく.

				}

				// 終了メッセージの送信.
				PostQuitMessage(0);	// PostQuitMessageで終了コードを0としてWM_QUITメッセージを送信.(これでメッセージループのGetMessageの戻り値が0になるので, メッセージループから抜ける.)

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
				HDC hMemDC;			// ウィンドウのデバイスコンテキストと互換性のあるメモリデバイスコンテキストハンドルを格納するHDC型変数hMemDC.
				HBITMAP hOldBitmap;	// SelectObjectをする前まで選択されていた古いビットマップのハンドルhOldBitmap.

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にはデバイスコンテキストハンドルが返るので, hDCに格納.

				// メモリデバイスコンテキストの生成
				hMemDC = CreateCompatibleDC(hDC);	// CreateCompatibleDCでウィンドウのデバイスコンテキストhDCと互換性のあるメモリデバイスコンテキストhMemDCを生成.

				// ロードしたビットマップ"icon_clean.bmp"を使用するようにメモリデバイスコンテキストに選択させる.
				hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBitmap);	// SelectObjectでhMemDCにロードしたビットマップhBitmapを選択させる.(それまで使われていたビットマップのハンドルが返るので, hOldBitmapに格納.)

				// 見出しのテキスト表示.
				TextOut(hDC, 50, 30, _T("BitBlt"), lstrlen(_T("BitBlt")));	// TextOutで"BitBlt"というラベルを表示.
				TextOut(hDC, 200, 30, _T("TransparentBlt"), lstrlen(_T("TransparentBlt")));	// TextOutで"TransparentBlt"というラベルを表示.

				// BitBltでそのまま描画.(白い背景ごと四角く表示される.)
				BitBlt(hDC, 50, 60, 32, 32, hMemDC, 0, 0, SRCCOPY);	// BitBltでhMemDCのピクセルをhDCに転送することで, ウィンドウにロードした画像を表示させる.

				// TransparentBltで白を透過色に指定して描画.(白い背景が透けて, アイコンだけが表示される.)
				TransparentBlt(hDC, 200, 60, 32, 32, hMemDC, 0, 0, 32, 32, crTransparent);	// TransparentBltでcrTransparent(サンプリングした背景色)を透過色に指定して転送することで, 背景を透過させてアイコンだけを表示させる.

				// ビットマップの状態を戻す.
				SelectObject(hMemDC, hOldBitmap);	// メモリデバイスコンテキストに元のhOldBitmapに戻すように選択させる.

				// メモリデバイスコンテキストの破棄
				DeleteDC(hMemDC);	// DeleteDCでhMemDCを破棄.

				// ウィンドウの描画終了
				EndPaint(hwnd, &ps);	// EndPaintでこのウィンドウの描画処理を終了させる.

			}

			// 次の処理へ続く.
			break;	// breakで抜けて, 次の処理(DefWindowProc)へ続く.

		// 上記以外の時.
		default:	// 上記以外の値の時の既定処理.

			// 次の処理へ続く.
			break;	// breakで抜けて, 次の処理(DefWindowProc)へ続く.

	}

	// あとは既定の処理に任せる.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// 戻り値もまとめてDefWindowProcに既定の処理を任せる.

}
nd, uMsg, wParam, lParam);	// 戻り値もまとめてDefWindowProcに既定の処理を任せる.

}
