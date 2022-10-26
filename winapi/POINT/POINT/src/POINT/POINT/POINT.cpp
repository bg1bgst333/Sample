// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// C標準入出力
#include <commctrl.h>	// コモンコントロール

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理をするように定義したコールバック関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数・配列の宣言・初期化
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージ情報を格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラス情報をもつWNDCLASS構造体型変数wc.
	HDC hDC;					// このウィンドウ(hWnd)のデバイスコンテキストハンドルhDC.
	POINT pt;					// マウス位置座標を表すPOINT構造体変数pt.
	TCHAR tszPosition[32];		// マウス位置座標文字列tszPosition(長さ32)
	HWND hPoint;				// WindowFromPointで取得したその位置のウィンドウハンドルhPoint.
	TCHAR tszHPoint[32];		// hPointを文字列にしたものtszHPoint.(長さ32)

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("POINT");							// ウィンドウクラス名は"POINT".
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
		MessageBox(NULL, _T("RegisterClass Failure!"), _T("POINT"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass Failure!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("POINT"), _T("POINT"), WS_OVERLAPPEDWINDOW, 100, 100, 640, 480, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"POINT"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow Failure!"), _T("POINT"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow Failure!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)

	}

	// ウィンドウハンドルの表示.
	TCHAR tszHWnd[64] = {0};	// ウィンドウハンドル文字列tszHWnd(長さ64)を{0}で初期化.
	_stprintf(tszHWnd, _T("hWnd = 0x%08x"), hWnd);	// hWndを文字列tszHWndに変換.
	MessageBox(NULL, tszHWnd, _T("POINT"), MB_OK);	// tszHWndを表示.
				
	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.

	// デバイスコンテキストの取得.
	hDC = GetDC(hWnd);	// GetDCでデバイスコンテキストハンドルhDCを取得.

	// PeekMessageによるメインループ.
	while (TRUE){	// 常に真(TRUE)なので無限ループ.

		// ウィンドウメッセージが来ているかを確認する.
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE)){	// PeekMessageでウィンドウメッセージが来ているかを確認し, 真なら来ている.(PM_NOREMOVEなのでメッセージキューからこのメッセージを削除しない.次のGetMessageがそのメッセージを処理する.)

			// 来ていたらそのメッセージを取得.
			if (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessageでPeekMessageで確認したメッセージを取得.

				// ウィンドウメッセージの送出
				TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.
				DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(この場合は独自に定義したWindowProc)に送出.

			}
			else{	// 正常終了(0), またはエラーによる異常終了(-1).

				// メインループを抜ける.
				break;	// breakでメインループを抜ける.

			}

		}
		else{	// 偽ならウィンドウメッセージが来ていないとき.

			// マウス位置座標を取得.
			GetCursorPos(&pt);	// GetCursorPosでマウス位置座標を取得し, ptに格納.

			// マウス位置座標を文字列に変換.
			_stprintf(tszPosition, _T("(%d, %d)"), pt.x, pt.y);	// _stprintfでpt.x, pt.yを文字列に変換してtszPositionに格納.

			// マウス位置座標文字列を描画.
			TextOut(hDC, 250, 50, tszPosition, (int)_tcslen(tszPosition));	// TextOutでマウス位置座標文字列tszPositionを描画.

			// その位置のウィンドウハンドルを取得.
			hPoint = WindowFromPoint(pt);	// WindowFromPointにptを渡して, その位置のウィンドウハンドルhPointを取得.

			// hPointを文字列に変換.
			_stprintf(tszHPoint, _T("hPoint = 0x%08x"), hPoint);	// hPointを文字列tszHPointに変換.

			// hPointを描画.
			TextOut(hDC, 250, 150, tszHPoint, (int)_tcslen(tszHPoint));	// TextOutでhPointを文字列に変換したtszHPointを描画.

		}

	}

	// デバイスコンテキストの解放.
	if (hDC != NULL){	// hDCが解放されていなければ.
 
		// デバイスコンテキストを解放する.
		ReleaseDC(hWnd, hDC);	// ReleaseDCでhDCを解放.
		hDC = NULL;	// NULLをセット.

	}

	// プログラムの終了
	return (int)msg.wParam;	// 終了コード(msg.wParam)を戻り値として返す.

}

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// ウィンドウメッセージに対して独自の処理をするように定義したウィンドウプロシージャ.

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-casa文でuMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始された時.
		case WM_CREATE:		// ウィンドウの作成が開始された時.(uMsgがWM_CREATEの時.)
 
			// WM_CREATEブロック
			{

				// 変数の宣言
				HWND hButton;			// ボタンのウィンドウハンドルhButton.
				LPCREATESTRUCT lpCS;	// CreateStruct構造体のポインタlpCS.

				// アプリケーションインスタンスハンドルの取得.
				lpCS = (LPCREATESTRUCT)lParam;	// lParamをLPCREATESTRUCTにキャストして, lpCSに格納.

				// ボタンの作成.
				hButton = CreateWindow(WC_BUTTON, _T("Button1"), WS_CHILD | WS_VISIBLE, 50, 50, 100, 100, hwnd, (HMENU)(WM_APP + 1), lpCS->hInstance, NULL);	// CreateWindowのWC_BUTTONでボタン"Button1"を作成.
				if (hButton == NULL){	// hButtonがNULLなら.

					// エラー処理.
					return -1;	// -1を返す.

				}

				// ボタンハンドルの表示.
				TCHAR tszHButton[64] = {0};	// ボタンハンドル文字列tszHButton(長さ64)を{0}で初期化.
				_stprintf(tszHButton, _T("hButton = 0x%08x"), hButton);	// hButtonを文字列tszHButtonに変換.
				MessageBox(NULL, tszHButton, _T("POINT"), MB_OK);	// tszHButtonを表示.

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
				
				// 描画終了.
				EndPaint(hwnd, &ps);	// EndPaintで描画終了.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりした時.
		case WM_COMMAND:	// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりした時.(uMsgがWM_COMMANDの時.)

			// WM_COMMANDブロック
			{

				// どのメニュー項目が選択されたかを判定する.
				switch (LOWORD(wParam)){	// LOWORD(wParam)で選択されたメニュー項目のIDが取得できるので, その値で判定する.

					
					// 取得したIDごとに処理を分岐.
					// Button1が選択された時.
					case WM_APP + 1:

						// WM_APP + 1ブロック
						{

							// この位置のウィンドウハンドル表示.
							POINT pt = {0};	// 位置ptを{0}で初期化.
							GetCursorPos(&pt);	// GetCursorPosでptを取得.
							HWND hPoint;	// このポイントのウィン		ドウハンドルhPoint.
							hPoint = WindowFromPoint(pt);	// WindowFromPointで, この位置のウィンドウハンドルを取得し, hPointに格納.
							TCHAR tszHPoint[64] = {0};	// ハンドル文字列tszHPoint(長さ64)を{0}で初期化.
							_stprintf(tszHPoint, _T("hPoint = 0x%08x"), hPoint);	// hPointを文字列tszHPointに変換.
							MessageBox(NULL, tszHPoint, _T("POINT"), MB_OK);	// tszHPointを表示.
							return 0;	// 処理したので戻り値として0を返す.

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// 上記以外の時.
					default:	// 上記以外の値の時の既定処理.
 
						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

				}

				// 既定の処理へ向かう.
				break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// マウスの左ボタンが押された時.
		case WM_LBUTTONDOWN:	// マウスの左ボタンが押された時.(uMsgがWM_LBUTTONDOWNの時.)

			// WM_LBUTTONDOWNブロック
			{

				// マウスカーソルの位置を取得.
				int x;	// マウス左ボタンが押された時のマウスカーソルの水平方向の位置.(x座標)
				int y;	// マウス左ボタンが押された時のマウスカーソルの垂直方向の位置.(y座標)
				x = LOWORD(lParam);	// lParamの下位16ビットはマウスカーソルのx座標を表しているので, LOWORDでlParamの下位16ビットを取得し, xに格納.
				y = HIWORD(lParam);	// lParamの上位16ビットはマウスカーソルのy座標を表しているので, HIWORDでlParamの上位16ビットを取得し, yに格納.

				// クライアント座標をスクリーン座標に変換.
				POINT pt;	// POINT構造体ptの宣言.
				pt.x = x;	// pt.xにxを代入.
				pt.y = y;	// pt.yにyを代入.
				ClientToScreen(hwnd, &pt);	// ClientToScreenでptをスクリーン座標に変換.

				// この位置のウィンドウハンドルを取得し, 表示.
				HWND hPoint;	// このポイントのウィン		ドウハンドルhPoint.
				hPoint = WindowFromPoint(pt);	// WindowFromPointで, この位置のウィンドウハンドルを取得し, hPointに格納.
				TCHAR tszHPoint[64] = {0};	// ハンドル文字列tszHPoint(長さ64)を{0}で初期化.
				_stprintf(tszHPoint, _T("hPoint = 0x%08x"), hPoint);	// hPointを文字列tszHPointに変換.
				MessageBox(NULL, tszHPoint, _T("POINT"), MB_OK);	// tszHPointを表示.

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