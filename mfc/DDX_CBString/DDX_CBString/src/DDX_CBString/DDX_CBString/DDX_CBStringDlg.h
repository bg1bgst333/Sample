// DDX_CBStringDlg.h : ヘッダー ファイル
//

#pragma once
#include "afxwin.h"


// CDDX_CBStringDlg ダイアログ
class CDDX_CBStringDlg : public CDialog
{
// コンストラクション
public:
	CDDX_CBStringDlg(CWnd* pParent = NULL);	// 標準コンストラクタ

// ダイアログ データ
	enum { IDD = IDD_DDX_CBSTRING_DIALOG };

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
	CString m_xvComboBox1;
	afx_msg void OnBnClickedButton1();
};
