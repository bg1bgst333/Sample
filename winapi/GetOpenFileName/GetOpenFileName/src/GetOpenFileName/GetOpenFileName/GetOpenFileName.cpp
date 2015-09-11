// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型

// 独自のヘッダファイル
#include "resource.h"	// リソースID

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理をするように定義したコールバック関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;			// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;			// ウィンドウメッセージ情報を格納するMSG構造体型変数msg.
	WNDCLASS wc;		// ウィンドウクラス情報をもつWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("GetOpenFileName");				// ウィンドウクラス名は"GetOpenFileName".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("GetOpenFileName"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("GetOpenFileName"), _T("GetOpenFileName"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"GetOpenFileName"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("GetOpenFileName"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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

				// 変数の宣言・初期化
				LPCREATESTRUCT lpcs;	// CreateStruct構造体のポインタlpcs.
				HINSTANCE hInstance;	// HINSTANCE型hInstance.
				HWND hEdit = NULL;	// エディットボックスのウィンドウハンドルhEdit.

				// CreateStruct構造体のポインタ取得.
				lpcs = (LPCREATESTRUCT)lParam;	// lParamをLPCREATESTRUCTにキャストして, lpcsに格納.

				// hInstanceの取得.
				hInstance = lpcs->hInstance;	// lpcsからhInstanceを取得.

				// エディットボックスの子ウィンドウ作成.
				hEdit = CreateWindow(_T("EDIT"), _T(""), WS_CHILD | WS_VISIBLE | WS_HSCROLL | WS_VSCROLL | ES_AUTOHSCROLL | ES_AUTOVSCROLL | ES_MULTILINE | ES_WANTRETURN, 0, 0, 640, 480, hwnd, (HMENU)ID_EDIT1, hInstance, NULL);	// CreateWindowでエディットボックスを生成.

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
					// Openが選択された時.
					case ID_FILE_OPEN:

						// ID_FILE_OPENブロック
						{

							// 変数の宣言・初期化.
							OPENFILENAME ofn = {0};	// OPENFILENAME構造体変数ofnを0で初期化.
							TCHAR tszFilePath[260] = {0};	// ファイルパスを格納するTCHAR型配列(長さ260)も0で初期化.
							HANDLE hFile = NULL;	// ファイルハンドルhFileをNULLに初期化.
							DWORD dwSize;	// DWORD型ファイルサイズdwSize
							LPBYTE lpBytes;	// テキストファイルの内容を格納するBYTE型メモリへのポインタlpBytes.
							HWND hEdit;	// エディットボックスのウィンドウハンドルhEdit.

							// ofnに値をセット.
							ofn.lStructSize = sizeof(OPENFILENAME);	// 構造体のサイズ.
							ofn.hwndOwner = hwnd;	// オーナーウィンドウ.
							ofn.lpstrFilter = _T("Text Files(*.txt)\0*.txt\0\0");	// フィルタ(指定したパターンのファイルだけ見える.)
							ofn.lpstrFile = tszFilePath;	// ファイルパス.
							ofn.nMaxFile = 260;	// ファイルパスの最大長.
							ofn.Flags = OFN_FILEMUSTEXIST;	// ファイルが存在しなかったら警告表示.

							// ファイル選択.
							if (!GetOpenFileName(&ofn)){	// GetOpenFileNameでファイルを選択.

								// 選択しなかった場合.(キャンセル)
								return 0;	// 処理したので戻り値として0を返す.


							}

							// ファイルの開く.
							hFile = CreateFile(tszFilePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFileで選択したファイルを開いて, 取得したハンドルをhFileに格納.
							if (hFile == INVALID_HANDLE_VALUE){	// hFileがINVALID_HANDLE_VALUEなら.

								// エラー処理
								MessageBox(NULL, _T("Error!\n"), _T("GetOpenFileName"), MB_ICONHAND);	// MessageBoxでエラーメッセージ.
								return 0;	// 処理したので戻り値として0を返す.

							}

							// ファイルサイズの取得.
							dwSize = GetFileSize(hFile, NULL);	// GetFileSizeでファイルサイズを取得する.

							// メモリの確保.
							lpBytes = new BYTE[dwSize + 1];	// dwSize + 1メモリを確保.

							// ファイルの読み込み.
							ReadFile(hFile, lpBytes, dwSize, &dwSize, NULL);	// ReadFileで読み込み.
							lpBytes[dwSize] = '\0';	// dwSize番目(一番最後)は'\0'で埋める.

							// エディットボックスのハンドル取得.
							hEdit = GetDlgItem(hwnd, ID_EDIT1);	// GetDlgItemでID_EDIT1のハンドル取得.

							// エディットボックスにセット.
							SetWindowTextA(hEdit, (LPCSTR)lpBytes);	// SetWindowTextA(SetWindowTextのASCII(ShiftJIS)版)でエディットボックスに読み込んだテキストをセット.

							// メモリ解放.
							delete [] lpBytes;	// deleteでメモリ解放.

							// ファイルを閉じる.
							CloseHandle(hFile);	// CloseHandleでファイルを閉じる.

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

		// ウィンドウのサイズが変更された時.
		case WM_SIZE:	// ウィンドウのサイズが変更された時.(uMsgがWM_SIZEの時.)

			// WM_SIZEブロック
			{
				
				// 変数の宣言
				int width;	// クライアント領域の幅.
				int height;	// クライアント領域の高さ.
				HWND hEdit;	// エディットボックスのウィンドウハンドル.

				// クライアント領域の変更後のサイズを取得.
				width = LOWORD(lParam);		// LOWORD(lParam)でクライアント領域の幅を取得.
				height = HIWORD(lParam);	// HIWORD(lParam)でクライアント領域の高さを取得.

				// エディットボックスのサイズ調整.
				hEdit = GetDlgItem(hwnd, ID_EDIT1);	// GetDlgItemでID_EDIT1のウィンドウハンドル取得.
				MoveWindow(hEdit, 0, 0, width, height, TRUE);	// MoveWindowでクライアント領域一杯にエディットボックスを広げる.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// それ以外の時.
		default:

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}