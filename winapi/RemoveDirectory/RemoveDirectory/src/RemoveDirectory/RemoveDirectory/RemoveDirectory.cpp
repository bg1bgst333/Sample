// ヘッダファイルのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <windowsx.h>	// マクロ
#include <tchar.h>		// TCHAR型

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理ができるように定義するコールバック関数WindowProc.

// 定数の定義
#define TEST_DIR_PATH _T("C:\\Temp\\RemoveDirectoryTest")	// このデモで作成・削除するテスト用ディレクトリのパス.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージを格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラスを格納するWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("RemoveDirectory");						// ウィンドウクラス名を"RemoveDirectory".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("RemoveDirectory"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("RemoveDirectory"), _T("RemoveDirectory"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 860, 460, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"RemoveDirectory"ウィンドウクラスのウィンドウを作成.(結果を複数行表示するため縦に長めのサイズを指定.)
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("RemoveDirectory"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)

	}

	// ウィンドウ表示前にテスト用ディレクトリを作成しておく.(SPACEキーを押す前の状態でも, エクスプローラで実際に存在することを確認できるようにするため.)
	CreateDirectory(TEST_DIR_PATH, NULL);	// CreateDirectory(既存)でテスト用ディレクトリを作成.

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
					BOOL bRemoveFirst;			// 1回目(実際に存在する, 成功するはず)のRemoveDirectoryの戻り値を格納するBOOL型変数.
					BOOL bRemoveSecond;			// 2回目(1回目で既に削除済みのため, 失敗するはず)のRemoveDirectoryの戻り値を格納するBOOL型変数.
					DWORD dwErrSecond;			// 2回目のRemoveDirectory直後のGetLastError(先行使用)の値を格納するDWORD型変数.
					TCHAR tszLine[1024];		// 結果文字列を組み立てるTCHAR型配列tszLine.

					// 1段階目: RemoveDirectory(本トピックの主役)で, 実際に存在する(中身が空の)テスト用ディレクトリを削除する.(成功するはず.)
					bRemoveFirst = RemoveDirectory(TEST_DIR_PATH);	// RemoveDirectoryでTEST_DIR_PATHを削除.

					// 2段階目: RemoveDirectory(本トピックの主役)で, わざと(1回目で既に削除済みで)もう存在しないディレクトリを再度削除しようとする.(失敗するはず.)
					bRemoveSecond = RemoveDirectory(TEST_DIR_PATH);	// もう存在しないTEST_DIR_PATHを再度削除しようとする.
					dwErrSecond = GetLastError();	// GetLastError(先行使用)で直後のエラーコードを取得.(ERROR_PATH_NOT_FOUNDのはず.)

					// 2段階の結果をまとめて組み立てる.
					wsprintf(tszLine, _T("1.実際に存在するテスト用ディレクトリをRemoveDirectoryで削除 -> %s\r\n2.既に削除済みの(もう無い)ディレクトリを再度RemoveDirectory -> %s(GetLastError=%lu, ERROR_PATH_NOT_FOUNDのはず)\r\n"),
						bRemoveFirst ? _T("成功") : _T("失敗"),
						bRemoveSecond ? _T("成功") : _T("失敗(正常)"), dwErrSecond);	// wsprintfで2段階をまとめて組み立てる.

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
				wsprintf(tszAll, _T("起動時にC:\\Temp\\RemoveDirectoryTestを作成済みです。SPACEキーを押すと, RemoveDirectoryでそのディレクトリを削除します。実際に存在する場合と, 既に削除済みでもう無い場合とで結果がどう変わるかを確認します。\r\n\r\n%s"), tszResult);	// 案内文にtszResultを連結.
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
