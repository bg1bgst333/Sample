// ヘッダのインクルード
// 独自のヘッダ
#include "Window.h"	// CWindow

// staticメンバ変数の定義.
std::map<HWND, CWindow *> CWindow::m_mapWindowMap;	// ウィンドウマップm_mapWindowMap.
std::map<DWORD, HandlerConditions *> CWindow::m_mapHandlerMap;	// ハンドラマップm_mapHandlerMap.

// コンストラクタCWindow()
CWindow::CWindow(){

	// メンバの初期化.
	m_hWnd = NULL;	// m_hWndをNULLで初期化.

}

// デストラクタ~CWindow()
CWindow::~CWindow(){

	// メンバの終了処理.
	Destroy();	// Destroyを呼ぶ.

}

// ウィンドウクラス登録関数RegisterClass.
BOOL CWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName){

	// メニュー名はNULL.
	return RegisterClass(hInstance, lpctszClassName, NULL);	// RegisterClass(メニュー名指定バージョン)のメニュー名にNULLを指定.

}

// ウィンドウクラス登録関数RegisterClass(メニュー名指定バージョン)
BOOL CWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName, LPCTSTR lpctszMenuName){

	// 変数・構造体の宣言
	WNDCLASS wc;	// WNDCLASS型ウィンドウクラス構造体wc.

	// ウィンドウクラス構造体wcにパラメータをセット.
	wc.lpszClassName = lpctszClassName;	// ウィンドウクラス名にlpctszClassNameをセットする.
	wc.style = CS_HREDRAW | CS_VREDRAW;	// スタイルはとりあえずCS_HREDRAW | CS_VREDRAWとする.
	wc.lpfnWndProc = StaticWindowProc;	// ウィンドウプロシージャには下で定義するStaticWindowProcを指定する.
	wc.hInstance = hInstance;	// アプリケーションインスタンスハンドルは引数のhInstanceを使う.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// LoadIconでアプリケーション既定のアイコンをロード.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);	// LoadCursorでアプリケーション既定のカーソルをロード.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// GetStockObjectで白ブラシを背景とする.
	wc.lpszMenuName = lpctszMenuName;	// メニューにはlpctszMenuNameをセット.
	wc.cbClsExtra = 0;	// とりあえず0を指定.
	wc.cbWndExtra = 0;	// とりあえず0を指定.

	// ウィンドウクラスの登録
	if (!::RegisterClass(&wc)){	// WindowsAPIのRegisterClassでウィンドウクラスを登録する.

		// 戻り値が0なら登録失敗なのでエラー処理.
		return FALSE;	// FALSEを返す.

	}

	// 登録成功なのでTRUE.
	return TRUE;	// returnでTRUEを返す.

}

