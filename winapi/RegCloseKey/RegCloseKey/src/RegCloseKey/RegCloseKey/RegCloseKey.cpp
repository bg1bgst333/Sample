// ヘッダファイルのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <windowsx.h>	// マクロ
#include <tchar.h>		// TCHAR型

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理ができるように定義するコールバック関数WindowProc.

// 定数の定義
#define TEST_KEY_PATH _T("Software\\Sample\\RegCloseKey")	// このデモで作成するテスト用レジストリキーのパス.
#define VALUE_NAME _T("Value1")	// このデモで設定する値の名前.
#define VALUE_DATA _T("Hello")	// このデモで設定する値のデータ.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージを格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラスを格納するWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("RegCloseKey");						// ウィンドウクラス名を"RegCloseKey".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("RegCloseKey"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("RegCloseKey"), _T("RegCloseKey"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 860, 460, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"RegCloseKey"ウィンドウクラスのウィンドウを作成.(結果を複数行表示するため縦に長めのサイズを指定.)
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("RegCloseKey"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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
					HKEY hKey = NULL;			// RegCreateKey(先行使用)で作成するキーハンドルを格納するHKEY型変数.
					LONG lRetCreate;			// RegCreateKeyの戻り値を格納するLONG型変数.
					LONG lRetSetBeforeClose;	// クローズ前, 開いているhKeyに対するRegSetValueEx(先行使用)の戻り値を格納するLONG型変数.(成功するはず.)
					LONG lRetClose;				// 1回目(開いているハンドルに対する, 成功するはず)のRegCloseKeyの戻り値を格納するLONG型変数.
					LONG lRetSetAfterClose;		// クローズ後, 同じhKeyに対してRegSetValueEx(先行使用)を呼んだ戻り値を格納するLONG型変数.(失敗するはず.)
					HKEY hKeyReopen = NULL;		// 再度RegOpenKeyEx(先行使用)で開き直すキーハンドルを格納するHKEY型変数.
					LONG lRetReopen;			// 再オープンのRegOpenKeyExの戻り値を格納するLONG型変数.(成功するはず, データ自体は無事なことの確認.)
					LONG lRetDeleteKey;			// 後片付け用のRegDeleteKey(先行使用)の戻り値を格納するLONG型変数.
					TCHAR tszLine[1024];		// 結果文字列を組み立てるTCHAR型配列tszLine.

					// 1段階目: RegCreateKey(先行使用)でテスト用キーを作成する.
					lRetCreate = RegCreateKey(HKEY_CURRENT_USER, TEST_KEY_PATH, &hKey);	// RegCreateKeyでテスト用キーを作成.

					// 2段階目: RegSetValueEx(先行使用)でクローズ前のhKeyに値を設定できることを確認する.(成功するはず.)
					lRetSetBeforeClose = RegSetValueEx(hKey, VALUE_NAME, 0, REG_SZ, (const BYTE *)VALUE_DATA, (lstrlen(VALUE_DATA) + 1) * sizeof(TCHAR));	// RegSetValueExでクローズ前に値を設定.

					// 3段階目: RegCloseKey(本トピックの主役)でhKeyを閉じる.(成功するはず.)
					lRetClose = RegCloseKey(hKey);	// RegCloseKeyでhKeyを閉じる.

					// 4段階目: RegSetValueEx(先行使用)で, クローズ済みの(もう無効な)hKeyに対して値を設定しようとする.(失敗するはず.)
					lRetSetAfterClose = RegSetValueEx(hKey, VALUE_NAME, 0, REG_SZ, (const BYTE *)VALUE_DATA, (lstrlen(VALUE_DATA) + 1) * sizeof(TCHAR));	// クローズ済みのhKeyに対するRegSetValueEx.

					// 5段階目: RegOpenKeyEx(先行使用)で改めて開き直し, キー自体(とデータ)が無事に残っていることを確認する.(成功するはず.)
					lRetReopen = RegOpenKeyEx(HKEY_CURRENT_USER, TEST_KEY_PATH, 0, KEY_READ, &hKeyReopen);	// RegOpenKeyExで開き直す.
					if (lRetReopen == ERROR_SUCCESS){	// 開けた場合.

						// ハンドルを閉じる.
						RegCloseKey(hKeyReopen);	// RegCloseKeyでハンドルを閉じる.

					}

					// 6段階目: 後片付けとしてRegDeleteKey(先行使用)でテスト用キーごと削除する.
					lRetDeleteKey = RegDeleteKey(HKEY_CURRENT_USER, TEST_KEY_PATH);	// RegDeleteKeyでテスト用キーを削除.

					// 6段階の結果をまとめて組み立てる.
					wsprintf(tszLine, _T("1.RegCreateKeyでキーを作成 -> 完了\r\n2.クローズ前のRegSetValueEx -> %s\r\n3.RegCloseKeyでhKeyを閉じる -> %s\r\n4.クローズ済みhKeyへのRegSetValueEx -> %s(戻り値=%ld, ERROR_INVALID_HANDLEのはず)\r\n5.RegOpenKeyExで開き直し -> %s(データ自体は無事なはず)\r\n6.後片付けのRegDeleteKey -> %s\r\n"),
						lRetSetBeforeClose == ERROR_SUCCESS ? _T("成功") : _T("失敗"),
						lRetClose == ERROR_SUCCESS ? _T("成功") : _T("失敗"),
						lRetSetAfterClose == ERROR_SUCCESS ? _T("成功") : _T("失敗(正常)"), lRetSetAfterClose,
						lRetReopen == ERROR_SUCCESS ? _T("成功") : _T("失敗"),
						lRetDeleteKey == ERROR_SUCCESS ? _T("成功") : _T("失敗"));	// wsprintfで6段階をまとめて組み立てる.

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
				wsprintf(tszAll, _T("SPACEキーを押すと, テスト用キーを作成してから, RegCloseKeyでハンドルを閉じ, 閉じた後のハンドルが本当に使えなくなるか, キー自体は無事に残るかを確認します。\r\n\r\n%s"), tszResult);	// 案内文にtszResultを連結.
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
