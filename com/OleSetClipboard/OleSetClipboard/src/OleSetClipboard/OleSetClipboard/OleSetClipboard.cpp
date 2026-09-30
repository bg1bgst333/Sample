// ヘッダファイルのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <windowsx.h>	// マクロ
#include <tchar.h>		// TCHAR型
#include <ole2.h>		// OleInitialize, OleUninitialize, OleSetClipboard, OleGetClipboard

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理ができるように定義したコールバック関数WindowProc.
LPCTSTR HResultToText(HRESULT hr);													// HRESULTを分かりやすい文字列に変換する関数HResultToTextのプロトタイプ宣言.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージを格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラスを格納するWNDCLASS構造体型変数wc.
	HRESULT hr;					// HRESULT型変数hr.

	// OleInitializeでOLEを初期化する.(OleSetClipboardを使うには, CoInitializeではなくOleInitializeを呼んでおく必要がある.)
	hr = OleInitialize(NULL);	// OleInitializeにNULLを渡してOLEを初期化し, 戻り値をhrに格納.
	if (FAILED(hr)){	// FAILEDマクロでhrが失敗を表す場合.

		// エラー処理
		MessageBox(NULL, _T("OleInitialize failed!"), _T("OleSetClipboard"), MB_OK | MB_ICONHAND);	// MessageBoxで"OleInitialize failed!"とエラーメッセージを表示.
		return -3;	// 異常終了(3)

	}

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("OleSetClipboard");				// ウィンドウクラス名は"OleSetClipboard".
	wc.style = CS_HREDRAW | CS_VREDRAW;							// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;								// ウィンドウプロシージャは独自の処理を定義したWindowProc.
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("OleSetClipboard"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		OleUninitialize();	// OleUninitializeで後始末.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("OleSetClipboard"), _T("OleSetClipboard"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"OleSetClipboard"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("OleSetClipboard"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
		OleUninitialize();	// OleUninitializeで後始末.
		return -2;	// 異常終了(2)

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.

	// メッセージループ
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessageでメッセージを取得, 戻り値が0より大きい間はループを続ける.

		// ウィンドウメッセージの送出
		DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(この場合は独自に定義するWindowProc)に送出.
		TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.

	}

	// OLEの終了処理.
	OleUninitialize();	// OleUninitializeでOLEの終了処理.

	// プログラムの終了
	return (int)msg.wParam;	// 終了コード(msg.wParam)を戻り値として返す.

}

// HResultToText関数の定義.(代表的なHRESULTだけ文字列に変換する. それ以外は16進数表記にする.)
LPCTSTR HResultToText(HRESULT hr){

	// hrの値で分岐する.
	switch (hr){	// switch文でhrの値ごとに分岐.

		case S_OK:					return _T("S_OK");					// 成功.
		case CLIPBRD_E_CANT_OPEN:	return _T("CLIPBRD_E_CANT_OPEN");	// クリップボードを開けなかった.
		default:					return _T("(other)");				// その他.

	}

}

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// ウィンドウメッセージに対して独自の処理ができるように定義したウィンドウプロシージャ.

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-case文でuMsgの値ごとに処理を振り分ける.

		// キーが押されたとき.
		case WM_KEYDOWN:	// キーが押されたとき.(uMsgがWM_KEYDOWNの場合.)

			// WM_KEYDOWNブロック
			{

				// SPACEキーが押された場合のみ処理する.
				if (wParam == VK_SPACE){	// wParamがVK_SPACEの場合.

					// このブロックのローカル変数の宣言
					HRESULT hrSet;			// OleSetClipboardの戻り値を格納するHRESULT型変数hrSet.
					HRESULT hrGetAfter;		// OleSetClipboard後のOleGetClipboardの戻り値を格納するHRESULT型変数hrGetAfter.
					IDataObject *pDataObjAfter;	// OleSetClipboard後にOleGetClipboardで取得するIDataObject*へのポインタpDataObjAfter.
					TCHAR tszTitle[256];	// タイトルバーに表示する文字列を組み立てるTCHAR型配列tszTitle.

					// OleSetClipboardにNULLを渡すと, クリップボードの持ち主を降ろし, クリップボードをクリアできる.(これが今回の主役.)
					hrSet = OleSetClipboard(NULL);	// OleSetClipboardにNULLを渡し, 戻り値をhrSetに格納.

					// クリアされたことを, OleGetClipboard(既にトピック化済み)で確かめる.(クリアされていても, 対応形式0件のIDataObjectが返るはず.)
					pDataObjAfter = NULL;	// pDataObjAfterをNULLで初期化しておく.
					hrGetAfter = OleGetClipboard(&pDataObjAfter);	// OleGetClipboardにpDataObjAfterのアドレスを渡し, 戻り値をhrGetAfterに格納.

					// 結果をタイトルバーに表示する.
					wsprintf(tszTitle, _T("OleSetClipboard (setNull=%s getAfter=%s pDataObjAfter=%s)"), HResultToText(hrSet), HResultToText(hrGetAfter), (pDataObjAfter != NULL) ? _T("(non-null)") : _T("NULL"));	// wsprintfで結果を埋め込んだ文字列を組み立てる.
					SetWindowText(hwnd, tszTitle);	// SetWindowTextでタイトルバーを書き換える.

					// 取得したpDataObjAfterをReleaseで解放する.
					if (pDataObjAfter != NULL){	// pDataObjAfterがNULLでない場合.

						pDataObjAfter->Release();	// Releaseでpdataobjafterを解放.

					}

				}

			}

			// 次の処理へ続く.
			break;	// breakで抜けても, 次の処理(DefWindowProc)へ続く.

		// ウィンドウが破棄されたとき.
		case WM_DESTROY:	// ウィンドウが破棄されたとき.(uMsgがWM_DESTROYの場合.)

			// WM_DESTROYブロック
			{

				// メッセージループを抜ける.
				PostQuitMessage(0);	// PostQuitMessageで抜ける.

			}

			// 次の処理へ続く.
			break;	// breakで抜けても, 次の処理(DefWindowProc)へ続く.

		// 画面の描画が求められたとき.
		case WM_PAINT:		// 画面の描画が求められたとき.(uMsgがWM_PAINTの場合.)

			// WM_PAINTブロック
			{

				// このブロックのローカル変数の宣言
				HDC hDC;			// デバイスコンテキストハンドルを格納するHDC型変数hDC.
				PAINTSTRUCT ps;		// ペイント情報を管理するPAINTSTRUCT構造体型の変数ps.
				RECT rcClient;		// クライアント領域を格納するRECT型変数rcClient.

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にはデバイスコンテキストハンドルが返るので, hDCに格納.

				// 案内文を表示する.
				GetClientRect(hwnd, &rcClient);	// GetClientRectでクライアント領域のサイズを取得.
				InflateRect(&rcClient, -20, -20);	// InflateRectで少し内側に余白をとる.
				DrawText(hDC, _T("SPACEキーで、OleSetClipboard(NULL)を呼んでクリップボードをクリアし, 直後にOleGetClipboardで確かめます。"), -1, &rcClient, DT_LEFT | DT_TOP | DT_WORDBREAK);	// DrawTextで案内文を折り返しながら表示.

				// ウィンドウの描画終了
				EndPaint(hwnd, &ps);	// EndPaintでこのウィンドウの描画処理を終了させる.

			}

			// 次の処理へ続く.
			break;	// breakで抜けても, 次の処理(DefWindowProc)へ続く.

		// それ以外の場合.
		default:

			// 次の処理へ続く.
			break;	// breakで抜けても, 次の処理(DefWindowProc)へ続く.

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}
