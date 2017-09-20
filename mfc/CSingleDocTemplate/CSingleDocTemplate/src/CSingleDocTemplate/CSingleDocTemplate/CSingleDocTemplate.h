// CSingleDocTemplate.h : CSingleDocTemplate アプリケーションのメイン ヘッダー ファイル
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"       // メイン シンボル


// CSingleDocTemplateApp:
// このクラスの実装については、CSingleDocTemplate.cpp を参照してください。
//

class CSingleDocTemplateApp : public CWinApp
{
public:
	CSingleDocTemplateApp();


// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSingleDocTemplateApp theApp;