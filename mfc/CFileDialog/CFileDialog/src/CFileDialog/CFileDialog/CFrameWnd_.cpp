// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_
#include <afxdlgs.h>	// �_�C�A���O�Ȃ�.
// �Ǝ��̃w�b�_
#include "CFrameWnd_.h"	// CFrameWnd_�N���X
#include "resource.h"	// ���\�[�XID

// CFrameWnd_�̃��b�Z�[�W�}�b�v
BEGIN_MESSAGE_MAP(CFrameWnd_, CFrameWnd)
	ON_UPDATE_COMMAND_UI(ID_ITEM_1_1, OnUpdateItem1_1)	// ���j���[���ڂȂǂ�UI�X�V�}�N��.(Item1_1)
	ON_COMMAND(ID_ITEM_1_1, OnItem1_1)	// ���j���[���ڂȂǂ̃R�}���h�}�N��.(Item1_1)
	ON_UPDATE_COMMAND_UI(ID_ITEM_1_2, OnUpdateItem1_2)	// ���j���[���ڂȂǂ�UI�X�V�}�N��.(Item1_2)
	ON_COMMAND(ID_ITEM_1_2, OnItem1_2)	// ���j���[���ڂȂǂ̃R�}���h�}�N��.(Item1_2)
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

	// "�t�@�C�����J��"�_�C�A���O�̕\��.
	CFileDialog dlg(TRUE);	// CFileDialog�I�u�W�F�N�gdlg�̃R���X�g���N�^��TRUE�����n��.
	INT_PTR ret = dlg.DoModal();	// dlg.DoModal�ŕ\��.
	if (ret == IDOK){	// �I�����ꂽ.
		AfxMessageBox(_T("IDOK"));
	}
	else if (ret == IDCANCEL){	// �L�����Z��.
		AfxMessageBox(_T("IDCANCEL"));
	}

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

	// "���O��t���ĕۑ�"�_�C�A���O�̕\��.
	CFileDialog dlg(FALSE);	// CFileDialog�I�u�W�F�N�gdlg�̃R���X�g���N�^��FALSE�����n��.
	INT_PTR ret = dlg.DoModal();	// dlg.DoModal�ŕ\��.
	if (ret == IDOK){	// �I�����ꂽ.
		AfxMessageBox(_T("IDOK"));
	}
	else if (ret == IDCANCEL){	// �L�����Z��.
		AfxMessageBox(_T("IDCANCEL"));
	}

}