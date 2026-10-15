// ヘッダファイルのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理ができるように定義するコールバック関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// 変数の宣言
	HWND hWnd;			// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;			// ウィンドウメッセージを格納するMSG構造体型変数msg.
	WNDCLASS wc;		// ウィンドウクラスを格納するWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("ExtCreatePen");						// ウィンドウクラス名を"ExtCreatePen".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;							// ウィンドウプロシージャは独自の処理を定義するWindowProc.
	wc.hInstance = hInstance;								// インスタンスハンドルは_tWinMainの引数.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// アイコンはアプリケーション既定のもの.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// カーソルは矢印.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 背景は白ブラシ.
	wc.lpszMenuName = NULL;									// メニューは無し.
	wc.cbClsExtra = 0;										// 0でよい.
	wc.cbWndExtra = 0;										// 0でよい.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)) {	// RegisterClassでウィンドウクラスを登録し, 0が返ってきたらエラー.

		// エラー処理
		MessageBox(NULL, _T("RegisterClass failed!"), _T("ExtCreatePen"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("ExtCreatePen"), _T("ExtCreatePen"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"ExtCreatePen"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL) {	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("ExtCreatePen"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.

	// メッセージループ
	while (GetMessage(&msg, NULL, 0, 0) > 0) {	// GetMessageでメッセージを取得し, 戻り値が0より大きい間はループを続ける.

		// ウィンドウメッセージの送出
		DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(今回の場合は独自に定義するWindowProc)に送出.

	}

	// プログラムの終了
	return (int)msg.wParam;	// 終了コード(msg.wParam)を戻り値として返す.

}

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {	// ウィンドウメッセージに対して独自の処理ができるように定義するウィンドウプロシージャ.

	// ウィンドウメッセージに対する処理.
	switch (uMsg) {	// switch-case文でuMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始されたとき.
		case WM_CREATE:		// ウィンドウの作成が開始されたとき.(uMsgがWM_CREATEの場合.)

			// WM_CREATEブロック
			{

				// ウィンドウ作成続行
				return 0;	// returnで0を返して, ウィンドウ作成続行とする.

			}

			// 既定の処理へ続く.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ続く.

		// ウィンドウが破棄されたとき.
		case WM_DESTROY:	// ウィンドウが破棄されたとき.(uMsgがWM_DESTROYの場合.)

			// WM_DESTROYブロック
			{

				// 終了メッセージの送信.
				PostQuitMessage(0);	// PostQuitMessageで終了コードを0とするWM_QUITメッセージを送信.(これでメッセージループのGetMessageの戻り値が0になるので, メッセージループから抜ける.)

			}

			// 既定の処理へ続く.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ続く.

		// 画面の描画が求められたとき.
		case WM_PAINT:		// 画面の描画が求められたとき.(uMsgがWM_PAINTの場合.)

			// WM_PAINTブロック
			{

				// このブロックのローカル変数・配列の宣言と初期化.
				HDC hDC;			// デバイスコンテキストハンドルを格納するHDC型変数hDC.
				PAINTSTRUCT ps;		// ペイント情報を管理するPAINTSTRUCT構造体型の変数ps.
				LOGBRUSH lb;		// ExtCreatePenに渡すペンの色・ブラシ情報を格納するLOGBRUSH構造体型変数.
				HPEN hPen;			// ExtCreatePenで作成するジオメトリックペンを格納するHPEN型変数.
				HPEN hPenOld;		// 退避用のHPEN型変数.
				DWORD dwEndCaps[3];	// 3本の線それぞれの端点スタイルを格納するDWORD型配列.
				LPCTSTR pszLabels[3];	// 3本の線それぞれのラベル文字列を格納するLPCTSTR型配列.
				int cx[3];			// 3本の線それぞれのX座標(開始位置)を格納するint型配列.
				int i;				// ループカウンタ用のint型変数.

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にはデバイスコンテキストハンドルが返るので, hDCに格納.

				// 3本の線それぞれの端点スタイル・ラベル・X座標を用意する.
				dwEndCaps[0] = PS_ENDCAP_ROUND;	dwEndCaps[1] = PS_ENDCAP_SQUARE;	dwEndCaps[2] = PS_ENDCAP_FLAT;	// 端点スタイル(丸・四角・平ら)を順に用意.
				pszLabels[0] = _T("PS_ENDCAP_ROUND");	pszLabels[1] = _T("PS_ENDCAP_SQUARE");	pszLabels[2] = _T("PS_ENDCAP_FLAT");	// 対応するラベル文字列を用意.
				cx[0] = 150;	cx[1] = 430;	cx[2] = 710;	// 3本の線を横に並べるX座標を用意.

				// LOGBRUSH構造体を用意する.(ExtCreatePenが参照するペンの色・塗りつぶし方式.)
				lb.lbStyle = BS_SOLID;			// lbStyleはBS_SOLID(単色塗りつぶし).
				lb.lbColor = RGB(80, 110, 230);	// lbColorは青色.
				lb.lbHatch = 0;					// lbHatchはBS_SOLIDのとき無視されるので0でよい.

				for (i = 0; i < 3; i++) {	// forループで3本の線すべてに対して処理.

					// ExtCreatePenで, PS_GEOMETRIC(ジオメトリックペン, 幅や端点・結合スタイルを指定できる)と, 端点スタイルdwEndCaps[i]を組み合わせた太いペインを作成する.
					hPen = ExtCreatePen(PS_GEOMETRIC | PS_SOLID | dwEndCaps[i], 30, &lb, 0, NULL);	// ExtCreatePenで幅30のジオメトリックペンを作成.(PS_SOLIDは実線, dwEndCaps[i]は端点スタイル.)
					hPenOld = (HPEN)SelectObject(hDC, hPen);	// SelectObjectで作成したペンを選択し, 元のペンをhPenOldに退避.

					MoveToEx(hDC, cx[i], 150, NULL);	// MoveToExで線の始点に現在位置を移動.
					LineTo(hDC, cx[i] + 120, 280);		// LineToで斜めの太い線を引く.(端点の形状の違いが見えるよう, 短めの線にする.)

					SelectObject(hDC, hPenOld);	// SelectObjectで元のペンに戻す.
					DeleteObject(hPen);				// DeleteObjectで作成したペンを破棄.

					// ラベルを表示.(文字数は必ずlstrlenで計算する.)
					TextOut(hDC, cx[i] - 20, 320, pszLabels[i], lstrlen(pszLabels[i]));	// TextOutでラベルを表示.

				}

				// ウィンドウの描画終了
				EndPaint(hwnd, &ps);	// EndPaintでこのウィンドウの描画処理を終了させる.

			}

			// 既定の処理へ続く.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ続く.

		// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりしたとき.
		case WM_COMMAND:	// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりしたとき.(uMsgがWM_COMMANDの場合.)

			// 既定の処理へ続く.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ続く.

		// 上記以外の場合.
		default:	// 上記以外の値の場合の既定処理.

			// 既定の処理へ続く.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ続く.

	}

	// あとは既定の処理に任せる.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// 戻り値をまるごとDefWindowProcに既定の処理を任せる.

}
