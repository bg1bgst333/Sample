// �w�b�_�t�@�C���̃C���N���[�h
#include "CFrameWnd_.h"	// CFrameWnd_�N���X
#include "resource.h"	// ���\�[�XID

// CFrameWnd_�̃��b�Z�[�W�}�b�v
BEGIN_MESSAGE_MAP(CFrameWnd_, CFrameWnd)
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

	// 0�Ԗڂ̃T�u���j���[���ڂ̐����擾.
	CMenu *pMenu = GetMenu();	// ���j���[�̎擾.
	CMenu *pSubMenu = pMenu->GetSubMenu(0);	// 0�Ԗڂ̃T�u���j���[�擾.
	UINT uiCount = pSubMenu->GetMenuItemCount();	// pSubMenu->GetMenuItemCount�ō��ڐ��擾.
	TCHAR tszCount[16] = {0};	// TCHAR�^�����z��tszCount��{0}�ŏ�����.
	_stprintf(tszCount, _T("%lu"), uiCount);	// ������������uiCount�𕶎���tszCount�ɕϊ�.
	AfxMessageBox(tszCount);	// tszCount��\��.

}

// �n���h��OnUpdateItem1_2()
void CFrameWnd_::OnUpdateItem1_2(CCmdUI* pCmdUI){	// ���j���[����Item1_2��UI�X�V�n���h��

	// ���j���[����Item1_2��UI�X�V
	if (pCmdUI){	// pCmdUI��NULL�łȂ��Ȃ�.

		// ���j���[����Item1_2�̗L����
		pCmdUI->Enable();	// Enable��Item1_2��L���ɂ���.(�f�t�H���g������TRUE.)

	}

}

// �n���h��OnItem1_2()
void CFrameWnd_::OnItem1_2(){	// ���j���[����Item1_2�̃R�}���h�n���h��

}

// �n���h��OnUpdateItem1_3()
void CFrameWnd_::OnUpdateItem1_3(CCmdUI* pCmdUI){	// ���j���[����Item1_3��UI�X�V�n���h��

	// ���j���[����Item1_3��UI�X�V
	if (pCmdUI){	// pCmdUI��NULL�łȂ��Ȃ�.

		// ���j���[����Item1_3�̗L����
		pCmdUI->Enable();	// Enable��Item1_3��L���ɂ���.(�f�t�H���g������TRUE.)

	}

}

// �n���h��OnItem1_3()
void CFrameWnd_::OnItem1_3(){	// ���j���[����Item1_3�̃R�}���h�n���h��

}

// �n���h��OnUpdateItem1_4()
void CFrameWnd_::OnUpdateItem1_4(CCmdUI* pCmdUI){	// ���j���[����Item1_4��UI�X�V�n���h��

	// ���j���[����Item1_4��UI�X�V
	if (pCmdUI){	// pCmdUI��NULL�łȂ��Ȃ�.

		// ���j���[����Item1_4�̗L����
		pCmdUI->Enable();	// Enable��Item1_4��L���ɂ���.(�f�t�H���g������TRUE.)

	}

}

// �n���h��OnItem1_4()
void CFrameWnd_::OnItem1_4(){	// ���j���[����Item1_4�̃R�}���h�n���h��

}