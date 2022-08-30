// CButtonDlg.h : ヘッダー ファイル
//

#pragma once


// CButtonDlg ダイアログ
class CButtonDlg : public CDialog
{
// コンストラクション
public:
	CButtonDlg(CWnd* pParent = NULL);	// 標準コンストラクタ

// ダイアログ データ
	enum { IDD = IDD_CBUTTON_DIALOG };

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
	CWnd *m_pButton1;		// CWndオブジェクトポインタm_pButton1
	CButton *m_pButton2;	// CButtonオブジェクトポインタm_pButton2
};
