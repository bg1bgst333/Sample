// �w�b�_�t�@�C���̃C���N���[�h
#include "CFrameWnd_.h"	// CFrameWnd_�N���X
#include "resource.h"	// ���\�[�XID

// CFrameWnd_�̃��b�Z�[�W�}�b�v
BEGIN_MESSAGE_MAP(CFrameWnd_, CFrameWnd)
	ON_UPDATE_COMMAND_UI(ID_ITEM_1_1, OnUpdateItem1_1)	// ���j���[���ڂȂǂ�UI�X�V�}�N��.(Item1_1)
	ON_COMMAND(ID_ITEM_1_1, OnItem1_1)	// ���j���[���ڂȂǂ̃R�}���h�}�N��.(Item1_1)
END_MESSAGE_MAP()

// CFrameWnd_�̃����o�̒�`
// �R���X�g���N�^CFrameWnd_()
CFrameWnd_::CFrameWnd_(){	// ����������

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

	// ���j���[�̍����ւ�.
	m_pMenu = GetMenu();	// CWnd::GetMenu��m_pMenu���擾.
	SetMenu(NULL);	// CWnd::SetMenu(NULL)�Ń��j���[���O��.
	m_pMenu->DestroyMenu();	// CMenu::DestroyMenu�Ń��j���[��j��.
	CMenu cNewMenu;	// CMenu�I�u�W�F�N�gcNewMenu.
	cNewMenu.CreateMenu();	// cNewMenu.CreateMenu�Ń��j���[�쐬.
	cNewMenu.AppendMenu(MF_ENABLED | MF_STRING, 102, _T("Item2"));	// cNewMenu.AppendMenu��Item2��ǉ�.
	m_pMenu = &cNewMenu;	// m_pMenu��cNewMenu�̃A�h���X���i�[.
	SetMenu(m_pMenu);	// SetMenu��m_pMenu���Z�b�g.

}