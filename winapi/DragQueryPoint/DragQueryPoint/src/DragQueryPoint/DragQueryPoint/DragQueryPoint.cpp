// ヘッダファイルのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <windowsx.h>	// マクロ
#include <tchar.h>		// TCHAR型
#include <shellapi.h>	// DragAcceptFiles, DragQueryFile, DragQueryPoint, DragFinish

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理ができるように定義したコールバック関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージを格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラスを格納するWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("DragQueryPoint");				// ウィンドウクラス名は"DragQueryPoint".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("DragQueryPoint"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("DragQueryPoint"), _T("DragQueryPoint"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"DragQueryPoint"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("DragQueryPoint"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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
	static TCHAR tszDropInfo[2048] = _T("ここにファイルをドロップしてください。");	// ドロップ座標・件数・パス一覧を表示するための文字列バッファtszDropInfo.

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-case文でuMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始されたとき.
		case WM_CREATE:		// ウィンドウの作成が開始されたとき.(uMsgがWM_CREATEの場合.)

			// WM_CREATEブロック
			{

				// DragAcceptFilesで, このウィンドウがファイルのドロップを受け付けられるようにする.
				DragAcceptFiles(hwnd, TRUE);	// DragAcceptFilesにhwndとTRUEを渡し, このウィンドウをドロップ対象として登録.(これでエクスプローラーからのファイルドロップ時にWM_DROPFILESが送られてくるようになる.)

				// ウィンドウ作成続行
				return 0;	// returnして0を返すと, ウィンドウ作成を続けるという扱い.

			}

			// 次の処理へ続く.
			break;	// breakで抜けても, 次の処理(DefWindowProc)へ続く.

		// ウィンドウが破棄されたとき.
		case WM_DESTROY:	// ウィンドウが破棄されたとき.(uMsgがWM_DESTROYの場合.)

			// WM_DESTROYブロック
			{

				// DragAcceptFilesにFALSEを渡し, ドロップ受け付けを解除しておく.(ウィンドウ破棄前の後始末.)
				DragAcceptFiles(hwnd, FALSE);	// DragAcceptFilesにhwndとFALSEを渡し, ドロップ対象から解除.

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

				// クライアント領域を取得し, その中にtszDropInfoをDrawTextで折り返し表示.
				GetClientRect(hwnd, &rcClient);	// GetClientRectでクライアント領域のサイズを取得.
				InflateRect(&rcClient, -20, -20);	// InflateRectで少し内側に余白をとる.
				DrawText(hDC, tszDropInfo, -1, &rcClient, DT_LEFT | DT_TOP | DT_WORDBREAK);	// DrawTextでtszDropInfoを折り返しながら表示.(改行文字はそのまま改行として扱われる.)

				// ウィンドウの描画終了
				EndPaint(hwnd, &ps);	// EndPaintでこのウィンドウの描画処理を終了させる.

			}

			// 次の処理へ続く.
			break;	// breakで抜けても, 次の処理(DefWindowProc)へ続く.

		// メニュー項目が選ばれたとき, ボタンなどのコントロールが操作されたりしたとき.
		case WM_COMMAND:	// メニュー項目が選ばれたとき, ボタンなどのコントロールが操作されたりしたとき.(uMsgがWM_COMMANDの場合.)

			// WM_COMMANDブロック
			{

			}

			// 次の処理へ続く.
			break;	// breakで抜けても, 次の処理(DefWindowProc)へ続く.

		// ファイルがドロップされたとき.
		case WM_DROPFILES:	// ファイルがドロップされたとき.(uMsgがWM_DROPFILESの場合. DragAcceptFilesでTRUEを渡しておかないと送られてこない.)

			// WM_DROPFILESブロック
			{

				// wParamをHDROP型にキャスト.
				HDROP hDrop = (HDROP)wParam;	// wParamはドロップされたファイル情報を持つHDROPハンドル.

				// このブロックのローカル変数の宣言
				UINT nFileCount;			// ドロップされたファイルの件数を格納するUINT型変数nFileCount.
				UINT i;						// ループカウンタ用のUINT型変数i.
				TCHAR tszFile[MAX_PATH];	// 1件分のファイルパスを格納するTCHAR型配列tszFile.
				TCHAR tszHeader[256];		// 先頭の座標・件数表示行を組み立てるTCHAR型配列tszHeader.
				POINT pt;					// ドロップ座標を格納するPOINT型変数pt.
				BOOL bClientArea;			// ドロップ位置がクライアント領域内かどうかを格納するBOOL型変数bClientArea.

				// DragQueryPointでドロップ座標(クライアント座標)を取得する.
				bClientArea = DragQueryPoint(hDrop, &pt);	// DragQueryPointはptにドロップ位置(クライアント座標)を書き込み, その位置がクライアント領域内ならTRUE, 非クライアント領域(タイトルバー等)ならFALSEを返す.

				// DragQueryFileの第2引数に0xFFFFFFFFを渡すと, 第3引数(lpszFile)は無視され, ドロップされたファイルの「件数」だけが戻り値として返る.
				nFileCount = DragQueryFile(hDrop, 0xFFFFFFFF, NULL, 0);	// DragQueryFileでドロップされたファイルの件数を取得.

				// 先頭行(座標・クライアント領域内かどうか・件数)を組み立てる.
				wsprintf(tszHeader, _T("ドロップ座標: (%d, %d)  %s\r\n%d個のファイルがドロップされました。\r\n"), pt.x, pt.y, bClientArea ? _T("クライアント領域内") : _T("クライアント領域外"), nFileCount);	// wsprintfで座標・判定・件数を埋め込んだ見出し行を組み立てる.
				lstrcpy(tszDropInfo, tszHeader);	// lstrcpyでtszDropInfoの先頭に見出し行をセット.

				// 0件目からnFileCount-1件目まで, 1件ずつDragQueryFileでファイルパスを取得し, tszDropInfoに追記していく.
				for (i = 0; i < nFileCount; i++){	// iを0からnFileCount-1まで回す.

					// DragQueryFileの第2引数にi(0以上の実際のインデックス)を渡すと, 第3引数(lpszFile)にi番目のファイルパスがコピーされる.
					DragQueryFile(hDrop, i, tszFile, MAX_PATH);	// DragQueryFileでi番目のファイルパスをtszFileへ取得.

					// tszDropInfoにtszFileと改行を追記する.
					lstrcat(tszDropInfo, tszFile);	// lstrcatでtszDropInfoの末尾にtszFileを追記.
					lstrcat(tszDropInfo, _T("\r\n"));	// lstrcatで改行を追記.

				}

				// DragFinishでhDropを解放する.(解放を忘れるとリソースが解放されない.)
				DragFinish(hDrop);	// DragFinishにhDropを渡して解放.

				// 表示を更新するため再描画要求.
				InvalidateRect(hwnd, NULL, TRUE);	// InvalidateRectで再描画要求.

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
