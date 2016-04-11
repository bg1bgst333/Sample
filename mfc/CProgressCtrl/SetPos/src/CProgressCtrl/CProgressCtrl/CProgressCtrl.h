// CProgressCtrl.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです。
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CProgressCtrlApp:
// このクラスの実装については、CProgressCtrl.cpp を参照してください。
//

class CProgressCtrlApp : public CWinApp
{
public:
	CProgressCtrlApp();

// オーバーライド
	public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CProgressCtrlApp theApp;