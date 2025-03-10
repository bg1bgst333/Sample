// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理をするように定義したコールバック関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;		// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;		// ウィンドウメッセージ情報を格納するMSG構造体型変数msg.
	WNDCLASS wc;		// ウィンドウクラス情報をもつWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("PAINTSTRUCT");					// ウィンドウクラス名は"PAINTSTRUCT".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;							// ウィンドウプロシージャは独自の処理を定義したWindowProc.
	wc.hInstance = hInstance;								// インスタンスハンドルは_tWinMainの引数.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// アイコンはアプリケーション既定のもの.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// カーソルは矢印.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 背景は白ブラシ.
	wc.lpszMenuName =NULL;									// なし
	wc.cbClsExtra = 0;										// 0でいい.
	wc.cbWndExtra = 0;										// 0でいい.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)) {	// RegisterClassでウィンドウクラスを登録し, 0が返ったらエラー.

		// エラー処理
		MessageBox(NULL, _T("RegisterClass Failure!"), _T("PAINTSTRUCT"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass Failure!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("PAINTSTRUCT"), _T("PAINTSTRUCT"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"PAINTSTRUCT"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL) {	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow Failure!"), _T("PAINTSTRUCT"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow Failure!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.

	// メッセージループ
	while (GetMessage(&msg, NULL, 0, 0) > 0) {	// GetMessageでメッセージを取得, 戻り値が0より大きい間はループし続ける.

		// ウィンドウメッセージ処理
		TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.
		DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(この場合は独自に定義したWindowProc)に送出.

	}

	// プログラムの終了
	return (int)msg.wParam;	// 終了コード(msg.wParam)を戻り値として返す.

}

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {	// ウィンドウメッセージに対して独自の処理をするように定義したウィンドウプロシージャ.

	// ウィンドウプロシージャ全体で使われるスタティック変数の宣言.
	static HPEN hRedPen;		// 描画する矩形の縁に使われる赤いペンのハンドルを格納するHPEN型スタティック変数hRedPen.
	static HBRUSH hRedBrush;	// 描画する矩形を塗りつぶすのに使われる赤いブラシのハンドルを格納するHBRUSH型スタティック変数hRedBrush.
	static HPEN hGreenPen;		// 描画する矩形の縁に使われる緑のペンのハンドルを格納するHPEN型スタティック変数hGreenPen.
	static HBRUSH hGreenBrush;	// 描画する矩形を塗りつぶすのに使われる緑のブラシのハンドルを格納するHBRUSH型スタティック変数hGreenBrush.
	static HPEN hBluePen;		// 描画する矩形の縁に使われる青いペンのハンドルを格納するHPEN型スタティック変数hBluePen.
	static HBRUSH hBlueBrush;	// 描画する矩形を塗りつぶすのに使われる青いブラシのハンドルを格納するHBRUSH型スタティック変数hBlueBrush.
	static BYTE btDrawColor = 0;	// どの色で塗るかを持つ状態変数btDrawColorを0(赤)で初期化.

	// ウィンドウメッセージに対する処理.
	switch (uMsg) {	// switch-casa文でuMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始された時.
		case WM_CREATE:		// ウィンドウの作成が開始された時.(uMsgがWM_CREATEの時.)

			// WM_CREATEブロック
			{

				// ペンとブラシの作成.
				hRedPen = CreatePen(PS_SOLID, 1, RGB(0xFF, 0x00, 0x00));	// CreatePenで赤いペンを作成.
				hRedBrush = CreateSolidBrush(RGB(0xFF, 0x00, 0x00));		// CreateSolidBrushで赤いブラシを作成.
				hGreenPen = CreatePen(PS_SOLID, 1, RGB(0x00, 0xFF, 0x00));	// CreatePenで緑のペンを作成.
				hGreenBrush = CreateSolidBrush(RGB(0x00, 0xFF, 0x00));		// CreateSolidBrushで緑のブラシを作成.
				hBluePen = CreatePen(PS_SOLID, 1, RGB(0x00, 0x00, 0xFF));	// CreatePenで青いペンを作成.
				hBlueBrush = CreateSolidBrush(RGB(0x00, 0x00, 0xFF));		// CreateSolidBrushで青いブラシを作成.

				// ウィンドウ作成成功
				return 0;	// return文で0を返して, ウィンドウ作成成功とする.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// ウィンドウが破棄された時.
		case WM_DESTROY:	// ウィンドウが破棄された時.(uMsgがWM_DESTROYの時.)

			// WM_DESTROYブロック
			{

				// ペンとブラシの破棄.
				DeleteObject(hRedPen);		// DeleteObjectでhRedPenを破棄.
				DeleteObject(hRedBrush);	// DeleteObjectでhRedBrushを破棄.
				DeleteObject(hGreenPen);	// DeleteObjectでhGreenPenを破棄.
				DeleteObject(hGreenBrush);	// DeleteObjectでhGreenBrushを破棄.
				DeleteObject(hBluePen);		// DeleteObjectでhBluePenを破棄.
				DeleteObject(hBlueBrush);	// DeleteObjectでhBlueBrushを破棄.

				// 終了メッセージの送信.
				PostQuitMessage(0);	// PostQuitMessageで終了コードを0としてWM_QUITメッセージを送信.(するとメッセージループのGetMessageの戻り値が0になるので, メッセージループから抜ける.)

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// 画面の描画を要求された時.
		case WM_PAINT:		// 画面の描画を要求された時.(uMsgがWM_PAINTの時.)
 
			// WM_PAINTブロック
			{

				// このブロックのローカル変数の宣言
				HDC hDC;			// デバイスコンテキストハンドルを格納するHDC型変数hDC.
				PAINTSTRUCT ps;		// ペイント情報を管理するPAINTSTRUCT構造体型の変数ps.
				HPEN hOldPen;		// SelectObjectされるまで使っていた古いペンのハンドルhOldPen.
				HBRUSH hOldBrush;	// SelectObjectされるまで使っていた古いブラシのハンドルhOldBrush.

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にはデバイスコンテキストハンドルが返るので, hDCに格納.

				// btDrawColorで色を変える.
				if (btDrawColor == 0){	// 赤
					hOldPen = (HPEN)SelectObject(hDC, hRedPen);	// 赤いペンを選択.
					hOldBrush = (HBRUSH)SelectObject(hDC, hRedBrush);	// 赤いブラシを選択.
					btDrawColor = 1;	// 緑にする.
				}
				else if (btDrawColor == 1){	// 緑
					hOldPen = (HPEN)SelectObject(hDC, hGreenPen);	// 緑のペンを選択.
					hOldBrush = (HBRUSH)SelectObject(hDC, hGreenBrush);	// 緑のブラシを選択.
					btDrawColor = 2;	// 青にする.
				}
				else{	// 青
					hOldPen = (HPEN)SelectObject(hDC, hBluePen);	// 青いペンを選択.
					hOldBrush = (HBRUSH)SelectObject(hDC, hBlueBrush);	// 青いブラシを選択.
					btDrawColor = 0;	// 赤にする.
				}

				// 矩形を描画.
				Rectangle(hDC, ps.rcPaint.left, ps.rcPaint.top, ps.rcPaint.right, ps.rcPaint.bottom);	// ps.rcPaintの領域に矩形描画.

				// ペンとブラシの状態を戻す.
				SelectObject(hDC, hOldPen);		// デバイスコンテキストに元のhOldPenに戻すように選択させる.
				SelectObject(hDC, hOldBrush);	// デバイスコンテキストに元のhOldBrushに戻すように選択させる.

				// ウィンドウの描画終了
				EndPaint(hwnd, &ps);	// EndPaintでこのウィンドウの描画処理を終了する.

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