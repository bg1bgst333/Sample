// CDocManager.h : CDocManager アプリケーションのメイン ヘッダー ファイル
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"       // メイン シンボル


// CDocManagerApp:
// このクラスの実装については、CDocManager.cpp を参照してください。
//

class CDocManagerApp : public CWinApp
{
public:
	CDocManagerApp();


// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDocManagerApp theApp;