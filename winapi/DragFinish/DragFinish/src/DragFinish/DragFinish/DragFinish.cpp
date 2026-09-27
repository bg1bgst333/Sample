// ヘッダファイルのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <windowsx.h>	// マクロ
#include <tchar.h>		// TCHAR型
#include <shellapi.h>	// DragAcceptFiles, DragQueryFile, DragQueryPoint, DragFinish
#include <psapi.h>		// GetProcessMemoryInfo

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理ができるように定義したコールバック関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージを格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラスを格納するWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("DragFinish");				// ウィンドウクラス名は"DragFinish".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("DragFinish"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("DragFinish"), _T("DragFinish"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"DragFinish"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("DragFinish"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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
	static TCHAR tszDropInfo[2048] = _T("ここにファイルをドロップしてください。");	// ドロップ回数・メモリ使用量等を表示するための文字列バッファtszDropInfo.
	static int nDropCount = 0;	// これまでにWM_DROPFILESを受け取った回数を数えるstatic変数nDropCount.

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
				UINT nFileCount;					// ドロップされたファイルの件数を格納するUINT型変数nFileCount.
				PROCESS_MEMORY_COUNTERS pmc;		// 自プロセスのメモリ使用量を格納するPROCESS_MEMORY_COUNTERS構造体型変数pmc.
				TCHAR tszHeader[256];				// 表示行を組み立てるTCHAR型配列tszHeader.

				// ドロップされた回数を1増やす.
				nDropCount++;	// nDropCountをインクリメント.

				// DragQueryFileの第2引数に0xFFFFFFFFを渡すと, 第3引数(lpszFile)は無視され, ドロップされたファイルの「件数」だけが戻り値として返る.
				nFileCount = DragQueryFile(hDrop, 0xFFFFFFFF, NULL, 0);	// DragQueryFileでドロップされたファイルの件数を取得.

				// GetProcessMemoryInfoで自プロセスの現在のメモリ使用量(ワーキングセットサイズ)を取得する.
				GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));	// GetProcessMemoryInfoでpmcに現在のメモリ使用量を取得.

				// 表示行(ドロップ回数・件数・メモリ使用量)を組み立てる.
				wsprintf(tszHeader, _T("ドロップ回数: %d回(今回%d個)\r\nワーキングセットサイズ: %d KB\r\n"), nDropCount, nFileCount, (int)(pmc.WorkingSetSize / 1024));	// wsprintfで回数・件数・メモリ使用量を埋め込んだ表示行を組み立てる.
				lstrcpy(tszDropInfo, tszHeader);	// lstrcpyでtszDropInfoに表示行をセット.

				// DragFinishでhDropを解放する.(これを呼ばないと, ドロップのたびにhDropが指すメモリが解放されずに残り続け, メモリリークになる.)
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
