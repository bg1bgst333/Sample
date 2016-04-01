// CComboBox.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです。
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CComboBoxApp:
// このクラスの実装については、CComboBox.cpp を参照してください。
//

class CComboBoxApp : public CWinApp
{
public:
	CComboBoxApp();

// オーバーライド
	public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CComboBoxApp theApp;