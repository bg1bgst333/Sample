// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// C標準入出力
#include <commctrl.h>	// コモンコントロール
// 独自のヘッダファイル
#include "resource.h"	// リソース

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理をするように定義したコールバック関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数・配列の宣言・初期化
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージ情報を格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラス情報をもつWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("EM_LINEINDEX");					// ウィンドウクラス名は"EM_LINEINDEX".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;							// ウィンドウプロシージャは独自の処理を定義したWindowProc.
	wc.hInstance = hInstance;								// インスタンスハンドルは_tWinMainの引数.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// アイコンはアプリケーション既定のもの.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// カーソルは矢印.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 背景は白ブラシ.
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MAINMENU);		// IDR_MAINMENU.
	wc.cbClsExtra = 0;										// 0でいい.
	wc.cbWndExtra = 0;										// 0でいい.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)){	// RegisterClassでウィンドウクラスを登録し, 0が返ったらエラー.

		// エラー処理
		MessageBox(NULL, _T("RegisterClass Failure!"), _T("EM_LINEINDEX"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass Failure!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("EM_LINEINDEX"), _T("EM_LINEINDEX"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"EM_LINEINDEX"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow Failure!"), _T("EM_LINEINDEX"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow Failure!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.

	// メッセージループ
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessageでメッセージを取得, 戻り値が0より大きい間はループし続ける.

		// ウィンドウメッセージ処理
		TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.
		DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(この場合は独自に定義したWindowProc)に送出.

	}

	// プログラムの終了
	return (int)msg.wParam;	// 終了コード(msg.wParam)を戻り値として返す.

}

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// ウィンドウメッセージに対して独自の処理をするように定義したウィンドウプロシージャ.

	// スタティック変数の初期化.
	static HWND hEdit = NULL;	// エディットコントロールのウィンドウハンドルhEditをNULLで初期化.
	static HFONT hFont1 = NULL;	// 1つ目のフォントハンドルhFont1をNULLで初期化.
	static HFONT hFont2 = NULL;	// 2つ目のフォントハンドルhFont2をNULLで初期化.

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-casa文でuMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始された時.
		case WM_CREATE:		// ウィンドウの作成が開始された時.(uMsgがWM_CREATEの時.)

			// WM_CREATEブロック
			{

				// 変数の宣言
				LPCREATESTRUCT lpCS;	// CreateStruct構造体のポインタlpCS.

				// アプリケーションインスタンスハンドルの取得.
				lpCS = (LPCREATESTRUCT)lParam;	// lParamをLPCREATESTRUCTにキャストして, lpCSに格納.

				// エディットコントロールの作成.
				hEdit = CreateWindow(WC_EDIT, _T("Edit1"), WS_CHILD | WS_VISIBLE | WS_HSCROLL | WS_VSCROLL | ES_WANTRETURN | ES_MULTILINE | ES_AUTOHSCROLL | ES_AUTOVSCROLL, 50, 50, 200, 100, hwnd, (HMENU)(WM_APP + 1), lpCS->hInstance, NULL);	// CreateWindowのWC_EDITでエディットコントロール"Edit1"を作成.
				if (hEdit == NULL){	// hEditがNULLなら.

					// エラー処理.
					return -1;	// -1を返す.

				}

				// フォントの作成.
				hFont1 = CreateFont(30, 0, 0, 0, FW_REGULAR, FALSE, FALSE, FALSE, SHIFTJIS_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, _T("ＭＳ ゴシック"));	// CreateFontで"ＭＳ ゴシック"フォントのGDIオブジェクトを新規に作成し, hFont1に格納.(設定はデフォルトのものにしておく.)
				hFont2 = CreateFont(40, 0, 0, 0, FW_REGULAR, FALSE, FALSE, FALSE, SHIFTJIS_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, _T("ＭＳ 明朝"));	// CreateFontで"ＭＳ 明朝"フォントのGDIオブジェクトを新規に作成し, hFont2に格納.(設定はデフォルトのものにしておく.)

				// Edit1にhFont1をセット.
				SendMessage(hEdit, WM_SETFONT, (WPARAM)hFont1, 0);	// WM_SETFONTでhEditにhFont1をセット.

				// ウィンドウ作成成功
				return 0;	// return文で0を返して, ウィンドウ作成成功とする.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// ウィンドウが破棄された時.
		case WM_DESTROY:	// ウィンドウが破棄された時.(uMsgがWM_DESTROYの時.)

			// WM_DESTROYブロック
			{

				// フォントの破棄.
				if (hFont1 != NULL){	// hFont1がNULLでない.
					DeleteObject(hFont1);	// DeleteObjectでhFont1を破棄.
					hFont1 = NULL;	// hFont1にNULLをセット.
				}
				if (hFont2 != NULL){	// hFont2がNULLでない.
					DeleteObject(hFont2);	// DeleteObjectでhFont2を破棄.
					hFont2 = NULL;	// hFont2にNULLをセット.
				}

				// 終了メッセージの送信.
				PostQuitMessage(0);	// PostQuitMessageで終了コードを0としてWM_QUITメッセージを送信.(するとメッセージループのGetMessageの戻り値が0になるので, メッセージループから抜ける.)

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりした時.
		case WM_COMMAND:	// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりした時.(uMsgがWM_COMMANDの時.)

			// WM_COMMANDブロック
			{

				// どのメニュー項目が選択されたかを判定する.
				switch (LOWORD(wParam)){	// LOWORD(wParam)で選択されたメニュー項目のIDが取得できるので, その値で判定する.

					// 取得したIDごとに処理を分岐.
					// Item1-1が選択された時.
					case ID_ITEM_1_1:

						// ID_ITEM_1_1ブロック
						{

							// Edit1にhFont1をセット.
							SendMessage(hEdit, WM_SETFONT, (WPARAM)hFont1, 0);	// WM_SETFONTでhEditにhFont1をセット.
							
							// 0を返す.
							return 0;	// 処理したので戻り値として0を返す.

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// Item1-2が選択された時.
					case ID_ITEM_1_2:

						// ID_ITEM_1_2ブロック
						{

							// Edit1にhFont2をセット.
							SendMessage(hEdit, WM_SETFONT, (WPARAM)hFont2, 0);	// WM_SETFONTでhEditにhFont2をセット.

							// 0を返す.
							return 0;	// 処理したので戻り値として0を返す.

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// Item2-1が選択された時.
					case ID_ITEM_2_1:

						// ID_ITEM_2_1ブロック
						{

							// フォントハンドルと文字の高さを取得.
							HFONT hFont = (HFONT)SendMessage(hEdit, WM_GETFONT, NULL, NULL);	// WM_GETFONTでhFontを取得.
							HDC hDC = GetDC(hEdit);	// hDC取得.
							HFONT hOld = (HFONT)SelectObject(hDC, hFont);	// hDCでhFontを選択.
							TEXTMETRIC tm = {0};	// TEXTMETRIC構造体tmを{0}で初期化.
							GetTextMetrics(hDC, &tm);	// GetTextMetricsでtmを取得.
							TCHAR tszText[128] = {0};	// TCHAR文字配列tszText(長さ128)を{0}で初期化.
							_stprintf(tszText, _T("hFont = 0x%08x, tm.tmHeight = %d\n"), hFont, tm.tmHeight);	// hFontとtm.tmHeightを文字列に変換.
							MessageBox(hwnd, tszText, _T("EM_LINEINDEX"), MB_OK);	// tszTextを表示.
							SelectObject(hDC, hOld);	// hDCでhOld選択.
							ReleaseDC(hEdit, hDC);	// hDC解放.

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// Item2-2が選択された時.
					case ID_ITEM_2_2:

						// ID_ITEM_2_2ブロック
						{

							// キャレットの位置を取得.
							POINT pt = {0};	// POINT構造体ptを{0}で初期化.
							GetCaretPos(&pt);	// GetCaretPosで位置ptを取得.
							TCHAR tszPoint[128] = {0};	// TCHAR文字配列tszPoint(長さ128)を{0}で初期化.
							_stprintf(tszPoint, _T("(%d, %d)"), pt.x, pt.y);	// (pt.x, pt.y)をtszPointに変換.
							MessageBox(hwnd, tszPoint, _T("EM_LINEINDEX"), MB_OK);	// tszPointを表示.

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// Item3-1が選択された時.
					case ID_ITEM_3_1:

						// ID_ITEM_3_1ブロック
						{

							// キャレットの位置の文字に関する情報を取得.
							POINT pt = {0};	// POINT構造体ptを{0}で初期化.
							GetCaretPos(&pt);	// GetCaretPosで位置ptを取得.
							DWORD dwPos = (DWORD)SendMessage(hEdit, EM_CHARFROMPOS, 0, MAKELPARAM(pt.x, pt.y));	// 座標ptからキャレットの位置の文字に関する情報dwPosを取得.
							WORD wRow = HIWORD(dwPos);	// HIWORD(dwPos)は何行目かを示すwRow.
							WORD wAllLen = LOWORD(dwPos);	// LOWORD(dwPos)はキャレットまでの総文字数wAllLen.
							TCHAR tszPos[128] = {0};	// TCHAR文字配列tszPos(長さ128)を{0}で初期化.
							_stprintf(tszPos, _T("wRow = %d, wAllLen = %d"), wRow, wAllLen);	// wRow, wAllLenをtszPosに変換.
							MessageBox(hwnd, tszPos, _T("EM_LINEINDEX"), MB_OK);	// tszPosを表示.

							// 指定した行(ここではキャレットのある行を指定)の先頭までの総文字数を取得.
							WORD wRowStart = (WORD)SendMessage(hEdit, EM_LINEINDEX, wRow, 0);	// 指定行の先頭までの総文字数wRowStart.
							WORD wCol = wAllLen - wRowStart;	// その行の何列目か(wCol)はwAllLenからwRowStartを引いたもの.
							TCHAR tszResult[128] = {0};	// TCHAR文字配列tszResult(長さ128)を{0}で初期化.
							_stprintf(tszResult, _T("wRowStart = %d, wCol = %d"), wRowStart, wCol);	// wRowStart, wColをtszResultに変換.
							MessageBox(hwnd, tszResult, _T("EM_LINEINDEX"), MB_OK);	// tszResultを表示.

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// 上記以外の時.
					default:	// 上記以外の値の時の既定処理.

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

				}
	
				// 既定の処理へ向かう.
				break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

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