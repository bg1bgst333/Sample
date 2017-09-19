// DDX_CBIndexDlg.h : ヘッダー ファイル
//

#pragma once
#include "afxwin.h"


// CDDX_CBIndexDlg ダイアログ
class CDDX_CBIndexDlg : public CDialog
{
// コンストラクション
public:
	CDDX_CBIndexDlg(CWnd* pParent = NULL);	// 標準コンストラクタ

// ダイアログ データ
	enum { IDD = IDD_DDX_CBINDEX_DIALOG };

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
	CComboBox m_xcComboBox1;
	int m_xvComboBox1;
	afx_msg void OnBnClickedButton1();
};
