// ヘッダファイルのインクルード
// 標準のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <windowsx.h>	// マクロ
#include <tchar.h>		// TCHAR型
#include <ole2.h>		// OleInitialize, OleUninitialize, RegisterDragDrop, RevokeDragDrop, IDropTarget

// CDropTargetクラスの定義.(IDropTargetの最小構成の実装. まだ中身は何もせず, 常にS_OKを返すだけのスタブ.)
class CDropTarget : public IDropTarget{

	// privateメンバ
	private:

		// privateメンバ変数
		LONG m_lRef;	// 参照カウントm_lRef.

	// publicメンバ
	public:

		// コンストラクタCDropTarget.
		CDropTarget() : m_lRef(1){}	// m_lRefを1で初期化.(生成した瞬間, 呼び出し元が1つ参照を持っているとみなす.)

		// IUnknownのメソッド
		// QueryInterfaceメソッド.
		STDMETHODIMP QueryInterface(REFIID riid, LPVOID *ppv){

			// riidがIID_IUnknownかIID_IDropTargetの場合のみ, 自分自身のポインタを返す.
			if (riid == IID_IUnknown || riid == IID_IDropTarget){	// riidが対応しているインターフェースの場合.

				*ppv = static_cast<IDropTarget *>(this);	// *ppvに自分自身をIDropTarget*としてキャストして格納.
				AddRef();	// AddRefで参照カウントを1増やす.
				return S_OK;	// S_OKを返す.

			}

			// 対応していないインターフェースの場合.
			*ppv = NULL;	// *ppvをNULLにする.
			return E_NOINTERFACE;	// E_NOINTERFACEを返す.

		}

		// AddRefメソッド.
		STDMETHODIMP_(ULONG) AddRef(){

			// InterlockedIncrementでm_lRefを1増やして返す.
			return InterlockedIncrement(&m_lRef);	// InterlockedIncrementでm_lRefをスレッドセーフに1増やす.

		}

		// Releaseメソッド.
		STDMETHODIMP_(ULONG) Release(){

			// InterlockedDecrementでm_lRefを1減らす.
			LONG lRes = InterlockedDecrement(&m_lRef);	// InterlockedDecrementでm_lRefをスレッドセーフに1減らし, lResに結果を格納.
			if (lRes == 0){	// 0になった(誰も参照していない)場合.

				delete this;	// deleteで自分自身を破棄.

			}
			return lRes;	// lResを返す.

		}

		// IDropTargetのメソッド(今回はまだ中身を作り込まず, 全て最小限のスタブ.)
		// DragEnterメソッド.(ドラッグがウィンドウに入ってきたとき.)
		STDMETHODIMP DragEnter(IDataObject *pDataObj, DWORD grfKeyState, POINTL pt, DWORD *pdwEffect){

			// まだ中身は見ず, とりあえずコピー効果ありとして受け入れる.
			*pdwEffect = DROPEFFECT_COPY;	// *pdwEffectにDROPEFFECT_COPYをセット.(これでドラッグ中のカーソルが「コピー」アイコンになる.)
			return S_OK;	// S_OKを返す.

		}

		// DragOverメソッド.(ドラッグ中, ウィンドウ内でマウスが動いたとき.)
		STDMETHODIMP DragOver(DWORD grfKeyState, POINTL pt, DWORD *pdwEffect){

			// DragEnterと同様, コピー効果ありのままにしておく.
			*pdwEffect = DROPEFFECT_COPY;	// *pdwEffectにDROPEFFECT_COPYをセット.
			return S_OK;	// S_OKを返す.

		}

		// DragLeaveメソッド.(ドラッグがウィンドウから出て行ったとき.)
		STDMETHODIMP DragLeave(){

			// まだ何もしない.
			return S_OK;	// S_OKを返す.

		}

