// DDX_LBIndex.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです。
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CDDX_LBIndexApp:
// このクラスの実装については、DDX_LBIndex.cpp を参照してください。
//

class CDDX_LBIndexApp : public CWinApp
{
public:
	CDDX_LBIndexApp();

// オーバーライド
	public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CDDX_LBIndexApp theApp;