// ヘッダファイルのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <windowsx.h>	// マクロ
#include <tchar.h>		// TCHAR型

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理ができるように定義するコールバック関数WindowProc.

// 定数の定義
#define TEST_KEY_PATH _T("Software\\Sample\\RegQueryValueEx")	// このデモで作成する対象のテスト用レジストリキーのパス.
#define TEST_VALUE_NAME _T("TestValue")	// このデモで設定/取得する対象のテスト用の値の名前.
#define TEST_VALUE_DATA _T("Hello,RegQueryValueEx!")	// このデモで設定する対象のテスト用の値のデータ.
#define MISSING_VALUE_NAME _T("NoSuchValue")	// このデモでわざと取得に失敗させる対象の, 存在しない値の名前.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージを格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラスを格納するWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("RegQueryValueEx");						// ウィンドウクラス名は"RegQueryValueEx".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("RegQueryValueEx"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("RegQueryValueEx"), _T("RegQueryValueEx"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 860, 460, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"RegQueryValueEx"ウィンドウクラスのウィンドウを作成.(結果を複数行表示するため縦に長めのサイズを指定.)
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("RegQueryValueEx"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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
					HKEY hKey = NULL;					// RegCreateKey(既存トピック)で作成するキーハンドルを格納するHKEY型変数.
					LONG lRetCreate;					// RegCreateKeyの戻り値を格納するLONG型変数.
					LONG lRetSet;						// RegSetValueEx(既存トピック)の戻り値を格納するLONG型変数.
					TCHAR tszReadBuf[256] = _T("");	// RegQueryValueEx(本トピックの主役)で読み戻した値を格納するTCHAR型配列.
					DWORD dwType;						// RegQueryValueExで取得する値の型を格納するDWORD型変数.
					DWORD cbReadSize;					// RegQueryValueExに渡すバッファサイズ/取得したサイズを格納するDWORD型変数.
					LONG lRetQueryOK;					// 1回目(成功するはず)のRegQueryValueExの戻り値を格納するLONG型変数.
					DWORD cbMissingSize;				// 2回目のRegQueryValueExに渡すバッファサイズを格納するDWORD型変数.
					LONG lRetQueryMissing;				// 2回目(わざと失敗させる)のRegQueryValueExの戻り値を格納するLONG型変数.
					LONG lRetDelete;					// RegDeleteKey(片付け用の先行利用)の戻り値を格納するLONG型変数.
					TCHAR tszLine[1024];				// 結果文字列を組み立てるTCHAR型配列tszLine.

					// 1段階目: RegCreateKey(既存トピック)でテスト用キーを作成する.
					lRetCreate = RegCreateKey(HKEY_CURRENT_USER, TEST_KEY_PATH, &hKey);	// RegCreateKeyでテスト用キーを作成.

					// 2段階目: RegSetValueEx(既存トピック)でテスト用の値を設定する.
					lRetSet = RegSetValueEx(hKey, TEST_VALUE_NAME, 0, REG_SZ, (const BYTE *)TEST_VALUE_DATA, (lstrlen(TEST_VALUE_DATA) + 1) * sizeof(TCHAR));	// RegSetValueExでREG_SZ型の値を設定.

					// 3段階目: RegQueryValueEx(本トピックの主役)で, 実際に存在する値を読み戻す.(成功するはず.)
					cbReadSize = sizeof(tszReadBuf);	// バッファサイズを設定.
					lRetQueryOK = RegQueryValueEx(hKey, TEST_VALUE_NAME, NULL, &dwType, (BYTE *)tszReadBuf, &cbReadSize);	// RegQueryValueExで読み戻す.

					// 4段階目: RegQueryValueEx(本トピックの主役)で, わざと存在しない値を読もうとする.(失敗するはず.)
					cbMissingSize = 0;	// 呼び出しのたびに再初期化する.(MSDN記載の注意事項.)
					lRetQueryMissing = RegQueryValueEx(hKey, MISSING_VALUE_NAME, NULL, NULL, NULL, &cbMissingSize);	// 存在しない値名を指定し, ERROR_FILE_NOT_FOUND(2)が返るはず.

					// 5段階目: ハンドルを閉じる.
					RegCloseKey(hKey);	// RegCloseKey(片付け用の先行利用)でハンドルを閉じる.

					// 6段階目: 次回実行時も同じ結果を再現できるように, テスト用キー自体をRegDeleteKey(片付け用の先行利用)で削除しておく.
					lRetDelete = RegDeleteKey(HKEY_CURRENT_USER, TEST_KEY_PATH);	// RegDeleteKey(片付け用の先行利用)でテスト用キーを削除し, レジストリを元の状態に戻す.

					// 6段階分の結果をまとめて組み立てる.
					wsprintf(tszLine, _T("1.RegCreateKeyでキーを作成 -> %s\r\n2.RegSetValueExで値\"%s\"に\"%s\"を設定 -> %s\r\n3.存在する値をRegQueryValueExで取得 -> %s(値=\"%s\")\r\n4.存在しない値をRegQueryValueExで取得 -> %s(戻り値=%ld, ERROR_FILE_NOT_FOUNDのはず)\r\n5.RegCloseKeyでハンドルを閉じる -> 完了\r\n6.片付け用にRegDeleteKeyで削除 -> %s\r\n"),
						lRetCreate == ERROR_SUCCESS ? _T("成功") : _T("失敗"),
						TEST_VALUE_NAME, TEST_VALUE_DATA,
						lRetSet == ERROR_SUCCESS ? _T("成功") : _T("失敗"),
						lRetQueryOK == ERROR_SUCCESS ? _T("成功") : _T("失敗"), tszReadBuf,
						lRetQueryMissing == ERROR_SUCCESS ? _T("成功") : _T("失敗"), lRetQueryMissing,
						lRetDelete == ERROR_SUCCESS ? _T("成功") : _T("失敗"));	// wsprintfで6段階分をまとめて組み立てる.

					// 実行済みフラグを立てる.(以降のSPACEキーは無視.)
					bDone = TRUE;	// bDoneをTRUEにする.

					// 組み立てた結果をこれまでの結果に追記する.
					lstrcat(tszResult, tszLine);	// lstrcatでtszResultの末尾にtszLineを連結.

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
				wsprintf(tszAll, _T("SPACEキーを押すと, テスト用の値を設定してから, 存在する値と存在しない値それぞれをRegQueryValueExで取得する, という一連の流れを実演します。\r\n\r\n%s"), tszResult);	// 案内文にtszResultを連結.
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
