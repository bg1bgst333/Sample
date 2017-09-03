// DDX_Radio.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです。
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CDDX_RadioApp:
// このクラスの実装については、DDX_Radio.cpp を参照してください。
//

class CDDX_RadioApp : public CWinApp
{
public:
	CDDX_RadioApp();

// オーバーライド
	public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CDDX_RadioApp theApp;