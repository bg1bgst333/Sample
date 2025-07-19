// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <commctrl.h>	// コモンコントロール
// 独自のヘッダファイル
#include "resource.h"	// リソースID

// グローバル変数.
HWND g_hFindDlg = NULL;	// 検索ダイアログハンドルg_hFindDlgをNULLで初期化.
TCHAR g_tszFindWhat[80] = {0};	// 検索文字列g_tszFindWhatを{0}で初期化.
FINDREPLACE g_fr = {0};	// FINDREPLACE構造体変数g_frを{0}で初期化.
int iSearchStart = 0;	// 検索開始位置iSearchStartを0で初期化.

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウプロシージャ
void DoFindText(HWND hwnd);	// FindTextを実行する関数DoFindText
void FindNext(HWND hwnd, HWND hEdit);	// 次の一致文字列を探す関数FindNext

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数・配列の宣言・初期化
	HWND hWnd;					// ウィンドウハンドルhWnd.
	MSG msg;					// メッセージmsg.
	WNDCLASS wc;				// ウィンドウクラスwc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("EM_SCROLLCARET");					// ウィンドウクラス名"EM_SCROLLCARET".
	wc.style = CS_HREDRAW | CS_VREDRAW;							// スタイルCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;								// ウィンドウプロシージャWindowProc.
	wc.hInstance = hInstance;									// インスタンスhInstance.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);					// アイコンはアプリケーション既定のもの.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);					// カーソルIDC_ARROW.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		// 背景WHITE_BRUSH.
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MAINMENU);			// メニューにはIDR_MAINMENUをMAKEINTRESOURCEマクロで指定.
	wc.cbClsExtra = 0;											// 0.
	wc.cbWndExtra = 0;											// 0.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)){	// RegisterClassでウィンドウクラスを登録.

		// エラー処理
		return -1;	// 異常終了(-1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("EM_SCROLLCARET"), _T("EM_SCROLLCARET"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowでウィンドウ作成.
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

	// スタティック変数の宣言
	static CHOOSEFONT cf = {0};	// CHOOSEFONT構造体cfを{0}で初期化.
	static LOGFONT lf = {0};	// LOGFONT構造体lfを{0}で初期化.
	static UINT uMessage;	// RegisterWindowMessageの戻り値uMessage.
	static TCHAR tszReplace[80] = {0};	// 置換する文字列tszReplace(長さ80)を{0}で初期化.
	static HWND hEdit = NULL;	// エディットコントロールのウィンドウハンドルhEditをNULLで初期化.

	// 登録済みメッセージが来た場合.
	if (uMsg == uMessage){
		LPFINDREPLACE lpFR = (LPFINDREPLACE)lParam;
		if (lpFR->Flags & FR_FINDNEXT){	// 次を検索を押された時.
			FindNext(hwnd, hEdit);
		}
		if (lpFR->Flags & FR_DIALOGTERM){	// ダイアログを閉じられた時.
			g_hFindDlg = NULL;
		}
		return 0;	// 0を返す.
	}

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// uMsgごとに処理振り分け.

		// ウィンドウの作成が開始された時.
		case WM_CREATE:

			// WM_CREATEブロック
			{

				// CHOOSEFONTの初期化.
				cf.lStructSize = sizeof(CHOOSEFONT);
				cf.hwndOwner = hwnd;
				cf.lpLogFont = &lf;
				cf.Flags = CF_EFFECTS | CF_SCREENFONTS;

				// FINDREPLACEの初期化.
				uMessage = RegisterWindowMessage(FINDMSGSTRING);	// RegisterWindowMessageでFINDMSGSTRINGを登録.

				// エディットコントロールの表示.
				LPCREATESTRUCT lpCS = (LPCREATESTRUCT)lParam;
				hEdit = CreateWindow(WC_EDIT, _T(""), WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_WANTRETURN | ES_AUTOHSCROLL | ES_AUTOVSCROLL | WS_HSCROLL | WS_VSCROLL, 0, 0, 200, 200, hwnd, (HMENU)IDC_EDIT1, lpCS->hInstance, NULL);
				if (hEdit == NULL){	// 失敗
					return -1;
				}

				// ウィンドウ作成成功
				return 0;	// 0を返すとウィンドウ作成成功となる.

			}

			// 既定の処理へ向かう.
			break;

		// ウィンドウが破棄された時.
		case WM_DESTROY:

			// WM_DESTROYブロック
			{

				// 終了メッセージの送信.
				PostQuitMessage(0);	// PostQuitMessageで終了コードを0とするWM_QUITを送信.

			}

			// 既定の処理へ向かう.
			break;

		// ウィンドウサイズが変更された時.
		case WM_SIZE:

			// WM_SIZEブロック
			{

				// エディットボックスのサイズををウィンドウ一杯にする.
				int iWidth = LOWORD(lParam);
				int iHeight = HIWORD(lParam);
				MoveWindow(hEdit, 0, 0, iWidth, iHeight, TRUE);

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
				HFONT hFont = CreateFontIndirect(&lf);	// CreateFontIndirectでlfからフォントを作る.
				HFONT hOld = (HFONT)SelectObject(hPaintDC, hFont);
				SetTextColor(hPaintDC, cf.rgbColors);

				// 描画終了.
				SelectObject(hPaintDC, hOld);
				DeleteObject(hFont);
				EndPaint(hwnd, &ps);

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
					// ID_FONT_CHOOSE(Choose Font)が選択された時.
					case ID_FONT_CHOOSE:

						// ID_FONT_CHOOSEブロック
						{

							// フォント選択ダイアログの表示.
							BOOL bRet = ChooseFont(&cf);	// ChooseFontでフォント選択ダイアログの表示.
							if (bRet){
								InvalidateRect(hwnd, NULL, TRUE);
							}

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// ID_SEACH_DIALOG(Search Dialog)が選択された時.
					case ID_SEACH_DIALOG:

						// ID_SEACH_DIALOGブロック
						{

							// 検索ダイアログの表示.
							DoFindText(hwnd);

						}

						// 既定の処理へ向かう.
						break;

					// ID_REPLACE_DIALOG(Replace Dialog)が選択された時.
					case ID_REPLACE_DIALOG:

						// ID_REPLACE_DIALOGブロック
						{

						}

						// 既定の処理へ向かう.
						break;

					// 上記以外の時.
					default:

						// 既定の処理へ向かう.
						break;

				}

				// 既定の処理へ向かう.
				break;

			}

			// 既定の処理へ向かう.
			break;

		// 上記以外の時.
		default:

			// 既定の処理へ向かう.
			break;

	}

	// 既定の処理に任せる.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// DefWindowProcを呼び, 戻り値をそのまま返す.

}

