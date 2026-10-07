// ヘッダファイルのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <windowsx.h>	// マクロ
#include <tchar.h>		// TCHAR型

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理ができるように定義するコールバック関数WindowProc.

// 定数の定義
#define TEST_FILE_PATH _T("C:\\Temp\\GetFileAttributesTest.txt")	// このデモで作成するテスト用ファイルのパス.
#define TEST_FILE_CONTENT _T("Hello, GetFileAttributes!")	// テスト用ファイルに書き込む内容.
#define MISSING_FILE_PATH _T("C:\\Temp\\NoSuchGetFileAttributesFile.txt")	// わざと存在しない状態で試すファイルのパス.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージを格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラスを格納するWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("GetFileAttributes");						// ウィンドウクラス名を"GetFileAttributes".
	wc.style = CS_HREDRAW | CS_VREDRAW;							// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;								// ウィンドウプロシージャは独自の処理を定義するWindowProc.
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("GetFileAttributes"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("GetFileAttributes"), _T("GetFileAttributes"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 860, 460, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"GetFileAttributes"ウィンドウクラスのウィンドウを作成.(結果を複数行表示するため縦に長めのサイズを指定.)
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("GetFileAttributes"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.

	// メッセージループ
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessageでメッセージを取得し, 戻り値が0より大きい間はループを続ける.

		// ウィンドウメッセージの送出
		DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(今回の場合は独自に定義するWindowProc)に送出.
		TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.

	}

	// プログラムの終了
	return (int)msg.wParam;	// 終了コード(msg.wParam)を戻り値として返す.

}

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// ウィンドウメッセージに対して独自の処理ができるように定義するウィンドウプロシージャ.

	// static変数の宣言
	static TCHAR tszResult[2048] = _T("");		// これまでの結果を積み上げて表示するstatic変数tszResult.
	static BOOL bDone = FALSE;					// 既に実行済みかどうかを表すstatic変数bDone.(SPACEキーの二重実行対策.)

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-case文でuMsgの値ごとに処理を振り分ける.

		// キーが押されたとき.
		case WM_KEYDOWN:	// キーが押されたとき.(uMsgがWM_KEYDOWNの場合.)

			// WM_KEYDOWNブロック
			{

				// SPACEキーが押された場合のみ処理する.
				if (wParam == VK_SPACE && !bDone){	// wParamがVK_SPACEかつ, まだ実行していない場合.

					// このブロックのローカル変数の宣言
					HANDLE hFile;				// CreateFile(先行使用)で作成するテスト用ファイルのハンドルを格納するHANDLE型変数.
					DWORD dwWritten;			// WriteFile(先行使用)で実際に書き込んだバイト数を格納するDWORD型変数.
					DWORD dwAttrExisting;		// 実際に存在するファイルに対するGetFileAttributesの戻り値を格納するDWORD型変数.(成功するはず.)
					DWORD dwAttrMissing;		// わざと存在しないファイルに対するGetFileAttributesの戻り値を格納するDWORD型変数.(失敗するはず.)
					DWORD dwErrMissing;			// 2回目のGetFileAttributes直後のGetLastError(先行使用)の値を格納するDWORD型変数.
					TCHAR tszLine[1024];		// 結果文字列を組み立てるTCHAR型配列tszLine.

					// 1段階目: CreateFile/WriteFile/CloseHandle(いずれも先行使用)でテスト用ファイルを作成する.
					hFile = CreateFile(TEST_FILE_PATH, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFileでテスト用ファイルを新規作成.
					WriteFile(hFile, TEST_FILE_CONTENT, lstrlen(TEST_FILE_CONTENT) * sizeof(TCHAR), &dwWritten, NULL);	// WriteFileで内容を書き込む.
					CloseHandle(hFile);	// CloseHandleでハンドルを閉じる.

					// 2段階目: GetFileAttributes(本トピックの主役)で, 実際に存在するファイルの属性を取得する.(成功するはず.)
					dwAttrExisting = GetFileAttributes(TEST_FILE_PATH);	// GetFileAttributesでTEST_FILE_PATHの属性を取得.

					// 3段階目: GetFileAttributes(本トピックの主役)で, わざと存在しないファイルの属性を取得しようとする.(失敗するはず.)
					dwAttrMissing = GetFileAttributes(MISSING_FILE_PATH);	// 存在しないMISSING_FILE_PATHの属性を取得しようとする.
					dwErrMissing = GetLastError();	// GetLastError(先行使用)で直後のエラーコードを取得.(ERROR_FILE_NOT_FOUNDのはず.)

					// 3段階の結果をまとめて組み立てる.
					wsprintf(tszLine, _T("1.テスト用ファイルをCreateFile/WriteFile/CloseHandleで作成 -> 完了\r\n2.実際に存在するファイルのGetFileAttributes -> %s(属性値=0x%08lX, FILE_ATTRIBUTE_ARCHIVEビット=%s)\r\n3.存在しないファイルのGetFileAttributes -> %s(戻り値=INVALID_FILE_ATTRIBUTES, GetLastError=%lu, ERROR_FILE_NOT_FOUNDのはず)\r\n"),
						dwAttrExisting != INVALID_FILE_ATTRIBUTES ? _T("成功") : _T("失敗"), dwAttrExisting,
						(dwAttrExisting & FILE_ATTRIBUTE_ARCHIVE) ? _T("あり") : _T("なし"),
						dwAttrMissing == INVALID_FILE_ATTRIBUTES ? _T("失敗(正常)") : _T("成功"), dwErrMissing);	// wsprintfで3段階をまとめて組み立てる.

					// 実行済みフラグを立てる.(以降はSPACEキーは無視.)
					bDone = TRUE;	// bDoneをTRUEにする.

					// 組み立てた結果をこれまでの結果に追記する.
					lstrcat(tszResult, tszLine);	// lstrcatでtszResultの末尾にtszLineを連結.

					// 表示を更新するため再描画要求.
					InvalidateRect(hwnd, NULL, TRUE);	// InvalidateRectで再描画要求.

				}

			}

			// 既定の処理へ続く.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ続く.

		// ウィンドウが破棄されたとき.
		case WM_DESTROY:	// ウィンドウが破棄されたとき.(uMsgがWM_DESTROYの場合.)

			// WM_DESTROYブロック
			{

				// メッセージループを抜ける.
				PostQuitMessage(0);	// PostQuitMessageで抜ける.

			}

			// 既定の処理へ続く.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ続く.

		// 画面の描画が求められたとき.
		case WM_PAINT:		// 画面の描画が求められたとき.(uMsgがWM_PAINTの場合.)

			// WM_PAINTブロック
			{

				// このブロックのローカル変数の宣言
				HDC hDC;			// デバイスコンテキストハンドルを格納するHDC型変数hDC.
				PAINTSTRUCT ps;		// ペイント情報を管理するPAINTSTRUCT構造体型の変数ps.
				RECT rcClient;		// クライアント領域を格納するRECT型変数rcClient.
				RECT rcText;		// 描画領域を格納するRECT型変数rcText.
				TCHAR tszAll[2304];	// 案内文+結果をまとめて表示するためのTCHAR型配列tszAll.

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にはデバイスコンテキストハンドルが返るので, hDCに格納.

				// 案内文とこれまでの結果を表示する.
				GetClientRect(hwnd, &rcClient);	// GetClientRectでクライアント領域のサイズを取得.
				rcText = rcClient;					// rcTextにrcClientをコピー.
				InflateRect(&rcText, -20, -20);	// InflateRectで少し内側に余白をとる.(先行使用のInflateRectを流用.)
				wsprintf(tszAll, _T("SPACEキーを押すと, テスト用ファイルを作成してから, GetFileAttributesで属性を取得します。実際に存在する場合と, 存在しない場合とで結果がどう変わるかを確認します。\r\n\r\n%s"), tszResult);	// 案内文にtszResultを連結.
				DrawText(hDC, tszAll, -1, &rcText, DT_LEFT | DT_TOP | DT_WORDBREAK);	// DrawTextで折り返しながら表示.

				// ウィンドウの描画終了
				EndPaint(hwnd, &ps);	// EndPaintでこのウィンドウの描画処理を終了させる.

			}

			// 既定の処理へ続く.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ続く.

		// それ以外の場合.
		default:

			// 既定の処理へ続く.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ続く.

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}
