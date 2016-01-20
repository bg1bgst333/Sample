// CWinApp_.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです。
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CWinApp_App:
// このクラスの実装については、CWinApp_.cpp を参照してください。
//

class CWinApp_App : public CWinApp
{
public:
	CWinApp_App();

// オーバーライド
	public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CWinApp_App theApp;