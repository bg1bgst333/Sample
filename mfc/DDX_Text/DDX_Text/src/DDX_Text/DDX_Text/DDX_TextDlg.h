// DDX_TextDlg.h : ヘッダー ファイル
//

#pragma once


// CDDX_TextDlg ダイアログ
class CDDX_TextDlg : public CDialog
{
// コンストラクション
public:
	CDDX_TextDlg(CWnd* pParent = NULL);	// 標準コンストラクタ

// ダイアログ データ
	enum { IDD = IDD_DDX_TEXT_DIALOG };

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
	int m_xvEdit1;
	int m_xvEdit2;
	afx_msg void OnBnClickedButton1();
};
