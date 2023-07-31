// _AfxDispatchCmdMsg.h : _AfxDispatchCmdMsg アプリケーションのメイン ヘッダー ファイル
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"       // メイン シンボル


// C_AfxDispatchCmdMsgApp:
// このクラスの実装については、_AfxDispatchCmdMsg.cpp を参照してください。
//

class C_AfxDispatchCmdMsgApp : public CWinApp
{
public:
	C_AfxDispatchCmdMsgApp();


// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C_AfxDispatchCmdMsgApp theApp;