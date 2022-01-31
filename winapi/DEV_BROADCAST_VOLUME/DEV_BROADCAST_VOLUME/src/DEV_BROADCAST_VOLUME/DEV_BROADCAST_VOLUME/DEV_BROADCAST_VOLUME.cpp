// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// C標準入出力
#include <dbt.h>		// デバイス管理

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理をするように定義したコールバック関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数・配列の宣言と初期化.
	HWND hWnd;							// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;							// ウィンドウメッセージ情報を格納するMSG構造体型変数msg.
	WNDCLASS wc;						// ウィンドウクラス情報をもつWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("DEV_BROADCAST_VOLUME");			// ウィンドウクラス名は"DEV_BROADCAST_VOLUME".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;							// ウィンドウプロシージャは独自の処理を定義したWindowProc.
	wc.hInstance = hInstance;								// インスタンスハンドルは_tWinMainの引数.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// アイコンはアプリケーション既定のもの.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);				// カーソルは矢印.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 背景は白ブラシ.
	wc.lpszMenuName = NULL;									// なし
	wc.cbClsExtra = 0;										// 0でいい.
	wc.cbWndExtra = 0;										// 0でいい.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)) {	// RegisterClassでウィンドウクラスを登録し, 0が返ったらエラー.

		// エラー処理
		MessageBox(NULL, _T("RegisterClass Failure!"), _T("DEV_BROADCAST_VOLUME"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass Failure!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("DEV_BROADCAST_VOLUME"), _T("DEV_BROADCAST_VOLUME"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"DEV_BROADCAST_VOLUME"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL) {	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow Failure!"), _T("DEV_BROADCAST_VOLUME"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow Failure!"とエラーメッセージを表示.
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

		// デバイスの状態が変化した時.
		case WM_DEVICECHANGE:	// デバイスの状態が変化した時.(uMsgがWM_DEVICECHANGEの時.)

			// WM_DEVICECHANGEブロック
			{

				// デバイス管理イベントに対する処理.
				switch (wParam) {	// wParamごとに振り分け.

					// デバイスノードが変更された時.
					case DBT_DEVNODES_CHANGED:

						// DBT_DEVNODES_CHANGEDブロック
						{

							// "DBT_DEVNODES_CHANGED"と表示.
							MessageBox(hwnd, _T("DBT_DEVNODES_CHANGED"), _T("DEV_BROADCAST_VOLUME"), MB_OK);	// MessageBoxで"DBT_DEVNODES_CHANGED"と表示.

						}

						// 既定の処理へ向かう.
						break;

					// デバイスが接続され使用可能になった時.
					case DBT_DEVICEARRIVAL:

						// DBT_DEVICEARRIVALブロック
						{

							// 変数の宣言・初期化
							DEV_BROADCAST_HDR *pDBH;	// DEV_BROADCAST_HDRポインタpDBH.
							TCHAR tszDBH[1024] = {0};	// TCHAR文字配列tszDBH(長さ1024)を{0}で初期化.

							// "DBT_DEVICEARRIVAL"と表示.
							MessageBox(hwnd, _T("DBT_DEVICEARRIVAL"), _T("DEV_BROADCAST_VOLUME"), MB_OK);	// MessageBoxで"DBT_DEVICEARRIVAL"と表示.

							// lParamをpDBHに.
							pDBH = (DEV_BROADCAST_HDR *)lParam;	// lParamをDEV_BROADCAST_HDRポインタにキャストして, pDBHに格納.

							// pDBHの各要素をテキスト変換.
							_stprintf(tszDBH, _T("pDBH->dbch_size = %lu,\n pDBH->dbch_devicetype = %lu,\n pDBH->dbch_reserved = %lu"), pDBH->dbch_size, pDBH->dbch_devicetype, pDBH->dbch_reserved);	// _stprintfでpDBHの各要素を示したテキストをtszDBHに変換.

							// tszDBHを表示.
							MessageBox(hwnd, tszDBH, _T("DEV_BROADCAST_VOLUME"), MB_OK);	// MessageBoxでtszDBHを表示.

							// pDBH->dbch_devicetypeごとに振り分け.
							switch (pDBH->dbch_devicetype){

								// ボリュームデバイス
								case DBT_DEVTYP_VOLUME:

									// DBT_DEVTYP_VOLUMEブロック
									{

										// 変数の宣言・初期化
										DEV_BROADCAST_VOLUME *pDBV;	// DEV_BROADCAST_VOLUMEポインタpDBV.
										TCHAR tszDBV[1024] = {0};	// TCHAR文字配列tszDBV(長さ1024)を{0}で初期化.

										// pDBHをpDBVに変換.
										pDBV = (DEV_BROADCAST_VOLUME *)pDBH;	// pDBHをDEV_BROADCAST_VOLUMEポインタにキャストして, pDBVに格納.

										// pDBVの各要素をテキスト変換.
										_stprintf(tszDBV, _T("pDBV->dbcv_size = %lu,\n pDBV->dbcv_devicetype = %lu,\n pDBV->dbcv_reserved = %lu,\n pDBV->dbcv_unitmask = %lu,\n pDBV->dbcv_flags = %u"), pDBV->dbcv_size, pDBV->dbcv_devicetype, pDBV->dbcv_reserved, pDBV->dbcv_unitmask, pDBV->dbcv_flags);	// _stprintfでpDBVの各要素を示したテキストをtszDBVに変換.

										// tszDBVを表示.
										MessageBox(hwnd, tszDBV, _T("DEV_BROADCAST_VOLUME"), MB_OK);	// MessageBoxでtszDBVを表示.

									}

									// 既定の処理へ向かう.
									break;

								// 上記以外の処理.
								default:

									// defaultブロック
									{

									}

									// 既定の処理へ向かう.
									break;

							}

						}

						// 既定の処理へ向かう.
						break;

					// デバイスの削除が完了した時.
					case DBT_DEVICEREMOVECOMPLETE:

						// DBT_DEVICEREMOVECOMPLETEブロック
						{

							// "DBT_DEVICEREMOVECOMPLETE"と表示.
							MessageBox(hwnd, _T("DBT_DEVICEREMOVECOMPLETE"), _T("DEV_BROADCAST_VOLUME"), MB_OK);	// MessageBoxで"DBT_DEVICEREMOVECOMPLETE"と表示.

						}

						// 既定の処理へ向かう.
						break;

					// 上記以外の処理.
					default:

						// defaultブロック
						{

							// "Other"と表示.
							MessageBox(hwnd, _T("Other"), _T("Other"), MB_OK);	// MessageBoxで"Other"と表示.

						}

						// 既定の処理へ向かう.
						break;

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