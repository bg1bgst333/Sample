// 二重インクルード防止
#ifndef __WINDOW_H__
#define __WINDOW_H__

// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <map>	// std::map

// ウィンドウクラスCWindow
class CWindow{

	// publicメンバ
	public:

		// publicメンバ変数
		HWND m_hWnd;	// HWND型ウィンドウハンドルm_hWnd.

		// staticメンバ変数
		static std::map<HWND, CWindow *>m_mapWindowMap;	// ウィンドウハンドルをキー, CWindowオブジェクトポインタを値とするマップm_mapWindowMap.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CWindow();	// コンストラクタCWindow()
		virtual ~CWindow();	// デストラクタ~CWindow()
		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create.
		virtual LRESULT DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ダイナミックウィンドウプロシージャDynamicWindowProc.

};

#endif