// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <commctrl.h>	// コモンコントロール

// 独自のヘッダファイル
#include "resource.h"	// リソースID

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理をするように定義したコールバック関数WindowProc.
INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ダイアログの処理をするコールバック関数DialogProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数・配列の宣言・初期化
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージ情報を格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラス情報をもつWNDCLASS構造体型変数wc.
	TCHAR tszWindowName[256];	// ウィンドウ名を格納するTCHAR型配列tszWindowName.(長さ256)
	HDC hDC = NULL;				// このウィンドウのデバイスコンテキストハンドルhDCをNULLに初期化.
	HACCEL hAccel = NULL;		// アクセラレータテーブルのハンドルを格納するHAACEL型変数hAccelをNULLに初期化.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("BS_GROUPBOX");						// ウィンドウクラス名は"BS_GROUPBOX".
	wc.style = CS_HREDRAW | CS_VREDRAW;							// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;								// ウィンドウプロシージャは独自の処理を定義したWindowProc.
	wc.hInstance = hInstance;									// インスタンスハンドルは_tWinMainの引数.
	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));	// アイコンには作成したアイコン"icon1.ico"(MAKEINTRESOURCE(IDI_ICON1))をLoadIconでロードして使う.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);					// カーソルは矢印.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		// 背景は白ブラシ.
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MAINMENU);			// メニューにはIDR_MAINMENUをMAKEINTRESOURCEマクロで指定.
	wc.cbClsExtra = 0;											// 0でいい.
	wc.cbWndExtra = 0;											// 0でいい.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)){	// RegisterClassでウィンドウクラスを登録し, 0が返ったらエラー.

		// エラー処理
		MessageBox(NULL, _T("RegisterClass failed!"), _T("BS_GROUPBOX"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// 文字列リソースのロード
	LoadString(hInstance, IDS_WINDOW_NAME, tszWindowName, 256);	// LoadStringでSTRINGTABLEからIDS_WINDOW_NAMEにあたる文字列をロードし, tszWindowNameに格納.

	// ウィンドウの作成
	hWnd = CreateWindow(_T("BS_GROUPBOX"), tszWindowName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"BS_GROUPBOX"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("BS_GROUPBOX"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)

	}

	// アクセラレータテーブルのロード
	hAccel =  LoadAccelerators(hInstance, MAKEINTRESOURCE(IDR_MAINMENU));	// LoadAcceleratorsでアクセラレータテーブルをロード.(アクセラレータテーブルのリソースIDはメニューと同じIDR_MAINMENU.)

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.

	// デバイスコンテキストの取得.
	hDC = GetDC(hWnd);	// GetDCでデバイスコンテキストハンドルhDCを取得.

	// PeekMessageによるメインループ.
	while (TRUE){	// 常に真(TRUE)なので無限ループ.

		// ウィンドウメッセージが来ているかを確認する.
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE)){	// PeekMessageでウィンドウメッセージが来ているかを確認し, 真なら来ている.(PM_NOREMOVEなのでメッセージキューからこのメッセージを削除しない.次のGetMessageがそのメッセージを処理する.)

			// 来ていたらそのメッセージを取得.
			if (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessageでPeekMessageで確認したメッセージを取得.

				// アクセラレータキーの処理.
				if (!TranslateAccelerator(hWnd, hAccel, &msg)){	// TranslateAcceleratorでアクセラレータキーをWM_COMMANDに変換できた場合は, 以下のメッセージ処理はしない.

					// ウィンドウメッセージの送出
					TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.
					DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(この場合は独自に定義したWindowProc)に送出.

				}

			}
			else{	// 正常終了(0), またはエラーによる異常終了(-1).

				// メインループを抜ける.
				break;	// breakでメインループを抜ける.

			}

		}
		else{	// 偽ならウィンドウメッセージが来ていないとき.

			// 何もしない.

		}

	}

	// デバイスコンテキストの解放.
	if (hDC != NULL){	// hDCが解放されていなければ.

		// デバイスコンテキストを解放する.
		ReleaseDC(hWnd, hDC);	// ReleaseDCでhDCを解放.
		hDC = NULL;	// NULLをセット.

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
				HWND hButton;			// ボタンのウィンドウハンドルhButton.
				HWND hStatic;			// スタティックコントロールのウィンドウハンドルhStatic.
				HWND hEdit;				// エディットコントロールのウィンドウハンドルhEdit.
				HWND hCheck;			// チェックボックスコントロールのウィンドウハンドルhCheck.
				HWND hRadio1;			// ラジオボタンコントロールのウィンドウハンドルhRadio1.
				HWND hRadio2;			// ラジオボタンコントロールのウィンドウハンドルhRadio2.
				HWND hRadio3;			// ラジオボタンコントロールのウィンドウハンドルhRadio3.
				HWND hGroup;			// グループボックスコントロールのウィンドウハンドルhGroup.
				LPCREATESTRUCT lpCS;	// CreateStruct構造体のポインタlpCS.

				// アプリケーションインスタンスハンドルの取得.
				lpCS = (LPCREATESTRUCT)lParam;	// lParamをLPCREATESTRUCTにキャストして, lpCSに格納.

				// ボタンの作成.
				hButton = CreateWindow(WC_BUTTON, _T("Button1"), WS_CHILD | WS_VISIBLE, 50, 00, 100, 30, hwnd, (HMENU)ID_BUTTON1, lpCS->hInstance, NULL);	// CreateWindowのWC_BUTTONでボタン"Button1"を作成.
				if (hButton == NULL){	// hButtonがNULLなら.

					// エラー処理.
					return -1;	// -1を返す.

				}

				// スタティックコントロール(テキスト)の作成.
				hStatic = CreateWindow(WC_STATIC, _T("StaticText1"), WS_CHILD | WS_VISIBLE, 50, 30, 100, 30, hwnd, (HMENU)ID_STATIC1, lpCS->hInstance, NULL);	// CreateWindowのWC_STATICでスタティックコントロール(テキスト)"StaticText1"を作成.
				if (hStatic == NULL){	// hStaticがNULLなら.

					// エラー処理.
					return -1;	// -1を返す.

				}

				// エディットコントロールの作成.
				hEdit = CreateWindow(WC_EDIT, _T("Edit1"), WS_CHILD | WS_BORDER | WS_VISIBLE, 50, 60, 150, 30, hwnd, (HMENU)ID_EDIT1, lpCS->hInstance, NULL);	// CreateWindowのWC_EDITでエディットコントロール"Edit1"を作成.
				if (hEdit == NULL){	// hEditがNULLなら.

					// エラー処理.
					return -1;	// -1を返す.

				}

				// チェックボックスの作成.
				hCheck = CreateWindow(WC_BUTTON, _T("CheckBox1"), WS_CHILD | WS_VISIBLE | BS_CHECKBOX, 50, 90, 100, 30, hwnd, (HMENU)ID_CHECK1, lpCS->hInstance, NULL);	// CreateWindowのWC_BUTTONとBS_CHECKBOXでチェックボックス"CheckBox1"を作成.
				if (hCheck == NULL){	// hCheckがNULLなら.

					// エラー処理.
					return -1;	// -1を返す.

				}

				// グループボックス1の作成.
				hGroup = CreateWindow(WC_BUTTON, _T("GroupBox1"), WS_CHILD | WS_VISIBLE | BS_GROUPBOX, 50, 120, 410, 150, hwnd, (HMENU)ID_GROUP1, lpCS->hInstance, NULL);	// CreateWindowのWC_BUTTONとBS_GROUPBOXでグループボックス"GroupBox1"を作成.
				if (hGroup == NULL){	// hGroupがNULLなら.

					// エラー処理.
					return -1;	// -1を返す.

				}

				// ラジオボタン1の作成.
				hRadio1 = CreateWindow(WC_BUTTON, _T("RadioButton1"), WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON | WS_GROUP, 20, 20, 120, 30, hGroup, (HMENU)ID_RADIO1, lpCS->hInstance, NULL);	// CreateWindowのWC_BUTTONとBS_RADIOBUTTONでラジオボタン"RadioButton1"を作成.(hGroupの子ウィンドウとして作成. グループの最初のコントロールにはWS_GROUPをつける.)
				if (hRadio1 == NULL){	// hRadio1がNULLなら.

					// エラー処理.
					return -1;	// -1を返す.

				}

				// ラジオボタン2の作成.
				hRadio2 = CreateWindow(WC_BUTTON, _T("RadioButton2"), WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON, 140, 20, 120, 30, hGroup, (HMENU)ID_RADIO2, lpCS->hInstance, NULL);	// CreateWindowのWC_BUTTONとBS_RADIOBUTTONでラジオボタン"RadioButton2"を作成.(hGroupの子ウィンドウとして作成.)
				if (hRadio2 == NULL){	// hRadio2がNULLなら.

					// エラー処理.
					return -1;	// -1を返す.

				}

				// ラジオボタン3の作成.
				hRadio3 = CreateWindow(WC_BUTTON, _T("RadioButton3"), WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON, 260, 20, 120, 30, hGroup, (HMENU)ID_RADIO3, lpCS->hInstance, NULL);	// CreateWindowのWC_BUTTONとBS_RADIOBUTTONでラジオボタン"RadioButton3"を作成.(hGroupの子ウィンドウとして作成.)
				if (hRadio3 == NULL){	// hRadio3がNULLなら.

					// エラー処理.
					return -1;	// -1を返す.

				}

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

		// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりして, コマンドが発生した時.
		case WM_COMMAND:	// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりして, コマンドが発生した時.(uMsgがWM_COMMANDの時.)

			// WM_COMMANDブロック
			{

				// どのメニュー項目, またはコントロールが選択されたかを判定する.
				switch (LOWORD(wParam)){	// LOWORD(wParam)で選択されたメニュー項目, またはコントロールのIDが取得できるので, その値で判定する.

					// 取得したIDごとに処理を分岐.
					// Item1-1が選択された時.
					case ID_ITEM_1_1:

						// ID_ITEM_1_1ブロック
						{

							// 変数の宣言
							HINSTANCE hInstance;	// アプリケーションインスタンスハンドル

							// hInstanceを取得
							hInstance = (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE);	// GetWindowLongでアプリケーションインスタンスハンドルを取得し, hInstanceに格納.

							// ダイアログボックスの表示
							DialogBox(hInstance, MAKEINTRESOURCEW(IDD_DIALOG), hwnd, DialogProc);	// DialogBoxでダイアログボックスを表示.(ダイアログの処理はDialogProcに書いてある.)

							// 0を返す.
							return 0;	// 処理したので戻り値として0を返す.

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// Item1-2が選択された時.
					case ID_ITEM_1_2:

						// ID_ITEM_1_2ブロック
						{

							// メッセージボックスを表示.
							MessageBox(NULL, _T("Item1-2"), _T("BS_GROUPBOX"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"Item1-2"と表示.

							// 0を返す.
							return 0;	// 処理したので戻り値として0を返す.

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// Item1-3が選択された時.
					case ID_ITEM_1_3:

						// ID_ITEM_1_3ブロック
						{

							// メッセージボックスを表示.
							MessageBox(NULL, _T("Item1-3"), _T("BS_GROUPBOX"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"Item1-3"と表示.

							// 0を返す.
							return 0;	// 処理したので戻り値として0を返す.

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// Item2-1が選択された時.
					case ID_ITEM_2_1:

						// ID_ITEM_2_1ブロック
						{

							// メッセージボックスを表示.
							MessageBox(NULL, _T("Item2-1"), _T("BS_GROUPBOX"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"Item2-1"と表示.

							// 0を返す.
							return 0;	// 処理したので戻り値として0を返す.

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// Item2-2が選択された時.
					case ID_ITEM_2_2:

						// ID_ITEM_2_2ブロック
						{

							// メッセージボックスを表示.
							MessageBox(NULL, _T("Item2-2"), _T("BS_GROUPBOX"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"Item2-2"と表示.

							// 0を返す.
							return 0;	// 処理したので戻り値として0を返す.

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// Item2-3が選択された時.
					case ID_ITEM_2_3:

						// ID_ITEM_2_3ブロック
						{

							// メッセージボックスを表示.
							MessageBox(NULL, _T("Item2-3"), _T("BS_GROUPBOX"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"Item2-3"と表示.

							// 0を返す.
							return 0;	// 処理したので戻り値として0を返す.

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// Item3-1が選択された時.
					case ID_ITEM_3_1:

						// ID_ITEM_3_1ブロック
						{

							// メッセージボックスを表示.
							MessageBox(NULL, _T("Item3-1"), _T("BS_GROUPBOX"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"Item3-1"と表示.

							// 0を返す.
							return 0;	// 処理したので戻り値として0を返す.

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// Item3-2が選択された時.
					case ID_ITEM_3_2:

						// ID_ITEM_3_2ブロック
						{

							// メッセージボックスを表示.
							MessageBox(NULL, _T("Item3-2"), _T("BS_GROUPBOX"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"Item3-2"と表示.

							// 0を返す.
							return 0;	// 処理したので戻り値として0を返す.

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// Item3-3が選択された時.
					case ID_ITEM_3_3:

						// ID_ITEM_3_3ブロック
						{

							// メッセージボックスを表示.
							MessageBox(NULL, _T("Item3-3"), _T("BS_GROUPBOX"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"Item3-3"と表示.

							// 0を返す.
							return 0;	// 処理したので戻り値として0を返す.

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// Button1が押された時.
					case ID_BUTTON1:

						// ID_BUTTON1ブロック
						{

							// 変数の宣言.
							HWND hGroup;	// GroupBox1のウィンドウハンドル.

							// GroupBox1のウィンドウハンドルを取得.
							hGroup = GetDlgItem(hwnd, ID_GROUP1);		// GetDlgItemでID_GROUP1のハンドル取得.

							// RadioButton1にチェックを入れる.
							CheckRadioButton(hGroup, ID_RADIO1, ID_RADIO3, ID_RADIO1);	// CheckRadioButtonでID_RADIO1のみにチェックをつける.

							// 0を返す.
							return 0;	// 処理したので戻り値として0を返す.

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// CheckBox1が押された時.
					case ID_CHECK1:

						// ID_CHECK1ブロック
						{

							// メッセージボックスを表示.
							MessageBox(NULL, _T("CheckBox1 Cliked!"), _T("BS_GROUPBOX"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"CheckBox1 Cliked!"と表示.
							
							// 0を返す.
							return 0;	// 処理したので戻り値として0を返す.

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// RadioButton1が押されたとき.
					case ID_RADIO1:

						// ID_RADIO1ブロック
						{

							// ID_RADIO1にチェックをつける.(実際にはID_RADIO1は, ID_GROUP1の子ウィンドウになっているため, ここには来ない.)
							CheckRadioButton(hwnd, ID_RADIO1, ID_RADIO3, ID_RADIO1);	// CheckRadioButtonでID_RADIO1のみにチェックをつける.

							// 0を返す.
							return 0;	// 処理したので戻り値として0を返す.

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// RadioButton2が押されたとき.
					case ID_RADIO2:

						// ID_RADIO2ブロック
						{

							// ID_RADIO2にチェックをつける.(実際にはID_RADIO2は, ID_GROUP1の子ウィンドウになっているため, ここには来ない.)
							CheckRadioButton(hwnd, ID_RADIO1, ID_RADIO3, ID_RADIO2);	// CheckRadioButtonでID_RADIO2のみにチェックをつける.

							// 0を返す.
							return 0;	// 処理したので戻り値として0を返す.

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// RadioButton3が押されたとき.
					case ID_RADIO3:

						// ID_RADIO3ブロック
						{

							// ID_RADIO3にチェックをつける.(実際にはID_RADIO3は, ID_GROUP1の子ウィンドウになっているため, ここには来ない.)
							CheckRadioButton(hwnd, ID_RADIO1, ID_RADIO3, ID_RADIO3);	// CheckRadioButtonでID_RADIO3のみにチェックをつける.

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

// DialogProc関数の定義
INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam){	// ダイアログの処理をするコールバック関数.

	// ダイアログのメッセージ処理
	switch (uMsg){	// uMsgの内容で判断.

		// ダイアログが閉じられた時.
		case WM_CLOSE:	// ダイアログが閉じられた時.(uMsgがWM_CLOSEの時.)

			// WM_CLOSEブロック
			{

				// ダイアログを終了する.
				EndDialog(hwndDlg, IDOK);	// EndDialogでダイアログを終了する.

				// TRUEを返す.
				return TRUE;	// 処理できたのでTRUE.

			}

			// 抜ける.
			break;	// breakで抜ける.

		default:

			// 抜ける.
			break;	// breakで抜ける.

	}

	// ここに来るときは処理できていない.
	return FALSE;	// 処理できていないのでFALSE.

}