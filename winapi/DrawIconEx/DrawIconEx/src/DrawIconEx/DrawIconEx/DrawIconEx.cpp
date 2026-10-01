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
	wc.lpszClassName = _T("DrawIconEx");							// ウィンドウクラス名は"DrawIconEx".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("DrawIconEx"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("DrawIconEx"), _T("DrawIconEx"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 620, 360, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"DrawIconEx"ウィンドウクラスのウィンドウを作成.(拡大表示も入るので少し広めのサイズを指定.)
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("DrawIconEx"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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
	static int iStep = 0;	// 現在どのパターンを表示しているかを表すstatic変数iStep.(0?3の4パターン.)

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-case文でuMsgの値ごとに処理を振り分ける.

		// キーが押されたとき.
		case WM_KEYDOWN:	// キーが押されたとき.(uMsgがWM_KEYDOWNの場合.)

			// WM_KEYDOWNブロック
			{

				// SPACEキーが押された場合のみ処理する.
				if (wParam == VK_SPACE){	// wParamがVK_SPACEの場合.

					// iStepを1つ進め, 4パターンを巡回させる.
					iStep = (iStep + 1) % 4;	// 4で割った余りにすることで, 0→1→2→3→0→...と巡回する.

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
				HICON hIcon;		// 描画するアイコンのハンドルを格納するHICON型変数hIcon.
				int cxSize;			// 今回描画する幅を格納するint型変数cxSize.
				int cySize;			// 今回描画する高さを格納するint型変数cySize.
				UINT diFlags;		// 今回描画するフラグを格納するUINT型変数diFlags.
				TCHAR tszInfo[256];	// 案内文+現在のパターン説明を組み立てるTCHAR型配列tszInfo.

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にはデバイスコンテキストハンドルが返るので, hDCに格納.

				// iStepの値に応じて, 描画サイズ・フラグを切り替える.
				switch (iStep){	// iStepの値ごとに処理を振り分ける.

					case 0:	// 標準サイズ(32x32)でそのまま描画.

						cxSize = 32;	// 幅32.
						cySize = 32;	// 高さ32.
						diFlags = DI_NORMAL;	// DI_NORMAL(通常通り, 画像+マスクの両方を描画).
						wsprintf(tszInfo, _T("SPACEキーでパターンを切り替えます。\r\n現在: DI_NORMAL, 32x32(標準サイズそのまま)"));	// 案内文を組み立てる.
						break;

					case 1:	// 拡大サイズ(64x64)で描画.(DrawIconExならではの, サイズ指定できる機能.)

						cxSize = 64;	// 幅64.
						cySize = 64;	// 高さ64.
						diFlags = DI_NORMAL;	// DI_NORMAL.
						wsprintf(tszInfo, _T("SPACEキーでパターンを切り替えます。\r\n現在: DI_NORMAL, 64x64(拡大。DrawIconは実寸固定だがDrawIconExはサイズ指定できる)"));	// 案内文を組み立てる.
						break;

					case 2:	// DI_IMAGEのみ(マスクを無視し, カラー画像部分だけ描画).

						cxSize = 64;	// 幅64.
						cySize = 64;	// 高さ64.
						diFlags = DI_IMAGE;	// DI_IMAGE(カラー画像部分のみ描画, マスクは無視).
						wsprintf(tszInfo, _T("SPACEキーでパターンを切り替えます。\r\n現在: DI_IMAGEのみ, 64x64(マスクを無視してカラー画像部分だけ描画)"));	// 案内文を組み立てる.
						break;

					default:	// case 3. DI_MASKのみ(マスク部分だけ描画, シルエットになる).

						cxSize = 64;	// 幅64.
						cySize = 64;	// 高さ64.
						diFlags = DI_MASK;	// DI_MASK(マスク部分のみ描画).
						wsprintf(tszInfo, _T("SPACEキーでパターンを切り替えます。\r\n現在: DI_MASKのみ, 64x64(マスク部分だけ描画, シルエットになる)"));	// 案内文を組み立てる.
						break;

				}

				// 案内文を表示する.
				GetClientRect(hwnd, &rcClient);	// GetClientRectでクライアント領域のサイズを取得.
				rcText = rcClient;					// rcTextにrcClientをコピー.
				InflateRect(&rcText, -20, -20);	// InflateRectで少し内側に余白をとる.(既存トピックのInflateRectを流用.)
				DrawText(hDC, tszInfo, -1, &rcText, DT_LEFT | DT_TOP | DT_WORDBREAK);	// DrawTextで案内文を表示.

				// アイコンを取得し, DrawIconExで描画する.(これが今回の主役.)
				hIcon = LoadIcon(NULL, IDI_APPLICATION);	// LoadIconでシステム共有のアプリケーションアイコンを取得し, hIconに格納.(共有リソースなのでDestroyIconで解放してはいけない.)
				DrawIconEx(hDC, 50, 100, hIcon, cxSize, cySize, 0, NULL, diFlags);	// DrawIconExでhDCの(50, 100)の位置に, cxSize x cySizeのサイズ・diFlagsの指定でhIconを描画する.(istepIfAniCurは0, hbrFlickerFreeDrawはNULL(未使用).)

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
