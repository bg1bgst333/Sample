// CStaticDlg.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "CStatic.h"
#include "CStaticDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStaticDlg �_�C�A���O




CStaticDlg::CStaticDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStaticDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStaticDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CStaticDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CStaticDlg ���b�Z�[�W �n���h��

BOOL CStaticDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���̃_�C�A���O�̃A�C�R����ݒ肵�܂��B�A�v���P�[�V�����̃��C�� �E�B���h�E���_�C�A���O�łȂ��ꍇ�A
	//  Framework �́A���̐ݒ�������I�ɍs���܂��B
	SetIcon(m_hIcon, TRUE);			// �傫���A�C�R���̐ݒ�
	SetIcon(m_hIcon, FALSE);		// �������A�C�R���̐ݒ�

	// TODO: �������������ɒǉ����܂��B
	m_pStatic1 = new CWnd();	// CWnd�I�u�W�F�N�g�𐶐���, �|�C���^��m_pStatic1�Ɋi�[.
	RECT rc1 = {50, 50, 150, 100};	// RECT�\����rc1��{50, 50, 150, 100}�ŏ�����.
	m_pStatic1->Create(_T("STATIC"), _T("Static1"), WS_CHILD | WS_VISIBLE | SS_LEFT, rc1, this, WM_APP + 1);	// m_pStatic1->Create�ŃE�B���h�E����.
	m_pStatic2 = new CStatic();	// CStatic�I�u�W�F�N�g�𐶐���, �|�C���^��m_pStatic2�Ɋi�[.
	RECT rc2 = {50, 150, 150, 200};	// RECT�\����rc2��{50, 150, 150, 200}�ŏ�����.
	m_pStatic2->Create(_T("Static2"), WS_CHILD | WS_VISIBLE | SS_LEFT, rc2, this);	// m_pStatic2->Create�ŃE�B���h�E����.

	return TRUE;  // �t�H�[�J�X���R���g���[���ɐݒ肵���ꍇ�������ATRUE ��Ԃ��܂��B
}

// �_�C�A���O�ɍŏ����{�^����ǉ�����ꍇ�A�A�C�R����`�悷�邽�߂�
//  ���̃R�[�h���K�v�ł��B�h�L�������g/�r���[ ���f�����g�� MFC �A�v���P�[�V�����̏ꍇ�A
//  ����́AFramework �ɂ���Ď����I�ɐݒ肳��܂��B

void CStaticDlg::OnPaint()
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
HCURSOR CStaticDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CStaticDlg::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: �����Ƀ��b�Z�[�W �n���h�� �R�[�h��ǉ����܂��B
	if (m_pStatic1 != NULL){	// NULL�łȂ�.
		delete m_pStatic1;	// delete��m_pStatic1�����.
		m_pStatic1 = NULL;	// m_pStatic1��NULL����.
	}
	if (m_pStatic2 != NULL){	// NULL�łȂ�.
		delete m_pStatic2;	// delete��m_pStatic2�����.
		m_pStatic2 = NULL;	// m_pStatic2��NULL����.
	}
}
