// CScrollBar.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです。
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CScrollBarApp:
// このクラスの実装については、CScrollBar.cpp を参照してください。
//

class CScrollBarApp : public CWinApp
{
public:
	CScrollBarApp();

// オーバーライド
	public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CScrollBarApp theApp;