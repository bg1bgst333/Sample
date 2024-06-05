// �w�b�_�t�@�C���̃C���N���[�h
#include "CFrameWnd_.h"	// CFrameWnd_�N���X
#include "resource.h"	// ���\�[�XID

// CFrameWnd_�̃��b�Z�[�W�}�b�v
BEGIN_MESSAGE_MAP(CFrameWnd_, CFrameWnd)
	ON_WM_PAINT()	// OnPaint�̃��b�Z�[�W�}�N��
	ON_UPDATE_COMMAND_UI(ID_ITEM_1_1, OnUpdateItem1_1)	// ���j���[���ڂȂǂ�UI�X�V�}�N��.(Item1_1)
	ON_COMMAND(ID_ITEM_1_1, OnItem1_1)	// ���j���[���ڂȂǂ̃R�}���h�}�N��.(Item1_1)
	ON_UPDATE_COMMAND_UI(ID_ITEM_1_2, OnUpdateItem1_2)	// ���j���[���ڂȂǂ�UI�X�V�}�N��.(Item1_2)
	ON_COMMAND(ID_ITEM_1_2, OnItem1_2)	// ���j���[���ڂȂǂ̃R�}���h�}�N��.(Item1_2)
	ON_UPDATE_COMMAND_UI(ID_ITEM_1_3, OnUpdateItem1_3)	// ���j���[���ڂȂǂ�UI�X�V�}�N��.(Item1_3)
	ON_COMMAND(ID_ITEM_1_3, OnItem1_3)	// ���j���[���ڂȂǂ̃R�}���h�}�N��.(Item1_3)
	ON_UPDATE_COMMAND_UI(ID_ITEM_1_4, OnUpdateItem1_4)	// ���j���[���ڂȂǂ�UI�X�V�}�N��.(Item1_4)
	ON_COMMAND(ID_ITEM_1_4, OnItem1_4)	// ���j���[���ڂȂǂ̃R�}���h�}�N��.(Item1_4)
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

// �n���h��OnUpdateItem1_1()
void CFrameWnd_::OnUpdateItem1_1(CCmdUI* pCmdUI){	// ���j���[����Item1_1��UI�X�V�n���h��

}

// �n���h��OnItem1_1()
void CFrameWnd_::OnItem1_1(){	// ���j���[����Item1_1�̃R�}���h�n���h��

	// Item1-1�̏�Ԃ𔻒�.
	CMenu *pMenu = CMenu::FromHandle(m_hMenuDefault);	// CMenu::FromHandle�Ńf�t�H���g���j���[��pMenu�擾.
	CMenu *pSubMenu = pMenu->GetSubMenu(0);	// 0�Ԗڂ̃T�u���j���[�擾.
	UINT uiState1 = pSubMenu->GetMenuState(ID_ITEM_1_1, MF_BYCOMMAND);	// pSubMenu->GetMenuState��uiState1���擾.
	if (uiState1 & MF_CHECKED){	// �`�F�b�N�ς�
		pSubMenu->CheckMenuItem(ID_ITEM_1_1, MF_UNCHECKED | MF_BYCOMMAND);	// pSubMenu->CheckMenuItem�Ń`�F�b�N�O��.
	}
	else{	// ���`�F�b�N
		pSubMenu->CheckMenuItem(ID_ITEM_1_1, MF_CHECKED | MF_BYCOMMAND);	// pSubMenu->CheckMenuItem�Ń`�F�b�N�t����.
	}

}

// �n���h��OnUpdateItem1_2()
void CFrameWnd_::OnUpdateItem1_2(CCmdUI* pCmdUI){	// ���j���[����Item1_2��UI�X�V�n���h��

}

// �n���h��OnItem1_2()
void CFrameWnd_::OnItem1_2(){	// ���j���[����Item1_2�̃R�}���h�n���h��

}

// �n���h��OnUpdateItem1_3()
void CFrameWnd_::OnUpdateItem1_3(CCmdUI* pCmdUI){	// ���j���[����Item1_3��UI�X�V�n���h��

}

// �n���h��OnItem1_3()
void CFrameWnd_::OnItem1_3(){	// ���j���[����Item1_3�̃R�}���h�n���h��

}

// �n���h��OnUpdateItem1_4()
void CFrameWnd_::OnUpdateItem1_4(CCmdUI* pCmdUI){	// ���j���[����Item1_4��UI�X�V�n���h��

}

// �n���h��OnItem1_4()
void CFrameWnd_::OnItem1_4(){	// ���j���[����Item1_4�̃R�}���h�n���h��

	// ���j���[���ڂ̏�Ԃ𔻒�.
	CMenu *pMenu = CMenu::FromHandle(m_hMenuDefault);	// CMenu::FromHandle�Ńf�t�H���g���j���[��pMenu�擾.
	CMenu *pSubMenu = pMenu->GetSubMenu(0);	// 0�Ԗڂ̃T�u���j���[�擾.
	UINT uiState1 = pSubMenu->GetMenuState(ID_ITEM_1_1, MF_BYCOMMAND);	// ID_ITEM_1_1�̏��uiState1���擾.
	if (uiState1 == MF_GRAYED){
		AfxMessageBox(_T("uiState1: MF_GRAYED"));
	}
	UINT uiState2 = pSubMenu->GetMenuState(ID_ITEM_1_2, MF_BYCOMMAND);	// ID_ITEM_1_2�̏��uiState2���擾.
	if (uiState2 == MF_ENABLED){
		AfxMessageBox(_T("uiState2: MF_ENABLED"));
	}
	UINT uiState3 = pSubMenu->GetMenuState(ID_ITEM_1_3, MF_BYCOMMAND);	// ID_ITEM_1_3�̏��uiState3���擾.
	if (uiState3 == MF_DISABLED){
		AfxMessageBox(_T("uiState3: MF_DISABLED"));
	}

}