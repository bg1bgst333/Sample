// AfxFindMessageEntry.h : AfxFindMessageEntry アプリケーションのメイン ヘッダー ファイル
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"       // メイン シンボル


// CAfxFindMessageEntryApp:
// このクラスの実装については、AfxFindMessageEntry.cpp を参照してください。
//

class CAfxFindMessageEntryApp : public CWinApp
{
public:
	CAfxFindMessageEntryApp();


// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CAfxFindMessageEntryApp theApp;