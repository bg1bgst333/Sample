// ヘッダのインクルード
// 独自のヘッダ
#include "Window.h"	// CWindowクラス

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理をするように定義したコールバック関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd1;		// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd1.
	HWND hWnd2;		// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd2.
	MSG msg;		// ウィンドウメッセージ情報を格納するMSG構造体型変数msg.
	WNDCLASS wc;	// ウィンドウクラス情報をもつWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("CREATESTRUCT");					// ウィンドウクラス名は"CREATESTRUCT".
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
		MessageBox(NULL, _T("RegisterClass Failure!"), _T("CREATESTRUCT"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass Failure!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// CWindowオブジェクトの作成.
	CWindow *pWindow1 = new CWindow();	// CWindowオブジェクトを作成し, pWindow1に格納.

	// ウィンドウの作成
	hWnd1 = CreateWindow(_T("CREATESTRUCT"), _T("Window1"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, pWindow1);	// CreateWindowで, 上で登録した"CREATESTRUCT"ウィンドウクラスのウィンドウを作成.(最後にCWindowオブジェクトポインタpWindow1を渡すと, それと紐付く.)
	if (hWnd1 == NULL) {	// ウィンドウの作成に失敗したとき.

		// エラー処理
		delete pWindow1;	// deleteでpWindow1を解放.
		MessageBox(NULL, _T("CreateWindow Failure!"), _T("CREATESTRUCT"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow Failure!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)

	}

	// CWindowオブジェクトの作成.
	CWindow *pWindow2 = new CWindow();	// CWindowオブジェクトを作成し, pWindow2に格納.

	// ウィンドウの作成
	hWnd2 = CreateWindow(_T("CREATESTRUCT"), _T("Window2"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, pWindow2);	// CreateWindowで, 上で登録した"CREATESTRUCT"ウィンドウクラスのウィンドウを作成.(最後にCWindowオブジェクトポインタpWindow2を渡すと, それと紐付く.)
	if (hWnd2 == NULL) {	// ウィンドウの作成に失敗したとき.

		// エラー処理
		delete pWindow2;	// deleteでpWindow2を解放.
		delete pWindow1;	// deleteでpWindow1を解放.
		MessageBox(NULL, _T("CreateWindow Failure!"), _T("CREATESTRUCT"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow Failure!"とエラーメッセージを表示.
		return -3;	// 異常終了(3)

	}

	// ウィンドウの表示
	ShowWindow(hWnd1, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.
	ShowWindow(hWnd2, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.

	// メッセージループ
	while (GetMessage(&msg, NULL, 0, 0) > 0) {	// GetMessageでメッセージを取得, 戻り値が0より大きい間はループし続ける.

		// ウィンドウメッセージ処理
		TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.
		DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(この場合は独自に定義したWindowProc)に送出.

	}

	// CWindowオブジェクトの破棄.
	delete pWindow2;	// deleteでpWindow2を解放.
	delete pWindow1;	// deleteでpWindow1を解放.

	// プログラムの終了
	return (int)msg.wParam;	// 終了コード(msg.wParam)を戻り値として返す.

}

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// ウィンドウメッセージに対して独自の処理をするように定義したウィンドウプロシージャ.

	// ポインタの初期化.
	CWindow *pWindow = NULL;	// CWindowオブジェクトポインタpWindowをNULLで初期化.

	// ウィンドウメッセージの処理.
	switch (uMsg){	// uMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始された時.
		case WM_CREATE:

			// WM_CREATEブロック
			{

				// ポインタの初期化
				CREATESTRUCT *lpCreateStruct = NULL;	// CREATESTRUCT構造体へのポインタlpCreateStructをNULL.

				// lParamからlpCreateStructを取り出す.
				lpCreateStruct = (LPCREATESTRUCT)lParam;	// lParamをLPCREATESTRUCT型にキャストしてlpCreateStructに格納.
				if (lpCreateStruct != NULL){	// lpCreateStructがNULLでなければ.

					// CWindowポインタpWindowの取り出し.
					pWindow = (CWindow *)lpCreateStruct->lpCreateParams;	// lpCreateStruct->lpCreateParamsはCWindowオブジェクトポインタにキャストし, pWindowに格納.

					// ウィンドウ名の格納.
					pWindow->m_wstrWindowName = lpCreateStruct->lpszName;	// lpCreateStruct->lpszNameをpWindow->m_wstrWindowNameに格納.

					// ウィンドウマップへの登録.
					CWindow::m_mapWindowMap.insert(std::pair<HWND, CWindow *>(hwnd, pWindow));	// m_mapWindowMapにhwndとpWindowのペアを登録.
					
				}

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて既定の処理へ向かう.

		// それ以外の時.
		default:

			// defaultブロック
			{

				// hwndでCWindowオブジェクトポインタが引けたら, pWindowに格納.
				if (CWindow::m_mapWindowMap.find(hwnd) != CWindow::m_mapWindowMap.end()){	// findでキーをhwndとするCWindowオブジェクトポインタが見つかったら.
					pWindow = CWindow::m_mapWindowMap[hwnd];	// pWindowにhwndで引けるCWindowオブジェクトポインタを格納.
				}

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて既定の処理へ向かう.

	}

	// CWindowオブジェクトポインタが取得できなかった場合, 取得できた場合で分ける.
	if (pWindow == NULL){	// pWindowがNULL

		// DefWindowProcに任せる.
		return DefWindowProc(hwnd, uMsg, wParam, lParam);	// DefWindowProcに引数をそのまま渡して, DefWindowProcの戻り値をそのまま返す.

	}
	else{	// pWindowがNULLでない時.

		// そのCWindowオブジェクトのWindowProcに渡す.
		return pWindow->WindowProc(hwnd, uMsg, wParam, lParam);	// pWindow->WindowProcに引数をそのまま渡して, WindowProcの戻り値をそのまま返す.

	}

}