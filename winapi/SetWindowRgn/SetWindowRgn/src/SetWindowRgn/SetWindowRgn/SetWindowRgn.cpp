// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理をするように定義したコールバック関数WindowProc.
 
// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){
 
	// 変数の宣言
	HWND hWnd;			// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;			// ウィンドウメッセージ情報を格納するMSG構造体型変数msg.
	WNDCLASS wc;		// ウィンドウクラス情報をもつWNDCLASS構造体型変数wc.
 
	// ウィンドウクラスの設定
	wc.lpszClassName = _T("SetWindowRgn");					// ウィンドウクラス名は"SetWindowRgn".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;							// ウィンドウプロシージャは独自の処理を定義したWindowProc.
	wc.hInstance = hInstance;								// インスタンスハンドルは_tWinMainの引数.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// アイコンはアプリケーション既定のもの.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// カーソルは矢印.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 背景は白ブラシ.
	wc.lpszMenuName = NULL;									// メニューはなし.
	wc.cbClsExtra = 0;										// 0でいい.
	wc.cbWndExtra = 0;										// 0でいい.
 
	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)){	// RegisterClassでウィンドウクラスを登録し, 0が返ったらエラー.
 
		// エラー処理
		MessageBox(NULL, _T("RegisterClass failed!"), _T("SetWindowRgn"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)
 
	}
 
	// ウィンドウの作成.(WS_POPUPと幅と高さを明示的に指定.)
	hWnd = CreateWindow(_T("SetWindowRgn"), _T("SetWindowRgn"), WS_POPUP, 0, 0, 640, 480, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"SetWindowRgn"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.
 
		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("SetWindowRgn"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)
 
	}
 
	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.
 
	// メッセージループ
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessageでメッセージを取得, 戻り値が0より大きい間はループし続ける.
 
		// ウィンドウメッセージの送出
		DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(この場合は独自に定義したWindowProc)に送出.
 
	}
 
	// プログラムの終了
	return (int)msg.wParam;	// 終了コード(msg.wParam)を戻り値として返す.
 
}
 
// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// ウィンドウメッセージに対して独自の処理をするように定義したウィンドウプロシージャ.

	// ウィンドウプロシージャ全体で使われるスタティック変数の宣言.
	static HBITMAP hBitmap;	// ロードしたビットマップのハンドルを格納するHBITMAP型スタティック変数hBitmap.
	static HRGN hRgn1;		// スタティックな矩形リージョンのハンドルhRgn1.
	static HRGN hRgn2;		// スタティックな楕円リージョンのハンドルhRgn2.
	static HRGN hRgn3;		// 空のリージョンのハンドルhRgn3.

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-casa文でuMsgの値ごとに処理を振り分ける.
 
		// ウィンドウの作成が開始された時.
		case WM_CREATE:		// ウィンドウの作成が開始された時.(uMsgがWM_CREATEの時.)
 
			// WM_CREATEブロック
			{

				// このブロックのローカル変数の宣言
				LPCREATESTRUCT lpcs;	// lParamから渡されたCREATESTRUCTへのポインタを格納するlpcs.

				// lParamをlpcsに渡す.
				lpcs = (LPCREATESTRUCT)lParam; // lParamをLPCREATESTRUCTにキャストしてlpcsに格納.

				// ビットマップのロード
				hBitmap = (HBITMAP)LoadImage(lpcs->hInstance, _T("test.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);	// LoadImageで"test.bmp"をロードし, 戻り値のビットマップハンドルはhBitmapに格納する.
				if (hBitmap == NULL) {	// hBitmapがNULLならロード失敗.

					// エラー処理
					MessageBox(hwnd, _T("LoadImage failed!"), _T("SetWindowRgn"), MB_OK | MB_ICONHAND);	// MessageBoxで"LoadImage failed!"とエラーメッセージを表示.
					return -1;	// 異常終了なので-1を返して, ウィンドウ生成失敗とする.

				}

				// 矩形のリージョンを生成.
				hRgn1 = CreateRectRgn(10, 10, 250, 250);	// CreateRectRgnで矩形のリージョンを生成.

				// 楕円のリージョンを生成.
				hRgn2 = CreateEllipticRgn(100, 50, 400, 300);	//  CreateEllipticRgnで楕円のリージョンを生成.

				// 空のリージョンを生成.
				hRgn3 = CreateRectRgn(0, 0, 0, 0);	// CreateRectRgnに(0, 0, 0, 0)を指定して空のリージョンを生成.

				// リージョンの結合.
				CombineRgn(hRgn1, hRgn1, hRgn2, RGN_OR);	// hRgn1とhRgn2の領域の和.

				// リージョンのコピー.(hRgn3はウィンドウにセットするとシステム管理となるため解放してはいけない.)
				CombineRgn(hRgn3, hRgn1, NULL, RGN_COPY);	// ウィンドウ用のリージョンハンドルhRgn3にコピー.

				// リージョンをウィンドウにセット.
				SetWindowRgn(hwnd, hRgn3, TRUE);	// SetWindowRgnでhwndにhRgn3をセット.

				// ウィンドウ作成成功
				return 0;	// return文で0を返して, ウィンドウ作成成功とする.
 
			}
 
			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.
 
		// ウィンドウが破棄された時.
		case WM_DESTROY:	// ウィンドウが破棄された時.(uMsgがWM_DESTROYの時.)
 
			// WM_DESTROYブロック
			{

				// ビットマップの終了処理
				if (hBitmap != NULL) {	// hBitmapがNULLでない場合.(ロードしたままの状態の場合.)

					// ビットマップの破棄
					DeleteObject(hBitmap);	// DeleteObjectでhBitmapの破棄.
					hBitmap = NULL;	// hBitmapはNULLにしておく.

				}

				// 楕円リージョンの削除
				DeleteObject(hRgn2);	// DeleteObjectでhRgn2を削除.

				// 矩形リージョンの削除
				DeleteObject(hRgn1);	// DeleteObjectでhRgn1を削除.

				// 終了メッセージの送信.
				PostQuitMessage(0);	// PostQuitMessageで終了コードを0としてWM_QUITメッセージを送信.(するとメッセージループのGetMessageの戻り値が0になるので, メッセージループから抜ける.)
 
			}
 
			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// 画面の描画を要求された時.
		case WM_PAINT:		// 画面の描画を要求された時.(uMsgがWM_PAINTの時.)
 
			// WM_PAINTブロック
			{

				// このブロックのローカル変数の宣言
				HDC hDC;			// デバイスコンテキストハンドルを格納するHDC型変数hDC.
				PAINTSTRUCT ps;		// ペイント情報を管理するPAINTSTRUCT構造体型の変数ps.
				HDC hMemDC;			// ウィンドウのデバイスコンテキストと互換性のあるメモリデバイスコンテキストハンドルを格納するHDC型変数hMemDC.
				HBITMAP hOldBitmap;	// SelectObjectされるまで選択していた古いビットマップのハンドルhOldBitmap.

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にはデバイスコンテキストハンドルが返るので, hDCに格納.

				// メモリデバイスコンテキストの生成
				hMemDC = CreateCompatibleDC(hDC);	// CreateCompatibleDCでウィンドウのデバイスコンテキストhDCと互換性のあるメモリデバイスコンテキストhMemDCを生成.

				// ロードしたビットマップ"test.bmp"を使用するようにメモリデバイスコンテキストに選択させる.
				hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBitmap);	// SelectObjectでhMemDCにロードしたビットマップhBitmapを選択させる.(それまで使っていたビットマップのハンドルが返るので, hOldBitmapに格納.)

				// ロードした画像の表示.
				BitBlt(hDC, 0, 0, 640, 480, hMemDC, 0, 0, SRCCOPY);	// BitBltでhMemDCのピクセル列をhDCに転送することで, ウィンドウにロードした画像が表示される.

				// ビットマップの状態を戻す.
				SelectObject(hMemDC, hOldBitmap);	// メモリデバイスコンテキストに元のhOldBitmapに戻すように選択させる.

				// メモリデバイスコンテキストの破棄
				DeleteDC(hMemDC);	// DeleteDCでhMemDCを破棄.

				// ウィンドウの描画終了
				EndPaint(hwnd, &ps);	// EndPaintでこのウィンドウの描画処理を終了する.

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