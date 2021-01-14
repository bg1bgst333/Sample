// 二重インクルード防止
#ifndef __PARENTWINDOW_H__
#define __PARENTWINDOW_H__

// ヘッダファイルのインクルード
// 独自のヘッダファイル
#include "Window.h"	// CWindow
#include "ChildWindow.h"	// CChildWindow

// ウィンドウクラスCParentWindow
class CParentWindow : public CWindow{

	// publicメンバ
	public:

		// publicメンバ変数
		CChildWindow *m_pChildWindow;	// 子ウィンドウポインタm_pChildWindow.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		virtual ~CParentWindow();	// デストラクタ~CParentWindow()
		virtual LRESULT DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ダイナミックウィンドウプロシージャDynamicWindowProc.

};

#endif