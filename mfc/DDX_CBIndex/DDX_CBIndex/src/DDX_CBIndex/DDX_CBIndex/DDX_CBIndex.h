// DDX_CBIndex.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです。
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CDDX_CBIndexApp:
// このクラスの実装については、DDX_CBIndex.cpp を参照してください。
//

class CDDX_CBIndexApp : public CWinApp
{
public:
	CDDX_CBIndexApp();

// オーバーライド
	public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CDDX_CBIndexApp theApp;