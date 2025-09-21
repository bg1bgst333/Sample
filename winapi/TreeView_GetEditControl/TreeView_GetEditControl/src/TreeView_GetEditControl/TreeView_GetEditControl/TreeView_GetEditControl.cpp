// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <commctrl.h>	// コモンコントロール

// 独自のヘッダファイル
#include "resource.h"	// リソースID

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理をするように定義したコールバック関数WindowProc.
INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ダイアログの処理をするコールバック関数DialogProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージ情報を格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラス情報をもつWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("TreeView_GetEditControl");			// ウィンドウクラス名は"TreeView_GetEditControl".
	wc.style = CS_HREDRAW | CS_VREDRAW;							// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;								// ウィンドウプロシージャは独自の処理を定義したWindowProc.
	wc.hInstance = hInstance;									// インスタンスハンドルは_tWinMainの引数.
	wc.hIcon = LoadIcon(hInstance, IDI_APPLICATION);			// アイコンはアプリケーション既定のもの.
	wc.hCursor = LoadCursor(hInstance, IDC_ARROW);				// カーソルは矢印.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		// 背景は白ブラシ.
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MAINMENU);			// メニューにはIDR_MAINMENUをMAKEINTRESOURCEマクロで指定.
	wc.cbClsExtra = 0;											// 0でいい.
	wc.cbWndExtra = 0;											// 0でいい.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)){	// RegisterClassでウィンドウクラスを登録し, 0が返ったらエラー.

		// エラー処理
		MessageBox(NULL, _T("RegisterClass failed!"), _T("TreeView_GetEditControl"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("TreeView_GetEditControl"), _T("TreeView_GetEditControl"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"TreeView_GetEditControl"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("TreeView_GetEditControl"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.

	// メッセージループ
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessageでメッセージを取得, 戻り値が0より大きい間はループし続ける.

		// ウィンドウメッセージの送出
		DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(この場合は独自に定義したWindowProc)に送出.
		TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.

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

				// コモンコントロールの初期化
				InitCommonControls();	// InitCommonControlsでコモンコントロールの初期化.

				// ウィンドウ作成成功
				return 0;	// return文で0を返して, ウィンドウ作成成功とする.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// ウィンドウが破棄された時.
		case WM_DESTROY:	// ウィンドウが破棄された時.(uMsgがWM_DESTROYの時.)

			// WM_DESTROYブロック
			{

				// メッセージループを抜ける.
				PostQuitMessage(0);	// PostQuitMessageで抜ける.

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
					// Dialogが選択された時.
					case ID_DIALOG:

						// ID_DIALOGブロック
						{

							// 変数の宣言
							HINSTANCE hInstance;	// アプリケーションインスタンスハンドル

							// hInstanceを取得
							hInstance = (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE);	// GetWindowLongでアプリケーションインスタンスハンドルを取得し, hInstanceに格納.

							// ダイアログボックスの表示
							DialogBox(hInstance, MAKEINTRESOURCEW(IDD_DIALOG1), hwnd, DialogProc);	// DialogBoxでダイアログボックスを表示.(ダイアログの処理はDialogProcに書いてある.)

							// 0を返す.
							return 0;	// 処理したので戻り値として0を返す.

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

						// 上記以外の時.
					default:

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.
						
				}

			}

		// それ以外の時.
		default:

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}

// DialogProc関数の定義
INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam){	// ダイアログの処理をするコールバック関数.

	// static変数の初期化.
	static HIMAGELIST hSmall = NULL;
	static HBITMAP hBitmap1 = NULL;
	static HBITMAP hBitmap2 = NULL;

	// ダイアログのメッセージ処理
	switch (uMsg){	// uMsgの内容で判断.

		// ダイアログの初期化時.
		case WM_INITDIALOG:	// ダイアログの初期化時.(uMsgがWM_INITDIALOGの時.)

			// WM_INITDIALOGブロック
			{

				// 変数の初期化.
				HTREEITEM hParent1 = NULL;	// 親ツリーハンドルhParent1をNULLで初期化.
				HTREEITEM hChild1 = NULL;	// 子要素ハンドルhChild1をNULLで初期化.
				HTREEITEM hParent2 = NULL;	// 親ツリーハンドルhParent2をNULLで初期化.
				HTREEITEM hParent3 = NULL;	// 親ツリーハンドルhParent3をNULLで初期化.
				TV_INSERTSTRUCT tvis = {0};	// TV_INSERTSTRUCT構造体tvisを{0}で初期化.

				// ツリーハンドル取得.
				HWND hTree = GetDlgItem(hwndDlg, IDC_TREE1);

				// イメージリストの作成.
				HINSTANCE hInstance = (HINSTANCE)GetWindowLong(hwndDlg, GWL_HINSTANCE);
				hSmall = ImageList_Create(16, 16, ILC_COLOR24, 2, 1);
				TreeView_SetImageList(hTree, hSmall, TVSIL_NORMAL);
				hBitmap1 = (HBITMAP)LoadImage(hInstance, _T("image1s.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
				hBitmap2 = (HBITMAP)LoadImage(hInstance, _T("image2s.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
				ImageList_Add(hSmall, hBitmap1, NULL);
				ImageList_Add(hSmall, hBitmap2, NULL);

				// 1番目のルート要素追加.
				tvis.hInsertAfter = TVI_LAST;	// 末尾.
				tvis.item.mask = TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE;	// テキストとアイコンと選択時アイコン.
				tvis.hParent = TVI_ROOT;	// ルート.
				tvis.item.pszText = _T("Taro");	// "Taro".
				tvis.item.iImage = 0;	// アイコン0番.
				tvis.item.iSelectedImage = 0;	// アイコン0番.
				hParent1 = (HTREEITEM)TreeView_InsertItem(hTree, &tvis);	// TreeView_InsertItemでtvisの要素を挿入.

				// 1番目の子要素追加.
				tvis.hParent = hParent1;	// hParent1が親.
				tvis.item.pszText = _T("Juutaro");	// "Juutaro".
				tvis.item.iImage = 1;	// アイコン1番.
				tvis.item.iSelectedImage = 1;	// アイコン1番.
				hChild1 = (HTREEITEM)TreeView_InsertItem(hTree, &tvis);		// TreeView_InsertItemでtvisの要素を挿入.

				// 2番目のルート要素追加.
				tvis.hParent = TVI_ROOT;	// ルート.
				tvis.item.pszText = _T("Jiro");	// "Jiro".
				tvis.item.iImage = 0;	// アイコン0番.
				tvis.item.iSelectedImage = 0;	// アイコン0番.
				hParent2 = (HTREEITEM)TreeView_InsertItem(hTree, &tvis);	// TreeView_InsertItemでtvisの要素を挿入.

				// 3番目のルート要素追加.
				tvis.item.pszText = _T("Saburo");	// "Saburo".
				hParent3 = (HTREEITEM)TreeView_InsertItem(hTree, &tvis);	// TreeView_InsertItemでtvisの要素を挿入.

				// TRUEを返す.
				return TRUE;	// 処理できたのでTRUE.

			}
			
			// 抜ける.
			break;	// breakで抜ける.

		// ダイアログが閉じられた時.
		case WM_CLOSE:	// ダイアログが閉じられた時.(uMsgがWM_CLOSEの時.)

			// WM_CLOSEブロック
			{

				// ビットマップの破棄.
				if (hBitmap2 != NULL){
					DeleteObject(hBitmap2);
					hBitmap2 = NULL;
				}
				if (hBitmap1 != NULL){
					DeleteObject(hBitmap1);
					hBitmap1 = NULL;
				}
				// イメージリストの破棄.
				if (hSmall != NULL){
					ImageList_Destroy(hSmall);
					hSmall = NULL;
				}

				// ダイアログを終了する.
				EndDialog(hwndDlg, IDOK);	// EndDialogでダイアログを終了する.

				// TRUEを返す.
				return TRUE;	// 処理できたのでTRUE.

			}

			// 抜ける.
			break;	// breakで抜ける.

		// コモンコントロールから通知が来た時.
		case WM_NOTIFY:

			// WM_NOTIFYブロック
			{

				// 変数の宣言・初期化
				HWND hTree;	// ツリービューのハンドルhTree.

				// ツリービューのハンドルを取得.
				hTree = GetDlgItem(hwndDlg, IDC_TREE1);	// GetDlgItemでIDC_TREE1のハンドル取得.

				// ツリービューの時.
				if ((int)wParam == IDC_TREE1){	// wParamがIDC_TREE1の時.
					TV_DISPINFO *tvi = (TV_DISPINFO *)lParam;	// lParamをTV_DISPINFOのポインタに変換.
					switch (tvi->hdr.code){	// 通知コードごとに分ける.
						case TVN_BEGINLABELEDIT:	// 編集開始.
							// デバッグ出力.
							OutputDebugString(_T("TVN_BEGINLABELEDIT\n"));	// OutputDebugStringで"TVN_BEGINLABELEDIT"を出力.
							break;
						case TVN_ENDLABELEDIT:	// 編集終了.

							// TVN_ENDLABELEDITブロック
							{

								// デバッグ出力.
								OutputDebugString(_T("TVN_ENDLABELEDIT\n"));	// OutputDebugStringで"TVN_ENDLABELEDIT"を出力.

								// エディットコントロールの取得.
								HWND hEdit = TreeView_GetEditControl(hTree);	// TreeView_GetEditControlでhEditを取得.

								// テキストの取得と出力.
								int iLen = GetWindowTextLength(hEdit);
								TCHAR *ptszBuf = new TCHAR[iLen + 1];
								ZeroMemory(ptszBuf, sizeof(TCHAR) * (iLen + 1));
								GetWindowText(hEdit, ptszBuf, iLen + 1);
								OutputDebugString(ptszBuf);
								OutputDebugString(_T("\n"));
								delete[] ptszBuf;

							}

							// 既定の処理へ向かう.
							break;	// breakで抜ける.

						default:	// それ以外.
							break;
					}
				}	

			}

			// 既定の処理へ向かう.
			break;

		// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりして, コマンドが発生した時.
		case WM_COMMAND:	// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりして, コマンドが発生した時.(uMsgがWM_COMMANDの時.)

			// WM_COMMANDブロック
			{

				// どのコントロールかを判定する.
				switch (LOWORD(wParam)){	// LOWORD(wParam)でコントロールのリソースIDが取得できるので, その値で判定する.

					// Button1の時.
					case ID_BUTTON1:

						// ID_BUTTON1ブロック
						{
							// 変数の宣言・初期化
							HWND hTree;	// ツリービューのハンドルhTree.

							// ツリービューのハンドルを取得.
							hTree = GetDlgItem(hwndDlg, IDC_TREE1);	// GetDlgItemでIDC_TREE1のハンドル取得.

							// 選択されたツリービューアイテムハンドルの取得と出力.
							HTREEITEM hItem = TreeView_GetSelection(hTree);	// TreeView_GetSelectionでhItemを取得.
							TCHAR tszHItem[256] = {0};
							_stprintf(tszHItem, _T("hItem = 0x%08x\n"), (unsigned long)hItem);
							OutputDebugString(tszHItem);	// OutputDebugStringでhItemの値を出力.

							// アイテムを編集モードにする.
							TreeView_EditLabel(hTree, hItem);	// TreeView_EditLabelでアイテムを編集モードにする.

						}

						// 既定の処理へ向かう.
						break;	// breakで抜ける.

					// 上記以外の時.
					default:

						// 既定の処理へ向かう.
						break;	// breakで抜ける.

				}

				// 既定の処理へ向かう.
				break;	// breakで抜ける.

			}

			// 抜ける.
			break;	// breakで抜ける.

		// 上記以外の時.
		default:

			// 抜ける.
			break;	// breakで抜ける.

	}

	// ここに来るときは処理できていない.
	return FALSE;	// 処理できていないのでFALSE.

}