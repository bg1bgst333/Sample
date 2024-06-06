// �w�b�_�t�@�C���̃C���N���[�h
#include "CFrameWnd_.h"	// CFrameWnd_�N���X
#include "resource.h"	// ���\�[�XID

// CFrameWnd_�̃��b�Z�[�W�}�b�v
BEGIN_MESSAGE_MAP(CFrameWnd_, CFrameWnd)
	ON_WM_PAINT()	// OnPaint�̃��b�Z�[�W�}�N��
	ON_COMMAND_RANGE(ID_ITEM_1_1, ID_ITEM_1_4, &OnRangeCmds)	// ���j���[���W�I�{�^���p�̃}�N��(����ID��ON_COMMAND�Ƃ͗����ł��Ȃ��݂����Ȃ̂Œ���!)
END_MESSAGE_MAP()

// CFrameWnd_�̃����o�̒�`
// �R���X�g���N�^CFrameWnd_()
CFrameWnd_::CFrameWnd_(){	// ����������

	// �����o�̏�����.
	m_bInitMenu = FALSE;	// m_bInitMenu��FALSE�ɏ�����.
	m_bAutoMenuEnable = FALSE;	// ������w�肵�Ȃ��Ɩ�����O���[�A�E�g�ɂȂ�Ȃ��̂Œ���!

}

// ���b�Z�[�W�n���h��OnPaint()
void CFrameWnd_::OnPaint(){	// ��ʂ̕`���v�����ꂽ��.

	// �ϐ��̐錾
	HDC hDC;		// ���̃E�B���h�E�̃f�o�C�X�R���e�L�X�g�n���h��hDC.
	PAINTSTRUCT ps;	// �y�C���g�����Ǘ�����PAINTSTRUCT�\���̕ϐ�ps.

	// ���j���[�̏�����.
	if (!m_bInitMenu){	// FALSE�Ȃ珉����.

		// ����������.
		m_bInitMenu = TRUE;	// TRUE���Z�b�g.
		
	}

	// ������̕`��
	hDC = ::BeginPaint(m_hWnd, &ps);	// WindowsAPI��BeginPaint�ŕ`��̏�������, �f�o�C�X�R���e�L�X�g�n���h�����擾.
	::EndPaint(m_hWnd, &ps);	// WindowsAPI��EndPaint�ŕ`����I��.

}

// �n���h��OnRangeCmds(UINT nID)
void CFrameWnd_::OnRangeCmds(UINT nID){	// �͈͓��̂ǂꂩ���I�����ꂽ���̃R�}���h�n���h��.

	// nID�ƍ���ID���r.
	if (nID == ID_ITEM_1_1){
		AfxMessageBox(_T("ID_ITEM_1_1"));
	}
	if (nID == ID_ITEM_1_2){
		AfxMessageBox(_T("ID_ITEM_1_2"));
	}
	if (nID == ID_ITEM_1_3){
		AfxMessageBox(_T("ID_ITEM_1_3"));
	}
	if (nID == ID_ITEM_1_4){
		AfxMessageBox(_T("ID_ITEM_1_4"));
	}

}