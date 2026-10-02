// ヘッダファイルのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <windowsx.h>	// マクロ
#include <tchar.h>		// TCHAR型

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理ができるように定義したコールバック関数WindowProc.
void FormatOneMessage(DWORD dwErrCode, TCHAR* tszOut, int iOutSize);	// 1個のエラーコードをFormatMessageで変換し, tszOutへ1行分の結果文字列を書き込む自作の補助関数.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージを格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラスを格納するWNDCLASS構造体型変数wc.

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("FormatMessage");						// ウィンドウクラス名は"FormatMessage".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("FormatMessage"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("FormatMessage"), _T("FormatMessage"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 820, 420, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"FormatMessage"ウィンドウクラスのウィンドウを作成.(結果を複数行表示するため少し広めのサイズを指定.)
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("FormatMessage"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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

	// プログラムの終了
	return (int)msg.wParam;	// 終了コード(msg.wParam)を戻り値として返す.

}

// FormatOneMessage関数の定義
void FormatOneMessage(DWORD dwErrCode, TCHAR* tszOut, int iOutSize){	// 1個のエラーコードをFormatMessage(本トピックの主役)で変換し, tszOutへ1行分の結果文字列を書き込む.

	// ローカル変数の宣言
	LPTSTR lpMsgBuf;	// FormatMessageが自動確保したバッファへのポインタを受け取るLPTSTR型変数lpMsgBuf.
	DWORD dwLen;		// FormatMessageの戻り値(変換後の文字数)を格納するDWORD型変数dwLen.
	int i;				// 末尾の改行除去に使うint型変数i.

	// FormatMessageでシステム定義のエラーメッセージを取得する.
	lpMsgBuf = NULL;	// 念のため初期化.
	dwLen = FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, NULL, dwErrCode, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpMsgBuf, 0, NULL);	// FORMAT_MESSAGE_ALLOCATE_BUFFERで必要な分だけ自動確保させる(lpMsgBufはLPTSTR*にキャストして渡す決まり).FORMAT_MESSAGE_FROM_SYSTEMでシステム定義のメッセージテーブルを検索.FORMAT_MESSAGE_IGNORE_INSERTSで%1等の挿入シーケンスを無視.

	// 結果を1行分の文字列にまとめる.
	if (dwLen > 0){	// 成功したとき(戻り値は文字数).

		// 末尾の改行文字(\r\n)を取り除く.(FormatMessageが返すシステムメッセージには末尾に改行が付くため.)
		for (i = (int)dwLen - 1; i >= 0 && (lpMsgBuf[i] == _T('\r') || lpMsgBuf[i] == _T('\n')); i--){	// 末尾から\rまたは\nが続く限り,

			lpMsgBuf[i] = _T('\0');	// その文字を終端文字に置き換えて切り詰める.

		}
		wsprintf(tszOut, _T("エラーコード%u -> \"%s\"\r\n"), dwErrCode, lpMsgBuf);	// wsprintfで1行にまとめる.
		LocalFree(lpMsgBuf);	// FORMAT_MESSAGE_ALLOCATE_BUFFERで確保されたバッファは, 使い終わったらLocalFreeで解放する決まり.

	}else{	// 失敗したとき(該当するメッセージが見つからなかった等).

		wsprintf(tszOut, _T("エラーコード%u -> FormatMessage失敗(GetLastError=%u)\r\n"), dwErrCode, GetLastError());	// wsprintfで失敗した旨をまとめる.

	}

}

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// ウィンドウメッセージに対して独自の処理ができるように定義したウィンドウプロシージャ.

	// static変数の宣言
	static TCHAR tszResult[2048] = _T("");		// これまでの結果を積み上げて表示するstatic変数tszResult.
	static BOOL bDone = FALSE;					// 既に実演済みかどうかを表すstatic変数bDone.(SPACEキーの二重押下対策.)

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-case文でuMsgの値ごとに処理を振り分ける.

		// キーが押されたとき.
		case WM_KEYDOWN:	// キーが押されたとき.(uMsgがWM_KEYDOWNの場合.)

			// WM_KEYDOWNブロック
			{

				// SPACEキーが押された場合のみ処理する.
				if (wParam == VK_SPACE && !bDone){	// wParamがVK_SPACEかつ, まだ実演していない場合.

					// このブロックのローカル変数の宣言
					TCHAR tszLine1[320];	// 1個目(エラーコード6)の結果文字列.
					TCHAR tszLine2[320];	// 2個目(エラーコード203)の結果文字列.
					TCHAR tszLine3[320];	// 3個目(存在しないエラーコード)の結果文字列.

					// 1個目: GetLastErrorトピックで実際に出たERROR_INVALID_HANDLE(6)を変換する.
					FormatOneMessage(6, tszLine1, 320);	// 補助関数FormatOneMessageでエラーコード6を変換.

					// 2個目: GetEnvironmentVariableトピックで実際に出たERROR_ENVVAR_NOT_FOUND(203)を変換する.
					FormatOneMessage(203, tszLine2, 320);	// 補助関数FormatOneMessageでエラーコード203を変換.

					// 3個目: わざと存在しないエラーコードを渡し, FormatMessage自体の失敗を確かめる.
					FormatOneMessage(999999, tszLine3, 320);	// 補助関数FormatOneMessageで存在しないエラーコード999999を変換.(対応するメッセージが無いので失敗するはず.)

					// 3行分の結果をこれまでの結果に追記する.
					lstrcat(tszResult, tszLine1);	// lstrcatでtszResultの末尾にtszLine1を連結.
					lstrcat(tszResult, tszLine2);	// 続けてtszLine2を連結.
					lstrcat(tszResult, tszLine3);	// 続けてtszLine3を連結.

					// 実演済みフラグを立てる.(以降のSPACEキーは無視.)
					bDone = TRUE;	// bDoneをTRUEにする.

					// 表示を更新するため再描画要求.
					InvalidateRect(hwnd, NULL, TRUE);	// InvalidateRectで再描画要求.

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
				RECT rcText;		// 描画領域を格納するRECT型変数rcText.
				TCHAR tszAll[2304];	// 案内文+結果をまとめて表示するためのTCHAR型配列tszAll.

				// ウィンドウの描画開始
				hDC = BeginPaint(hwnd, &ps);	// BeginPaintでこのウィンドウの描画の準備をする. 戻り値にはデバイスコンテキストハンドルが返るので, hDCに格納.

				// 案内文とこれまでの結果を表示する.
				GetClientRect(hwnd, &rcClient);	// GetClientRectでクライアント領域のサイズを取得.
				rcText = rcClient;					// rcTextにrcClientをコピー.
				InflateRect(&rcText, -20, -20);	// InflateRectで少し内側に余白をとる.(既存トピックのInflateRectを流用.)
				wsprintf(tszAll, _T("SPACEキーを押すと、FormatMessageで3種類のエラーコードを人間が読めるメッセージに変換します。\r\n\r\n%s"), tszResult);	// 案内文とtszResultを連結.
				DrawText(hDC, tszAll, -1, &rcText, DT_LEFT | DT_TOP | DT_WORDBREAK);	// DrawTextで折り返しながら表示.

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
