// CEditDlg.h : �w�b�_�[ �t�@�C��
//

#pragma once


// CEditDlg �_�C�A���O
class CEditDlg : public CDialog
{
// �R���X�g���N�V����
public:
	CEditDlg(CWnd* pParent = NULL);	// �W���R���X�g���N�^

// �_�C�A���O �f�[�^
	enum { IDD = IDD_CEDIT_DIALOG };

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
	CWnd *m_pEdit1;		// CWnd�I�u�W�F�N�g�|�C���^m_pEdit1
	CEdit *m_pEdit2;	// CEdit�I�u�W�F�N�g�|�C���^m_pEdit2
};
