// ヘッダファイルのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <windowsx.h>	// マクロ
#include <tchar.h>		// TCHAR型
#include <ole2.h>		// FORMATETC

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理ができるように定義したコールバック関数WindowProc.
LPCTSTR ClipFormatToText(CLIPFORMAT cf);											// cfFormatを分かりやすい文字列に変換する関数ClipFormatToTextのプロトタイプ宣言.
LPCTSTR AspectToText(DWORD dwAspect);												// dwAspectを分かりやすい文字列に変換する関数AspectToTextのプロトタイプ宣言.
LPCTSTR TymedToText(DWORD tymed);													// tymedを分かりやすい文字列に変換する関数TymedToTextのプロトタイプ宣言.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージを格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラスを格納するWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("FORMATETC");				// ウィンドウクラス名は"FORMATETC".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("FORMATETC"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("FORMATETC"), _T("FORMATETC"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"FORMATETC"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("FORMATETC"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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

// ClipFormatToText関数の定義.(代表的なcfFormatだけ文字列に変換する.)
LPCTSTR ClipFormatToText(CLIPFORMAT cf){

	// cfの値で分岐する.
	switch (cf){	// switch文でcfの値ごとに分岐.

		case CF_TEXT:	return _T("CF_TEXT");		// テキスト形式.
		case CF_BITMAP:	return _T("CF_BITMAP");	// ビットマップ形式.
		default:		return _T("(other)");		// その他.

	}

}

// AspectToText関数の定義.(代表的なdwAspectだけ文字列に変換する.)
LPCTSTR AspectToText(DWORD dwAspect){

	// dwAspectの値で分岐する.
	switch (dwAspect){	// switch文でdwAspectの値ごとに分岐.

		case DVASPECT_CONTENT:	return _T("DVASPECT_CONTENT");	// 通常の中身.
		default:				return _T("(other)");			// その他.

	}

}

// TymedToText関数の定義.(代表的なtymedだけ文字列に変換する.)
LPCTSTR TymedToText(DWORD tymed){

	// tymedの値で分岐する.
	switch (tymed){	// switch文でtymedの値ごとに分岐.

		case TYMED_HGLOBAL:	return _T("TYMED_HGLOBAL");	// グローバルメモリで受け渡す.
		case TYMED_GDI:			return _T("TYMED_GDI");			// GDIオブジェクト(HBITMAP等)で受け渡す.
		default:				return _T("(other)");			// その他.

	}

}

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// ウィンドウメッセージに対して独自の処理ができるように定義したウィンドウプロシージャ.

	// static変数の宣言
	static int nState = 0;	// 表示するFORMATETCのパターンを覚えておくstatic変数nState.(0=まだ未表示, 1=CF_TEXT版, 2=CF_BITMAP版.)

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-case文でuMsgの値ごとに処理を振り分ける.

		// キーが押されたとき.
		case WM_KEYDOWN:	// キーが押されたとき.(uMsgがWM_KEYDOWNの場合.)

			// WM_KEYDOWNブロック
			{

				// SPACEキーが押された場合のみ処理する.
				if (wParam == VK_SPACE){	// wParamがVK_SPACEの場合.

					// このブロックのローカル変数の宣言
					FORMATETC fe;			// 組み立てるFORMATETC構造体型変数fe.
					TCHAR tszTitle[256];	// タイトルバーに表示する文字列を組み立てるTCHAR型配列tszTitle.

					// SPACEキーを押すたびに, CF_TEXT版とCF_BITMAP版を交互に切り替える.
					nState = (nState % 2) + 1;	// nStateを1→2→1→2...と交互に切り替える.

					if (nState == 1){	// 1回目(またはCF_TEXT版)の場合.

						// CF_TEXT形式(テキストをグローバルメモリで受け渡す)のFORMATETCを組み立てる.
						fe.cfFormat = CF_TEXT;			// cfFormatにCF_TEXTをセット.
						fe.ptd = NULL;					// ptdはNULL(特定のターゲットデバイスを指定しない).
						fe.dwAspect = DVASPECT_CONTENT;	// dwAspectはDVASPECT_CONTENT(通常の中身)をセット.
						fe.lindex = -1;					// lindexは-1(ページ等の区別が無いことを示す)をセット.
						fe.tymed = TYMED_HGLOBAL;		// tymedはTYMED_HGLOBAL(グローバルメモリ)をセット.

					}
					else{	// 2回目(CF_BITMAP版)の場合.

						// CF_BITMAP形式(ビットマップをGDIオブジェクトで受け渡す)のFORMATETCを組み立てる.
						fe.cfFormat = CF_BITMAP;		// cfFormatにCF_BITMAPをセット.
						fe.ptd = NULL;					// ptdはNULL.
						fe.dwAspect = DVASPECT_CONTENT;	// dwAspectはDVASPECT_CONTENT(通常の中身)をセット.
						fe.lindex = -1;					// lindexは-1をセット.
						fe.tymed = TYMED_GDI;			// tymedはTYMED_GDI(GDIオブジェクト)をセット.

					}

					// 組み立てたFORMATETCの各フィールドをタイトルバーに表示する.
					wsprintf(tszTitle, _T("FORMATETC (cfFormat=%s ptd=%s dwAspect=%s lindex=%d tymed=%s)"), ClipFormatToText(fe.cfFormat), (fe.ptd == NULL) ? _T("NULL") : _T("(non-null)"), AspectToText(fe.dwAspect), fe.lindex, TymedToText(fe.tymed));	// wsprintfで各フィールドを埋め込んだ文字列を組み立てる.
					SetWindowText(hwnd, tszTitle);	// SetWindowTextでタイトルバーを書き換える.

				}

			}

			// 次の処理へ続く.
			break;	// breakで抜けても, 次の処理(DefWindowProc)へ続く.

		// ウィンドウが破棄されたとき.
		case WM_DESTROY:	// ウィンドウが破棄されたとき.(uMsgがWM_DESTROYの場合.)

			// WM_DESTROYブロック
			{

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

				// 案内文を表示する.
				GetClientRect(hwnd, &rcClient);	// GetClientRectでクライアント領域のサイズを取得.
				InflateRect(&rcClient, -20, -20);	// InflateRectで少し内側に余白をとる.
				DrawText(hDC, _T("SPACEキーで、CF_TEXT版とCF_BITMAP版のFORMATETCを交互に組み立て、各フィールド(cfFormat/ptd/dwAspect/lindex/tymed)の値をタイトルバーに表示します。"), -1, &rcClient, DT_LEFT | DT_TOP | DT_WORDBREAK);	// DrawTextで案内文を折り返しながら表示.

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
