// CBitmapDlg.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "CBitmap.h"
#include "CBitmapDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBitmapDlg �_�C�A���O




CBitmapDlg::CBitmapDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBitmapDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBitmapDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CBitmapDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CBitmapDlg ���b�Z�[�W �n���h��

BOOL CBitmapDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���̃_�C�A���O�̃A�C�R����ݒ肵�܂��B�A�v���P�[�V�����̃��C�� �E�B���h�E���_�C�A���O�łȂ��ꍇ�A
	//  Framework �́A���̐ݒ�������I�ɍs���܂��B
	SetIcon(m_hIcon, TRUE);			// �傫���A�C�R���̐ݒ�
	SetIcon(m_hIcon, FALSE);		// �������A�C�R���̐ݒ�

	// TODO: �������������ɒǉ����܂��B
	CBitmap *pBitmap = new CBitmap();	// CBitmap�I�u�W�F�N�g�𐶐���, �|�C���^��pBitmap�Ɋi�[.
	BOOL bRet = pBitmap->LoadBitmap(IDB_BITMAP1);	// CBitmap::LoadBitmap��IDB_BITMAP1�����[�h.
	if (bRet){	// ����.
		AfxMessageBox(_T("CBitmap::LoadBitmap Success!"));	// "CBitmap::LoadBitmap Success!"�ƕ\��.
	}
	else{	// ���s.
		AfxMessageBox(_T("CBitmap::LoadBitmap Failed!"));	// "CBitmap::LoadBitmap Failed!"�ƕ\��.
	}
	delete pBitmap;	// pBitmap�����.

	return TRUE;  // �t�H�[�J�X���R���g���[���ɐݒ肵���ꍇ�������ATRUE ��Ԃ��܂��B
}

// �_�C�A���O�ɍŏ����{�^����ǉ�����ꍇ�A�A�C�R����`�悷�邽�߂�
//  ���̃R�[�h���K�v�ł��B�h�L�������g/�r���[ ���f�����g�� MFC �A�v���P�[�V�����̏ꍇ�A
//  ����́AFramework �ɂ���Ď����I�ɐݒ肳��܂��B

void CBitmapDlg::OnPaint()
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
HCURSOR CBitmapDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

