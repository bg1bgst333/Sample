// CEditDlg.h : ヘッダー ファイル
//

#pragma once


// CEditDlg ダイアログ
class CEditDlg : public CDialog
{
// コンストラクション
public:
	CEditDlg(CWnd* pParent = NULL);	// 標準コンストラクタ

// ダイアログ データ
	enum { IDD = IDD_CEDIT_DIALOG };

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
	afx_msg void OnDestroy();

// 追加
public:
	CWnd *m_pEdit1;		// CWndオブジェクトポインタm_pEdit1
	CEdit *m_pEdit2;	// CEditオブジェクトポインタm_pEdit2
};
