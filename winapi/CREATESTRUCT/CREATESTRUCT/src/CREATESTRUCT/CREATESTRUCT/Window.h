// 二重インクルード防止
#ifndef __WINDOW_H__
#define __WINDOW_H__

// ヘッダのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <string>		// std::wstring
#include <map>			// std::map

// ウィンドウクラスCWindow
class CWindow{

	// publicメンバ
	public:

		// メンバ変数
		std::wstring m_wstrWindowName;	// ウィンドウ名m_wstrWindowName.
		// staticメンバ変数
		static std::map<HWND, CWindow *>m_mapWindowMap;	// ウィンドウハンドルをキー, CWindowオブジェクトポインタを値とするマップm_mapWindowMap.

		// メンバ関数
		virtual LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// CWindowクラス内のウィンドウプロシージャ.

};

#endif