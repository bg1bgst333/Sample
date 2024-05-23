// �w�b�_�t�@�C���̃C���N���[�h
#include "CFrameWnd_.h"	// CFrameWnd_�N���X
#include "resource.h"	// ���\�[�XID

// CFrameWnd_�̃��b�Z�[�W�}�b�v
BEGIN_MESSAGE_MAP(CFrameWnd_, CFrameWnd)
	ON_UPDATE_COMMAND_UI(ID_ITEM_1_1, OnUpdateItem1_1)	// ���j���[���ڂȂǂ�UI�X�V�}�N��.(Item1_1)
	ON_COMMAND(ID_ITEM_1_1, OnItem1_1)	// ���j���[���ڂȂǂ̃R�}���h�}�N��.(Item1_1)
	ON_WM_CREATE()	// OnCreate�̃��b�Z�[�W�}�N��
END_MESSAGE_MAP()

// CFrameWnd_�̃����o�̒�`
// �R���X�g���N�^CFrameWnd_()
CFrameWnd_::CFrameWnd_(){	// ����������

}

// ���b�Z�[�W�n���h��OnCreate()
int CFrameWnd_::OnCreate(LPCREATESTRUCT lpCreateStruct){	// �E�B���h�E���쐬���ꂽ��.

	// �q�E�B���h�E�̍쐬.
	m_hChild = CreateWindow(_T("STATIC"), _T("Child"), WS_CHILD | WS_VISIBLE | WS_BORDER,0, 0, 100, 100, m_hWnd, NULL, lpCreateStruct->hInstance, NULL);
	return 0;

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

	// CWnd�I�u�W�F�N�g�ɃE�B���h�E�n���h�����ꎞ�I�ɃA�^�b�`����, ���삵��, �f�^�b�`.
	CWnd child;
	child.Attach(m_hChild);
	child.SetWindowText(_T("Item1-1"));
	HWND hWnd;
	hWnd = child.Detach();

}