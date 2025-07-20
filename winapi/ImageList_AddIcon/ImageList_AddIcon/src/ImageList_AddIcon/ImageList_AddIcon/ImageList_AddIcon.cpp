// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <commctrl.h>	// コモンコントロール

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウプロシージャ

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数・配列の宣言・初期化
	HWND hWnd;					// ウィンドウハンドルhWnd.
	MSG msg;					// メッセージmsg.
	WNDCLASS wc;				// ウィンドウクラスwc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("ImageList_AddIcon");					// ウィンドウクラス名"ImageList_AddIcon".
	wc.style = CS_HREDRAW | CS_VREDRAW;							// スタイルCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;								// ウィンドウプロシージャWindowProc.
	wc.hInstance = hInstance;									// インスタンスhInstance.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);					// アイコンはアプリケーション既定のもの.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);					// カーソルIDC_ARROW.
	wc.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);		// 背景GRAY_BRUSH.
	wc.lpszMenuName = NULL;										// メニューはなし.
	wc.cbClsExtra = 0;											// 0.
	wc.cbWndExtra = 0;											// 0.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)){	// RegisterClassでウィンドウクラスを登録.

		// エラー処理
		return -1;	// 異常終了(-1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("ImageList_AddIcon"), _T("ImageList_AddIcon"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowでウィンドウ作成.
	if (hWnd == NULL){

		// エラー処理
		return -2;	// 異常終了(-2)

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);

	// メッセージループ
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessageでメッセージ取得.

		// ウィンドウメッセージの送出
		TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.
		DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャに送出.

	}

	// プログラムの終了
	return (int)msg.wParam;	// msg.wParamを返す.

}

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

	// ウィンドウプロシージャ全体で使われるスタティック変数の宣言.
	static HIMAGELIST hImageList;	// イメージリストハンドルを格納するHIMAGELIST型スタティック変数hImageList.

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// uMsgごとに処理振り分け.

		// ウィンドウの作成が開始された時.
		case WM_CREATE:

			// WM_CREATEブロック
			{

				// このブロックのローカル変数の宣言
				LPCREATESTRUCT lpcs;	// lParamから渡されたCREATESTRUCTへのポインタを格納するlpcs.

				InitCommonControls();

				// lParamをlpcsに渡す.
				lpcs = (LPCREATESTRUCT)lParam; // lParamをLPCREATESTRUCTにキャストしてlpcsに格納.

				// イメージリストの作成
				hImageList = ImageList_Create(32, 32, ILC_COLOR24 | ILC_MASK, 2, 1);	// ImageList_Createでイメージリストを作成.(ILC_MASKを付けないとマスクが有効にならない.)
				if (hImageList == NULL){	// hImageListがNULLなら失敗.

					// エラー処理
					MessageBox(hwnd, _T("ImageList_Create failed!"), _T("ImageList_AddIcon"), MB_OK | MB_ICONHAND);	// MessageBoxで"ImageList_Create failed!"とエラーメッセージを表示.
					return -1;	// 異常終了なので-1を返して, ウィンドウ生成失敗とする.

				}

				// イメージリストへの追加.
				HICON hIcon1 = LoadIcon(NULL, IDI_QUESTION);	// LoadIconでIDI_QUESTIONをロード.
				HICON hIcon2 = LoadIcon(NULL, IDI_EXCLAMATION);	// LoadIconでIDI_EXCLAMATIONをロード.
				ImageList_AddIcon(hImageList, hIcon1);	// ImageList_AddIconでhImageListにhIcon1を追加.
				ImageList_AddIcon(hImageList, hIcon2);	// ImageList_AddIconでhImageListにhIcon2を追加.

				// 描画の更新.
				InvalidateRect(hwnd, NULL, TRUE);

			}

			// 既定の処理へ向かう.
			break;

		// ウィンドウが破棄された時.
		case WM_DESTROY:

			// WM_DESTROYブロック
			{

				// イメージリストの終了処理
				if (hImageList != NULL){	// hImageListがNULLでない場合.

					// イメージリストの破棄
					ImageList_Destroy(hImageList);
					hImageList = NULL;

				}

				// 終了メッセージの送信.
				PostQuitMessage(0);	// PostQuitMessageで終了コードを0とするWM_QUITを送信.

			}

			// 既定の処理へ向かう.
			break;

		// 描画要求された時.
		case WM_PAINT:

			// WM_PAINTブロック
			{

				// 描画開始.
				PAINTSTRUCT ps = {0};
				HDC hPaintDC = BeginPaint(hwnd, &ps);

				// 描画.
				int c = ImageList_GetImageCount(hImageList);	// ImageList_GetImageCountでイメージ数を取得し, cに格納.
				for (int i = 0; i < c; i++){	// cの分だけ繰り返す.
					ImageList_Draw(hImageList, i, hPaintDC, 50 + (32 * i), 50, ILD_NORMAL);	// ImageList_Drawでiを(50 + (32 * i), 50)に描画.
				}

				// 描画終了.
				EndPaint(hwnd, &ps);

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.


		// 上記以外の時.
		default:

			// 既定の処理へ向かう.
			break;

	}

	// 既定の処理に任せる.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// DefWindowProcを呼び, 戻り値をそのまま返す.

}