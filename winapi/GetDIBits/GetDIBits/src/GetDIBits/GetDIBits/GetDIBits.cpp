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
	wc.lpszClassName = _T("GetDIBits");						// ウィンドウクラス名は"GetDIBits".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("GetDIBits"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("GetDIBits"), _T("GetDIBits"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"GetDIBits"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("GetDIBits"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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
	static HBITMAP hLoadDDB;		// 表示するDDBのハンドルを格納するHBITMAP型スタティック変数hLoadDDB.
	static HDC hBackMemDC;			// hBackBitmap用のデバイスコンテキストhBackMemDC.
	static HDC hDDBMemDC;			// hLoadDDB用のデバイスコンテキストhDDBMemDC.
	static HBITMAP hOldBackBitmap;	// 選択前のバックバッファビットマップhOldBackBitmap.
	static HBITMAP hOldLoadDDB;		// 選択前のDDB側のビットマップhOldLoadDDB.

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-casa文でuMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始された時.
		case WM_CREATE:		// ウィンドウの作成が開始された時.(uMsgがWM_CREATEの時.)

			// WM_CREATEブロック
			{

				// このブロックのローカル変数の宣言・初期化
				HDC hDC = NULL;			// ウィンドウのデバイスコンテキストハンドルhDCをNULLに初期化.(互換ビットマップ作成に必要.)
				LPCREATESTRUCT lpcs;	// lParamから渡されたCREATESTRUCTへのポインタを格納するlpcs.

				// lParamをlpcsに渡す.
				lpcs = (LPCREATESTRUCT)lParam; // lParamをLPCREATESTRUCTにキャストしてlpcsに格納.

				// ウィンドウのデバイスコンテキストハンドルを取得.
				hDC = GetDC(hwnd);	// GetDCでウィンドウのデバイスコンテキストハンドルを取得し, hDCに格納.

				// バックバッファ用ビットマップを生成.
				hBackBitmap = (HBITMAP)CreateCompatibleBitmap(hDC, 640, 480);	// CreateCompatibleBitmapでサイズ(640, 480)のhDCと互換性のあるビットマップhBackBitmapを作成.

				// 表示するDDBをロード.
				hLoadDDB = (HBITMAP)LoadImage(lpcs->hInstance, _T("test.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);	// LoadImageで"test.bmp"をロードし, 戻り値のビットマップハンドルをhLoadDDBに格納.

				// hBackMemDC用のメモリデバイスコンテキストを作成.
				hBackMemDC = CreateCompatibleDC(hDC);	// CreateCompatibleDCでhBackMemDC用のメモリデバイスコンテキストを作成.

				// hDDB用のメモリデバイスコンテキストを作成.
				hDDBMemDC = CreateCompatibleDC(hDC);	// CreateCompatibleDCでhDDB用のメモリデバイスコンテキストを作成.

				// バックバッファビットマップの選択.
				hOldBackBitmap = (HBITMAP)SelectObject(hBackMemDC, hBackBitmap);	// SelectObjectでhBackBitmapを選択.

				// DDBの選択.
				hOldLoadDDB = (HBITMAP)SelectObject(hDDBMemDC, hLoadDDB);

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

				// ローカル変数の宣言.
				HDC hDC;				// デバイスコンテキストハンドルhDC
				BITMAPINFO bi;			// ビットマップ情報bi.
				LPBYTE lpBitsPixel;		// ピクセル列へのポインタlpBitsPixel.
				BITMAPFILEHEADER bfh;	// ビットマップファイル情報bfh.
				HANDLE hFile;			// ファイルハンドルhFile.
				DWORD dwBytes;			// 書き込みバイト数.

				// 元に戻す.
				SelectObject(hDDBMemDC, hOldLoadDDB);		// SelectObjectでhOldLoadDDBに戻す.

				// 元に戻す.
				SelectObject(hBackMemDC, hOldBackBitmap);	// SelectObjectでhOldBackBitmapに戻す.

				// ビットマップ情報のセット.(これらはセットしておかないといけない.)
				bi.bmiHeader.biBitCount = 24;
				bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
				bi.bmiHeader.biWidth = 640;
				bi.bmiHeader.biHeight = 480;
				bi.bmiHeader.biPlanes = 1;
				bi.bmiHeader.biCompression = BI_RGB;

				// デバイスコンテキストハンドルの取得.
				hDC = GetDC(hwnd);	// GetDCでデバイスコンテキストハンドルの取得.
				
				// DDBからDIBのピクセル列を取得.(ピクセル列のサイズはGetDIBitsで取れる.)
				GetDIBits(hDC, hLoadDDB, 0, 480, NULL, &bi, DIB_RGB_COLORS);	// GetDIBitsでピクセル列のサイズ(bi.bmiHeader.biSizeImage)を取得.
				lpBitsPixel = new BYTE[bi.bmiHeader.biSizeImage];	// メモリ確保.
				GetDIBits(hDC, hLoadDDB, 0, 480, lpBitsPixel, &bi, DIB_RGB_COLORS);	// GetDIBitsでDDBからDIBのピクセル列を取得.

				// デバイスコンテキストハンドルの解放.
				ReleaseDC(hwnd, hDC);	// ReleaseDCでデバイスコンテキストの解放.

				// ビットマップファイル情報のセット.
				bfh.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
				bfh.bfSize = bfh.bfOffBits + bi.bmiHeader.biSizeImage;
				bfh.bfType = 0x4d42;
				bfh.bfReserved1 = 0;
				bfh.bfReserved2 = 0;

				// ファイルに書き込む.
				hFile = CreateFile(_T("test2.bmp"), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFileで"test2.bmp"を作成.
				WriteFile(hFile, &bfh, sizeof(BITMAPFILEHEADER), &dwBytes, NULL);			// WriteFileでbfhを書き込み.
				WriteFile(hFile, &bi, sizeof(BITMAPINFOHEADER), &dwBytes, NULL);			// WriteFileでbiを書き込み.
				WriteFile(hFile, lpBitsPixel, bi.bmiHeader.biSizeImage, &dwBytes, NULL);	// WriteFileでlpBitsPixelを書き込み.
				CloseHandle(hFile);	// 閉じる.

				// メモリの解放.
				delete [] lpBitsPixel;	// lpBitsPixelを解放.

				// hDDBMemDCの削除
				if (hDDBMemDC){	// hDDBMemDCがNULLでない時.
					DeleteDC(hDDBMemDC);	// DeleteDCでhDDBMemDCを削除.
					hDDBMemDC = NULL;		// NULLを代入.
				}

				// hBackMemDCの削除
				if (hBackMemDC){	// hBackMemDCがNULLでない時.
					DeleteDC(hBackMemDC);	// DeleteDCでhBackMemDCを削除.
					hBackMemDC = NULL;		// NULLを代入.
				}

				// DDBのビットマップハンドル削除.
				if (hLoadDDB){	// hLoadDDBがNULLでない時.
					DeleteObject(hLoadDDB);	// DeleteObjectでhLoadDDBを削除.
					hLoadDDB = NULL;	// NULLを代入.
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

				// DDBを描画.
				BitBlt(hBackMemDC, 0, 0, 640, 480, hDDBMemDC, 0, 0, SRCCOPY);	// BitBltでhDDBMemDCをhBackMemDCに描画.
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