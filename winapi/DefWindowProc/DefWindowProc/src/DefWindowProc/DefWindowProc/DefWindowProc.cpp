// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理をするように定義したコールバンク関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;			// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;			// ウィンドウメッセージ情報を格納するMSG構造体型変数msg.
	WNDCLASS wc;		// ウィンドウクラス情報をもつWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("DefWindowProc");					// ウィンドウクラス名は"DefWindowProc".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;							// ウィンドウプロシージャは独自の処理を定義したWindowProc.
	wc.hInstance = hInstance;								// インスタンスハンドルは_tWinMainの引数.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// アイコンはアプリケーション既定のもの.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// カーソルは矢印.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 背景は白ブラシ.
	wc.lpszMenuName = NULL;									// メニューはなし.
	wc.cbClsExtra = 0;										// 0でいい.
	wc.cbWndExtra = 0;										// 0でいい.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)){	// RegisterClassでウィンドウクラスを登録し, 0が返ったらエラー.

		// エラー処理
		MessageBox(NULL, _T("RegisterClass failed!"), _T("DefWindowProc"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("DefWindowProc"), _T("DefWindowProc"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"DefWindowProc"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("DefWindowProc"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.

	// メッセージループ
	while (TRUE){	// 常にTRUE(真)で, 以下のbreak以外では抜けない.

		// ウィンドウメッセージの取得
		GetMessage(&msg, NULL, 0, 0);	// GetMessageでウィンドウメッセージを取得.
		if (msg.message == WM_NCLBUTTONDOWN && msg.wParam == HTCLOSE){	// もし, ウィンドウメッセージがWM_NCLBUTTONDOWN(非クライアント領域でマウスの左ボタンが押された)かつHTCLOSE(閉じるボタン上)のとき.

			// メッセージループの終了
			break;	// breakでメッセージループを抜ける.

		}

		// ウィンドウメッセージの送出
		DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(この場合は独自に定義したWindowProc)に送出.

	}

	// ウィンドウの破棄
	DestroyWindow(hWnd);	// DestroyWindowでウィンドウを破棄.

	// プログラムの終了
	return 0;

}

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// ウィンドウメッセージに対して独自の処理をするように定義したウィンドウプロシージャ.

	// static変数の宣言
	// WindowProcで返す戻り値のパターンiPattern.
	// 1: WM_CREATE, それ以外, ともにDefWindowProc.
	// 2: WM_CREATEで0, それ以外でDefWindowProc.
	// 3: WM_CREATEでDefWindowProc, それ以外で0.
	// 4: WM_CREATE, それ以外, ともに0.
	static int iPattern;	// 上記パターンの値を格納するstaticなint型変数iPattern.(初期値はstaticなので0.)

	// パターンの選択
	if (uMsg == WM_CREATE && iPattern == 0){	// パターンが決まっていない場合.
		int iRet = MessageBox(hwnd, _T("Pattern1?"), _T("DefWindowProc"), MB_YESNO | MB_ICONQUESTION);	// MB_YESNOなMessageBoxで"Pattern1?"と表示し, Pattern1かどうかを選択させる.
		if (iRet == IDYES){	// "はい"のとき.
			iPattern = 1;	// iPatternを1にセット.
		}
		else{	// "いいえ"のとき.
			iRet = MessageBox(hwnd, _T("Pattern2?"), _T("DefWindowProc"), MB_YESNO | MB_ICONQUESTION);	// MB_YESNOなMessageBoxで"Pattern2?"と表示し, Pattern2かどうかを選択させる.
			if (iRet == IDYES){	// "はい"のとき.
				iPattern = 2;	// iPatternを2にセット.
			}
			else{	// "いいえ"のとき.
				iRet = MessageBox(hwnd, _T("Pattern3?"), _T("DefWindowProc"), MB_YESNO | MB_ICONQUESTION);	// MB_YESNOなMessageBoxで"Pattern3?"と表示し, Pattern3かどうかを選択させる.
				if (iRet == IDYES){	// "はい"のとき.
					iPattern = 3;	// iPatternを3にセット.
				}
				else{	// "いいえ"のとき.
					iPattern = 4;	// iPatternを4にセット.
				}
			}
		}
	}

	// メッセージの処理
	if (iPattern == 1){	// iPatternが1のとき.
		return DefWindowProc(hwnd, uMsg, wParam, lParam);	// 常にDefWindowProcの戻り値を返す.
	}
	else if (iPattern == 2){	// iPatternが2のとき.
		if (uMsg == WM_CREATE){	// WM_CREATEのとき.
			return 0;	// 0を返す.
		}
		else{	// それ以外.
			return DefWindowProc(hwnd, uMsg, wParam, lParam);	// DefWindowProcの戻り値を返す.
		}
	}
	else if (iPattern == 3){	// iPatternが3のとき.
		if (uMsg == WM_CREATE){	// WM_CREATEのとき.
			return DefWindowProc(hwnd, uMsg, wParam, lParam);	// DefWindowProcの戻り値を返す.
		}
		else{	// それ以外.
			return 0;	// 0を返す.
		}
	}
	else if (iPattern == 4){	// iPatternが4のとき.
		return 0;	// 常に0を返す.
	}
	else{	// それ以外のとき.(iPatternが0のときなど.)
		return DefWindowProc(hwnd, uMsg, wParam, lParam);	// 常にDefWindowProcの戻り値を返す.
	}

}