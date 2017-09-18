// DDX_LBStringDlg.h : ヘッダー ファイル
//

#pragma once
#include "afxwin.h"


// CDDX_LBStringDlg ダイアログ
class CDDX_LBStringDlg : public CDialog
{
// コンストラクション
public:
	CDDX_LBStringDlg(CWnd* pParent = NULL);	// 標準コンストラクタ

// ダイアログ データ
	enum { IDD = IDD_DDX_LBSTRING_DIALOG };

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
	CString m_xvListBox1;
	CListBox m_xcListBox1;
	afx_msg void OnBnClickedButton1();
};
