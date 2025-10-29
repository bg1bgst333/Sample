// CWnd_Dlg.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "CWnd_.h"
#include "CWnd_Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWnd_Dlg �_�C�A���O




CWnd_Dlg::CWnd_Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWnd_Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWnd_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CWnd_Dlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CWnd_Dlg ���b�Z�[�W �n���h��

BOOL CWnd_Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���̃_�C�A���O�̃A�C�R����ݒ肵�܂��B�A�v���P�[�V�����̃��C�� �E�B���h�E���_�C�A���O�łȂ��ꍇ�A
	//  Framework �́A���̐ݒ�������I�ɍs���܂��B
	SetIcon(m_hIcon, TRUE);			// �傫���A�C�R���̐ݒ�
	SetIcon(m_hIcon, FALSE);		// �������A�C�R���̐ݒ�

	// TODO: �������������ɒǉ����܂��B

	return TRUE;  // �t�H�[�J�X���R���g���[���ɐݒ肵���ꍇ�������ATRUE ��Ԃ��܂��B
}

// �_�C�A���O�ɍŏ����{�^����ǉ�����ꍇ�A�A�C�R����`�悷�邽�߂�
//  ���̃R�[�h���K�v�ł��B�h�L�������g/�r���[ ���f�����g�� MFC �A�v���P�[�V�����̏ꍇ�A
//  ����́AFramework �ɂ���Ď����I�ɐݒ肳��܂��B

void CWnd_Dlg::OnPaint()
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
HCURSOR CWnd_Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CWnd_Dlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: �����Ƀ��b�Z�[�W �n���h�� �R�[�h��ǉ����܂��B
	// �������L���v�V�����ɕ\��.
	TCHAR tszSize[1024] = {0};	// tszSize(����1024)��{0}�ŏ�����.
	_stprintf(tszSize, _T("nType = %lu, cx = %d, cy = %d"), nType, cx, cy);	// _stprintf��nType, cx, cy���e�L�X�gtszSize�ɕϊ�.
	SetWindowText(tszSize);	// SetWindowText��tszSize���L���v�V�����ɃZ�b�g.

	// �G�f�B�b�g�{�b�N�X�̃T�C�Y���E�B���h�E�ɒǐ�����悤��.
	CWnd *pEdit1 = GetDlgItem(IDC_EDIT1);
	RECT rc = {0};
	rc.left = 221;
	rc.top = 21;
	rc.right = cx - 10;
	rc.bottom = cy - 10;
	pEdit1->MoveWindow(&rc);	// CWnd::MoveWindow��pEdit1��rc�̋�`�ɏ]���Ĉړ�&���T�C�Y.

}

BOOL CWnd_Dlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: �����Ƀ��b�Z�[�W �n���h�� �R�[�h��ǉ����邩�A����̏������Ăяo���܂��B
	RECT rc = {0};
	::GetClientRect(m_hWnd, &rc);
	HBRUSH hBrush = ::CreateSolidBrush(RGB(255, 0, 0));
	HPEN hPen = ::CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	HBRUSH hOldBrush = (HBRUSH)::SelectObject(pDC->m_hDC, hBrush);
	HPEN hOldPen = (HPEN)::SelectObject(pDC->m_hDC, hPen);
	::Rectangle(pDC->m_hDC, rc.left, rc.top, rc.right, rc.bottom);
	::SelectObject(pDC->m_hDC, hOldPen);
	::SelectObject(pDC->m_hDC, hOldBrush);
	::DeleteObject(hPen);
	::DeleteObject(hBrush);
	return TRUE;
	//return CDialog::OnEraseBkgnd(pDC);
}
