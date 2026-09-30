// ヘッダファイルのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <windowsx.h>	// マクロ
#include <tchar.h>		// TCHAR型
#include <ole2.h>		// OleInitialize, OleUninitialize
// 独自のヘッダ
#include "EnumFormatEtc.h"	// CEnumFormatEtc

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理ができるように定義したコールバック関数WindowProc.
LPCTSTR HResultToText(HRESULT hr);													// HRESULTを分かりやすい文字列に変換する関数HResultToTextのプロトタイプ宣言.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージを格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラスを格納するWNDCLASS構造体型変数wc.
	HRESULT hr;					// HRESULT型変数hr.

	// OleInitializeでOLEを初期化する.
	hr = OleInitialize(NULL);	// OleInitializeにNULLを渡してOLEを初期化し, 戻り値をhrに格納.
	if (FAILED(hr)){	// FAILEDマクロでhrが失敗を表す場合.

		// エラー処理
		MessageBox(NULL, _T("OleInitialize failed!"), _T("IEnumFORMATETC"), MB_OK | MB_ICONHAND);	// MessageBoxで"OleInitialize failed!"とエラーメッセージを表示.
		return -3;	// 異常終了(3)

	}

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("IEnumFORMATETC");				// ウィンドウクラス名は"IEnumFORMATETC".
	wc.style = CS_HREDRAW | CS_VREDRAW;							// スタイルはCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;								// ウィンドウプロシージャは独自の処理を定義したWindowProc.
	wc.hInstance = hInstance;									// インスタンスハンドルは_tWinMainの引数.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);					// アイコンはアプリケーション既定のもの.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);					// カーソルは矢印.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		// 背景は白ブラシ.
	wc.lpszMenuName = NULL;										// メニューは無し.
	wc.cbClsExtra = 0;											// 0でよい.
	wc.cbWndExtra = 0;											// 0でよい.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)){	// RegisterClassでウィンドウクラスを登録し, 0が返ってきたらエラー.

		// エラー処理
		MessageBox(NULL, _T("RegisterClass failed!"), _T("IEnumFORMATETC"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		OleUninitialize();	// OleUninitializeで後始末.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("IEnumFORMATETC"), _T("IEnumFORMATETC"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"IEnumFORMATETC"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("IEnumFORMATETC"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
		OleUninitialize();	// OleUninitializeで後始末.
		return -2;	// 異常終了(2)

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでSW_SHOWを指定してウィンドウの表示.

	// メッセージループ
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessageでメッセージを取得, 戻り値が0より大きい間はループを続ける.

		// ウィンドウメッセージの送出
		DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(この場合は独自に定義するWindowProc)に送出.
		TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.

	}

	// OLEの終了処理.
	OleUninitialize();	// OleUninitializeでOLEの終了処理.

	// プログラムの終了
	return (int)msg.wParam;	// 終了コード(msg.wParam)を戻り値として返す.

}

