// DDX_Control.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです。
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CDDX_ControlApp:
// このクラスの実装については、DDX_Control.cpp を参照してください。
//

class CDDX_ControlApp : public CWinApp
{
public:
	CDDX_ControlApp();

// オーバーライド
	public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CDDX_ControlApp theApp;