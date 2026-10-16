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
	wc.lpszClassName = _T("PolyDraw");						// ウィンドウクラス名を"PolyDraw".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("PolyDraw"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("PolyDraw"), _T("PolyDraw"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"PolyDraw"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL) {	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("PolyDraw"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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
				HPEN hPenBlue;		// 青色の太いペンを格納するHPEN型変数.
				HPEN hPenOld;		// 退避用のHPEN型変数.
				POINT points[6];	// PolyDrawに渡す6点(直線2本+ベジェ曲線1本+直線1本(自動クローズ))を格納するPOINT構造体型配列.
				BYTE types[6];		// 各点の種類(PT_MOVETO/PT_LINETO/PT_BEZIERTO, 必要に応じてPT_CLOSEFIGUREを論理和)を格納するBYTE型配列.
				LPCTSTR pszLabel;	// ラベル文字列.

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にはデバイスコンテキストハンドルが返るので, hDCに格納.

				// 角丸看板のような形(直線→直線→ベジェ曲線(丸い頭)→直線(自動クローズ))を, 1回のPolyDraw呼び出しで組み立てる.
				points[0].x = 100;	points[0].y = 300;	types[0] = PT_MOVETO;						// 0点目: 左下. PT_MOVETOで現在位置をここに設定.(パスの出発点.)
				points[1].x = 100;	points[1].y = 150;	types[1] = PT_LINETO;						// 1点目: 左上. PT_LINETOで直線を引く.(左の辺.)
				points[2].x = 100;	points[2].y = 80;	types[2] = PT_BEZIERTO;						// 2点目: ベジェ曲線の制御点1.
				points[3].x = 300;	points[3].y = 80;	types[3] = PT_BEZIERTO;						// 3点目: ベジェ曲線の制御点2.
				points[4].x = 300;	points[4].y = 150;	types[4] = PT_BEZIERTO;						// 4点目: ベジェ曲線の終点.(2?4点目の3点セットで, 1点目から4点目まで丸く弧を描く「丸い頭」の部分.)
				points[5].x = 300;	points[5].y = 300;	types[5] = PT_LINETO | PT_CLOSEFIGURE;		// 5点目: 右下. PT_LINETOで直線を引いたうえで, PT_CLOSEFIGUREを論理和することで最後に出発点(0点目)まで自動的に直線を引いて図形を閉じる.(右の辺+底辺.)

				hPenBlue = CreatePen(PS_SOLID, 4, RGB(80, 110, 230));	// CreatePenで青色の太い(4ピクセル)実線ペンを作成.
				hPenOld = (HPEN)SelectObject(hDC, hPenBlue);			// SelectObjectで青色ペンを選択し, 元のペンをhPenOldに退避.
				PolyDraw(hDC, points, types, 6);						// PolyDrawで6点とその種類を渡し, 直線とベジェ曲線が混在した1本のパスを1回の呼び出しで描画.(Polyline単体やPolyBezier単体では直線と曲線を混ぜられない.)
				SelectObject(hDC, hPenOld);							// SelectObjectで元のペンに戻す.
				DeleteObject(hPenBlue);									// DeleteObjectで青色ペンを破棄.

				// 説明用のラベルを表示.(文字数は必ずlstrlenで計算する.)
				pszLabel = _T("PolyDraw: line + line + bezier + line(close), one call");	// ラベル文字列.
				TextOut(hDC, 100, 330, pszLabel, lstrlen(pszLabel));	// TextOutでラベルを表示.

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
