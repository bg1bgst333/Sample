// CCmdTarget_.h : CCmdTarget_ アプリケーションのメイン ヘッダー ファイル
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"       // メイン シンボル


// CCmdTarget_App:
// このクラスの実装については、CCmdTarget_.cpp を参照してください。
//

class CCmdTarget_App : public CWinApp
{
public:
	CCmdTarget_App();


// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCmdTarget_App theApp;