// 二重インクルード防止
#ifndef __HANDLER_CONDITIONS_H__
#define __HANDLER_CONDITIONS_H__

// ヘッダのインクルード
// 既定のヘッダ
#include <tchar.h>		// TCHAR型
#include <windows.h>	// 標準WindowsAPI
// 独自のヘッダ
#include "Window.h"	// CWindow

// 前方宣言
class CWindow;	// ウィンドウクラスCWindow

// ハンドラの発生条件を格納する構造体HandlerConditions
struct HandlerConditions{
	UINT m_nID;	// リソースID
	UINT m_nCode;	// 通知コード
	int (CWindow:: * m_fpHandler)(WPARAM wParam, LPARAM lParam);	// CWindowクラスメンバのハンドラ関数へのポインタm_fpHandler.
};

#endif