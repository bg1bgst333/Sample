// DDX_Text.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです。
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// DDX_TextApp:
// このクラスの実装については、DDX_Text.cpp を参照してください。
//

class DDX_TextApp : public CWinApp
{
public:
	DDX_TextApp();

// オーバーライド
	public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern DDX_TextApp theApp;