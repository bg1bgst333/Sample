// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <commctrl.h>	// コモンコントロール

// 独自のヘッダファイル
#include "resource.h"	// リソースID

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理をするように定義したコールバック関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// 変数の宣言
	HWND hWnd;			// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;			// ウィンドウメッセージ情報を格納するMSG構造体型変数msg.
	WNDCLASS wc;		// ウィンドウクラス情報をもつWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("MultiByteToWideChar");			// ウィンドウクラス名は"MultiByteToWideChar".
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
	if (!RegisterClass(&wc)) {	// RegisterClassでウィンドウクラスを登録し, 0が返ったらエラー.

		// エラー処理
		MessageBox(NULL, _T("RegisterClass Failure!"), _T("MultiByteToWideChar"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass Failure!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("MultiByteToWideChar"), _T("MultiByteToWideChar"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"MultiByteToWideChar"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL) {	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow Failure!"), _T("MultiByteToWideChar"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow Failure!"とエラーメッセージを表示.
		return -2;	// 異常終了(2)

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.

	// メッセージループ
	while (GetMessage(&msg, NULL, 0, 0) > 0) {	// GetMessageでメッセージを取得, 戻り値が0より大きい間はループし続ける.

		// ウィンドウメッセージ処理
		TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.
		DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(この場合は独自に定義したWindowProc)に送出.

	}

	// プログラムの終了
	return (int)msg.wParam;	// 終了コード(msg.wParam)を戻り値として返す.

}

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {	// ウィンドウメッセージに対して独自の処理をするように定義したウィンドウプロシージャ.

	// ウィンドウメッセージに対する処理.
	switch (uMsg) {	// switch-casa文でuMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始された時.
		case WM_CREATE:		// ウィンドウの作成が開始された時.(uMsgがWM_CREATEの時.)

			// WM_CREATEブロック
			{
				
				// 変数の宣言
				HWND hEdit;				// エディットコントロールのウィンドウハンドルhEdit.
				LPCREATESTRUCT lpCS;	// CreateStruct構造体のポインタlpCS.

				// アプリケーションインスタンスハンドルの取得.
				lpCS = (LPCREATESTRUCT)lParam;	// lParamをLPCREATESTRUCTにキャストして, lpCSに格納.

				// エディットコントロールの作成.
				hEdit = CreateWindow(WC_EDIT, _T("Edit1"), WS_CHILD | WS_BORDER | WS_VISIBLE | ES_MULTILINE | ES_WANTRETURN, 50, 50, 250, 200, hwnd, (HMENU)ID_EDIT1, lpCS->hInstance, NULL);	// CreateWindowのWC_EDITでエディットコントロール"Edit1"を作成.
				if (hEdit == NULL){	// hEditがNULLなら.

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

		// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりした時.
		case WM_COMMAND:	// メニュー項目が選択されたり, ボタンなどのコントロールが押されたりした時.(uMsgがWM_COMMANDの時.)

			// WM_COMMANDブロック
			{

				// どのメニュー項目が選択されたかを判定する.
				switch (LOWORD(wParam)){	// LOWORD(wParam)で選択されたメニュー項目のIDが取得できるので, その値で判定する.

					// 取得したIDごとに処理を分岐.
					// Openが選択された時.
					case ID_ITEM_OPEN:

						// ID_ITEM_OPENブロック
						{

							// 変数の宣言
							HANDLE hFile;		// HANDLE型ファイルハンドルhFile
							BYTE btBuf[128];	// BYTE型配列btBuf(長さ128)
							DWORD dwReadBytes;	// DWORD型読み込んだバイト数dwReadBytes.
							HWND hEdit1;	// ID_EDIT1のハンドルhEdit1.
							int iLen;	// バッファに必要な長さiLen.
							TCHAR *ptszBuf;	// TCHARバッファポインタptszBuf.

							// ファイルを開く
							hFile = CreateFile(_T("test.txt"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFileで"test.txt"を開いて, 取得したハンドルをhFileに格納.
							if (hFile != INVALID_HANDLE_VALUE){	// hFileがINVALID_HANDLE_VALUEでなければ.

								// ファイルの内容を読み込む.
								ReadFile(hFile, btBuf, 128, &dwReadBytes, NULL);	// ReadFileでhFileの内容をbtBufに読み込む.
								btBuf[dwReadBytes] = 0x0;	// 末尾を'\0'( = 0x0)で埋める.

								// 閉じる.
								CloseHandle(hFile);	// CloseHandleでhFileを閉じる.

								// マルチバイト文字列をワイド文字列に変換.
								iLen = MultiByteToWideChar(CP_ACP, 0, (char *)btBuf, -1, NULL, 0);	// MultiByteToWideCharで必要なバッファの長さを求める.
								ptszBuf = new TCHAR[iLen];	// 長さiLenのTCHARバッファを確保し, ptszBufに格納.
								MultiByteToWideChar(CP_ACP, 0, (char *)btBuf, -1, ptszBuf, iLen);	// MultiByteToWideCharでbtBufをptszBufに変換.
								
								// エディットコントロールにセット.
								hEdit1 = GetDlgItem(hwnd, ID_EDIT1);	// ID_EDIT1のハンドルhEdit1を取得.
								SetWindowText(hEdit1, ptszBuf);	// SetWindowTextでhEdit1にptszBufをセット.							

								// メモリ解放.
								delete [] ptszBuf;	// ptszBufを解放.

							}

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// Saveが選択された時.
					case ID_ITEM_SAVE:

						// ID_ITEM_SAVEブロック
						{

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// Copyが選択された時.
					case ID_ITEM_COPY:

						// ID_ITEM_COPYブロック
						{

							// 変数の宣言
							BOOL bOpen;	// 開いたかどうかの結果bOpen.
							BOOL bEmpty;	// 空にできたかどうかの結果bEmpty.

							// クリップボードを開く.
							bOpen = OpenClipboard(hwnd);	// OpenClipboardでクリップボードを開く.
							if (bOpen){	// 成功.
								bEmpty = EmptyClipboard();	// EmptyClipboardでクリップボードを空にする.
								if (bEmpty){	// 成功.
									MessageBox(hwnd, _T("EmptyClipboard Success!"), _T("MultiByteToWideChar"), MB_OK | MB_ICONASTERISK);	// "EmptyClipboard Success!"と表示.
								}
								else{	// 失敗.
									MessageBox(hwnd, _T("EmptyClipboard Failure!"), _T("MultiByteToWideChar"), MB_OK | MB_ICONHAND);	// "EmptyClipboard Failure!"と表示.
								}
								CloseClipboard();	// CloseClipboardでクリップボードを閉じる.
							}

						}

						// 既定の処理へ向かう.
						break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

					// Pasteが選択された時.
					case ID_ITEM_PASTE:

						// ID_ITEM_PASTEブロック
						{

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