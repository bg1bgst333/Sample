// ヘッダファイルのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <windowsx.h>	// マクロ
#include <tchar.h>		// TCHAR型

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理ができるように定義するコールバック関数WindowProc.

// 定数の定義
#define TEST_KEY_PATH _T("Software\\Sample\\RegEnumValue")	// このデモで作成する対象のテスト用レジストリキーのパス.
#define VALUE_NAME_1 _T("Value1")	// このデモで設定する1個目の値の名前.
#define VALUE_DATA_1 _T("Apple")	// このデモで設定する1個目の値のデータ.
#define VALUE_NAME_2 _T("Value2")	// このデモで設定する2個目の値の名前.
#define VALUE_DATA_2 _T("Banana")	// このデモで設定する2個目の値のデータ.
#define VALUE_NAME_3 _T("Value3")	// このデモで設定する3個目の値の名前.
#define VALUE_DATA_3 _T("Cherry")	// このデモで設定する3個目の値のデータ.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージを格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラスを格納するWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("RegEnumValue");						// ウィンドウクラス名は"RegEnumValue".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("RegEnumValue"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("RegEnumValue"), _T("RegEnumValue"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 860, 460, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"RegEnumValue"ウィンドウクラスのウィンドウを作成.(結果を複数行表示するため縦に長めのサイズを指定.)
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("RegEnumValue"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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
	static BOOL bDone = FALSE;					// 既に実行済みかどうかを表すstatic変数bDone.(SPACEキーの二重押下対策.)

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-case文でuMsgの値ごとに処理を振り分け.

		// キーが押されたとき.
		case WM_KEYDOWN:	// キーが押されたとき.(uMsgがWM_KEYDOWNの場合.)

			// WM_KEYDOWNブロック
			{

				// SPACEキーが押された場合のみ処理する.
				if (wParam == VK_SPACE && !bDone){	// wParamがVK_SPACEかつ, まだ実行していない場合.

					// このブロックのローカル変数の宣言
					HKEY hKey = NULL;				// RegCreateKey(既存トピック)で作成するキーハンドルを格納するHKEY型変数.
					LONG lRetCreate;				// RegCreateKeyの戻り値を格納するLONG型変数.
					DWORD dwIndex;					// RegEnumValue(本トピックの主役)に渡す列挙インデックスを格納するDWORD型変数.
					TCHAR tszValueName[256];		// RegEnumValueで取得する値の名前を格納するTCHAR型配列.
					DWORD cchValueName;				// tszValueNameのバッファサイズ(文字数)/取得した文字数を格納するDWORD型変数.
					TCHAR tszValueData[256];		// RegEnumValueで取得する値のデータを格納するTCHAR型配列.
					DWORD cbValueData;				// tszValueDataのバッファサイズ(バイト数)/取得したバイト数を格納するDWORD型変数.
					LONG lRetEnum;					// RegEnumValueの戻り値を格納するLONG型変数.
					int iEnumCount;					// 列挙に成功した値の個数を数えるint型変数.
					LONG lRetDelete;				// RegDeleteKey(片付け用の先行利用)の戻り値を格納するLONG型変数.
					TCHAR tszLine[1024];			// 結果文字列を組み立てるTCHAR型配列tszLine.

					// 1段階目: RegCreateKey(既存トピック)でテスト用キーを作成する.
					lRetCreate = RegCreateKey(HKEY_CURRENT_USER, TEST_KEY_PATH, &hKey);	// RegCreateKeyでテスト用キーを作成.

					// 2段階目: RegSetValueEx(既存トピック)で3個の値を設定する.
					RegSetValueEx(hKey, VALUE_NAME_1, 0, REG_SZ, (const BYTE *)VALUE_DATA_1, (lstrlen(VALUE_DATA_1) + 1) * sizeof(TCHAR));	// 1個目の値を設定.
					RegSetValueEx(hKey, VALUE_NAME_2, 0, REG_SZ, (const BYTE *)VALUE_DATA_2, (lstrlen(VALUE_DATA_2) + 1) * sizeof(TCHAR));	// 2個目の値を設定.
					RegSetValueEx(hKey, VALUE_NAME_3, 0, REG_SZ, (const BYTE *)VALUE_DATA_3, (lstrlen(VALUE_DATA_3) + 1) * sizeof(TCHAR));	// 3個目の値を設定.

					// 3段階目: RegEnumValue(本トピックの主役)で, dwIndexを0から1ずつ増やしながらERROR_NO_MORE_ITEMSが返るまで全部の値を列挙する.
					wsprintf(tszLine, _T("1.RegCreateKeyでキーを作成, 2.RegSetValueExで3個の値を設定 -> 完了\r\n3.RegEnumValueで列挙:\r\n"));	// まず1～2段階目のまとめを組み立てる.
					lstrcat(tszResult, tszLine);	// tszResultに追記.
					iEnumCount = 0;	// 列挙カウントを0に初期化.
					for (dwIndex = 0; ; dwIndex++){	// dwIndexを0から1ずつ増やしながらループ.

						// 呼び出すたびにバッファサイズを再初期化する.(MSDN記載の注意事項.)
						cchValueName = sizeof(tszValueName) / sizeof(TCHAR);	// 文字数単位でバッファサイズを設定.
						cbValueData = sizeof(tszValueData);	// バイト数単位でバッファサイズを設定.

						// RegEnumValueでdwIndex番目の値を取得する.
						lRetEnum = RegEnumValue(hKey, dwIndex, tszValueName, &cchValueName, NULL, NULL, (BYTE *)tszValueData, &cbValueData);	// RegEnumValueで列挙.

						// もうこれ以上値が無ければループを抜ける.
						if (lRetEnum == ERROR_NO_MORE_ITEMS){	// ERROR_NO_MORE_ITEMSが返ったとき.

							// ループを抜ける.
							break;	// breakでforループを抜ける.

						}

						// 取得に失敗した場合もループを抜ける.(想定外のエラー.)
						if (lRetEnum != ERROR_SUCCESS){	// ERROR_SUCCESS以外(ERROR_NO_MORE_ITEMS以外)の場合.

							// ループを抜ける.
							break;	// breakでforループを抜ける.

						}

						// 取得できた値を結果に追記する.
						wsprintf(tszLine, _T("  [%d] 名前=\"%s\" データ=\"%s\"\r\n"), dwIndex, tszValueName, tszValueData);	// インデックス・名前・データを組み立てる.
						lstrcat(tszResult, tszLine);	// tszResultに追記.
						iEnumCount++;	// 列挙カウントを1増やす.

					}

					// 列挙結果のまとめを追記する.
					wsprintf(tszLine, _T("  -> 合計%d個の値を列挙し, 最後はERROR_NO_MORE_ITEMSで終了(戻り値=%ld)\r\n"), iEnumCount, lRetEnum);	// まとめを組み立てる.
					lstrcat(tszResult, tszLine);	// tszResultに追記.

					// 4段階目: ハンドルを閉じる.
					RegCloseKey(hKey);	// RegCloseKey(片付け用の先行利用)でハンドルを閉じる.

					// 5段階目: 次回実行時も同じ結果を再現できるように, テスト用キー自体をRegDeleteKey(片付け用の先行利用)で削除しておく.
					lRetDelete = RegDeleteKey(HKEY_CURRENT_USER, TEST_KEY_PATH);	// RegDeleteKey(片付け用の先行利用)でテスト用キーを削除し, レジストリを元の状態に戻す.
					wsprintf(tszLine, _T("4.RegCloseKeyでハンドルを閉じる -> 完了\r\n5.片付け用にRegDeleteKeyで削除 -> %s\r\n"), lRetDelete == ERROR_SUCCESS ? _T("成功") : _T("失敗"));	// 4～5段階目のまとめを組み立てる.
					lstrcat(tszResult, tszLine);	// tszResultに追記.

					// 実行済みフラグを立てる.(以降のSPACEキーは無視.)
					bDone = TRUE;	// bDoneをTRUEにする.

					// 表示を更新するため再描画要求.
					InvalidateRect(hwnd, NULL, TRUE);	// InvalidateRectで再描画要求.

				}

			}

			// 次の処理へ続く.
			break;	// breakで抜けて, 次の処理(DefWindowProc)へ続く.

		// ウィンドウが破棄されたとき.
		case WM_DESTROY:	// ウィンドウが破棄されたとき.(uMsgがWM_DESTROYの場合.)

			// WM_DESTROYブロック
			{

				// メッセージループを抜ける.
				PostQuitMessage(0);	// PostQuitMessageで抜ける.

			}

			// 次の処理へ続く.
			break;	// breakで抜けて, 次の処理(DefWindowProc)へ続く.

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
				InflateRect(&rcText, -20, -20);	// InflateRectで少し内側に余白をとる.(既存トピックのInflateRectを流用.)
				wsprintf(tszAll, _T("SPACEキーを押すと, テスト用キーに3個の値を設定してから, RegEnumValueでdwIndexを0から1ずつ増やしながら全部の値を列挙する, という一連の流れを実演します。\r\n\r\n%s"), tszResult);	// 案内文にtszResultを連結.
				DrawText(hDC, tszAll, -1, &rcText, DT_LEFT | DT_TOP | DT_WORDBREAK);	// DrawTextで折り返しながら表示.

				// ウィンドウの描画終了
				EndPaint(hwnd, &ps);	// EndPaintでこのウィンドウの描画処理を終了させる.

			}

			// 次の処理へ続く.
			break;	// breakで抜けて, 次の処理(DefWindowProc)へ続く.

		// それ以外の場合.
		default:

			// 次の処理へ続く.
			break;	// breakで抜けて, 次の処理(DefWindowProc)へ続く.

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}
