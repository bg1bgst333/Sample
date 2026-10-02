// ヘッダファイルのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <windowsx.h>	// マクロ
#include <tchar.h>		// TCHAR型

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理ができるように定義したコールバック関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージを格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラスを格納するWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("ClipCursor");							// ウィンドウクラス名は"ClipCursor".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("ClipCursor"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("ClipCursor"), _T("ClipCursor"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 600, 500, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"ClipCursor"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("ClipCursor"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// ウィンドウメッセージに対して独自の処理ができるように定義したウィンドウプロシージャ.

	// static変数の宣言
	static RECT rcClip = {100, 150, 400, 350};	// カーソルを閉じ込める範囲(クライアント座標)を表すstatic変数rcClip.
	static BOOL bClipped = FALSE;				// 現在ClipCursorで制限中かどうかを表すstatic変数bClipped.(初期状態は制限なし.)

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-case文でuMsgの値ごとに処理を振り分ける.

		// キーが押されたとき.
		case WM_KEYDOWN:	// キーが押されたとき.(uMsgがWM_KEYDOWNの場合.)

			// WM_KEYDOWNブロック
			{

				// SPACEキーが押された場合のみ処理する.
				if (wParam == VK_SPACE){	// wParamがVK_SPACEの場合.

					// bClippedを反転させる.
					bClipped = !bClipped;	// bClippedを反転(制限する⇔しないを交互に切り替える).

					// bClippedの値に応じてClipCursorを呼ぶ.(これが今回の主役.)
					if (bClipped){	// 制限する場合.

						// このブロックのローカル変数の宣言
						RECT rcScreen;	// スクリーン座標に変換した範囲を格納するRECT型変数rcScreen.
						POINT ptLT;		// 左上の座標を格納するPOINT型変数ptLT.
						POINT ptRB;		// 右下の座標を格納するPOINT型変数ptRB.

						// rcClip(クライアント座標)をスクリーン座標へ変換する.(ClipCursorはスクリーン座標で指定する決まりのため.)
						ptLT.x = rcClip.left;	// ptLTにrcClipの左上をセット.
						ptLT.y = rcClip.top;
						ptRB.x = rcClip.right;	// ptRBにrcClipの右下をセット.
						ptRB.y = rcClip.bottom;
						ClientToScreen(hwnd, &ptLT);	// ClientToScreenでptLTをスクリーン座標へ変換.(既存トピック.)
						ClientToScreen(hwnd, &ptRB);	// ClientToScreenでptRBをスクリーン座標へ変換.

						// rcScreenを組み立ててClipCursorに渡す.
						rcScreen.left = ptLT.x;	// rcScreenにptLT・ptRBをセット.
						rcScreen.top = ptLT.y;
						rcScreen.right = ptRB.x;
						rcScreen.bottom = ptRB.y;
						ClipCursor(&rcScreen);	// ClipCursorにrcScreenのアドレスを渡し, カーソルの移動範囲をこの矩形内に制限する.

					}
					else{	// 制限しない場合.

						// ClipCursorにNULLを渡すと制限が解除される.
						ClipCursor(NULL);	// ClipCursorにNULLを渡し, 画面全体へ移動できるように制限を解除する.

					}

					// 表示を更新するため再描画要求.
					InvalidateRect(hwnd, NULL, TRUE);	// InvalidateRectで再描画要求.

				}

			}

			// 次の処理へ続く.
			break;	// breakで抜けても, 次の処理(DefWindowProc)へ続く.

		// ウィンドウが破棄されたとき.
		case WM_DESTROY:	// ウィンドウが破棄されたとき.(uMsgがWM_DESTROYの場合.)

			// WM_DESTROYブロック
			{

				// 終了前に, 制限がかかったままにならないよう解除しておく.
				ClipCursor(NULL);	// ClipCursorにNULLを渡し, 制限を必ず解除してから終了する.

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
				RECT rcText;		// 案内文の表示領域を格納するRECT型変数rcText.
				TCHAR tszInfo[256];	// 案内文+現在の状態を組み立てるTCHAR型配列tszInfo.

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にはデバイスコンテキストハンドルが返るので, hDCに格納.

				// 案内文と現在の状態を表示する.
				GetClientRect(hwnd, &rcClient);	// GetClientRectでクライアント領域のサイズを取得.
				rcText = rcClient;					// rcTextにrcClientをコピー.
				InflateRect(&rcText, -20, -20);	// InflateRectで少し内側に余白をとる.(既存トピックのInflateRectを流用.)
				wsprintf(tszInfo, _T("SPACEキーで、下の矩形の内側へカーソルの移動範囲をClipCursorで制限する⇔解除するを切り替えます。\r\n現在の状態: %s"), bClipped ? _T("制限中(矩形の外へ出られない)") : _T("制限なし(自由に動ける)"));	// wsprintfで案内文と現在の状態を組み立てる.
				DrawText(hDC, tszInfo, -1, &rcText, DT_LEFT | DT_TOP | DT_WORDBREAK);	// DrawTextで折り返しながら表示.

				// 制限範囲を矩形の枠で描画する.(FrameRect、既存トピック.)
				FrameRect(hDC, &rcClip, (HBRUSH)GetStockObject(BLACK_BRUSH));	// FrameRectでrcClipの枠を黒ブラシで描画.

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
