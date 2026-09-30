// ヘッダファイルのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <windowsx.h>	// マクロ
#include <tchar.h>		// TCHAR型
#include <ole2.h>		// OleInitialize, OleUninitialize

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理ができるように定義したコールバック関数WindowProc.
LPCTSTR HResultToText(HRESULT hr);													// HRESULTを分かりやすい文字列に変換する関数HResultToTextのプロトタイプ宣言.

// _tWinMain関数の定義
// 注意: 今回はOleInitializeをここでは呼ばない.(OLE未初期化の状態からSPACEキー操作で実演するため.)
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージを格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラスを格納するWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("OleUninitialize");				// ウィンドウクラス名は"OleUninitialize".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("OleUninitialize"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("OleUninitialize"), _T("OleUninitialize"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"OleUninitialize"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("OleUninitialize"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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

	// プログラムの終了
	return (int)msg.wParam;	// 終了コード(msg.wParam)を戻り値として返す.

}

// HResultToText関数の定義.(代表的なHRESULTだけ文字列に変換する. それ以外は16進数表記にする.)
LPCTSTR HResultToText(HRESULT hr){

	// hrの値で分岐する.
	switch (hr){	// switch文でhrの値ごとに分岐.

		case S_OK:		return _T("S_OK");		// 初めての初期化(未初期化状態からの呼び出し).
		case S_FALSE:	return _T("S_FALSE");	// 既に初期化済みの状態からの呼び出し(参照カウントが1増えるだけ).
		default:		return _T("(other)");	// その他.

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
					HRESULT hr1;			// 1回目のOleInitializeの戻り値を格納するHRESULT型変数hr1.
					HRESULT hr2;			// 2回目のOleInitialize(入れ子)の戻り値を格納するHRESULT型変数hr2.
					HRESULT hr3;			// 1回だけOleUninitializeした直後のOleInitializeの戻り値を格納するHRESULT型変数hr3.
					HRESULT hr4;			// 入れ子を全てOleUninitializeでバランスさせた後のOleInitializeの戻り値を格納するHRESULT型変数hr4.
					TCHAR tszTitle[256];	// タイトルバーに表示する文字列を組み立てるTCHAR型配列tszTitle.

					// (1) 1回目のOleInitialize.(未初期化状態からの呼び出しなので, 新規に初期化されてS_OKになるはず.)
					hr1 = OleInitialize(NULL);	// OleInitializeにNULLを渡し, 戻り値をhr1に格納.

					// (2) 2回目のOleInitialize(入れ子).(既に初期化済みなので, 参照カウントが1増えるだけでS_FALSEになるはず.)
					hr2 = OleInitialize(NULL);	// OleInitializeにNULLを渡し, 戻り値をhr2に格納.

					// (3) OleUninitializeを1回だけ呼ぶ.(参照カウントが2→1になるだけで, まだ初期化状態は解除されない.)
					OleUninitialize();	// OleUninitializeでOLEの終了処理を1回分だけ行う.

					// (4) (3)の直後にもう一度OleInitialize.(まだ初期化済み状態のはずなので, ここでもS_FALSEになるはず. これが今回の主役=1回のOleUninitializeだけでは解除しきれないことの証拠.)
					hr3 = OleInitialize(NULL);	// OleInitializeにNULLを渡し, 戻り値をhr3に格納.

					// (5) 残っている参照カウント分(2回)をOleUninitializeでバランスさせ, 完全に未初期化状態へ戻す.
					OleUninitialize();	// OleUninitializeでOLEの終了処理をもう1回.
					OleUninitialize();	// OleUninitializeでOLEの終了処理をさらにもう1回.(これで(1)?(4)の呼び出し回数と完全にバランスする.)

					// (6) 完全に未初期化状態に戻った後のOleInitialize.(今度こそ新規初期化としてS_OKになるはず.)
					hr4 = OleInitialize(NULL);	// OleInitializeにNULLを渡し, 戻り値をhr4に格納.

					// (7) 後始末として, この最後のOleInitializeの分もOleUninitializeでバランスさせておく.
					OleUninitialize();	// OleUninitializeでOLEの終了処理.(これで一連の呼び出しが完全にバランスし, 未初期化状態で終わる.)

					// 結果をタイトルバーに表示する.
					wsprintf(tszTitle, _T("OleUninitialize (1st=%s nested=%s after1uninit=%s afterAllUninit=%s)"), HResultToText(hr1), HResultToText(hr2), HResultToText(hr3), HResultToText(hr4));	// wsprintfで結果を埋め込んだ文字列を組み立てる.
					SetWindowText(hwnd, tszTitle);	// SetWindowTextでタイトルバーを書き換える.

				}

			}

			// 次の処理へ続く.
			break;	// breakで抜けても, 次の処理(DefWindowProc)へ続く.

		// ウィンドウが破棄されたとき.
		case WM_DESTROY:	// ウィンドウが破棄されたとき.(uMsgがWM_DESTROYの場合.)

			// WM_DESTROYブロック
			{

				// メッセージループを抜ける.(OLEの初期化/終了処理は, SPACEキーの一連の操作の中で既にバランスして完結しているので, ここでは何もしなくてよい.)
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
				DrawText(hDC, _T("SPACEキーで、OleInitializeを2回連続(入れ子)で呼んだ後、OleUninitializeを1回だけ呼んだ直後と、残り全部呼んだ後、それぞれの状態でOleInitializeを試し、戻り値を対比表示します。"), -1, &rcClient, DT_LEFT | DT_TOP | DT_WORDBREAK);	// DrawTextで案内文を折り返しながら表示.

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
