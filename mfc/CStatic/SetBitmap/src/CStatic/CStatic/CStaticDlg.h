// CStaticDlg.h : �w�b�_�[ �t�@�C��
//

#pragma once


// CStaticDlg �_�C�A���O
class CStaticDlg : public CDialog
{
// �R���X�g���N�V����
public:
	CStaticDlg(CWnd* pParent = NULL);	// �W���R���X�g���N�^

// �_�C�A���O �f�[�^
	enum { IDD = IDD_CSTATIC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �T�|�[�g


// ����
protected:
	HICON m_hIcon;

	// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();

// �ǉ�
public:
	CStatic *m_pStatic1;	// CStatic�I�u�W�F�N�g�|�C���^m_pStatic1
	CBitmap *m_pBitmap1;	// CBitmap�I�u�W�F�N�g�|�C���^m_pBitmap1
};
