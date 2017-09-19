// DDX_CBString.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです。
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CDDX_CBStringApp:
// このクラスの実装については、DDX_CBString.cpp を参照してください。
//

class CDDX_CBStringApp : public CWinApp
{
public:
	CDDX_CBStringApp();

// オーバーライド
	public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CDDX_CBStringApp theApp;