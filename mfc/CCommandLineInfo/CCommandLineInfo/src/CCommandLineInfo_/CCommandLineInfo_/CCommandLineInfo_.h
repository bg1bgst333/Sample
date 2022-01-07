// CCommandLineInfo_.h : CCommandLineInfo_ アプリケーションのメイン ヘッダー ファイル
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"       // メイン シンボル


// CCommandLineInfo_App:
// このクラスの実装については、CCommandLineInfo_.cpp を参照してください。
//

class CCommandLineInfo_App : public CWinApp
{
public:
	CCommandLineInfo_App();


// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCommandLineInfo_App theApp;