// CListCtrl.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです。
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CListCtrlApp:
// このクラスの実装については、CListCtrl.cpp を参照してください。
//

class CListCtrlApp : public CWinApp
{
public:
	CListCtrlApp();

// オーバーライド
	public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CListCtrlApp theApp;