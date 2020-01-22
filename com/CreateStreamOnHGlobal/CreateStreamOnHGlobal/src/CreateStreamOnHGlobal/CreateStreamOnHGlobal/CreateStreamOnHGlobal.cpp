// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <string.h>		// C文字列処理
#include <shlwapi.h>	// シェルAPI

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理をするように定義したコールバック関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;		// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;		// ウィンドウメッセージ情報を格納するMSG構造体型変数msg.
	WNDCLASS wc;	// ウィンドウクラス情報をもつWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("CreateStreamOnHGlobal");			// ウィンドウクラス名は"CreateStreamOnHGlobal".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("CreateStreamOnHGlobal"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("CreateStreamOnHGlobal"), _T("CreateStreamOnHGlobal"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"CreateStreamOnHGlobal"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("CreateStreamOnHGlobal"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-casa文でuMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始された時.
		case WM_CREATE:	// ウィンドウの作成が開始された時.(uMsgがWM_CREATEの時.)

			// WM_CREATEブロック
			{

				// 変数の宣言と初期化.
				HANDLE hFile;	// ファイルハンドルhFile
				DWORD dwFileSize;	// ファイルサイズhFileSize
				HGLOBAL hGlobal;	// グローバルハンドルhGlobal
				LPVOID lpBuf;	// バッファポインタlpBuf
				IStream *pStream;	// IStreamポインタpStream
				TCHAR tszPath[MAX_PATH] = {0};	// tszPath(長さMAX_PATH)を{0}で初期化.

				// 画像のパス.				
				GetModuleFileName(NULL, tszPath, MAX_PATH);	// GetModuleFileNameでこの実行ファイルのフルパスを取得.
				PathRemoveFileSpec(tszPath);	// PathRemoveFileSpecでファイル名の部分を取り除く.
				_tcscat(tszPath, _T("\\test.jpg"));	// 上記パスに"\test.txt"を連結.

				// 画像ファイルを開く.
				hFile = CreateFile(tszPath, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);	// "test.jpg"を開く.

				// ファイルサイズを取得.
				dwFileSize = GetFileSize(hFile, NULL);	// GetFileSizeでファイルサイズを取得.

				// メモリ確保.
				hGlobal = GlobalAlloc(GMEM_MOVEABLE, dwFileSize);	// dwFileSize分メモリ確保.

				// ロック.
				lpBuf = GlobalLock(hGlobal);	// ロックしてポインタ取得.

				// 読み込み.
				ReadFile(hFile, lpBuf, dwFileSize, &dwFileSize, NULL);	// ReadFileで読み込み.

				// 閉じる.
				CloseHandle(hFile);	// ファイルハンドルを閉じる.

				// アンロック
				GlobalUnlock(hGlobal);	// アンロック.

				// グローバルメモリからIStreamを作成.
				HRESULT hr = CreateStreamOnHGlobal(hGlobal, TRUE, &pStream);	// CreateStreamOnHGlobalでpStreamにIStreamポインタが格納される.
				if (SUCCEEDED(hr)){

					// ポインタ表示.
					TCHAR tszText[256] = {0};
					_stprintf(tszText, _T("pStream = %08x"), (unsigned int)pStream);	// 文字列変換.
					MessageBox(hwnd, tszText, _T("CreateStreamOnHGlobal"), MB_OK | MB_ICONASTERISK);	// OK表示.

					// 解放.
					pStream->Release();	// IStreamオブジェクトポインタを解放.

				}

				// 解放.
				GlobalFree(hGlobal);	// 解放.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// ウィンドウが破棄された時.
		case WM_DESTROY:	// ウィンドウが破棄された時.(uMsgがWM_DESTROYの時.)

			// WM_DESTROYブロック
			{

				// メッセージループを抜ける.
				PostQuitMessage(0);	// PostQuitMessageで抜ける.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// 画面の描画を要求された時.
		case WM_PAINT:	// 画面の描画を要求された時.(uMsgがWM_PAINTの時.)

			// WM_PAINTブロック
			{

				// このブロックのローカル変数の宣言
				HDC hDC;		// デバイスコンテキストハンドルを格納するHDC型変数hDC.
				PAINTSTRUCT ps;	// ペイント情報を管理するPAINTSTRUCT構造体型の変数ps.

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にはデバイスコンテキストハンドルが返るので, hDCに格納.

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