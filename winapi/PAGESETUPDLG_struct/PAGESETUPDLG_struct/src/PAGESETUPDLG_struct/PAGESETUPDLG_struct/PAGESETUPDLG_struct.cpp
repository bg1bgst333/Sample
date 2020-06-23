// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <cstring>		// C文字列処理
#include <commctrl.h>	// コモンコントロール
#include <shlwapi.h>	// シェルAPI
// 独自のヘッダファイル
#include "resource.h"	// リソース

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理をするように定義したコールバック関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){
 
	// 変数の宣言
	HWND hWnd;		// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;		// ウィンドウメッセージ情報を格納するMSG構造体型変数msg.
	WNDCLASS wc;	// ウィンドウクラス情報をもつWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("PAGESETUPDLG_struct");					// ウィンドウクラス名は"PAGESETUPDLG_struct".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;							// ウィンドウプロシージャは独自の処理を定義したWindowProc.
	wc.hInstance = hInstance;								// インスタンスハンドルは_tWinMainの引数.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// アイコンはアプリケーション既定のもの.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// カーソルは矢印.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 背景は白ブラシ.
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MAINMENU);		// メニューにはIDR_MAINMENUをMAKEINTRESOURCEマクロで指定.
	wc.cbClsExtra = 0;										// 0でいい.
	wc.cbWndExtra = 0;										// 0でいい.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)){	// RegisterClassでウィンドウクラスを登録し, 0が返ったらエラー.
 
		// エラー処理
		MessageBox(NULL, _T("RegisterClass failed!"), _T("PAGESETUPDLG_struct"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)
 
	}

	// ウィンドウの作成.
	hWnd = CreateWindow(_T("PAGESETUPDLG_struct"), _T("PAGESETUPDLG_struct"), WS_OVERLAPPEDWINDOW, 100, 100, 640, 480, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"PAGESETUPDLG_struct"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.
 
		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("PAGESETUPDLG_struct"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)
 
	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.

	// メッセージループ
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessageでメッセージを取得, 戻り値が0より大きい間はループし続ける.
 
		// ウィンドウメッセージの送出
		TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.
		DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(この場合は独自に定義したWindowProc)に送出.

	}

	// プログラムの終了
	return (int)msg.wParam;	// 終了コード(msg.wParam)を戻り値として返す.
 
}

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// ウィンドウメッセージに対して独自の処理をするように定義したウィンドウプロシージャ.

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-casa文でuMsgの値ごとに処理を振り分ける.
 
		// ウィンドウの作成が開始された時.
		case WM_CREATE:		// ウィンドウの作成が開始された時.(uMsgがWM_CREATEの時.)
 
			// WM_CREATEブロック
			{

				// 変数の宣言
				HWND hEdit1;	// エディットコントロールのウィンドウハンドルhEdit1.
				HWND hEdit2;	// エディットコントロールのウィンドウハンドルhEdit2.
				LPCREATESTRUCT lpCS;	// CreateStruct構造体のポインタlpCS.
				TCHAR tszModulePath[MAX_PATH] = {0};	// tszModulePath(長さMAX_PATH)を{0}で初期化.

				// アプリケーションインスタンスハンドルの取得.
				lpCS = (LPCREATESTRUCT)lParam;	// lParamをLPCREATESTRUCTにキャストして, lpCSに格納.

				// エディットコントロールの作成.
				hEdit1 = CreateWindow(WC_EDIT, _T(""), WS_CHILD | WS_BORDER | WS_VISIBLE, 50, 50, 300, 30, hwnd, (HMENU)ID_EDIT1, lpCS->hInstance, NULL);	// CreateWindowのWC_EDITでエディットコントロールを作成.
				if (hEdit1 == NULL){	// hEdit1がNULLなら.

					// エラー処理.
					return -1;	// -1を返す.

				}
				hEdit2 = CreateWindow(WC_EDIT, _T(""), WS_CHILD | WS_BORDER | WS_VISIBLE | ES_AUTOHSCROLL, 50, 100, 300, 30, hwnd, (HMENU)ID_EDIT2, lpCS->hInstance, NULL);	// CreateWindowのWC_EDITでエディットコントロールを作成.
				if (hEdit2 == NULL){	// hEdit2がNULLなら.

					// エラー処理.
					return -1;	// -1を返す.

				}

				// 現在実行中の実行ファイルのフルパスを取得.
				//GetModuleFileName(NULL, tszModulePath, MAX_PATH);	// GetModuleFileNameでこの実行ファイルのフルパスを取得.

				// ファイル名の部分を取り除き, 所属するフォルダパスを取得する.
				//PathRemoveFileSpec(tszModulePath);	// PathRemoveFileSpecでファイル名の部分を取り除く.

				// "\test.pdf"を連結.
				//_tcscat(tszModulePath, _T("\\test.pdf"));	// _tcscatで"\test.pdf"を連結.

				// hEdit2にセット.
				//SetWindowText(hEdit2, tszModulePath);	// SetWindowTextでhEdit2にtszModulePathをセット.

				// ウィンドウ作成成功
				return 0;	// return文で0を返して, ウィンドウ作成成功とする.
 
			}
 
			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.
 
		// ウィンドウが破棄された時.
		case WM_DESTROY:	// ウィンドウが破棄された時.(uMsgがWM_DESTROYの時.)
 
			// WM_DESTROYブロック
			{

				// 終了メッセージの送信.
				PostQuitMessage(0);	// PostQuitMessageで終了コードを0としてWM_QUITメッセージを送信.(するとメッセージループのGetMessageの戻り値が0になるので, メッセージループから抜ける.)
 
			}
 
			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// 画面の描画を要求された時.
		case WM_PAINT:		// 画面の描画を要求された時.(uMsgがWM_PAINTの時.)
 
			// WM_PAINTブロック
			{

				// このブロックのローカル変数の宣言
				HDC hDC;			// デバイスコンテキストハンドルを格納するHDC型変数hDC.
				PAINTSTRUCT ps;		// ペイント情報を管理するPAINTSTRUCT構造体型の変数ps.

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にはデバイスコンテキストハンドルが返るので, hDCに格納.

				// ウィンドウの描画終了
				EndPaint(hwnd, &ps);	// EndPaintでこのウィンドウの描画処理を終了する.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// ウィンドウが閉じられた時.
		case WM_CLOSE:	// ウィンドウが閉じられた時.(uMsgがWM_CLOSEの時.)

			// WM_CLOSEブロック
			{

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりして, コマンドが発生した時.
		case WM_COMMAND:	// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりして, コマンドが発生した時.(uMsgがWM_COMMANDの時.)

			// WM_COMMANDブロック
			{

				// どのメニュー項目が選択されたかを判定する.
				switch (LOWORD(wParam)){	// LOWORD(wParam)で選択されたメニュー項目のIDが取得できるので, その値で判定する.

					// 取得したIDごとに処理を分岐.
					// Printが選択された時.
					case ID_ITEM_PRINT:

						// ID_ITEM_PRINTブロック
						{

							// 変数の宣言と初期化.
							PRINTDLG pd = {0};	// PRINTDLG構造体pdを0で初期化.
							PAGESETUPDLG psd = {0};	// PAGESETUPDLG構造体psdを0で初期化.

							// pdの初期設定
							pd.lStructSize = sizeof(PRINTDLG);	// PRINTDLG構造体pdを0で初期化.
							pd.hwndOwner = hwnd;	// hwndを指定.
							pd.Flags = PD_RETURNDC;	// pdのメンバとしてhDCを返す.

							// PrintDlgの表示.
							BOOL bRet = PrintDlg(&pd);	// PrintDlgにpdを渡して表示し, 戻り値をBOOLのbRetに格納.
							if (bRet){	// 印刷を押したらTRUE.

								// psdの初期設定
								psd.lStructSize = sizeof(PAGESETUPDLG);	// sizeofでPAGESETUPDLG構造体のサイズを指定.
								psd.hwndOwner = hwnd;		// hwndを指定.
								psd.Flags = PSD_INHUNDREDTHSOFMILLIMETERS | PSD_MARGINS;	// ミリ単位に設定, 余白の変更.
								psd.rtMargin.left = 10;		// 左端マージン10.
								psd.rtMargin.top = 20;		// 上端マージン20.
								psd.rtMargin.right = 30;	// 右端マージン30.
								psd.rtMargin.bottom = 40;	// 下端マージン40.

								// PageSetupDlgの表示.
								bRet = PageSetupDlg(&psd);	// PageSetupDlgにpsdを渡して表示し, 戻り値をbRetに格納.
								if (bRet){	// bRetがTRUE.
									MessageBox(NULL, _T("OK!"), _T("PAGESETUPDLG_struct"), MB_OK);	// MessageBoxで"OK!"とメッセージを表示.
								}
								else{	// bRetがFALSE.
									MessageBox(NULL, _T("Cancel!"), _T("PAGESETUPDLG_struct"), MB_OK);	// MessageBoxで"Cancel!"とメッセージを表示.
								}

								// 終了処理.
								DeleteDC(pd.hDC);	// DeleteDCでpd.hDCを削除.

							}

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// 上記以外の時.
					default:

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

				}

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// 上記以外の時.
		default:	// 上記以外の値の時の既定処理.
 
			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.
 
	}
 
	// あとは既定の処理に任せる.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// 戻り値も含めDefWindowProcに既定の処理を任せる.

}