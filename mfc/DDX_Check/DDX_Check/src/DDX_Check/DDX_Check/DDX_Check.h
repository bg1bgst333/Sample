// DDX_Check.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです。
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CDDX_CheckApp:
// このクラスの実装については、DDX_Check.cpp を参照してください。
//

class CDDX_CheckApp : public CWinApp
{
public:
	CDDX_CheckApp();

// オーバーライド
	public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CDDX_CheckApp theApp;