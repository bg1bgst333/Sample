// DDX_ControlDlg.h : ヘッダー ファイル
//

#pragma once
#include "afxwin.h"


// CDDX_ControlDlg ダイアログ
class CDDX_ControlDlg : public CDialog
{
// コンストラクション
public:
	CDDX_ControlDlg(CWnd* pParent = NULL);	// 標準コンストラクタ

// ダイアログ データ
	enum { IDD = IDD_DDX_CONTROL_DIALOG };

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
	CListBox m_xcListBox1;
	afx_msg void OnBnClickedButton1();
};
