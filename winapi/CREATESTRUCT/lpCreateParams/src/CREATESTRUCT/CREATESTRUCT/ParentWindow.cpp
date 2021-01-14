// ヘッダファイルのインクルード
// 独自のヘッダファイル
#include "ParentWindow.h"	// CParentWindow

// デストラクタ~CParentWindow()
CParentWindow::~CParentWindow(){

	// 終了処理
	if (m_pChildWindow != NULL){
		delete m_pChildWindow;
		m_pChildWindow = NULL;
	}

}

// ダイナミックウィンドウプロシージャDynamicWindowProc.
LRESULT CParentWindow::DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

	// ウィンドウメッセージの処理.
	switch (uMsg){	// uMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始された時.
		case WM_CREATE:

			// WM_CREATEブロック
			{

				// ポインタの初期化
				LPCREATESTRUCT lpCreateStruct = NULL;	// CREATESTRUCT構造体へのポインタlpCreateStructをNULL.
				// lParamからlpCreateStructを取り出す.
				lpCreateStruct = (LPCREATESTRUCT)lParam;	// lParamをLPCREATESTRUCT型にキャストしてlpCreateStructに格納.
				if (lpCreateStruct != NULL){	// lpCreateStructがNULLでなければ.

					// 子ウィンドウ作成.
					m_pChildWindow = new CChildWindow();	// オブジェクト作成.
					m_pChildWindow->Create(_T("CREATESTRUCT"), _T("CREATESTRUCT"), WS_CHILD | WS_VISIBLE | WS_BORDER, 100, 100, 300, 300, hwnd, (HMENU)WM_APP + 1, lpCreateStruct->hInstance);	// ウィンドウ作成.

				}

				// 0を返して成功.
				return 0;	// 0を返す.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// ウィンドウが破棄された時.
		case WM_DESTROY:

			// WM_DESTROYブロック
			{

				// 終了メッセージの送信.
				PostQuitMessage(0);	// PostQuitMessageで終了コードを0としてWM_QUITメッセージを送信.(するとメッセージループのGetMessageの戻り値が0になるので, メッセージループから抜ける.)

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