// CCmdTarget.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです。
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CCmdTargetApp:
// このクラスの実装については、CCmdTarget.cpp を参照してください。
//

class CCmdTargetApp : public CWinApp
{
public:
	CCmdTargetApp();

// オーバーライド
	public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CCmdTargetApp theApp;