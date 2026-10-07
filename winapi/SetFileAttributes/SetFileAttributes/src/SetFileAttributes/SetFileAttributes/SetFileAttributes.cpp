// ヘッダファイルのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <windowsx.h>	// マクロ
#include <tchar.h>		// TCHAR型

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理ができるように定義するコールバック関数WindowProc.

// 定数の定義
#define TEST_FILE_PATH _T("C:\\Temp\\SetFileAttributesTest.txt")	// このデモで作成するテスト用ファイルのパス.
#define TEST_FILE_CONTENT _T("Hello, SetFileAttributes!")	// テスト用ファイルに書き込む内容.
#define MISSING_FILE_PATH _T("C:\\Temp\\NoSuchSetFileAttributesFile.txt")	// わざと存在しない状態で試すファイルのパス.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージを格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラスを格納するWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("SetFileAttributes");						// ウィンドウクラス名を"SetFileAttributes".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("SetFileAttributes"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("SetFileAttributes"), _T("SetFileAttributes"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 860, 460, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"SetFileAttributes"ウィンドウクラスのウィンドウを作成.(結果を複数行表示するため縦に長めのサイズを指定.)
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("SetFileAttributes"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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
					DWORD dwAttrBefore;			// SetFileAttributes前のGetFileAttributes(先行使用)の戻り値を格納するDWORD型変数.
					BOOL bSetReadOnly;			// 1回目(実際に存在する, 成功するはず)のSetFileAttributesの戻り値を格納するBOOL型変数.
					DWORD dwAttrAfter;			// SetFileAttributes後のGetFileAttributes(先行使用)の戻り値を格納するDWORD型変数.
					BOOL bSetMissing;			// 2回目(わざと存在しないファイルに対する, 失敗するはず)のSetFileAttributesの戻り値を格納するBOOL型変数.
					DWORD dwErrMissing;			// 2回目のSetFileAttributes直後のGetLastError(先行使用)の値を格納するDWORD型変数.
					TCHAR tszLine[1024];		// 結果文字列を組み立てるTCHAR型配列tszLine.

					// 1段階目: CreateFile/WriteFile/CloseHandle(いずれも先行使用)でテスト用ファイルを作成する.
					hFile = CreateFile(TEST_FILE_PATH, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFileでテスト用ファイルを新規作成.
					WriteFile(hFile, TEST_FILE_CONTENT, lstrlen(TEST_FILE_CONTENT) * sizeof(TCHAR), &dwWritten, NULL);	// WriteFileで内容を書き込む.
					CloseHandle(hFile);	// CloseHandleでハンドルを閉じる.

					// 2段階目: GetFileAttributes(先行使用)で変更前の属性を取得する.
					dwAttrBefore = GetFileAttributes(TEST_FILE_PATH);	// GetFileAttributesで変更前の属性を取得.

					// 3段階目: SetFileAttributes(本トピックの主役)で読み取り専用属性を設定する.(成功するはず.)
					bSetReadOnly = SetFileAttributes(TEST_FILE_PATH, FILE_ATTRIBUTE_READONLY);	// SetFileAttributesでFILE_ATTRIBUTE_READONLYを設定.

					// 4段階目: GetFileAttributes(先行使用)で変更後の属性を取得し, 実際に反映されたか確認する.
					dwAttrAfter = GetFileAttributes(TEST_FILE_PATH);	// GetFileAttributesで変更後の属性を取得.

					// 5段階目: SetFileAttributes(本トピックの主役)で, わざと存在しないファイルに属性を設定しようとする.(失敗するはず.)
					bSetMissing = SetFileAttributes(MISSING_FILE_PATH, FILE_ATTRIBUTE_NORMAL);	// 存在しないMISSING_FILE_PATHに属性設定を試みる.
					dwErrMissing = GetLastError();	// GetLastError(先行使用)で直後のエラーコードを取得.(ERROR_FILE_NOT_FOUNDのはず.)

					// 6段階目: 後片付けとして読み取り専用を解除してからDeleteFile(先行使用)で削除する.(読み取り専用のままだと削除に失敗するため.)
					SetFileAttributes(TEST_FILE_PATH, FILE_ATTRIBUTE_NORMAL);	// SetFileAttributesで読み取り専用を解除.
					DeleteFile(TEST_FILE_PATH);	// DeleteFile(先行使用)でテスト用ファイルを削除.

					// 5段階の結果をまとめて組み立てる.
					wsprintf(tszLine, _T("1.テスト用ファイルをCreateFile/WriteFile/CloseHandleで作成 -> 完了\r\n2.変更前の属性(GetFileAttributes) -> 0x%08lX(READONLYビット=%s)\r\n3.SetFileAttributesでFILE_ATTRIBUTE_READONLYを設定 -> %s\r\n4.変更後の属性(GetFileAttributes) -> 0x%08lX(READONLYビット=%s)\r\n5.存在しないファイルへのSetFileAttributes -> %s(GetLastError=%lu, ERROR_FILE_NOT_FOUNDのはず)\r\n"),
						dwAttrBefore, (dwAttrBefore & FILE_ATTRIBUTE_READONLY) ? _T("あり") : _T("なし"),
						bSetReadOnly ? _T("成功") : _T("失敗"),
						dwAttrAfter, (dwAttrAfter & FILE_ATTRIBUTE_READONLY) ? _T("あり") : _T("なし"),
						bSetMissing ? _T("成功") : _T("失敗(正常)"), dwErrMissing);	// wsprintfで5段階をまとめて組み立てる.

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
				wsprintf(tszAll, _T("SPACEキーを押すと, テスト用ファイルを作成してから, SetFileAttributesで読み取り専用属性を設定します。属性が実際に変わるかと, 存在しないファイルに設定しようとした場合の結果を確認します。\r\n\r\n%s"), tszResult);	// 案内文にtszResultを連結.
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
