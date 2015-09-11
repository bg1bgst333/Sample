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
	wc.lpszClassName = _T("CreateDIBSection");				// ウィンドウクラス名は"CreateDIBSection".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("CreateDIBSection"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("CreateDIBSection"), _T("CreateDIBSection"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"CreateDIBSection"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("CreateDIBSection"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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
	static LPBYTE lpBitsPixel;		// DIBセクションのピクセルビット列lpBitsPixel.
	static HBITMAP hDIBSection;		// DIBセクションのビットマップハンドルhDIBSection.
	static HDC hBackMemDC;			// hBackBitmap用のデバイスコンテキストhBackMemDC.
	static HDC hDIBSectionMemDC;	// hDIBSection用のデバイスコンテキストhDIBSectionMemDC.
	static HBITMAP hOldBackBitmap;	// 選択前のバックバッファビットマップhOldBackBitmap.
	static HBITMAP hOldDIBSection;	// DIBセクションを選択する前のビットマップhOldDIBSection.
	static BITMAPINFO bi;			// BITMAPINFO構造体変数bi.
	static BITMAPFILEHEADER bfh;	// BITMAPFILEHEADER構造体変数bfh.

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

				// DIBセクションの作成.
				hDIBSection = CreateDIBSection(hDC, &bi, DIB_RGB_COLORS, (void **)&lpBitsPixel, NULL, 0);	// CreateDIBSectionでDIBセクションを作成.

				// ピクセル列の読み込み.
				ReadFile(hFile, lpBitsPixel, dwSize - bfh.bfOffBits, &dwReadBytes, NULL);	// ReadFileでピクセル列を読み込む.

				// hBackBitmap用のメモリデバイスコンテキストを作成.
				hBackMemDC = CreateCompatibleDC(hDC);		// CreateCompatibleDCでhBackBitmap用のメモリデバイスコンテキストを作成.

				// hDIBSection用のメモリデバイスコンテキストを作成.
				hDIBSectionMemDC = CreateCompatibleDC(hDC);	// CreateCompatibleDCでhDIBSection用のメモリデバイスコンテキストを作成.

				// バックバッファビットマップの選択.
				hOldBackBitmap = (HBITMAP)SelectObject(hBackMemDC, hBackBitmap);		// SelectObjectでhBackBitmapを選択.

				// DIBセクションの選択.
				hOldDIBSection = (HBITMAP)SelectObject(hDIBSectionMemDC, hDIBSection);	// SelectObjectでhDIBSectionを選択.

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

				// ローカル変数の宣言.
				HANDLE hFile;			// ファイルハンドルhFile.
				DWORD dwBytes;			// 書き込みバイト数.

				// 元に戻す.
				SelectObject(hDIBSectionMemDC, hOldDIBSection);	// SelectObjectでhOldDIBSectionに戻す.

				// 元に戻す.
				SelectObject(hBackMemDC, hOldBackBitmap);	// SelectObjectでhOldBackBitmapに戻す.

				// ファイルに書き込む.
				hFile = CreateFile(_T("test2.bmp"), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFileで"test2.bmp"を作成.
				WriteFile(hFile, &bfh, sizeof(BITMAPFILEHEADER), &dwBytes, NULL);			// WriteFileでbfhを書き込み.
				WriteFile(hFile, &bi, sizeof(BITMAPINFOHEADER), &dwBytes, NULL);			// WriteFileでbiを書き込み.
				WriteFile(hFile, lpBitsPixel, bi.bmiHeader.biSizeImage, &dwBytes, NULL);	// WriteFileでlpBitsPixelを書き込み.
				CloseHandle(hFile);	// 閉じる.

				// hDIBSectionMemDCの削除
				if (hDIBSectionMemDC){	// hDIBSectionMemDCがNULLでない時.
					DeleteDC(hDIBSectionMemDC);	// DeleteDCでhDIBSectionMemDCを削除.
					hDIBSectionMemDC = NULL;	// NULLを代入.
				}

				// hBackMemDCの削除
				if (hBackMemDC){	// hBackMemDCがNULLでない時.
					DeleteDC(hBackMemDC);	// DeleteDCでhBackMemDCを削除.
					hBackMemDC = NULL;		// NULLを代入.
				}

				// DIBセクションの削除.
				if (hDIBSection){	// hDIBSectionがNULLでない時.
					DeleteObject(hDIBSection);	// DeleteObjectでhDIBSectionを削除.
					hDIBSection = NULL;	// NULLを代入.
				}

				// ピクセル列はDIBセクションの削除時に自動で解放.
				lpBitsPixel = NULL;	// NULLは代入しておく.

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

				// DIBセクションの描画.
				BitBlt(hBackMemDC, 0, 0, bi.bmiHeader.biWidth, bi.bmiHeader.biHeight, hDIBSectionMemDC, 0, 0, SRCCOPY);	// BitBltでhDIBSectionMemDCをhBackMemDCに描画.
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