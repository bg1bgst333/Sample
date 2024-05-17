// �w�b�_�t�@�C���̃C���N���[�h
#include "CFrameWnd_.h"	// CFrameWnd_�N���X
#include "resource.h"	// ���\�[�XID

// CFrameWnd_�̃��b�Z�[�W�}�b�v
BEGIN_MESSAGE_MAP(CFrameWnd_, CFrameWnd)
	ON_UPDATE_COMMAND_UI(ID_ITEM_1_1, OnUpdateItem1_1)	// ���j���[���ڂȂǂ�UI�X�V�}�N��.(Item1_1)
	ON_COMMAND(ID_ITEM_1_1, OnItem1_1)	// ���j���[���ڂȂǂ̃R�}���h�}�N��.(Item1_1)
	ON_WM_PAINT()	// OnPaint�̃��b�Z�[�W�}�N��
END_MESSAGE_MAP()

// CFrameWnd_�̃����o�̒�`
// �R���X�g���N�^CFrameWnd_()
CFrameWnd_::CFrameWnd_(){	// ����������

	// �����o�̏�����.
	m_pMenu = NULL;	// m_pMenu��NULL�ɏ�����.

}

// �n���h��OnUpdateItem1_1()
void CFrameWnd_::OnUpdateItem1_1(CCmdUI* pCmdUI){	// ���j���[����Item1_1��UI�X�V�n���h��

	// ���j���[����Item1_1��UI�X�V
	if (pCmdUI){	// pCmdUI��NULL�łȂ��Ȃ�.

		// ���j���[����Item1_1�̗L����
		pCmdUI->Enable();	// Enable��Item1_1��L���ɂ���.(�f�t�H���g������TRUE.)

	}

}

// �n���h��OnItem1_1()
void CFrameWnd_::OnItem1_1(){	// ���j���[����Item1_1�̃R�}���h�n���h��

}

// ���b�Z�[�W�n���h��OnPaint()
void CFrameWnd_::OnPaint(){	// ��ʂ̕`���v�����ꂽ��.

	// �ϐ��̐錾
	HDC hDC;		// ���̃E�B���h�E�̃f�o�C�X�R���e�L�X�g�n���h��hDC.
	PAINTSTRUCT ps;	// �y�C���g�����Ǘ�����PAINTSTRUCT�\���̕ϐ�ps.

	// ���j���[�̏�����.
	if (m_pMenu == NULL){
		CMenu menu;	// CMenu�I�u�W�F�N�gmenu.
		menu.CreateMenu();	// menu.CreateMenu�Ń��j���[�쐬.
		menu.AppendMenu(MF_ENABLED | MF_STRING, 101, _T("Item1"));	// menu.AppendMenu��Item1��ǉ�.
		m_pMenu = &menu;	// m_pMenu��menu�̃A�h���X���i�[.
		SetMenu(m_pMenu);	// SetMenu��m_pMenu���Z�b�g.
	}

	// ������̕`��
	hDC = ::BeginPaint(m_hWnd, &ps);	// WindowsAPI��BeginPaint�ŕ`��̏�������, �f�o�C�X�R���e�L�X�g�n���h�����擾.
	::EndPaint(m_hWnd, &ps);	// WindowsAPI��EndPaint�ŕ`����I��.

}