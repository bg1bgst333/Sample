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
	ON_WM_HSCROLL()
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
	// �X�N���[���o�[�̏�����.
	CScrollBar *pScrollBar1 = (CScrollBar *)GetDlgItem(IDC_SCROLLBAR1);	// GetDlgItem�ŃX�N���[���o�[�R���g���[��IDC_SCROLLBAR1�̃I�u�W�F�N�g�|�C���^��pScrollBar1�Ɋi�[.((CScrollBar *)�ɃL���X�g.)
	pScrollBar1->SetScrollRange(0, 100);	// pScrollBar1->SetScrollRange�Ŕ͈͂�0�`100�ɂ���.
	pScrollBar1->SetScrollPos(0);	// pScrollBar1->SetScrollPos�ňʒu��0�ɂ���.

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


void CWnd_Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �����Ƀ��b�Z�[�W �n���h�� �R�[�h��ǉ����邩�A����̏������Ăяo���܂��B
	// �n���ꂽCScrollBar�I�u�W�F�N�g�|�C���^��NULL�̎�.
	if (pScrollBar == NULL){	// pScrollBar��NULL�̎�.
		CDialog::OnHScroll(nSBCode, nPos, pScrollBar);	// ������CDialog::OnHScroll�ɓn���ĔC����.
		return;	// �����ŏI��.
	}
	// �X�N���[���o�[�̈ʒu�X�V.
	int iNewPos = pScrollBar->GetScrollPos();	// �X�V��̈ʒuiNewPos���ЂƂ܂�pScrollBar->GetScrollPos(), �܂茻�݈ʒu�ɂ���.
	int iMinPos = 0;	// �ŏ��liMinPos.
	int iMaxPos = 0;	// �ő�liMaxPos.
	pScrollBar->GetScrollRange(&iMinPos, &iMaxPos);	// pScrollBar->GetScrollRange�ōŏ��l, �ő�l���擾.
	switch (nSBCode){	// nSBCode�̒l�ŐU�蕪��.
		case SB_THUMBTRACK:		// �X�N���[���܂݂���������.
		case SB_THUMBPOSITION:	// �X�N���[���܂݂������ꂽ��.
			iNewPos = (int)nPos;	// iNewPos��nPos���Z�b�g.(�X�V���nPos.)
			break;
		case SB_LEFT:	// ���[�̎�.
			iNewPos = iMinPos;	// iNewPos��iMinPos���Z�b�g.
			break;
		case SB_RIGHT:	// �E�[�̎�.
			iNewPos = iMaxPos;	// iNewPos��iMaxPos���Z�b�g.
			break;
		case SB_LINERIGHT:	// �E�[�̃{�^��������.
			if ((int)nPos < iMaxPos - 1 + 1){	// �ő�l��菬�����Ȃ牺������.(�����1�s��1�y�[�W�Ƃ���.)
				iNewPos++;	// 1���₷.
			}
			break;
		case SB_LINELEFT:	//	���[�̃{�^��������.
			if ((int)nPos > iMinPos){	// �ŏ��l���傫���Ȃ�グ����.(�����1�s��1�y�[�W.)
				iNewPos--;	// 1���炷.
			}
			break;
		case SB_PAGERIGHT:	// �E�̗]��������.
			iNewPos += 1;	// 1�y�[�W�����₷.(�����1�s������.)
			break;
		case SB_PAGELEFT:	// ���̗]��������.
			iNewPos -= 1;	// 1�y�[�W�����炷.(�����1�s�グ��.)
			break;
		default:
			break;
	}
	// �V�����ʒu���Z�b�g.
	pScrollBar->SetScrollPos(iNewPos);	// pScrollBar->SetScrollPos��iNewPos���Z�b�g.
	// ���Ɛe�N���X��OnHScroll�ɔC����.
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
