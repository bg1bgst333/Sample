// DDX_LBString.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです。
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CDDX_LBStringApp:
// このクラスの実装については、DDX_LBString.cpp を参照してください。
//

class CDDX_LBStringApp : public CWinApp
{
public:
	CDDX_LBStringApp();

// オーバーライド
	public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CDDX_LBStringApp theApp;