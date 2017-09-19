// DDX_Scroll.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです。
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CDDX_ScrollApp:
// このクラスの実装については、DDX_Scroll.cpp を参照してください。
//

class CDDX_ScrollApp : public CWinApp
{
public:
	CDDX_ScrollApp();

// オーバーライド
	public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CDDX_ScrollApp theApp;