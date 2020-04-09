// CDocTemplate.h : CDocTemplate アプリケーションのメイン ヘッダー ファイル
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"       // メイン シンボル


// CDocTemplateApp:
// このクラスの実装については、CDocTemplate.cpp を参照してください。
//

class CDocTemplateApp : public CWinApp
{
public:
	CDocTemplateApp();


// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDocTemplateApp theApp;