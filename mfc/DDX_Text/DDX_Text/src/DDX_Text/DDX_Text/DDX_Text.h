// DDX_Text.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです。
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CDDX_TextApp:
// このクラスの実装については、DDX_Text.cpp を参照してください。
//

class CDDX_TextApp : public CWinApp
{
public:
	CDDX_TextApp();

// オーバーライド
	public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CDDX_TextApp theApp;