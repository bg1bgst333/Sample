// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// C標準入出力
#include <string.h>		// C文字列処理
 
// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理をするように定義したコールバンク関数WindowProc.
 
// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){
 
	// 変数の宣言
	HWND hWnd;			// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;			// ウィンドウメッセージ情報を格納するMSG構造体型変数msg.
	WNDCLASS wc;		// ウィンドウクラス情報をもつWNDCLASS構造体型変数wc.
 
	// ウィンドウクラスの設定
	wc.lpszClassName = _T("LineTo");						// ウィンドウクラス名は"LineTo".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;							// ウィンドウプロシージャは独自の処理を定義したWindowProc.
	wc.hInstance = hInstance;								// インスタンスハンドルは_tWinMainの引数.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// アイコンはアプリケーション既定のもの.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// カーソルは矢印.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 背景は白ブラシ.
	wc.lpszMenuName = NULL;									// メニューはなし.
	wc.cbClsExtra = 0;										// 0でいい.
	wc.cbWndExtra = 0;										// 0でいい.
 
	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)){	// RegisterClassでウィンドウクラスを登録し, 0が返ったらエラー.
 
		// エラー処理
		MessageBox(NULL, _T("RegisterClass failed!"), _T("LineTo"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)
 
	}
 
	// ウィンドウの作成
	hWnd = CreateWindow(_T("LineTo"), _T("LineTo"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"LineTo"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.
 
		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("LineTo"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)
 
	}
 
	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.
 
	// メッセージループ
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessageでメッセージを取得, 戻り値が0より大きい間はループし続ける.
 
		// ウィンドウメッセージの送出
		DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(この場合は独自に定義したWindowProc)に送出.
 
	}
 
	// プログラムの終了
	return (int)msg.wParam;	// 終了コード(msg.wParam)を戻り値として返す.
 
}
 
// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// ウィンドウメッセージに対して独自の処理をするように定義したウィンドウプロシージャ.
 
	// ウィンドウプロシージャ全体で使われるスタティック変数の宣言.
	static HDC hDC;		// デバイスコンテキストハンドルを格納するHDC型スタティック変数hDC.

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-casa文でuMsgの値ごとに処理を振り分ける.
 
		// ウィンドウの作成が開始された時.
		case WM_CREATE:		// ウィンドウの作成が開始された時.(uMsgがWM_CREATEの時.)
 
			// WM_CREATEブロック
			{
 
				// このウィンドウのデバイスコンテキストハンドルを取得.
				hDC = GetDC(hwnd);	// GetDCでhwndのデバイスコンテキストハンドルを取得し, hDCに格納.

				// ウィンドウ作成成功
				return 0;	// return文で0を返して, ウィンドウ作成成功とする.
 
			}
 
			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.
 
		// ウィンドウが破棄された時.
		case WM_DESTROY:	// ウィンドウが破棄された時.(uMsgがWM_DESTROYの時.)
 
			// WM_DESTROYブロック
			{

				// デバイスコンテキストの解放.
				ReleaseDC(hwnd, hDC);	// ReleaseDCでhDCに格納されているデバイスコンテキストを解放.
 
				// 終了メッセージの送信.
				PostQuitMessage(0);	// PostQuitMessageで終了コードを0としてWM_QUITメッセージを送信.(するとメッセージループのGetMessageの戻り値が0になるので, メッセージループから抜ける.)
 
			}
 
			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// マウスの左ボタンが押された時.
		case WM_LBUTTONDOWN:	// マウスの左ボタンが押された時.(uMsgがWM_LBUTTONDOWNの時.)

			// WM_LBUTTONDOWNブロック
			{

				// このブロックのローカル変数・配列の宣言
				int x;					// マウス左ボタンが押された時のマウスカーソルの位置x座標.
				int y;					// マウス左ボタンが押された時のマウスカーソルの位置y座標.
				TCHAR tszPoints[128];	// 直近でマウス左ボタンが押された時のマウスカーソル位置座標と, その前に押された時のマウスカーソル位置座標を表示するために用意したTCHAR型文字配列tszPoints.(長さ128)
				size_t uiLen;			// tszPointsに格納された文字列の長さを格納するためのsize_t型変数uiLen.
				POINT pt;				// 以前押された時のマウスカーソル位置座標を格納するPOINT型構造体変数pt.

				// マウスカーソルの位置を取得.
				x = LOWORD(lParam);	// lParamの下位16ビットはマウスカーソルのx座標を表しているので, LOWORDでlParamの下位16ビットを取得し, xに格納.
				y = HIWORD(lParam);	// lParamの上位16ビットはマウスカーソルのy座標を表しているので, HIWORDでlParamの上位16ビットを取得し, yに格納.

				// 描画する現在の位置(LineToなどで)を, 直近でマウス左ボタンが押された時のマウスカーソル位置座標に更新する.
				MoveToEx(hDC, x, y, &pt);	// MoveToExで描画する現在の位置を(x, y)に更新する. 以前の位置はptに格納される.

				// 新しい位置の座標(x, y)と以前の位置の座標(pt.x, pt.y)を表示.
				_stprintf(tszPoints, _T("before(%d, %d) -> after(%d, %d)"), pt.x, pt.y, x, y);	// _stprintfでtszPointsに以前の座標(pt.x, pt.y)と新しい座標座標(x, y)を"before(%d, %d) -> after(%d, %d)"のフォーマットでセット.
				uiLen = _tcslen(tszPoints);	// _tcslenでtszPointsの長さを取得. 
				TextOut(hDC, 0, 0, tszPoints, (int)uiLen);	// TextOutでウィンドウhwndの座標(0, 0)の位置にtszPointsを描画.

				// マウス左ボタンが押された時のマウスカーソル位置に赤い点を打つ.
				SetPixel(hDC, x, y, 0x000000FF);	// SetPixelで座標(x, y)の位置に赤い(0x000000FF)点を打つ.
				
			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// マウスの右ボタンが押された時.
		case WM_RBUTTONDOWN:	// マウスの右ボタンが押された時.(uMsgがWM_RBUTTONDOWNの時.)

			// WM_RBUTTONDOWNブロック
			{

				// このブロックのローカル変数
				int x;	// マウス右ボタンが押された時のマウスカーソルの位置x座標.
				int y;	// マウス右ボタンが押された時のマウスカーソルの位置y座標.
				
				// マウスカーソルの位置を取得.
				x = LOWORD(lParam);	// lParamの下位16ビットはマウスカーソルのx座標を表しているので, LOWORDでlParamの下位16ビットを取得し, xに格納.
				y = HIWORD(lParam);	// lParamの上位16ビットはマウスカーソルのy座標を表しているので, HIWORDでlParamの上位16ビットを取得し, yに格納.

				// 描画する現在の位置(マウス左ボタンが押された時の位置)からマウス右ボタンが押された位置まで直線を引く.
				LineTo(hDC, x, y);	// LineToで押す前のマウスカーソルの位置から(x, y)までの直線を描画する.

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