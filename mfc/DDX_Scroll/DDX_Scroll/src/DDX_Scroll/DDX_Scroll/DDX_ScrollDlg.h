// DDX_ScrollDlg.h : ヘッダー ファイル
//

#pragma once
#include "afxwin.h"


// CDDX_ScrollDlg ダイアログ
class CDDX_ScrollDlg : public CDialog
{
// コンストラクション
public:
	CDDX_ScrollDlg(CWnd* pParent = NULL);	// 標準コンストラクタ

// ダイアログ データ
	enum { IDD = IDD_DDX_SCROLL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート


// 実装
protected:
	HICON m_hIcon;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CScrollBar m_xcScrollBar1;
	int m_xvScrollBar1;
	afx_msg void OnBnClickedButton1();
};
