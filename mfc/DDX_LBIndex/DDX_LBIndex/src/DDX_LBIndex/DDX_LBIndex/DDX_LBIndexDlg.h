// DDX_LBIndexDlg.h : ヘッダー ファイル
//

#pragma once
#include "afxwin.h"


// CDDX_LBIndexDlg ダイアログ
class CDDX_LBIndexDlg : public CDialog
{
// コンストラクション
public:
	CDDX_LBIndexDlg(CWnd* pParent = NULL);	// 標準コンストラクタ

// ダイアログ データ
	enum { IDD = IDD_DDX_LBINDEX_DIALOG };

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
	int m_xvListBox1;
	CListBox m_xcListBox1;
	afx_msg void OnBnClickedButton1();
};
