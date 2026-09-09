// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理をするように定義されるコールバック関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;		// CreateWindowで作成されるウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;		// ウィンドウメッセージを格納するMSG構造体型変数msg.
	WNDCLASS wc;	// ウィンドウクラスを扱うWNDCLASS構造体型変数wc.
	HDC hDC;		// このウィンドウ(hWnd)のデバイスコンテキストハンドルhDC.
	double x = 0;		// 矩形位置座標x(double型)を0に初期化.
	double y = 0;		// 矩形位置座標y(double型)を0に初期化.
	TCHAR szBuf[256];	// 表示文字列を組み立てるバッファszBuf.
	TCHAR szSnapshot[256];	// フリーズ直後のスナップショット文字列を格納するszSnapshot.
	BOOL bPrevSpaceDown = FALSE;	// 直前のフレームでスペースキーが押されていたかどうかbPrevSpaceDown.(エッジ検出用.)
	BOOL bSpaceDownNow;		// 今回のフレームでスペースキーが押されているかどうかbSpaceDownNow.
	BOOL bShowingSnapshot = FALSE;	// フリーズ直後のスナップショットを表示中かどうかbShowingSnapshot.(表示中はタイトルバーの上書きを止める.)
	DWORD dwSnapshotShownAt = 0;	// スナップショットを表示し始めた時刻(GetTickCountの値)dwSnapshotShownAt.(一定時間後にライブ表示へ戻すために使う.)

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("GetAsyncKeyState");					// ウィンドウクラス名を"GetAsyncKeyState".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;							// ウィンドウプロシージャは独自の処理を定義したWindowProc.
	wc.hInstance = hInstance;								// インスタンスハンドルは_tWinMainの引数.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// アイコンはアプリケーション既定のもの.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// カーソルは矢印.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 背景は白ブラシ.
	wc.lpszMenuName = NULL;									// メニューはなし.
	wc.cbClsExtra = 0;										// 0でよい.
	wc.cbWndExtra = 0;										// 0でよい.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)){	// RegisterClassでウィンドウクラスを登録し, 0が返ったらエラー.

		// エラー処理
		MessageBox(NULL, _T("RegisterClass failed!"), _T("GetAsyncKeyState"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("GetAsyncKeyState"), _T("GetAsyncKeyState"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"GetAsyncKeyState"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("GetAsyncKeyState"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.

	// デバイスコンテキストの取得.
	hDC = GetDC(hWnd);	// GetDCでデバイスコンテキストハンドルhDCを取得.

	// 文字列描画用にフォントを明示的に選択しておく.
	SelectObject(hDC, GetStockObject(SYSTEM_FONT));	// SelectObjectでシステムフォントをhDCに選択.(TextOutを使うため明示的に選択しておく.)

	// PeekMessageによるメインループ.
	while (TRUE){	// 常に真(TRUE)なので無限ループ.

		// ウィンドウメッセージが来ているかを確認する.
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE)){	// PeekMessageでウィンドウメッセージが来ているかを確認し, 真なら来ている.(PM_NOREMOVEなのでメッセージキューからこのメッセージを削除しない.あとでGetMessageがこのメッセージを取得する.)

			// 来ていたらそのメッセージを取得.
			if (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessageでPeekMessageで確認したメッセージを取得.

				// ウィンドウメッセージの送出
				TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.
				DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(この場合は独自に定義するWindowProc)に送出.

			}
			else{	// 正常終了(0), または, エラーによる異常終了(-1).

				// メインループを抜ける.
				break;	// breakでメインループを抜ける.

			}

		}
		else{	// 偽ならウィンドウメッセージが来ていないとき.

			// 少しだけ休止
			Sleep(5);	// Sleepで5ミリ秒休止.(こうしないと, 移動する矩形が表示されない.)

			// キーの状態をチェック.
			// 左キー
			if (GetAsyncKeyState(VK_LEFT) & 0x8000){		// GetAsyncKeyState(VK_LEFT)で戻り値(SHORT型)の最上位ビットが1の時.(0x8000とのAND演算がそれ.)

				// 押されている状態なのでx座標を0.1減らす.
				x = x - 0.1;	// xを0.1減らす.

			}

			// 上キー
			if (GetAsyncKeyState(VK_UP) & 0x8000){		// GetAsyncKeyState(VK_UP)で戻り値(SHORT型)の最上位ビットが1の時.(0x8000とのAND演算がそれ.)

				// 押されている状態なのでy座標を0.1減らす.
				y = y - 0.1;	// yを0.1減らす.

			}

			// 右キー
			if (GetAsyncKeyState(VK_RIGHT) & 0x8000){	// GetAsyncKeyState(VK_RIGHT)で戻り値(SHORT型)の最上位ビットが1の時.(0x8000とのAND演算がそれ.)

				// 押されている状態なのでx座標を0.1増やす.
				x = x + 0.1;	// xを0.1増やす.

			}

			// 下キー
			if (GetAsyncKeyState(VK_DOWN) & 0x8000){		// GetAsyncKeyState(VK_DOWN)で戻り値(SHORT型)の最上位ビットが1の時.(0x8000とのAND演算がそれ.)

				// 押されている状態なのでy座標を0.1増やす.
				y = y + 0.1;	// yを0.1増やす.

			}

			// スペースキーが今押されているかどうかを取得.
			bSpaceDownNow = (GetAsyncKeyState(VK_SPACE) & 0x8000) ? TRUE : FALSE;	// GetAsyncKeyState(VK_SPACE)で現在のスペースキーの状態を取得.

			// スペースキーが今回新たに押された瞬間(エッジ)を検出.
			if (bSpaceDownNow && !bPrevSpaceDown){	// 直前は押されておらず, 今回押されたとき.

				// フリーズ中であることをタイトルバーで表示.
				SetWindowText(hWnd, _T("freezing for 3 sec (message pump stopped)..."));	// SetWindowTextでフリーズ中であることを表示.

				// 3秒間, メッセージポンプを止めてSleepするだけ.(この間にWM_KEYUPが来てもメッセージキューに溜まるだけで処理されない.)
				Sleep(3000);	// Sleepで3000ミリ秒(3秒)休止.(PeekMessage/GetMessageを一切呼ばないのがポイント.)

				// フリーズ直後(まだ一度もメッセージを取得していない状態)のキー状態を記録する.
				wsprintf(szSnapshot, _T("[freeze end] GetKeyState=%s / GetAsyncKeyState=%s"), (GetKeyState(VK_RIGHT) & 0x8000) ? _T("PRESSED") : _T("RELEASED"), (GetAsyncKeyState(VK_RIGHT) & 0x8000) ? _T("PRESSED") : _T("RELEASED"));	// wsprintfでszSnapshotにフリーズ直後の両方の状態を記録.

				// タイトルバーにスナップショット結果を表示する.
				SetWindowText(hWnd, szSnapshot);	// SetWindowTextでウィンドウのタイトルをszSnapshotに変更.

				// 以後しばらく, 通常の状態表示によるタイトルバー上書きを止める.(スナップショット結果をしばらく表示し続けるため.)
				bShowingSnapshot = TRUE;	// bShowingSnapshotをTRUEにする.
				dwSnapshotShownAt = GetTickCount();	// GetTickCountで表示開始時刻を記録.

			}

			// 今回のスペースキーの状態を次回のために保存.
			bPrevSpaceDown = bSpaceDownNow;	// bSpaceDownNowをbPrevSpaceDownに保存.

			// 背景用の矩形の描画.
			Rectangle(hDC, 0, 0, 640, 480);	// Rectangleで矩形(0, 0, 640, 480)を背景用に描画.

			// 移動する矩形の描画.
			Rectangle(hDC, (int)x, (int)y, (int)(x + 100), (int)(y + 100));	// Rectangleで矩形(x, y, x + 100, y + 100)の矩形を描画.(x, yはdouble型なのでintにキャストしている.)

			// スナップショット表示開始から3秒経っていたら, ライブ表示に戻す.(何度でも実験し直せるようにするため.)
			if (bShowingSnapshot && (GetTickCount() - dwSnapshotShownAt >= 3000)){	// スナップショット表示中かつ3000ミリ秒以上経過したとき.

				// ライブ表示に戻す.
				bShowingSnapshot = FALSE;	// bShowingSnapshotをFALSEに戻す.

			}

			// スナップショット表示中でなければ, タイトルバーに現在の状態を表示し続ける.(GetKeyStateとGetAsyncKeyStateの違いを見せるための比較用表示.)
			if (!bShowingSnapshot){	// bShowingSnapshotが偽(スナップショット表示中でない)のとき.

				// GetKeyState(VK_RIGHT)とGetAsyncKeyState(VK_RIGHT)の状態を1行にまとめて文字列に組み立てる.
				wsprintf(szBuf, _T("GetKeyState=%s / GetAsyncKeyState=%s"), (GetKeyState(VK_RIGHT) & 0x8000) ? _T("PRESSED") : _T("RELEASED"), (GetAsyncKeyState(VK_RIGHT) & 0x8000) ? _T("PRESSED") : _T("RELEASED"));	// wsprintfで文字列szBufを組み立てる.(最上位ビットが1ならPRESSED, そうでなければRELEASED.)

				// タイトルバーへ反映.
				SetWindowText(hWnd, szBuf);	// SetWindowTextでウィンドウのタイトルをszBufに変更.

			}

		}

	}

	// デバイスコンテキストの解放.
	if (hDC != NULL){	// hDCが解放されていないとき.

		// デバイスコンテキストを解放.
		ReleaseDC(hWnd, hDC);	// ReleaseDCでhDCを解放.
		hDC = NULL;	// NULLをセット.

	}

	// プログラムの終了
	return (int)msg.wParam;	// 終了コード(msg.wParam)を戻り値として返す.

}

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// ウィンドウメッセージに対して独自の処理をするように定義されるウィンドウプロシージャ.

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-caseによりuMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始されたら.
		case WM_CREATE:		// ウィンドウの作成が開始されたら.(uMsgがWM_CREATEの時.)

			// WM_CREATEブロック
			{

				// ウィンドウ作成続行
				return 0;	// returnして0を返すと, ウィンドウ作成続行とする.

			}

			// 既定の処理へ委ねる.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ委ねる.

		// ウィンドウが破棄されたら.
		case WM_DESTROY:	// ウィンドウが破棄されたら.(uMsgがWM_DESTROYの時.)

			// WM_DESTROYブロック
			{

				// 終了メッセージの送信.
				PostQuitMessage(0);	// PostQuitMessageで終了コードを0としてWM_QUITメッセージを送信.(これでメッセージループのGetMessageの戻り値が0になるので, メッセージループから抜ける.)

			}

			// 既定の処理へ委ねる.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ委ねる.

		// 上記以外の時.
		default:	// 上記以外の値の時の既定処理.

			// 既定の処理へ委ねる.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ委ねる.

	}

	// あとは既定の処理に任せる.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// 戻り値ごと既定のDefWindowProcに既定の処理を任せる.

}
