// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <windowsx.h>	// マクロ
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
	wc.lpszClassName = _T("NM_KILLFOCUS");						// ウィンドウクラス名は"NM_KILLFOCUS".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("NM_KILLFOCUS"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("NM_KILLFOCUS"), _T("NM_KILLFOCUS"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"NM_KILLFOCUS"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("NM_KILLFOCUS"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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

	// 変数の宣言.
	static HWND hEdit;
	static TCHAR *ptszBuf = NULL;
	static HIMAGELIST hSmall = NULL;
	static HBITMAP hBitmap1 = NULL;
	static HBITMAP hBitmap2 = NULL;
	static TCHAR *ptszBefore = NULL;

	// ダイアログのメッセージ処理
	switch (uMsg){	// uMsgの内容で判断.

		// ダイアログの初期化時.
		case WM_INITDIALOG:	// ダイアログの初期化時.(uMsgがWM_INITDIALOGの時.)

			// WM_INITDIALOGブロック
			{

				// 変数の宣言
				LVCOLUMN column1;	// 挿入するカラム情報(Name)を格納するLVCOLUMN構造体変数column1.
				LVCOLUMN column2;	// 挿入するカラム情報(Address)を格納するLVCOLUMN構造体変数column2.
				LVCOLUMN column3;	// 挿入するカラム情報(PhoneNumber)を格納するLVCOLUMN構造体変数column3.
				LVCOLUMN column4;	// 挿入するカラム情報(Age)を格納するLVCOLUMN構造体変数column4.
				LVCOLUMN column5;	// 挿入するカラム情報(Other)を格納するLVCOLUMN構造体変数column5.
				HWND hList;			// リストビューのハンドルhList.

				// カラムNameの設定.
				column1.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;	// このカラムには, 列の形式, 列の幅, テキスト, サブアイテムのインデックスをセットする.
				column1.fmt = LVCFMT_LEFT;	// 左寄せ
				column1.cx = 80;	// 幅80
				column1.pszText = _T("Name");	// 項目名"Name"
				column1.iSubItem = 0;	// サブアイテムのインデックスは0.

				// カラムAddressの設定.
				column2.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;	// このカラムには, 列の形式, 列の幅, テキスト, サブアイテムのインデックスをセットする.
				column2.fmt = LVCFMT_LEFT;	// 左寄せ
				column2.cx = 80;	// 幅80
				column2.pszText = _T("Address");	// 項目名"Address"
				column2.iSubItem = 1;	// サブアイテムのインデックスは1.

				// カラムPhoneNumberの設定.
				column3.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;	// このカラムには, 列の形式, 列の幅, テキスト, サブアイテムのインデックスをセットする.
				column3.fmt = LVCFMT_LEFT;	// 左寄せ
				column3.cx = 80;	// 幅80
				column3.pszText = _T("PhoneNumber");	// 項目名"PhoneNumber"
				column3.iSubItem = 2;	// サブアイテムのインデックスは2.

				// カラムAgeの設定.
				column4.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;	// このカラムには, 列の形式, 列の幅, テキスト, サブアイテムのインデックスをセットする.
				column4.fmt = LVCFMT_LEFT;	// 左寄せ
				column4.cx = 80;	// 幅80
				column4.pszText = _T("Age");	// 項目名"Age"
				column4.iSubItem = 3;	// サブアイテムのインデックスは3.

				// カラムOtherの設定.
				column5.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;	// このカラムには, 列の形式, 列の幅, テキスト, サブアイテムのインデックスをセットする.
				column5.fmt = LVCFMT_LEFT;	// 左寄せ
				column5.cx = 80;	// 幅80
				column5.pszText = _T("Other");	// 項目名"Other"
				column5.iSubItem = 4;	// サブアイテムのインデックスは4.

				// カラムの挿入.
				hList = GetDlgItem(hwndDlg, IDC_LIST1);	// GetDlgItemでIDC_LIST1のハンドル取得.
				ListView_InsertColumn(hList, 0, &column1);	// ListView_InsertColumnでcolumn1の内容のカラムを挿入.
				ListView_InsertColumn(hList, 1, &column2);	// ListView_InsertColumnでcolumn2の内容のカラムを挿入.
				ListView_InsertColumn(hList, 2, &column3);	// ListView_InsertColumnでcolumn3の内容のカラムを挿入.
				ListView_InsertColumn(hList, 3, &column4);	// ListView_InsertColumnでcolumn4の内容のカラムを挿入.
				ListView_InsertColumn(hList, 4, &column5);	// ListView_InsertColumnでcolumn5の内容のカラムを挿入.

				// イメージリストの作成.
				HINSTANCE hInstance = (HINSTANCE)GetWindowLong(hwndDlg, GWL_HINSTANCE);
				hSmall = ImageList_Create(16, 16, ILC_COLOR24, 2, 1);
				ListView_SetImageList(hList, hSmall, LVSIL_SMALL);
				hBitmap1 = (HBITMAP)LoadImage(hInstance, _T("image1s.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
				hBitmap2 = (HBITMAP)LoadImage(hInstance, _T("image2s.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
				ImageList_Add(hSmall, hBitmap1, NULL);
				ImageList_Add(hSmall, hBitmap2, NULL);

				// LVITEM構造体変数nameに設定.
				LVITEM name = {0};
				name.mask = LVIF_TEXT | LVIF_IMAGE;	// 表示テキストと小さい画像をセット.
				name.iItem = 0;			// 一番上から挿入.
				name.iSubItem = 0;
				name.pszText = _T("Taro");	// 表示テキストは"Taro".
				name.iImage = 0;
				ListView_InsertItem(hList, &name);		// ListView_InsertItemでhListにnameを挿入.
				// LVITEM構造体変数addressに設定.
				LVITEM address = {0};
				address.mask = LVIF_TEXT;		// 表示テキストのみセット.
				address.iItem = 0;				// 一番上のにセット.
				address.iSubItem = 1;			// 0から数えて1番目にセット.
				address.pszText = _T("Tokyo");	// 表示テキストは"Tokyo".
				ListView_SetItem(hList, &address);	// ListView_SetItemでhListにaddressをセット.
				// LVITEM構造体変数phonenumberに設定.
				LVITEM phonenumber = {0};
				phonenumber.mask = LVIF_TEXT;			// 表示テキストのみセット.
				phonenumber.iItem = 0;					// 一番上のにセット.
				phonenumber.iSubItem = 2;				// 0から数えて2番目にセット.
				phonenumber.pszText = _T("11111111");	// 表示テキストは"11111111".
				ListView_SetItem(hList, &phonenumber);	// ListView_SetItemでhListにphonenumberをセット.
				// LVITEM構造体変数ageに設定.
				LVITEM age = {0};
				age.mask = LVIF_TEXT;	// 表示テキストのみセット.
				age.iItem = 0;	// 一番上のにセット.
				age.iSubItem = 3;	// 0から数えて3番目にセット.
				age.pszText = _T("30");	// 表示テキストは"30".
				ListView_SetItem(hList, &age);	// ListView_SetItemでhListにageをセット.

				// LVITEM構造体変数nameに設定.
				ZeroMemory(&name, sizeof(name));
				name.mask = LVIF_TEXT | LVIF_IMAGE;	// 表示テキストと小さい画像をセット.
				name.iItem = 1;			// 二番目から挿入.
				name.iSubItem = 0;
				name.pszText = _T("Jiro");	// 表示テキストは"Jiro".
				name.iImage = 1;
				ListView_InsertItem(hList, &name);		// ListView_InsertItemでhListにnameを挿入.
				// LVITEM構造体変数addressに設定.
				ZeroMemory(&address, sizeof(address));
				address.mask = LVIF_TEXT;		// 表示テキストのみセット.
				address.iItem = 1;				// 二番目にセット.
				address.iSubItem = 1;			// 0から数えて1番目にセット.
				address.pszText = _T("Osaka");	// 表示テキストは"Osaka".
				ListView_SetItem(hList, &address);	// ListView_SetItemでhListにaddressをセット.
				// LVITEM構造体変数phonenumberに設定.
				ZeroMemory(&phonenumber, sizeof(phonenumber));
				phonenumber.mask = LVIF_TEXT;			// 表示テキストのみセット.
				phonenumber.iItem = 1;					// 二番目セット.
				phonenumber.iSubItem = 2;				// 0から数えて2番目にセット.
				phonenumber.pszText = _T("22222222");	// 表示テキストは"22222222".
				ListView_SetItem(hList, &phonenumber);	// ListView_SetItemでhListにphonenumberをセット.
				// LVITEM構造体変数ageに設定.
				ZeroMemory(&age, sizeof(age));
				age.mask = LVIF_TEXT;	// 表示テキストのみセット.
				age.iItem = 1;	// 二番目にセット.
				age.iSubItem = 3;	// 0から数えて3番目にセット.
				age.pszText = _T("28");	// 表示テキストは"28".
				ListView_SetItem(hList, &age);	// ListView_SetItemでhListにageをセット.

				// LVITEM構造体変数nameに設定.
				ZeroMemory(&name, sizeof(name));
				name.mask = LVIF_TEXT | LVIF_IMAGE;	// 表示テキストと小さい画像をセット.
				name.iItem = 2;			// 三番目から挿入.
				name.iSubItem = 0;
				name.pszText = _T("Saburo");	// 表示テキストは"Saburo".
				name.iImage = 0;
				ListView_InsertItem(hList, &name);		// ListView_InsertItemでhListにnameを挿入.
				// LVITEM構造体変数addressに設定.
				ZeroMemory(&address, sizeof(address));
				address.mask = LVIF_TEXT;		// 表示テキストのみセット.
				address.iItem = 2;				// 三番目から挿入.
				address.iSubItem = 1;			// 0から数えて1番目にセット.
				address.pszText = _T("Nagoya");	// 表示テキストは"Nagoya".
				ListView_SetItem(hList, &address);	// ListView_SetItemでhListにaddressをセット.
				// LVITEM構造体変数phonenumberに設定.
				ZeroMemory(&phonenumber, sizeof(phonenumber));
				phonenumber.mask = LVIF_TEXT;			// 表示テキストのみセット.
				phonenumber.iItem = 2;					// 三番目から挿入..
				phonenumber.iSubItem = 2;				// 0から数えて2番目にセット.
				phonenumber.pszText = _T("33333333");	// 表示テキストは"33333333".
				ListView_SetItem(hList, &phonenumber);	// ListView_SetItemでhListにphonenumberをセット.
				// LVITEM構造体変数ageに設定.
				ZeroMemory(&age, sizeof(age));
				age.mask = LVIF_TEXT;	// 表示テキストのみセット.
				age.iItem = 2;	// 三番目にセット.
				age.iSubItem = 3;	// 0から数えて3番目にセット.
				age.pszText = _T("26");	// 表示テキストは"26".
				ListView_SetItem(hList, &age);	// ListView_SetItemでhListにageをセット.

				// LVITEM構造体変数nameに設定.
				ZeroMemory(&name, sizeof(name));
				name.mask = LVIF_TEXT | LVIF_IMAGE;	// 表示テキストと小さい画像をセット.
				name.iItem = 3;			// 四番目から挿入.
				name.iSubItem = 0;
				name.pszText = _T("Shiro");	// 表示テキストは"Shiro".
				name.iImage = 1;
				ListView_InsertItem(hList, &name);		// ListView_InsertItemでhListにnameを挿入.

				// LVITEM構造体変数nameに設定.
				ZeroMemory(&name, sizeof(name));
				name.mask = LVIF_TEXT | LVIF_IMAGE;	// 表示テキストと小さい画像をセット.
				name.iItem = 4;			// 五番目から挿入.
				name.iSubItem = 0;
				name.pszText = _T("Goro");	// 表示テキストは"Goro".
				name.iImage = 0;
				ListView_InsertItem(hList, &name);		// ListView_InsertItemでhListにnameを挿入.

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

				// 終了処理.
				if (ptszBuf != NULL){	// バッファが残っている.
					delete[] ptszBuf;	// deleteで解放.
					ptszBuf = NULL;	// ポインタにNULLをセット.
				}
				if (ptszBefore != NULL){	// バッファが残っている.
					delete[] ptszBefore;	// deleteで解放.
					ptszBefore = NULL;	// ポインタにNULLをセット.
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
				HWND hList;					// リストビューのハンドルhList.

				// リストビューのハンドルを取得.
				hList = GetDlgItem(hwndDlg, IDC_LIST1);	// GetDlgItemでIDC_LIST1のハンドル取得.

				// リストビューの時.
				if ((int)wParam == IDC_LIST1){	// wParamがIDC_LIST1の時.
					NMHDR *hdr = (NMHDR *)lParam;	// lParamをNMHDRのポインタに変換.
					NMLVDISPINFO *lvi = (NMLVDISPINFO *)lParam;	// lParamをNMLVDISPINFOのポインタに変換.
					NMLISTVIEW *lv = (NMLISTVIEW *)lParam;	// lParamをNMLISTVIEWのポインタに変換.
					NMITEMACTIVATE *act = (NMITEMACTIVATE *)lParam;	// lParamをNMITEMACTIVATEのポインタに変換.
					NMLVODSTATECHANGE *sc = (NMLVODSTATECHANGE *)lParam;	// lParamをNMLVODSTATECHANGEのポインタに変換.
					NMLVFINDITEM *fi = (NMLVFINDITEM *)lParam;	// lParamをNMLVFINDITEMのポインタに変換.
					NMLVCACHEHINT *hint = (NMLVCACHEHINT *)lParam;	// lParamをNMLVCACHEHINTのポインタに変換.
					NMLVKEYDOWN *kd = (NMLVKEYDOWN *)lParam;	// lParamをNMLVKEYDOWNのポインタに変換.
					switch (hdr->code){	// 通知コードごとに分ける.
						case LVN_ITEMCHANGING:	// アイテム選択変更中.

							// LVN_ITEMCHANGINGブロック.
							{

								// デバッグ出力.
								OutputDebugString(_T("LVN_ITEMCHANGING\n"));	// OutputDebugStringで"LVN_ITEMCHANGING"を出力.

								// 状態変化以外は無視.
								if (!(lv->uChanged & LVIF_STATE)){
									break;
								}

								// 選択状態の変化を調べる.
								BOOL bOld = (lv->uOldState & LVIS_SELECTED) != 0;
								BOOL bNew = (lv->uNewState & LVIS_SELECTED) != 0;
								if (!bOld && bNew){	// 未選択から選択になった.
									if (lv->iItem == 0){	// 0番目は選択禁止.
										SetWindowLongPtr(hwndDlg, DWLP_MSGRESULT, TRUE);	// これを入れると選択が拒否される.
										OutputDebugString(_T("lv->iItem == 0\n"));
										return TRUE;	// ダイアログの場合はこれだけだと禁止が効かない.
									}
								}

							}

							break;
						case LVN_ITEMCHANGED:	// アイテム選択変更確定.

							// LVN_ITEMCHANGEDブロック.
							{

								// デバッグ出力.
								OutputDebugString(_T("LVN_ITEMCHANGED\n"));	// OutputDebugStringで"LVN_ITEMCHANGING"を出力.

								// 状態変化以外は無視.
								if (!(lv->uChanged & LVIF_STATE)){
									break;
								}

								// 選択状態の変化を調べる.
								BOOL bOld = (lv->uOldState & LVIS_SELECTED) != 0;
								BOOL bNew = (lv->uNewState & LVIS_SELECTED) != 0;
								if (!bOld && bNew){	// 未選択から選択になった.
									TCHAR tszText[512] = {0};
									// エディットコントロールにセット.
									ListView_GetItemText(lv->hdr.hwndFrom, lv->iItem, 0, tszText, 512);
									HWND hEditName = GetDlgItem(hwndDlg, ID_EDIT_NAME);
									SetWindowText(hEditName, tszText);
								}

							}

							break;
						case LVN_INSERTITEM:	// アイテム挿入時.

							// LVN_INSERTITEMブロック.
							{

								// 挿入したアイテム情報を出力.
								TCHAR tszItem[256] = {0};
								_stprintf(tszItem, _T("LVN_INSERTITEM: lv->iItem = %d\n"), lv->iItem);
								OutputDebugString(tszItem);

							}

							break;
						case LVN_DELETEITEM:	// アイテム削除時.

							// LVN_DELETEITEMブロック.
							{

								// 削除したアイテム情報を出力.
								TCHAR tszItem[256] = {0};
								_stprintf(tszItem, _T("LVN_DELETEITEM: lv->iItem = %d\n"), lv->iItem);
								OutputDebugString(tszItem);

							}

							break;
						case LVN_DELETEALLITEMS:	// アイテム全削除時.

							// LVN_DELETEALLITEMSブロック.
							{

								// デバッグ出力.
								OutputDebugString(_T("LVN_DELETEALLITEMS\n"));	// OutputDebugStringで"LVN_DELETEALLITEMS"を出力.
								SetWindowLongPtr(hwndDlg, DWLP_MSGRESULT, TRUE);	// これと下の"return TRUE;"が両方無いとLVN_DELETEITEM抑制が効かない.
								return TRUE;

							}

							break;
						case LVN_BEGINLABELEDIT:	// 編集開始.

							// LVN_BEGINLABELEDITブロック.
							{

								// デバッグ出力.
								OutputDebugString(_T("LVN_BEGINLABELEDIT\n"));	// OutputDebugStringで"LVN_BEGINLABELEDIT"を出力.
								hEdit = ListView_GetEditControl(hList);	// ListView_GetEditControlで編集する要素のエディットコントロールハンドルを取得.
								if (ptszBefore != NULL){	// バッファが残っている.
									delete[] ptszBefore;	// deleteで解放.
									ptszBefore = NULL;	// ポインタにNULLをセット.
								}
								int iLen = GetWindowTextLength(hEdit);	// GetWindowTextLengthでテキストの長さを取得.
								ptszBefore = new TCHAR[iLen + 1];	// iLen + 1分のTCHAR配列確保.
								ZeroMemory(ptszBefore, sizeof(TCHAR) * (iLen + 1));	// ptszBufのクリア.
								GetWindowText(hEdit, ptszBefore, iLen + 1);	// テキスト取得.

							}

							break;
						case LVN_ENDLABELEDIT:	// 編集終了.

							// LVN_ENDLABELEDITブロック.
							{

								// デバッグ出力.
								OutputDebugString(_T("LVN_ENDLABELEDIT\n"));	// OutputDebugStringで"LVN_ENDLABELEDIT"を出力.
								if (ptszBuf != NULL){	// バッファが残っている.
									delete[] ptszBuf;	// deleteで解放.
									ptszBuf = NULL;	// ポインタにNULLをセット.
								}
								int iLen = GetWindowTextLength(hEdit);	// GetWindowTextLengthでテキストの長さを取得.
								ptszBuf = new TCHAR[iLen + 1];	// iLen + 1分のTCHAR配列確保.
								ZeroMemory(ptszBuf, sizeof(TCHAR) * (iLen + 1));	// ptszBufのクリア.
								GetWindowText(hEdit, ptszBuf, iLen + 1);	// テキスト取得.
								ListView_SetItemText(hList, lvi->item.iItem, 0, ptszBuf);	// ListView_SetItemTextでテキストをセット.
								if (_tcscmp(ptszBefore, ptszBuf) != 0){	// 変わっていれば.
									ListView_SetItemText(hList, lvi->item.iItem, 4, _T("Changed!"));	// ListView_SetItemTextで"Changed!"をセット.
								}
								OutputDebugString(ptszBuf);	// OutputDebugStringでptszBufを出力.
								OutputDebugString(_T("\n"));	// OutputDebugStringで改行を出力.
								delete[] ptszBuf;	// deleteで解放.
								ptszBuf = NULL;	// ポインタにNULLをセット.

							}

							break;
						case LVN_COLUMNCLICK:	// カラムクリック.
							// デバッグ出力
							OutputDebugString(_T("LVN_COLUMNCLICK\n"));	// OutputDebugStringで"LVN_COLUMNCLICK"を出力.
							break;
						case LVN_ITEMACTIVATE:	// アイテムを選択実行確定.

							// LVN_ITEMACTIVATEブロック.
							{

								// ダブルクリックされたアイテム文字列を表示.
								if (act->iItem >= 0){
									TCHAR tszText[256] = {0};
									ListView_GetItemText(act->hdr.hwndFrom, act->iItem, 0, tszText, 256);
									MessageBox(hwndDlg, tszText, _T("NMITEMACTIVATE"), MB_OK);
								}

							}

							break;
						case LVN_ODSTATECHANGED:	// オーナーデータで状態変更時.

							// LVN_ODSTATECHANGEDブロック.
							{

								// 選択状態が変わったかどうか調べる.
								if ((sc->uOldState ^ sc->uNewState) & LVIS_SELECTED){
									for (int i = sc->iFrom; i <= sc->iTo; i++){
										BOOL bSelected = (sc->uNewState & LVIS_SELECTED) != 0;
										TCHAR tszText[512] = {0};
										if (bSelected){
											_stprintf(tszText, _T("Selected: %d\n"), i);
										}
										else{
											_stprintf(tszText, _T("Not selected: %d\n"), i);
										}
										OutputDebugString(tszText);
									}
								}

							}

							break;
						case LVN_ODCACHEHINT:	// オーナーデータでキャッシュヒント.

							// LVN_ODCACHEHINTブロック.
							{

								// キャッシュする項目の範囲を出力.
								TCHAR tszText[256] = {0};
								_stprintf(tszText, _T("hint->iFrom = %d, hint->iTo = %d\n"), hint->iFrom, hint->iTo);
								OutputDebugString(tszText);

							}

							break;
						case LVN_ODFINDITEM:	// オーナーデータでアイテム検索.

							// LVN_ODFINDITEMブロック.
							{

								// 選択アイテムの次にヒットするやつのインデックスを返す.(選択そのものは内部ルールによって先頭に返るらしく, ヒットしたアイテムに来ないのは注意!)
								if (!(fi->lvfi.flags & LVFI_STRING)){
									return -1;
								}
								for (int i = fi->iStart; i < 5; i++){
									TCHAR tszText[256] = {0};
									ListView_GetItemText(fi->hdr.hwndFrom, i, 0, tszText, 256);
									if (_tcsnicmp(tszText, fi->lvfi.psz, wcslen(fi->lvfi.psz)) == 0){
										OutputDebugString(tszText);
										OutputDebugString(_T("\n"));
										return i;
									}
								}
								return -1;

							}

							break;
						case LVN_GETDISPINFO:	// 表示情報取得.

							// LVN_GETDISPINFOブロック.
							{

								// ここでアイテム情報をセット.
								if (lvi->item.mask & LVIF_TEXT){
									if (lvi->item.iItem == 0){
										if (lvi->item.iSubItem == 0){
											_tcscpy(lvi->item.pszText, _T("abc"));
										}
										if (lvi->item.iSubItem == 1){
											_tcscpy(lvi->item.pszText, _T("item0-sub1"));
										}
										if (lvi->item.iSubItem == 2){
											_tcscpy(lvi->item.pszText, _T("item0-sub2"));
										}
									}
									if (lvi->item.iItem == 1){
										if (lvi->item.iSubItem == 0){
											_tcscpy(lvi->item.pszText, _T("bcd"));
										}
										if (lvi->item.iSubItem == 1){
											_tcscpy(lvi->item.pszText, _T("item1-sub1"));
										}
										if (lvi->item.iSubItem == 2){
											_tcscpy(lvi->item.pszText, _T("item1-sub2"));
										}
									}
									if (lvi->item.iItem == 2){
										if (lvi->item.iSubItem == 0){
											_tcscpy(lvi->item.pszText, _T("ayz"));
										}
										if (lvi->item.iSubItem == 1){
											_tcscpy(lvi->item.pszText, _T("item2-sub1"));
										}
										if (lvi->item.iSubItem == 2){
											_tcscpy(lvi->item.pszText, _T("item2-sub2"));
										}
									}
									if (lvi->item.iItem == 3){
										if (lvi->item.iSubItem == 0){
											_tcscpy(lvi->item.pszText, _T("ccc"));
										}
										if (lvi->item.iSubItem == 1){
											_tcscpy(lvi->item.pszText, _T("item3-sub1"));
										}
										if (lvi->item.iSubItem == 2){
											_tcscpy(lvi->item.pszText, _T("item3-sub2"));
										}
									}
									if (lvi->item.iItem == 4){
										if (lvi->item.iSubItem == 0){
											_tcscpy(lvi->item.pszText, _T("azz"));
										}
										if (lvi->item.iSubItem == 1){
											_tcscpy(lvi->item.pszText, _T("item4-sub1"));
										}
										if (lvi->item.iSubItem == 2){
											_tcscpy(lvi->item.pszText, _T("item4-sub2"));
										}
									}
								}

							}

							break;
						case LVN_KEYDOWN:	// キーダウン.

							// LVN_KEYDOWNブロック.
							{

								// Deleteキーが押された時.
								if (kd->wVKey == VK_DELETE){
									OutputDebugString(_T("LVN_KEYDOWN: kd->wVKey == VK_DELETE\n"));
									return 1;
								}
								OutputDebugString(_T("LVN_KEYDOWN\n"));
								return 0;

							}

							break;
						case NM_CLICK:	// クリック.

							// NM_CLICKブロック.
							{

								// どこがクリックされたかを調べる.
								DWORD dwPos = GetMessagePos();	// GetMessagePosで最後のメッセージのカーソル位置を取得.
								POINT pt = {GET_X_LPARAM(dwPos), GET_Y_LPARAM(dwPos)};
								HWND hList = GetDlgItem(hwndDlg, IDC_LIST1);
								ScreenToClient(hList, &pt);
								LVHITTESTINFO htinfo = {0};
								htinfo.pt = pt;
								int iItem = ListView_HitTest(hList, &htinfo);
								TCHAR tszHitTestInfo[512] = {0};
								if (iItem >= 0){
									if (htinfo.flags & LVHT_ONITEMLABEL){	// ラベル
										_stprintf(tszHitTestInfo, _T("NM_CLICK: iItem = %d, LVHT_ONITEMLABEL\n"), iItem);
										OutputDebugString(tszHitTestInfo);
									}
									else if (htinfo.flags & LVHT_ONITEMICON){	// アイコン
										_stprintf(tszHitTestInfo, _T("NM_CLICK: iItem = %d, LVHT_ONITEMICON\n"), iItem);
										OutputDebugString(tszHitTestInfo);
									}
								}

							}

							break;
						case NM_DBLCLK:	// ダブルクリック

							// NM_DBLCLKブロック.
							{

								// デバッグ出力
								OutputDebugString(_T("NM_DBLCLK\n"));	// OutputDebugStringで"NM_DBLCLK"を出力.

							}

							break;
						case NM_RCLICK:	// 右クリック

							// NM_RCLICKブロック.
							{

								// デバッグ出力
								OutputDebugString(_T("NM_RCLICK\n"));	// OutputDebugStringで"NM_RCLICK"を出力.

							}

							break;
						case NM_SETFOCUS:	// フォーカスが来た時.

							// NM_SETFOCUSブロック.
							{

								// デバッグ出力
								OutputDebugString(_T("NM_SETFOCUS\n"));	// OutputDebugStringで"NM_SETFOCUS"を出力.

							}

							break;
						case NM_KILLFOCUS:	// フォーカスを失った時.

							// NM_KILLFOCUSブロック.
							{

								// デバッグ出力
								OutputDebugString(_T("NM_KILLFOCUS\n"));	// OutputDebugStringで"NM_KILLFOCUS"を出力.

							}

							break;
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

							// 変数の宣言・初期化.
							HWND hEditName;				// Nameを入力するエディットボックスのハンドルhEditName.
							HWND hEditAddress;			// Addressを入力するエディットボックスのハンドルhEditAddress.
							HWND hEditPhoneNumber;		// PhoneNumberを入力するエディットボックスのハンドルhEditPhoneNumber.
							TCHAR tszName[64];			// 名前(長さ64)
							TCHAR tszAddress[128];		// 住所(長さ128)
							TCHAR tszPhoneNumber[32];	// 電話番号(長さ32)
							HWND hList;					// リストビューのハンドルhList.
							LVITEM name = {0};			// 項目を格納するLVITEM構造体変数nameを0で初期化.
							LVITEM address = {0};		// 項目を格納するLVITEM構造体変数addressを0で初期化.
							LVITEM phonenumber = {0};	// 項目を格納するLVITEM構造体変数phonenumberを0で初期化.

							// エディットボックスの内容を取得.
							hEditName = GetDlgItem(hwndDlg, ID_EDIT_NAME);	// GetDlgItemでNameを入力するエディットボックスのハンドル取得.
							GetWindowText(hEditName, tszName, 64);	// GetWindowTextでエディットボックスの内容をtszNameに格納.
							hEditAddress = GetDlgItem(hwndDlg, ID_EDIT_ADDRESS);	// GetDlgItemでAddressを入力するエディットボックスのハンドル取得.
							GetWindowText(hEditAddress, tszAddress, 128);	// GetWindowTextでエディットボックスの内容をtszAddressに格納.
							hEditPhoneNumber = GetDlgItem(hwndDlg, ID_EDIT_PHONENUMBER);	// GetDlgItemでPhoneNumberを入力するエディットボックスのハンドル取得.
							GetWindowText(hEditPhoneNumber, tszPhoneNumber, 32);	// GetWindowTextでエディットボックスの内容をtszPhoneNumberに格納.

							// LVITEM構造体変数nameに設定.
							name.mask = LVIF_TEXT;	// 表示テキストのみセット.
							name.iItem = 0;			// 一番上から挿入.
							name.pszText = tszName;	// 表示テキストはtszName.

							// nameの挿入.
							hList = GetDlgItem(hwndDlg, IDC_LIST1);	// GetDlgItemでIDC_LIST1のハンドル取得.
							ListView_InsertItem(hList, &name);		// ListView_InsertItemでhListにnameを挿入.

							// LVITEM構造体変数addressに設定.
							address.mask = LVIF_TEXT;		// 表示テキストのみセット.
							address.iItem = 0;				// 一番上のにセット.
							address.iSubItem = 1;			// 0から数えて1番目にセット.
							address.pszText = tszAddress;	// 表示テキストはtszAddress.

							// addressの挿入.
							ListView_SetItem(hList, &address);	// ListView_SetItemでhListにaddressをセット.

							// LVITEM構造体変数phonenumberに設定.
							phonenumber.mask = LVIF_TEXT;			// 表示テキストのみセット.
							phonenumber.iItem = 0;					// 一番上のにセット.
							phonenumber.iSubItem = 2;				// 0から数えて2番目にセット.
							phonenumber.pszText = tszPhoneNumber;	// 表示テキストはtszPhoneNumber.

							// phonenumberの挿入.
							ListView_SetItem(hList, &phonenumber);	// ListView_SetItemでhListにphonenumberをセット.

							// TRUEを返す.
							return TRUE;	// 処理できたのでTRUE.

						}

						// 既定の処理へ向かう.
						break;	// breakで抜ける.

					// Button2の時.
					case ID_BUTTON2:

						// ID_BUTTON2ブロック
						{

							// 変数の宣言・初期化
							HWND hList;					// リストビューのハンドルhList.
							int idx = -1;				// 選択されている項目のインデックスを格納するint型変数idxを-1に初期化.
							TCHAR tszName[256];			// 選択行のNameを格納するtszName.(長さ256)
							TCHAR tszAddress[256];		// 選択行のAddressを格納するtszAddress.(長さ256)
							TCHAR tszPhoneNumber[256];	// 選択行のPhoneNumberを格納するtszPhoneNumber.(長さ256)
							HWND hEditName;				// NameのエディットボックスのハンドルhEditName.
							HWND hEditAddress;			// AddressのエディットボックスのハンドルhEditAddress.
							HWND hEditPhoneNumber;		// PhoneNumberのエディットボックスのハンドルhEditPhoneNumber.

							// リストビューのハンドルを取得.
							hList = GetDlgItem(hwndDlg, IDC_LIST1);	// GetDlgItemでIDC_LIST1のハンドル取得.

							// 選択されている行(最初の1つのみ)のインデックスを取得.
							if ((idx = ListView_GetNextItem(hList, idx, LVNI_SELECTED)) != -1){	// ListView_GetNextItemで選択項目のインデックス取得.

								// 選択されている行の各テキストを取得し, 表示.
								ListView_GetItemText(hList, idx, 0, tszName, 256);				// ListView_GetItemTextでi行目の0列目のテキストをtszNameに格納.
								hEditName = GetDlgItem(hwndDlg, ID_EDIT_NAME);					// GetDlgItemでID_EDIT_NAMEのハンドルを取得.
								SetWindowText(hEditName, tszName);								// SetWindowTextでエディットボックスにセット.
								ListView_GetItemText(hList, idx, 1, tszAddress, 256);				// ListView_GetItemTextでi行目の1列目のテキストをtszAddressに格納.
								hEditAddress = GetDlgItem(hwndDlg, ID_EDIT_ADDRESS);			// GetDlgItemでID_EDIT_ADDRESSのハンドルを取得.
								SetWindowText(hEditAddress, tszAddress);						// SetWindowTextでエディットボックスにセット.
								ListView_GetItemText(hList, idx, 2, tszPhoneNumber, 256);			// ListView_GetItemTextでi行目の2列目のテキストをtszPhoneNumberに格納.
								hEditPhoneNumber = GetDlgItem(hwndDlg, ID_EDIT_PHONENUMBER);	// GetDlgItemでID_EDIT_PHONENUMBERのハンドルを取得.
								SetWindowText(hEditPhoneNumber, tszPhoneNumber);				// SetWindowTextでエディットボックスにセット.

							}

							// TRUEを返す.
							return TRUE;	// 処理できたのでTRUE.

						}

						// 既定の処理へ向かう.
						break;	// breakで抜ける.

					// Button3の時.
					case ID_BUTTON3:

						// ID_BUTTON3ブロック
						{

							// 変数の宣言・初期化
							HWND hList;					// リストビューのハンドルhList.
							int idx = -1;				// 選択されている項目のインデックスを格納するint型変数idxを-1に初期化.

							// リストビューのハンドルを取得.
							hList = GetDlgItem(hwndDlg, IDC_LIST1);	// GetDlgItemでIDC_LIST1のハンドル取得.

							// 選択されている行(最初の1つのみ)のインデックスを取得.
							if ((idx = ListView_GetNextItem(hList, idx, LVNI_SELECTED)) != -1){	// ListView_GetNextItemで選択項目のインデックス取得.

								// 選択されている行の削除.
								ListView_DeleteItem(hList, idx);	// ListView_DeleteItemで選択行の削除.
								ListView_Arrange(hList, LVA_ALIGNLEFT);	// ListView_Arrangeで左から整列.

							}

						}

						// 既定の処理へ向かう.
						break;	// breakで抜ける.

					// Button4の時.
					case ID_BUTTON4:

						// ID_BUTTON4ブロック
						{

							// 変数の宣言・初期化
							HWND hList;					// リストビューのハンドルhList.
							int idx = -1;				// 選択されている項目のインデックスを格納するint型変数idxを-1に初期化.

							// リストビューのハンドルを取得.
							hList = GetDlgItem(hwndDlg, IDC_LIST1);	// GetDlgItemでIDC_LIST1のハンドル取得.

							// 選択されている行(最初の1つのみ)のインデックスを取得.
							if ((idx = ListView_GetNextItem(hList, idx, LVNI_SELECTED)) != -1){	// ListView_GetNextItemで選択項目のインデックス取得.
								SetFocus(hList);	// これがないとフォーカス外れてるので編集状態にならない.
								ListView_EditLabel(hList, idx);	// ListView_EditLabelで編集状態にする.
							}

						}

						// 既定の処理へ向かう.
						break;	// breakで抜ける.

					// Button5の時.
					case ID_BUTTON5:

						// ID_BUTTON5ブロック
						{

							// 変数の宣言・初期化
							HWND hList;					// リストビューのハンドルhList.

							// リストビューのハンドルを取得.
							hList = GetDlgItem(hwndDlg, IDC_LIST1);	// GetDlgItemでIDC_LIST1のハンドル取得.

							// すべてのアイテムを削除.
							ListView_DeleteAllItems(hList);	// ListView_DeleteAllItemsですべてのアイテムを削除.

						}

						// 既定の処理へ向かう.
						break;	// breakで抜ける.

					// 上記以外の時.
					default:

						// 既定の処理へ向かう.
						break;	// breakで抜ける.

				}

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