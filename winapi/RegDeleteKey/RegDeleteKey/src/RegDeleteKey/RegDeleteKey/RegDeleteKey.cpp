// ヘッダファイルのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <windowsx.h>	// マクロ
#include <tchar.h>		// TCHAR型

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理ができるように定義するコールバック関数WindowProc.

// 定数の定義
#define TEST_KEY_PATH _T("Software\\Sample\\RegDeleteKey")	// このデモで作成・削除対象のテスト用レジストリキーのパス.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージを格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラスを格納するWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("RegDeleteKey");						// ウィンドウクラス名を"RegDeleteKey".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("RegDeleteKey"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("RegDeleteKey"), _T("RegDeleteKey"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 860, 460, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"RegDeleteKey"ウィンドウクラスのウィンドウを作成.(結果を複数行表示するため縦に長めのサイズを指定.)
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("RegDeleteKey"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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
					HKEY hKey = NULL;				// RegCreateKey(先行使用)で作成するキーハンドルを格納するHKEY型変数.
					LONG lRetCreate;				// RegCreateKeyの戻り値を格納するLONG型変数.
					HKEY hKeyCheckBefore = NULL;	// 削除前の確認用にRegOpenKeyEx(先行使用)で開くキーハンドルを格納するHKEY型変数.
					LONG lRetOpenBefore;			// 削除前のRegOpenKeyExの戻り値を格納するLONG型変数.(成功するはず.)
					LONG lRetDeleteOK;				// 1回目(存在するキーに対する, 成功するはず)のRegDeleteKeyの戻り値を格納するLONG型変数.
					HKEY hKeyCheckAfter = NULL;	// 削除後の確認用にRegOpenKeyEx(先行使用)で開くキーハンドルを格納するHKEY型変数.
					LONG lRetOpenAfter;			// 削除後のRegOpenKeyExの戻り値を格納するLONG型変数.(失敗するはず.)
					LONG lRetDeleteMissing;		// 2回目(わざと存在しないキーに対する, 失敗するはず)のRegDeleteKeyの戻り値を格納するLONG型変数.
					TCHAR tszLine[1024];			// 結果文字列を組み立てるTCHAR型配列tszLine.

					// 1段階目: RegCreateKey(先行使用)でテスト用キーを作成する.
					lRetCreate = RegCreateKey(HKEY_CURRENT_USER, TEST_KEY_PATH, &hKey);	// RegCreateKeyでテスト用キーを作成.

					// 2段階目: RegCloseKey(先行使用)でハンドルを閉じる.
					RegCloseKey(hKey);	// RegCloseKey(先行使用)でハンドルを閉じる.

					// 3段階目: RegOpenKeyEx(先行使用)で削除前にキーが存在することを確認する.(成功するはず.)
					lRetOpenBefore = RegOpenKeyEx(HKEY_CURRENT_USER, TEST_KEY_PATH, 0, KEY_READ, &hKeyCheckBefore);	// RegOpenKeyExで削除前の存在確認.
					if (lRetOpenBefore == ERROR_SUCCESS){	// 開けた場合.

						// ハンドルを閉じる.
						RegCloseKey(hKeyCheckBefore);	// RegCloseKey(先行使用)でハンドルを閉じる.

					}

					// 4段階目: RegDeleteKey(本トピックの主役)でTEST_KEY_PATHを削除する.(成功するはず.)
					lRetDeleteOK = RegDeleteKey(HKEY_CURRENT_USER, TEST_KEY_PATH);	// RegDeleteKeyでTEST_KEY_PATHを削除.

					// 5段階目: RegOpenKeyEx(先行使用)で削除後にキーが無くなったことを確認する.(失敗するはず.)
					lRetOpenAfter = RegOpenKeyEx(HKEY_CURRENT_USER, TEST_KEY_PATH, 0, KEY_READ, &hKeyCheckAfter);	// RegOpenKeyExで削除後の存在確認.
					if (lRetOpenAfter == ERROR_SUCCESS){	// 万一開けてしまった場合(本来は無いはず).

						// ハンドルを閉じる.
						RegCloseKey(hKeyCheckAfter);	// RegCloseKey(先行使用)でハンドルを閉じる.

					}

					// 6段階目: RegDeleteKey(本トピックの主役)で, わざと既に削除済みのキーを再度削除しようとする.(失敗するはず.)
					lRetDeleteMissing = RegDeleteKey(HKEY_CURRENT_USER, TEST_KEY_PATH);	// 既に存在しないTEST_KEY_PATHを再度削除しようとし, ERROR_FILE_NOT_FOUND(2)が返るはず.

					// 6段階の結果をまとめて組み立てる.
					wsprintf(tszLine, _T("1.RegCreateKeyでキーを作成, 2.RegCloseKeyでハンドルを閉じる -> 完了\r\n3.削除前のRegOpenKeyExでの存在確認 -> %s\r\n4.RegDeleteKeyで削除 -> %s\r\n5.削除後のRegOpenKeyExでの存在確認 -> %s(開けたらNG)\r\n6.削除済みキーへのRegDeleteKey -> %s(戻り値=%ld, ERROR_FILE_NOT_FOUNDのはず)\r\n"),
						lRetOpenBefore == ERROR_SUCCESS ? _T("成功(存在する)") : _T("失敗"),
						lRetDeleteOK == ERROR_SUCCESS ? _T("成功") : _T("失敗"),
						lRetOpenAfter == ERROR_SUCCESS ? _T("成功(存在する)") : _T("失敗(存在しない, 正常)"),
						lRetDeleteMissing == ERROR_SUCCESS ? _T("成功") : _T("失敗(正常)"), lRetDeleteMissing);	// wsprintfで6段階をまとめて組み立てる.

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
				wsprintf(tszAll, _T("SPACEキーを押すと, テスト用キーを作成してから, RegDeleteKeyで削除し, 削除前後でキーの有無がどう変わるか, さらに既に削除済みのキーを再削除しようとした結果も確認します。\r\n\r\n%s"), tszResult);	// 案内文にtszResultを連結.
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
