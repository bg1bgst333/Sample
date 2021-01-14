// 二重インクルード防止
#ifndef __CHILDWINDOW_H__
#define __CHILDWINDOW_H__

// ヘッダファイルのインクルード
// 独自のヘッダファイル
#include "Window.h"	// CWindow

// ウィンドウクラスCChildWindow
class CChildWindow : public CWindow{

	// publicメンバ
	public:

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		virtual ~CChildWindow();	// デストラクタ~CChildWindow()
		virtual LRESULT DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ダイナミックウィンドウプロシージャDynamicWindowProc.

};

#endif