// FindTextを実行する関数DoFindText
void DoFindText(HWND hwnd){

	// 検索ダイアログがあるか.
	if (g_hFindDlg == NULL){	// ない.
		ZeroMemory(&g_fr, sizeof(FINDREPLACE));
		g_fr.lStructSize = sizeof(FINDREPLACE);
		g_fr.hwndOwner = hwnd;
		g_fr.lpstrFindWhat = g_tszFindWhat;
		g_fr.wFindWhatLen = 80;
		g_fr.Flags = FR_DOWN;
		g_hFindDlg = FindText(&g_fr);
	}
	else{
		SetFocus(g_hFindDlg);
	}

}

// 次の一致文字列を探す関数FindNext
void FindNext(HWND hwnd, HWND hEdit){

	// テキストを取得.
	int iLen = GetWindowTextLength(hEdit);
	TCHAR *tszBuf = new TCHAR[iLen + 1];
	ZeroMemory(tszBuf, (iLen + 1) * sizeof(TCHAR));
	GetWindowText(hEdit, tszBuf, iLen + 1);

	// 検索文字列を探す.
	TCHAR * ptszStr = g_fr.lpstrFindWhat;
	TCHAR * ptszPos = _tcsstr(tszBuf + iSearchStart, ptszStr);

	// 見つかったら.
	if (ptszPos != NULL){
		int iFoundPos = (int)(ptszPos - tszBuf);
		int iFoundLen = lstrlen(ptszStr);
		SetFocus(hEdit);
		SendMessage(hEdit, EM_SETSEL, iFoundPos, iFoundPos + iFoundLen);
		SendMessage(hEdit, EM_SCROLLCARET, 0, 0);
		iSearchStart = iFoundPos + iFoundLen;
	}
	else{	// 見つからなかったら.
		MessageBox(hwnd, _T("みつかりません"), _T("EM_SCROLLCARET"), MB_OK);
		iSearchStart = 0;
	}
	delete [] tszBuf;

}