// スタティックウィンドウプロシージャStaticWindowProc関数の定義
LRESULT CALLBACK CWindow::StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

	// ポインタの初期化.
	CWindow *pWindow = NULL;	// CWindowオブジェクトポインタpWindowをNULLで初期化.

	// ウィンドウメッセージの処理.
	switch (uMsg){	// uMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始された時.
		case WM_CREATE:

			// WM_CREATEブロック
			{

				// ポインタの初期化
				LPCREATESTRUCT lpCreateStruct = NULL;	// CREATESTRUCTへのポインタlpCreateStructをNULL.

				// lParamからlpCreateStructを取り出す.
				lpCreateStruct = (LPCREATESTRUCT)lParam;	// lParamをLPCREATESTRUCT型にキャストしてlpCreateStructに格納.
				if (lpCreateStruct != NULL){	// lpCreateStructがNULLでなければ.
					pWindow = (CWindow *)lpCreateStruct->lpCreateParams;	// lpCreateStruct->lpCreateParamsはCWindowオブジェクトポインタにキャストし, pWindowに格納.
					CWindow::m_mapWindowMap.insert(std::pair<HWND, CWindow *>(hwnd, pWindow));	// m_mapWindowMapにhwndとpWindowのペアを登録.
				}

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// 上記以外の時.
		default:

			// defaultブロック
			{

				// hwndでCWindowオブジェクトポインタが引けたら, pWindowに格納.
				if (CWindow::m_mapWindowMap.find(hwnd) != CWindow::m_mapWindowMap.end()){	// findでキーをhwndとするCWindowオブジェクトポインタが見つかったら.
					pWindow = CWindow::m_mapWindowMap[hwnd];	// pWindowにhwndで引けるCWindowオブジェクトポインタを格納.
				}

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

	}

	// CWindowオブジェクトポインタが取得できなかった場合, 取得できた場合で分ける.
	if (pWindow == NULL){	// pWindowがNULL

		// DefWindowProcに任せる.
		return DefWindowProc(hwnd, uMsg, wParam, lParam);	// DefWindowProcに引数をそのまま渡して, DefWindowProcの戻り値をそのまま返す.

	}
	else{	// pWindowがNULLでない時.

		// そのCWindowオブジェクトのDynamicWindowProcに渡す.
		return pWindow->DynamicWindowProc(hwnd, uMsg, wParam, lParam);	// pWindow->DynamicWindowProcに引数をそのまま渡して, DynamicWindowProcの戻り値をそのまま返す.

	}

}

// ウィンドウ作成関数Create.
BOOL CWindow::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// ウィンドウの作成.
	m_hWnd = CreateWindow(lpctszClassName, lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance, this);	// CreateWindowでウィンドウを作成し, ハンドルをm_hWndに格納.(最後の引数にオブジェクト自身のポインタthisを渡す.)
	if (m_hWnd == NULL){	// m_hWndがNULLなら失敗.

		// m_hWndがNULLならウィンドウ作成失敗なのでエラー処理.
		return FALSE;	// FALSEを返す.

	}

	// ウィンドウ作成成功なのでTRUE.
	return TRUE;	// returnでTRUEを返す.

}

// ウィンドウ作成関数Create.(RECTバージョン.)
BOOL CWindow::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, const RECT &rect, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// RECTで指定されたサイズをx, y, iWidth, iHeightに変換.
	return CWindow::Create(lpctszClassName, lpctszWindowName, dwStyle, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, hWndParent, hMenu, hInstance);	// CWindow::Createでウィンドウ作成.

}

// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)
BOOL CWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)

	// ウィンドウクラス名は"CWindow".
	return CWindow::Create(_T("CWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Createにウィンドウクラス名"CWindow"を指定.

}

// ウィンドウ破棄関数Destroy
BOOL CWindow::Destroy(){

	// 変数の初期化.
	BOOL bDestroy = FALSE;	// 破棄に成功かどうかを示すbDestroyをFALSEに初期化.

	// 破棄処理.
	if (m_hWnd != NULL){	// m_hWndがNULLでない時.
		bDestroy = DestroyWindow(m_hWnd);	// DestroyWindowでm_hWndを破棄.
		if (bDestroy){	// TRUEなら.
			m_hWnd = NULL;	// m_hWndにNULLをセット.
			return bDestroy;	// bDestroyを返す.
		}
	}

	// 上を通らない(破棄処理をしなかった)のでFALSE.
	return FALSE;	// returnでFALSEを返す.

}

// 子ウィンドウ破棄関数DestroyChildren
BOOL CWindow::DestroyChildren(){

	// ここでは何もせず, 常にFALSEを返す.
	return FALSE;

}

// ウィンドウ表示関数ShowWindow.
BOOL CWindow::ShowWindow(int nCmdShow){

	// ウィンドウの表示.
	return ::ShowWindow(m_hWnd, nCmdShow);	// WindowsAPIのShowWindowでm_hWndを表示.

}

// コマンドハンドラの追加.
void CWindow::AddCommandHandler(UINT nID, UINT nCode, int(CWindow:: * handler)(WPARAM wParam, LPARAM lParam)){

	// HandlerConditionsの生成と追加.
	HandlerConditions *pCond = new HandlerConditions();	// HandlerConditionsオブジェクトを作成し, ポインタをpCondに格納.
	pCond->m_nID = nID;	// pCond->m_nIDにnIDを格納.
	pCond->m_nCode = nCode;	// pCond->m_nCodeにnCodeを格納.
	pCond->m_fpHandler = handler;	// pCond->m_fpHandlerにhandlerを格納.
	m_mapHandlerMap.insert(std::pair<DWORD, HandlerConditions *>((DWORD)MAKEWPARAM(nID, nCode), pCond));	// m_mapHandlerMap.insertでnID, nCodeをMAKEWPARAMしたものをキー, pCondを値として登録.

}

// コマンドハンドラの削除.
void CWindow::DeleteCommandHandler(UINT nID, UINT nCode){

	// ハンドラマップから指定のハンドラ情報を削除.
	HandlerConditions *pCond = NULL;	// HandlerConditionsオブジェクトポインタpCondをNULLに初期化.
	std::map<DWORD, HandlerConditions *>::iterator itor = m_mapHandlerMap.find((DWORD)(MAKEWPARAM(nID, nCode)));	// findでキーを(DWORD)(MAKEWPARAM(nID, nCode))とするHandlerConditionsオブジェクトポインタのイテレータを取得.
	if (itor != m_mapHandlerMap.end()){	// 見つかったら.
		pCond = m_mapHandlerMap[(DWORD)(MAKEWPARAM(nID, nCode))];	// (DWORD)(MAKEWPARAM(nID, nCode))を使ってハンドラマップからHandlerConditionsオブジェクトポインタを引き出す.
		delete pCond;	// HandlerConditionsオブジェクトを破棄.
		m_mapHandlerMap.erase(itor);	// itorの指す要素を削除.
	}

}

// テキストを取得.
int CWindow::GetWindowText(LPTSTR lptszStringBuf, int nMaxCount) const {

	// 指定されたウィンドウのテキストを取得する.
	return ::GetWindowText(m_hWnd, lptszStringBuf, nMaxCount);	// Win32APIのGetWindowTextでテキストを取得して, 戻り値を返す.

}

// テキストを取得.(tstringの参照バージョン.)
void CWindow::GetWindowText(tstring& rString) const{

	// テキストの長さを取得.
	int iLen = GetWindowTextLength();	// CWindow::GetWindowTextLengthで長さを取得.

	// バッファを確保.
	TCHAR *ptszBuf = new TCHAR[iLen + 1];	// TCHARバッファptszBuf(長さiLen + 1)を確保.
	ZeroMemory(ptszBuf, sizeof(TCHAR) * (iLen + 1));	// ptszBufの初期化.

	// テキストを取得.
	GetWindowText(ptszBuf, iLen + 1);	// CWindow::GetWindowTextでテキストを取得.

	// 渡された参照rStringに格納.
	rString = ptszBuf;	// rStringにptszBufをコピー.

	// バッファを解放.
	delete [] ptszBuf;	// delete[]でptszBufを解放.

}

// テキストの長さを取得.
int CWindow::GetWindowTextLength() const {
	
	// 指定されたウィンドウのテキストの長さを取得して返す.
	return ::GetWindowTextLength(m_hWnd);	// Win32APIのGetWindowTextLengthで長さを取得してそのまま返す.

}

// テキストの設定.
void CWindow::SetWindowText(LPCTSTR lpctszString){

	// 指定されたウィンドウテキストを設定する.
	::SetWindowText(m_hWnd, lpctszString);	// Win32APIのSetWindowTextでlpctszStringをセット.

}

// ダイナミックウィンドウプロシージャDynamicWindowProc.
LRESULT CWindow::DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

	// ウィンドウメッセージの処理.
	switch (uMsg){	// uMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始された時.
		case WM_CREATE:

			// WM_CREATEブロック
			{

				// OnCreateに任せる.
				return OnCreate(hwnd, (LPCREATESTRUCT)lParam);	// hwndとlParamをOnCreateに渡し, あとは任せる.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// ウィンドウが破棄された時.
		case WM_DESTROY:

			// WM_DESTROYブロック
			{

				// OnDestroyに任せる.
				OnDestroy();	// OnDestroyを呼ぶ.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// ウィンドウのサイズが変更された時.
		case WM_SIZE:

			// WM_SIZEブロック
			{

				// OnSizeに任せる.
				OnSize((UINT)wParam, LOWORD(lParam), HIWORD(lParam));	// OnSizeに任せる.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// ウィンドウの描画を要求された時.
		case WM_PAINT:

			// WM_PAINTブロック
			{

				// OnPaintに任せる.
				OnPaint();	// OnPaintを呼ぶ.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// ウィンドウが閉じられる時.
		case WM_CLOSE:

			// WM_CLOSEブロック
			{

				// OnCloseに任せる.
				if (OnClose() != 0){	// 0以外なら.
					return 0;	// 0を返す.(閉じなくなる.)
				}

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// コマンドが発生した時.
		case WM_COMMAND:

			// WM_COMMANDブロック
			{

				// OnCommandに任せる.
				return OnCommand(wParam, lParam) ? 0 : 1;

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// 水平スクロールバーがスクロールされた時.
		case WM_HSCROLL:	// 水平スクロールバーがスクロールされた時.(uMsgがWM_HSCROLLの時.)

			// WM_HSCROLLブロック
			{

				// OnHScrollに任せる.
				OnHScroll(LOWORD(wParam), HIWORD(wParam));	// OnHScrollに任せる.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// 垂直スクロールバーがスクロールされた時.
		case WM_VSCROLL:	// 垂直スクロールバーがスクロールされた時.(uMsgがWM_VSCROLLの時.)

			// WM_VSCROLLブロック
			{

				// OnVScrollに任せる.
				OnVScroll(LOWORD(wParam), HIWORD(wParam));	// OnVScrollに任せる.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// 上記以外の時.
		default:

			// defaultブロック
			{

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

	}

	// あとは既定の処理に任せる.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// 戻り値も含めてDefWindowProcに既定の処理を任せる.

}

// ウィンドウの作成が開始された時.
int CWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// 常にウィンドウ作成に成功するものとする.
	return 0;	// 0を返すと, ウィンドウ作成に成功したということになる.

}

// ウィンドウが破棄された時.
void CWindow::OnDestroy(){

	// ウィンドウハンドルはNULL.
	m_hWnd = NULL;	// NULLをセット.

	// 終了メッセージの送信.
	PostQuitMessage(0);	// PostQuitMessageで終了コードを0としてWM_QUITメッセージを送信.

}

// ウィンドウのサイズが変更された時.
void CWindow::OnSize(UINT nType, int cx, int cy){

}

// ウィンドウの描画を要求された時.
void CWindow::OnPaint(){

}

// ウィンドウが閉じられる時.
int CWindow::OnClose(){

	// 子ウィンドウの破棄.
	DestroyChildren();	// DestroyChildrenで子ウィンドウの破棄.

	// 常に閉じるものとする.
	return 0;	// 0を返してウィンドウを閉じる.

}

// コマンドが発生した時.
BOOL CWindow::OnCommand(WPARAM wParam, LPARAM lParam){

	// wParamからハンドラ情報を引き出す.
	HandlerConditions *pCond = NULL;	// HandlerConditionsオブジェクトポインタpCondをNULLに初期化.
	if (m_mapHandlerMap.find((const unsigned long)wParam) != m_mapHandlerMap.end()){	// findでキーをwParamとするHandlerConditionsオブジェクトポインタが見つかったら.
		pCond = m_mapHandlerMap[(const unsigned long)wParam];	// wParamでキーが取得できるので, それを使ってハンドラマップからHandlerConditionsオブジェクトポインタを引き出す.
	}
	if (pCond != NULL){	// pCondがNULLでないなら, ハンドラ登録されている.
		int iRet = (this->*pCond->m_fpHandler)(wParam, lParam);	// 登録したハンドラpCond->m_fpHandlerを呼び出し, 戻り値はiRetに格納.
		if (iRet == 0){	// 0なら処理をした.
			return TRUE;	// 処理をしたのでTRUE.
		}
	}

	// 処理していないのでFALSE.
	return FALSE;	// returnでFALSEを返す.

}

// 水平方向スクロールバーイベント時.
void CWindow::OnHScroll(UINT nSBCode, UINT nPos){

	// 水平方向スクロールバー情報を取得.
	SCROLLINFO scrHorz = {0};	// 水平方向スクロール情報scrHorzを{0}で初期化.
	scrHorz.cbSize = sizeof(SCROLLINFO);	// sizeofで構造体サイズ指定.
	scrHorz.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// ページ, レンジ, 位置を取得.
	GetScrollInfo(m_hWnd, SB_HORZ, &scrHorz);	// GetScrollInfoでscrHorzを取得.

	// つまみの最大位置を計算.
	int iMaxPos = scrHorz.nMax + 1 - scrHorz.nPage;	// セットした最大値 + 1が大きさで, そこからページ数を引くと, つまみの最大の位置.

	// 通知コード処理
	switch (nSBCode){	// 通知コードが格納されているので, それで判定する.

		// 1番左
		case SB_LEFT:

			// 1番左にセット.
			scrHorz.nPos = scrHorz.nMin;	// 現在位置を1番左にセット.
			break;	// 抜ける.

		// 1番右
		case SB_RIGHT:

			// 1番右にセット.
			scrHorz.nPos = scrHorz.nMax;	// 現在位置を1番右にセット.
			break;	// 抜ける.

		// 1列左
		case SB_LINELEFT:

			// 1列左に戻す.
			if (scrHorz.nPos > scrHorz.nMin){	// scrHorz.nPosがscrHorz.nMinより大きい場合.
				scrHorz.nPos--;	// 1戻る.
			}
			break;	// 抜ける.

		// 1列右
		case SB_LINERIGHT:

			// 1列右に進める.
			if (scrHorz.nPos < iMaxPos){	// scrHorz.nPosがiMaxPosより小さい場合.
				scrHorz.nPos++;	// 1進む.
			}
			break;	// 抜ける.

		// 1ページ左
		case SB_PAGELEFT:

			// SB_PAGELEFTブロック.
			{

				// 1ページ戻る.
				int after = scrHorz.nPos - scrHorz.nPage;	// 現在位置から1ページ分引く.
				if (after >= scrHorz.nMin){	// 左端を超えてなければ.
					scrHorz.nPos -= scrHorz.nPage;	// 1ページ分マイナス.
				}
				else{	// 左端を超えたら.
					scrHorz.nPos = scrHorz.nMin;	// 最小値に.
				}

			}

			// 抜ける.
			break;	// breakで抜ける.

		// 1ページ右
		case SB_PAGERIGHT:

			// SB_PAGERIGHTブロック.
			{

				// 1ページ進む.
				int after = scrHorz.nPos + scrHorz.nPage;	// 現在位置から1ページ分足す.
				if (after <= iMaxPos){	// 右端を超えてなければ.
					scrHorz.nPos += scrHorz.nPage;	// 1ページ分プラス.
				}
				else{	// 右端を超えたら.
					scrHorz.nPos = scrHorz.nMax;	// 最大値に.
				}

			}

			// 抜ける.
			break;	// breakで抜ける.

		// スクロールつまみが離された時.
		case SB_THUMBPOSITION:


			// SB_THUMBPOSITIONブロック.
			{

				// 離された位置をセット.
				int before = scrHorz.nPos;	// 以前.
				int after = nPos;	// 以後.
				scrHorz.nPos = after;	// HIWORD(wParam)に離された位置が格納されているのでscrHorz.nPosにセット.

			}

			// 抜ける.
			break;	// breakで抜ける.

		// それ以外.
		default:

			// 抜ける.
			break;	// breakで抜ける.

	}

	// scrHorz.nPosをhwndのSB_HORZにセット.
	SetScrollInfo(m_hWnd, SB_HORZ, &scrHorz, TRUE);	// SetScrollInfoで現在のscrHorz.nPosをm_hWndにセット.
	InvalidateRect(m_hWnd, NULL, TRUE);	// InvalidateRectで無効領域を作成.(NULLなので全体が無効領域.)
	UpdateWindow(m_hWnd);	// UpdateWindowでウィンドウの更新.

}

// 垂直方向スクロールバーイベント時.
void CWindow::OnVScroll(UINT nSBCode, UINT nPos){

	// 垂直方向スクロールバー情報を取得.
	SCROLLINFO scrVert = {0};	// 垂直方向スクロール情報scrVertを{0}で初期化.
	scrVert.cbSize = sizeof(SCROLLINFO);	// sizeofで構造体サイズ指定.
	scrVert.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// ページ, レンジ, 位置を取得.
	GetScrollInfo(m_hWnd, SB_VERT, &scrVert);	// GetScrollInfoでscrVertを取得.

	// つまみの最大位置を計算.
	int iMaxPos = scrVert.nMax + 1 - scrVert.nPage;	// セットした最大値 + 1が大きさで, そこからページ数を引くと, つまみの最大の位置.

	// 通知コード処理
	switch (nSBCode){	// 通知コードが格納されているので, それで判定する.

		// 1番上
		case SB_TOP:

			// 1番上にセット.
			scrVert.nPos = scrVert.nMin;	// 現在位置を1番上にセット.
			break;	// 抜ける.

		// 1番下
		case SB_BOTTOM:

			// 1番下にセット.
			scrVert.nPos = scrVert.nMax;	// 現在位置を1番下にセット.
			break;	// 抜ける.

		// 1列上
		case SB_LINEUP:

			// 1列上に戻す.
			if (scrVert.nPos > scrVert.nMin){	// scrVert.nPosがscrVert.nMinより大きい場合.
				scrVert.nPos--;	// 1戻る.
			}
			break;	// 抜ける.

		// 1列下
		case SB_LINEDOWN:

			// 1列下に進める.
			if (scrVert.nPos < iMaxPos){	// scrVert.nPosがiMaxPosより小さい場合.
				scrVert.nPos++;	// 1進む.
			}
			break;	// 抜ける.

		// 1ページ上
		case SB_PAGEUP:

			// SB_PAGEUPブロック.
			{

				// 1ページ戻る.
				int after = scrVert.nPos - scrVert.nPage;	// 現在位置から1ページ分引く.
				if (after >= scrVert.nMin){	// 下限を超えてなければ.
					scrVert.nPos -= scrVert.nPage;	// 1ページ分マイナス.
				}
				else{	// 下限を超えたら.
					scrVert.nPos = scrVert.nMin;	// 最小値に.
				}

			}

			// 抜ける.
			break;	// breakで抜ける.

		// 1ページ下
		case SB_PAGEDOWN:

			// SB_PAGEDOWNブロック.
			{

				// 1ページ進む.
				int after = scrVert.nPos + scrVert.nPage;	// 現在位置から1ページ分足す.
				if (after <= iMaxPos){	// 上限を超えてなければ.
					scrVert.nPos += scrVert.nPage;	// 1ページ分プラス.
				}
				else{	// 上限を超えたら.
					scrVert.nPos = scrVert.nMax;	// 最大値に.
				}

			}

			// 抜ける.
			break;	// breakで抜ける.

		// スクロールつまみが離された時.
		case SB_THUMBPOSITION:


			// SB_THUMBPOSITIONブロック.
			{

				// 離された位置をセット.
				int before = scrVert.nPos;	// 以前.
				int after = nPos;	// 以後.
				scrVert.nPos = after;	// HIWORD(wParam)に離された位置が格納されているのでscrVert.nPosにセット.

			}

			// 抜ける.
			break;	// breakで抜ける.

		// それ以外.
		default:

			// 抜ける.
			break;	// breakで抜ける.

	}

	// scrVert.nPosをhwndのSB_VERTにセット.
	SetScrollInfo(m_hWnd, SB_VERT, &scrVert, TRUE);	// SetScrollInfoで現在のscrVert.nPosをm_hWndにセット.
	InvalidateRect(m_hWnd, NULL, TRUE);	// InvalidateRectで無効領域を作成.(NULLなので全体が無効領域.)
	UpdateWindow(m_hWnd);	// UpdateWindowでウィンドウの更新.

}