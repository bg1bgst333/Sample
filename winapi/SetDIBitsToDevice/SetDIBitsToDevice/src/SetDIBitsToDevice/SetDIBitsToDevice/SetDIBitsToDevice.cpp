// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理をするように定義したコールバンク関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;			// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;			// ウィンドウメッセージ情報を格納するMSG構造体型変数msg.
	WNDCLASS wc;		// ウィンドウクラス情報をもつWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("SetDIBitsToDevice");				// ウィンドウクラス名は"SetDIBitsToDevice".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("SetDIBitsToDevice"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("SetDIBitsToDevice"), _T("SetDIBitsToDevice"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"SetDIBitsToDevice"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("SetDIBitsToDevice"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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

	// ウィンドウプロシージャ全体で使われるスタティック変数の宣言.
	static HBITMAP hBackBitmap;		// バックバッファ用ビットマップのハンドルを格納するHBITMAP型スタティック変数hBackBitmap.
	static LPBYTE lpBitsPixel;		// ピクセルビット列lpBitsPixel.
	static HDC hBackMemDC;			// hBackBitmap用のデバイスコンテキストhBackMemDC.
	static HBITMAP hOldBackBitmap;	// 選択前のバックバッファビットマップhOldBackBitmap.
	static BITMAPINFO bi;			// BITMAPINFO構造体変数bi.

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-casa文でuMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始された時.
		case WM_CREATE:		// ウィンドウの作成が開始された時.(uMsgがWM_CREATEの時.)

			// WM_CREATEブロック
			{

				// このブロックのローカル変数の宣言・初期化
				HDC hDC = NULL;			// ウィンドウのデバイスコンテキストハンドルhDCをNULLに初期化.(互換ビットマップ作成に必要.)
				HANDLE hFile;			// ファイルハンドルhFile.
				DWORD dwSize;			// ファイルサイズdwSize.
				BITMAPFILEHEADER bfh;	// BITMAPFILEHEADER構造体変数bfh.
				DWORD dwReadBytes;		// 読み込んだ長さdwReadBytes.

				// ウィンドウのデバイスコンテキストハンドルを取得.
				hDC = GetDC(hwnd);	// GetDCでウィンドウのデバイスコンテキストハンドルを取得し, hDCに格納.

				// バックバッファ用ビットマップを生成.
				hBackBitmap = (HBITMAP)CreateCompatibleBitmap(hDC, 640, 480);	// CreateCompatibleBitmapでサイズ(640, 480)のhDCと互換性のあるビットマップhBackBitmapを作成.

				// ファイルを開く
				hFile = CreateFile(_T("test.bmp"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFileで"test.bmp"を開いて, 取得したハンドルをhFileに格納.
				if (hFile == INVALID_HANDLE_VALUE){	// hFileがINVALID_HANDLE_VALUEなら.

					// エラー処理
					DeleteObject(hBackBitmap);	// DeleteObjectでhBackBitmapを削除.
					ReleaseDC(hwnd, hDC);	// ReleaseDCでhDCを解放.
					hDC = NULL;	// hDCをNULLにする.
					return -1;	// -1を返す.

				}

				// ファイルサイズの取得.
				dwSize = GetFileSize(hFile, NULL);	// GetFileSizeで"test.bmp"のファイルサイズを取得する.

				// BITMAPFILEHEADERの読み込み.
				ReadFile(hFile, &bfh, sizeof(BITMAPFILEHEADER), &dwReadBytes, NULL);	// ReadFileでBITMAPFILEHEADERを読み込む.

				// BITMAPINFOHEADERの読み込み.(BITMAPINFO構造体にBITMAPINFOHEADERのみ読み込む.)
				ReadFile(hFile, &bi, sizeof(BITMAPINFOHEADER), &dwReadBytes, NULL);	// ReadFileでBITMAPINFOの構造体変数にBITMAPINFOHEADERのデータのみ読み込む.

				// ピクセル列を格納するバッファの確保.
				lpBitsPixel = new BYTE[dwSize - bfh.bfOffBits];	// dwSize - bfh.bfOffBits = (ピクセル列のサイズ)

				// ピクセル列の読み込み.
				ReadFile(hFile, lpBitsPixel, dwSize - bfh.bfOffBits, &dwReadBytes, NULL);	// ReadFileでピクセル列を読み込む.

				// hBackMemDC用のメモリデバイスコンテキストを作成.
				hBackMemDC = CreateCompatibleDC(hDC);	// CreateCompatibleDCでhBackMemDC用のメモリデバイスコンテキストを作成.

				// バックバッファビットマップの選択.
				hOldBackBitmap = (HBITMAP)SelectObject(hBackMemDC, hBackBitmap);	// SelectObjectでhBackBitmapを選択.

				// 閉じる.
				CloseHandle(hFile);	// CloseHandleでhFileを閉じる.

				// ウィンドウのデバイスコンテキストを解放.
				ReleaseDC(hwnd, hDC);	// ReleaseDCでhDCを解放.
				hDC = NULL;	// hDCをNULLにする.

				// 0を返す.
				return 0;	// return 0.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.
		
		// ウィンドウが破棄された時.
		case WM_DESTROY:	// ウィンドウが破棄された時.(uMsgがWM_DESTROYの時.)

			// WM_DESTROYブロック
			{

				// 元に戻す.
				SelectObject(hBackMemDC, hOldBackBitmap);	// SelectObjectでhOldBackBitmapに戻す.

				// hBackMemDCの削除
				if (hBackMemDC){	// hBackMemDCがNULLでない時.
					DeleteDC(hBackMemDC);	// DeleteDCでhBackMemDCを削除.
					hBackMemDC = NULL;		// NULLを代入.
				}

				// ピクセル列の解放.
				if (lpBitsPixel){	// hBitsPixelがNULLでない時.
					delete[] lpBitsPixel;	// delete[]でlpBitsPixelを解放.
					lpBitsPixel = NULL;		// NULLを代入.
				}

				// バックバッファ用ビットマップの削除.
				if (hBackBitmap){	// hBackBitmapがNULLでない時.
					DeleteObject(hBackBitmap);	// DeleteObjectでhBackBitmapを削除.
					hBackBitmap = NULL;		// NULLを代入.
				}

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

				// DIBをそのまま描画.
				SetDIBitsToDevice(hBackMemDC, 0, 0, bi.bmiHeader.biWidth, bi.bmiHeader.biHeight, 0, 0, 0, 480, lpBitsPixel, &bi, DIB_RGB_COLORS);	// SetDIBitsToDeviceでDIBのlpBitsPixelをhBackMemDCに描画.
				BitBlt(hDC, 0, 0, 640, 480, hBackMemDC, 0, 0, SRCCOPY);	// BitBltでhBackMemDCをhDCに描画.

				// ウィンドウの描画終了
				EndPaint(hwnd, &ps);	// EndPaintでこのウィンドウの描画処理を終了する.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		default:

			break;

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}