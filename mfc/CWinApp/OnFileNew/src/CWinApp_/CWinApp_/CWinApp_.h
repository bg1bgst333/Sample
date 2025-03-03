// CWinApp_.h : CWinApp_ アプリケーションのメイン ヘッダー ファイル
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"       // メイン シンボル


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
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnFileNew();
};

extern CWinApp_App theApp;