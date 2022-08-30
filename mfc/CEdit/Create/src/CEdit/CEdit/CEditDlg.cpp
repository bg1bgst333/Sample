// CEditDlg.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "CEdit.h"
#include "CEditDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEditDlg �_�C�A���O




CEditDlg::CEditDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CEditDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CEditDlg ���b�Z�[�W �n���h��

BOOL CEditDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���̃_�C�A���O�̃A�C�R����ݒ肵�܂��B�A�v���P�[�V�����̃��C�� �E�B���h�E���_�C�A���O�łȂ��ꍇ�A
	//  Framework �́A���̐ݒ�������I�ɍs���܂��B
	SetIcon(m_hIcon, TRUE);			// �傫���A�C�R���̐ݒ�
	SetIcon(m_hIcon, FALSE);		// �������A�C�R���̐ݒ�

	// TODO: �������������ɒǉ����܂��B
	m_pEdit1 = new CWnd();	// CWnd�I�u�W�F�N�g�𐶐���, �|�C���^��m_pEdit1�Ɋi�[.
	RECT rc1 = {50, 50, 150, 100};	// RECT�\����rc1��{50, 50, 150, 100}�ŏ�����.
	m_pEdit1->Create(_T("EDIT"), _T("Edit1"), WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_WANTRETURN | ES_AUTOHSCROLL | ES_AUTOVSCROLL, rc1, this, WM_APP + 1);	// m_pEdit1->Create�ŃE�B���h�E����.
	m_pEdit2 = new CEdit();	// CEdit�I�u�W�F�N�g�𐶐���, �|�C���^��m_pEdit2�Ɋi�[.
	RECT rc2 = {50, 150, 150, 200};	// RECT�\����rc2��{50, 150, 150, 200}�ŏ�����.
	m_pEdit2->Create(WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_WANTRETURN | ES_AUTOHSCROLL | ES_AUTOVSCROLL, rc2, this, WM_APP + 2);	// m_pEdit2->Create�ŃE�B���h�E����.

	return TRUE;  // �t�H�[�J�X���R���g���[���ɐݒ肵���ꍇ�������ATRUE ��Ԃ��܂��B
}

// �_�C�A���O�ɍŏ����{�^����ǉ�����ꍇ�A�A�C�R����`�悷�邽�߂�
//  ���̃R�[�h���K�v�ł��B�h�L�������g/�r���[ ���f�����g�� MFC �A�v���P�[�V�����̏ꍇ�A
//  ����́AFramework �ɂ���Ď����I�ɐݒ肳��܂��B

void CEditDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �`��̃f�o�C�X �R���e�L�X�g

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// �N���C�A���g�̎l�p�`�̈���̒���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �A�C�R���̕`��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// ���[�U�[���ŏ��������E�B���h�E���h���b�O���Ă���Ƃ��ɕ\������J�[�\�����擾���邽�߂ɁA
//  �V�X�e�������̊֐����Ăяo���܂��B
HCURSOR CEditDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CEditDlg::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: �����Ƀ��b�Z�[�W �n���h�� �R�[�h��ǉ����܂��B
	if (m_pEdit1 != NULL){	// NULL�łȂ�.
		delete m_pEdit1;	// delete��m_pEdit1�����.
		m_pEdit1 = NULL;	// m_pEdit1��NULL����.
	}
	if (m_pEdit2 != NULL){	// NULL�łȂ�.
		delete m_pEdit2;	// delete��m_pEdit2�����.
		m_pEdit2 = NULL;	// m_pEdit2��NULL����.
	}
}
