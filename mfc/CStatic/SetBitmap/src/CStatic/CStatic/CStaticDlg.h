// CStaticDlg.h : ヘッダー ファイル
//

#pragma once


// CStaticDlg ダイアログ
class CStaticDlg : public CDialog
{
// コンストラクション
public:
	CStaticDlg(CWnd* pParent = NULL);	// 標準コンストラクタ

// ダイアログ データ
	enum { IDD = IDD_CSTATIC_DIALOG };

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
	CStatic *m_pStatic1;	// CStaticオブジェクトポインタm_pStatic1
	CBitmap *m_pBitmap1;	// CBitmapオブジェクトポインタm_pBitmap1
};