		// Dropメソッド.(ウィンドウ内でドロップされたとき.)
		STDMETHODIMP Drop(IDataObject *pDataObj, DWORD grfKeyState, POINTL pt, DWORD *pdwEffect){

			// まだ何もしない.(pDataObjの中身を見るのは次回以降のトピックで扱う.)
			*pdwEffect = DROPEFFECT_COPY;	// *pdwEffectにDROPEFFECT_COPYをセット.
			return S_OK;	// S_OKを返す.

		}

};

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウメッセージに対して独自の処理ができるように定義したコールバック関数WindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 変数の宣言
	HWND hWnd;					// CreateWindowで作成したウィンドウのウィンドウハンドルを格納するHWND型変数hWnd.
	MSG msg;					// ウィンドウメッセージを格納するMSG構造体型変数msg.
	WNDCLASS wc;				// ウィンドウクラスを格納するWNDCLASS構造体型変数wc.
	HRESULT hr;					// HRESULT型変数hr.

	// OleInitializeでOLEを初期化する.(RegisterDragDropを使うには, CoInitializeではなくOleInitializeを呼んでおく必要がある.)
	hr = OleInitialize(NULL);	// OleInitializeにNULLを渡してOLEを初期化し, 戻り値をhrに格納.
	if (FAILED(hr)){	// FAILEDマクロでhrが失敗を表す場合.

		// エラー処理
		MessageBox(NULL, _T("OleInitialize failed!"), _T("RegisterDragDrop"), MB_OK | MB_ICONHAND);	// MessageBoxで"OleInitialize failed!"とエラーメッセージを表示.
		return -3;	// 異常終了(3)

	}

	// ウィンドウクラスの設定
	wc.lpszClassName = _T("RegisterDragDrop");				// ウィンドウクラス名は"RegisterDragDrop".
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("RegisterDragDrop"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"とエラーメッセージを表示.
		OleUninitialize();	// OleUninitializeで後始末.
		return -1;	// 異常終了(1)

	}

	// ウィンドウの作成
	hWnd = CreateWindow(_T("RegisterDragDrop"), _T("RegisterDragDrop"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowで, 上で登録した"RegisterDragDrop"ウィンドウクラスのウィンドウを作成.
	if (hWnd == NULL){	// ウィンドウの作成に失敗したとき.

		// エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("RegisterDragDrop"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"とエラーメッセージを表示.
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

// WindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){	// ウィンドウメッセージに対して独自の処理ができるように定義したウィンドウプロシージャ.

	// static変数の宣言
	static CDropTarget *pDropTarget = NULL;	// 登録するCDropTargetオブジェクトへのポインタpDropTarget.

	// ウィンドウメッセージに対する処理.
	switch (uMsg){	// switch-case文でuMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始されたとき.
		case WM_CREATE:		// ウィンドウの作成が開始されたとき.(uMsgがWM_CREATEの場合.)

			// WM_CREATEブロック
			{

				// このブロックのローカル変数の宣言
				HRESULT hr;	// HRESULT型変数hr.

				// CDropTargetオブジェクトを1つ作成する.
				pDropTarget = new CDropTarget();	// newでCDropTargetオブジェクトを作成し, pDropTargetに格納.

				// RegisterDragDropで, このウィンドウをOLEドラッグ&ドロップの対象として登録する.
				hr = RegisterDragDrop(hwnd, pDropTarget);	// RegisterDragDropにhwndとpDropTargetを渡し, 戻り値をhrに格納.
				if (FAILED(hr)){	// FAILEDマクロでhrが失敗を表す場合.

					// エラー処理
					MessageBox(hwnd, _T("RegisterDragDrop failed!"), _T("RegisterDragDrop"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterDragDrop failed!"とエラーメッセージを表示.

				}
				else{	// 成功した場合.

					// タイトルバーに成功したことを表示する.
					SetWindowText(hwnd, _T("RegisterDragDrop (success!)"));	// SetWindowTextでタイトルバーに成功メッセージを表示.

				}

				// ウィンドウ作成続行
				return 0;	// returnして0を返すと, ウィンドウ作成を続けるという扱い.

			}

			// 次の処理へ続く.
			break;	// breakで抜けても, 次の処理(DefWindowProc)へ続く.

		// ウィンドウが破棄されたとき.
		case WM_DESTROY:	// ウィンドウが破棄されたとき.(uMsgがWM_DESTROYの場合.)

			// WM_DESTROYブロック
			{

				// RevokeDragDropで, このウィンドウをドラッグ&ドロップの対象から解除する.(ウィンドウ破棄前の後始末.)
				RevokeDragDrop(hwnd);	// RevokeDragDropにhwndを渡して解除.

				// pDropTargetをReleaseで解放する.(RegisterDragDropが内部でAddRefしているので, ここでのReleaseは自分が最初にnewした分の後始末.)
				if (pDropTarget != NULL){	// pDropTargetがNULLでない場合.

					pDropTarget->Release();	// Releaseでpドロップターゲットを解放.
					pDropTarget = NULL;	// pDropTargetをNULLに戻す.

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
				DrawText(hDC, _T("このウィンドウはRegisterDragDropで\r\nOLEドラッグ&ドロップの対象として登録されています。\r\n(まだ中身は何もしません。)"), -1, &rcClient, DT_LEFT | DT_TOP | DT_WORDBREAK);	// DrawTextで案内文を折り返しながら表示.

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