// HResultToText関数の定義.(代表的なHRESULTだけ文字列に変換する. それ以外は16進数表記にする.)
LPCTSTR HResultToText(HRESULT hr){

	// hrの値で分岐する.
	switch (hr){	// switch文でhrの値ごとに分岐.

		case S_OK:		return _T("S_OK");		// 成功(要求通り取得/範囲内).
		case S_FALSE:	return _T("S_FALSE");	// 「もう無い」ことを示す.
		default:		return _T("(other)");	// その他.

	}

}

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// ウィンドウメッセージに対して独自の処理ができるように定義したウィンドウプロシージャ.

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-case文でuMsgの値ごとに処理を振り分ける.

		// キーが押されたとき.
		case WM_KEYDOWN:	// キーが押されたとき.(uMsgがWM_KEYDOWNの場合.)

			// WM_KEYDOWNブロック
			{

				// SPACEキーが押された場合のみ処理する.
				if (wParam == VK_SPACE){	// wParamがVK_SPACEの場合.

					// このブロックのローカル変数の宣言
					CEnumFormatEtc *pEnum;	// 作成するCEnumFormatEtcオブジェクトへのポインタpEnum.
					IEnumFORMATETC *pClone;	// Cloneで複製するIEnumFORMATETC*へのポインタpClone.
					FORMATETC fe;			// Nextで受け取るFORMATETC構造体型変数fe.
					ULONG celtFetched;		// Nextで実際に取得できた件数を格納するULONG型変数celtFetched.
					HRESULT hrNext1;		// 1回目のNextの戻り値を格納するHRESULT型変数hrNext1.
					HRESULT hrNext2;		// 2回目のNextの戻り値を格納するHRESULT型変数hrNext2.
					HRESULT hrSkip;			// Skipの戻り値を格納するHRESULT型変数hrSkip.
					HRESULT hrNext3;		// Skip後のNextの戻り値を格納するHRESULT型変数hrNext3.
					HRESULT hrCloneNext;	// Clone後, 複製に対するNextの戻り値を格納するHRESULT型変数hrCloneNext.
					TCHAR tszTitle[256];	// タイトルバーに表示する文字列を組み立てるTCHAR型配列tszTitle.

					// CEnumFormatEtcオブジェクトを1つ作成する.
					pEnum = new CEnumFormatEtc();	// newでCEnumFormatEtcオブジェクトを作成し, pEnumに格納.

					// (1) 1回目のNext.(1件だけ持っているので, 成功してS_OKになるはず.)
					hrNext1 = pEnum->Next(1, &fe, &celtFetched);	// Nextに celt=1, fe, celtFetchedを渡し, 戻り値をhrNext1に格納.

					// (2) 2回目のNext.(もう1件も無いので, S_FALSEになるはず.)
					hrNext2 = pEnum->Next(1, &fe, &celtFetched);	// Nextに celt=1, fe, celtFetchedを渡し, 戻り値をhrNext2に格納.

					// (3) Resetで先頭に戻す.
					pEnum->Reset();	// Resetで列挙位置を先頭に戻す.

					// (4) Skip(1)で1件読み飛ばす.(ちょうど1件しか無いので, 範囲内としてS_OKになるはず.)
					hrSkip = pEnum->Skip(1);	// Skipに1を渡し, 戻り値をhrSkipに格納.

					// (5) Skip後のNext.(既に読み飛ばし済みなので, S_FALSEになるはず.)
					hrNext3 = pEnum->Next(1, &fe, &celtFetched);	// Nextに celt=1, fe, celtFetchedを渡し, 戻り値をhrNext3に格納.

					// (6) Resetで先頭に戻してからCloneする.
					pEnum->Reset();	// Resetで列挙位置を先頭に戻す.
					pEnum->Clone(&pClone);	// Cloneでpcloneに複製を作成.(戻り値は常にS_OKなので受け取らない.)

					// (7) 複製に対してNext.(複製は元のオブジェクトとは独立しているので, 先頭からS_OKになるはず.)
					hrCloneNext = pClone->Next(1, &fe, &celtFetched);	// pcloneのNextに celt=1, fe, celtFetchedを渡し, 戻り値をhrCloneNextに格納.

					// 後始末
					pClone->Release();	// Releaseでpcloneを解放.
					pEnum->Release();	// Releaseでpenumを解放.

					// 結果をタイトルバーに表示する.
					wsprintf(tszTitle, _T("IEnumFORMATETC (Next1=%s Next2=%s Skip1=%s Next3=%s CloneNext=%s)"), HResultToText(hrNext1), HResultToText(hrNext2), HResultToText(hrSkip), HResultToText(hrNext3), HResultToText(hrCloneNext));	// wsprintfで結果を埋め込んだ文字列を組み立てる.
					SetWindowText(hwnd, tszTitle);	// SetWindowTextでタイトルバーを書き換える.

				}

			}

			// 次の処理へ続く.
			break;	// breakで抜けても, 次の処理(DefWindowProc)へ続く.

		// ウィンドウが破棄されたとき.
		case WM_DESTROY:	// ウィンドウが破棄されたとき.(uMsgがWM_DESTROYの場合.)

			// WM_DESTROYブロック
			{

				// メッセージループを抜ける.
				PostQuitMessage(0);	// PostQuitMessageで抜ける.

			}

			// 次の処理へ続く.
			break;	// breakで抜けても, 次の処理(DefWindowProc)へ続く.

		// 画面の描画が求められたとき.
		case WM_PAINT:		// 画面の描画が求められたとき.(uMsgがWM_PAINTの場合.)

			// WM_PAINTブロック
			{

				// このブロックのローカル変数の宣言
				HDC hDC;			// デバイスコンテキストハンドルを格納するHDC型変数hDC.
				PAINTSTRUCT ps;		// ペイント情報を管理するPAINTSTRUCT構造体型の変数ps.
				RECT rcClient;		// クライアント領域を格納するRECT型変数rcClient.

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にはデバイスコンテキストハンドルが返るので, hDCに格納.

				// 案内文を表示する.
				GetClientRect(hwnd, &rcClient);	// GetClientRectでクライアント領域のサイズを取得.
				InflateRect(&rcClient, -20, -20);	// InflateRectで少し内側に余白をとる.
				DrawText(hDC, _T("SPACEキーで、CF_TEXT形式を1件だけ持つCEnumFormatEtcに対し、Next/Skip/Reset/Cloneを一通り試し、結果を対比表示します。"), -1, &rcClient, DT_LEFT | DT_TOP | DT_WORDBREAK);	// DrawTextで案内文を折り返しながら表示.

				// ウィンドウの描画終了
				EndPaint(hwnd, &ps);	// EndPaintでこのウィンドウの描画処理を終了させる.

			}

			// 次の処理へ続く.
			break;	// breakで抜けても, 次の処理(DefWindowProc)へ続く.

		// それ以外の場合.
		default:

			// 次の処理へ続く.
			break;	// breakで抜けても, 次の処理(DefWindowProc)へ続く.

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}
