// DDX_CheckDlg.h : ヘッダー ファイル
//

#pragma once


// CDDX_CheckDlg ダイアログ
class CDDX_CheckDlg : public CDialog
{
// コンストラクション
public:
	CDDX_CheckDlg(CWnd* pParent = NULL);	// 標準コンストラクタ

// ダイアログ データ
	enum { IDD = IDD_DDX_CHECK_DIALOG };

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
	BOOL m_xvCheck1;
	afx_msg void OnBnClickedButton1();
};
