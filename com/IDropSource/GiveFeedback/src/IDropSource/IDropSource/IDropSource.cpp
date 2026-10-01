// ヘッダファイルのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <windowsx.h>	// マクロ
#include <tchar.h>		// TCHAR型
#include <ole2.h>		// OleInitialize, OleUninitialize
// 独自のヘッダ
#include "DropSource.h"	// CDropSource

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理ができるように定義したコールバック関数WindowProc.
LPCTSTR EffectToText(DWORD dwEffect);												// dwEffectを分かりやすい文字列に変換する関数EffectToTextのプロトタイプ宣言.

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
		MessageBox(NULL, _T("OleInitialize failed!"), _T("IDropSource"), MB_OK | MB_ICONHAND);	// MessageBoxで"OleInitialize failed!"とエラーメッセージを表示.
		return -3;	// 異常終了(3)

	}

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("IDropSource");				// ウィンドウクラス名は"IDropSource".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("IDropSource"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		OleUninitialize();	// OleUninitializeで後始末.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("IDropSource"), _T("IDropSource"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"IDropSource"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("IDropSource"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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

// EffectToText関数の定義.(dwEffectを文字列に変換する.)
LPCTSTR EffectToText(DWORD dwEffect){

	// dwEffectの値で分岐する.
	switch (dwEffect){	// switch文でdwEffectの値ごとに分岐.

		case DROPEFFECT_COPY:	return _T("DROPEFFECT_COPY (IDC_UPARROW)");		// コピー効果.
		case DROPEFFECT_MOVE:	return _T("DROPEFFECT_MOVE (IDC_SIZEALL)");	// 移動効果.
		case DROPEFFECT_LINK:	return _T("DROPEFFECT_LINK (IDC_HAND)");		// リンク効果.
		default:				return _T("DROPEFFECT_NONE (IDC_NO)");			// 受け付けない.

	}

}

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// ウィンドウメッセージに対して独自の処理ができるように定義したウィンドウプロシージャ.

	// static変数の宣言
	static CDropSource *pDropSource = NULL;	// 使い回すCDropSourceオブジェクトへのポインタpDropSource.
	static int nState = 0;						// 現在のdwEffectのパターンを覚えておくstatic変数nState.(0=COPY, 1=MOVE, 2=LINK, 3=NONE.)
	static DWORD dwCurrentEffect = DROPEFFECT_COPY;	// 現在表示しているdwEffectを覚えておくstatic変数dwCurrentEffect.

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-case文でuMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始されたとき.
		case WM_CREATE:		// ウィンドウの作成が開始されたとき.(uMsgがWM_CREATEの場合.)

			// WM_CREATEブロック
			{

				// CDropSourceオブジェクトを1つ作成しておく.(SPACEキーのたびに使い回す.)
				pDropSource = new CDropSource();	// newでCDropSourceオブジェクトを作成し, pDropSourceに格納.

				// ウィンドウ作成続行
				return 0;	// returnして0を返すと, ウィンドウ作成を続けるという扱い.

			}

			// 次の処理へ続く.
			break;	// breakで抜けても, 次の処理(DefWindowProc)へ続く.

		// キーが押されたとき.
		case WM_KEYDOWN:	// キーが押されたとき.(uMsgがWM_KEYDOWNの場合.)

			// WM_KEYDOWNブロック
			{

				// SPACEキーが押された場合のみ処理する.
				if (wParam == VK_SPACE){	// wParamがVK_SPACEの場合.

					// このブロックのローカル変数の宣言
					HRESULT hrFeedback;		// GiveFeedbackの戻り値を格納するHRESULT型変数hrFeedback.
					TCHAR tszTitle[256];	// タイトルバーに表示する文字列を組み立てるTCHAR型配列tszTitle.
					RECT rcClient;			// クライアント領域を格納するRECT型変数rcClient.
					POINT ptCenter;			// クライアント領域の中心座標を格納するPOINT型変数ptCenter.

					// SPACEキーを押すたびに, COPY→MOVE→LINK→NONE→COPY...と切り替える.
					switch (nState){	// switch文でnStateの値ごとに分岐.

						case 0:	dwCurrentEffect = DROPEFFECT_COPY;	break;	// 0ならCOPY.
						case 1:	dwCurrentEffect = DROPEFFECT_MOVE;	break;	// 1ならMOVE.
						case 2:	dwCurrentEffect = DROPEFFECT_LINK;	break;	// 2ならLINK.
						default: dwCurrentEffect = DROPEFFECT_NONE;	break;	// 3(それ以外)ならNONE.

					}
					nState = (nState + 1) % 4;	// nStateを次に進める.(3の次は0に戻る.)

					// GiveFeedbackを呼ぶ.(これが今回の主役. 内部でSetCursorにより実際にカーソルの見た目が変わる.)
					hrFeedback = pDropSource->GiveFeedback(dwCurrentEffect);	// GiveFeedbackにdwCurrentEffectを渡し, 戻り値をhrFeedbackに格納.

					// カーソルの変化が見えるように, マウスカーソルをクライアント領域の中心へ移動させる.
					GetClientRect(hwnd, &rcClient);	// GetClientRectでクライアント領域を取得.
					ptCenter.x = (rcClient.left + rcClient.right) / 2;		// ptCenter.xに水平方向の中心を計算.
					ptCenter.y = (rcClient.top + rcClient.bottom) / 2;		// ptCenter.yに垂直方向の中心を計算.
					ClientToScreen(hwnd, &ptCenter);	// ClientToScreenでクライアント座標をスクリーン座標に変換.
					SetCursorPos(ptCenter.x, ptCenter.y);	// SetCursorPosでマウスカーソルをその位置へ移動.

					// 結果をタイトルバーに表示する.
					wsprintf(tszTitle, _T("IDropSource (GiveFeedback! effect=%s hr=0x%08X)"), EffectToText(dwCurrentEffect), hrFeedback);	// wsprintfで結果を埋め込んだ文字列を組み立てる.
					SetWindowText(hwnd, tszTitle);	// SetWindowTextでタイトルバーを書き換える.

				}

			}

			// 次の処理へ続く.
			break;	// breakで抜けても, 次の処理(DefWindowProc)へ続く.

		// カーソルの形状を決める必要があるとき.
		case WM_SETCURSOR:	// カーソルの形状を決める必要があるとき.(uMsgがWM_SETCURSORの場合.)

			// WM_SETCURSORブロック
			{

				// クライアント領域内であれば, GiveFeedbackで設定したカーソルを維持するため, 既定処理(DefWindowProc)に渡さず自分で処理済みとして扱う.
				if (LOWORD(lParam) == HTCLIENT){	// lParamの下位ワードがHTCLIENT(クライアント領域内)の場合.

					// GiveFeedbackを再度呼んで, 現在のdwCurrentEffectに応じたカーソルを再設定する.(マウスが動くたびにWindowsが上書きしようとするのを防ぐため.)
					if (pDropSource != NULL){	// pDropSourceがNULLでない場合.

						pDropSource->GiveFeedback(dwCurrentEffect);	// GiveFeedbackにdwCurrentEffectを渡し, カーソルを再設定.

					}
					return TRUE;	// TRUEを返し, 処理済みであることを伝える.

				}

			}

			// 次の処理へ続く.
			break;	// breakで抜けても, 次の処理(DefWindowProc)へ続く.

		// ウィンドウが破棄されたとき.
		case WM_DESTROY:	// ウィンドウが破棄されたとき.(uMsgがWM_DESTROYの場合.)

			// WM_DESTROYブロック
			{

				// pDropSourceをReleaseで解放する.
				if (pDropSource != NULL){	// pDropSourceがNULLでない場合.

					pDropSource->Release();	// Releaseでpdropsourceを解放.
					pDropSource = NULL;	// pDropSourceをNULLに戻す.

				}

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
				DrawText(hDC, _T("SPACEキーで、GiveFeedbackにCOPY→MOVE→LINK→NONEの順でdwEffectを渡します。GiveFeedback内でSetCursorにより、実際にマウスカーソルの形状が切り替わります。"), -1, &rcClient, DT_LEFT | DT_TOP | DT_WORDBREAK);	// DrawTextで案内文を折り返しながら表示.

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
