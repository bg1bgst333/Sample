// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// C標準入出力

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理をするように定義したコールバック関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数・配列の宣言・初期化
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージ情報を格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラス情報をもつWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("ClientToScreen");				// ウィンドウクラス名は"ClientToScreen".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;							// ウィンドウプロシージャは独自の処理を定義したWindowProc.
	wc.hInstance = hInstance;								// インスタンスハンドルは_tWinMainの引数.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// アイコンはアプリケーション既定のもの.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// カーソルは矢印.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 背景は白ブラシ.
	wc.lpszMenuName = NULL;									// なし
	wc.cbClsExtra = 0;										// 0でいい.
	wc.cbWndExtra = 0;										// 0でいい.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)){	// RegisterClassでウィンドウクラスを登録し, 0が返ったらエラー.

		// エラー処理
		MessageBox(NULL, _T("RegisterClass Failure!"), _T("ClientToScreen"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass Failure!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("ClientToScreen"), _T("ClientToScreen"), WS_OVERLAPPEDWINDOW, 100, 100, 640, 480, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"ClientToScreen"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow Failure!"), _T("ClientToScreen"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow Failure!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.

	// メッセージループ
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessageでメッセージを取得, 戻り値が0より大きい間はループし続ける.

		// ウィンドウメッセージ処理
		TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.
		DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(この場合は独自に定義したWindowProc)に送出.

	}

	// プログラムの終了
	return (int)msg.wParam;	// 終了コード(msg.wParam)を戻り値として返す.

}

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// ウィンドウメッセージに対して独自の処理をするように定義したウィンドウプロシージャ.

	// スタティック変数の宣言.
	static int x;	// マウス左ボタンが押された時のマウスカーソルの水平方向の位置.(x座標)
	static int y;	// マウス左ボタンが押された時のマウスカーソルの垂直方向の位置.(y座標)

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-casa文でuMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始された時.
		case WM_CREATE:		// ウィンドウの作成が開始された時.(uMsgがWM_CREATEの時.)
 
			// WM_CREATEブロック
			{
 
				// ウィンドウ作成成功
				return 0;	// return文で0を返して, ウィンドウ作成成功とする.
 
			}
 
			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.
 
		// ウィンドウが破棄された時.
		case WM_DESTROY:	// ウィンドウが破棄された時.(uMsgがWM_DESTROYの時.)
 
			// WM_DESTROYブロック
			{
 
				// 終了メッセージの送信.
				PostQuitMessage(0);	// PostQuitMessageで終了コードを0としてWM_QUITメッセージを送信.(するとメッセージループのGetMessageの戻り値が0になるので, メッセージループから抜ける.)
 
			}
 
			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// ウィンドウの描画を要求された時.
		case WM_PAINT:

			// WM_PAINTブロック
			{

				// 描画開始.
				PAINTSTRUCT ps = {0};	// PAINTSTRUCT構造体psを{0}で初期化.
				HDC hDC = BeginPaint(hwnd, &ps);	// BeginPaintで描画開始し, hDC取得.
				
				// クリックされた位置のクライアント座標を描画.
				TCHAR tszClient[64] = {0};	// クライアント座標文字列tszClient(長さ64)を{0}で初期化.
				_stprintf(tszClient, _T("Client(%d, %d)"), x, y);	// クライアント座標(x, y)を文字列tszClientに変換.
				TextOut(hDC, 50, 50, tszClient, (int)_tcslen(tszClient));	// TextOutでtszClientを描画.

				// クライアント座標をスクリーン座標に変換し, それも描画.
				POINT pt;	// POINT構造体ptの宣言.
				pt.x = x;	// pt.xにxを代入.
				pt.y = y;	// pt.yにyを代入.
				ClientToScreen(hwnd, &pt);	// ClientToScreenでptをスクリーン座標に変換.
				TCHAR tszScreen[64] = {0};	// スクリーン座標文字列tszScreen(長さ64)を{0}で初期化.
				_stprintf(tszScreen, _T("Screen(%d, %d)"), pt.x, pt.y);	// スクリーン座標(pt.x, pt.y)を文字列tszScreenに変換.
				TextOut(hDC, 50, 100, tszScreen, (int)_tcslen(tszScreen));	// TextOutでtszScreenを描画.

				// 描画終了.
				EndPaint(hwnd, &ps);	// EndPaintで描画終了.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// マウスの左ボタンが押された時.
		case WM_LBUTTONDOWN:	// マウスの左ボタンが押された時.(uMsgがWM_LBUTTONDOWNの時.)

			// WM_LBUTTONDOWNブロック
			{

				// マウスカーソルの位置を取得.
				x = LOWORD(lParam);	// lParamの下位16ビットはマウスカーソルのx座標を表しているので, LOWORDでlParamの下位16ビットを取得し, xに格納.
				y = HIWORD(lParam);	// lParamの上位16ビットはマウスカーソルのy座標を表しているので, HIWORDでlParamの上位16ビットを取得し, yに格納.

				// マウスの左ボタンが押されたので, 画面を無効領域化することで更新を促す.
				InvalidateRect(hwnd, NULL, TRUE);	// InvalidateRectでhwndの画面を無効領域化する.(第2引数がNULLなら, ウィンドウのクライアント領域全体を更新対象とする.)

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// 上記以外の時.
		default:	// 上記以外の値の時の既定処理.
 
			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.
 
	}
 
	// あとは既定の処理に任せる.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// 戻り値も含めDefWindowProcに既定の処理を任せる.

}