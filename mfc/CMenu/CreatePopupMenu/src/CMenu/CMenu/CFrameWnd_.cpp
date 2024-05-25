// �w�b�_�t�@�C���̃C���N���[�h
#include "CFrameWnd_.h"	// CFrameWnd_�N���X
#include "resource.h"	// ���\�[�XID

// CFrameWnd_�̃��b�Z�[�W�}�b�v
BEGIN_MESSAGE_MAP(CFrameWnd_, CFrameWnd)
	ON_WM_PAINT()	// OnPaint�̃��b�Z�[�W�}�N��
	ON_UPDATE_COMMAND_UI(ID_ITEM_1_1, OnUpdateItem1_1)	// ���j���[���ڂȂǂ�UI�X�V�}�N��.(Item1_1)
	ON_COMMAND(ID_ITEM_1_1, OnItem1_1)	// ���j���[���ڂȂǂ̃R�}���h�}�N��.(Item1_1)
	ON_UPDATE_COMMAND_UI(ID_ITEM_2_2, OnUpdateItem2_2)	// ���j���[���ڂȂǂ�UI�X�V�}�N��.(Item2_2)
	ON_COMMAND(ID_ITEM_2_2, OnItem2_2)	// ���j���[���ڂȂǂ̃R�}���h�}�N��.(Item2_2)
	ON_UPDATE_COMMAND_UI(ID_ITEM_3_3, OnUpdateItem3_3)	// ���j���[���ڂȂǂ�UI�X�V�}�N��.(Item3_3)
	ON_COMMAND(ID_ITEM_3_3, OnItem3_3)	// ���j���[���ڂȂǂ̃R�}���h�}�N��.(Item3_3)
END_MESSAGE_MAP()

// CFrameWnd_�̃����o�̒�`
// �R���X�g���N�^CFrameWnd_()
CFrameWnd_::CFrameWnd_(){	// ����������

	// �����o�̏�����.
	m_bInitMenu = FALSE;	// m_bInitMenu��FALSE�ɏ�����.

}

// ���b�Z�[�W�n���h��OnPaint()
void CFrameWnd_::OnPaint(){	// ��ʂ̕`���v�����ꂽ��.

	// �ϐ��̐錾
	HDC hDC;		// ���̃E�B���h�E�̃f�o�C�X�R���e�L�X�g�n���h��hDC.
	PAINTSTRUCT ps;	// �y�C���g�����Ǘ�����PAINTSTRUCT�\���̕ϐ�ps.

	// ���j���[�̏�����.
	if (!m_bInitMenu){	// FALSE�Ȃ珉����.

		// ���j���[�̍����ւ�.
		SetMenu(NULL);
		CMenu *pMenu = CMenu::FromHandle(m_hMenuDefault);
		pMenu->DestroyMenu();
		m_cPopupMenu1.CreatePopupMenu();
		m_cPopupMenu1.AppendMenu(MF_STRING, ID_ITEM_1_1, _T("Item1-1(&A)"));
		m_cPopupMenu1.AppendMenu(MF_STRING, ID_ITEM_1_2, _T("Item1-2(&B)"));
		m_cPopupMenu1.AppendMenu(MF_STRING, ID_ITEM_1_3, _T("Item1-3(&C)"));
		m_cPopupMenu2.CreatePopupMenu();
		m_cPopupMenu2.AppendMenu(MF_STRING, ID_ITEM_2_1, _T("Item2-1(&D)"));
		m_cPopupMenu2.AppendMenu(MF_STRING, ID_ITEM_2_2, _T("Item2-2(&E)"));
		m_cPopupMenu2.AppendMenu(MF_STRING, ID_ITEM_2_3, _T("Item3-3(&F)"));
		m_cPopupMenu3.CreatePopupMenu();
		m_cPopupMenu3.AppendMenu(MF_STRING, ID_ITEM_3_1, _T("Item3-1(&G)"));
		m_cPopupMenu3.AppendMenu(MF_STRING, ID_ITEM_3_2, _T("Item3-2(&H)"));
		m_cPopupMenu3.AppendMenu(MF_STRING, ID_ITEM_3_3, _T("Item3-3(&I)"));
		CMenu cMenu;
		cMenu.CreateMenu();
		cMenu.AppendMenu(MF_POPUP, (UINT_PTR)m_cPopupMenu1.m_hMenu, _T("Item1"));
		cMenu.AppendMenu(MF_POPUP, (UINT_PTR)m_cPopupMenu2.m_hMenu, _T("Item2"));
		cMenu.AppendMenu(MF_POPUP, (UINT_PTR)m_cPopupMenu3.m_hMenu, _T("Item3"));
		SetMenu(&cMenu);
		m_hMenuDefault = cMenu.m_hMenu;
		m_bInitMenu = TRUE;	// TRUE���Z�b�g.

	}

	// ������̕`��
	hDC = ::BeginPaint(m_hWnd, &ps);	// WindowsAPI��BeginPaint�ŕ`��̏�������, �f�o�C�X�R���e�L�X�g�n���h�����擾.
	::EndPaint(m_hWnd, &ps);	// WindowsAPI��EndPaint�ŕ`����I��.

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

// �n���h��OnUpdateItem2_2()
void CFrameWnd_::OnUpdateItem2_2(CCmdUI* pCmdUI){	// ���j���[����Item2_2��UI�X�V�n���h��

	// ���j���[����Item2_2��UI�X�V
	if (pCmdUI){	// pCmdUI��NULL�łȂ��Ȃ�.

		// ���j���[����Item2_2�̗L����
		pCmdUI->Enable();	// Enable��Item2_2��L���ɂ���.(�f�t�H���g������TRUE.)

	}

}

// �n���h��OnItem2_2()
void CFrameWnd_::OnItem2_2(){	// ���j���[����Item2_2�̃R�}���h�n���h��

}

// �n���h��OnUpdateItem3_3()
void CFrameWnd_::OnUpdateItem3_3(CCmdUI* pCmdUI){	// ���j���[����Item3_3��UI�X�V�n���h��

	// ���j���[����Item3_3��UI�X�V
	if (pCmdUI){	// pCmdUI��NULL�łȂ��Ȃ�.

		// ���j���[����Item3_3�̗L����
		pCmdUI->Enable();	// Enable��Item3_3��L���ɂ���.(�f�t�H���g������TRUE.)

	}

}

// �n���h��OnItem3_3()
void CFrameWnd_::OnItem3_3(){	// ���j���[����Item3_3�̃R�}���h�n���h��

}